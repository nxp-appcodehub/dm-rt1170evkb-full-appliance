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
	lv_obj_set_pos(ui->ui_Aircon_Label_Temp, 25, 87);
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

	//Write codes ui_Aircon_btn_1
	ui->ui_Aircon_btn_1 = lv_btn_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_btn_1, 200, 114);
	lv_obj_set_size(ui->ui_Aircon_btn_1, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_btn_1_main_main_default
	static lv_style_t style_ui_aircon_btn_1_main_main_default;
	if (style_ui_aircon_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_1_main_main_default);
	else
		lv_style_init(&style_ui_aircon_btn_1_main_main_default);
	lv_style_set_radius(&style_ui_aircon_btn_1_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_1_main_main_default, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_aircon_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Aircon_btn_1, &style_ui_aircon_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_ui_aircon_btn_1_main_main_pressed
	static lv_style_t style_ui_aircon_btn_1_main_main_pressed;
	if (style_ui_aircon_btn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_btn_1_main_main_pressed);
	else
		lv_style_init(&style_ui_aircon_btn_1_main_main_pressed);
	lv_style_set_radius(&style_ui_aircon_btn_1_main_main_pressed, 10);
	lv_style_set_bg_color(&style_ui_aircon_btn_1_main_main_pressed, lv_color_make(0x18, 0xC2, 0x20));
	lv_style_set_bg_grad_color(&style_ui_aircon_btn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_btn_1_main_main_pressed, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_btn_1_main_main_pressed, 255);
	lv_style_set_border_color(&style_ui_aircon_btn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_btn_1_main_main_pressed, 0);
	lv_style_set_border_opa(&style_ui_aircon_btn_1_main_main_pressed, 255);
	lv_style_set_text_color(&style_ui_aircon_btn_1_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->ui_Aircon_btn_1, &style_ui_aircon_btn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
	ui->ui_Aircon_btn_1_label = lv_label_create(ui->ui_Aircon_btn_1);
	lv_label_set_text(ui->ui_Aircon_btn_1_label, "");
	lv_obj_set_style_pad_all(ui->ui_Aircon_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Aircon_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Aircon_Sw_Swing
	ui->ui_Aircon_Sw_Swing = lv_switch_create(ui->ui_Aircon_cont_1);
	lv_obj_set_pos(ui->ui_Aircon_Sw_Swing, 125, 549);
	lv_obj_set_size(ui->ui_Aircon_Sw_Swing, 66, 36);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Sw_Swing, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_sw_swing_main_main_default
	static lv_style_t style_ui_aircon_sw_swing_main_main_default;
	if (style_ui_aircon_sw_swing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_sw_swing_main_main_default);
	else
		lv_style_init(&style_ui_aircon_sw_swing_main_main_default);
	lv_style_set_radius(&style_ui_aircon_sw_swing_main_main_default, 100);
	lv_style_set_bg_color(&style_ui_aircon_sw_swing_main_main_default, lv_color_make(0x6A, 0x6A, 0x6A));
	lv_style_set_bg_grad_color(&style_ui_aircon_sw_swing_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_sw_swing_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_sw_swing_main_main_default, 255);
	lv_style_set_border_color(&style_ui_aircon_sw_swing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_sw_swing_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_sw_swing_main_main_default, 0);
	lv_obj_add_style(ui->ui_Aircon_Sw_Swing, &style_ui_aircon_sw_swing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_ui_aircon_sw_swing_main_indicator_checked
	static lv_style_t style_ui_aircon_sw_swing_main_indicator_checked;
	if (style_ui_aircon_sw_swing_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_sw_swing_main_indicator_checked);
	else
		lv_style_init(&style_ui_aircon_sw_swing_main_indicator_checked);
	lv_style_set_bg_color(&style_ui_aircon_sw_swing_main_indicator_checked, lv_color_make(0x29, 0xBA, 0xE6));
	lv_style_set_bg_grad_color(&style_ui_aircon_sw_swing_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_aircon_sw_swing_main_indicator_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_sw_swing_main_indicator_checked, 255);
	lv_style_set_border_color(&style_ui_aircon_sw_swing_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_sw_swing_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_ui_aircon_sw_swing_main_indicator_checked, 0);
	lv_obj_add_style(ui->ui_Aircon_Sw_Swing, &style_ui_aircon_sw_swing_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_ui_aircon_sw_swing_main_knob_default
	static lv_style_t style_ui_aircon_sw_swing_main_knob_default;
	if (style_ui_aircon_sw_swing_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_ui_aircon_sw_swing_main_knob_default);
	else
		lv_style_init(&style_ui_aircon_sw_swing_main_knob_default);
	lv_style_set_radius(&style_ui_aircon_sw_swing_main_knob_default, 100);
	lv_style_set_bg_color(&style_ui_aircon_sw_swing_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_aircon_sw_swing_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_aircon_sw_swing_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_aircon_sw_swing_main_knob_default, 255);
	lv_style_set_border_color(&style_ui_aircon_sw_swing_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_aircon_sw_swing_main_knob_default, 0);
	lv_style_set_border_opa(&style_ui_aircon_sw_swing_main_knob_default, 255);
	lv_obj_add_style(ui->ui_Aircon_Sw_Swing, &style_ui_aircon_sw_swing_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Init events for screen
	events_init_ui_Aircon(ui);
}