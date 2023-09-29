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


void setup_scr_ui_Hood(lv_ui *ui)
{
	//Write codes ui_Hood
	ui->ui_Hood = lv_obj_create(NULL);
	lv_obj_set_size(ui->ui_Hood, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Hood, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Hood_Bg
	ui->ui_Hood_ui_Image_Hood_Bg = lv_img_create(ui->ui_Hood);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Hood_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Hood_Bg, &_hood_bg_alpha_1280x720);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Hood_Bg, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Hood_Bg, 0);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Hood_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Hood_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Hood_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Image_Hood_Bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_ui_Image_Hood_Bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Hood_Light
	ui->ui_Hood_ui_Image_Hood_Light = lv_img_create(ui->ui_Hood);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Hood_Light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Hood_Light, &_hood_light_alpha_901x460);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Hood_Light, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Hood_Light, 0);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Hood_Light, 2, 179);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Hood_Light, 901, 460);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Hood_Light, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Image_Hood_Light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_ui_Image_Hood_Light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Group_Hood_Content
	ui->ui_Hood_ui_Group_Hood_Content = lv_obj_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Group_Hood_Content, 664, 98);
	lv_obj_set_size(ui->ui_Hood_ui_Group_Hood_Content, 548, 112);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Group_Hood_Content, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Group_Hood_Content, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Hood_ui_Group_Hood_Content, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Hood_ui_Group_Hood_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Hood_ui_Group_Hood_Content, lv_color_hex(0x4A4C4a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Group_Hood_Content, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Group_Hood_Content, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Hood_ui_Group_Hood_Content, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Hood_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Hood_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Hood_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Hood_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_ui_Group_Hood_Content, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Hood_Line
	ui->ui_Hood_ui_Hood_Line = lv_line_create(ui->ui_Hood_ui_Group_Hood_Content);
	static lv_point_t ui_Hood_ui_Hood_Line[] ={{0, 0},{526, 0},};
	lv_line_set_points(ui->ui_Hood_ui_Hood_Line, ui_Hood_ui_Hood_Line, 2);
	lv_obj_set_pos(ui->ui_Hood_ui_Hood_Line, 9, 8);
	lv_obj_set_size(ui->ui_Hood_ui_Hood_Line, 535, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Hood_Line, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Hood_Line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Hood_ui_Hood_Line, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Hood_ui_Hood_Line, lv_color_hex(0xACFF62), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Hood_ui_Hood_Line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Hood_ui_Hood_Line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Slider_Hood_Fan
	ui->ui_Hood_ui_Slider_Hood_Fan = lv_slider_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_slider_set_range(ui->ui_Hood_ui_Slider_Hood_Fan, 0,2);
	lv_slider_set_value(ui->ui_Hood_ui_Slider_Hood_Fan, 1, false);
	lv_obj_set_pos(ui->ui_Hood_ui_Slider_Hood_Fan, 329, 37);
	lv_obj_set_size(ui->ui_Hood_ui_Slider_Hood_Fan, 180, 16);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Slider_Hood_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Slider_Hood_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Slider_Hood_Fan, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Hood_ui_Slider_Hood_Fan, lv_color_hex(0x52555A), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Slider_Hood_Fan, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->ui_Hood_ui_Slider_Hood_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_ui_Slider_Hood_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Hood_ui_Slider_Hood_Fan, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Slider_Hood_Fan, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Hood_ui_Slider_Hood_Fan, lv_color_hex(0x73CA29), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Slider_Hood_Fan, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for ui_Hood_ui_Slider_Hood_Fan, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Slider_Hood_Fan, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Hood_ui_Slider_Hood_Fan, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Slider_Hood_Fan, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes ui_Hood_sw_1
	ui->ui_Hood_sw_1 = lv_switch_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_set_pos(ui->ui_Hood_sw_1, 106, 43);
	lv_obj_set_size(ui->ui_Hood_sw_1, 76, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_sw_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Hood_sw_1, lv_color_hex(0x6A6A6a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Hood_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_sw_1, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Hood_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
	lv_obj_set_style_bg_opa(ui->ui_Hood_sw_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_color(ui->ui_Hood_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_width(ui->ui_Hood_sw_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_radius(ui->ui_Hood_sw_1, 100, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_shadow_width(ui->ui_Hood_sw_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

	//Write style for ui_Hood_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->ui_Hood_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->ui_Hood_sw_1, lv_color_hex(0x73CA29), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->ui_Hood_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for ui_Hood_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Hood_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Hood_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_sw_1, 100, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Line2
	ui->ui_Hood_ui_Line2 = lv_line_create(ui->ui_Hood_ui_Group_Hood_Content);
	static lv_point_t ui_Hood_ui_Line2[] ={{0, 0},{0, 60},};
	lv_line_set_points(ui->ui_Hood_ui_Line2, ui_Hood_ui_Line2, 2);
	lv_obj_set_pos(ui->ui_Hood_ui_Line2, 209, 32);
	lv_obj_set_size(ui->ui_Hood_ui_Line2, 8, 65);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Line2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Line2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Hood_ui_Line2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Hood_ui_Line2, lv_color_hex(0x52555a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Hood_ui_Line2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Hood_ui_Line2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Label_Light
	ui->ui_Hood_ui_Label_Light = lv_label_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_label_set_text(ui->ui_Hood_ui_Label_Light, "LIGHT");
	lv_label_set_long_mode(ui->ui_Hood_ui_Label_Light, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Hood_ui_Label_Light, 4, 44);
	lv_obj_set_size(ui->ui_Hood_ui_Label_Light, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Label_Light, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Label_Light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Hood_ui_Label_Light, lv_color_hex(0xACFF62), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Hood_ui_Label_Light, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Hood_ui_Label_Light, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Hood_ui_Label_Light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Hood_ui_Label_Light, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_ui_Label_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Hood_Text
	ui->ui_Hood_ui_Image_Hood_Text = lv_img_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Hood_Text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Hood_Text, &_text_fan_param_alpha_198x26);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Hood_Text, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Hood_Text, 0);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Hood_Text, 323, 70);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Hood_Text, 198, 26);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Hood_Text, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Image_Hood_Text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_ui_Image_Hood_Text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Label_Fan
	ui->ui_Hood_ui_Label_Fan = lv_label_create(ui->ui_Hood_ui_Group_Hood_Content);
	lv_label_set_text(ui->ui_Hood_ui_Label_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Hood_ui_Label_Fan, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Hood_ui_Label_Fan, 216, 44);
	lv_obj_set_size(ui->ui_Hood_ui_Label_Fan, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Label_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Label_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Hood_ui_Label_Fan, lv_color_hex(0xACFF62), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Hood_ui_Label_Fan, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Hood_ui_Label_Fan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Hood_ui_Label_Fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Hood_ui_Label_Fan, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_ui_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Group_Smog1
	ui->ui_Hood_ui_Group_Smog1 = lv_obj_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Group_Smog1, 189, 210);
	lv_obj_set_size(ui->ui_Hood_ui_Group_Smog1, 195, 310);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Group_Smog1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Group_Smog1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Hood_ui_Group_Smog1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Hood_ui_Group_Smog1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_ui_Group_Smog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Smog11
	ui->ui_Hood_ui_Image_Smog11 = lv_img_create(ui->ui_Hood_ui_Group_Smog1);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog11, &_smog_1_alpha_133x472);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog11, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog11, 0);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog11, 31, 0);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog11, 133, 472);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog11, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Image_Smog11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_ui_Image_Smog11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Smog12
	ui->ui_Hood_ui_Image_Smog12 = lv_img_create(ui->ui_Hood_ui_Group_Smog1);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog12, &_smog_2_alpha_133x630);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog12, 0,0);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog12, 0);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog12, 31, 310);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog12, 133, 630);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog12, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Image_Smog12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_ui_Image_Smog12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Group_Smog2
	ui->ui_Hood_ui_Group_Smog2 = lv_obj_create(ui->ui_Hood);
	lv_obj_set_pos(ui->ui_Hood_ui_Group_Smog2, 411, 210);
	lv_obj_set_size(ui->ui_Hood_ui_Group_Smog2, 195, 310);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Group_Smog2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Group_Smog2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Hood_ui_Group_Smog2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Hood_ui_Group_Smog2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_ui_Group_Smog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Smog21
	ui->ui_Hood_ui_Image_Smog21 = lv_img_create(ui->ui_Hood_ui_Group_Smog2);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog21, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog21, &_smog_1_alpha_133x472);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog21, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog21, 0);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog21, 33, 0);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog21, 133, 472);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog21, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Image_Smog21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_ui_Image_Smog21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Image_Smog22
	ui->ui_Hood_ui_Image_Smog22 = lv_img_create(ui->ui_Hood_ui_Group_Smog2);
	lv_obj_add_flag(ui->ui_Hood_ui_Image_Smog22, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_ui_Image_Smog22, &_smog_2_alpha_133x630);
	lv_img_set_pivot(ui->ui_Hood_ui_Image_Smog22, 50,50);
	lv_img_set_angle(ui->ui_Hood_ui_Image_Smog22, 0);
	lv_obj_set_pos(ui->ui_Hood_ui_Image_Smog22, 33, 310);
	lv_obj_set_size(ui->ui_Hood_ui_Image_Smog22, 133, 630);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Image_Smog22, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Image_Smog22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_ui_Image_Smog22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_Lottie_Mic
	ui->ui_Hood_Lottie_Mic = lv_rlottie_create_from_raw(ui->ui_Hood, 62, 74, (const void *)lottie_lf30_gbhpz7py);
	lv_obj_set_pos(ui->ui_Hood_Lottie_Mic, 8, 639);
	lv_obj_set_size(ui->ui_Hood_Lottie_Mic, 62, 74);

	//Write style for ui_Hood_Lottie_Mic, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood_Lottie_Mic, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_Img_Label_Bg
	ui->ui_Hood_Img_Label_Bg = lv_img_create(ui->ui_Hood);
	lv_obj_add_flag(ui->ui_Hood_Img_Label_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Hood_Img_Label_Bg, &_title_bg_2_alpha_783x128);
	lv_img_set_pivot(ui->ui_Hood_Img_Label_Bg, 50,50);
	lv_img_set_angle(ui->ui_Hood_Img_Label_Bg, 0);
	lv_obj_set_pos(ui->ui_Hood_Img_Label_Bg, 630, -15);
	lv_obj_set_size(ui->ui_Hood_Img_Label_Bg, 783, 128);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_Img_Label_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_Img_Label_Bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Hood_Img_Label_Bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_Label_Hood
	ui->ui_Hood_Label_Hood = lv_label_create(ui->ui_Hood);
	lv_label_set_text(ui->ui_Hood_Label_Hood, "Hood");
	lv_label_set_long_mode(ui->ui_Hood_Label_Hood, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Hood_Label_Hood, 679, 33);
	lv_obj_set_size(ui->ui_Hood_Label_Hood, 100, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_Label_Hood, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_Label_Hood, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Hood_Label_Hood, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Hood_Label_Hood, &lv_font_Antonio_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Hood_Label_Hood, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Hood_Label_Hood, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Hood_Label_Hood, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_Label_Hood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Hood_ui_Btn_Back1
	ui->ui_Hood_ui_Btn_Back1 = lv_btn_create(ui->ui_Hood);
	ui->ui_Hood_ui_Btn_Back1_label = lv_label_create(ui->ui_Hood_ui_Btn_Back1);
	lv_label_set_text(ui->ui_Hood_ui_Btn_Back1_label, "BACK");
	lv_label_set_long_mode(ui->ui_Hood_ui_Btn_Back1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Hood_ui_Btn_Back1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Hood_ui_Btn_Back1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Hood_ui_Btn_Back1, -41, 24);
	lv_obj_set_size(ui->ui_Hood_ui_Btn_Back1, 155, 65);
	lv_obj_set_scrollbar_mode(ui->ui_Hood_ui_Btn_Back1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Hood_ui_Btn_Back1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Hood_ui_Btn_Back1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Hood_ui_Btn_Back1, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Hood_ui_Btn_Back1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Hood_ui_Btn_Back1, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Hood_ui_Btn_Back1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Hood_ui_Btn_Back1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Hood_ui_Btn_Back1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Hood_ui_Btn_Back1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->ui_Hood);

	
	//Init events for screen.
	events_init_ui_Hood(ui);
}
