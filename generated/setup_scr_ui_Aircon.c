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


void setup_scr_ui_Aircon(lv_ui *ui)
{
	//Write codes ui_Aircon
	ui->ui_Aircon = lv_obj_create(NULL);
	lv_obj_set_size(ui->ui_Aircon, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Bg
	ui->ui_Aircon_Img_Bg = lv_img_create(ui->ui_Aircon);
	lv_obj_add_flag(ui->ui_Aircon_Img_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Bg, &_aircon_bg_alpha_1280x720);
	lv_img_set_pivot(ui->ui_Aircon_Img_Bg, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Bg, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_Bg, 0, 0);
	lv_obj_set_size(ui->ui_Aircon_Img_Bg, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_Bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_Bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Label_Bg
	ui->ui_Aircon_Img_Label_Bg = lv_img_create(ui->ui_Aircon);
	lv_obj_add_flag(ui->ui_Aircon_Img_Label_Bg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Label_Bg, &_title_bg_alpha_799x130);
	lv_img_set_pivot(ui->ui_Aircon_Img_Label_Bg, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Label_Bg, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_Label_Bg, 0, 590);
	lv_obj_set_size(ui->ui_Aircon_Img_Label_Bg, 799, 130);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Label_Bg, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_Label_Bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_Label_Bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Air
	ui->ui_Aircon_Label_Air = lv_label_create(ui->ui_Aircon);
	lv_label_set_text(ui->ui_Aircon_Label_Air, "Air Conditioner");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Air, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Air, 565, 639);
	lv_obj_set_size(ui->ui_Aircon_Label_Air, 180, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Air, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Air, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Air, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Air, &lv_font_Antonio_Regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Air, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Air, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Air, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Swing
	ui->ui_Aircon_Img_Swing = lv_img_create(ui->ui_Aircon);
	lv_obj_add_flag(ui->ui_Aircon_Img_Swing, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Swing, &_aircon_swing_1_alpha_632x113);
	lv_img_set_pivot(ui->ui_Aircon_Img_Swing, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Swing, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_Swing, 120, 380);
	lv_obj_set_size(ui->ui_Aircon_Img_Swing, 632, 113);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Swing, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_Swing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_Swing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Cont
	ui->ui_Aircon_Cont = lv_obj_create(ui->ui_Aircon);
	lv_obj_set_pos(ui->ui_Aircon_Cont, 826, 30);
	lv_obj_set_size(ui->ui_Aircon_Cont, 409, 657);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Cont, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Aircon_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Aircon_Cont, lv_color_hex(0x4A4C4A), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Cont, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Cont, 250, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Cont, lv_color_hex(0x242424), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line
	ui->ui_Aircon_line = lv_line_create(ui->ui_Aircon_Cont);
	static lv_point_t ui_Aircon_line[] ={{0, 0},{393, 0},};
	lv_line_set_points(ui->ui_Aircon_line, ui_Aircon_line, 2);
	lv_obj_set_pos(ui->ui_Aircon_line, 7, 7);
	lv_obj_set_size(ui->ui_Aircon_line, 405, 24);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Aircon_line, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Aircon_line, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Aircon_line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->ui_Aircon_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Temp
	ui->ui_Aircon_Label_Temp = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Temp, "25");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Temp, 12, 58);
	lv_obj_set_size(ui->ui_Aircon_Label_Temp, 151, 123);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Temp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Temp, &lv_font_Antonio_Regular_120, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Temp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Btn_TempUp
	ui->ui_Aircon_Btn_TempUp = lv_btn_create(ui->ui_Aircon_Cont);
	ui->ui_Aircon_Btn_TempUp_label = lv_label_create(ui->ui_Aircon_Btn_TempUp);
	lv_label_set_text(ui->ui_Aircon_Btn_TempUp_label, "");
	lv_label_set_long_mode(ui->ui_Aircon_Btn_TempUp_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Aircon_Btn_TempUp_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TempUp, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TempUp, 198, 100);
	lv_obj_set_size(ui->ui_Aircon_Btn_TempUp, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TempUp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Btn_TempUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TempUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TempUp, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TempUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TempUp, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TempUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TempUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TempUp, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Btn_TempUp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Btn_TempUp, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TempUp, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TempUp, lv_color_hex(0x18C220), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TempUp, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TempUp, 10, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TempUp, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TempUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TempUp, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes ui_Aircon_Label_SetTemp
	ui->ui_Aircon_Label_SetTemp = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_SetTemp, "SET TEMPERATURE");
	lv_label_set_long_mode(ui->ui_Aircon_Label_SetTemp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_SetTemp, 110, 22);
	lv_obj_set_size(ui->ui_Aircon_Label_SetTemp, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_SetTemp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_SetTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_SetTemp, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_SetTemp, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_SetTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_SetTemp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_SetTemp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Cen
	ui->ui_Aircon_Label_Cen = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Cen, "ºC");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Cen, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Cen, 121, 61);
	lv_obj_set_size(ui->ui_Aircon_Label_Cen, 72, 53);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Cen, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Cen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Cen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Cen, &lv_font_Alatsi_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Cen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Cen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Cen, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Btn_TempDown
	ui->ui_Aircon_Btn_TempDown = lv_btn_create(ui->ui_Aircon_Cont);
	ui->ui_Aircon_Btn_TempDown_label = lv_label_create(ui->ui_Aircon_Btn_TempDown);
	lv_label_set_text(ui->ui_Aircon_Btn_TempDown_label, "");
	lv_label_set_long_mode(ui->ui_Aircon_Btn_TempDown_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Aircon_Btn_TempDown_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TempDown, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TempDown, 295, 100);
	lv_obj_set_size(ui->ui_Aircon_Btn_TempDown, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TempDown, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Btn_TempDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TempDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TempDown, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TempDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TempDown, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TempDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TempDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TempDown, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Btn_TempDown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Btn_TempDown, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TempDown, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TempDown, lv_color_hex(0x18C220), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TempDown, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TempDown, 10, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TempDown, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TempDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TempDown, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes ui_Aircon_Img_TemUp
	ui->ui_Aircon_Img_TemUp = lv_img_create(ui->ui_Aircon_Cont);
	lv_obj_add_flag(ui->ui_Aircon_Img_TemUp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TemUp, &_arrow_up_alpha_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TemUp, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TemUp, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_TemUp, 222, 122);
	lv_obj_set_size(ui->ui_Aircon_Img_TemUp, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TemUp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_TemUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_TemUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_TempDown
	ui->ui_Aircon_Img_TempDown = lv_img_create(ui->ui_Aircon_Cont);
	lv_obj_add_flag(ui->ui_Aircon_Img_TempDown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TempDown, &_arrow_down_alpha_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TempDown, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TempDown, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_TempDown, 319, 122);
	lv_obj_set_size(ui->ui_Aircon_Img_TempDown, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TempDown, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_TempDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_TempDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Roller_Mode
	ui->ui_Aircon_Roller_Mode = lv_roller_create(ui->ui_Aircon_Cont);
	lv_roller_set_options(ui->ui_Aircon_Roller_Mode, "COOL\nDRY\nFAN", LV_ROLLER_MODE_INFINITE);
	lv_roller_set_visible_row_count(ui->ui_Aircon_Roller_Mode, 3);
	lv_obj_set_pos(ui->ui_Aircon_Roller_Mode, 40, 404);
	lv_obj_set_width(ui->ui_Aircon_Roller_Mode, 100);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Roller_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Roller_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->ui_Aircon_Roller_Mode, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Roller_Mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0x9D9D9D), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Roller_Mode, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Roller_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Aircon_Roller_Mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->ui_Aircon_Roller_Mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Roller_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Roller_Mode, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Roller_Mode, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0x20A1C5), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Roller_Mode, &lv_font_Antonio_Regular_21, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Roller_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Btn_Swing
	ui->ui_Aircon_Btn_Swing = lv_btn_create(ui->ui_Aircon_Cont);
	lv_obj_add_flag(ui->ui_Aircon_Btn_Swing, LV_OBJ_FLAG_CHECKABLE);
	ui->ui_Aircon_Btn_Swing_label = lv_label_create(ui->ui_Aircon_Btn_Swing);
	lv_label_set_text(ui->ui_Aircon_Btn_Swing_label, "ON");
	lv_label_set_long_mode(ui->ui_Aircon_Btn_Swing_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Aircon_Btn_Swing_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_Swing, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Aircon_Btn_Swing, 99, 572);
	lv_obj_set_size(ui->ui_Aircon_Btn_Swing, 78, 45);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_Swing, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Btn_Swing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Swing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0x6A6A6A), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_Swing, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0x9D9D9D), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Swing, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Btn_Swing, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Btn_Swing, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Swing, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_Swing, 10, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Swing, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for ui_Aircon_Btn_Swing, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Swing, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_Swing, 10, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Swing, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes ui_Aircon_Label_Swing
	ui->ui_Aircon_Label_Swing = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Swing, "SWING");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Swing, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Swing, 30, 576);
	lv_obj_set_size(ui->ui_Aircon_Label_Swing, 73, 38);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Swing, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Swing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Swing, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Swing, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Swing, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Swing, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Swing, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line_1
	ui->ui_Aircon_line_1 = lv_line_create(ui->ui_Aircon_Cont);
	static lv_point_t ui_Aircon_line_1[] ={{0, 0},{360, 0},};
	lv_line_set_points(ui->ui_Aircon_line_1, ui_Aircon_line_1, 2);
	lv_obj_set_pos(ui->ui_Aircon_line_1, 23, 199);
	lv_obj_set_size(ui->ui_Aircon_line_1, 371, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Aircon_line_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Aircon_line_1, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Aircon_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line_2
	ui->ui_Aircon_line_2 = lv_line_create(ui->ui_Aircon_Cont);
	static lv_point_t ui_Aircon_line_2[] ={{0, 0},{360, 0},};
	lv_line_set_points(ui->ui_Aircon_line_2, ui_Aircon_line_2, 2);
	lv_obj_set_pos(ui->ui_Aircon_line_2, 23, 359);
	lv_obj_set_size(ui->ui_Aircon_line_2, 371, 13);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Aircon_line_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Aircon_line_2, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Aircon_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line_3
	ui->ui_Aircon_line_3 = lv_line_create(ui->ui_Aircon_Cont);
	static lv_point_t ui_Aircon_line_3[] ={{0, 0},{360, 0},};
	lv_line_set_points(ui->ui_Aircon_line_3, ui_Aircon_line_3, 2);
	lv_obj_set_pos(ui->ui_Aircon_line_3, 23, 540);
	lv_obj_set_size(ui->ui_Aircon_line_3, 371, 7);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_3, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Aircon_line_3, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Aircon_line_3, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Aircon_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line_4
	ui->ui_Aircon_line_4 = lv_line_create(ui->ui_Aircon_Cont);
	static lv_point_t ui_Aircon_line_4[] ={{0, 0},{0, 100},};
	lv_line_set_points(ui->ui_Aircon_line_4, ui_Aircon_line_4, 2);
	lv_obj_set_pos(ui->ui_Aircon_line_4, 242, 410);
	lv_obj_set_size(ui->ui_Aircon_line_4, 29, 119);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_4, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Aircon_line_4, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Aircon_line_4, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Aircon_line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_line_5
	ui->ui_Aircon_line_5 = lv_line_create(ui->ui_Aircon_Cont);
	static lv_point_t ui_Aircon_line_5[] ={{0, 0},{0, 50},};
	lv_line_set_points(ui->ui_Aircon_line_5, ui_Aircon_line_5, 2);
	lv_obj_set_pos(ui->ui_Aircon_line_5, 192, 568);
	lv_obj_set_size(ui->ui_Aircon_line_5, 17, 67);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_line_5, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->ui_Aircon_line_5, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->ui_Aircon_line_5, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->ui_Aircon_line_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Timer
	ui->ui_Aircon_Label_Timer = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Timer, "SET TIMER");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Timer, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Timer, 105, 202);
	lv_obj_set_size(ui->ui_Aircon_Label_Timer, 203, 32);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Timer, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Timer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Timer, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Timer, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Timer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Timer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Timer, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Mode
	ui->ui_Aircon_Label_Mode = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Mode, "SELECT MODE");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Mode, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Mode, 123, 364);
	lv_obj_set_size(ui->ui_Aircon_Label_Mode, 178, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Mode, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Mode, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Mode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Fan
	ui->ui_Aircon_Label_Fan = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Fan, "FAN");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Fan, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Fan, 204, 571);
	lv_obj_set_size(ui->ui_Aircon_Label_Fan, 45, 38);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Fan, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Fan, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Fan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Fan, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Slider_Fan
	ui->ui_Aircon_Slider_Fan = lv_slider_create(ui->ui_Aircon_Cont);
	lv_slider_set_range(ui->ui_Aircon_Slider_Fan, 0,2);
	lv_slider_set_value(ui->ui_Aircon_Slider_Fan, 1, false);
	lv_obj_set_pos(ui->ui_Aircon_Slider_Fan, 257, 579);
	lv_obj_set_size(ui->ui_Aircon_Slider_Fan, 127, 16);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Slider_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Slider_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Slider_Fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Slider_Fan, lv_color_hex(0x6A6A6A), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Slider_Fan, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->ui_Aircon_Slider_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Slider_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Slider_Fan, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Slider_Fan, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Slider_Fan, lv_color_hex(0x29BAE6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Slider_Fan, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Slider_Fan, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Slider_Fan, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Slider_Fan, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Slider_Fan, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Low
	ui->ui_Aircon_Label_Low = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Low, "•\nLOW");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Low, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Low, 249, 592);
	lv_obj_set_size(ui->ui_Aircon_Label_Low, 29, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Low, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Low, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Low, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Low, &lv_font_Antonio_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Low, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Low, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Low, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Low, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Medium
	ui->ui_Aircon_Label_Medium = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Medium, "•\nMEDIUM");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Medium, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Medium, 295, 592);
	lv_obj_set_size(ui->ui_Aircon_Label_Medium, 53, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Medium, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Medium, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Medium, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Medium, &lv_font_Antonio_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Medium, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Medium, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Medium, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Medium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_High
	ui->ui_Aircon_Label_High = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_High, "•\nHIGH");
	lv_label_set_long_mode(ui->ui_Aircon_Label_High, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_High, 363, 592);
	lv_obj_set_size(ui->ui_Aircon_Label_High, 29, 34);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_High, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_High, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_High, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_High, &lv_font_Antonio_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_High, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_High, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_High, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_High, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_Comp
	ui->ui_Aircon_Label_Comp = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_Comp, "COMP");
	lv_label_set_long_mode(ui->ui_Aircon_Label_Comp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_Comp, 302, 402);
	lv_obj_set_size(ui->ui_Aircon_Label_Comp, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_Comp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_Comp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_Comp, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_Comp, &lv_font_Antonio_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Comp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_Comp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Comp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Comp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_On
	ui->ui_Aircon_Label_On = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_On, "ON");
	lv_label_set_long_mode(ui->ui_Aircon_Label_On, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_On, 302, 424);
	lv_obj_set_size(ui->ui_Aircon_Label_On, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_On, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_On, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_On, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_On, &lv_font_Antonio_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_On, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_On, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_On, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_On, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Comp
	ui->ui_Aircon_Img_Comp = lv_img_create(ui->ui_Aircon_Cont);
	lv_obj_add_flag(ui->ui_Aircon_Img_Comp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Comp, &_icn_cool_alpha_27x31);
	lv_img_set_pivot(ui->ui_Aircon_Img_Comp, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Comp, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_Comp, 272, 413);
	lv_obj_set_size(ui->ui_Aircon_Img_Comp, 27, 31);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Comp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_Comp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_Comp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_FanSt
	ui->ui_Aircon_Label_FanSt = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_FanSt, "FAN");
	lv_label_set_long_mode(ui->ui_Aircon_Label_FanSt, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_FanSt, 303, 462);
	lv_obj_set_size(ui->ui_Aircon_Label_FanSt, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_FanSt, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_FanSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_FanSt, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_FanSt, &lv_font_Antonio_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_FanSt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_FanSt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_FanSt, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_FanState
	ui->ui_Aircon_Label_FanState = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_FanState, "LOW");
	lv_label_set_long_mode(ui->ui_Aircon_Label_FanState, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_FanState, 303, 485);
	lv_obj_set_size(ui->ui_Aircon_Label_FanState, 65, 30);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_FanState, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_FanState, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_FanState, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_FanState, &lv_font_Antonio_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_FanState, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_FanState, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_FanState, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_FanState, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_FanSt
	ui->ui_Aircon_Img_FanSt = lv_img_create(ui->ui_Aircon_Cont);
	lv_obj_add_flag(ui->ui_Aircon_Img_FanSt, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_FanSt, &_icn_fan_low_alpha_31x27);
	lv_img_set_pivot(ui->ui_Aircon_Img_FanSt, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_FanSt, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_FanSt, 272, 474);
	lv_obj_set_size(ui->ui_Aircon_Img_FanSt, 31, 27);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_FanSt, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_FanSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_FanSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Btn_TimerUp
	ui->ui_Aircon_Btn_TimerUp = lv_btn_create(ui->ui_Aircon_Cont);
	ui->ui_Aircon_Btn_TimerUp_label = lv_label_create(ui->ui_Aircon_Btn_TimerUp);
	lv_label_set_text(ui->ui_Aircon_Btn_TimerUp_label, "");
	lv_label_set_long_mode(ui->ui_Aircon_Btn_TimerUp_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Aircon_Btn_TimerUp_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TimerUp, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TimerUp, 198, 260);
	lv_obj_set_size(ui->ui_Aircon_Btn_TimerUp, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TimerUp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Btn_TimerUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TimerUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TimerUp, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TimerUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TimerUp, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TimerUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TimerUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TimerUp, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Btn_TimerUp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Btn_TimerUp, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TimerUp, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TimerUp, lv_color_hex(0x18C220), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TimerUp, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TimerUp, 10, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TimerUp, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TimerUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TimerUp, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes ui_Aircon_Img_TimerUp
	ui->ui_Aircon_Img_TimerUp = lv_img_create(ui->ui_Aircon_Cont);
	lv_obj_add_flag(ui->ui_Aircon_Img_TimerUp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TimerUp, &_arrow_up_alpha_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TimerUp, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TimerUp, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_TimerUp, 222, 281);
	lv_obj_set_size(ui->ui_Aircon_Img_TimerUp, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TimerUp, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_TimerUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_TimerUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Btn_TimerDown
	ui->ui_Aircon_Btn_TimerDown = lv_btn_create(ui->ui_Aircon_Cont);
	ui->ui_Aircon_Btn_TimerDown_label = lv_label_create(ui->ui_Aircon_Btn_TimerDown);
	lv_label_set_text(ui->ui_Aircon_Btn_TimerDown_label, "");
	lv_label_set_long_mode(ui->ui_Aircon_Btn_TimerDown_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Aircon_Btn_TimerDown_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TimerDown, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Aircon_Btn_TimerDown, 295, 260);
	lv_obj_set_size(ui->ui_Aircon_Btn_TimerDown, 74, 58);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Btn_TimerDown, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Btn_TimerDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TimerDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TimerDown, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TimerDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TimerDown, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TimerDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TimerDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TimerDown, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Btn_TimerDown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for ui_Aircon_Btn_TimerDown, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TimerDown, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TimerDown, lv_color_hex(0x18C220), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TimerDown, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->ui_Aircon_Btn_TimerDown, 10, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TimerDown, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TimerDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TimerDown, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes ui_Aircon_Img_TimerDown
	ui->ui_Aircon_Img_TimerDown = lv_img_create(ui->ui_Aircon_Cont);
	lv_obj_add_flag(ui->ui_Aircon_Img_TimerDown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_TimerDown, &_arrow_down_alpha_28x14);
	lv_img_set_pivot(ui->ui_Aircon_Img_TimerDown, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_TimerDown, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_TimerDown, 319, 281);
	lv_obj_set_size(ui->ui_Aircon_Img_TimerDown, 28, 14);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_TimerDown, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_TimerDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_TimerDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_TimerHour
	ui->ui_Aircon_Label_TimerHour = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_TimerHour, "01");
	lv_label_set_long_mode(ui->ui_Aircon_Label_TimerHour, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_TimerHour, 19, 234);
	lv_obj_set_size(ui->ui_Aircon_Label_TimerHour, 76, 103);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_TimerHour, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_TimerHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_TimerHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_TimerHour, &lv_font_Antonio_Regular_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_TimerHour, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_TimerHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_TimerHour, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_TimerPoints
	ui->ui_Aircon_Label_TimerPoints = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_TimerPoints, ":");
	lv_label_set_long_mode(ui->ui_Aircon_Label_TimerPoints, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_TimerPoints, 93, 229);
	lv_obj_set_size(ui->ui_Aircon_Label_TimerPoints, 23, 103);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_TimerPoints, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_TimerPoints, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_TimerPoints, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_TimerPoints, &lv_font_Antonio_Regular_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_TimerPoints, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_TimerPoints, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_TimerPoints, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_TimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Label_TimerMin
	ui->ui_Aircon_Label_TimerMin = lv_label_create(ui->ui_Aircon_Cont);
	lv_label_set_text(ui->ui_Aircon_Label_TimerMin, "15");
	lv_label_set_long_mode(ui->ui_Aircon_Label_TimerMin, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_Aircon_Label_TimerMin, 118, 234);
	lv_obj_set_size(ui->ui_Aircon_Label_TimerMin, 76, 103);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Label_TimerMin, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Label_TimerMin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_Label_TimerMin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_Label_TimerMin, &lv_font_Antonio_Regular_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_TimerMin, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_Label_TimerMin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_Aircon_Label_TimerMin, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Fan
	ui->ui_Aircon_Img_Fan = lv_img_create(ui->ui_Aircon);
	lv_obj_add_flag(ui->ui_Aircon_Img_Fan, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Fan, &_aircon_fan_1_alpha_98x98);
	lv_img_set_pivot(ui->ui_Aircon_Img_Fan, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Fan, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_Fan, 646, 218);
	lv_obj_set_size(ui->ui_Aircon_Img_Fan, 98, 98);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Fan, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_Fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Img_Cool
	ui->ui_Aircon_Img_Cool = lv_img_create(ui->ui_Aircon);
	lv_obj_add_flag(ui->ui_Aircon_Img_Cool, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ui_Aircon_Img_Cool, &_aircon_cool_1_alpha_92x102);
	lv_img_set_pivot(ui->ui_Aircon_Img_Cool, 50,50);
	lv_img_set_angle(ui->ui_Aircon_Img_Cool, 0);
	lv_obj_set_pos(ui->ui_Aircon_Img_Cool, 559, 213);
	lv_obj_set_size(ui->ui_Aircon_Img_Cool, 92, 102);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_Img_Cool, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_Img_Cool, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ui_Aircon_Img_Cool, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_ui_Btn_Back2
	ui->ui_Aircon_ui_Btn_Back2 = lv_btn_create(ui->ui_Aircon);
	ui->ui_Aircon_ui_Btn_Back2_label = lv_label_create(ui->ui_Aircon_ui_Btn_Back2);
	lv_label_set_text(ui->ui_Aircon_ui_Btn_Back2_label, "BACK");
	lv_label_set_long_mode(ui->ui_Aircon_ui_Btn_Back2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_Aircon_ui_Btn_Back2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_Aircon_ui_Btn_Back2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ui_Aircon_ui_Btn_Back2, -38, 23);
	lv_obj_set_size(ui->ui_Aircon_ui_Btn_Back2, 155, 65);
	lv_obj_set_scrollbar_mode(ui->ui_Aircon_ui_Btn_Back2, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_Aircon_ui_Btn_Back2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_ui_Btn_Back2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_Aircon_ui_Btn_Back2, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_Aircon_ui_Btn_Back2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_Aircon_ui_Btn_Back2, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_Aircon_ui_Btn_Back2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_Aircon_ui_Btn_Back2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_Aircon_ui_Btn_Back2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_Aircon_ui_Btn_Back2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_Aircon_Lottie_Mic
	ui->ui_Aircon_Lottie_Mic = lv_rlottie_create_from_raw(ui->ui_Aircon, 62, 74, (const void *)lottie_KNiPNozN4m);
	lv_obj_set_pos(ui->ui_Aircon_Lottie_Mic, 8, 639);
	lv_obj_set_size(ui->ui_Aircon_Lottie_Mic, 62, 74);

	//Write style for ui_Aircon_Lottie_Mic, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_Aircon_Lottie_Mic, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->ui_Aircon);

	
	//Init events for screen.
	events_init_ui_Aircon(ui);
}
