// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

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
    /* Add your codes here */
	/*Aircon code*/
//	lv_obj_clear_flag(ui->ui_Aircon_Cont, LV_OBJ_FLAG_SCROLLABLE);
//
//    lv_obj_set_style_radius(ui->ui_Aircon_Slider_Fan, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_radius(ui->ui_Aircon_Slider_Fan, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//    lv_obj_set_style_radius(ui->ui_Aircon_Slider_Fan, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
//
//    lv_obj_set_width(ui->ui_Aircon_Roller_Mode, 176);
//    lv_obj_set_height(ui->ui_Aircon_Roller_Mode, 117);
//
//    ui_aricon_set_fan_speed(kAIRCON_FanMedium);
//    ui_aircon_star_cool();
//
//    lv_obj_clear_flag(ui->ui_Aircon_Img_TemUp, LV_OBJ_FLAG_CLICKABLE);
//    lv_obj_clear_flag(ui->ui_Aircon_Img_TempDown, LV_OBJ_FLAG_CLICKABLE);
//    lv_obj_clear_flag(ui->ui_Aircon_Img_TimerUp, LV_OBJ_FLAG_CLICKABLE);
//    lv_obj_clear_flag(ui->ui_Aircon_Img_TimerDown, LV_OBJ_FLAG_CLICKABLE);

	ui_oven_init();
}

