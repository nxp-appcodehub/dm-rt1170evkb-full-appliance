/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef UI_OVEN_H_
#define UI_OVEN_H_

#include "gui_guider.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define FADE_ANIM_TIME			300

typedef enum
{
	kOVEN_ModeFFRE,
	kOVEN_ModeULEC,
	kOVEN_ModeFFULC,
	kOVEN_ModeFFLEC,
	kOVEN_ModeGrill,
	kOVEN_ModeFFG,
	kOVEN_ModeUOE,
	kOVEN_ModeLOE,
	kOVEN_ModeDeFrost,
	kOVEN_ModeNull
} OVEN_MODE_T;

typedef enum
{
	kOVEN_ModeDirLeft,
	kOVEN_ModeDirRight,
} OVEN_MODE_Dir_T;

typedef enum
{
	kOVEN_DoorClose,
	kOVEN_DoorOpen,
} OVEN_Door_T;

typedef enum
{
	kOVEN_lightOff,
	kOVEN_LightOn,
} OVEN_Light_T;

typedef enum
{
	kOVEN_Start,
	kOVEN_Stop,
} OVEN_State_T;

typedef enum
{
	kOVEN_FanOff,
	kOVEN_FanOn,
} OVEN_Fan_T;

typedef enum
{
	kVIT_Start = 1,
	kVIT_Stop,
	kVIT_OpenDoor,
	kVIT_CloseDoor,
	kVIT_LightOn,
	kVIT_LightOff,
	kVIT_SetTemp150,
	kVIT_SetTemp180,
	kVIT_SetTemp210,
	kVIT_DefrotsMode,
	kVIT_ModeToLeft,
	kVIT_ModeToRight
} VIT_Oven_Commands_T;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void ui_oven_init (void);

void ui_oven_set_Temperature(uint32_t temp);

void ui_oven_set_Timer(uint32_t time);

void ui_oven_set_mode(OVEN_MODE_T mode, OVEN_MODE_Dir_T dir);

void ui_oven_door(OVEN_Door_T state);

void ui_oven_set_light(OVEN_Light_T state);

void ui_oven_set_state(OVEN_State_T state);

void ui_oven_process_command (unsigned short cmd_id);

#endif /* UI_OVEN_H_ */
