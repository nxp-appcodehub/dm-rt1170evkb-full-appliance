/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_ui_Aircon(lv_ui *ui){

	//Write codes ui_Aircon
	ui->ui_Aircon = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_main_main_default
	static lv_style_t style_ui_aircon_main_main_default;
	if (style_ui_aircon_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_main_main_default);
	else
		lv_style_init(&style_ui_aircon_main_main_default);
	lv_style_set_bg_color(&style_ui_aircon_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_ui_aircon_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon, &style_ui_aircon_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Bg
	ui->ui_Aircon_Img_Bg = lv_img_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_Img_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Aircon_Img_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_bg_main_main_default
	static lv_style_t style_ui_aircon_img_bg_main_main_default;
	if (style_ui_aircon_img_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_bg_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_bg_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_bg_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_Bg, &style_ui_aircon_img_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Bg,&_aircon_bg_1280x720);
	lv_img_set_pivot(ui->ui_Aircon_Img_Bg, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Bg, 0);

	//Write codes ui_Aircon_Img_Lable_Bg
	ui->ui_Aircon_Img_Lable_Bg = lv_img_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_Img_Lable_Bg, 0, 590);
	lv_obj_set_size(ui->ui_Aircon_Img_Lable_Bg, 799, 130);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Lable_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_lable_bg_main_main_default
	static lv_style_t style_ui_aircon_img_lable_bg_main_main_default;
	if (style_ui_aircon_img_lable_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_lable_bg_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_lable_bg_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_lable_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_lable_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_lable_bg_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_Lable_Bg, &style_ui_aircon_img_lable_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_Lable_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Lable_Bg,&_title_bg_799x130);
	lv_img_set_pivot(ui->ui_Aircon_Img_Lable_Bg, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Lable_Bg, 0);

	//Write codes ui_Aircon_Label_Air
	ui->ui_Aircon_Label_Air = lv_label_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_Label_Air, 565, 639);
	lv_obj_set_size(ui->ui_Aircon_Label_Air, 180, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Air, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Air, "Air Conditioner");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Air, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_air_main_main_default
	static lv_style_t style_ui_aircon_label_air_main_main_default;
	if (style_ui_aircon_label_air_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_air_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_air_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_air_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_air_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_air_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_air_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_air_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_air_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_air_main_main_default, &lv_font_Amiko_Regular_18);
	lv_style_set_text_letter_space(&style_ui_aircon_label_air_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_air_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_air_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_air_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_air_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_air_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_air_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Air, &style_ui_aircon_label_air_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Swing
	ui->ui_Aircon_Img_Swing = lv_img_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_Img_Swing, 120, 380);
	lv_obj_set_size(ui->ui_Aircon_Img_Swing, 632, 113);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Swing, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_swing_main_main_default
	static lv_style_t style_ui_aircon_img_swing_main_main_default;
	if (style_ui_aircon_img_swing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_swing_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_swing_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_swing_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_swing_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_swing_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_Swing, &style_ui_aircon_img_swing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_Swing, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Swing,&_aircon_swing_1_632x113);
	lv_img_set_pivot(ui->ui_Aircon_Img_Swing, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Swing, 0);

	//Write codes ui_Aircon_cont_1
	ui->ui_Aircon_cont_1 = lv_obj_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_cont_1, 826, 30);
	lv_obj_set_size(ui->ui_Aircon_cont_1, 409, 657);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_cont_1_main_main_default
	static lv_style_t style_ui_aircon_cont_1_main_main_default;
	if (style_ui_aircon_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_cont_1_main_main_default);
	else
		lv_style_init(&style_ui_aircon_cont_1_main_main_default);
	lv_style_set_radius(&style_ui_aircon_cont_1_main_main_default, 20);
	lv_style_set_bg_color(&style_ui_aircon_cont_1_main_main_default, lv_color_make(0x24, 0x24, 0x24));
	lv_style_set_bg_grad_color(&style_ui_aircon_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_aircon_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_cont_1_main_main_default, 250);
	lv_style_set_border_color(&style_ui_aircon_cont_1_main_main_default, lv_color_make(0x4A, 0x4C, 0x4A));
	lv_style_set_border_width(&style_ui_aircon_cont_1_main_main_default, 1);
	lv_style_set_border_opa(&style_ui_aircon_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_ui_aircon_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_aircon_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_cont_1, &style_ui_aircon_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line
	ui->ui_Aircon_line = lv_line_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_line, 7, 7);
	lv_obj_set_size(ui->ui_Aircon_line, 405, 24);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_line_main_main_default
	static lv_style_t style_ui_aircon_line_main_main_default;
	if (style_ui_aircon_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_line_main_main_default);
	else
		lv_style_init(&style_ui_aircon_line_main_main_default);
	lv_style_set_line_color(&style_ui_aircon_line_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_line_width(&style_ui_aircon_line_main_main_default, 17);
	lv_style_set_line_rounded(&style_ui_aircon_line_main_main_default, true);
	lv_obj_add_style(ui->ui_Aircon_line, &style_ui_aircon_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Aircon_line[] ={{0, 0},{393, 0},};
	lv_line_set_points(ui->ui_Aircon_line,ui_Aircon_line,2);

	//Write codes ui_Aircon_Label_Temp
	ui->ui_Aircon_Label_Temp = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Temp, 12, 58);
	lv_obj_set_size(ui->ui_Aircon_Label_Temp, 151, 123);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Temp, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Temp, "25");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Temp, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_temp_main_main_default
	static lv_style_t style_ui_aircon_label_temp_main_main_default;
	if (style_ui_aircon_label_temp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_temp_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_temp_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_temp_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_temp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_temp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_temp_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_temp_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_temp_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_temp_main_main_default, &lv_font_Antonio_Regular_120);
	lv_style_set_text_letter_space(&style_ui_aircon_label_temp_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_temp_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_temp_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_temp_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_temp_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_temp_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_temp_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Temp, &style_ui_aircon_label_temp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Btn_TempUp
	ui->ui_Aircon_Btn_TempUp = lv_btn_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TempUp, 198, 100);
	lv_obj_set_size(ui->ui_Aircon_Btn_TempUp, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TempUp, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_btn_tempup_main_main_default
	static lv_style_t style_ui_aircon_btn_tempup_main_main_default;
	if (style_ui_aircon_btn_tempup_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_tempup_main_main_default);
	else
		lv_style_init(&style_ui_aircon_btn_tempup_main_main_default);
	lv_style_set_radius(&style_ui_aircon_btn_tempup_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_tempup_main_main_default, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_tempup_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_tempup_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_tempup_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_tempup_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_tempup_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_tempup_main_main_default, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_tempup_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_aircon_btn_tempup_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Aircon_Btn_TempUp, &style_ui_aircon_btn_tempup_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_ui_aircon_btn_tempup_main_main_pressed
	static lv_style_t style_ui_aircon_btn_tempup_main_main_pressed;
	if (style_ui_aircon_btn_tempup_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_tempup_main_main_pressed);
	else
		lv_style_init(&style_ui_aircon_btn_tempup_main_main_pressed);
	lv_style_set_radius(&style_ui_aircon_btn_tempup_main_main_pressed, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_tempup_main_main_pressed, lv_color_make(0x18, 0xC2, 0x20));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_tempup_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_tempup_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_tempup_main_main_pressed, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_tempup_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_tempup_main_main_pressed, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_tempup_main_main_pressed, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_tempup_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->ui_Aircon_Btn_TempUp, &style_ui_aircon_btn_tempup_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
	ui->ui_Aircon_Btn_TempUp_label = lv_label_create(ui->ui_Aircon_Btn_TempUp);
	lv_label_set_text(ui->ui_Aircon_Btn_TempUp_label, "");
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TempUp, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Aircon_Btn_TempUp_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Aircon_Label_SetTemp
	ui->ui_Aircon_Label_SetTemp = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_SetTemp, 110, 22);
	lv_obj_set_size(ui->ui_Aircon_Label_SetTemp, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_SetTemp, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_SetTemp, "SET TEMPERATURE");
	lv_label_set_long_mode(ui->ui_Aircon_Label_SetTemp, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_settemp_main_main_default
	static lv_style_t style_ui_aircon_label_settemp_main_main_default;
	if (style_ui_aircon_label_settemp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_settemp_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_settemp_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_settemp_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_settemp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_settemp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_settemp_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_settemp_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_settemp_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_label_settemp_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_aircon_label_settemp_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_settemp_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_settemp_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_settemp_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_settemp_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_settemp_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_settemp_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_SetTemp, &style_ui_aircon_label_settemp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Cen
	ui->ui_Aircon_Label_Cen = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Cen, 121, 61);
	lv_obj_set_size(ui->ui_Aircon_Label_Cen, 72, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Cen, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Cen, "ºC");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Cen, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_cen_main_main_default
	static lv_style_t style_ui_aircon_label_cen_main_main_default;
	if (style_ui_aircon_label_cen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_cen_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_cen_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_cen_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_cen_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_cen_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_cen_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_cen_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_cen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_cen_main_main_default, &lv_font_Alatsi_Regular_26);
	lv_style_set_text_letter_space(&style_ui_aircon_label_cen_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_cen_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_cen_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_cen_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_cen_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_cen_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_cen_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Cen, &style_ui_aircon_label_cen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Btn_TempDown
	ui->ui_Aircon_Btn_TempDown = lv_btn_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TempDown, 295, 100);
	lv_obj_set_size(ui->ui_Aircon_Btn_TempDown, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TempDown, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_btn_tempdown_main_main_default
	static lv_style_t style_ui_aircon_btn_tempdown_main_main_default;
	if (style_ui_aircon_btn_tempdown_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_tempdown_main_main_default);
	else
		lv_style_init(&style_ui_aircon_btn_tempdown_main_main_default);
	lv_style_set_radius(&style_ui_aircon_btn_tempdown_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_tempdown_main_main_default, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_tempdown_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_tempdown_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_tempdown_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_tempdown_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_tempdown_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_tempdown_main_main_default, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_tempdown_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_aircon_btn_tempdown_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Aircon_Btn_TempDown, &style_ui_aircon_btn_tempdown_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_ui_aircon_btn_tempdown_main_main_pressed
	static lv_style_t style_ui_aircon_btn_tempdown_main_main_pressed;
	if (style_ui_aircon_btn_tempdown_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_tempdown_main_main_pressed);
	else
		lv_style_init(&style_ui_aircon_btn_tempdown_main_main_pressed);
	lv_style_set_radius(&style_ui_aircon_btn_tempdown_main_main_pressed, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_tempdown_main_main_pressed, lv_color_make(0x18, 0xC2, 0x20));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_tempdown_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_tempdown_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_tempdown_main_main_pressed, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_tempdown_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_tempdown_main_main_pressed, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_tempdown_main_main_pressed, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_tempdown_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->ui_Aircon_Btn_TempDown, &style_ui_aircon_btn_tempdown_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
	ui->ui_Aircon_Btn_TempDown_label = lv_label_create(ui->ui_Aircon_Btn_TempDown);
	lv_label_set_text(ui->ui_Aircon_Btn_TempDown_label, "");
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TempDown, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Aircon_Btn_TempDown_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Aircon_Img_TemUp
	ui->ui_Aircon_Img_TemUp = lv_img_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Img_TemUp, 222, 122);
	lv_obj_set_size(ui->ui_Aircon_Img_TemUp, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TemUp, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_temup_main_main_default
	static lv_style_t style_ui_aircon_img_temup_main_main_default;
	if (style_ui_aircon_img_temup_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_temup_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_temup_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_temup_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_temup_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_temup_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_TemUp, &style_ui_aircon_img_temup_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_TemUp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TemUp,&_arrow_up_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TemUp, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TemUp, 0);

	//Write codes ui_Aircon_Img_TempDown
	ui->ui_Aircon_Img_TempDown = lv_img_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Img_TempDown, 319, 122);
	lv_obj_set_size(ui->ui_Aircon_Img_TempDown, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TempDown, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_tempdown_main_main_default
	static lv_style_t style_ui_aircon_img_tempdown_main_main_default;
	if (style_ui_aircon_img_tempdown_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_tempdown_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_tempdown_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_tempdown_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_tempdown_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_tempdown_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_TempDown, &style_ui_aircon_img_tempdown_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_TempDown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TempDown,&_arrow_down_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TempDown, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TempDown, 0);

	//Write codes ui_Aircon_Roller_Mode
	ui->ui_Aircon_Roller_Mode = lv_roller_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Roller_Mode, 40, 404);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Roller_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_roller_mode_main_main_default
	static lv_style_t style_ui_aircon_roller_mode_main_main_default;
	if (style_ui_aircon_roller_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_roller_mode_main_main_default);
	else
		lv_style_init(&style_ui_aircon_roller_mode_main_main_default);
	lv_style_set_radius(&style_ui_aircon_roller_mode_main_main_default, 5);
	lv_style_set_bg_color(&style_ui_aircon_roller_mode_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_ui_aircon_roller_mode_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_aircon_roller_mode_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_roller_mode_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_roller_mode_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_ui_aircon_roller_mode_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_aircon_roller_mode_main_main_default, 255);
	lv_style_set_text_color(&style_ui_aircon_roller_mode_main_main_default, lv_color_make(0x9D, 0x9D, 0x9D));
	lv_style_set_text_font(&style_ui_aircon_roller_mode_main_main_default, &lv_font_Antonio_Regular_21);
	lv_obj_add_style(ui->ui_Aircon_Roller_Mode, &style_ui_aircon_roller_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_roller_mode_main_selected_default
	static lv_style_t style_ui_aircon_roller_mode_main_selected_default;
	if (style_ui_aircon_roller_mode_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_roller_mode_main_selected_default);
	else
		lv_style_init(&style_ui_aircon_roller_mode_main_selected_default);
	lv_style_set_bg_color(&style_ui_aircon_roller_mode_main_selected_default, lv_color_make(0x20, 0xA1, 0xC5));
	lv_style_set_bg_grad_color(&style_ui_aircon_roller_mode_main_selected_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_roller_mode_main_selected_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_roller_mode_main_selected_default, 255);
	lv_style_set_text_color(&style_ui_aircon_roller_mode_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_roller_mode_main_selected_default, &lv_font_Antonio_Regular_21);
	lv_obj_add_style(ui->ui_Aircon_Roller_Mode, &style_ui_aircon_roller_mode_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->ui_Aircon_Roller_Mode,"COOL\nDRY\nFAN",LV_ROLLER_MODE_INFINITE);
	lv_roller_set_visible_row_count(ui->ui_Aircon_Roller_Mode,3);

	//Write codes ui_Aircon_Btn_Swing
	ui->ui_Aircon_Btn_Swing = lv_btn_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Btn_Swing, 99, 572);
	lv_obj_set_size(ui->ui_Aircon_Btn_Swing, 78, 45);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_Swing, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_btn_swing_main_main_default
	static lv_style_t style_ui_aircon_btn_swing_main_main_default;
	if (style_ui_aircon_btn_swing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_swing_main_main_default);
	else
		lv_style_init(&style_ui_aircon_btn_swing_main_main_default);
	lv_style_set_radius(&style_ui_aircon_btn_swing_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_swing_main_main_default, lv_color_make(0x6A, 0x6A, 0x6A));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_swing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_swing_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_swing_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_swing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_swing_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_swing_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_btn_swing_main_main_default, lv_color_make(0x9D, 0x9D, 0x9D));
	lv_style_set_text_font(&style_ui_aircon_btn_swing_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_align(&style_ui_aircon_btn_swing_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Aircon_Btn_Swing, &style_ui_aircon_btn_swing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_ui_aircon_btn_swing_main_main_pressed
	static lv_style_t style_ui_aircon_btn_swing_main_main_pressed;
	if (style_ui_aircon_btn_swing_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_swing_main_main_pressed);
	else
		lv_style_init(&style_ui_aircon_btn_swing_main_main_pressed);
	lv_style_set_radius(&style_ui_aircon_btn_swing_main_main_pressed, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_swing_main_main_pressed, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_swing_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_swing_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_swing_main_main_pressed, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_swing_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_swing_main_main_pressed, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_swing_main_main_pressed, 0);
	lv_style_set_text_color(&style_ui_aircon_btn_swing_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_btn_swing_main_main_pressed, &lv_font_Antonio_Regular_20);
	lv_obj_add_style(ui->ui_Aircon_Btn_Swing, &style_ui_aircon_btn_swing_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_ui_aircon_btn_swing_main_main_checked
	static lv_style_t style_ui_aircon_btn_swing_main_main_checked;
	if (style_ui_aircon_btn_swing_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_swing_main_main_checked);
	else
		lv_style_init(&style_ui_aircon_btn_swing_main_main_checked);
	lv_style_set_radius(&style_ui_aircon_btn_swing_main_main_checked, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_swing_main_main_checked, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_swing_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_swing_main_main_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_swing_main_main_checked, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_swing_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_swing_main_main_checked, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_swing_main_main_checked, 0);
	lv_style_set_text_color(&style_ui_aircon_btn_swing_main_main_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_btn_swing_main_main_checked, &lv_font_Antonio_Regular_20);
	lv_obj_add_style(ui->ui_Aircon_Btn_Swing, &style_ui_aircon_btn_swing_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_add_flag(ui->ui_Aircon_Btn_Swing, LV_OBJ_FLAG_CHECKABLE);
	ui->ui_Aircon_Btn_Swing_label = lv_label_create(ui->ui_Aircon_Btn_Swing);
	lv_label_set_text(ui->ui_Aircon_Btn_Swing_label, "OFF");
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_Swing, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Aircon_Btn_Swing_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Aircon_Label_Swing
	ui->ui_Aircon_Label_Swing = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Swing, 30, 576);
	lv_obj_set_size(ui->ui_Aircon_Label_Swing, 73, 38);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Swing, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Swing, "SWING");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Swing, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_swing_main_main_default
	static lv_style_t style_ui_aircon_label_swing_main_main_default;
	if (style_ui_aircon_label_swing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_swing_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_swing_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_swing_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_swing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_swing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_swing_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_swing_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_swing_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_label_swing_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_aircon_label_swing_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_swing_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_swing_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_swing_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_swing_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_swing_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_swing_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Swing, &style_ui_aircon_label_swing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line_1
	ui->ui_Aircon_line_1 = lv_line_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_line_1, 23, 199);
	lv_obj_set_size(ui->ui_Aircon_line_1, 371, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_line_1_main_main_default
	static lv_style_t style_ui_aircon_line_1_main_main_default;
	if (style_ui_aircon_line_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_line_1_main_main_default);
	else
		lv_style_init(&style_ui_aircon_line_1_main_main_default);
	lv_style_set_line_color(&style_ui_aircon_line_1_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_aircon_line_1_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_aircon_line_1_main_main_default, false);
	lv_obj_add_style(ui->ui_Aircon_line_1, &style_ui_aircon_line_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Aircon_line_1[] ={{0, 0},{360, 0},};
	lv_line_set_points(ui->ui_Aircon_line_1,ui_Aircon_line_1,2);

	//Write codes ui_Aircon_line_2
	ui->ui_Aircon_line_2 = lv_line_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_line_2, 23, 359);
	lv_obj_set_size(ui->ui_Aircon_line_2, 371, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_line_2_main_main_default
	static lv_style_t style_ui_aircon_line_2_main_main_default;
	if (style_ui_aircon_line_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_line_2_main_main_default);
	else
		lv_style_init(&style_ui_aircon_line_2_main_main_default);
	lv_style_set_line_color(&style_ui_aircon_line_2_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_aircon_line_2_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_aircon_line_2_main_main_default, false);
	lv_obj_add_style(ui->ui_Aircon_line_2, &style_ui_aircon_line_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Aircon_line_2[] ={{0, 0},{360, 0},};
	lv_line_set_points(ui->ui_Aircon_line_2,ui_Aircon_line_2,2);

	//Write codes ui_Aircon_line_3
	ui->ui_Aircon_line_3 = lv_line_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_line_3, 23, 540);
	lv_obj_set_size(ui->ui_Aircon_line_3, 371, 7);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_line_3_main_main_default
	static lv_style_t style_ui_aircon_line_3_main_main_default;
	if (style_ui_aircon_line_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_line_3_main_main_default);
	else
		lv_style_init(&style_ui_aircon_line_3_main_main_default);
	lv_style_set_line_color(&style_ui_aircon_line_3_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_aircon_line_3_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_aircon_line_3_main_main_default, false);
	lv_obj_add_style(ui->ui_Aircon_line_3, &style_ui_aircon_line_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Aircon_line_3[] ={{0, 0},{360, 0},};
	lv_line_set_points(ui->ui_Aircon_line_3,ui_Aircon_line_3,2);

	//Write codes ui_Aircon_line_4
	ui->ui_Aircon_line_4 = lv_line_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_line_4, 242, 410);
	lv_obj_set_size(ui->ui_Aircon_line_4, 29, 119);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_line_4_main_main_default
	static lv_style_t style_ui_aircon_line_4_main_main_default;
	if (style_ui_aircon_line_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_line_4_main_main_default);
	else
		lv_style_init(&style_ui_aircon_line_4_main_main_default);
	lv_style_set_line_color(&style_ui_aircon_line_4_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_aircon_line_4_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_aircon_line_4_main_main_default, false);
	lv_obj_add_style(ui->ui_Aircon_line_4, &style_ui_aircon_line_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Aircon_line_4[] ={{0, 0},{0, 100},};
	lv_line_set_points(ui->ui_Aircon_line_4,ui_Aircon_line_4,2);

	//Write codes ui_Aircon_line_5
	ui->ui_Aircon_line_5 = lv_line_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_line_5, 192, 568);
	lv_obj_set_size(ui->ui_Aircon_line_5, 17, 67);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_line_5_main_main_default
	static lv_style_t style_ui_aircon_line_5_main_main_default;
	if (style_ui_aircon_line_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_line_5_main_main_default);
	else
		lv_style_init(&style_ui_aircon_line_5_main_main_default);
	lv_style_set_line_color(&style_ui_aircon_line_5_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_aircon_line_5_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_aircon_line_5_main_main_default, false);
	lv_obj_add_style(ui->ui_Aircon_line_5, &style_ui_aircon_line_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Aircon_line_5[] ={{0, 0},{0, 50},};
	lv_line_set_points(ui->ui_Aircon_line_5,ui_Aircon_line_5,2);

	//Write codes ui_Aircon_Label_Timer
	ui->ui_Aircon_Label_Timer = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Timer, 105, 202);
	lv_obj_set_size(ui->ui_Aircon_Label_Timer, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Timer, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Timer, "SET TIMER");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Timer, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_timer_main_main_default
	static lv_style_t style_ui_aircon_label_timer_main_main_default;
	if (style_ui_aircon_label_timer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_timer_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_timer_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_timer_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_timer_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_timer_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_timer_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_timer_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_timer_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_label_timer_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_aircon_label_timer_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_timer_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_timer_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_timer_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_timer_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_timer_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_timer_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Timer, &style_ui_aircon_label_timer_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Mode
	ui->ui_Aircon_Label_Mode = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Mode, 123, 364);
	lv_obj_set_size(ui->ui_Aircon_Label_Mode, 178, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Mode, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Mode, "SELECT MODE");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Mode, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_mode_main_main_default
	static lv_style_t style_ui_aircon_label_mode_main_main_default;
	if (style_ui_aircon_label_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_mode_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_mode_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_mode_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_mode_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_mode_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_mode_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_label_mode_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_aircon_label_mode_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_mode_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_mode_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_mode_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_mode_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_mode_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_mode_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Mode, &style_ui_aircon_label_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Fan
	ui->ui_Aircon_Label_Fan = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Fan, 204, 571);
	lv_obj_set_size(ui->ui_Aircon_Label_Fan, 45, 38);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Fan, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Fan, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_fan_main_main_default
	static lv_style_t style_ui_aircon_label_fan_main_main_default;
	if (style_ui_aircon_label_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_fan_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_fan_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_fan_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_fan_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_fan_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_fan_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_label_fan_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_aircon_label_fan_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_fan_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_fan_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_fan_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_fan_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_fan_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_fan_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Fan, &style_ui_aircon_label_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Slider_Fan
	ui->ui_Aircon_Slider_Fan = lv_slider_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Slider_Fan, 257, 579);
	lv_obj_set_size(ui->ui_Aircon_Slider_Fan, 127, 16);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Slider_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_slider_fan_main_main_default
	static lv_style_t style_ui_aircon_slider_fan_main_main_default;
	if (style_ui_aircon_slider_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_slider_fan_main_main_default);
	else
		lv_style_init(&style_ui_aircon_slider_fan_main_main_default);
	lv_style_set_radius(&style_ui_aircon_slider_fan_main_main_default, 50);
	lv_style_set_bg_color(&style_ui_aircon_slider_fan_main_main_default, lv_color_make(0x6A, 0x6A, 0x6A));
	lv_style_set_bg_grad_color(&style_ui_aircon_slider_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_slider_fan_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_slider_fan_main_main_default, 255);
	lv_style_set_outline_color(&style_ui_aircon_slider_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_ui_aircon_slider_fan_main_main_default, 0);
	lv_style_set_outline_opa(&style_ui_aircon_slider_fan_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Slider_Fan, &style_ui_aircon_slider_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_slider_fan_main_indicator_default
	static lv_style_t style_ui_aircon_slider_fan_main_indicator_default;
	if (style_ui_aircon_slider_fan_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_slider_fan_main_indicator_default);
	else
		lv_style_init(&style_ui_aircon_slider_fan_main_indicator_default);
	lv_style_set_radius(&style_ui_aircon_slider_fan_main_indicator_default, 50);
	lv_style_set_bg_color(&style_ui_aircon_slider_fan_main_indicator_default, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_slider_fan_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_slider_fan_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_slider_fan_main_indicator_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Slider_Fan, &style_ui_aircon_slider_fan_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_slider_fan_main_knob_default
	static lv_style_t style_ui_aircon_slider_fan_main_knob_default;
	if (style_ui_aircon_slider_fan_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_slider_fan_main_knob_default);
	else
		lv_style_init(&style_ui_aircon_slider_fan_main_knob_default);
	lv_style_set_radius(&style_ui_aircon_slider_fan_main_knob_default, 50);
	lv_style_set_bg_color(&style_ui_aircon_slider_fan_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_aircon_slider_fan_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_slider_fan_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_slider_fan_main_knob_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Slider_Fan, &style_ui_aircon_slider_fan_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->ui_Aircon_Slider_Fan,0, 2);
	lv_slider_set_value(ui->ui_Aircon_Slider_Fan,1,false);

	//Write codes ui_Aircon_Label_Low
	ui->ui_Aircon_Label_Low = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Low, 249, 592);
	lv_obj_set_size(ui->ui_Aircon_Label_Low, 29, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Low, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Low, "•\nLOW");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Low, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_low_main_main_default
	static lv_style_t style_ui_aircon_label_low_main_main_default;
	if (style_ui_aircon_label_low_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_low_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_low_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_low_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_low_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_low_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_low_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_low_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_low_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_low_main_main_default, &lv_font_Antonio_Regular_12);
	lv_style_set_text_letter_space(&style_ui_aircon_label_low_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_low_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_low_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_low_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_low_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_low_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_low_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Low, &style_ui_aircon_label_low_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Medium
	ui->ui_Aircon_Label_Medium = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Medium, 295, 592);
	lv_obj_set_size(ui->ui_Aircon_Label_Medium, 53, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Medium, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Medium, "•\nMEDIUM");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Medium, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_medium_main_main_default
	static lv_style_t style_ui_aircon_label_medium_main_main_default;
	if (style_ui_aircon_label_medium_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_medium_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_medium_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_medium_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_medium_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_medium_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_medium_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_medium_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_medium_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_medium_main_main_default, &lv_font_Antonio_Regular_12);
	lv_style_set_text_letter_space(&style_ui_aircon_label_medium_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_medium_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_medium_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_medium_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_medium_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_medium_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_medium_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Medium, &style_ui_aircon_label_medium_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_High
	ui->ui_Aircon_Label_High = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_High, 363, 592);
	lv_obj_set_size(ui->ui_Aircon_Label_High, 29, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_High, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_High, "•\nHIGH");
	lv_label_set_long_mode(ui->ui_Aircon_Label_High, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_high_main_main_default
	static lv_style_t style_ui_aircon_label_high_main_main_default;
	if (style_ui_aircon_label_high_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_high_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_high_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_high_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_high_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_high_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_high_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_high_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_high_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_high_main_main_default, &lv_font_Antonio_Regular_12);
	lv_style_set_text_letter_space(&style_ui_aircon_label_high_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_high_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_high_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_high_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_high_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_high_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_high_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_High, &style_ui_aircon_label_high_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Comp
	ui->ui_Aircon_Label_Comp = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_Comp, 302, 402);
	lv_obj_set_size(ui->ui_Aircon_Label_Comp, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Comp, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_Comp, "COMP");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Comp, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_comp_main_main_default
	static lv_style_t style_ui_aircon_label_comp_main_main_default;
	if (style_ui_aircon_label_comp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_comp_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_comp_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_comp_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_comp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_comp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_comp_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_comp_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_comp_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_label_comp_main_main_default, &lv_font_Antonio_Regular_19);
	lv_style_set_text_letter_space(&style_ui_aircon_label_comp_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_comp_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_comp_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_comp_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_comp_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_comp_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_comp_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_Comp, &style_ui_aircon_label_comp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_On
	ui->ui_Aircon_Label_On = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_On, 302, 424);
	lv_obj_set_size(ui->ui_Aircon_Label_On, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_On, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_On, "ON");
	lv_label_set_long_mode(ui->ui_Aircon_Label_On, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_on_main_main_default
	static lv_style_t style_ui_aircon_label_on_main_main_default;
	if (style_ui_aircon_label_on_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_on_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_on_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_on_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_on_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_on_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_on_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_on_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_on_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_on_main_main_default, &lv_font_Antonio_Regular_19);
	lv_style_set_text_letter_space(&style_ui_aircon_label_on_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_on_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_on_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_on_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_on_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_on_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_on_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_On, &style_ui_aircon_label_on_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Comp
	ui->ui_Aircon_Img_Comp = lv_img_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Img_Comp, 272, 413);
	lv_obj_set_size(ui->ui_Aircon_Img_Comp, 27, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Comp, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_comp_main_main_default
	static lv_style_t style_ui_aircon_img_comp_main_main_default;
	if (style_ui_aircon_img_comp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_comp_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_comp_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_comp_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_comp_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_comp_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_Comp, &style_ui_aircon_img_comp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_Comp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Comp,&_icn_cool_27x31);
	lv_img_set_pivot(ui->ui_Aircon_Img_Comp, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Comp, 0);

	//Write codes ui_Aircon_Label_FanSt
	ui->ui_Aircon_Label_FanSt = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_FanSt, 303, 462);
	lv_obj_set_size(ui->ui_Aircon_Label_FanSt, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_FanSt, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_FanSt, "FAN");
	lv_label_set_long_mode(ui->ui_Aircon_Label_FanSt, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_fanst_main_main_default
	static lv_style_t style_ui_aircon_label_fanst_main_main_default;
	if (style_ui_aircon_label_fanst_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_fanst_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_fanst_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_fanst_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_fanst_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_fanst_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_fanst_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_fanst_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_fanst_main_main_default, lv_color_make(0x52, 0xDA, 0xFF));
	lv_style_set_text_font(&style_ui_aircon_label_fanst_main_main_default, &lv_font_Antonio_Regular_19);
	lv_style_set_text_letter_space(&style_ui_aircon_label_fanst_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_fanst_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_fanst_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_fanst_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_fanst_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_fanst_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_fanst_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_FanSt, &style_ui_aircon_label_fanst_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_FanState
	ui->ui_Aircon_Label_FanState = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_FanState, 303, 485);
	lv_obj_set_size(ui->ui_Aircon_Label_FanState, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_FanState, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_FanState, "LOW");
	lv_label_set_long_mode(ui->ui_Aircon_Label_FanState, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_fanstate_main_main_default
	static lv_style_t style_ui_aircon_label_fanstate_main_main_default;
	if (style_ui_aircon_label_fanstate_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_fanstate_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_fanstate_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_fanstate_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_fanstate_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_fanstate_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_fanstate_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_fanstate_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_fanstate_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_fanstate_main_main_default, &lv_font_Antonio_Regular_19);
	lv_style_set_text_letter_space(&style_ui_aircon_label_fanstate_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_fanstate_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_fanstate_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_fanstate_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_fanstate_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_fanstate_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_fanstate_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_FanState, &style_ui_aircon_label_fanstate_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_FanSt
	ui->ui_Aircon_Img_FanSt = lv_img_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Img_FanSt, 272, 474);
	lv_obj_set_size(ui->ui_Aircon_Img_FanSt, 31, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_FanSt, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_fanst_main_main_default
	static lv_style_t style_ui_aircon_img_fanst_main_main_default;
	if (style_ui_aircon_img_fanst_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_fanst_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_fanst_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_fanst_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_fanst_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_fanst_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_FanSt, &style_ui_aircon_img_fanst_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_FanSt, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_FanSt,&_icn_fan_low_31x27);
	lv_img_set_pivot(ui->ui_Aircon_Img_FanSt, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_FanSt, 0);

	//Write codes ui_Aircon_Btn_TimerUp
	ui->ui_Aircon_Btn_TimerUp = lv_btn_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TimerUp, 198, 260);
	lv_obj_set_size(ui->ui_Aircon_Btn_TimerUp, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TimerUp, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_btn_timerup_main_main_default
	static lv_style_t style_ui_aircon_btn_timerup_main_main_default;
	if (style_ui_aircon_btn_timerup_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_timerup_main_main_default);
	else
		lv_style_init(&style_ui_aircon_btn_timerup_main_main_default);
	lv_style_set_radius(&style_ui_aircon_btn_timerup_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_timerup_main_main_default, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_timerup_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_timerup_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_timerup_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_timerup_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_timerup_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_timerup_main_main_default, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_timerup_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_aircon_btn_timerup_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Aircon_Btn_TimerUp, &style_ui_aircon_btn_timerup_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_ui_aircon_btn_timerup_main_main_pressed
	static lv_style_t style_ui_aircon_btn_timerup_main_main_pressed;
	if (style_ui_aircon_btn_timerup_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_timerup_main_main_pressed);
	else
		lv_style_init(&style_ui_aircon_btn_timerup_main_main_pressed);
	lv_style_set_radius(&style_ui_aircon_btn_timerup_main_main_pressed, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_timerup_main_main_pressed, lv_color_make(0x18, 0xC2, 0x20));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_timerup_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_timerup_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_timerup_main_main_pressed, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_timerup_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_timerup_main_main_pressed, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_timerup_main_main_pressed, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_timerup_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->ui_Aircon_Btn_TimerUp, &style_ui_aircon_btn_timerup_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
	ui->ui_Aircon_Btn_TimerUp_label = lv_label_create(ui->ui_Aircon_Btn_TimerUp);
	lv_label_set_text(ui->ui_Aircon_Btn_TimerUp_label, "");
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TimerUp, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Aircon_Btn_TimerUp_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Aircon_Img_TimerUp
	ui->ui_Aircon_Img_TimerUp = lv_img_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Img_TimerUp, 222, 281);
	lv_obj_set_size(ui->ui_Aircon_Img_TimerUp, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TimerUp, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_timerup_main_main_default
	static lv_style_t style_ui_aircon_img_timerup_main_main_default;
	if (style_ui_aircon_img_timerup_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_timerup_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_timerup_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_timerup_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_timerup_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_timerup_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_TimerUp, &style_ui_aircon_img_timerup_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_TimerUp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TimerUp,&_arrow_up_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TimerUp, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TimerUp, 0);

	//Write codes ui_Aircon_Btn_TimerDown
	ui->ui_Aircon_Btn_TimerDown = lv_btn_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TimerDown, 295, 260);
	lv_obj_set_size(ui->ui_Aircon_Btn_TimerDown, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TimerDown, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_btn_timerdown_main_main_default
	static lv_style_t style_ui_aircon_btn_timerdown_main_main_default;
	if (style_ui_aircon_btn_timerdown_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_timerdown_main_main_default);
	else
		lv_style_init(&style_ui_aircon_btn_timerdown_main_main_default);
	lv_style_set_radius(&style_ui_aircon_btn_timerdown_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_timerdown_main_main_default, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_timerdown_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_timerdown_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_timerdown_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_timerdown_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_timerdown_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_timerdown_main_main_default, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_timerdown_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_aircon_btn_timerdown_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Aircon_Btn_TimerDown, &style_ui_aircon_btn_timerdown_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_ui_aircon_btn_timerdown_main_main_pressed
	static lv_style_t style_ui_aircon_btn_timerdown_main_main_pressed;
	if (style_ui_aircon_btn_timerdown_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_timerdown_main_main_pressed);
	else
		lv_style_init(&style_ui_aircon_btn_timerdown_main_main_pressed);
	lv_style_set_radius(&style_ui_aircon_btn_timerdown_main_main_pressed, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_timerdown_main_main_pressed, lv_color_make(0x18, 0xC2, 0x20));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_timerdown_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_timerdown_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_timerdown_main_main_pressed, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_timerdown_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_timerdown_main_main_pressed, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_timerdown_main_main_pressed, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_timerdown_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->ui_Aircon_Btn_TimerDown, &style_ui_aircon_btn_timerdown_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
	ui->ui_Aircon_Btn_TimerDown_label = lv_label_create(ui->ui_Aircon_Btn_TimerDown);
	lv_label_set_text(ui->ui_Aircon_Btn_TimerDown_label, "");
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TimerDown, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Aircon_Btn_TimerDown_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Aircon_Img_TimerDown
	ui->ui_Aircon_Img_TimerDown = lv_img_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Img_TimerDown, 319, 281);
	lv_obj_set_size(ui->ui_Aircon_Img_TimerDown, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TimerDown, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_timerdown_main_main_default
	static lv_style_t style_ui_aircon_img_timerdown_main_main_default;
	if (style_ui_aircon_img_timerdown_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_timerdown_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_timerdown_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_timerdown_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_timerdown_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_timerdown_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_TimerDown, &style_ui_aircon_img_timerdown_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_TimerDown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TimerDown,&_arrow_down_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TimerDown, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TimerDown, 0);

	//Write codes ui_Aircon_Label_TimerHour
	ui->ui_Aircon_Label_TimerHour = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_TimerHour, 19, 234);
	lv_obj_set_size(ui->ui_Aircon_Label_TimerHour, 76, 103);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_TimerHour, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_TimerHour, "01");
	lv_label_set_long_mode(ui->ui_Aircon_Label_TimerHour, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_timerhour_main_main_default
	static lv_style_t style_ui_aircon_label_timerhour_main_main_default;
	if (style_ui_aircon_label_timerhour_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_timerhour_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_timerhour_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_timerhour_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_timerhour_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_timerhour_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_timerhour_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_timerhour_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_timerhour_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_timerhour_main_main_default, &lv_font_Antonio_Regular_80);
	lv_style_set_text_letter_space(&style_ui_aircon_label_timerhour_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_timerhour_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_timerhour_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_timerhour_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_timerhour_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_timerhour_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_timerhour_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_TimerHour, &style_ui_aircon_label_timerhour_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_TimerPoints
	ui->ui_Aircon_Label_TimerPoints = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_TimerPoints, 93, 229);
	lv_obj_set_size(ui->ui_Aircon_Label_TimerPoints, 23, 103);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_TimerPoints, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_TimerPoints, ":");
	lv_label_set_long_mode(ui->ui_Aircon_Label_TimerPoints, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_timerpoints_main_main_default
	static lv_style_t style_ui_aircon_label_timerpoints_main_main_default;
	if (style_ui_aircon_label_timerpoints_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_timerpoints_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_timerpoints_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_timerpoints_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_timerpoints_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_timerpoints_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_timerpoints_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_timerpoints_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_timerpoints_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_timerpoints_main_main_default, &lv_font_Antonio_Regular_80);
	lv_style_set_text_letter_space(&style_ui_aircon_label_timerpoints_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_timerpoints_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_timerpoints_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_timerpoints_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_timerpoints_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_timerpoints_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_timerpoints_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_TimerPoints, &style_ui_aircon_label_timerpoints_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_TimerMin
	ui->ui_Aircon_Label_TimerMin = lv_label_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Label_TimerMin, 118, 234);
	lv_obj_set_size(ui->ui_Aircon_Label_TimerMin, 76, 103);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_TimerMin, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Aircon_Label_TimerMin, "15");
	lv_label_set_long_mode(ui->ui_Aircon_Label_TimerMin, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_label_timermin_main_main_default
	static lv_style_t style_ui_aircon_label_timermin_main_main_default;
	if (style_ui_aircon_label_timermin_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_label_timermin_main_main_default);
	else
		lv_style_init(&style_ui_aircon_label_timermin_main_main_default);
	lv_style_set_radius(&style_ui_aircon_label_timermin_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_aircon_label_timermin_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_aircon_label_timermin_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_label_timermin_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_label_timermin_main_main_default, 0);
	lv_style_set_text_color(&style_ui_aircon_label_timermin_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_aircon_label_timermin_main_main_default, &lv_font_Antonio_Regular_80);
	lv_style_set_text_letter_space(&style_ui_aircon_label_timermin_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_aircon_label_timermin_main_main_default, 0);
	lv_style_set_text_align(&style_ui_aircon_label_timermin_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_aircon_label_timermin_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_aircon_label_timermin_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_aircon_label_timermin_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_aircon_label_timermin_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Label_TimerMin, &style_ui_aircon_label_timermin_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Fan
	ui->ui_Aircon_Img_Fan = lv_img_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_Img_Fan, 646, 218);
	lv_obj_set_size(ui->ui_Aircon_Img_Fan, 98, 98);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_fan_main_main_default
	static lv_style_t style_ui_aircon_img_fan_main_main_default;
	if (style_ui_aircon_img_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_fan_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_fan_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_fan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_fan_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_fan_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_Fan, &style_ui_aircon_img_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Fan,&_aircon_fan_1_98x98);
	lv_img_set_pivot(ui->ui_Aircon_Img_Fan, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Fan, 0);

	//Write codes ui_Aircon_Img_Cool
	ui->ui_Aircon_Img_Cool = lv_img_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_Img_Cool, 559, 213);
	lv_obj_set_size(ui->ui_Aircon_Img_Cool, 92, 102);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Cool, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_img_cool_main_main_default
	static lv_style_t style_ui_aircon_img_cool_main_main_default;
	if (style_ui_aircon_img_cool_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_img_cool_main_main_default);
	else
		lv_style_init(&style_ui_aircon_img_cool_main_main_default);
	lv_style_set_img_recolor(&style_ui_aircon_img_cool_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_aircon_img_cool_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_aircon_img_cool_main_main_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Img_Cool, &style_ui_aircon_img_cool_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Aircon_Img_Cool, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Cool,&_aircon_cool_1_92x102);
	lv_img_set_pivot(ui->ui_Aircon_Img_Cool, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Cool, 0);

	//Init events for screen
	events_init_ui_Aircon(ui);
}