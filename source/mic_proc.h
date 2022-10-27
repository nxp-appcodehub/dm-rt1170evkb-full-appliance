/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MIC_PROC_H_
#define MIC_PROC_H_

#define DEMO_CHANNEL_NUM        1
#define PDM_BYTE_DEPTH          4

void MIC_Init(void);
void MIC_Close();
int MIC_Read(uint8_t *data, uint32_t size);

#endif /* MIC_PROC_H_ */
