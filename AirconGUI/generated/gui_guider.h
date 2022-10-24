/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *ui_Aircon;
	bool ui_Aircon_del;
	lv_obj_t *ui_Aircon_Img_Bg;
	lv_obj_t *ui_Aircon_Img_Lable_Bg;
	lv_obj_t *ui_Aircon_Label_Air;
	lv_obj_t *ui_Aircon_Img_Swing;
	lv_obj_t *ui_Aircon_cont_1;
	lv_obj_t *ui_Aircon_line;
	lv_obj_t *ui_Aircon_Label_Temp;
	lv_obj_t *ui_Aircon_Btn_TempUp;
	lv_obj_t *ui_Aircon_Btn_TempUp_label;
	lv_obj_t *ui_Aircon_Label_SetTemp;
	lv_obj_t *ui_Aircon_Label_Cen;
	lv_obj_t *ui_Aircon_Btn_TempDown;
	lv_obj_t *ui_Aircon_Btn_TempDown_label;
	lv_obj_t *ui_Aircon_Img_TemUp;
	lv_obj_t *ui_Aircon_Img_TempDown;
	lv_obj_t *ui_Aircon_Roller_Mode;
	lv_obj_t *ui_Aircon_Btn_Swing;
	lv_obj_t *ui_Aircon_Btn_Swing_label;
	lv_obj_t *ui_Aircon_Label_Swing;
	lv_obj_t *ui_Aircon_line_1;
	lv_obj_t *ui_Aircon_line_2;
	lv_obj_t *ui_Aircon_line_3;
	lv_obj_t *ui_Aircon_line_4;
	lv_obj_t *ui_Aircon_line_5;
	lv_obj_t *ui_Aircon_Label_Timer;
	lv_obj_t *ui_Aircon_Label_Mode;
	lv_obj_t *ui_Aircon_Label_Fan;
	lv_obj_t *ui_Aircon_Slider_Fan;
	lv_obj_t *ui_Aircon_Label_Low;
	lv_obj_t *ui_Aircon_Label_Medium;
	lv_obj_t *ui_Aircon_Label_High;
	lv_obj_t *ui_Aircon_Label_Comp;
	lv_obj_t *ui_Aircon_Label_On;
	lv_obj_t *ui_Aircon_Img_Comp;
	lv_obj_t *ui_Aircon_Label_FanSt;
	lv_obj_t *ui_Aircon_Label_FanState;
	lv_obj_t *ui_Aircon_Img_FanSt;
	lv_obj_t *ui_Aircon_Btn_TimerUp;
	lv_obj_t *ui_Aircon_Btn_TimerUp_label;
	lv_obj_t *ui_Aircon_Img_TimerUp;
	lv_obj_t *ui_Aircon_Btn_TimerDown;
	lv_obj_t *ui_Aircon_Btn_TimerDown_label;
	lv_obj_t *ui_Aircon_Img_TimerDown;
	lv_obj_t *ui_Aircon_Img_Fan;
	lv_obj_t *ui_Aircon_Img_Cool;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_ui_Aircon(lv_ui *ui);
LV_IMG_DECLARE(_aircon_fan_1_98x98);
LV_IMG_DECLARE(_aircon_bg_1280x720);
LV_IMG_DECLARE(_icn_cool_27x31);
LV_IMG_DECLARE(_aircon_cool_1_92x102);
LV_IMG_DECLARE(_aircon_swing_1_632x113);
LV_IMG_DECLARE(_arrow_down_28x14);
LV_IMG_DECLARE(_arrow_up_28x14);
LV_IMG_DECLARE(_title_bg_799x130);
LV_IMG_DECLARE(_icn_fan_low_31x27);

#ifdef __cplusplus
}
#endif
#endif