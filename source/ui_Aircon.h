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
#define FADE_ANIM_TIME			300

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

typedef enum
{
	kAIRCON_FanLow,
	kAIRCON_FanMedium,
	kAIRCON_FanHigh
} AIRCON_Fan_Speed_T;

typedef enum
{
	kAIRCON_ModeCool,
	kAIRCON_ModeDry,
	kAIRCON_ModeFan
} AIRCON_Mode_T;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state);

void ui_aircon_swing (bool state);

void ui_aricon_set_fan_speed (AIRCON_Fan_Speed_T speed);

void ui_aircon_set_mode (AIRCON_Mode_T mode);

void ui_aircon_star_cool(void);

#endif /* UI_AIRCON_H_ */
