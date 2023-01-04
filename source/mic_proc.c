/*
 * Copyright 2018-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "fsl_cache.h"
#include "fsl_pdm.h"
#include "fsl_pdm_edma.h"
#include "fsl_dmamux.h"
#include "fsl_os_abstraction.h"
#include "fsl_debug_console.h"

#include "mic_proc.h"
#include "PL_platformTypes_CortexM.h"
#include "VIT.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* PDM */
#define DEMO_PDM                        PDM
#define DEMO_PDM_CLK_FREQ               24576000
#define DEMO_PDM_FIFO_WATERMARK         (4)
#define DEMO_PDM_QUALITY_MODE           kPDM_QualityModeHigh
#define DEMO_PDM_CIC_OVERSAMPLE_RATE    (0U)
#define DEMO_PDM_ENABLE_CHANNEL_0       (0U)
#define DEMO_PDM_ENABLE_CHANNEL_1       (1U)
#define DEMO_PDM_SAMPLE_CLOCK_RATE      (6144000U) /* 6.144MHZ */
#define DEMO_PDM_CHANNEL_GAIN           kPDM_DfOutputGain4
#define DEMO_AUDIO_SAMPLE_RATE          (16000)

/* DMA */
#define DEMO_EDMA                       DMA0
#define DEMO_DMAMUX                     DMAMUX0
#define DEMO_EDMA_CHANNEL               0
#define DEMO_PDM_REQUEST_SOURCE         kDmaRequestMuxPdm

/* DMA/PDM Buffers */
#define RECORD_BUFFER_SIZE      (VIT_SAMPLES_PER_FRAME * PDM_BYTE_DEPTH * DEMO_CHANNEL_NUM)
#define BUFFER_NUM              (3U)
#define BUFFER_SIZE             (RECORD_BUFFER_SIZE * BUFFER_NUM)

/*******************************************************************************
 * Variables
 ******************************************************************************/
AT_NONCACHEABLE_SECTION_ALIGN(pdm_edma_handle_t pdmRxHandle, 4);
AT_NONCACHEABLE_SECTION_ALIGN(edma_handle_t dmaRxHandle, 4);
AT_QUICKACCESS_SECTION_DATA_ALIGN(edma_tcd_t s_edmaTcd[BUFFER_NUM], 32U);
AT_NONCACHEABLE_SECTION_ALIGN(static uint8_t s_buffer[BUFFER_SIZE], 16);

static pdm_edma_transfer_t s_receiveXfer[BUFFER_NUM];
static volatile uint32_t s_readIndex = 0U;

static const pdm_config_t pdmConfig  = {
    .enableDoze        = false,
    .fifoWatermark     = DEMO_PDM_FIFO_WATERMARK,
    .qualityMode       = DEMO_PDM_QUALITY_MODE,
    .cicOverSampleRate = DEMO_PDM_CIC_OVERSAMPLE_RATE,
};

static pdm_channel_config_t channelConfig = {
#if (defined(FSL_FEATURE_PDM_HAS_DC_OUT_CTRL) && (FSL_FEATURE_PDM_HAS_DC_OUT_CTRL))
    .outputCutOffFreq = kPDM_DcRemoverCutOff40Hz,
#else
    .cutOffFreq = kPDM_DcRemoverCutOff152Hz,
#endif
    .gain = DEMO_PDM_CHANNEL_GAIN,
};

static SemaphoreHandle_t semaphoreRX;

static void pdmRxCallback(PDM_Type *base, pdm_edma_handle_t *handle, status_t status, void *userData)
{
    BaseType_t reschedule = -1;
    xSemaphoreGiveFromISR(semaphoreRX, &reschedule);
    portYIELD_FROM_ISR(reschedule);
}

void MIC_Init(void)
{
    edma_config_t dmaConfig;

    NVIC_SetPriority(PDM_ERROR_IRQn, 5);
    NVIC_SetPriority(DMA_ERROR_IRQn, 5);

    NVIC_SetPriority(DMA1_DMA17_IRQn, 4U);
    NVIC_SetPriority(DMA0_DMA16_IRQn, 4U);

    DMAMUX_Init(DEMO_DMAMUX);
    DMAMUX_SetSource(DEMO_DMAMUX, DEMO_EDMA_CHANNEL, DEMO_PDM_REQUEST_SOURCE);
    DMAMUX_EnableChannel(DEMO_DMAMUX, DEMO_EDMA_CHANNEL);

    EDMA_GetDefaultConfig(&dmaConfig);
    EDMA_Init(DEMO_EDMA, &dmaConfig);
    /* Create DMA handle. */
    EDMA_CreateHandle(&dmaRxHandle, DEMO_EDMA, DEMO_EDMA_CHANNEL);

    /* Setup pdm */
    PDM_Init(DEMO_PDM, &pdmConfig);
    PDM_TransferCreateHandleEDMA(DEMO_PDM, &pdmRxHandle, pdmRxCallback, NULL, &dmaRxHandle);
    PDM_TransferInstallEDMATCDMemory(&pdmRxHandle, s_edmaTcd, BUFFER_NUM);
    if (DEMO_CHANNEL_NUM >= 1)
    {
    	PDM_TransferSetChannelConfigEDMA(DEMO_PDM, &pdmRxHandle, DEMO_PDM_ENABLE_CHANNEL_0, &channelConfig);
    }
    if (DEMO_CHANNEL_NUM >= 2)
    {
    	PDM_TransferSetChannelConfigEDMA(DEMO_PDM, &pdmRxHandle, DEMO_PDM_ENABLE_CHANNEL_1, &channelConfig);
    }
    PDM_SetSampleRateConfig(DEMO_PDM, DEMO_PDM_CLK_FREQ, DEMO_AUDIO_SAMPLE_RATE);
    PDM_Reset(DEMO_PDM);
    PDM_Enable(DEMO_PDM, true);

    /* Wait for mic to stabilize */
    OSA_TimeDelay(500);

    for (int ibuf = 0; ibuf < BUFFER_NUM; ibuf++)
    {
        s_receiveXfer[ibuf].data     = &s_buffer[ibuf * RECORD_BUFFER_SIZE];
        s_receiveXfer[ibuf].dataSize = RECORD_BUFFER_SIZE;
        int ibuf_next                = ibuf + 1;
        if (ibuf_next == BUFFER_NUM)
            ibuf_next = 0;
        s_receiveXfer[ibuf].linkTransfer = &s_receiveXfer[ibuf_next];
    }

    semaphoreRX = xSemaphoreCreateBinary();
    PDM_TransferReceiveEDMA(DEMO_PDM, &pdmRxHandle, &s_receiveXfer[0]);
}

void MIC_Close()
{
    PDM_TransferTerminateReceiveEDMA(DEMO_PDM, &pdmRxHandle);
    vSemaphoreDelete(semaphoreRX);
}

int MIC_Read(uint8_t *data, uint32_t size)
{
    /* Wait 100ms for the previous transfer to finish */
    if (xSemaphoreTake(semaphoreRX, pdMS_TO_TICKS(200)) != pdTRUE)
        return -1;
    /* Copy data from the DMIC buffer */
    memcpy(data, &s_buffer[s_readIndex], size);
    s_readIndex += size;
    if (s_readIndex >= BUFFER_SIZE)
        s_readIndex -= BUFFER_SIZE;

    return 0;
}
