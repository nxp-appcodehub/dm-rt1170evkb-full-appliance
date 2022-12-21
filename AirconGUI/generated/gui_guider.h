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
	lv_obj_t *ui_Oven;
	bool ui_Oven_del;
	lv_obj_t *ui_Oven_Img_Bg;
	lv_obj_t *ui_Oven_Img_Door;
	lv_obj_t *ui_Oven_Img_Lable_Bg;
	lv_obj_t *ui_Oven_Label_Oven;
	lv_obj_t *ui_Oven_Group_Oven;
	lv_obj_t *ui_Oven_line;
	lv_obj_t *ui_Oven_Label_CurrTemp;
	lv_obj_t *ui_Oven_line_5;
	lv_obj_t *ui_Oven_line_4;
	lv_obj_t *ui_Oven_line_3;
	lv_obj_t *ui_Oven_line_2;
	lv_obj_t *ui_Oven_line_1;
	lv_obj_t *ui_Oven_Label_Temp;
	lv_obj_t *ui_Oven_Label_Cen;
	lv_obj_t *ui_Oven_Label_Status;
	lv_obj_t *ui_Oven_Label_CurrStat;
	lv_obj_t *ui_Oven_Label_Time;
	lv_obj_t *ui_Oven_Bar_Time;
	lv_obj_t *ui_Oven_Label_Mode;
	lv_obj_t *ui_Oven_Btn_ModeLeft;
	lv_obj_t *ui_Oven_Btn_ModeLeft_label;
	lv_obj_t *ui_Oven_Btn_ModeRigth;
	lv_obj_t *ui_Oven_Btn_ModeRigth_label;
	lv_obj_t *ui_Oven_Btn_State;
	lv_obj_t *ui_Oven_Btn_State_label;
	lv_obj_t *ui_Oven_Label_Settings;
	lv_obj_t *ui_Oven_Tile_Mode;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_9;
	lv_obj_t *ui_Oven_Img_Mode9;
	lv_obj_t *ui_Oven_Label_Mode9;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_8;
	lv_obj_t *ui_Oven_Img_Mode8;
	lv_obj_t *ui_Oven_Label_Mode8;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_7;
	lv_obj_t *ui_Oven_Img_Mode7;
	lv_obj_t *ui_Oven_Label_Mode7;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_6;
	lv_obj_t *ui_Oven_Img_Mode6;
	lv_obj_t *ui_Oven_Label_Mode6;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_5;
	lv_obj_t *ui_Oven_Img_Mode5;
	lv_obj_t *ui_Oven_Label_Mode5;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_4;
	lv_obj_t *ui_Oven_Img_Mode4;
	lv_obj_t *ui_Oven_Label_Mode4;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_3;
	lv_obj_t *ui_Oven_Label_Mode3;
	lv_obj_t *ui_Oven_Img_Mode3;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_2;
	lv_obj_t *ui_Oven_Img_Mode2;
	lv_obj_t *ui_Oven_Label_Mode2;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_1;
	lv_obj_t *ui_Oven_Img_Mode1;
	lv_obj_t *ui_Oven_Label_Mode1;
	lv_obj_t *ui_Oven_Group_TarTemp;
	lv_obj_t *ui_Oven_Img_TempWheel;
	lv_obj_t *ui_Oven_Label_SelTemp;
	lv_obj_t *ui_Oven_Label_TarCen;
	lv_obj_t *ui_Oven_Group_Timer;
	lv_obj_t *ui_Oven_Img_TimerWheel;
	lv_obj_t *ui_Oven_Label_SelTimer;
	lv_obj_t *ui_Oven_Label_TimerSel;
	lv_obj_t *ui_Aircon;
	bool ui_Aircon_del;
	lv_obj_t *ui_Aircon_Img_Bg;
	lv_obj_t *ui_Aircon_Img_Lable_Bg;
	lv_obj_t *ui_Aircon_Label_Air;
	lv_obj_t *ui_Aircon_Img_Swing;
	lv_obj_t *ui_Aircon_Cont;
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
	lv_obj_t *ui_Aircon_Label_TimerHour;
	lv_obj_t *ui_Aircon_Label_TimerPoints;
	lv_obj_t *ui_Aircon_Label_TimerMin;
	lv_obj_t *ui_Aircon_Img_Fan;
	lv_obj_t *ui_Aircon_Img_Cool;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_ui_Oven(lv_ui *ui);
void setup_scr_ui_Aircon(lv_ui *ui);
LV_IMG_DECLARE(_icn_oven_gril_62x62);
LV_IMG_DECLARE(_aircon_fan_1_98x98);
LV_IMG_DECLARE(_aircon_cool_1_92x102);
LV_IMG_DECLARE(_BTN_oven_alpha_134x51);
LV_IMG_DECLARE(_oven_light_704x720);
LV_IMG_DECLARE(_icn_oven_upper_lower_62x62);
LV_IMG_DECLARE(_icn_oven_fan_gril_62x62);
LV_IMG_DECLARE(_wheel_bg_2_151x259);
LV_IMG_DECLARE(_oven_bg_1280x720);
LV_IMG_DECLARE(_icn_oven_defrost_62x62);
LV_IMG_DECLARE(_icn_oven_fan_upper_lower_62x62);
LV_IMG_DECLARE(_aircon_swing_1_632x113);
LV_IMG_DECLARE(_icn_oven_upper_62x62);
LV_IMG_DECLARE(_wheel_bg_151x259);
LV_IMG_DECLARE(_title_bg_654x130);
LV_IMG_DECLARE(_aircon_bg_1280x720);
LV_IMG_DECLARE(_icn_cool_27x31);
LV_IMG_DECLARE(_icn_oven_fan_rear_62x62);
LV_IMG_DECLARE(_arrow_left_alpha_18x35);
LV_IMG_DECLARE(_arrow_down_28x14);
LV_IMG_DECLARE(_arrow_right_alpha_18x35);
LV_IMG_DECLARE(_arrow_up_28x14);
LV_IMG_DECLARE(_icn_oven_lower_62x62);
LV_IMG_DECLARE(_icn_oven_fan_lower_62x62);
LV_IMG_DECLARE(_title_bg_799x130);
LV_IMG_DECLARE(_icn_fan_low_31x27);

#ifdef __cplusplus
}
#endif
#endif