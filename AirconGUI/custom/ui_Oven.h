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

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void ui_oven_init (void);

void ui_oven_set_mode(OVEN_MODE_T mode, OVEN_MODE_Dir_T dir);

#endif /* UI_OVEN_H_ */
