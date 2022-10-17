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
	lv_obj_t *ui_Aircon_cont_1;
	lv_obj_t *ui_Aircon_line;
	lv_obj_t *ui_Aircon_Label_Temp;
	lv_obj_t *ui_Aircon_btn_1;
	lv_obj_t *ui_Aircon_btn_1_label;
	lv_obj_t *ui_Aircon_Sw_Swing;
	lv_obj_t *ui_Aircon_Img_Swing;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_ui_Aircon(lv_ui *ui);
LV_IMG_DECLARE(_aircon_bg_1280x720);
LV_IMG_DECLARE(_aircon_swing_1_632x113);
LV_IMG_DECLARE(_title_bg_799x130);

#ifdef __cplusplus
}
#endif
#endif