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


void setup_scr_ui_Home(lv_ui *ui)
{
	//Write codes ui_Home
	ui->ui_Home = lv_obj_create(NULL);
	lv_obj_set_size(ui->ui_Home, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Home, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Menu_Bg
	ui->ui_Home_ui_Image_Menu_Bg = lv_img_create(ui->ui_Home);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Menu_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Menu_Bg, &_menu_bg_alpha_1280x720);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Menu_Bg, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Menu_Bg, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Menu_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Home_ui_Image_Menu_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Menu_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Menu_Bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Menu_Bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Nxp_Logo
	ui->ui_Home_ui_Group_Nxp_Logo = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Nxp_Logo, 15, 325);
	lv_obj_set_size(ui->ui_Home_ui_Group_Nxp_Logo, 388, 50);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Nxp_Logo, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Group_Nxp_Logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Group_Nxp_Logo, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Home_ui_Group_Nxp_Logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Home_ui_Group_Nxp_Logo, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Group_Nxp_Logo, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Group_Nxp_Logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Home_ui_Group_Nxp_Logo, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Group_Nxp_Logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Group_Nxp_Logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Group_Nxp_Logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Group_Nxp_Logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Group_Nxp_Logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Nxp_Logo
	ui->ui_Home_ui_Image_Nxp_Logo = lv_img_create(ui->ui_Home_ui_Group_Nxp_Logo);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Nxp_Logo, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Nxp_Logo, &_nxp_alpha_75x27);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Nxp_Logo, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Nxp_Logo, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Nxp_Logo, 22, 10);
	lv_obj_set_size(ui->ui_Home_ui_Image_Nxp_Logo, 75, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Nxp_Logo, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Nxp_Logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Nxp_Logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Smart_Kitchen_Demo
	ui->ui_Home_ui_Label_Smart_Kitchen_Demo = lv_label_create(ui->ui_Home_ui_Group_Nxp_Logo);
	lv_label_set_text(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, "Smart Kitchen Demo");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 130, 7);
	lv_obj_set_size(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 240, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Smart_Kitchen_Demo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Smart_Kitchen_Demo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Aircon_Content
	ui->ui_Home_ui_Group_Aircon_Content = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Aircon_Content, 16, 29);
	lv_obj_set_size(ui->ui_Home_ui_Group_Aircon_Content, 389, 272);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Aircon_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Group_Aircon_Content, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Group_Aircon_Content, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Home_ui_Group_Aircon_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Home_ui_Group_Aircon_Content, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Group_Aircon_Content, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Group_Aircon_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Home_ui_Group_Aircon_Content, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Group_Aircon_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Group_Aircon_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Group_Aircon_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Group_Aircon_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Group_Aircon_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Aircon_Text
	ui->ui_Home_ui_Image_Aircon_Text = lv_img_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Text, &_text_aircon_alpha_15x88);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Text, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Text, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Text, 23, 159);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Text, 15, 88);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Aircon_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Aircon_Text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Aircon_Line
	ui->ui_Home_ui_Aircon_Line = lv_line_create(ui->ui_Home_ui_Group_Aircon_Content);
	static lv_point_t ui_Home_ui_Aircon_Line[] ={{0, 0},{0, 252},};
	lv_line_set_points(ui->ui_Home_ui_Aircon_Line, ui_Home_ui_Aircon_Line, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Aircon_Line, 2, 8);
	lv_obj_set_size(ui->ui_Home_ui_Aircon_Line, 21, 259);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Aircon_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Aircon_Line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Aircon_Line, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Aircon_Line, lv_color_hex(0x52DAFf), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Aircon_Line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Aircon_Line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_1
	ui->ui_Home_ui_Line_1 = lv_line_create(ui->ui_Home_ui_Group_Aircon_Content);
	static lv_point_t ui_Home_ui_Line_1[] ={{0, 0},{0, 100},};
	lv_line_set_points(ui->ui_Home_ui_Line_1, ui_Home_ui_Line_1, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_1, 223, 152);
	lv_obj_set_size(ui->ui_Home_ui_Line_1, 3, 108);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Mode
	ui->ui_Home_ui_Label_Aircon_Mode = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Mode, "MODE");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Mode, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Mode, 262, 143);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Mode, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Aircon_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Aircon_Mode, lv_color_hex(0x52DAFf), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Aircon_Mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Aircon_Mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Aircon_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Aircon_Mode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Aircon_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Fan
	ui->ui_Home_ui_Label_Aircon_Fan = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Fan, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Fan, 262, 202);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Fan, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Aircon_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Aircon_Fan, lv_color_hex(0x52DAFf), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Aircon_Fan, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Aircon_Fan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Aircon_Fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Aircon_Fan, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Aircon_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Mode_Text
	ui->ui_Home_ui_Label_Aircon_Mode_Text = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Mode_Text, "Dry");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Mode_Text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Mode_Text, 281, 168);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Mode_Text, 60, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Mode_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Aircon_Mode_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Aircon_Mode_Text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Aircon_Mode_Text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Aircon_Mode_Text, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Aircon_Mode_Text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Aircon_Mode_Text, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Aircon_Mode_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Fan_Text
	ui->ui_Home_ui_Label_Aircon_Fan_Text = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Fan_Text, "Low");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Fan_Text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Fan_Text, 268, 226);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Fan_Text, 89, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Fan_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Aircon_Fan_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Aircon_Fan_Text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Aircon_Fan_Text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Aircon_Fan_Text, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Aircon_Fan_Text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Aircon_Fan_Text, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Aircon_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Aircon_Mode
	ui->ui_Home_ui_Image_Aircon_Mode = lv_img_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Mode, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Mode, &_icn_cool_alpha_27x31);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Mode, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Mode, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Mode, 241, 157);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Mode, 27, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Aircon_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Aircon_Mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Aircon_Fan
	ui->ui_Home_ui_Image_Aircon_Fan = lv_img_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Fan, &_icn_fan_low_alpha_31x27);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Fan, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Fan, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Fan, 241, 218);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Fan, 31, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Aircon_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Aircon_Fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_Number1
	ui->ui_Home_ui_Label_Aircon_Number1 = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_Number1, "25");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_Number1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_Number1, 75, 155);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_Number1, 120, 89);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_Number1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Aircon_Number1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Aircon_Number1, lv_color_hex(0x52DAFf), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Aircon_Number1, &lv_font_Antonio_Regular_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Aircon_Number1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Aircon_Number1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Aircon_Number1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Aircon_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Aircon_centigrade
	ui->ui_Home_ui_Label_Aircon_centigrade = lv_label_create(ui->ui_Home_ui_Group_Aircon_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Aircon_centigrade, "°C");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Aircon_centigrade, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Aircon_centigrade, 156, 165);
	lv_obj_set_size(ui->ui_Home_ui_Label_Aircon_centigrade, 64, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Aircon_centigrade, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Aircon_centigrade, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Aircon_centigrade, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Aircon_centigrade, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Aircon_centigrade, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Aircon_centigrade, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Aircon_centigrade, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Aircon_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Light_Menu
	ui->ui_Home_ui_Image_Hood_Light_Menu = lv_img_create(ui->ui_Home);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Light_Menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Light_Menu, &_hood_menu_light_alpha_439x217);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Light_Menu, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Light_Menu, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Light_Menu, 424, 191);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Light_Menu, 439, 217);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Light_Menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Hood_Light_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Hood_Light_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Oven_Content
	ui->ui_Home_ui_Group_Oven_Content = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Oven_Content, 16, 399);
	lv_obj_set_size(ui->ui_Home_ui_Group_Oven_Content, 767, 305);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Oven_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Group_Oven_Content, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Group_Oven_Content, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Home_ui_Group_Oven_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Home_ui_Group_Oven_Content, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Group_Oven_Content, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Group_Oven_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Home_ui_Group_Oven_Content, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Group_Oven_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Group_Oven_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Group_Oven_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Group_Oven_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Group_Oven_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Oven_Text
	ui->ui_Home_ui_Image_Oven_Text = lv_img_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Oven_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Oven_Text, &_text_oven_alpha_15x62);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Oven_Text, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Oven_Text, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Oven_Text, 23, 113);
	lv_obj_set_size(ui->ui_Home_ui_Image_Oven_Text, 15, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Oven_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Oven_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Oven_Text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Oven_Line
	ui->ui_Home_ui_Oven_Line = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	static lv_point_t ui_Home_ui_Oven_Line[] ={{0, 0},{0, 285},};
	lv_line_set_points(ui->ui_Home_ui_Oven_Line, ui_Home_ui_Oven_Line, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Oven_Line, 3, 8);
	lv_obj_set_size(ui->ui_Home_ui_Oven_Line, 60, 291);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Oven_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Oven_Line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Oven_Line, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Oven_Line, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Oven_Line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Oven_Line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_4
	ui->ui_Home_ui_Line_4 = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	static lv_point_t ui_Home_ui_Line_4[] ={{0, 0},{198, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_4, ui_Home_ui_Line_4, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_4, 62, 140);
	lv_obj_set_size(ui->ui_Home_ui_Line_4, 198, 1);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_4, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_4, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_4, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_5
	ui->ui_Home_ui_Line_5 = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	static lv_point_t ui_Home_ui_Line_5[] ={{0, 0},{0, 275},};
	lv_line_set_points(ui->ui_Home_ui_Line_5, ui_Home_ui_Line_5, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_5, 283, 15);
	lv_obj_set_size(ui->ui_Home_ui_Line_5, 2, 282);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_5, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_5, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_5, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_6
	ui->ui_Home_ui_Line_6 = lv_line_create(ui->ui_Home_ui_Group_Oven_Content);
	static lv_point_t ui_Home_ui_Line_6[] ={{0, 0},{150, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_6, ui_Home_ui_Line_6, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_6, 308, 95);
	lv_obj_set_size(ui->ui_Home_ui_Line_6, 157, 2);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_6, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_6, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Time_Left
	ui->ui_Home_ui_Label_Time_Left = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Time_Left, "TIME\nLEFT");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Time_Left, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Time_Left, 64, 180);
	lv_obj_set_size(ui->ui_Home_ui_Label_Time_Left, 68, 44);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Time_Left, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Time_Left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Time_Left, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Time_Left, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Time_Left, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Time_Left, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Time_Left, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Time_Left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Status
	ui->ui_Home_ui_Label_Status = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Status, "STATUS");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Status, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Status, 333, 12);
	lv_obj_set_size(ui->ui_Home_ui_Label_Status, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Status, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Status, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Status, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Status, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Status, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Oven_Mode
	ui->ui_Home_ui_Label_Oven_Mode = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Oven_Mode, "MODE");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Oven_Mode, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Oven_Mode, 333, 106);
	lv_obj_set_size(ui->ui_Home_ui_Label_Oven_Mode, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Oven_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Oven_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Oven_Mode, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Oven_Mode, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Oven_Mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Oven_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Oven_Mode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Oven_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Mystat
	ui->ui_Home_ui_Label_Mystat = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Mystat, "My stat");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Mystat, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Mystat, 333, 39);
	lv_obj_set_size(ui->ui_Home_ui_Label_Mystat, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Mystat, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Mystat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Mystat, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Mystat, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Mystat, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Mystat, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Mystat, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Mystat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Mode1
	ui->ui_Home_ui_Label_Mode1 = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Mode1, "Fan Forced\nLower Element\nConvection");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Mode1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Mode1, 328, 133);
	lv_obj_set_size(ui->ui_Home_ui_Label_Mode1, 114, 96);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Mode1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Mode1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Mode1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Mode1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Mode1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Mode1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Mode1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Oven_Mode
	ui->ui_Home_ui_Image_Oven_Mode = lv_img_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Oven_Mode, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Oven_Mode, &_icn_oven_fan_upper_lower_alpha_62x62);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Oven_Mode, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Oven_Mode, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Oven_Mode, 354, 228);
	lv_obj_set_size(ui->ui_Home_ui_Image_Oven_Mode, 62, 62);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Oven_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Oven_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Oven_Mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Oven_Number1
	ui->ui_Home_ui_Label_Oven_Number1 = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Oven_Number1, "250");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Oven_Number1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Oven_Number1, 73, 33);
	lv_obj_set_size(ui->ui_Home_ui_Label_Oven_Number1, 173, 92);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Oven_Number1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Oven_Number1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Oven_Number1, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Oven_Number1, &lv_font_Antonio_Regular_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Oven_Number1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Oven_Number1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Oven_Number1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Oven_Number1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Oven_TimeLeft
	ui->ui_Home_ui_Label_Oven_TimeLeft = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Oven_TimeLeft, "25");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Oven_TimeLeft, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Oven_TimeLeft, 146, 173);
	lv_obj_set_size(ui->ui_Home_ui_Label_Oven_TimeLeft, 65, 61);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Oven_TimeLeft, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Oven_TimeLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Oven_TimeLeft, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Oven_TimeLeft, &lv_font_Antonio_Regular_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Oven_TimeLeft, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Oven_TimeLeft, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Oven_TimeLeft, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Oven_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Oven_Mins
	ui->ui_Home_ui_Label_Oven_Mins = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Oven_Mins, "mins");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Oven_Mins, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Oven_Mins, 186, 196);
	lv_obj_set_size(ui->ui_Home_ui_Label_Oven_Mins, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Oven_Mins, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Oven_Mins, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Oven_Mins, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Oven_Mins, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Oven_Mins, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Oven_Mins, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Oven_Mins, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Oven_Mins, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Oven_centigrade
	ui->ui_Home_ui_Label_Oven_centigrade = lv_label_create(ui->ui_Home_ui_Group_Oven_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Oven_centigrade, "°C");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Oven_centigrade, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Oven_centigrade, 201, 42);
	lv_obj_set_size(ui->ui_Home_ui_Label_Oven_centigrade, 64, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Oven_centigrade, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Oven_centigrade, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Oven_centigrade, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Oven_centigrade, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Oven_centigrade, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Oven_centigrade, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Oven_centigrade, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Oven_centigrade, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Hood_Content
	ui->ui_Home_ui_Group_Hood_Content = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Hood_Content, 449, 20);
	lv_obj_set_size(ui->ui_Home_ui_Group_Hood_Content, 328, 167);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Hood_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Group_Hood_Content, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Group_Hood_Content, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Home_ui_Group_Hood_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Home_ui_Group_Hood_Content, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Group_Hood_Content, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Group_Hood_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Home_ui_Group_Hood_Content, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Text
	ui->ui_Home_ui_Image_Hood_Text = lv_img_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Text, &_text_hood_alpha_15x68);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Text, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Text, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Text, 20, 45);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Text, 15, 68);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Hood_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Hood_Text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Hood_Line
	ui->ui_Home_ui_Hood_Line = lv_line_create(ui->ui_Home_ui_Group_Hood_Content);
	static lv_point_t ui_Home_ui_Hood_Line[] ={{0, 0},{0, 148},};
	lv_line_set_points(ui->ui_Home_ui_Hood_Line, ui_Home_ui_Hood_Line, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Hood_Line, -1, 6);
	lv_obj_set_size(ui->ui_Home_ui_Hood_Line, 62, 156);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Hood_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Hood_Line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Hood_Line, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Hood_Line, lv_color_hex(0xACFF62), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Hood_Line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Hood_Line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_2
	ui->ui_Home_ui_Line_2 = lv_line_create(ui->ui_Home_ui_Group_Hood_Content);
	static lv_point_t ui_Home_ui_Line_2[] ={{0, 0},{60, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_2, ui_Home_ui_Line_2, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_2, 50, 80);
	lv_obj_set_size(ui->ui_Home_ui_Line_2, 60, 5);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_2, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_3
	ui->ui_Home_ui_Line_3 = lv_line_create(ui->ui_Home_ui_Group_Hood_Content);
	static lv_point_t ui_Home_ui_Line_3[] ={{0, 0},{60, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_3, ui_Home_ui_Line_3, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_3, 247, 80);
	lv_obj_set_size(ui->ui_Home_ui_Line_3, 60, 5);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_3, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_3, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_3, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Fan
	ui->ui_Home_ui_Label_Fan = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Fan, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Fan, 225, 9);
	lv_obj_set_size(ui->ui_Home_ui_Label_Fan, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Fan, lv_color_hex(0xACFF62), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Fan, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Fan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Fan, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Light
	ui->ui_Home_ui_Label_Light = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Light, "LIGHT");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Light, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Light, 30, 9);
	lv_obj_set_size(ui->ui_Home_ui_Label_Light, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Light, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Light, lv_color_hex(0xACFF62), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Light, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Light, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Light, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Light
	ui->ui_Home_ui_Image_Hood_Light = lv_img_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Light, &_icn_light_on_alpha_39x31);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Light, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Light, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Light, 61, 103);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Light, 39, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Light, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Hood_Light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Hood_Light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Fan
	ui->ui_Home_ui_Image_Hood_Fan = lv_img_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Fan, &_icn_fan_low_alpha_31x27);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Fan, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Fan, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Fan, 261, 103);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Fan, 31, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Hood_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Hood_Fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Hood_Light_Text
	ui->ui_Home_ui_Label_Hood_Light_Text = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Hood_Light_Text, "Off");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Hood_Light_Text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Hood_Light_Text, 51, 41);
	lv_obj_set_size(ui->ui_Home_ui_Label_Hood_Light_Text, 58, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Hood_Light_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Hood_Light_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Hood_Light_Text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Hood_Light_Text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Hood_Light_Text, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Hood_Light_Text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Hood_Light_Text, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Hood_Light_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Hood_Fan_Text
	ui->ui_Home_ui_Label_Hood_Fan_Text = lv_label_create(ui->ui_Home_ui_Group_Hood_Content);
	lv_label_set_text(ui->ui_Home_ui_Label_Hood_Fan_Text, "Low");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Hood_Fan_Text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Hood_Fan_Text, 249, 41);
	lv_obj_set_size(ui->ui_Home_ui_Label_Hood_Fan_Text, 51, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Hood_Fan_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Hood_Fan_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Hood_Fan_Text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Hood_Fan_Text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Hood_Fan_Text, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Hood_Fan_Text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Hood_Fan_Text, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Hood_Fan_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Info
	ui->ui_Home_ui_Group_Info = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Info, 912, 0);
	lv_obj_set_size(ui->ui_Home_ui_Group_Info, 300, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Info, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Group_Info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Group_Info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Home_ui_Group_Info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Home_ui_Group_Info, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Group_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Group_Info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Home_ui_Group_Info, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Group_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Group_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Group_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Group_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Group_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Weather_Icon
	ui->ui_Home_ui_Image_Weather_Icon = lv_img_create(ui->ui_Home_ui_Group_Info);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Weather_Icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Weather_Icon, &_icn_weather_1_alpha_56x52);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Weather_Icon, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Weather_Icon, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Weather_Icon, 22, 243);
	lv_obj_set_size(ui->ui_Home_ui_Image_Weather_Icon, 56, 52);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Weather_Icon, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Weather_Icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Weather_Icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_7
	ui->ui_Home_ui_Line_7 = lv_line_create(ui->ui_Home_ui_Group_Info);
	static lv_point_t ui_Home_ui_Line_7[] ={{0, 0},{255, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_7, ui_Home_ui_Line_7, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_7, 22, 214);
	lv_obj_set_size(ui->ui_Home_ui_Line_7, 263, 1);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_7, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_7, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_7, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Line_8
	ui->ui_Home_ui_Line_8 = lv_line_create(ui->ui_Home_ui_Group_Info);
	static lv_point_t ui_Home_ui_Line_8[] ={{0, 0},{255, 0},};
	lv_line_set_points(ui->ui_Home_ui_Line_8, ui_Home_ui_Line_8, 2);
	lv_obj_set_pos(ui->ui_Home_ui_Line_8, 22, 381);
	lv_obj_set_size(ui->ui_Home_ui_Line_8, 263, 1);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Line_8, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Line_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Home_ui_Line_8, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Home_ui_Line_8, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Home_ui_Line_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Home_ui_Line_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Label_Mic_Text
	ui->ui_Home_ui_Label_Mic_Text = lv_label_create(ui->ui_Home_ui_Group_Info);
	lv_label_set_text(ui->ui_Home_ui_Label_Mic_Text, "\"Hey Oven\"\n\n\"Hey Hood\"\n\n\"Hey Aircon\"\n");
	lv_label_set_long_mode(ui->ui_Home_ui_Label_Mic_Text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Home_ui_Label_Mic_Text, 78, 606);
	lv_obj_set_size(ui->ui_Home_ui_Label_Mic_Text, 155, 101);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Label_Mic_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Label_Mic_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Label_Mic_Text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Label_Mic_Text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Home_ui_Label_Mic_Text, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Label_Mic_Text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Label_Mic_Text, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Label_Mic_Text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Hood_Menu
	ui->ui_Home_ui_Image_Hood_Menu = lv_img_create(ui->ui_Home);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Hood_Menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Hood_Menu, &_hood_small_alpha_299x199);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Hood_Menu, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Hood_Menu, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Hood_Menu, 479, 12);
	lv_obj_set_size(ui->ui_Home_ui_Image_Hood_Menu, 299, 199);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Hood_Menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Hood_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Hood_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Btn_Hood
	ui->ui_Home_ui_Btn_Hood = lv_btn_create(ui->ui_Home);
	ui->ui_Home_ui_Btn_Hood_label = lv_label_create(ui->ui_Home_ui_Btn_Hood);
	lv_label_set_text(ui->ui_Home_ui_Btn_Hood_label, "");
	lv_label_set_long_mode(ui->ui_Home_ui_Btn_Hood_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Home_ui_Btn_Hood_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Home_ui_Btn_Hood, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Home_ui_Btn_Hood, 457, 23);
	lv_obj_set_size(ui->ui_Home_ui_Btn_Hood, 312, 158);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Btn_Hood, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Btn_Hood, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Btn_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Home_ui_Btn_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Btn_Hood, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Btn_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Btn_Hood, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Btn_Hood, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Btn_Hood, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Aircon_Menu
	ui->ui_Home_ui_Image_Aircon_Menu = lv_img_create(ui->ui_Home);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Aircon_Menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Aircon_Menu, &_aircon_small_alpha_318x125);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Aircon_Menu, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Aircon_Menu, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Aircon_Menu, 60, 42);
	lv_obj_set_size(ui->ui_Home_ui_Image_Aircon_Menu, 318, 125);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Aircon_Menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Aircon_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Aircon_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Oven_Menu
	ui->ui_Home_ui_Image_Oven_Menu = lv_img_create(ui->ui_Home);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Oven_Menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Oven_Menu, &_oven_light_menu_alpha_257x269);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Oven_Menu, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Oven_Menu, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Oven_Menu, 506, 418);
	lv_obj_set_size(ui->ui_Home_ui_Image_Oven_Menu, 257, 269);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Oven_Menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Oven_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Oven_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Btn_Aircon
	ui->ui_Home_ui_Btn_Aircon = lv_btn_create(ui->ui_Home);
	ui->ui_Home_ui_Btn_Aircon_label = lv_label_create(ui->ui_Home_ui_Btn_Aircon);
	lv_label_set_text(ui->ui_Home_ui_Btn_Aircon_label, "");
	lv_label_set_long_mode(ui->ui_Home_ui_Btn_Aircon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Home_ui_Btn_Aircon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Home_ui_Btn_Aircon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Home_ui_Btn_Aircon, 35, 41);
	lv_obj_set_size(ui->ui_Home_ui_Btn_Aircon, 363, 240);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Btn_Aircon, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Btn_Aircon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Btn_Aircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Home_ui_Btn_Aircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Btn_Aircon, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Btn_Aircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Btn_Aircon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Btn_Aircon, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Btn_Aircon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Btn_Oven
	ui->ui_Home_ui_Btn_Oven = lv_btn_create(ui->ui_Home);
	ui->ui_Home_ui_Btn_Oven_label = lv_label_create(ui->ui_Home_ui_Btn_Oven);
	lv_label_set_text(ui->ui_Home_ui_Btn_Oven_label, "");
	lv_label_set_long_mode(ui->ui_Home_ui_Btn_Oven_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Home_ui_Btn_Oven_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Home_ui_Btn_Oven, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Home_ui_Btn_Oven, 497, 405);
	lv_obj_set_size(ui->ui_Home_ui_Btn_Oven, 287, 295);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Btn_Oven, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Btn_Oven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Btn_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Home_ui_Btn_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Btn_Oven, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Btn_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Home_ui_Btn_Oven, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Home_ui_Btn_Oven, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Home_ui_Btn_Oven, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Menu_Swing
	ui->ui_Home_ui_Image_Menu_Swing = lv_img_create(ui->ui_Home);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Menu_Swing, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Menu_Swing, &_aircon_menu_swing_01_alpha_298x39);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Menu_Swing, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Menu_Swing, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Menu_Swing, 72, 135);
	lv_obj_set_size(ui->ui_Home_ui_Image_Menu_Swing, 298, 39);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Menu_Swing, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Menu_Swing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Menu_Swing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Smog_menu_1
	ui->ui_Home_ui_Group_Smog_menu_1 = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Smog_menu_1, 494, 207);
	lv_obj_set_size(ui->ui_Home_ui_Group_Smog_menu_1, 165, 152);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Smog_menu_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Group_Smog_menu_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Group_Smog_menu_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Home_ui_Group_Smog_menu_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Group_Smog_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Smog_menu_11
	ui->ui_Home_ui_Image_Smog_menu_11 = lv_img_create(ui->ui_Home_ui_Group_Smog_menu_1);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Smog_menu_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Smog_menu_11, &_smog_1_alpha_110x472);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Smog_menu_11, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Smog_menu_11, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Smog_menu_11, 31, 0);
	lv_obj_set_size(ui->ui_Home_ui_Image_Smog_menu_11, 110, 472);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Smog_menu_11, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Smog_menu_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Smog_menu_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Smog_menu_12
	ui->ui_Home_ui_Image_Smog_menu_12 = lv_img_create(ui->ui_Home_ui_Group_Smog_menu_1);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Smog_menu_12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Smog_menu_12, &_smog_2_alpha_110x630);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Smog_menu_12, 0,0);
	lv_img_set_angle(ui->ui_Home_ui_Image_Smog_menu_12, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Smog_menu_12, 31, 310);
	lv_obj_set_size(ui->ui_Home_ui_Image_Smog_menu_12, 110, 630);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Smog_menu_12, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Smog_menu_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Smog_menu_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Group_Smog_menu_2
	ui->ui_Home_ui_Group_Smog_menu_2 = lv_obj_create(ui->ui_Home);
	lv_obj_set_pos(ui->ui_Home_ui_Group_Smog_menu_2, 599, 207);
	lv_obj_set_size(ui->ui_Home_ui_Group_Smog_menu_2, 165, 161);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Group_Smog_menu_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Group_Smog_menu_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Home_ui_Group_Smog_menu_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Home_ui_Group_Smog_menu_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Home_ui_Group_Smog_menu_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Smog_menu_21
	ui->ui_Home_ui_Image_Smog_menu_21 = lv_img_create(ui->ui_Home_ui_Group_Smog_menu_2);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Smog_menu_21, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Smog_menu_21, &_smog_1_alpha_110x472);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Smog_menu_21, 50,50);
	lv_img_set_angle(ui->ui_Home_ui_Image_Smog_menu_21, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Smog_menu_21, 31, 0);
	lv_obj_set_size(ui->ui_Home_ui_Image_Smog_menu_21, 110, 472);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Smog_menu_21, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Smog_menu_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Smog_menu_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Home_ui_Image_Smog_menu_22
	ui->ui_Home_ui_Image_Smog_menu_22 = lv_img_create(ui->ui_Home_ui_Group_Smog_menu_2);
	lv_obj_add_flag(ui->ui_Home_ui_Image_Smog_menu_22, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Home_ui_Image_Smog_menu_22, &_smog_2_alpha_110x630);
	lv_img_set_pivot(ui->ui_Home_ui_Image_Smog_menu_22, 0,0);
	lv_img_set_angle(ui->ui_Home_ui_Image_Smog_menu_22, 0);
	lv_obj_set_pos(ui->ui_Home_ui_Image_Smog_menu_22, 31, 310);
	lv_obj_set_size(ui->ui_Home_ui_Image_Smog_menu_22, 110, 630);
	lv_obj_set_scrollbar_mode(ui->ui_Home_ui_Image_Smog_menu_22, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Home_ui_Image_Smog_menu_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Home_ui_Image_Smog_menu_22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->ui_Home);

	
	//Init events for screen.
	events_init_ui_Home(ui);
}
