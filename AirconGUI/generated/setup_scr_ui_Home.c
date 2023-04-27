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


void setup_scr_ui_Home(lv_ui *ui){

	//Write codes ui_Home
	ui->ui_Home = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->ui_Home, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_main_main_default
	static lv_style_t style_ui_home_main_main_default;
	if (style_ui_home_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_main_main_default);
	else
		lv_style_init(&style_ui_home_main_main_default);
	lv_style_set_bg_color(&style_ui_home_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_ui_home_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home, &style_ui_home_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Menu_Bg
	ui->ui_Home_ui_Image_Menu_Bg = lv_img_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Menu_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Home_ui_Image_Menu_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Menu_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_menu_bg_main_main_default
	static lv_style_t style_ui_home_ui_image_menu_bg_main_main_default;
	if (style_ui_home_ui_image_menu_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_menu_bg_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_menu_bg_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_menu_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_menu_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_menu_bg_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Menu_Bg, &style_ui_home_ui_image_menu_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Menu_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Menu_Bg,&_menu_bg_1280x720);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Menu_Bg, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Menu_Bg, 0);

	//Write codes ui_Home_ui_Group_Nxp_Logo
	ui->ui_Home_ui_Group_Nxp_Logo = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Nxp_Logo, 15, 325);
	lv_obj_set_size(ui->ui_Home_ui_Group_Nxp_Logo, 388, 50);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Nxp_Logo, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_group_nxp_logo_main_main_default
	static lv_style_t style_ui_home_ui_group_nxp_logo_main_main_default;
	if (style_ui_home_ui_group_nxp_logo_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_group_nxp_logo_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_group_nxp_logo_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_group_nxp_logo_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_home_ui_group_nxp_logo_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_home_ui_group_nxp_logo_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_group_nxp_logo_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_group_nxp_logo_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_group_nxp_logo_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_group_nxp_logo_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_group_nxp_logo_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_border_width(&style_ui_home_ui_group_nxp_logo_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_home_ui_group_nxp_logo_main_main_default, 255);
	lv_style_set_pad_left(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_home_ui_group_nxp_logo_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Group_Nxp_Logo, &style_ui_home_ui_group_nxp_logo_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Nxp_Logo
	ui->ui_Home_ui_Image_Nxp_Logo = lv_img_create(ui->ui_Home_ui_Group_Nxp_Logo);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Nxp_Logo, 22, 10);
	lv_obj_set_size(ui->ui_Home_ui_Image_Nxp_Logo, 75, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Nxp_Logo, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_nxp_logo_main_main_default
	static lv_style_t style_ui_home_ui_image_nxp_logo_main_main_default;
	if (style_ui_home_ui_image_nxp_logo_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_nxp_logo_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_nxp_logo_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_nxp_logo_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_nxp_logo_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_nxp_logo_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Nxp_Logo, &style_ui_home_ui_image_nxp_logo_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Nxp_Logo, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Nxp_Logo,&_nxp_75x27);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Nxp_Logo, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Nxp_Logo, 0);

	//Write codes ui_Home_ui_Label_Smart_Kitchen_Demo
	ui->ui_Home_ui_Label_Smart_Kitchen_Demo = lv_label_create(ui->ui_Home_ui_Group_Nxp_Logo);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 130, 7);
	lv_obj_set_size(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 240, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, "Smart Kitchen Demo");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_smart_kitchen_demo_main_main_default
	static lv_style_t style_ui_home_ui_label_smart_kitchen_demo_main_main_default;
	if (style_ui_home_ui_label_smart_kitchen_demo_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_smart_kitchen_demo_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, &style_ui_home_ui_label_smart_kitchen_demo_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Aircon_Content
	ui->ui_Home_ui_Group_Aircon_Content = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Aircon_Content, 16, 29);
	lv_obj_set_size(ui->ui_Home_ui_Group_Aircon_Content, 389, 272);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Aircon_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_group_aircon_content_main_main_default
	static lv_style_t style_ui_home_ui_group_aircon_content_main_main_default;
	if (style_ui_home_ui_group_aircon_content_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_group_aircon_content_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_group_aircon_content_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_group_aircon_content_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_home_ui_group_aircon_content_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_home_ui_group_aircon_content_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_group_aircon_content_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_group_aircon_content_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_group_aircon_content_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_group_aircon_content_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_group_aircon_content_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_border_width(&style_ui_home_ui_group_aircon_content_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_home_ui_group_aircon_content_main_main_default, 255);
	lv_style_set_pad_left(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_home_ui_group_aircon_content_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Group_Aircon_Content, &style_ui_home_ui_group_aircon_content_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Aircon_Text
	ui->ui_Home_ui_Image_Aircon_Text = lv_img_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Text, 23, 159);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Text, 15, 88);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_aircon_text_main_main_default
	static lv_style_t style_ui_home_ui_image_aircon_text_main_main_default;
	if (style_ui_home_ui_image_aircon_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_aircon_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_aircon_text_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_aircon_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_aircon_text_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_aircon_text_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Aircon_Text, &style_ui_home_ui_image_aircon_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Text,&_text_aircon_15x88);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Text, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Text, 0);

	//Write codes ui_Home_ui_Aircon_Line
	ui->ui_Home_ui_Aircon_Line = lv_line_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Aircon_Line, 2, 8);
	lv_obj_set_size(ui->ui_Home_ui_Aircon_Line, 21, 259);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Aircon_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_aircon_line_main_main_default
	static lv_style_t style_ui_home_ui_aircon_line_main_main_default;
	if (style_ui_home_ui_aircon_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_aircon_line_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_aircon_line_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_aircon_line_main_main_default, lv_color_make(0x52, 0xDA, 0xFf));
	lv_style_set_line_width(&style_ui_home_ui_aircon_line_main_main_default, 14);
	lv_style_set_line_rounded(&style_ui_home_ui_aircon_line_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Aircon_Line, &style_ui_home_ui_aircon_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Aircon_Line[] ={{0, 0},{0, 252},};
	lv_line_set_points(ui->ui_Home_ui_Aircon_Line,ui_Home_ui_Aircon_Line,2);

	//Write codes ui_Home_ui_Line_1
	ui->ui_Home_ui_Line_1 = lv_line_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Line_1, 223, 152);
	lv_obj_set_size(ui->ui_Home_ui_Line_1, 3, 108);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_1_main_main_default
	static lv_style_t style_ui_home_ui_line_1_main_main_default;
	if (style_ui_home_ui_line_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_1_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_1_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_1_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_1_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_home_ui_line_1_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_1, &style_ui_home_ui_line_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_1[] ={{0, 0},{0, 100},};
	lv_line_set_points(ui->ui_Home_ui_Line_1,ui_Home_ui_Line_1,2);

	//Write codes ui_Home_ui_Label_Aircon_Mode
	ui->ui_Home_ui_Label_Aircon_Mode = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Mode, 262, 143);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Mode, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Mode, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Mode, "MODE");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Mode, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_aircon_mode_main_main_default
	static lv_style_t style_ui_home_ui_label_aircon_mode_main_main_default;
	if (style_ui_home_ui_label_aircon_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_aircon_mode_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_aircon_mode_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_aircon_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_aircon_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_aircon_mode_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_aircon_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_aircon_mode_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_aircon_mode_main_main_default, lv_color_make(0x52, 0xDA, 0xFf));
	lv_style_set_text_font(&style_ui_home_ui_label_aircon_mode_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_aircon_mode_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_aircon_mode_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_aircon_mode_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_aircon_mode_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Aircon_Mode, &style_ui_home_ui_label_aircon_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Fan
	ui->ui_Home_ui_Label_Aircon_Fan = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Fan, 262, 202);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Fan, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Fan, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Fan, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_aircon_fan_main_main_default
	static lv_style_t style_ui_home_ui_label_aircon_fan_main_main_default;
	if (style_ui_home_ui_label_aircon_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_aircon_fan_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_aircon_fan_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_aircon_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_aircon_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_aircon_fan_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_aircon_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_aircon_fan_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_aircon_fan_main_main_default, lv_color_make(0x52, 0xDA, 0xFf));
	lv_style_set_text_font(&style_ui_home_ui_label_aircon_fan_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_aircon_fan_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_aircon_fan_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_aircon_fan_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_aircon_fan_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Aircon_Fan, &style_ui_home_ui_label_aircon_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Mode_Text
	ui->ui_Home_ui_Label_Aircon_Mode_Text = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Mode_Text, 281, 168);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Mode_Text, 60, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Mode_Text, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Mode_Text, "Dry");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Mode_Text, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_aircon_mode_text_main_main_default
	static lv_style_t style_ui_home_ui_label_aircon_mode_text_main_main_default;
	if (style_ui_home_ui_label_aircon_mode_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_aircon_mode_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_aircon_mode_text_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_aircon_mode_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_aircon_mode_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_aircon_mode_text_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_aircon_mode_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_aircon_mode_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_aircon_mode_text_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_aircon_mode_text_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_aircon_mode_text_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Aircon_Mode_Text, &style_ui_home_ui_label_aircon_mode_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Fan_Text
	ui->ui_Home_ui_Label_Aircon_Fan_Text = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Fan_Text, 281, 226);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Fan_Text, 60, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Fan_Text, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Fan_Text, "Low");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Fan_Text, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_aircon_fan_text_main_main_default
	static lv_style_t style_ui_home_ui_label_aircon_fan_text_main_main_default;
	if (style_ui_home_ui_label_aircon_fan_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_aircon_fan_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_aircon_fan_text_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_aircon_fan_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_aircon_fan_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_aircon_fan_text_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_aircon_fan_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_aircon_fan_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_aircon_fan_text_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_aircon_fan_text_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_aircon_fan_text_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Aircon_Fan_Text, &style_ui_home_ui_label_aircon_fan_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Aircon_Mode
	ui->ui_Home_ui_Image_Aircon_Mode = lv_img_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Mode, 241, 157);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Mode, 27, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_aircon_mode_main_main_default
	static lv_style_t style_ui_home_ui_image_aircon_mode_main_main_default;
	if (style_ui_home_ui_image_aircon_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_aircon_mode_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_aircon_mode_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_aircon_mode_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_aircon_mode_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_aircon_mode_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Aircon_Mode, &style_ui_home_ui_image_aircon_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Mode, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Mode,&_icn_cool_27x31);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Mode, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Mode, 0);

	//Write codes ui_Home_ui_Image_Aircon_Fan
	ui->ui_Home_ui_Image_Aircon_Fan = lv_img_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Fan, 241, 218);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Fan, 31, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_aircon_fan_main_main_default
	static lv_style_t style_ui_home_ui_image_aircon_fan_main_main_default;
	if (style_ui_home_ui_image_aircon_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_aircon_fan_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_aircon_fan_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_aircon_fan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_aircon_fan_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_aircon_fan_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Aircon_Fan, &style_ui_home_ui_image_aircon_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Fan,&_icn_fan_low_31x27);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Fan, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Fan, 0);

	//Write codes ui_Home_ui_Label_Aircon_Number1
	ui->ui_Home_ui_Label_Aircon_Number1 = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Number1, 75, 155);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Number1, 120, 89);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Number1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Number1, "46");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Number1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_aircon_number1_main_main_default
	static lv_style_t style_ui_home_ui_label_aircon_number1_main_main_default;
	if (style_ui_home_ui_label_aircon_number1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_aircon_number1_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_aircon_number1_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_aircon_number1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_aircon_number1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_aircon_number1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_aircon_number1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_aircon_number1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_aircon_number1_main_main_default, lv_color_make(0x52, 0xDA, 0xFf));
	lv_style_set_text_font(&style_ui_home_ui_label_aircon_number1_main_main_default, &lv_font_montserratMedium_80);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_aircon_number1_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_aircon_number1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_aircon_number1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_aircon_number1_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Aircon_Number1, &style_ui_home_ui_label_aircon_number1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Oven_Content
	ui->ui_Home_ui_Group_Oven_Content = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Oven_Content, 16, 399);
	lv_obj_set_size(ui->ui_Home_ui_Group_Oven_Content, 767, 305);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Oven_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_group_oven_content_main_main_default
	static lv_style_t style_ui_home_ui_group_oven_content_main_main_default;
	if (style_ui_home_ui_group_oven_content_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_group_oven_content_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_group_oven_content_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_group_oven_content_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_home_ui_group_oven_content_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_home_ui_group_oven_content_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_group_oven_content_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_group_oven_content_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_group_oven_content_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_group_oven_content_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_group_oven_content_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_border_width(&style_ui_home_ui_group_oven_content_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_home_ui_group_oven_content_main_main_default, 255);
	lv_style_set_pad_left(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_home_ui_group_oven_content_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Group_Oven_Content, &style_ui_home_ui_group_oven_content_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Oven_Text
	ui->ui_Home_ui_Image_Oven_Text = lv_img_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Oven_Text, 23, 113);
	lv_obj_set_size(ui->ui_Home_ui_Image_Oven_Text, 15, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Oven_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_oven_text_main_main_default
	static lv_style_t style_ui_home_ui_image_oven_text_main_main_default;
	if (style_ui_home_ui_image_oven_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_oven_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_oven_text_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_oven_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_oven_text_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_oven_text_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Oven_Text, &style_ui_home_ui_image_oven_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Oven_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Oven_Text,&_text_oven_15x62);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Oven_Text, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Oven_Text, 0);

	//Write codes ui_Home_ui_Oven_Line
	ui->ui_Home_ui_Oven_Line = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Oven_Line, 3, 8);
	lv_obj_set_size(ui->ui_Home_ui_Oven_Line, 60, 291);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Oven_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_oven_line_main_main_default
	static lv_style_t style_ui_home_ui_oven_line_main_main_default;
	if (style_ui_home_ui_oven_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_oven_line_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_oven_line_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_oven_line_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_line_width(&style_ui_home_ui_oven_line_main_main_default, 14);
	lv_style_set_line_rounded(&style_ui_home_ui_oven_line_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Oven_Line, &style_ui_home_ui_oven_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Oven_Line[] ={{0, 0},{0, 285},};
	lv_line_set_points(ui->ui_Home_ui_Oven_Line,ui_Home_ui_Oven_Line,2);

	//Write codes ui_Home_ui_Line_4
	ui->ui_Home_ui_Line_4 = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Line_4, 62, 140);
	lv_obj_set_size(ui->ui_Home_ui_Line_4, 198, 1);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_4_main_main_default
	static lv_style_t style_ui_home_ui_line_4_main_main_default;
	if (style_ui_home_ui_line_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_4_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_4_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_4_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_4_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_home_ui_line_4_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_4, &style_ui_home_ui_line_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_4[] ={{0, 0},{198, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_4,ui_Home_ui_Line_4,2);

	//Write codes ui_Home_ui_Line_5
	ui->ui_Home_ui_Line_5 = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Line_5, 283, 15);
	lv_obj_set_size(ui->ui_Home_ui_Line_5, 2, 282);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_5_main_main_default
	static lv_style_t style_ui_home_ui_line_5_main_main_default;
	if (style_ui_home_ui_line_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_5_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_5_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_5_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_5_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_home_ui_line_5_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_5, &style_ui_home_ui_line_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_5[] ={{0, 0},{0, 275},};
	lv_line_set_points(ui->ui_Home_ui_Line_5,ui_Home_ui_Line_5,2);

	//Write codes ui_Home_ui_Line_6
	ui->ui_Home_ui_Line_6 = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Line_6, 308, 95);
	lv_obj_set_size(ui->ui_Home_ui_Line_6, 157, 2);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_6_main_main_default
	static lv_style_t style_ui_home_ui_line_6_main_main_default;
	if (style_ui_home_ui_line_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_6_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_6_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_6_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_6_main_main_default, 2);
	lv_style_set_line_rounded(&style_ui_home_ui_line_6_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_6, &style_ui_home_ui_line_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_6[] ={{0, 0},{150, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_6,ui_Home_ui_Line_6,2);

	//Write codes ui_Home_ui_Label_Time_Left
	ui->ui_Home_ui_Label_Time_Left = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Time_Left, 64, 180);
	lv_obj_set_size(ui->ui_Home_ui_Label_Time_Left, 68, 44);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Time_Left, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Time_Left, "TIME\nLEFT");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Time_Left, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_time_left_main_main_default
	static lv_style_t style_ui_home_ui_label_time_left_main_main_default;
	if (style_ui_home_ui_label_time_left_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_time_left_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_time_left_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_time_left_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_time_left_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_time_left_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_time_left_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_time_left_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_time_left_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_home_ui_label_time_left_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_time_left_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_time_left_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_time_left_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_time_left_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Time_Left, &style_ui_home_ui_label_time_left_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Status
	ui->ui_Home_ui_Label_Status = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Status, 333, 12);
	lv_obj_set_size(ui->ui_Home_ui_Label_Status, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Status, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Status, "STATUS");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Status, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_status_main_main_default
	static lv_style_t style_ui_home_ui_label_status_main_main_default;
	if (style_ui_home_ui_label_status_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_status_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_status_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_status_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_status_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_status_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_status_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_status_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_status_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_home_ui_label_status_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_status_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_status_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_status_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_status_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Status, &style_ui_home_ui_label_status_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Oven_Mode
	ui->ui_Home_ui_Label_Oven_Mode = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Oven_Mode, 333, 106);
	lv_obj_set_size(ui->ui_Home_ui_Label_Oven_Mode, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Oven_Mode, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Oven_Mode, "MODE");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Oven_Mode, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_oven_mode_main_main_default
	static lv_style_t style_ui_home_ui_label_oven_mode_main_main_default;
	if (style_ui_home_ui_label_oven_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_oven_mode_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_oven_mode_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_oven_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_oven_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_oven_mode_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_oven_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_oven_mode_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_oven_mode_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_home_ui_label_oven_mode_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_oven_mode_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_oven_mode_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_oven_mode_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_oven_mode_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Oven_Mode, &style_ui_home_ui_label_oven_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Mystat
	ui->ui_Home_ui_Label_Mystat = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Mystat, 333, 39);
	lv_obj_set_size(ui->ui_Home_ui_Label_Mystat, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Mystat, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Mystat, "My stat");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Mystat, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_mystat_main_main_default
	static lv_style_t style_ui_home_ui_label_mystat_main_main_default;
	if (style_ui_home_ui_label_mystat_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_mystat_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_mystat_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_mystat_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_mystat_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_mystat_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_mystat_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_mystat_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_mystat_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_mystat_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_mystat_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_mystat_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_mystat_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_mystat_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Mystat, &style_ui_home_ui_label_mystat_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Mode1
	ui->ui_Home_ui_Label_Mode1 = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Mode1, 328, 133);
	lv_obj_set_size(ui->ui_Home_ui_Label_Mode1, 114, 96);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Mode1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Mode1, "Fan Forced\nLower Element\nConvection");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Mode1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_mode1_main_main_default
	static lv_style_t style_ui_home_ui_label_mode1_main_main_default;
	if (style_ui_home_ui_label_mode1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_mode1_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_mode1_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_mode1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_mode1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_mode1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_mode1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_mode1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_mode1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_mode1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_mode1_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_mode1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_mode1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_mode1_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Mode1, &style_ui_home_ui_label_mode1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Oven_Mode
	ui->ui_Home_ui_Image_Oven_Mode = lv_img_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Oven_Mode, 354, 228);
	lv_obj_set_size(ui->ui_Home_ui_Image_Oven_Mode, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Oven_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_oven_mode_main_main_default
	static lv_style_t style_ui_home_ui_image_oven_mode_main_main_default;
	if (style_ui_home_ui_image_oven_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_oven_mode_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_oven_mode_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_oven_mode_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_oven_mode_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_oven_mode_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Oven_Mode, &style_ui_home_ui_image_oven_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Oven_Mode, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Oven_Mode,&_icn_oven_fan_upper_lower_62x62);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Oven_Mode, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Oven_Mode, 0);

	//Write codes ui_Home_ui_Label_Oven_Number1
	ui->ui_Home_ui_Label_Oven_Number1 = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Oven_Number1, 73, 33);
	lv_obj_set_size(ui->ui_Home_ui_Label_Oven_Number1, 173, 92);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Oven_Number1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Oven_Number1, "234");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Oven_Number1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_oven_number1_main_main_default
	static lv_style_t style_ui_home_ui_label_oven_number1_main_main_default;
	if (style_ui_home_ui_label_oven_number1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_oven_number1_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_oven_number1_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_oven_number1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_oven_number1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_oven_number1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_oven_number1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_oven_number1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_oven_number1_main_main_default, lv_color_make(0xFF, 0x91, 0x10));
	lv_style_set_text_font(&style_ui_home_ui_label_oven_number1_main_main_default, &lv_font_montserratMedium_80);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_oven_number1_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_oven_number1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_oven_number1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_oven_number1_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Oven_Number1, &style_ui_home_ui_label_oven_number1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Hood_Content
	ui->ui_Home_ui_Group_Hood_Content = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Hood_Content, 449, 20);
	lv_obj_set_size(ui->ui_Home_ui_Group_Hood_Content, 328, 167);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Hood_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_group_hood_content_main_main_default
	static lv_style_t style_ui_home_ui_group_hood_content_main_main_default;
	if (style_ui_home_ui_group_hood_content_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_group_hood_content_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_group_hood_content_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_group_hood_content_main_main_default, 10);
	lv_style_set_bg_color(&style_ui_home_ui_group_hood_content_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_home_ui_group_hood_content_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_group_hood_content_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_group_hood_content_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_group_hood_content_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_group_hood_content_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_group_hood_content_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_border_width(&style_ui_home_ui_group_hood_content_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_home_ui_group_hood_content_main_main_default, 255);
	lv_style_set_pad_left(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_home_ui_group_hood_content_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Group_Hood_Content, &style_ui_home_ui_group_hood_content_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Text
	ui->ui_Home_ui_Image_Hood_Text = lv_img_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Text, 20, 45);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Text, 15, 68);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_hood_text_main_main_default
	static lv_style_t style_ui_home_ui_image_hood_text_main_main_default;
	if (style_ui_home_ui_image_hood_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_hood_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_hood_text_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_hood_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_hood_text_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_hood_text_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Hood_Text, &style_ui_home_ui_image_hood_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Text,&_text_hood_15x68);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Text, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Text, 0);

	//Write codes ui_Home_ui_Hood_Line
	ui->ui_Home_ui_Hood_Line = lv_line_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Hood_Line, -1, 6);
	lv_obj_set_size(ui->ui_Home_ui_Hood_Line, 62, 156);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Hood_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_hood_line_main_main_default
	static lv_style_t style_ui_home_ui_hood_line_main_main_default;
	if (style_ui_home_ui_hood_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_hood_line_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_hood_line_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_hood_line_main_main_default, lv_color_make(0xAC, 0xFF, 0x62));
	lv_style_set_line_width(&style_ui_home_ui_hood_line_main_main_default, 14);
	lv_style_set_line_rounded(&style_ui_home_ui_hood_line_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Hood_Line, &style_ui_home_ui_hood_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Hood_Line[] ={{0, 0},{0, 148},};
	lv_line_set_points(ui->ui_Home_ui_Hood_Line,ui_Home_ui_Hood_Line,2);

	//Write codes ui_Home_ui_Line_2
	ui->ui_Home_ui_Line_2 = lv_line_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Line_2, 50, 80);
	lv_obj_set_size(ui->ui_Home_ui_Line_2, 60, 5);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_2_main_main_default
	static lv_style_t style_ui_home_ui_line_2_main_main_default;
	if (style_ui_home_ui_line_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_2_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_2_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_2_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_2_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_home_ui_line_2_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_2, &style_ui_home_ui_line_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_2[] ={{0, 0},{60, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_2,ui_Home_ui_Line_2,2);

	//Write codes ui_Home_ui_Line_3
	ui->ui_Home_ui_Line_3 = lv_line_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Line_3, 247, 80);
	lv_obj_set_size(ui->ui_Home_ui_Line_3, 60, 5);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_3_main_main_default
	static lv_style_t style_ui_home_ui_line_3_main_main_default;
	if (style_ui_home_ui_line_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_3_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_3_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_3_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_3_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_home_ui_line_3_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_3, &style_ui_home_ui_line_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_3[] ={{0, 0},{60, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_3,ui_Home_ui_Line_3,2);

	//Write codes ui_Home_ui_Label_Fan
	ui->ui_Home_ui_Label_Fan = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Fan, 225, 9);
	lv_obj_set_size(ui->ui_Home_ui_Label_Fan, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Fan, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Fan, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_fan_main_main_default
	static lv_style_t style_ui_home_ui_label_fan_main_main_default;
	if (style_ui_home_ui_label_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_fan_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_fan_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_fan_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_fan_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_fan_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_fan_main_main_default, lv_color_make(0xAC, 0xFF, 0x62));
	lv_style_set_text_font(&style_ui_home_ui_label_fan_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_fan_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_fan_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_fan_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_fan_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Fan, &style_ui_home_ui_label_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Light
	ui->ui_Home_ui_Label_Light = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Light, 30, 9);
	lv_obj_set_size(ui->ui_Home_ui_Label_Light, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Light, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Light, "LIGHT");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Light, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_light_main_main_default
	static lv_style_t style_ui_home_ui_label_light_main_main_default;
	if (style_ui_home_ui_label_light_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_light_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_light_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_light_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_light_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_light_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_light_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_light_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_light_main_main_default, lv_color_make(0xAC, 0xFF, 0x62));
	lv_style_set_text_font(&style_ui_home_ui_label_light_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_light_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_light_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_light_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_light_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Light, &style_ui_home_ui_label_light_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Light
	ui->ui_Home_ui_Image_Hood_Light = lv_img_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Light, 61, 103);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Light, 39, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Light, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_hood_light_main_main_default
	static lv_style_t style_ui_home_ui_image_hood_light_main_main_default;
	if (style_ui_home_ui_image_hood_light_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_hood_light_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_hood_light_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_hood_light_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_hood_light_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_hood_light_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Hood_Light, &style_ui_home_ui_image_hood_light_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Light,&_icn_light_on_39x31);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Light, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Light, 0);

	//Write codes ui_Home_ui_Image_Hood_Fan
	ui->ui_Home_ui_Image_Hood_Fan = lv_img_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Fan, 261, 103);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Fan, 31, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_hood_fan_main_main_default
	static lv_style_t style_ui_home_ui_image_hood_fan_main_main_default;
	if (style_ui_home_ui_image_hood_fan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_hood_fan_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_hood_fan_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_hood_fan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_hood_fan_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_hood_fan_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Hood_Fan, &style_ui_home_ui_image_hood_fan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Fan,&_icn_fan_low_31x27);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Fan, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Fan, 0);

	//Write codes ui_Home_ui_Label_Hood_Light_Text
	ui->ui_Home_ui_Label_Hood_Light_Text = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Hood_Light_Text, 51, 41);
	lv_obj_set_size(ui->ui_Home_ui_Label_Hood_Light_Text, 58, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Hood_Light_Text, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Hood_Light_Text, "Off");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Hood_Light_Text, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_hood_light_text_main_main_default
	static lv_style_t style_ui_home_ui_label_hood_light_text_main_main_default;
	if (style_ui_home_ui_label_hood_light_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_hood_light_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_hood_light_text_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_hood_light_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_hood_light_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_hood_light_text_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_hood_light_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_hood_light_text_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_hood_light_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_hood_light_text_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_hood_light_text_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_hood_light_text_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_hood_light_text_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_hood_light_text_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Hood_Light_Text, &style_ui_home_ui_label_hood_light_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Hood_Fan_Text
	ui->ui_Home_ui_Label_Hood_Fan_Text = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Hood_Fan_Text, 249, 41);
	lv_obj_set_size(ui->ui_Home_ui_Label_Hood_Fan_Text, 51, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Hood_Fan_Text, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Hood_Fan_Text, "Low");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Hood_Fan_Text, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_hood_fan_text_main_main_default
	static lv_style_t style_ui_home_ui_label_hood_fan_text_main_main_default;
	if (style_ui_home_ui_label_hood_fan_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_hood_fan_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_hood_fan_text_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_hood_fan_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_hood_fan_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_hood_fan_text_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_hood_fan_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_hood_fan_text_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_hood_fan_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_hood_fan_text_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_hood_fan_text_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_hood_fan_text_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_hood_fan_text_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_hood_fan_text_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Hood_Fan_Text, &style_ui_home_ui_label_hood_fan_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Info
	ui->ui_Home_ui_Group_Info = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Info, 912, 0);
	lv_obj_set_size(ui->ui_Home_ui_Group_Info, 300, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Info, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_group_info_main_main_default
	static lv_style_t style_ui_home_ui_group_info_main_main_default;
	if (style_ui_home_ui_group_info_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_group_info_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_group_info_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_group_info_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_bg_grad_color(&style_ui_home_ui_group_info_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_group_info_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_group_info_main_main_default, 255);
	lv_style_set_shadow_width(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_group_info_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_group_info_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_group_info_main_main_default, lv_color_make(0x18, 0x18, 0x18));
	lv_style_set_border_width(&style_ui_home_ui_group_info_main_main_default, 2);
	lv_style_set_border_opa(&style_ui_home_ui_group_info_main_main_default, 255);
	lv_style_set_pad_left(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_style_set_pad_bottom(&style_ui_home_ui_group_info_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Group_Info, &style_ui_home_ui_group_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Weather_Icon
	ui->ui_Home_ui_Image_Weather_Icon = lv_img_create(ui->ui_Home_ui_Group_Info);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Weather_Icon, 22, 243);
	lv_obj_set_size(ui->ui_Home_ui_Image_Weather_Icon, 56, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Weather_Icon, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_weather_icon_main_main_default
	static lv_style_t style_ui_home_ui_image_weather_icon_main_main_default;
	if (style_ui_home_ui_image_weather_icon_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_weather_icon_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_weather_icon_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_weather_icon_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_weather_icon_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_weather_icon_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Weather_Icon, &style_ui_home_ui_image_weather_icon_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Weather_Icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Weather_Icon,&_icn_weather_1_56x52);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Weather_Icon, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Weather_Icon, 0);

	//Write codes ui_Home_ui_Line_7
	ui->ui_Home_ui_Line_7 = lv_line_create(ui->ui_Home_ui_Group_Info);
	lv_obj_set_pos(ui->ui_Home_ui_Line_7, 22, 214);
	lv_obj_set_size(ui->ui_Home_ui_Line_7, 263, 1);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_7_main_main_default
	static lv_style_t style_ui_home_ui_line_7_main_main_default;
	if (style_ui_home_ui_line_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_7_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_7_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_7_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_7_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_home_ui_line_7_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_7, &style_ui_home_ui_line_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_7[] ={{0, 0},{255, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_7,ui_Home_ui_Line_7,2);

	//Write codes ui_Home_ui_Line_8
	ui->ui_Home_ui_Line_8 = lv_line_create(ui->ui_Home_ui_Group_Info);
	lv_obj_set_pos(ui->ui_Home_ui_Line_8, 22, 381);
	lv_obj_set_size(ui->ui_Home_ui_Line_8, 263, 1);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_line_8_main_main_default
	static lv_style_t style_ui_home_ui_line_8_main_main_default;
	if (style_ui_home_ui_line_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_line_8_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_line_8_main_main_default);
	lv_style_set_line_color(&style_ui_home_ui_line_8_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_ui_home_ui_line_8_main_main_default, 3);
	lv_style_set_line_rounded(&style_ui_home_ui_line_8_main_main_default, true);
	lv_obj_add_style(ui->ui_Home_ui_Line_8, &style_ui_home_ui_line_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t ui_Home_ui_Line_8[] ={{0, 0},{255, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_8,ui_Home_ui_Line_8,2);

	//Write codes ui_Home_ui_Label_Mic_Text
	ui->ui_Home_ui_Label_Mic_Text = lv_label_create(ui->ui_Home_ui_Group_Info);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Mic_Text, 78, 606);
	lv_obj_set_size(ui->ui_Home_ui_Label_Mic_Text, 155, 101);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Mic_Text, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->ui_Home_ui_Label_Mic_Text, "\"Hey Oven\"\n\n\"Hey Hood\"\n\n\"Hey Aircon\"\n");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Mic_Text, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_label_mic_text_main_main_default
	static lv_style_t style_ui_home_ui_label_mic_text_main_main_default;
	if (style_ui_home_ui_label_mic_text_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_label_mic_text_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_label_mic_text_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_bg_color(&style_ui_home_ui_label_mic_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_label_mic_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_label_mic_text_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_label_mic_text_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_label_mic_text_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_text_color(&style_ui_home_ui_label_mic_text_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ui_home_ui_label_mic_text_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_ui_home_ui_label_mic_text_main_main_default, 2);
	lv_style_set_text_line_space(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_text_align(&style_ui_home_ui_label_mic_text_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_pad_right(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_style_set_pad_top(&style_ui_home_ui_label_mic_text_main_main_default, 8);
	lv_style_set_pad_bottom(&style_ui_home_ui_label_mic_text_main_main_default, 0);
	lv_obj_add_style(ui->ui_Home_ui_Label_Mic_Text, &style_ui_home_ui_label_mic_text_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Menu
	ui->ui_Home_ui_Image_Hood_Menu = lv_img_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Menu, 479, 12);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Menu, 299, 199);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Menu, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_hood_menu_main_main_default
	static lv_style_t style_ui_home_ui_image_hood_menu_main_main_default;
	if (style_ui_home_ui_image_hood_menu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_hood_menu_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_hood_menu_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_hood_menu_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_hood_menu_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_hood_menu_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Hood_Menu, &style_ui_home_ui_image_hood_menu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Menu,&_hood_small_299x199);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Menu, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Menu, 0);

	//Write codes ui_Home_ui_Btn_Hood
	ui->ui_Home_ui_Btn_Hood = lv_btn_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Btn_Hood, 457, 23);
	lv_obj_set_size(ui->ui_Home_ui_Btn_Hood, 312, 158);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Btn_Hood, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_btn_hood_main_main_default
	static lv_style_t style_ui_home_ui_btn_hood_main_main_default;
	if (style_ui_home_ui_btn_hood_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_btn_hood_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_btn_hood_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_btn_hood_main_main_default, 5);
	lv_style_set_bg_color(&style_ui_home_ui_btn_hood_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_btn_hood_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_btn_hood_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_btn_hood_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_btn_hood_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_btn_hood_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_btn_hood_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_btn_hood_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_btn_hood_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_btn_hood_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_btn_hood_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_home_ui_btn_hood_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_home_ui_btn_hood_main_main_default, 255);
	lv_style_set_text_color(&style_ui_home_ui_btn_hood_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_home_ui_btn_hood_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Home_ui_Btn_Hood, &style_ui_home_ui_btn_hood_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->ui_Home_ui_Btn_Hood_label = lv_label_create(ui->ui_Home_ui_Btn_Hood);
	lv_label_set_text(ui->ui_Home_ui_Btn_Hood_label, "");
	lv_obj_set_style_pad_all(ui->ui_Home_ui_Btn_Hood, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Home_ui_Btn_Hood_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Home_ui_Image_Aircon_Menu
	ui->ui_Home_ui_Image_Aircon_Menu = lv_img_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Menu, 60, 42);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Menu, 318, 125);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Menu, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_aircon_menu_main_main_default
	static lv_style_t style_ui_home_ui_image_aircon_menu_main_main_default;
	if (style_ui_home_ui_image_aircon_menu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_aircon_menu_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_aircon_menu_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_aircon_menu_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_aircon_menu_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_aircon_menu_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Aircon_Menu, &style_ui_home_ui_image_aircon_menu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Menu,&_aircon_small_318x125);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Menu, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Menu, 0);

	//Write codes ui_Home_ui_Image_Oven_Menu
	ui->ui_Home_ui_Image_Oven_Menu = lv_img_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Oven_Menu, 506, 418);
	lv_obj_set_size(ui->ui_Home_ui_Image_Oven_Menu, 257, 269);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Oven_Menu, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_image_oven_menu_main_main_default
	static lv_style_t style_ui_home_ui_image_oven_menu_main_main_default;
	if (style_ui_home_ui_image_oven_menu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_image_oven_menu_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_image_oven_menu_main_main_default);
	lv_style_set_img_recolor(&style_ui_home_ui_image_oven_menu_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_ui_home_ui_image_oven_menu_main_main_default, 0);
	lv_style_set_img_opa(&style_ui_home_ui_image_oven_menu_main_main_default, 255);
	lv_obj_add_style(ui->ui_Home_ui_Image_Oven_Menu, &style_ui_home_ui_image_oven_menu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Oven_Menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Oven_Menu,&_oven_light_menu_257x269);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Oven_Menu, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Oven_Menu, 0);

	//Write codes ui_Home_ui_Btn_Aircon
	ui->ui_Home_ui_Btn_Aircon = lv_btn_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Btn_Aircon, 35, 41);
	lv_obj_set_size(ui->ui_Home_ui_Btn_Aircon, 363, 240);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Btn_Aircon, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_btn_aircon_main_main_default
	static lv_style_t style_ui_home_ui_btn_aircon_main_main_default;
	if (style_ui_home_ui_btn_aircon_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_btn_aircon_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_btn_aircon_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_btn_aircon_main_main_default, 5);
	lv_style_set_bg_color(&style_ui_home_ui_btn_aircon_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_btn_aircon_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_btn_aircon_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_btn_aircon_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_btn_aircon_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_btn_aircon_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_btn_aircon_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_btn_aircon_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_btn_aircon_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_btn_aircon_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_btn_aircon_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_home_ui_btn_aircon_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_home_ui_btn_aircon_main_main_default, 255);
	lv_style_set_text_color(&style_ui_home_ui_btn_aircon_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_home_ui_btn_aircon_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Home_ui_Btn_Aircon, &style_ui_home_ui_btn_aircon_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->ui_Home_ui_Btn_Aircon_label = lv_label_create(ui->ui_Home_ui_Btn_Aircon);
	lv_label_set_text(ui->ui_Home_ui_Btn_Aircon_label, "");
	lv_obj_set_style_pad_all(ui->ui_Home_ui_Btn_Aircon, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Home_ui_Btn_Aircon_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes ui_Home_ui_Btn_Oven
	ui->ui_Home_ui_Btn_Oven = lv_btn_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Btn_Oven, 493, 405);
	lv_obj_set_size(ui->ui_Home_ui_Btn_Oven, 287, 295);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Btn_Oven, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_ui_home_ui_btn_oven_main_main_default
	static lv_style_t style_ui_home_ui_btn_oven_main_main_default;
	if (style_ui_home_ui_btn_oven_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_ui_home_ui_btn_oven_main_main_default);
	else
		lv_style_init(&style_ui_home_ui_btn_oven_main_main_default);
	lv_style_set_radius(&style_ui_home_ui_btn_oven_main_main_default, 5);
	lv_style_set_bg_color(&style_ui_home_ui_btn_oven_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_ui_home_ui_btn_oven_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_ui_home_ui_btn_oven_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_ui_home_ui_btn_oven_main_main_default, 0);
	lv_style_set_shadow_width(&style_ui_home_ui_btn_oven_main_main_default, 0);
	lv_style_set_shadow_color(&style_ui_home_ui_btn_oven_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_ui_home_ui_btn_oven_main_main_default, 255);
	lv_style_set_shadow_spread(&style_ui_home_ui_btn_oven_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_ui_home_ui_btn_oven_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_ui_home_ui_btn_oven_main_main_default, 0);
	lv_style_set_border_color(&style_ui_home_ui_btn_oven_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_ui_home_ui_btn_oven_main_main_default, 0);
	lv_style_set_border_opa(&style_ui_home_ui_btn_oven_main_main_default, 255);
	lv_style_set_text_color(&style_ui_home_ui_btn_oven_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_ui_home_ui_btn_oven_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->ui_Home_ui_Btn_Oven, &style_ui_home_ui_btn_oven_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->ui_Home_ui_Btn_Oven_label = lv_label_create(ui->ui_Home_ui_Btn_Oven);
	lv_label_set_text(ui->ui_Home_ui_Btn_Oven_label, "");
	lv_obj_set_style_pad_all(ui->ui_Home_ui_Btn_Oven, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->ui_Home_ui_Btn_Oven_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_ui_Home(ui);
}