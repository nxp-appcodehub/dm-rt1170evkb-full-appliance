/*
 * Copyright 2022 NXP
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
	kAIRCON_TimerDown,
	kAIRCON_TimerUp,
} AIRCON_Timer_T;

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

typedef enum
{
    kVIT_IncreaseTemp = 1,
	kVIT_DecreaseTemp,
	kVIT_SetTemp19,
	kVIT_SetFanToHigh,
	kVIT_SetFanToMedium,
	kVIT_SetFanToLow,
	kVIT_SwingOn,
	kVIT_SwingOff,
	kVIT_SetModeCool,
	kVIT_SetModeDry,
	kVIT_SetModeFan,
	kVIT_SetTimer4
} VIT_Aircon_Commands_T;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state);

void ui_aircon_update_timer (uint32_t hour, AIRCON_Timer_T state);

void ui_aircon_swing (bool state);

void ui_aricon_set_fan_speed (AIRCON_Fan_Speed_T speed);

void ui_aircon_set_mode (AIRCON_Mode_T mode);

void ui_aircon_star_cool(void);

void ui_aircon_process_command (unsigned short cmd_id);

#endif /* UI_AIRCON_H_ */
