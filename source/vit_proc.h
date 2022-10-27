/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _VIT_PROC_H_
#define _VIT_PROC_H_

#include "PL_platformTypes_CortexM.h"
#include "VIT.h"

void DeInterleave(const PL_INT16 *pDataInput, PL_INT16 *pDataOutput, PL_UINT16 FrameSize, PL_UINT16 ChannelNumber);
void VIT_Task(void *pvParameters);

#endif
