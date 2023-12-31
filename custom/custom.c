// SPDX-License-Identifier: MIT
// Copyright 2023 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "ui_Aircon.h"
#include "ui_Oven.h"
#include "ui_Hood.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
	guider_ui.ui_Home_del = false;
	ui_aircon_init();
	ui_oven_init();
	ui_hood_init();
}

