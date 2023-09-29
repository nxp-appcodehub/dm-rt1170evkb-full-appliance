/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CUSTOM_UI_HOOD_H_
#define CUSTOM_UI_HOOD_H_

#include "gui_guider.h"

typedef enum
{
	kHOOD_lightOff,
	kHOOD_LightOn
} HOOD_Light_T;

typedef enum
{
	kHOOD_FanOff,
	kHOOD_FanLow,
	kHOOD_FanHigh
} HOOD_Fan_Speed_T;
typedef enum
{
	kVIT_Light_On = 1,
	kVIT_Light_Off,
	kVIT_SetFanOff,
	kVIT_SetFanLow,
	kVIT_SetFanHigh
} VIT_Hood_Commands_T;

void ui_hood_init (void);
void ui_hood_set_light(HOOD_Light_T state);
void ui_hood_set_fan_speed (HOOD_Fan_Speed_T speed);
void _ui_smog1_anim(lv_obj_t * obj, bool fast);
void _ui_smog2_anim(lv_obj_t * obj, bool fast);
void ui_hood_process_command(unsigned short cmd_id);


#endif /* CUSTOM_UI_HOOD_H_ */
