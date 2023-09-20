/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_ui_Oven(lv_ui *ui)
{
	//Write codes ui_Oven
	ui->ui_Oven = lv_obj_create(NULL);
	lv_obj_set_size(ui->ui_Oven, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Oven, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_Bg
	ui->ui_Oven_Img_Bg = lv_img_create(ui->ui_Oven);
	lv_obj_add_flag(ui->ui_Oven_Img_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Bg, &_oven_bg_alpha_1280x720);
	lv_img_set_pivot(ui->ui_Oven_Img_Bg, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Bg, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Oven_Img_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_Door
	ui->ui_Oven_Img_Door = lv_img_create(ui->ui_Oven);
	lv_obj_add_flag(ui->ui_Oven_Img_Door, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Door, &_oven_light_alpha_704x720);
	lv_img_set_pivot(ui->ui_Oven_Img_Door, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Door, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Door, 5, -1);
	lv_obj_set_size(ui->ui_Oven_Img_Door, 704, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Door, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Door, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Door, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_Fan
	ui->ui_Oven_Img_Fan = lv_img_create(ui->ui_Oven);
	lv_obj_add_flag(ui->ui_Oven_Img_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Fan, &_oven_fan_light_1_alpha_120x119);
	lv_img_set_pivot(ui->ui_Oven_Img_Fan, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Fan, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Fan, 364, 344);
	lv_obj_set_size(ui->ui_Oven_Img_Fan, 120, 119);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_Label_Bg
	ui->ui_Oven_Img_Label_Bg = lv_img_create(ui->ui_Oven);
	lv_obj_add_flag(ui->ui_Oven_Img_Label_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Label_Bg, &_title_bg_alpha_654x130);
	lv_img_set_pivot(ui->ui_Oven_Img_Label_Bg, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Label_Bg, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Label_Bg, 0, 590);
	lv_obj_set_size(ui->ui_Oven_Img_Label_Bg, 654, 130);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Label_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Label_Bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Label_Bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Oven
	ui->ui_Oven_Label_Oven = lv_label_create(ui->ui_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Oven, "Oven");
	lv_label_set_long_mode(ui->ui_Oven_Label_Oven, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Oven, 541, 639);
	lv_obj_set_size(ui->ui_Oven_Label_Oven, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Oven, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Oven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Oven, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Oven, &lv_font_Antonio_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Oven, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Oven, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Oven, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Group_Oven
	ui->ui_Oven_Group_Oven = lv_obj_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Group_Oven, 677, 17);
	lv_obj_set_size(ui->ui_Oven_Group_Oven, 534, 686);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Group_Oven, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Group_Oven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Group_Oven, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Oven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Oven_Group_Oven, lv_color_hex(0x4A484A), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Group_Oven, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Group_Oven, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Oven_Group_Oven, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line
	ui->ui_Oven_line = lv_line_create(ui->ui_Oven_Group_Oven);
	static lv_point_t ui_Oven_line[] ={{0, 0},{519, 0},};
	lv_line_set_points(ui->ui_Oven_line, ui_Oven_line, 2);
	lv_obj_set_pos(ui->ui_Oven_line, 7, 7);
	lv_obj_set_size(ui->ui_Oven_line, 530, 24);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Oven_line, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Oven_line, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Oven_line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Oven_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_CurrTemp
	ui->ui_Oven_Label_CurrTemp = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_CurrTemp, "CURRENT TEMP.");
	lv_label_set_long_mode(ui->ui_Oven_Label_CurrTemp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_CurrTemp, 34, 49);
	lv_obj_set_size(ui->ui_Oven_Label_CurrTemp, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_CurrTemp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_CurrTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_CurrTemp, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_CurrTemp, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_CurrTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_CurrTemp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_CurrTemp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line_5
	ui->ui_Oven_line_5 = lv_line_create(ui->ui_Oven_Group_Oven);
	static lv_point_t ui_Oven_line_5[] ={{0, 0},{485, 0},};
	lv_line_set_points(ui->ui_Oven_line_5, ui_Oven_line_5, 2);
	lv_obj_set_pos(ui->ui_Oven_line_5, 23, 234);
	lv_obj_set_size(ui->ui_Oven_line_5, 495, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_5, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Oven_line_5, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Oven_line_5, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Oven_line_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line_4
	ui->ui_Oven_line_4 = lv_line_create(ui->ui_Oven_Group_Oven);
	static lv_point_t ui_Oven_line_4[] ={{0, 0},{485, 0},};
	lv_line_set_points(ui->ui_Oven_line_4, ui_Oven_line_4, 2);
	lv_obj_set_pos(ui->ui_Oven_line_4, 23, 379);
	lv_obj_set_size(ui->ui_Oven_line_4, 495, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_4, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Oven_line_4, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Oven_line_4, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Oven_line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line_3
	ui->ui_Oven_line_3 = lv_line_create(ui->ui_Oven_Group_Oven);
	static lv_point_t ui_Oven_line_3[] ={{0, 0},{235, 0},};
	lv_line_set_points(ui->ui_Oven_line_3, ui_Oven_line_3, 2);
	lv_obj_set_pos(ui->ui_Oven_line_3, 269, 117);
	lv_obj_set_size(ui->ui_Oven_line_3, 240, 7);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_3, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Oven_line_3, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Oven_line_3, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Oven_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line_2
	ui->ui_Oven_line_2 = lv_line_create(ui->ui_Oven_Group_Oven);
	static lv_point_t ui_Oven_line_2[] ={{0, 0},{0, 160},};
	lv_line_set_points(ui->ui_Oven_line_2, ui_Oven_line_2, 2);
	lv_obj_set_pos(ui->ui_Oven_line_2, 252, 52);
	lv_obj_set_size(ui->ui_Oven_line_2, 29, 169);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Oven_line_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Oven_line_2, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Oven_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line_1
	ui->ui_Oven_line_1 = lv_line_create(ui->ui_Oven_Group_Oven);
	static lv_point_t ui_Oven_line_1[] ={{0, 0},{0, 300},};
	lv_line_set_points(ui->ui_Oven_line_1, ui_Oven_line_1, 2);
	lv_obj_set_pos(ui->ui_Oven_line_1, 267, 441);
	lv_obj_set_size(ui->ui_Oven_line_1, 17, 146);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Oven_line_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Oven_line_1, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Oven_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Temp
	ui->ui_Oven_Label_Temp = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Temp, "250");
	lv_label_set_long_mode(ui->ui_Oven_Label_Temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Temp, 7, 89);
	lv_obj_set_size(ui->ui_Oven_Label_Temp, 214, 125);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Temp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Temp, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Temp, &lv_font_Antonio_Regular_120, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Temp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Cen
	ui->ui_Oven_Label_Cen = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Cen, "ºC");
	lv_label_set_long_mode(ui->ui_Oven_Label_Cen, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Cen, 175, 88);
	lv_obj_set_size(ui->ui_Oven_Label_Cen, 72, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Cen, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Cen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Cen, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Cen, &lv_font_Alatsi_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Cen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Cen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Cen, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Status
	ui->ui_Oven_Label_Status = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Status, "STATUS");
	lv_label_set_long_mode(ui->ui_Oven_Label_Status, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Status, 287, 34);
	lv_obj_set_size(ui->ui_Oven_Label_Status, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Status, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Status, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Status, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Status, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Status, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_CurrStat
	ui->ui_Oven_Label_CurrStat = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_CurrStat, "My Stat");
	lv_label_set_long_mode(ui->ui_Oven_Label_CurrStat, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_CurrStat, 329, 67);
	lv_obj_set_size(ui->ui_Oven_Label_CurrStat, 118, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_CurrStat, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_CurrStat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_CurrStat, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_CurrStat, &lv_font_Antonio_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_CurrStat, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_CurrStat, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_CurrStat, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Time
	ui->ui_Oven_Label_Time = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Time, "TIME\nLEFT");
	lv_label_set_long_mode(ui->ui_Oven_Label_Time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Time, 236, 132);
	lv_obj_set_size(ui->ui_Oven_Label_Time, 118, 57);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Time, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Time, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Time, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Time, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Bar_Time
	ui->ui_Oven_Bar_Time = lv_bar_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_style_anim_time(ui->ui_Oven_Bar_Time, 1000, 0);
	lv_bar_set_mode(ui->ui_Oven_Bar_Time, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->ui_Oven_Bar_Time, 30, LV_ANIM_OFF);
	lv_obj_set_pos(ui->ui_Oven_Bar_Time, 274, 195);
	lv_obj_set_size(ui->ui_Oven_Bar_Time, 225, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Bar_Time, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Bar_Time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Oven_Bar_Time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Oven_Bar_Time, lv_color_hex(0x4A4441), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Bar_Time, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Bar_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Oven_Bar_Time, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Oven_Bar_Time, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Oven_Bar_Time, lv_color_hex(0xFF9110), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Bar_Time, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode
	ui->ui_Oven_Label_Mode = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Mode, "MODE");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode, 208, 240);
	lv_obj_set_size(ui->ui_Oven_Label_Mode, 118, 57);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Btn_ModeLeft
	ui->ui_Oven_Btn_ModeLeft = lv_imgbtn_create(ui->ui_Oven_Group_Oven);
	lv_obj_add_flag(ui->ui_Oven_Btn_ModeLeft, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_PRESSED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_obj_add_flag(ui->ui_Oven_Btn_ModeLeft, LV_OBJ_FLAG_CHECKABLE);
	ui->ui_Oven_Btn_ModeLeft_label = lv_label_create(ui->ui_Oven_Btn_ModeLeft);
	lv_label_set_text(ui->ui_Oven_Btn_ModeLeft_label, "");
	lv_label_set_long_mode(ui->ui_Oven_Btn_ModeLeft_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Oven_Btn_ModeLeft_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Oven_Btn_ModeLeft, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Oven_Btn_ModeLeft, 27, 291);
	lv_obj_set_size(ui->ui_Oven_Btn_ModeLeft, 18, 35);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Btn_ModeLeft, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Btn_ModeLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Btn_ModeLeft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Btn_ModeLeft, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Btn_ModeLeft, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Btn_ModeLeft, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Btn_ModeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Oven_Btn_ModeLeft, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->ui_Oven_Btn_ModeLeft, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->ui_Oven_Btn_ModeLeft, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->ui_Oven_Btn_ModeLeft, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Btn_ModeLeft, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for ui_Oven_Btn_ModeLeft, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->ui_Oven_Btn_ModeLeft, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->ui_Oven_Btn_ModeLeft, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->ui_Oven_Btn_ModeLeft, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Btn_ModeLeft, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes ui_Oven_Btn_ModeRigth
	ui->ui_Oven_Btn_ModeRigth = lv_imgbtn_create(ui->ui_Oven_Group_Oven);
	lv_obj_add_flag(ui->ui_Oven_Btn_ModeRigth, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_PRESSED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_obj_add_flag(ui->ui_Oven_Btn_ModeRigth, LV_OBJ_FLAG_CHECKABLE);
	ui->ui_Oven_Btn_ModeRigth_label = lv_label_create(ui->ui_Oven_Btn_ModeRigth);
	lv_label_set_text(ui->ui_Oven_Btn_ModeRigth_label, "");
	lv_label_set_long_mode(ui->ui_Oven_Btn_ModeRigth_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Oven_Btn_ModeRigth_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Oven_Btn_ModeRigth, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Oven_Btn_ModeRigth, 486, 291);
	lv_obj_set_size(ui->ui_Oven_Btn_ModeRigth, 18, 35);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Btn_ModeRigth, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Btn_ModeRigth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Btn_ModeRigth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Btn_ModeRigth, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Btn_ModeRigth, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Btn_ModeRigth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Btn_ModeRigth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Btn_State
	ui->ui_Oven_Btn_State = lv_imgbtn_create(ui->ui_Oven_Group_Oven);
	lv_obj_add_flag(ui->ui_Oven_Btn_State, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_RELEASED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_PRESSED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_obj_add_flag(ui->ui_Oven_Btn_State, LV_OBJ_FLAG_CHECKABLE);
	ui->ui_Oven_Btn_State_label = lv_label_create(ui->ui_Oven_Btn_State);
	lv_label_set_text(ui->ui_Oven_Btn_State_label, "START");
	lv_label_set_long_mode(ui->ui_Oven_Btn_State_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Oven_Btn_State_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Oven_Btn_State, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Oven_Btn_State, 203, 607);
	lv_obj_set_size(ui->ui_Oven_Btn_State, 134, 51);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Btn_State, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Btn_State, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->ui_Oven_Btn_State, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->ui_Oven_Btn_State, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->ui_Oven_Btn_State, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Btn_State, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Btn_State, &lv_font_Antonio_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Btn_State, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Btn_State, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Oven_Btn_State, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->ui_Oven_Btn_State, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->ui_Oven_Btn_State, lv_color_hex(0x35C915), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->ui_Oven_Btn_State, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->ui_Oven_Btn_State, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->ui_Oven_Btn_State, &lv_font_Antonio_Regular_26, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Btn_State, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes ui_Oven_Label_Settings
	ui->ui_Oven_Label_Settings = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Settings, "SETTINGS");
	lv_label_set_long_mode(ui->ui_Oven_Label_Settings, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Settings, 206, 395);
	lv_obj_set_size(ui->ui_Oven_Label_Settings, 118, 46);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Settings, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Settings, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Settings, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Settings, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Settings, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_TimeLeft
	ui->ui_Oven_Label_TimeLeft = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_TimeLeft, "15");
	lv_label_set_long_mode(ui->ui_Oven_Label_TimeLeft, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_TimeLeft, 319, 130);
	lv_obj_set_size(ui->ui_Oven_Label_TimeLeft, 109, 51);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_TimeLeft, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_TimeLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_TimeLeft, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_TimeLeft, &lv_font_Antonio_Regular_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_TimeLeft, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_TimeLeft, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_TimeLeft, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Min
	ui->ui_Oven_Label_Min = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_label_set_text(ui->ui_Oven_Label_Min, "mins");
	lv_label_set_long_mode(ui->ui_Oven_Label_Min, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Min, 393, 146);
	lv_obj_set_size(ui->ui_Oven_Label_Min, 63, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Min, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Min, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Min, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Min, &lv_font_Alatsi_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Min, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Min, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Min, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Tile_Mode
	ui->ui_Oven_Tile_Mode = lv_tileview_create(ui->ui_Oven);
	ui->ui_Oven_Tile_Mode_Mode_1 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 0, 0, LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_2 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_3 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 2, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_4 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 3, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_5 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 4, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_6 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 5, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_7 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 6, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_8 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 7, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->ui_Oven_Tile_Mode_Mode_9 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 8, 0, LV_DIR_LEFT);
	lv_obj_set_pos(ui->ui_Oven_Tile_Mode, 728, 294);
	lv_obj_set_size(ui->ui_Oven_Tile_Mode, 430, 86);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Tile_Mode, LV_SCROLLBAR_MODE_ON);

	//Write style for ui_Oven_Tile_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Oven_Tile_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Tile_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Tile_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Oven_Tile_Mode, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Oven_Tile_Mode, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Tile_Mode, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode1
	ui->ui_Oven_Img_Mode1 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_1);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode1, &_icn_oven_fan_rear_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode1, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode1, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode1, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode1, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode1
	ui->ui_Oven_Label_Mode1 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_1);
	lv_label_set_text(ui->ui_Oven_Label_Mode1, "Fan Forced\nRear Element");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode1, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode1, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode1, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode2
	ui->ui_Oven_Img_Mode2 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_2);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode2, &_icn_oven_upper_lower_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode2, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode2, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode2, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode2, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode2
	ui->ui_Oven_Label_Mode2 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_2);
	lv_label_set_text(ui->ui_Oven_Label_Mode2, "Upper & Lower\nElements\nConvection");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode2, 211, 7);
	lv_obj_set_size(ui->ui_Oven_Label_Mode2, 141, 66);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode2, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode2, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Label_Mode3
	ui->ui_Oven_Label_Mode3 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_3);
	lv_label_set_text(ui->ui_Oven_Label_Mode3, "Fan Forced\nUpper & Lower\nConvection");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode3, 211, 7);
	lv_obj_set_size(ui->ui_Oven_Label_Mode3, 141, 66);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode3, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode3, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode3, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_Mode3
	ui->ui_Oven_Img_Mode3 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_3);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode3, &_icn_oven_fan_upper_lower_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode3, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode3, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode3, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode3, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode3, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode4
	ui->ui_Oven_Img_Mode4 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_4);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode4, &_icn_oven_fan_lower_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode4, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode4, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode4, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode4, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode4, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode4
	ui->ui_Oven_Label_Mode4 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_4);
	lv_label_set_text(ui->ui_Oven_Label_Mode4, "Fan Forced\nLower Element\nConvection");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode4, 211, 7);
	lv_obj_set_size(ui->ui_Oven_Label_Mode4, 141, 66);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode4, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode4, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode4, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode5
	ui->ui_Oven_Img_Mode5 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_5);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode5, &_icn_oven_gril_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode5, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode5, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode5, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode5, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode5, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode5
	ui->ui_Oven_Label_Mode5 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_5);
	lv_label_set_text(ui->ui_Oven_Label_Mode5, "Grill");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode5, 220, 22);
	lv_obj_set_size(ui->ui_Oven_Label_Mode5, 141, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode5, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode5, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode5, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode6
	ui->ui_Oven_Img_Mode6 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_6);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode6, &_icn_oven_fan_gril_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode6, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode6, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode6, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode6, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode6, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode6
	ui->ui_Oven_Label_Mode6 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_6);
	lv_label_set_text(ui->ui_Oven_Label_Mode6, "Fan Forced\nGrill");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode6, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode6, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode6, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode6, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode6, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode7
	ui->ui_Oven_Img_Mode7 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_7);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode7, &_icn_oven_upper_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode7, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode7, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode7, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode7, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode7, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode7
	ui->ui_Oven_Label_Mode7 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_7);
	lv_label_set_text(ui->ui_Oven_Label_Mode7, "Upper Outer\nElement");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode7, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode7, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode7, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode7, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode7, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode8
	ui->ui_Oven_Img_Mode8 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_8);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode8, &_icn_oven_lower_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode8, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode8, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode8, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode8, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode8, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode8
	ui->ui_Oven_Label_Mode8 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_8);
	lv_label_set_text(ui->ui_Oven_Label_Mode8, "Lower Outer\nElement");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode8, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode8, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode8, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode8, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode8, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes ui_Oven_Img_Mode9
	ui->ui_Oven_Img_Mode9 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_9);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode9, &_icn_oven_defrost_alpha_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode9, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode9, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode9, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode9, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode9, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_Mode9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_Mode9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Mode9
	ui->ui_Oven_Label_Mode9 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_9);
	lv_label_set_text(ui->ui_Oven_Label_Mode9, "Defrost");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode9, 220, 22);
	lv_obj_set_size(ui->ui_Oven_Label_Mode9, 141, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode9, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_Mode9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_Mode9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_Mode9, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_Mode9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_Mode9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_Mode9, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Group_TarTemp
	ui->ui_Oven_Group_TarTemp = lv_obj_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Group_TarTemp, 697, 427);
	lv_obj_set_size(ui->ui_Oven_Group_TarTemp, 235, 240);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Group_TarTemp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Group_TarTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Group_TarTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Oven_Group_TarTemp, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_TempWheel
	ui->ui_Oven_Img_TempWheel = lv_img_create(ui->ui_Oven_Group_TarTemp);
	lv_obj_add_flag(ui->ui_Oven_Img_TempWheel, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_TempWheel, &_wheel_bg_alpha_151x259);
	lv_img_set_pivot(ui->ui_Oven_Img_TempWheel, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_TempWheel, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_TempWheel, 51, -11);
	lv_obj_set_size(ui->ui_Oven_Img_TempWheel, 151, 259);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_TempWheel, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_TempWheel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_TempWheel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_SelTemp
	ui->ui_Oven_Label_SelTemp = lv_label_create(ui->ui_Oven_Group_TarTemp);
	lv_label_set_text(ui->ui_Oven_Label_SelTemp, "TARGET\nTEMP.");
	lv_label_set_long_mode(ui->ui_Oven_Label_SelTemp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_SelTemp, -11, 91);
	lv_obj_set_size(ui->ui_Oven_Label_SelTemp, 118, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_SelTemp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_SelTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_SelTemp, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_SelTemp, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_SelTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_SelTemp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_SelTemp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_TarCen
	ui->ui_Oven_Label_TarCen = lv_label_create(ui->ui_Oven_Group_TarTemp);
	lv_label_set_text(ui->ui_Oven_Label_TarCen, "ºC");
	lv_label_set_long_mode(ui->ui_Oven_Label_TarCen, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_TarCen, 68, 111);
	lv_obj_set_size(ui->ui_Oven_Label_TarCen, 55, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_TarCen, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_TarCen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_TarCen, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_TarCen, &lv_font_Alatsi_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_TarCen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_TarCen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_TarCen, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Group_Timer
	ui->ui_Oven_Group_Timer = lv_obj_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Group_Timer, 957, 427);
	lv_obj_set_size(ui->ui_Oven_Group_Timer, 235, 240);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Group_Timer, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Group_Timer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Group_Timer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Oven_Group_Timer, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_TimerWheel
	ui->ui_Oven_Img_TimerWheel = lv_img_create(ui->ui_Oven_Group_Timer);
	lv_obj_add_flag(ui->ui_Oven_Img_TimerWheel, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_TimerWheel, &_wheel_bg_2_alpha_151x259);
	lv_img_set_pivot(ui->ui_Oven_Img_TimerWheel, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_TimerWheel, 0);
	lv_obj_set_pos(ui->ui_Oven_Img_TimerWheel, 39, -11);
	lv_obj_set_size(ui->ui_Oven_Img_TimerWheel, 151, 259);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_TimerWheel, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Img_TimerWheel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Oven_Img_TimerWheel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_SelTimer
	ui->ui_Oven_Label_SelTimer = lv_label_create(ui->ui_Oven_Group_Timer);
	lv_label_set_text(ui->ui_Oven_Label_SelTimer, "SETUP\nTIMER");
	lv_label_set_long_mode(ui->ui_Oven_Label_SelTimer, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_SelTimer, 148, 91);
	lv_obj_set_size(ui->ui_Oven_Label_SelTimer, 104, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_SelTimer, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_SelTimer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_SelTimer, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_SelTimer, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_SelTimer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_SelTimer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_SelTimer, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_TimerSel
	ui->ui_Oven_Label_TimerSel = lv_label_create(ui->ui_Oven_Group_Timer);
	lv_label_set_text(ui->ui_Oven_Label_TimerSel, "mins");
	lv_label_set_long_mode(ui->ui_Oven_Label_TimerSel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Oven_Label_TimerSel, 114, 108);
	lv_obj_set_size(ui->ui_Oven_Label_TimerSel, 63, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_TimerSel, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_Label_TimerSel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_Label_TimerSel, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_Label_TimerSel, &lv_font_Alatsi_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Oven_Label_TimerSel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_Label_TimerSel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Oven_Label_TimerSel, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Lottie_Mic
	ui->ui_Oven_Lottie_Mic = lv_rlottie_create_from_raw(ui->ui_Oven, 62, 74, (const void *)lottie_lf30_gbhpz7py);
	lv_obj_set_pos(ui->ui_Oven_Lottie_Mic, 8, 639);
	lv_obj_set_size(ui->ui_Oven_Lottie_Mic, 62, 74);

	//Write style for ui_Oven_Lottie_Mic, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Oven_Lottie_Mic, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_ui_Btn_Back3
	ui->ui_Oven_ui_Btn_Back3 = lv_btn_create(ui->ui_Oven);
	ui->ui_Oven_ui_Btn_Back3_label = lv_label_create(ui->ui_Oven_ui_Btn_Back3);
	lv_label_set_text(ui->ui_Oven_ui_Btn_Back3_label, "BACK");
	lv_label_set_long_mode(ui->ui_Oven_ui_Btn_Back3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Oven_ui_Btn_Back3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Oven_ui_Btn_Back3, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Oven_ui_Btn_Back3, -41, 24);
	lv_obj_set_size(ui->ui_Oven_ui_Btn_Back3, 155, 65);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_ui_Btn_Back3, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Oven_ui_Btn_Back3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Oven_ui_Btn_Back3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Oven_ui_Btn_Back3, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Oven_ui_Btn_Back3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Oven_ui_Btn_Back3, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Oven_ui_Btn_Back3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Oven_ui_Btn_Back3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Oven_ui_Btn_Back3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Oven_ui_Btn_Back3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->ui_Oven);

	
	//Init events for screen.
	events_init_ui_Oven(ui);
}
