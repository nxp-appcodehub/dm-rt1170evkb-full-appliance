/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MIC_PROC_H_
#define MIC_PROC_H_



#define DEMO_CHANNEL_NUM        g_mic_channel_num
#define DEMO_MAX_CHANNEL_NUM    3
#define PDM_BYTE_DEPTH          4

typedef enum
{
    MIMXRT1170_EVK,
    MIMXRT1170_EVKB,
    UNKWON_BOARD,
} Board_t;

extern Board_t boardUsed;
extern uint8_t g_mic_channel_num;

void MIC_Init(void);
void MIC_Close();
int MIC_Read(uint8_t *data, uint32_t size);
int MIC_GetStatus();

#endif /* MIC_PROC_H_ */
