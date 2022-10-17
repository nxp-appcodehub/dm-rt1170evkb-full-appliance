/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef UI_AIRCON_H_
#define UI_AIRCON_H_

#include "gui_guider.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    kAIRCON_TempDown,
	kAIRCON_TempUp,
} AIRCON_Temp_T;

typedef enum
{
    kAIRCON_SwingOff,
	kAIRCON_SwingOn,
} AIRCON_Swing_State_T;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state);

void ui_aircon_swing (bool state);

#endif /* UI_AIRCON_H_ */
