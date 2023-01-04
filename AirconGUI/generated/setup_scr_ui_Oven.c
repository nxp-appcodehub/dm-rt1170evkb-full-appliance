/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_ui_Oven(lv_ui *ui){

	//Write codes ui_Oven
	ui->ui_Oven = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->ui_Oven, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_main_main_default
	static lv_style_t style_ui_oven_main_main_default;
	if (style_ui_oven_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_main_main_default);
	else
		lv_style_init(&style_ui_oven_main_main_default);
	lv_style_set_bg_color(&style_ui_oven_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_ui_oven_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven, &style_ui_oven_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_Bg
	ui->ui_Oven_Img_Bg = lv_img_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Img_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Oven_Img_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_bg_main_main_default
	static lv_style_t style_ui_oven_img_bg_main_main_default;
	if (style_ui_oven_img_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_bg_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_bg_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_bg_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Bg, &style_ui_oven_img_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Bg,&_oven_bg_1280x720);
	lv_img_set_pivot(ui->ui_Oven_Img_Bg, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Bg, 0);

	//Write codes ui_Oven_Img_Door
	ui->ui_Oven_Img_Door = lv_img_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Img_Door, 5, -1);
	lv_obj_set_size(ui->ui_Oven_Img_Door, 704, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Door, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_door_main_main_default
	static lv_style_t style_ui_oven_img_door_main_main_default;
	if (style_ui_oven_img_door_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_door_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_door_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_door_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_door_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_door_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Door, &style_ui_oven_img_door_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Door, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Door,&_oven_light_704x720);
	lv_img_set_pivot(ui->ui_Oven_Img_Door, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Door, 0);

	//Write codes ui_Oven_Img_Fan
	ui->ui_Oven_Img_Fan = lv_img_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Img_Fan, 364, 344);
	lv_obj_set_size(ui->ui_Oven_Img_Fan, 120, 119);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_fan_main_main_default
	static lv_style_t style_ui_oven_img_fan_main_main_default;
	if (style_ui_oven_img_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_fan_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_fan_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_fan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_fan_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_fan_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Fan, &style_ui_oven_img_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Fan,&_oven_fan_light_1_120x119);
	lv_img_set_pivot(ui->ui_Oven_Img_Fan, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Fan, 0);

	//Write codes ui_Oven_Img_Lable_Bg
	ui->ui_Oven_Img_Lable_Bg = lv_img_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Img_Lable_Bg, 0, 590);
	lv_obj_set_size(ui->ui_Oven_Img_Lable_Bg, 654, 130);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Lable_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_lable_bg_main_main_default
	static lv_style_t style_ui_oven_img_lable_bg_main_main_default;
	if (style_ui_oven_img_lable_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_lable_bg_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_lable_bg_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_lable_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_lable_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_lable_bg_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Lable_Bg, &style_ui_oven_img_lable_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Lable_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Lable_Bg,&_title_bg_654x130);
	lv_img_set_pivot(ui->ui_Oven_Img_Lable_Bg, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Lable_Bg, 0);

	//Write codes ui_Oven_Label_Oven
	ui->ui_Oven_Label_Oven = lv_label_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Oven, 541, 639);
	lv_obj_set_size(ui->ui_Oven_Label_Oven, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Oven, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Oven, "Oven");
	lv_label_set_long_mode(ui->ui_Oven_Label_Oven, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_oven_main_main_default
	static lv_style_t style_ui_oven_label_oven_main_main_default;
	if (style_ui_oven_label_oven_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_oven_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_oven_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_oven_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_oven_main_main_default, lv_color_make(0x4a, 0x60, 0x73));
	lv_style_set_bg_grad_color(&style_ui_oven_label_oven_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_oven_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_oven_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_oven_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_oven_main_main_default, &lv_font_Antonio_Regular_22);
	lv_style_set_text_letter_space(&style_ui_oven_label_oven_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_oven_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_oven_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_oven_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_oven_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_oven_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_oven_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Oven, &style_ui_oven_label_oven_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Group_Oven
	ui->ui_Oven_Group_Oven = lv_obj_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Group_Oven, 677, 17);
	lv_obj_set_size(ui->ui_Oven_Group_Oven, 534, 686);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Group_Oven, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_group_oven_main_main_default
	static lv_style_t style_ui_oven_group_oven_main_main_default;
	if (style_ui_oven_group_oven_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_group_oven_main_main_default);
	else
		lv_style_init(&style_ui_oven_group_oven_main_main_default);
	lv_style_set_radius(&style_ui_oven_group_oven_main_main_default, 20);
	lv_style_set_bg_color(&style_ui_oven_group_oven_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_oven_group_oven_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_oven_group_oven_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_group_oven_main_main_default, 255);
	lv_style_set_border_color(&style_ui_oven_group_oven_main_main_default, lv_color_make(0x4A, 0x48, 0x4A));
	lv_style_set_border_width(&style_ui_oven_group_oven_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_oven_group_oven_main_main_default, 0);
	lv_style_set_pad_left(&style_ui_oven_group_oven_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_group_oven_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_group_oven_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_oven_group_oven_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Group_Oven, &style_ui_oven_group_oven_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line
	ui->ui_Oven_line = lv_line_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_line, 7, 7);
	lv_obj_set_size(ui->ui_Oven_line, 530, 24);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_line_main_main_default
	static lv_style_t style_ui_oven_line_main_main_default;
	if (style_ui_oven_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_line_main_main_default);
	else
		lv_style_init(&style_ui_oven_line_main_main_default);
	lv_style_set_line_color(&style_ui_oven_line_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_line_width(&style_ui_oven_line_main_main_default, 17);
	lv_style_set_line_rounded(&style_ui_oven_line_main_main_default, true);
	lv_obj_add_style(ui->ui_Oven_line, &style_ui_oven_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Oven_line[] ={{0, 0},{519, 0},};
	lv_line_set_points(ui->ui_Oven_line,ui_Oven_line,2);

	//Write codes ui_Oven_Label_CurrTemp
	ui->ui_Oven_Label_CurrTemp = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_CurrTemp, 34, 49);
	lv_obj_set_size(ui->ui_Oven_Label_CurrTemp, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_CurrTemp, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_CurrTemp, "CURRENT TEMP.");
	lv_label_set_long_mode(ui->ui_Oven_Label_CurrTemp, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_currtemp_main_main_default
	static lv_style_t style_ui_oven_label_currtemp_main_main_default;
	if (style_ui_oven_label_currtemp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_currtemp_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_currtemp_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_currtemp_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_currtemp_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_label_currtemp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_currtemp_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_currtemp_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_currtemp_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_currtemp_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_oven_label_currtemp_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_currtemp_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_currtemp_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_currtemp_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_currtemp_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_currtemp_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_currtemp_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_CurrTemp, &style_ui_oven_label_currtemp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_line_5
	ui->ui_Oven_line_5 = lv_line_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_line_5, 23, 234);
	lv_obj_set_size(ui->ui_Oven_line_5, 495, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_line_5_main_main_default
	static lv_style_t style_ui_oven_line_5_main_main_default;
	if (style_ui_oven_line_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_line_5_main_main_default);
	else
		lv_style_init(&style_ui_oven_line_5_main_main_default);
	lv_style_set_line_color(&style_ui_oven_line_5_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_oven_line_5_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_oven_line_5_main_main_default, false);
	lv_obj_add_style(ui->ui_Oven_line_5, &style_ui_oven_line_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Oven_line_5[] ={{0, 0},{485, 0},};
	lv_line_set_points(ui->ui_Oven_line_5,ui_Oven_line_5,2);

	//Write codes ui_Oven_line_4
	ui->ui_Oven_line_4 = lv_line_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_line_4, 23, 379);
	lv_obj_set_size(ui->ui_Oven_line_4, 495, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_line_4_main_main_default
	static lv_style_t style_ui_oven_line_4_main_main_default;
	if (style_ui_oven_line_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_line_4_main_main_default);
	else
		lv_style_init(&style_ui_oven_line_4_main_main_default);
	lv_style_set_line_color(&style_ui_oven_line_4_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_oven_line_4_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_oven_line_4_main_main_default, false);
	lv_obj_add_style(ui->ui_Oven_line_4, &style_ui_oven_line_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Oven_line_4[] ={{0, 0},{485, 0},};
	lv_line_set_points(ui->ui_Oven_line_4,ui_Oven_line_4,2);

	//Write codes ui_Oven_line_3
	ui->ui_Oven_line_3 = lv_line_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_line_3, 269, 117);
	lv_obj_set_size(ui->ui_Oven_line_3, 240, 7);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_line_3_main_main_default
	static lv_style_t style_ui_oven_line_3_main_main_default;
	if (style_ui_oven_line_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_line_3_main_main_default);
	else
		lv_style_init(&style_ui_oven_line_3_main_main_default);
	lv_style_set_line_color(&style_ui_oven_line_3_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_oven_line_3_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_oven_line_3_main_main_default, false);
	lv_obj_add_style(ui->ui_Oven_line_3, &style_ui_oven_line_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Oven_line_3[] ={{0, 0},{235, 0},};
	lv_line_set_points(ui->ui_Oven_line_3,ui_Oven_line_3,2);

	//Write codes ui_Oven_line_2
	ui->ui_Oven_line_2 = lv_line_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_line_2, 252, 52);
	lv_obj_set_size(ui->ui_Oven_line_2, 29, 169);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_line_2_main_main_default
	static lv_style_t style_ui_oven_line_2_main_main_default;
	if (style_ui_oven_line_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_line_2_main_main_default);
	else
		lv_style_init(&style_ui_oven_line_2_main_main_default);
	lv_style_set_line_color(&style_ui_oven_line_2_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_oven_line_2_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_oven_line_2_main_main_default, false);
	lv_obj_add_style(ui->ui_Oven_line_2, &style_ui_oven_line_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Oven_line_2[] ={{0, 0},{0, 160},};
	lv_line_set_points(ui->ui_Oven_line_2,ui_Oven_line_2,2);

	//Write codes ui_Oven_line_1
	ui->ui_Oven_line_1 = lv_line_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_line_1, 267, 441);
	lv_obj_set_size(ui->ui_Oven_line_1, 17, 146);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_line_1_main_main_default
	static lv_style_t style_ui_oven_line_1_main_main_default;
	if (style_ui_oven_line_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_line_1_main_main_default);
	else
		lv_style_init(&style_ui_oven_line_1_main_main_default);
	lv_style_set_line_color(&style_ui_oven_line_1_main_main_default, lv_color_make(0x65, 0x64, 0x61));
	lv_style_set_line_width(&style_ui_oven_line_1_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_oven_line_1_main_main_default, false);
	lv_obj_add_style(ui->ui_Oven_line_1, &style_ui_oven_line_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Oven_line_1[] ={{0, 0},{0, 300},};
	lv_line_set_points(ui->ui_Oven_line_1,ui_Oven_line_1,2);

	//Write codes ui_Oven_Label_Temp
	ui->ui_Oven_Label_Temp = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Temp, 7, 89);
	lv_obj_set_size(ui->ui_Oven_Label_Temp, 214, 125);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Temp, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Temp, "250");
	lv_label_set_long_mode(ui->ui_Oven_Label_Temp, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_temp_main_main_default
	static lv_style_t style_ui_oven_label_temp_main_main_default;
	if (style_ui_oven_label_temp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_temp_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_temp_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_temp_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_temp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_temp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_temp_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_temp_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_temp_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_temp_main_main_default, &lv_font_Antonio_Regular_120);
	lv_style_set_text_letter_space(&style_ui_oven_label_temp_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_temp_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_temp_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_temp_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_temp_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_temp_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_temp_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Temp, &style_ui_oven_label_temp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Cen
	ui->ui_Oven_Label_Cen = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Cen, 175, 88);
	lv_obj_set_size(ui->ui_Oven_Label_Cen, 72, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Cen, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Cen, "ºC");
	lv_label_set_long_mode(ui->ui_Oven_Label_Cen, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_cen_main_main_default
	static lv_style_t style_ui_oven_label_cen_main_main_default;
	if (style_ui_oven_label_cen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_cen_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_cen_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_cen_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_cen_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_cen_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_cen_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_cen_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_cen_main_main_default, lv_color_make(0xc9, 0xc5, 0xc5));
	lv_style_set_text_font(&style_ui_oven_label_cen_main_main_default, &lv_font_Alatsi_Regular_26);
	lv_style_set_text_letter_space(&style_ui_oven_label_cen_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_cen_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_cen_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_cen_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_cen_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_cen_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_cen_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Cen, &style_ui_oven_label_cen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Status
	ui->ui_Oven_Label_Status = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Status, 287, 34);
	lv_obj_set_size(ui->ui_Oven_Label_Status, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Status, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Status, "STATUS");
	lv_label_set_long_mode(ui->ui_Oven_Label_Status, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_status_main_main_default
	static lv_style_t style_ui_oven_label_status_main_main_default;
	if (style_ui_oven_label_status_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_status_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_status_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_status_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_status_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_label_status_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_status_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_status_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_status_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_status_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_oven_label_status_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_status_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_status_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_status_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_status_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_status_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_status_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Status, &style_ui_oven_label_status_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_CurrStat
	ui->ui_Oven_Label_CurrStat = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_CurrStat, 329, 67);
	lv_obj_set_size(ui->ui_Oven_Label_CurrStat, 118, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_CurrStat, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_CurrStat, "My Stat");
	lv_label_set_long_mode(ui->ui_Oven_Label_CurrStat, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_currstat_main_main_default
	static lv_style_t style_ui_oven_label_currstat_main_main_default;
	if (style_ui_oven_label_currstat_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_currstat_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_currstat_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_currstat_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_currstat_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_currstat_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_currstat_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_currstat_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_currstat_main_main_default, lv_color_make(0xc9, 0xc5, 0xc5));
	lv_style_set_text_font(&style_ui_oven_label_currstat_main_main_default, &lv_font_Antonio_Regular_26);
	lv_style_set_text_letter_space(&style_ui_oven_label_currstat_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_currstat_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_currstat_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_currstat_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_currstat_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_currstat_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_currstat_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_CurrStat, &style_ui_oven_label_currstat_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Time
	ui->ui_Oven_Label_Time = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Time, 236, 132);
	lv_obj_set_size(ui->ui_Oven_Label_Time, 118, 57);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Time, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Time, "TIME\nLEFT");
	lv_label_set_long_mode(ui->ui_Oven_Label_Time, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_time_main_main_default
	static lv_style_t style_ui_oven_label_time_main_main_default;
	if (style_ui_oven_label_time_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_time_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_time_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_time_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_time_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_label_time_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_time_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_time_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_time_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_time_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_oven_label_time_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_time_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_time_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_time_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_time_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_time_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_time_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Time, &style_ui_oven_label_time_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Bar_Time
	ui->ui_Oven_Bar_Time = lv_bar_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Bar_Time, 274, 195);
	lv_obj_set_size(ui->ui_Oven_Bar_Time, 225, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Bar_Time, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_bar_time_main_main_default
	static lv_style_t style_ui_oven_bar_time_main_main_default;
	if (style_ui_oven_bar_time_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_bar_time_main_main_default);
	else
		lv_style_init(&style_ui_oven_bar_time_main_main_default);
	lv_style_set_radius(&style_ui_oven_bar_time_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_oven_bar_time_main_main_default, lv_color_make(0x4A, 0x44, 0x41));
	lv_style_set_bg_grad_color(&style_ui_oven_bar_time_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_bar_time_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_bar_time_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Bar_Time, &style_ui_oven_bar_time_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_bar_time_main_indicator_default
	static lv_style_t style_ui_oven_bar_time_main_indicator_default;
	if (style_ui_oven_bar_time_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_bar_time_main_indicator_default);
	else
		lv_style_init(&style_ui_oven_bar_time_main_indicator_default);
	lv_style_set_radius(&style_ui_oven_bar_time_main_indicator_default, 10);
	lv_style_set_bg_color(&style_ui_oven_bar_time_main_indicator_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_bar_time_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_bar_time_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_bar_time_main_indicator_default, 255);
	lv_obj_add_style(ui->ui_Oven_Bar_Time, &style_ui_oven_bar_time_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->ui_Oven_Bar_Time, 1000, 0);
	lv_bar_set_mode(ui->ui_Oven_Bar_Time, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->ui_Oven_Bar_Time, 30, LV_ANIM_OFF);

	//Write codes ui_Oven_Label_Mode
	ui->ui_Oven_Label_Mode = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode, 208, 240);
	lv_obj_set_size(ui->ui_Oven_Label_Mode, 118, 57);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode, "MODE");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode_main_main_default
	static lv_style_t style_ui_oven_label_mode_main_main_default;
	if (style_ui_oven_label_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_mode_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_mode_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode, &style_ui_oven_label_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Btn_ModeLeft
	ui->ui_Oven_Btn_ModeLeft = lv_imgbtn_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Btn_ModeLeft, 27, 291);
	lv_obj_set_size(ui->ui_Oven_Btn_ModeLeft, 18, 35);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Btn_ModeLeft, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_btn_modeleft_main_main_default
	static lv_style_t style_ui_oven_btn_modeleft_main_main_default;
	if (style_ui_oven_btn_modeleft_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_btn_modeleft_main_main_default);
	else
		lv_style_init(&style_ui_oven_btn_modeleft_main_main_default);
	lv_style_set_text_color(&style_ui_oven_btn_modeleft_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_ui_oven_btn_modeleft_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_ui_oven_btn_modeleft_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_btn_modeleft_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_btn_modeleft_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Btn_ModeLeft, &style_ui_oven_btn_modeleft_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_ui_oven_btn_modeleft_main_main_pressed
	static lv_style_t style_ui_oven_btn_modeleft_main_main_pressed;
	if (style_ui_oven_btn_modeleft_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_btn_modeleft_main_main_pressed);
	else
		lv_style_init(&style_ui_oven_btn_modeleft_main_main_pressed);
	lv_style_set_text_color(&style_ui_oven_btn_modeleft_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_ui_oven_btn_modeleft_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_ui_oven_btn_modeleft_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_ui_oven_btn_modeleft_main_main_pressed, 0);
	lv_style_set_img_opa(&style_ui_oven_btn_modeleft_main_main_pressed, 255);
	lv_obj_add_style(ui->ui_Oven_Btn_ModeLeft, &style_ui_oven_btn_modeleft_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_ui_oven_btn_modeleft_main_main_checked
	static lv_style_t style_ui_oven_btn_modeleft_main_main_checked;
	if (style_ui_oven_btn_modeleft_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_btn_modeleft_main_main_checked);
	else
		lv_style_init(&style_ui_oven_btn_modeleft_main_main_checked);
	lv_style_set_text_color(&style_ui_oven_btn_modeleft_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_ui_oven_btn_modeleft_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_ui_oven_btn_modeleft_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_ui_oven_btn_modeleft_main_main_checked, 0);
	lv_style_set_img_opa(&style_ui_oven_btn_modeleft_main_main_checked, 255);
	lv_obj_add_style(ui->ui_Oven_Btn_ModeLeft, &style_ui_oven_btn_modeleft_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_PRESSED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeLeft, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_arrow_left_alpha_18x35, NULL);
	lv_obj_add_flag(ui->ui_Oven_Btn_ModeLeft, LV_OBJ_FLAG_CHECKABLE);

	//Write codes ui_Oven_Btn_ModeRigth
	ui->ui_Oven_Btn_ModeRigth = lv_imgbtn_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Btn_ModeRigth, 486, 291);
	lv_obj_set_size(ui->ui_Oven_Btn_ModeRigth, 18, 35);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Btn_ModeRigth, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_btn_moderigth_main_main_default
	static lv_style_t style_ui_oven_btn_moderigth_main_main_default;
	if (style_ui_oven_btn_moderigth_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_btn_moderigth_main_main_default);
	else
		lv_style_init(&style_ui_oven_btn_moderigth_main_main_default);
	lv_style_set_text_color(&style_ui_oven_btn_moderigth_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_ui_oven_btn_moderigth_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_ui_oven_btn_moderigth_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_btn_moderigth_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_btn_moderigth_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Btn_ModeRigth, &style_ui_oven_btn_moderigth_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_PRESSED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_ModeRigth, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_arrow_right_alpha_18x35, NULL);
	lv_obj_add_flag(ui->ui_Oven_Btn_ModeRigth, LV_OBJ_FLAG_CHECKABLE);

	//Write codes ui_Oven_Btn_State
	ui->ui_Oven_Btn_State = lv_imgbtn_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Btn_State, 203, 607);
	lv_obj_set_size(ui->ui_Oven_Btn_State, 134, 51);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Btn_State, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_btn_state_main_main_default
	static lv_style_t style_ui_oven_btn_state_main_main_default;
	if (style_ui_oven_btn_state_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_btn_state_main_main_default);
	else
		lv_style_init(&style_ui_oven_btn_state_main_main_default);
	lv_style_set_text_color(&style_ui_oven_btn_state_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_btn_state_main_main_default, &lv_font_Antonio_Regular_26);
	lv_style_set_text_align(&style_ui_oven_btn_state_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_ui_oven_btn_state_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_img_recolor_opa(&style_ui_oven_btn_state_main_main_default, 255);
	lv_style_set_img_opa(&style_ui_oven_btn_state_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Btn_State, &style_ui_oven_btn_state_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_ui_oven_btn_state_main_main_checked
	static lv_style_t style_ui_oven_btn_state_main_main_checked;
	if (style_ui_oven_btn_state_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_btn_state_main_main_checked);
	else
		lv_style_init(&style_ui_oven_btn_state_main_main_checked);
	lv_style_set_text_color(&style_ui_oven_btn_state_main_main_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_btn_state_main_main_checked, &lv_font_Antonio_Regular_26);
	lv_style_set_text_align(&style_ui_oven_btn_state_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_ui_oven_btn_state_main_main_checked, lv_color_make(0x35, 0xC9, 0x15));
	lv_style_set_img_recolor_opa(&style_ui_oven_btn_state_main_main_checked, 255);
	lv_style_set_img_opa(&style_ui_oven_btn_state_main_main_checked, 255);
	lv_obj_add_style(ui->ui_Oven_Btn_State, &style_ui_oven_btn_state_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_RELEASED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_PRESSED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_imgbtn_set_src(ui->ui_Oven_Btn_State, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_BTN_oven_alpha_134x51, NULL);
	lv_obj_add_flag(ui->ui_Oven_Btn_State, LV_OBJ_FLAG_CHECKABLE);
	ui->ui_Oven_Btn_State_label = lv_label_create(ui->ui_Oven_Btn_State);
	lv_label_set_text(ui->ui_Oven_Btn_State_label, "START");
	lv_obj_set_style_pad_all(ui->ui_Oven_Btn_State, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Oven_Btn_State_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Oven_Label_Settings
	ui->ui_Oven_Label_Settings = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Settings, 206, 395);
	lv_obj_set_size(ui->ui_Oven_Label_Settings, 118, 46);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Settings, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Settings, "SETTINGS");
	lv_label_set_long_mode(ui->ui_Oven_Label_Settings, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_settings_main_main_default
	static lv_style_t style_ui_oven_label_settings_main_main_default;
	if (style_ui_oven_label_settings_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_settings_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_settings_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_settings_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_settings_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_label_settings_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_settings_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_settings_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_settings_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_settings_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_oven_label_settings_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_settings_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_settings_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_settings_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_settings_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_settings_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_settings_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Settings, &style_ui_oven_label_settings_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_TimeLeft
	ui->ui_Oven_Label_TimeLeft = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_TimeLeft, 319, 130);
	lv_obj_set_size(ui->ui_Oven_Label_TimeLeft, 109, 51);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_TimeLeft, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_TimeLeft, "15");
	lv_label_set_long_mode(ui->ui_Oven_Label_TimeLeft, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_timeleft_main_main_default
	static lv_style_t style_ui_oven_label_timeleft_main_main_default;
	if (style_ui_oven_label_timeleft_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_timeleft_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_timeleft_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_timeleft_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_timeleft_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_timeleft_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_timeleft_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_timeleft_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_timeleft_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_timeleft_main_main_default, &lv_font_Antonio_Regular_40);
	lv_style_set_text_letter_space(&style_ui_oven_label_timeleft_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_timeleft_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_timeleft_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_timeleft_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_timeleft_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_timeleft_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_timeleft_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_TimeLeft, &style_ui_oven_label_timeleft_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_Min
	ui->ui_Oven_Label_Min = lv_label_create(ui->ui_Oven_Group_Oven);
	lv_obj_set_pos(ui->ui_Oven_Label_Min, 393, 146);
	lv_obj_set_size(ui->ui_Oven_Label_Min, 63, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Min, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Min, "mins");
	lv_label_set_long_mode(ui->ui_Oven_Label_Min, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_min_main_main_default
	static lv_style_t style_ui_oven_label_min_main_main_default;
	if (style_ui_oven_label_min_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_min_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_min_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_min_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_min_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_min_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_min_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_min_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_min_main_main_default, lv_color_make(0xc9, 0xc5, 0xc5));
	lv_style_set_text_font(&style_ui_oven_label_min_main_main_default, &lv_font_Alatsi_Regular_23);
	lv_style_set_text_letter_space(&style_ui_oven_label_min_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_min_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_min_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_min_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_min_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_min_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_min_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Min, &style_ui_oven_label_min_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Tile_Mode
	ui->ui_Oven_Tile_Mode = lv_tileview_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Tile_Mode, 728, 294);
	lv_obj_set_size(ui->ui_Oven_Tile_Mode, 430, 86);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Tile_Mode, LV_SCROLLBAR_MODE_ON);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_tile_mode_main_main_default
	static lv_style_t style_ui_oven_tile_mode_main_main_default;
	if (style_ui_oven_tile_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_tile_mode_main_main_default);
	else
		lv_style_init(&style_ui_oven_tile_mode_main_main_default);
	lv_style_set_radius(&style_ui_oven_tile_mode_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_tile_mode_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_tile_mode_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_tile_mode_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_tile_mode_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Tile_Mode, &style_ui_oven_tile_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_tile_mode_main_scrollbar_default
	static lv_style_t style_ui_oven_tile_mode_main_scrollbar_default;
	if (style_ui_oven_tile_mode_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_tile_mode_main_scrollbar_default);
	else
		lv_style_init(&style_ui_oven_tile_mode_main_scrollbar_default);
	lv_style_set_radius(&style_ui_oven_tile_mode_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_ui_oven_tile_mode_main_scrollbar_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_opa(&style_ui_oven_tile_mode_main_scrollbar_default, 0);
	lv_obj_add_style(ui->ui_Oven_Tile_Mode, &style_ui_oven_tile_mode_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_9
	ui->ui_Oven_Tile_Mode_Mode_9 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 8 , 0, LV_DIR_LEFT);

	//Write codes ui_Oven_Img_Mode9
	ui->ui_Oven_Img_Mode9 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_9);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode9, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode9, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode9_main_main_default
	static lv_style_t style_ui_oven_img_mode9_main_main_default;
	if (style_ui_oven_img_mode9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode9_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode9_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode9_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode9_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode9, &style_ui_oven_img_mode9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode9,&_icn_oven_defrost_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode9, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode9, 0);

	//Write codes ui_Oven_Label_Mode9
	ui->ui_Oven_Label_Mode9 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_9);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode9, 220, 22);
	lv_obj_set_size(ui->ui_Oven_Label_Mode9, 141, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode9, "Defrost");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode9_main_main_default
	static lv_style_t style_ui_oven_label_mode9_main_main_default;
	if (style_ui_oven_label_mode9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode9_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode9_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode9_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode9_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode9_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode9_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode9_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode9_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode9_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode9_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode9_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode9_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode9, &style_ui_oven_label_mode9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_8
	ui->ui_Oven_Tile_Mode_Mode_8 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 7 , 0, LV_DIR_LEFT | LV_DIR_RIGHT);

	//Write codes ui_Oven_Img_Mode8
	ui->ui_Oven_Img_Mode8 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_8);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode8, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode8, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode8_main_main_default
	static lv_style_t style_ui_oven_img_mode8_main_main_default;
	if (style_ui_oven_img_mode8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode8_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode8_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode8_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode8_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode8, &style_ui_oven_img_mode8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode8,&_icn_oven_lower_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode8, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode8, 0);

	//Write codes ui_Oven_Label_Mode8
	ui->ui_Oven_Label_Mode8 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_8);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode8, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode8, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode8, "Lower Outer\nElement");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode8_main_main_default
	static lv_style_t style_ui_oven_label_mode8_main_main_default;
	if (style_ui_oven_label_mode8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode8_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode8_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode8_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode8_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode8_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode8_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode8_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode8_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode8_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode8_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode8_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode8_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode8, &style_ui_oven_label_mode8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_7
	ui->ui_Oven_Tile_Mode_Mode_7 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 6 , 0, LV_DIR_LEFT | LV_DIR_RIGHT);

	//Write codes ui_Oven_Img_Mode7
	ui->ui_Oven_Img_Mode7 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_7);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode7, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode7, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode7_main_main_default
	static lv_style_t style_ui_oven_img_mode7_main_main_default;
	if (style_ui_oven_img_mode7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode7_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode7_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode7_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode7_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode7, &style_ui_oven_img_mode7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode7,&_icn_oven_upper_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode7, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode7, 0);

	//Write codes ui_Oven_Label_Mode7
	ui->ui_Oven_Label_Mode7 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_7);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode7, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode7, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode7, "Upper Outer\nElement");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode7_main_main_default
	static lv_style_t style_ui_oven_label_mode7_main_main_default;
	if (style_ui_oven_label_mode7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode7_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode7_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode7_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode7_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode7_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode7_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode7_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode7_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode7_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode7_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode7_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode7_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode7, &style_ui_oven_label_mode7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_6
	ui->ui_Oven_Tile_Mode_Mode_6 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 5 , 0, LV_DIR_LEFT | LV_DIR_RIGHT);

	//Write codes ui_Oven_Img_Mode6
	ui->ui_Oven_Img_Mode6 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_6);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode6, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode6, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode6_main_main_default
	static lv_style_t style_ui_oven_img_mode6_main_main_default;
	if (style_ui_oven_img_mode6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode6_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode6_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode6_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode6_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode6, &style_ui_oven_img_mode6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode6,&_icn_oven_fan_gril_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode6, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode6, 0);

	//Write codes ui_Oven_Label_Mode6
	ui->ui_Oven_Label_Mode6 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_6);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode6, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode6, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode6, "Fan Forced\nGrill");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode6_main_main_default
	static lv_style_t style_ui_oven_label_mode6_main_main_default;
	if (style_ui_oven_label_mode6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode6_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode6_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode6_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode6_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode6_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode6_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode6_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode6_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode6_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode6_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode6_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode6_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode6, &style_ui_oven_label_mode6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_5
	ui->ui_Oven_Tile_Mode_Mode_5 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 4 , 0, LV_DIR_LEFT | LV_DIR_RIGHT);

	//Write codes ui_Oven_Img_Mode5
	ui->ui_Oven_Img_Mode5 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_5);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode5, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode5, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode5_main_main_default
	static lv_style_t style_ui_oven_img_mode5_main_main_default;
	if (style_ui_oven_img_mode5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode5_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode5_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode5_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode5_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode5, &style_ui_oven_img_mode5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode5,&_icn_oven_gril_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode5, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode5, 0);

	//Write codes ui_Oven_Label_Mode5
	ui->ui_Oven_Label_Mode5 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_5);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode5, 220, 22);
	lv_obj_set_size(ui->ui_Oven_Label_Mode5, 141, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode5, "Grill");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode5_main_main_default
	static lv_style_t style_ui_oven_label_mode5_main_main_default;
	if (style_ui_oven_label_mode5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode5_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode5_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode5_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode5_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode5_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode5_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode5_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode5_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode5_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode5_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode5_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode5_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode5, &style_ui_oven_label_mode5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_4
	ui->ui_Oven_Tile_Mode_Mode_4 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 3 , 0, LV_DIR_LEFT | LV_DIR_RIGHT);

	//Write codes ui_Oven_Img_Mode4
	ui->ui_Oven_Img_Mode4 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_4);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode4, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode4, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode4_main_main_default
	static lv_style_t style_ui_oven_img_mode4_main_main_default;
	if (style_ui_oven_img_mode4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode4_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode4_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode4_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode4_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode4, &style_ui_oven_img_mode4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode4,&_icn_oven_fan_lower_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode4, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode4, 0);

	//Write codes ui_Oven_Label_Mode4
	ui->ui_Oven_Label_Mode4 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_4);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode4, 211, 7);
	lv_obj_set_size(ui->ui_Oven_Label_Mode4, 141, 66);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode4, "Fan Forced\nLower Element\nConvection");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode4_main_main_default
	static lv_style_t style_ui_oven_label_mode4_main_main_default;
	if (style_ui_oven_label_mode4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode4_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode4_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode4_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode4_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode4_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode4_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode4_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode4_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode4_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode4_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode4_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode4_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode4, &style_ui_oven_label_mode4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_3
	ui->ui_Oven_Tile_Mode_Mode_3 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 2 , 0, LV_DIR_LEFT | LV_DIR_RIGHT);

	//Write codes ui_Oven_Label_Mode3
	ui->ui_Oven_Label_Mode3 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_3);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode3, 211, 7);
	lv_obj_set_size(ui->ui_Oven_Label_Mode3, 141, 66);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode3, "Fan Forced\nUpper & Lower\nConvection");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode3_main_main_default
	static lv_style_t style_ui_oven_label_mode3_main_main_default;
	if (style_ui_oven_label_mode3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode3_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode3_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode3_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode3_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode3_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode3_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode3_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode3_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode3_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode3_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode3_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode3, &style_ui_oven_label_mode3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_Mode3
	ui->ui_Oven_Img_Mode3 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_3);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode3, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode3, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode3_main_main_default
	static lv_style_t style_ui_oven_img_mode3_main_main_default;
	if (style_ui_oven_img_mode3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode3_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode3_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode3_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode3_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode3, &style_ui_oven_img_mode3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode3,&_icn_oven_fan_upper_lower_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode3, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode3, 0);

	//add new tile ui_Oven_Tile_Mode_Mode_2
	ui->ui_Oven_Tile_Mode_Mode_2 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 1 , 0, LV_DIR_LEFT | LV_DIR_RIGHT);

	//Write codes ui_Oven_Img_Mode2
	ui->ui_Oven_Img_Mode2 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_2);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode2, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode2, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode2_main_main_default
	static lv_style_t style_ui_oven_img_mode2_main_main_default;
	if (style_ui_oven_img_mode2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode2_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode2_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode2_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode2_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode2, &style_ui_oven_img_mode2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode2,&_icn_oven_upper_lower_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode2, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode2, 0);

	//Write codes ui_Oven_Label_Mode2
	ui->ui_Oven_Label_Mode2 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_2);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode2, 211, 7);
	lv_obj_set_size(ui->ui_Oven_Label_Mode2, 141, 66);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode2, "Upper & Lower\nElements\nConvection");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode2_main_main_default
	static lv_style_t style_ui_oven_label_mode2_main_main_default;
	if (style_ui_oven_label_mode2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode2_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode2_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode2_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode2_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode2_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode2_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode2_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode2_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode2_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode2_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode2_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode2, &style_ui_oven_label_mode2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//add new tile ui_Oven_Tile_Mode_Mode_1
	ui->ui_Oven_Tile_Mode_Mode_1 = lv_tileview_add_tile(ui->ui_Oven_Tile_Mode, 0, 0, LV_DIR_RIGHT);

	//Write codes ui_Oven_Img_Mode1
	ui->ui_Oven_Img_Mode1 = lv_img_create(ui->ui_Oven_Tile_Mode_Mode_1);
	lv_obj_set_pos(ui->ui_Oven_Img_Mode1, 134, 12);
	lv_obj_set_size(ui->ui_Oven_Img_Mode1, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_Mode1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_mode1_main_main_default
	static lv_style_t style_ui_oven_img_mode1_main_main_default;
	if (style_ui_oven_img_mode1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_mode1_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_mode1_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_mode1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_mode1_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_mode1_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_Mode1, &style_ui_oven_img_mode1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_Mode1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_Mode1,&_icn_oven_fan_rear_62x62);
	lv_img_set_pivot(ui->ui_Oven_Img_Mode1, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_Mode1, 0);

	//Write codes ui_Oven_Label_Mode1
	ui->ui_Oven_Label_Mode1 = lv_label_create(ui->ui_Oven_Tile_Mode_Mode_1);
	lv_obj_set_pos(ui->ui_Oven_Label_Mode1, 211, 17);
	lv_obj_set_size(ui->ui_Oven_Label_Mode1, 141, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_Mode1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_Mode1, "Fan Forced\nRear Element");
	lv_label_set_long_mode(ui->ui_Oven_Label_Mode1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_mode1_main_main_default
	static lv_style_t style_ui_oven_label_mode1_main_main_default;
	if (style_ui_oven_label_mode1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_mode1_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_mode1_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_mode1_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_mode1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_mode1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_mode1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_mode1_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_mode1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_oven_label_mode1_main_main_default, &lv_font_Antonio_Regular_18);
	lv_style_set_text_letter_space(&style_ui_oven_label_mode1_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_mode1_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_mode1_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_ui_oven_label_mode1_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_mode1_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_mode1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_mode1_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_Mode1, &style_ui_oven_label_mode1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Group_TarTemp
	ui->ui_Oven_Group_TarTemp = lv_obj_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Group_TarTemp, 697, 427);
	lv_obj_set_size(ui->ui_Oven_Group_TarTemp, 235, 240);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Group_TarTemp, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_group_tartemp_main_main_default
	static lv_style_t style_ui_oven_group_tartemp_main_main_default;
	if (style_ui_oven_group_tartemp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_group_tartemp_main_main_default);
	else
		lv_style_init(&style_ui_oven_group_tartemp_main_main_default);
	lv_style_set_radius(&style_ui_oven_group_tartemp_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_group_tartemp_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_oven_group_tartemp_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_oven_group_tartemp_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_group_tartemp_main_main_default, 0);
	lv_style_set_border_color(&style_ui_oven_group_tartemp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_oven_group_tartemp_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_oven_group_tartemp_main_main_default, 0);
	lv_style_set_pad_left(&style_ui_oven_group_tartemp_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_group_tartemp_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_group_tartemp_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_oven_group_tartemp_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Group_TarTemp, &style_ui_oven_group_tartemp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_TempWheel
	ui->ui_Oven_Img_TempWheel = lv_img_create(ui->ui_Oven_Group_TarTemp);
	lv_obj_set_pos(ui->ui_Oven_Img_TempWheel, 51, -11);
	lv_obj_set_size(ui->ui_Oven_Img_TempWheel, 151, 259);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_TempWheel, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_tempwheel_main_main_default
	static lv_style_t style_ui_oven_img_tempwheel_main_main_default;
	if (style_ui_oven_img_tempwheel_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_tempwheel_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_tempwheel_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_tempwheel_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_tempwheel_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_tempwheel_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_TempWheel, &style_ui_oven_img_tempwheel_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_TempWheel, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_TempWheel,&_wheel_bg_151x259);
	lv_img_set_pivot(ui->ui_Oven_Img_TempWheel, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_TempWheel, 0);

	//Write codes ui_Oven_Label_SelTemp
	ui->ui_Oven_Label_SelTemp = lv_label_create(ui->ui_Oven_Group_TarTemp);
	lv_obj_set_pos(ui->ui_Oven_Label_SelTemp, -11, 91);
	lv_obj_set_size(ui->ui_Oven_Label_SelTemp, 118, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_SelTemp, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_SelTemp, "TARGET\nTEMP.");
	lv_label_set_long_mode(ui->ui_Oven_Label_SelTemp, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_seltemp_main_main_default
	static lv_style_t style_ui_oven_label_seltemp_main_main_default;
	if (style_ui_oven_label_seltemp_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_seltemp_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_seltemp_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_seltemp_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_seltemp_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_label_seltemp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_seltemp_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_seltemp_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_seltemp_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_seltemp_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_oven_label_seltemp_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_seltemp_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_seltemp_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_seltemp_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_seltemp_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_seltemp_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_seltemp_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_SelTemp, &style_ui_oven_label_seltemp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_TarCen
	ui->ui_Oven_Label_TarCen = lv_label_create(ui->ui_Oven_Group_TarTemp);
	lv_obj_set_pos(ui->ui_Oven_Label_TarCen, 68, 111);
	lv_obj_set_size(ui->ui_Oven_Label_TarCen, 55, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_TarCen, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_TarCen, "ºC");
	lv_label_set_long_mode(ui->ui_Oven_Label_TarCen, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_tarcen_main_main_default
	static lv_style_t style_ui_oven_label_tarcen_main_main_default;
	if (style_ui_oven_label_tarcen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_tarcen_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_tarcen_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_tarcen_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_tarcen_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_tarcen_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_tarcen_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_tarcen_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_tarcen_main_main_default, lv_color_make(0xc9, 0xc5, 0xc5));
	lv_style_set_text_font(&style_ui_oven_label_tarcen_main_main_default, &lv_font_Alatsi_Regular_23);
	lv_style_set_text_letter_space(&style_ui_oven_label_tarcen_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_tarcen_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_tarcen_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_tarcen_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_tarcen_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_tarcen_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_tarcen_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_TarCen, &style_ui_oven_label_tarcen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Group_Timer
	ui->ui_Oven_Group_Timer = lv_obj_create(ui->ui_Oven);
	lv_obj_set_pos(ui->ui_Oven_Group_Timer, 957, 427);
	lv_obj_set_size(ui->ui_Oven_Group_Timer, 235, 240);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Group_Timer, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_group_timer_main_main_default
	static lv_style_t style_ui_oven_group_timer_main_main_default;
	if (style_ui_oven_group_timer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_group_timer_main_main_default);
	else
		lv_style_init(&style_ui_oven_group_timer_main_main_default);
	lv_style_set_radius(&style_ui_oven_group_timer_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_group_timer_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_oven_group_timer_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_oven_group_timer_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_group_timer_main_main_default, 0);
	lv_style_set_border_color(&style_ui_oven_group_timer_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_oven_group_timer_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_oven_group_timer_main_main_default, 0);
	lv_style_set_pad_left(&style_ui_oven_group_timer_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_group_timer_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_group_timer_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_oven_group_timer_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Group_Timer, &style_ui_oven_group_timer_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Img_TimerWheel
	ui->ui_Oven_Img_TimerWheel = lv_img_create(ui->ui_Oven_Group_Timer);
	lv_obj_set_pos(ui->ui_Oven_Img_TimerWheel, 39, -11);
	lv_obj_set_size(ui->ui_Oven_Img_TimerWheel, 151, 259);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Img_TimerWheel, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_img_timerwheel_main_main_default
	static lv_style_t style_ui_oven_img_timerwheel_main_main_default;
	if (style_ui_oven_img_timerwheel_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_img_timerwheel_main_main_default);
	else
		lv_style_init(&style_ui_oven_img_timerwheel_main_main_default);
	lv_style_set_img_recolor(&style_ui_oven_img_timerwheel_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_oven_img_timerwheel_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_oven_img_timerwheel_main_main_default, 255);
	lv_obj_add_style(ui->ui_Oven_Img_TimerWheel, &style_ui_oven_img_timerwheel_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Oven_Img_TimerWheel, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Oven_Img_TimerWheel,&_wheel_bg_2_151x259);
	lv_img_set_pivot(ui->ui_Oven_Img_TimerWheel, 50,50);
	lv_img_set_angle(ui->ui_Oven_Img_TimerWheel, 0);

	//Write codes ui_Oven_Label_SelTimer
	ui->ui_Oven_Label_SelTimer = lv_label_create(ui->ui_Oven_Group_Timer);
	lv_obj_set_pos(ui->ui_Oven_Label_SelTimer, 148, 91);
	lv_obj_set_size(ui->ui_Oven_Label_SelTimer, 104, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_SelTimer, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_SelTimer, "SETUP\nTIMER");
	lv_label_set_long_mode(ui->ui_Oven_Label_SelTimer, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_seltimer_main_main_default
	static lv_style_t style_ui_oven_label_seltimer_main_main_default;
	if (style_ui_oven_label_seltimer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_seltimer_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_seltimer_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_seltimer_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_seltimer_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_bg_grad_color(&style_ui_oven_label_seltimer_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_seltimer_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_seltimer_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_seltimer_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_oven_label_seltimer_main_main_default, &lv_font_Antonio_Regular_21);
	lv_style_set_text_letter_space(&style_ui_oven_label_seltimer_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_seltimer_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_seltimer_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_seltimer_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_seltimer_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_seltimer_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_seltimer_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_SelTimer, &style_ui_oven_label_seltimer_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Oven_Label_TimerSel
	ui->ui_Oven_Label_TimerSel = lv_label_create(ui->ui_Oven_Group_Timer);
	lv_obj_set_pos(ui->ui_Oven_Label_TimerSel, 114, 108);
	lv_obj_set_size(ui->ui_Oven_Label_TimerSel, 63, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Oven_Label_TimerSel, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Oven_Label_TimerSel, "mins");
	lv_label_set_long_mode(ui->ui_Oven_Label_TimerSel, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_oven_label_timersel_main_main_default
	static lv_style_t style_ui_oven_label_timersel_main_main_default;
	if (style_ui_oven_label_timersel_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_oven_label_timersel_main_main_default);
	else
		lv_style_init(&style_ui_oven_label_timersel_main_main_default);
	lv_style_set_radius(&style_ui_oven_label_timersel_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_oven_label_timersel_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_oven_label_timersel_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_oven_label_timersel_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_oven_label_timersel_main_main_default, 0);
	lv_style_set_text_color(&style_ui_oven_label_timersel_main_main_default, lv_color_make(0xc9, 0xc5, 0xc5));
	lv_style_set_text_font(&style_ui_oven_label_timersel_main_main_default, &lv_font_Alatsi_Regular_23);
	lv_style_set_text_letter_space(&style_ui_oven_label_timersel_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_oven_label_timersel_main_main_default, 0);
	lv_style_set_text_align(&style_ui_oven_label_timersel_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_oven_label_timersel_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_oven_label_timersel_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_oven_label_timersel_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_oven_label_timersel_main_main_default, 0);
	lv_obj_add_style(ui->ui_Oven_Label_TimerSel, &style_ui_oven_label_timersel_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_ui_Oven(ui);
}