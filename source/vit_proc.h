/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _VIT_PROC_H_
#define _VIT_PROC_H_

#include "mic_proc.h"
#include "PL_platformTypes_CortexM.h"
#include "VIT.h"

#define VIT_WW_DETECT (1 << 0)
#define VIT_CMD_DETECT (1 << 1)

#define DEMO_FRAME_MS       (30)    // Only 10 or 30 ms supported by VIT
#define SAMPLES_PER_FRAME   (VIT_SAMPLE_RATE * DEMO_FRAME_MS / 1000U)

void DeInterleave(const PL_INT16 *pDataInput, PL_INT16 *pDataOutput, PL_UINT16 FrameSize, PL_UINT16 ChannelNumber);
void VIT_Task(void *pvParameters);

#endif
