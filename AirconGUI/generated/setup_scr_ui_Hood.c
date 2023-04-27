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


void setup_scr_ui_Hood(lv_ui *ui){

	//Write codes ui_Hood
	ui->ui_Hood = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->ui_Hood, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_main_main_default
	static lv_style_t style_ui_hood_main_main_default;
	if (style_ui_hood_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_main_main_default);
	else
		lv_style_init(&style_ui_hood_main_main_default);
	lv_style_set_bg_color(&style_ui_hood_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_ui_hood_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood, &style_ui_hood_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Hood_Bg
	ui->ui_Hood_ui_Image_Hood_Bg = lv_img_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Hood_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Hood_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Hood_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_image_hood_bg_main_main_default
	static lv_style_t style_ui_hood_ui_image_hood_bg_main_main_default;
	if (style_ui_hood_ui_image_hood_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_image_hood_bg_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_image_hood_bg_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_ui_image_hood_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_ui_image_hood_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_ui_image_hood_bg_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Image_Hood_Bg, &style_ui_hood_ui_image_hood_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Hood_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Hood_Bg,&_hood_bg_1280x720);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Hood_Bg, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Hood_Bg, 0);

	//Write codes ui_Hood_ui_Image_Hood_Light
	ui->ui_Hood_ui_Image_Hood_Light = lv_img_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Hood_Light, 2, 179);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Hood_Light, 901, 460);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Hood_Light, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_image_hood_light_main_main_default
	static lv_style_t style_ui_hood_ui_image_hood_light_main_main_default;
	if (style_ui_hood_ui_image_hood_light_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_image_hood_light_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_image_hood_light_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_ui_image_hood_light_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_ui_image_hood_light_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_ui_image_hood_light_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Image_Hood_Light, &style_ui_hood_ui_image_hood_light_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Hood_Light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Hood_Light,&_hood_light_901x460);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Hood_Light, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Hood_Light, 0);

	//Write codes ui_Hood_ui_Group_Hood_Content
	ui->ui_Hood_ui_Group_Hood_Content = lv_obj_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Group_Hood_Content, 664, 98);
	lv_obj_set_size(ui->ui_Hood_ui_Group_Hood_Content, 548, 112);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Group_Hood_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_group_hood_content_main_main_default
	static lv_style_t style_ui_hood_ui_group_hood_content_main_main_default;
	if (style_ui_hood_ui_group_hood_content_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_group_hood_content_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_group_hood_content_main_main_default);
	lv_style_set_radius(&style_ui_hood_ui_group_hood_content_main_main_default, 20);
	lv_style_set_bg_color(&style_ui_hood_ui_group_hood_content_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_group_hood_content_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_group_hood_content_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_group_hood_content_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_ui_group_hood_content_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_ui_group_hood_content_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_style_set_border_color(&style_ui_hood_ui_group_hood_content_main_main_default, lv_color_make(0x4A, 0x4C, 0x4a));
	lv_style_set_border_width(&style_ui_hood_ui_group_hood_content_main_main_default, 1);
	lv_style_set_border_opa(&style_ui_hood_ui_group_hood_content_main_main_default, 255);
	lv_style_set_pad_left(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_hood_ui_group_hood_content_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_ui_Group_Hood_Content, &style_ui_hood_ui_group_hood_content_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Hood_Line
	ui->ui_Hood_ui_Hood_Line = lv_line_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_ui_Hood_Line, 9, 8);
	lv_obj_set_size(ui->ui_Hood_ui_Hood_Line, 535, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Hood_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_hood_line_main_main_default
	static lv_style_t style_ui_hood_ui_hood_line_main_main_default;
	if (style_ui_hood_ui_hood_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_hood_line_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_hood_line_main_main_default);
	lv_style_set_line_color(&style_ui_hood_ui_hood_line_main_main_default, lv_color_make(0xAC, 0xFF, 0x62));
	lv_style_set_line_width(&style_ui_hood_ui_hood_line_main_main_default, 17);
	lv_style_set_line_rounded(&style_ui_hood_ui_hood_line_main_main_default, true);
	lv_obj_add_style(ui->ui_Hood_ui_Hood_Line, &style_ui_hood_ui_hood_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Hood_ui_Hood_Line[] ={{0, 0},{526, 0},};
	lv_line_set_points(ui->ui_Hood_ui_Hood_Line,ui_Hood_ui_Hood_Line,2);

	//Write codes ui_Hood_ui_Slider_Hood_Fan
	ui->ui_Hood_ui_Slider_Hood_Fan = lv_slider_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_ui_Slider_Hood_Fan, 329, 37);
	lv_obj_set_size(ui->ui_Hood_ui_Slider_Hood_Fan, 180, 16);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Slider_Hood_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_slider_hood_fan_main_main_default
	static lv_style_t style_ui_hood_ui_slider_hood_fan_main_main_default;
	if (style_ui_hood_ui_slider_hood_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_slider_hood_fan_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_slider_hood_fan_main_main_default);
	lv_style_set_radius(&style_ui_hood_ui_slider_hood_fan_main_main_default, 50);
	lv_style_set_bg_color(&style_ui_hood_ui_slider_hood_fan_main_main_default, lv_color_make(0x52, 0x55, 0x5A));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_slider_hood_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_slider_hood_fan_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_slider_hood_fan_main_main_default, 60);
	lv_style_set_shadow_width(&style_ui_hood_ui_slider_hood_fan_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_ui_slider_hood_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_ui_slider_hood_fan_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_ui_slider_hood_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_ui_slider_hood_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_ui_slider_hood_fan_main_main_default, 0);
	lv_style_set_outline_color(&style_ui_hood_ui_slider_hood_fan_main_main_default, lv_color_make(0x73, 0xCA, 0x29));
	lv_style_set_outline_width(&style_ui_hood_ui_slider_hood_fan_main_main_default, 0);
	lv_style_set_outline_opa(&style_ui_hood_ui_slider_hood_fan_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_ui_Slider_Hood_Fan, &style_ui_hood_ui_slider_hood_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_slider_hood_fan_main_indicator_default
	static lv_style_t style_ui_hood_ui_slider_hood_fan_main_indicator_default;
	if (style_ui_hood_ui_slider_hood_fan_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_slider_hood_fan_main_indicator_default);
	else
		lv_style_init(&style_ui_hood_ui_slider_hood_fan_main_indicator_default);
	lv_style_set_radius(&style_ui_hood_ui_slider_hood_fan_main_indicator_default, 50);
	lv_style_set_bg_color(&style_ui_hood_ui_slider_hood_fan_main_indicator_default, lv_color_make(0x73, 0xCA, 0x29));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_slider_hood_fan_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_slider_hood_fan_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_slider_hood_fan_main_indicator_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Slider_Hood_Fan, &style_ui_hood_ui_slider_hood_fan_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_slider_hood_fan_main_knob_default
	static lv_style_t style_ui_hood_ui_slider_hood_fan_main_knob_default;
	if (style_ui_hood_ui_slider_hood_fan_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_slider_hood_fan_main_knob_default);
	else
		lv_style_init(&style_ui_hood_ui_slider_hood_fan_main_knob_default);
	lv_style_set_radius(&style_ui_hood_ui_slider_hood_fan_main_knob_default, 50);
	lv_style_set_bg_color(&style_ui_hood_ui_slider_hood_fan_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_slider_hood_fan_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_slider_hood_fan_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_slider_hood_fan_main_knob_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Slider_Hood_Fan, &style_ui_hood_ui_slider_hood_fan_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->ui_Hood_ui_Slider_Hood_Fan,0, 2);
	lv_slider_set_value(ui->ui_Hood_ui_Slider_Hood_Fan,1,false);

	//Write codes ui_Hood_sw_1
	ui->ui_Hood_sw_1 = lv_switch_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_sw_1, 106, 43);
	lv_obj_set_size(ui->ui_Hood_sw_1, 76, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_sw_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_sw_1_main_main_default
	static lv_style_t style_ui_hood_sw_1_main_main_default;
	if (style_ui_hood_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_sw_1_main_main_default);
	else
		lv_style_init(&style_ui_hood_sw_1_main_main_default);
	lv_style_set_radius(&style_ui_hood_sw_1_main_main_default, 100);
	lv_style_set_bg_color(&style_ui_hood_sw_1_main_main_default, lv_color_make(0x6A, 0x6A, 0x6a));
	lv_style_set_bg_grad_color(&style_ui_hood_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_ui_hood_sw_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_sw_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_hood_sw_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_sw_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_sw_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_sw_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_sw_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_sw_1_main_main_default, 0);
	lv_style_set_border_color(&style_ui_hood_sw_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_hood_sw_1_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_hood_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_sw_1, &style_ui_hood_sw_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DISABLED for style_ui_hood_sw_1_main_main_disabled
	static lv_style_t style_ui_hood_sw_1_main_main_disabled;
	if (style_ui_hood_sw_1_main_main_disabled.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_sw_1_main_main_disabled);
	else
		lv_style_init(&style_ui_hood_sw_1_main_main_disabled);
	lv_style_set_radius(&style_ui_hood_sw_1_main_main_disabled, 100);
	lv_style_set_bg_color(&style_ui_hood_sw_1_main_main_disabled, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_ui_hood_sw_1_main_main_disabled, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_ui_hood_sw_1_main_main_disabled, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_sw_1_main_main_disabled, 255);
	lv_style_set_shadow_width(&style_ui_hood_sw_1_main_main_disabled, 0);
	lv_style_set_shadow_color(&style_ui_hood_sw_1_main_main_disabled, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_sw_1_main_main_disabled, 255);
	lv_style_set_shadow_spread(&style_ui_hood_sw_1_main_main_disabled, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_sw_1_main_main_disabled, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_sw_1_main_main_disabled, 0);
	lv_style_set_border_color(&style_ui_hood_sw_1_main_main_disabled, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_hood_sw_1_main_main_disabled, 0);
	lv_style_set_border_opa(&style_ui_hood_sw_1_main_main_disabled, 255);
	lv_obj_add_style(ui->ui_Hood_sw_1, &style_ui_hood_sw_1_main_main_disabled, LV_PART_MAIN|LV_STATE_DISABLED);

	//Write style state: LV_STATE_CHECKED for style_ui_hood_sw_1_main_indicator_checked
	static lv_style_t style_ui_hood_sw_1_main_indicator_checked;
	if (style_ui_hood_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_ui_hood_sw_1_main_indicator_checked);
	lv_style_set_bg_color(&style_ui_hood_sw_1_main_indicator_checked, lv_color_make(0x73, 0xCA, 0x29));
	lv_style_set_bg_grad_color(&style_ui_hood_sw_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_sw_1_main_indicator_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_sw_1_main_indicator_checked, 255);
	lv_style_set_border_color(&style_ui_hood_sw_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_hood_sw_1_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_ui_hood_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->ui_Hood_sw_1, &style_ui_hood_sw_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_sw_1_main_knob_default
	static lv_style_t style_ui_hood_sw_1_main_knob_default;
	if (style_ui_hood_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_sw_1_main_knob_default);
	else
		lv_style_init(&style_ui_hood_sw_1_main_knob_default);
	lv_style_set_radius(&style_ui_hood_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_ui_hood_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_hood_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_hood_sw_1_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_sw_1_main_knob_default, 255);
	lv_style_set_border_color(&style_ui_hood_sw_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_hood_sw_1_main_knob_default, 0);
	lv_style_set_border_opa(&style_ui_hood_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->ui_Hood_sw_1, &style_ui_hood_sw_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Line2
	ui->ui_Hood_ui_Line2 = lv_line_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_ui_Line2, 209, 32);
	lv_obj_set_size(ui->ui_Hood_ui_Line2, 8, 65);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Line2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_line2_main_main_default
	static lv_style_t style_ui_hood_ui_line2_main_main_default;
	if (style_ui_hood_ui_line2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_line2_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_line2_main_main_default);
	lv_style_set_line_color(&style_ui_hood_ui_line2_main_main_default, lv_color_make(0x52, 0x55, 0x5a));
	lv_style_set_line_width(&style_ui_hood_ui_line2_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_hood_ui_line2_main_main_default, true);
	lv_obj_add_style(ui->ui_Hood_ui_Line2, &style_ui_hood_ui_line2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Hood_ui_Line2[] ={{0, 0},{0, 60},};
	lv_line_set_points(ui->ui_Hood_ui_Line2,ui_Hood_ui_Line2,2);

	//Write codes ui_Hood_ui_Label_Light
	ui->ui_Hood_ui_Label_Light = lv_label_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_ui_Label_Light, 4, 44);
	lv_obj_set_size(ui->ui_Hood_ui_Label_Light, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Label_Light, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Hood_ui_Label_Light, "LIGHT");
	lv_label_set_long_mode(ui->ui_Hood_ui_Label_Light, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_label_light_main_main_default
	static lv_style_t style_ui_hood_ui_label_light_main_main_default;
	if (style_ui_hood_ui_label_light_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_label_light_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_label_light_main_main_default);
	lv_style_set_radius(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_hood_ui_label_light_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_label_light_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_label_light_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_ui_label_light_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_ui_label_light_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_text_color(&style_ui_hood_ui_label_light_main_main_default, lv_color_make(0xAC, 0xFF, 0x62));
	lv_style_set_text_font(&style_ui_hood_ui_label_light_main_main_default, &lv_font_montserratMedium_19);
	lv_style_set_text_letter_space(&style_ui_hood_ui_label_light_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_text_align(&style_ui_hood_ui_label_light_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_hood_ui_label_light_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_hood_ui_label_light_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_ui_Label_Light, &style_ui_hood_ui_label_light_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Hood_Text
	ui->ui_Hood_ui_Image_Hood_Text = lv_img_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Hood_Text, 323, 70);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Hood_Text, 198, 26);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Hood_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_image_hood_text_main_main_default
	static lv_style_t style_ui_hood_ui_image_hood_text_main_main_default;
	if (style_ui_hood_ui_image_hood_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_image_hood_text_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_image_hood_text_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_ui_image_hood_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_ui_image_hood_text_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_ui_image_hood_text_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Image_Hood_Text, &style_ui_hood_ui_image_hood_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Hood_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Hood_Text,&_text_fan_param_198x26);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Hood_Text, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Hood_Text, 0);

	//Write codes ui_Hood_ui_Label_Fan
	ui->ui_Hood_ui_Label_Fan = lv_label_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_ui_Label_Fan, 216, 44);
	lv_obj_set_size(ui->ui_Hood_ui_Label_Fan, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Label_Fan, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Hood_ui_Label_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Hood_ui_Label_Fan, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_label_fan_main_main_default
	static lv_style_t style_ui_hood_ui_label_fan_main_main_default;
	if (style_ui_hood_ui_label_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_label_fan_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_label_fan_main_main_default);
	lv_style_set_radius(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_hood_ui_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_label_fan_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_ui_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_ui_label_fan_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_text_color(&style_ui_hood_ui_label_fan_main_main_default, lv_color_make(0xAC, 0xFF, 0x62));
	lv_style_set_text_font(&style_ui_hood_ui_label_fan_main_main_default, &lv_font_montserratMedium_19);
	lv_style_set_text_letter_space(&style_ui_hood_ui_label_fan_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_text_align(&style_ui_hood_ui_label_fan_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_hood_ui_label_fan_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_hood_ui_label_fan_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_ui_Label_Fan, &style_ui_hood_ui_label_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Group_Smog1
	ui->ui_Hood_ui_Group_Smog1 = lv_obj_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Group_Smog1, 189, 210);
	lv_obj_set_size(ui->ui_Hood_ui_Group_Smog1, 195, 310);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Group_Smog1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_group_smog1_main_main_default
	static lv_style_t style_ui_hood_ui_group_smog1_main_main_default;
	if (style_ui_hood_ui_group_smog1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_group_smog1_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_group_smog1_main_main_default);
	lv_style_set_radius(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_hood_ui_group_smog1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_group_smog1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_group_smog1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_ui_group_smog1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_ui_group_smog1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_border_color(&style_ui_hood_ui_group_smog1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_hood_ui_group_smog1_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_pad_left(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_hood_ui_group_smog1_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_ui_Group_Smog1, &style_ui_hood_ui_group_smog1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Smog11
	ui->ui_Hood_ui_Image_Smog11 = lv_img_create(ui->ui_Hood_ui_Group_Smog1);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog11, 31, 0);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog11, 133, 472);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog11, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_image_smog11_main_main_default
	static lv_style_t style_ui_hood_ui_image_smog11_main_main_default;
	if (style_ui_hood_ui_image_smog11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_image_smog11_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_image_smog11_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_ui_image_smog11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_ui_image_smog11_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_ui_image_smog11_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Image_Smog11, &style_ui_hood_ui_image_smog11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog11,&_smog_1_133x472);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog11, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog11, 0);

	//Write codes ui_Hood_ui_Image_Smog12
	ui->ui_Hood_ui_Image_Smog12 = lv_img_create(ui->ui_Hood_ui_Group_Smog1);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog12, 31, 310);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog12, 133, 630);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog12, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_image_smog12_main_main_default
	static lv_style_t style_ui_hood_ui_image_smog12_main_main_default;
	if (style_ui_hood_ui_image_smog12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_image_smog12_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_image_smog12_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_ui_image_smog12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_ui_image_smog12_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_ui_image_smog12_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Image_Smog12, &style_ui_hood_ui_image_smog12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog12,&_smog_2_133x630);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog12, 0,0);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog12, 0);

	//Write codes ui_Hood_ui_Group_Smog2
	ui->ui_Hood_ui_Group_Smog2 = lv_obj_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Group_Smog2, 411, 210);
	lv_obj_set_size(ui->ui_Hood_ui_Group_Smog2, 195, 310);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Group_Smog2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_group_smog2_main_main_default
	static lv_style_t style_ui_hood_ui_group_smog2_main_main_default;
	if (style_ui_hood_ui_group_smog2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_group_smog2_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_group_smog2_main_main_default);
	lv_style_set_radius(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_hood_ui_group_smog2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_group_smog2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_group_smog2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_ui_group_smog2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_ui_group_smog2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_border_color(&style_ui_hood_ui_group_smog2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_hood_ui_group_smog2_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_pad_left(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_hood_ui_group_smog2_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_ui_Group_Smog2, &style_ui_hood_ui_group_smog2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Smog21
	ui->ui_Hood_ui_Image_Smog21 = lv_img_create(ui->ui_Hood_ui_Group_Smog2);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog21, 33, 0);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog21, 133, 472);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog21, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_image_smog21_main_main_default
	static lv_style_t style_ui_hood_ui_image_smog21_main_main_default;
	if (style_ui_hood_ui_image_smog21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_image_smog21_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_image_smog21_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_ui_image_smog21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_ui_image_smog21_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_ui_image_smog21_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Image_Smog21, &style_ui_hood_ui_image_smog21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog21, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog21,&_smog_1_133x472);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog21, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog21, 0);

	//Write codes ui_Hood_ui_Image_Smog22
	ui->ui_Hood_ui_Image_Smog22 = lv_img_create(ui->ui_Hood_ui_Group_Smog2);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog22, 33, 310);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog22, 133, 630);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog22, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_image_smog22_main_main_default
	static lv_style_t style_ui_hood_ui_image_smog22_main_main_default;
	if (style_ui_hood_ui_image_smog22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_image_smog22_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_image_smog22_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_ui_image_smog22_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_ui_image_smog22_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_ui_image_smog22_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_ui_Image_Smog22, &style_ui_hood_ui_image_smog22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog22, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog22,&_smog_2_133x630);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog22, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog22, 0);

	//Write codes ui_Hood_Lottie_Mic
	ui->ui_Hood_Lottie_Mic = lv_rlottie_create_from_raw(ui->ui_Hood, 62, 74, (const void *)lottie_lf30_gbhpz7py);
	lv_obj_set_pos(ui->ui_Hood_Lottie_Mic, 8, 639);
	lv_obj_set_size(ui->ui_Hood_Lottie_Mic, 62, 74);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_lottie_mic_main_main_default
	static lv_style_t style_ui_hood_lottie_mic_main_main_default;
	if (style_ui_hood_lottie_mic_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_lottie_mic_main_main_default);
	else
		lv_style_init(&style_ui_hood_lottie_mic_main_main_default);
	lv_style_set_bg_color(&style_ui_hood_lottie_mic_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_opa(&style_ui_hood_lottie_mic_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_Lottie_Mic, &style_ui_hood_lottie_mic_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_Img_Label_Bg
	ui->ui_Hood_Img_Label_Bg = lv_img_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_Img_Label_Bg, 630, -15);
	lv_obj_set_size(ui->ui_Hood_Img_Label_Bg, 783, 128);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_Img_Label_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_img_label_bg_main_main_default
	static lv_style_t style_ui_hood_img_label_bg_main_main_default;
	if (style_ui_hood_img_label_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_img_label_bg_main_main_default);
	else
		lv_style_init(&style_ui_hood_img_label_bg_main_main_default);
	lv_style_set_img_recolor(&style_ui_hood_img_label_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_hood_img_label_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_hood_img_label_bg_main_main_default, 255);
	lv_obj_add_style(ui->ui_Hood_Img_Label_Bg, &style_ui_hood_img_label_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Hood_Img_Label_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_Img_Label_Bg,&_title_bg_2_783x128);
	lv_img_set_pivot(ui->ui_Hood_Img_Label_Bg, 50,50);
	lv_img_set_angle(ui->ui_Hood_Img_Label_Bg, 0);

	//Write codes ui_Hood_Label_Hood
	ui->ui_Hood_Label_Hood = lv_label_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_Label_Hood, 679, 33);
	lv_obj_set_size(ui->ui_Hood_Label_Hood, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_Label_Hood, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Hood_Label_Hood, "Hood");
	lv_label_set_long_mode(ui->ui_Hood_Label_Hood, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_label_hood_main_main_default
	static lv_style_t style_ui_hood_label_hood_main_main_default;
	if (style_ui_hood_label_hood_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_label_hood_main_main_default);
	else
		lv_style_init(&style_ui_hood_label_hood_main_main_default);
	lv_style_set_radius(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_hood_label_hood_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_hood_label_hood_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_label_hood_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_label_hood_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_label_hood_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_text_color(&style_ui_hood_label_hood_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_hood_label_hood_main_main_default, &lv_font_Antonio_Regular_22);
	lv_style_set_text_letter_space(&style_ui_hood_label_hood_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_text_align(&style_ui_hood_label_hood_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_hood_label_hood_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_hood_label_hood_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_hood_label_hood_main_main_default, 0);
	lv_obj_add_style(ui->ui_Hood_Label_Hood, &style_ui_hood_label_hood_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Btn_Back1
	ui->ui_Hood_ui_Btn_Back1 = lv_btn_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Btn_Back1, -41, 24);
	lv_obj_set_size(ui->ui_Hood_ui_Btn_Back1, 155, 65);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Btn_Back1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_hood_ui_btn_back1_main_main_default
	static lv_style_t style_ui_hood_ui_btn_back1_main_main_default;
	if (style_ui_hood_ui_btn_back1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_hood_ui_btn_back1_main_main_default);
	else
		lv_style_init(&style_ui_hood_ui_btn_back1_main_main_default);
	lv_style_set_radius(&style_ui_hood_ui_btn_back1_main_main_default, 65);
	lv_style_set_bg_color(&style_ui_hood_ui_btn_back1_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_hood_ui_btn_back1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_hood_ui_btn_back1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_hood_ui_btn_back1_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_hood_ui_btn_back1_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_hood_ui_btn_back1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_hood_ui_btn_back1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_hood_ui_btn_back1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_hood_ui_btn_back1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_hood_ui_btn_back1_main_main_default, 0);
	lv_style_set_border_color(&style_ui_hood_ui_btn_back1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_hood_ui_btn_back1_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_hood_ui_btn_back1_main_main_default, 255);
	lv_style_set_text_color(&style_ui_hood_ui_btn_back1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_hood_ui_btn_back1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_ui_hood_ui_btn_back1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Hood_ui_Btn_Back1, &style_ui_hood_ui_btn_back1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->ui_Hood_ui_Btn_Back1_label = lv_label_create(ui->ui_Hood_ui_Btn_Back1);
	lv_label_set_text(ui->ui_Hood_ui_Btn_Back1_label, "BACK");
	lv_obj_set_style_pad_all(ui->ui_Hood_ui_Btn_Back1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Hood_ui_Btn_Back1_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_ui_Hood(ui);
}