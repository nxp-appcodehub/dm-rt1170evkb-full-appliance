/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>
#include <string.h>
#include <math.h>


#include "fsl_debug_console.h"
#include "fsl_os_abstraction.h"

#include "vit_proc.h"
#include "VIT.h"
#include "PL_platformTypes_CortexM.h"

#if VIT_DEVICE_AIRCON
#include "VIT_Model_Aircon.h"
#endif
#if VIT_DEVICE_OVEN
#include "VIT_Model_Oven.h"
#endif

#include "mic_proc.h"
#include "board.h"
#include "arm_math.h"

#define VIT_CMD_TIME_SPAN   3

#define NUMBER_OF_CHANNELS  DEMO_CHANNEL_NUM
#define BYTE_DEPTH          PDM_BYTE_DEPTH
#define MODEL_LOCATION      VIT_MODEL_IN_RAM

#define DEVICE_ID           VIT_IMXRT1170

#define MEMORY_ALIGNMENT    8 // in bytes

#define VIT_MEM_INFO        1   // Print VIT memory usage
#define CPU_PROFILING       1   // Enable VIT and VoiceSeeker profiling of CPU usage
#define MIC_DB              1   // Calculate dB of mic data


#define DEMO_FRAME_MS       (10)    // Only 10 or 30 ms supported by VIT
#define SAMPLES_PER_FRAME   (VIT_SAMPLE_RATE * DEMO_FRAME_MS / 1000U)
#define WINDOW_FRAMES       (1000 / DEMO_FRAME_MS)  // One measurement per ~1s


static VIT_Handle_t VITHandle = PL_NULL;      // VIT handle pointer
static VIT_InstanceParams_st VITInstParams;   // VIT instance parameters structure
static VIT_ControlParams_st VITControlParams; // VIT control parameters structure
static PL_MemoryTable_st VITMemoryTable;      // VIT memory table descriptor
static PL_BOOL InitPhase_Error        = PL_FALSE;
static VIT_DataIn_st VIT_InputBuffers = {PL_NULL, PL_NULL,
                                         PL_NULL}; // Resetting Input Buffer addresses provided to VIT_process() API
static PL_INT8 *pMemory[PL_NR_MEMORY_REGIONS];
static PL_INT16 DeInterleavedBuffer[SAMPLES_PER_FRAME * NUMBER_OF_CHANNELS];

extern EventGroupHandle_t GPH_Process;
PL_UINT16 cmd_id = 0;

#if DEBUG_MIC
#include <cr_section_macros.h>
#define TEST_BUFF_DURATION  2U
#define FRAME_SIZE          (SAMPLES_PER_FRAME * BYTE_DEPTH * NUMBER_OF_CHANNELS)
#define TEST_BUFF_SIZE      (VIT_SAMPLE_RATE * BYTE_DEPTH * NUMBER_OF_CHANNELS * TEST_BUFF_DURATION)
__BSS(BOARD_SDRAM) int8_t debug_pcm_buffer[TEST_BUFF_SIZE];
int AudioIoFrameCnt = 0;
#endif


#if CPU_PROFILING
static uint32_t cpu_profiling_count = 0;
static uint32_t cycles[WINDOW_FRAMES] = { 0 };
#endif

#if MIC_DB
static uint32_t mic_db_count = 0;
static float rms[NUMBER_OF_CHANNELS+1][WINDOW_FRAMES] = { 0 };
static float float_inputBuffer[SAMPLES_PER_FRAME] = { 0 };
#endif

__BSS(SRAM_OC1) SDK_ALIGN(static uint8_t ocram_slow_data_region[216 * 1024], + MEMORY_ALIGNMENT);
AT_QUICKACCESS_SECTION_DATA_ALIGN(static uint8_t dtc_fast_data_region[136 * 1024], MEMORY_ALIGNMENT);
AT_QUICKACCESS_SECTION_DATA_ALIGN(static uint8_t dtc_fast_coef_region[10 * 1024], MEMORY_ALIGNMENT);
AT_QUICKACCESS_SECTION_DATA_ALIGN(static uint8_t dtc_fast_temp_region[48  * 1024], MEMORY_ALIGNMENT);


/****************************************************************************************/
/*                                                                                      */
/*  Functions                                                                            */
/*                                                                                      */
/****************************************************************************************/
#if CPU_PROFILING
static void enableCpuCycleCounter(void)
{
    /* Make sure the DWT trace fucntion is enabled. */
    if (CoreDebug_DEMCR_TRCENA_Msk != (CoreDebug_DEMCR_TRCENA_Msk & CoreDebug->DEMCR))
    {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    }

    /* CYCCNT not supported on this device. */
    assert(DWT_CTRL_NOCYCCNT_Msk != (DWT->CTRL & DWT_CTRL_NOCYCCNT_Msk));

    /* Read CYCCNT directly if CYCCENT has already been enabled, otherwise enable CYCCENT first. */
    if (DWT_CTRL_CYCCNTENA_Msk != (DWT_CTRL_CYCCNTENA_Msk & DWT->CTRL))
    {
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
}

static uint32_t getCpuCycleCount(void)
{
    return DWT->CYCCNT;
}
#endif

VIT_ReturnStatus_en VIT_ModelInfo(void)
{
    VIT_ReturnStatus_en VIT_Status;
    VIT_ModelInfo_st Model_Info;
    VIT_Status = VIT_GetModelInfo(&Model_Info);
    if (VIT_Status != VIT_SUCCESS)
    {
        PRINTF("VIT_GetModelInfo error: %d\r\n", VIT_Status);
        return VIT_INVALID_MODEL;
    }

    PRINTF("\n[VIT] Model info\r\n");
//    PRINTF("  VIT Model Release: 0x%04x\r\n", Model_Info.VIT_Model_Release);
//    if (Model_Info.pLanguage != PL_NULL)
//    {
//        PRINTF("  Language supported: %s \r\n", Model_Info.pLanguage);
//    }
//    PRINTF("  Number of WakeWords supported : %d \r\n", Model_Info.NbOfWakeWords);
//    PRINTF("  Number of Commands supported : %d \r\n", Model_Info.NbOfVoiceCmds);

    if (!Model_Info.WW_VoiceCmds_Strings) // Check here if Model is containing WW and CMDs strings
    {
//        PRINTF("  VIT_Model integrating WakeWord and Voice Commands strings: NO\r\n");
    }
    else
    {
        const char *ptr;

//        PRINTF("  VIT_Model integrating WakeWord and Voice Commands strings: YES\r\n");
        PRINTF("  WakeWords supported : \r\n");
        ptr = Model_Info.pWakeWord;
        if (ptr != PL_NULL)
        {
            for (PL_UINT16 i = 0; i < Model_Info.NbOfWakeWords; i++)
            {
                PRINTF("   '%s' \r\n", ptr);
                ptr += strlen(ptr) + 1; // to consider NULL char
            }
        }
        PRINTF("  Voice commands supported: \r\n");
        ptr = Model_Info.pVoiceCmds_List;
        if (ptr != PL_NULL)
        {
            for (PL_UINT16 i = 0; i < Model_Info.NbOfVoiceCmds; i++)
            {
                PRINTF("   '%s' \r\n", ptr);
                ptr += strlen(ptr) + 1; // to consider NULL char
            }
        }
    }
    /*
     *   VIT Get Library information
     */
//    VIT_LibInfo_st Lib_Info;
//    VIT_Status = VIT_GetLibInfo(&Lib_Info);
//    if (VIT_Status != VIT_SUCCESS)
//    {
//        PRINTF("VIT_GetLibInfo error: %d\r\n", VIT_Status);
//        return VIT_INVALID_STATE;
//    }
//    PRINTF("\n  VIT Lib Info\r\n");
//    PRINTF("  VIT LIB Release: 0x%04x\r\n", Lib_Info.VIT_LIB_Release);
//    PRINTF("  VIT Features supported by the lib: 0x%04x\r\n", Lib_Info.VIT_Features_Supported);
//    PRINTF("  Number of channels supported by VIT lib: %d\r\n", Lib_Info.NumberOfChannels_Supported);
//    if (Lib_Info.WakeWord_In_Text2Model)
//    {
//        PRINTF("  VIT WakeWord in Text2Model\r\n\r\n");
//    }
//    else
//    {
//        PRINTF("  VIT WakeWord in Audio2Model\r\n\r\n");
//    }
//    /*
//     *   Configure VIT Instance Parameters
//     */
//    // Check that NUMBER_OF_CHANNELS is supported by VIT
//    // Retrieve from VIT_GetLibInfo API the number of channel supported by the VIT lib
//    PL_UINT16 max_nb_of_Channels = Lib_Info.NumberOfChannels_Supported;
//    if (NUMBER_OF_CHANNELS > max_nb_of_Channels)
//    {
//        PRINTF("VIT lib is supporting only: %d channels\r\n", max_nb_of_Channels);
//        return VIT_INVALID_PARAMETER_OUTOFRANGE;
//    }
    return VIT_SUCCESS;
}

int VIT_Initialize()
{
    VIT_ReturnStatus_en VIT_Status = VIT_SUCCESS;
    uint16_t i, minIdx; /* loop index */
    int32_t temp32;     /* temporary address */
    int16_t j;          /* loop index */
    uint16_t order[PL_NR_MEMORY_REGIONS];

#if CPU_PROFILING
    enableCpuCycleCounter();
    cpu_profiling_count = 0;
#endif
#if MIC_DB
    mic_db_count = 0;
#endif

    VIT_Status = VIT_SetModel(VIT_Model_Oven, MODEL_LOCATION);

    if (VIT_Status != VIT_SUCCESS)
    {
        return VIT_Status;
    }

    VIT_Status = VIT_ModelInfo();
    if (VIT_Status != VIT_SUCCESS)
    {
        return VIT_Status;
    }
    /*
     *   Configure VIT Instance Parameters
     */
    VITInstParams.SampleRate_Hz   = VIT_SAMPLE_RATE;
    VITInstParams.SamplesPerFrame = SAMPLES_PER_FRAME;
    VITInstParams.NumberOfChannel = NUMBER_OF_CHANNELS;
    VITInstParams.DeviceId        = DEVICE_ID;

    /*
     *   VIT get memory table: Get size info per memory type
     */
    VIT_Status = VIT_GetMemoryTable(PL_NULL, // VITHandle param should be NULL
                                    &VITMemoryTable, &VITInstParams);
    if (VIT_Status != VIT_SUCCESS)
    {
        PRINTF("VIT_GetMemoryTable error: %d\r\n", VIT_Status);
        return VIT_Status;
    }

    /* Initialize order variable */
    for (i = 0; i < PL_NR_MEMORY_REGIONS; i++)
    {
        order[i] = i;
    }

    /* Sort region indexes by region size */
    for (i = 0; i < (PL_NR_MEMORY_REGIONS - 1); i++)
    {
        minIdx = i;
        for (j = i + 1; j < PL_NR_MEMORY_REGIONS; j++)
            if (VITMemoryTable.Region[order[j]].Size < VITMemoryTable.Region[order[minIdx]].Size)
                minIdx = j;

        /* Swap indexes */
        temp32        = order[minIdx];
        order[minIdx] = order[i];
        order[i]      = temp32;
    }

    float total_size_allocated = 0;
    /*
     *   Reserve memory space: Malloc for each memory type
     */
    for (j = (PL_NR_MEMORY_REGIONS - 1); j >= 0; j--)
    {
        /* Log the memory size */
        if (VITMemoryTable.Region[order[j]].Size != 0)
        {
            // reserve memory space
            // NB: VITMemoryTable.Region[PL_MEMREGION_PERSISTENT_FAST_DATA] should be allocated
            //      in the fastest memory of the platform (when possible) - this is not the case in this example.

            if (PL_PERSISTENT_SLOW_DATA == order[j])
            {
//                pMemory[j] = OSA_MemoryAllocate(VITMemoryTable.Region[order[j]].Size + MEMORY_ALIGNMENT);
                pMemory[j] = &ocram_slow_data_region[0];
            }
            else if (PL_PERSISTENT_FAST_DATA == order[j])
            {
                pMemory[j] = &dtc_fast_data_region[0];
            }
            else if (PL_PERSISTENT_FAST_COEF == order[j])
            {
                pMemory[j] = &dtc_fast_coef_region[0];
            }
            else if (PL_TEMPORARY_FAST == order[j])
            {
                pMemory[j] = &dtc_fast_temp_region[0];
            }
            if (!pMemory[j])
            {
                return VIT_INVALID_NULLADDRESS;
            }
            VITMemoryTable.Region[order[j]].pBaseAddress = (void *)pMemory[j];

#if VIT_MEM_INFO
            PRINTF(" VITMemoryTable.Region[");
            PRINTF("%s", order[j] == PL_PERSISTENT_SLOW_DATA ? "SLOW_DATA" :
                    order[j] == PL_PERSISTENT_FAST_DATA ? "FAST_DATA" :
                    order[j] == PL_PERSISTENT_FAST_COEF ? "FAST_COEF" :
                    order[j] == PL_TEMPORARY_FAST ? "TEMP_FAST" : "UNKNOWN");
            PRINTF("] @ 0x%x", VITMemoryTable.Region[order[j]].pBaseAddress);
            PRINTF(" Size = %.2f kB\r\n", (float)(VITMemoryTable.Region[order[j]].Size) / 1024.0f);
            total_size_allocated += (float)(VITMemoryTable.Region[order[j]].Size) / 1024.0f;
#endif
        }
    }

#if VIT_MEM_INFO
    float vit_model_size_kb = (float) sizeof(VIT_Model_Oven) / 1024.0f;
    float vit_model_ram_size = 0;

    PRINTF(" Total Size Allocated = %.2f kB\r\n", total_size_allocated);
    if (MODEL_LOCATION == VIT_MODEL_IN_ROM)
        PRINTF(" VIT Model located in ROM");
    else if (MODEL_LOCATION == VIT_MODEL_IN_RAM)
        PRINTF(" VIT Model located in RAM");

    PRINTF(" @ 0x%x", &VIT_Model_Oven);
    PRINTF(" Size = %.2f kB\r\n", vit_model_size_kb);

    if ((int) &VIT_Model_Oven[0] & 0xFF000000 == 0x30000000)
    {
        vit_model_ram_size = 0; // Model placed in flash
    }
    else if ((int) &VIT_Model_Oven[0] & 0xFF000000 == 0x20000000)
    {
        vit_model_ram_size = vit_model_size_kb; // Model placed in RAM (CM33 system bus)
    }

    PRINTF("\r\n Total RAM = %.2f kB\r\n", total_size_allocated + vit_model_ram_size);
#endif

    /*
     *    Create VIT Instance
     */
    VITHandle  = PL_NULL; // force to null address for correct memory initialization
    VIT_Status = VIT_GetInstanceHandle(&VITHandle, &VITMemoryTable, &VITInstParams);
    if (VIT_Status != VIT_SUCCESS)
    {
        InitPhase_Error = PL_TRUE;
        PRINTF("VIT_GetInstanceHandle error: %d\r\n", VIT_Status);
    }

    /*
     *    Test the reset (OPTIONAL)
     */
//    if (!InitPhase_Error)
//    {
//        VIT_Status = VIT_ResetInstance(VITHandle);
//        if (VIT_Status != VIT_SUCCESS)
//        {
//            InitPhase_Error = PL_TRUE;
//            PRINTF("VIT_ResetInstance error: %d\r\n", VIT_Status);
//        }
//    }

    /*
     *   Set and Apply VIT control parameters
     */
    if (NUMBER_OF_CHANNELS == 1)
    {
		VITControlParams.OperatingMode  = VIT_WAKEWORD_ENABLE | VIT_VOICECMD_ENABLE;
		VITControlParams.MIC1_MIC2_Distance = 0;
		VITControlParams.MIC1_MIC3_Distance = 0;
    }
    else if (NUMBER_OF_CHANNELS == 2)
    {
		VITControlParams.OperatingMode  = VIT_WAKEWORD_ENABLE | VIT_VOICECMD_ENABLE | VIT_AFE_ENABLE;
		VITControlParams.MIC1_MIC2_Distance = 60;
		VITControlParams.MIC1_MIC3_Distance = 0;
    }
    VITControlParams.Command_Time_Span  = VIT_CMD_TIME_SPAN;

    if (!InitPhase_Error)
    {
        VIT_Status = VIT_SetControlParameters(VITHandle, &VITControlParams);
        if (VIT_Status != VIT_SUCCESS)
        {
            InitPhase_Error = PL_TRUE;
            PRINTF("VIT_SetControlParameters error: %d\r\n", VIT_Status);
        }
    }

    PRINTF("\n[VIT] Started\r\n");

    return VIT_Status;
}

int VIT_Execute(void *inputBuffer, int size)
{
    VIT_ReturnStatus_en VIT_Status;
    VIT_VoiceCommand_st VoiceCommand; // Voice Command info
    VIT_WakeWord_st WakeWord;         // Wakeword info

    VIT_DetectionStatus_en VIT_DetectionResults = VIT_NO_DETECTION; // VIT detection result

#if CPU_PROFILING
    uint32_t tic = 0, toc = 0;
#endif

    if (size != SAMPLES_PER_FRAME * NUMBER_OF_CHANNELS * BYTE_DEPTH)
    {
        PRINTF("Input buffer format issue\r\n");
        return VIT_INVALID_FRAME_SIZE;
    }
    DeInterleave(inputBuffer, DeInterleavedBuffer, SAMPLES_PER_FRAME, NUMBER_OF_CHANNELS);

#if DEBUG_MIC
     // Copy float vector to debug_buffer
     if (AudioIoFrameCnt * FRAME_SIZE < TEST_BUFF_SIZE )
     {
         memcpy((void *)&debug_pcm_buffer[AudioIoFrameCnt * FRAME_SIZE % TEST_BUFF_SIZE], (void *)inputBuffer, FRAME_SIZE);
     }
     else if ( AudioIoFrameCnt * FRAME_SIZE == TEST_BUFF_SIZE )
     {
         PRINTF("[VIT] Saved %ds of %d-ch mic data to debug_buffer\r\n", TEST_BUFF_DURATION, NUMBER_OF_CHANNELS);
         __NOP();
     }
     AudioIoFrameCnt++;
#endif

    /*
     *   VIT Process
     */
    // Current VIT library is supporting only one channel
    // VIT_InputBuffers.pBuffer_Chan1 should be set to the input buffer address
    // VIT_InputBuffers.pBuffer_Chan1 setting can be done out of the while loop
    // Application should take care of the ping pong buffers (when present) handling - no pingpong buffer in this
    // example app.
    if (VITInstParams.NumberOfChannel == _1CHAN)
    {
        VIT_InputBuffers.pBuffer_Chan1 = DeInterleavedBuffer;
        VIT_InputBuffers.pBuffer_Chan2 = PL_NULL;
        VIT_InputBuffers.pBuffer_Chan3 = PL_NULL;
    }
    else if (VITInstParams.NumberOfChannel == _2CHAN)
    {
        VIT_InputBuffers.pBuffer_Chan1 = DeInterleavedBuffer;
        VIT_InputBuffers.pBuffer_Chan2 = &DeInterleavedBuffer[SAMPLES_PER_FRAME * 1];
        VIT_InputBuffers.pBuffer_Chan3 = PL_NULL;
    }
    else if (VITInstParams.NumberOfChannel == _3CHAN)
    {
        VIT_InputBuffers.pBuffer_Chan1 = DeInterleavedBuffer;
        VIT_InputBuffers.pBuffer_Chan2 = &DeInterleavedBuffer[SAMPLES_PER_FRAME * 1];
        VIT_InputBuffers.pBuffer_Chan3 = &DeInterleavedBuffer[SAMPLES_PER_FRAME * 2];
    }

#if CPU_PROFILING
     __disable_irq();
    tic = getCpuCycleCount();
#endif
    VIT_Status = VIT_Process(VITHandle,
                             &VIT_InputBuffers, // temporal audio input data
                             &VIT_DetectionResults);
#if CPU_PROFILING
    toc = getCpuCycleCount();
     __enable_irq();
#endif
    if (VIT_Status != VIT_SUCCESS)
    {
        PRINTF("VIT_Process error: %d\r\n", VIT_Status);
        return VIT_Status; // will stop processing VIT and go directly to MEM free
    }

    if (VIT_DetectionResults == VIT_WW_DETECTED)
    {
        // Retrieve id of the WakeWord detected
        // String of the Command can also be retrieved (when WW and CMDs strings are integrated in Model)
        VIT_Status = VIT_GetWakeWordFound(VITHandle, &WakeWord);
        if (VIT_Status != VIT_SUCCESS)
        {
            PRINTF("VIT_GetWakeWordFound error : %d\r\n", VIT_Status);
            return VIT_Status; // will stop processing VIT and go directly to MEM free
        }
        else
        {
            PRINTF("\033[2K"); // VT100 code to erase line
            PRINTF(" - WW: ");

            // Retrieve WakeWord Name : OPTIONAL
            // Check first if WakeWord string is present
            if (WakeWord.pWW_Name != PL_NULL)
            {
                PRINTF(" %s\r\n", WakeWord.pWW_Name);
            }

            /*Set event WW detect*/
            xEventGroupSetBits(GPH_Process, VIT_WW_DETECT);
        }
    }
    else if (VIT_DetectionResults == VIT_VC_DETECTED)
    {
        // Retrieve id of the Voice Command detected
        // String of the Command can also be retrieved (when WW and CMDs strings are integrated in Model)
        VIT_Status = VIT_GetVoiceCommandFound(VITHandle, &VoiceCommand);
        if (VIT_Status != VIT_SUCCESS)
        {
            PRINTF("VIT_GetVoiceCommandFound error: %d\r\n", VIT_Status);
            return VIT_Status; // will stop processing VIT and go directly to MEM free
        }
        else
        {
            PRINTF("\033[2K"); // VT100 code to erase line
            PRINTF(" - CMD %d: ", VoiceCommand.Cmd_Id);
            /*Set Event CMD detect*/
            xEventGroupSetBits(GPH_Process, VIT_CMD_DETECT);

            cmd_id = VoiceCommand.Cmd_Id;

            // Retrieve CMD Name: OPTIONAL
            // Check first if CMD string is present
            if (VoiceCommand.pCmd_Name != PL_NULL)
            {
                PRINTF(" %s\r\n", VoiceCommand.pCmd_Name);
            }
            else
            {
                PRINTF("\r\n");
            }
        }
    }

#if CPU_PROFILING
    uint32_t avg_cycles = 0, max_cycles = 0;
    uint32_t max_index = 0;

    cycles[cpu_profiling_count % WINDOW_FRAMES] = toc - tic;

    if (cpu_profiling_count == 0)
    {
        PRINTF("\r\n VIT MHz");
        PRINTF("\r\n Avg\tMax");
    }
    /* Calculate CPU usage for one window */
    if ((cpu_profiling_count + 1) % WINDOW_FRAMES == 0)
    {
        /* VIT */
        arm_mean_q31(cycles, WINDOW_FRAMES, &avg_cycles);
        arm_max_q31(cycles, WINDOW_FRAMES, &max_cycles, &max_index);

        /* Adjust for 1s of CPU usage depending on window size */
        PRINTF("\r\n %.2f", ((float) avg_cycles * WINDOW_FRAMES) / 1000000.0f);
        PRINTF("\t%.2f", ((float) max_cycles * WINDOW_FRAMES) / 1000000.0f);

    }
    cpu_profiling_count++;
#endif

#if MIC_DB
    for (uint8_t ch = 0; ch < NUMBER_OF_CHANNELS; ch++)
    {
        float sum[NUMBER_OF_CHANNELS] = { 0 };

        PL_INT16 *InputTempDataINT16 = (PL_INT16*) DeInterleavedBuffer;

        arm_q15_to_float(&InputTempDataINT16[SAMPLES_PER_FRAME * ch], &float_inputBuffer[0], SAMPLES_PER_FRAME);
        /* Get RMS value */
        arm_rms_f32(&float_inputBuffer[0], SAMPLES_PER_FRAME, &rms[ch][mic_db_count % WINDOW_FRAMES]);

        if (mic_db_count == 0)
        {
            PRINTF("\tch%d dB", ch);
        }
        /* Calculate average values for the selected window */
        if ((mic_db_count + 1) % WINDOW_FRAMES == 0)
        {
            float avg_rms[NUMBER_OF_CHANNELS] = { 0 };
            float value_dB[NUMBER_OF_CHANNELS] = { 0 };
            float value_dBFS[NUMBER_OF_CHANNELS] = { 0 };

            arm_mean_f32(&rms[ch][0], WINDOW_FRAMES, &avg_rms[ch]);

            /* Convert to dB and dBFS */
            value_dB[ch] = 20 * log10f(avg_rms[ch]);
            value_dBFS[ch] = 20 * log10f(avg_rms[ch]) + 3.0103f;

            PRINTF("\t%.2f", value_dB[ch]);
        }
    }
    mic_db_count++;
#endif

    return VIT_Status;
}

int VIT_Deinit(void)
{
    VIT_ReturnStatus_en VIT_Status; /* Function call status */
                                    // retrieve size of the different MEM tables allocated
    VIT_Status =
        VIT_GetMemoryTable(VITHandle, // Should provide VIT_Handle to retrieve the size of the different MemTabs
                           &VITMemoryTable, &VITInstParams);
    if (VIT_Status != VIT_SUCCESS)
    {
        PRINTF("VIT_GetMemoryTable error: %d\r\n", VIT_Status);
        return VIT_Status;
    }

    // Free the MEM tables
    for (int i = 0; i < PL_NR_MEMORY_REGIONS; i++)
    {
        if (VITMemoryTable.Region[i].Size != 0)
        {
            OSA_MemoryFree((PL_INT8 *)pMemory[i]);
            pMemory[i] = NULL;
        }
    }
    return VIT_Status;
}

//  de-Interleave Multichannel signal
//   example:  A1.B1.C1.A2.B2.C2.A3.B3.C3....An.Bn.Cn   (3 Channels case : A, B, C)
//             will become
//             A1.A2.A3....An.B1.B2.B3....Bn.C1.C2.C3....Cn

// Simple helper function for de-interleaving Multichannel stream
// The caller function shall ensure that all arguments are correct.
// This function assumes the input data as 32 bit width and transforms it into 16 bit width
void DeInterleave(const PL_INT16 *pDataInput, PL_INT16 *pDataOutput, PL_UINT16 FrameSize, PL_UINT16 ChannelNumber)
{
    for (PL_UINT16 ichan = 0; ichan < ChannelNumber; ichan++)
    {
        for (PL_UINT16 i = 0; i < FrameSize; i++)
        {
            /* Select the 16 MSB of the 32 input bits */
            pDataOutput[i + (ichan * FrameSize)] = pDataInput[(i * 2 * ChannelNumber) + (ichan * 2) + 1];
        }
    }
    return;
}

void VIT_Task(void *pvParameters)
{
    uint8_t buff[SAMPLES_PER_FRAME * NUMBER_OF_CHANNELS * BYTE_DEPTH];

    MIC_Init();
    VIT_Initialize();

    while (1)
    {
        if(MIC_Read(buff, sizeof(buff)) == 0)
        {
            VIT_Execute(buff, sizeof(buff));
        }
        else
        {
            PRINTF("[VIT] Error: no mic data\r\n");
        }
    }
}

