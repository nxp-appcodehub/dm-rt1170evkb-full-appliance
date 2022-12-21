/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <ui_Oven.h>
#include "ui_Animations.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
LV_FONT_DECLARE(lv_font_Antonio_Regular_50)
LV_IMG_DECLARE(_oven_door_01_704x720);
LV_IMG_DECLARE(_oven_door_02_704x720);
LV_IMG_DECLARE(_oven_door_03_704x720);
LV_IMG_DECLARE(_oven_door_04_704x720);
LV_IMG_DECLARE(_oven_door_05_704x720);
LV_IMG_DECLARE(_oven_door_06_704x720);
LV_IMG_DECLARE(_oven_door_07_704x720);
LV_IMG_DECLARE(_oven_door_08_704x720);

static const lv_img_dsc_t * oven_door[] = {&_oven_light_704x720, /*&_oven_door_01_704x720,*/ &_oven_door_02_704x720, /*&_oven_door_03_704x720,*/ &_oven_door_04_704x720,
		/*&_oven_door_05_704x720,*/ &_oven_door_06_704x720, &_oven_door_07_704x720, &_oven_door_08_704x720};
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
uint16_t lv_obj_get_tile_id(lv_obj_t * obj);
static void oven_wheel_scroll_event_cb(lv_event_t * e);
static void ui_oven_anim_door(bool open, uint32_t delay);
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint16_t Oven_Mode = kOVEN_ModeFFRE;
bool ui_oven_door_state = kOVEN_DoorClose;
bool ui_oven_light_state = kOVEN_lightOff;
/*******************************************************************************
 * Function
 ******************************************************************************/
/*Complete Oven setting*/
void ui_oven_init (void)
{

	lv_obj_clear_flag(guider_ui.ui_Oven_Group_Oven, LV_OBJ_FLAG_SCROLLABLE);

	/*Set first Tile*/
	lv_obj_set_tile_id(guider_ui.ui_Oven_Group_Oven, 0, 0 ,LV_ANIM_OFF);

	/*Set the light as off*/
	lv_obj_set_style_opa(guider_ui.ui_Oven_Img_Door, LV_OPA_TRANSP, 0);

	/*Oven target temperature*/
	lv_obj_t * ui_Label_Target_Temp_Numer;
	ui_Label_Target_Temp_Numer = lv_label_create(guider_ui.ui_Oven_Img_TempWheel);

	lv_obj_set_width(ui_Label_Target_Temp_Numer, 101);
	lv_obj_set_height(ui_Label_Target_Temp_Numer, LV_SIZE_CONTENT);

	lv_obj_set_x(ui_Label_Target_Temp_Numer, -20);
	lv_obj_set_y(ui_Label_Target_Temp_Numer, 2);

	lv_obj_set_align(ui_Label_Target_Temp_Numer, LV_ALIGN_RIGHT_MID);

	lv_label_set_text(ui_Label_Target_Temp_Numer, "170");

	lv_obj_set_style_text_color(ui_Label_Target_Temp_Numer, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_Label_Target_Temp_Numer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui_Label_Target_Temp_Numer, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_Label_Target_Temp_Numer, &lv_font_Antonio_Regular_50, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_set_flex_flow(guider_ui.ui_Oven_Group_TarTemp, LV_FLEX_FLOW_COLUMN);
	lv_obj_set_flex_align(guider_ui.ui_Oven_Group_TarTemp, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
	lv_obj_set_style_pad_row(guider_ui.ui_Oven_Group_TarTemp, 20, 0);
	lv_obj_set_style_text_color(guider_ui.ui_Oven_Group_TarTemp, lv_color_hex(0xff9110), 0);
	lv_obj_set_style_text_font(guider_ui.ui_Oven_Group_TarTemp, &lv_font_Antonio_Regular_20, 0);
	lv_obj_add_flag(guider_ui.ui_Oven_Img_TempWheel, LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING);
	lv_obj_add_flag(guider_ui.ui_Oven_Label_SelTemp, LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING);
	lv_obj_add_flag(guider_ui.ui_Oven_Label_TarCen, LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING);

	lv_obj_add_event_cb(guider_ui.ui_Oven_Group_TarTemp, oven_wheel_scroll_event_cb, LV_EVENT_SCROLL, ui_Label_Target_Temp_Numer);
	lv_obj_set_scroll_snap_y(guider_ui.ui_Oven_Group_TarTemp, LV_SCROLL_SNAP_CENTER);

	uint32_t i;
	for(i = 0; i < 20; i++) {
		lv_obj_t * label = lv_label_create(guider_ui.ui_Oven_Group_TarTemp);
		lv_label_set_text_fmt(label, "%d", 150 + i * 5);
		lv_obj_set_width(label, 80);
	}

	lv_obj_move_foreground(guider_ui.ui_Oven_Img_TempWheel);
	lv_obj_move_foreground(guider_ui.ui_Oven_Label_SelTemp);
	lv_obj_move_foreground(guider_ui.ui_Oven_Label_TarCen);

	lv_obj_update_layout(guider_ui.ui_Oven_Group_TarTemp);
	lv_obj_update_snap(guider_ui.ui_Oven_Group_TarTemp, LV_ANIM_OFF);
	lv_event_send(guider_ui.ui_Oven_Group_TarTemp, LV_EVENT_SCROLL, NULL);

	/*Oven Timer*/
	lv_obj_t * ui_Label_Timer_Number;
	ui_Label_Timer_Number = lv_label_create(guider_ui.ui_Oven_Img_TimerWheel);

	lv_obj_set_width(ui_Label_Timer_Number, 102);
	lv_obj_set_height(ui_Label_Timer_Number, LV_SIZE_CONTENT);

	lv_obj_set_x(ui_Label_Timer_Number, -33);
	lv_obj_set_y(ui_Label_Timer_Number, 2);

	lv_obj_set_align(ui_Label_Timer_Number, LV_ALIGN_RIGHT_MID);

	lv_label_set_text(ui_Label_Timer_Number, "15");

	lv_obj_set_style_text_color(ui_Label_Timer_Number, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_Label_Timer_Number, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui_Label_Timer_Number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_Label_Timer_Number, &lv_font_Antonio_Regular_50, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_set_flex_flow(guider_ui.ui_Oven_Group_Timer, LV_FLEX_FLOW_COLUMN);
	lv_obj_set_flex_align(guider_ui.ui_Oven_Group_Timer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
	lv_obj_set_style_pad_row(guider_ui.ui_Oven_Group_Timer, 20, 0);
	lv_obj_set_style_text_font(guider_ui.ui_Oven_Group_Timer, &lv_font_Antonio_Regular_20, 0);
	lv_obj_set_style_text_color(guider_ui.ui_Oven_Group_Timer, lv_color_hex(0xff9110), 0);
	lv_obj_add_flag(guider_ui.ui_Oven_Img_TimerWheel, LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING);
	lv_obj_add_flag(guider_ui.ui_Oven_Label_SelTimer, LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING);
	lv_obj_add_flag(guider_ui.ui_Oven_Label_TimerSel, LV_OBJ_FLAG_IGNORE_LAYOUT | LV_OBJ_FLAG_FLOATING);

	lv_obj_add_event_cb(guider_ui.ui_Oven_Group_Timer, oven_wheel_scroll_event_cb, LV_EVENT_SCROLL, ui_Label_Timer_Number);
	lv_obj_set_scroll_snap_y(guider_ui.ui_Oven_Group_Timer, LV_SCROLL_SNAP_CENTER);
	for(i = 0; i < 17; i++) {
		lv_obj_t * label = lv_label_create(guider_ui.ui_Oven_Group_Timer);
		lv_label_set_text_fmt(label, "%d", i * 5 + 10);
		lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_RIGHT, 0);
		lv_obj_set_width(label, 80);
	}

	lv_obj_move_foreground(guider_ui.ui_Oven_Img_TimerWheel);
	lv_obj_move_foreground(guider_ui.ui_Oven_Label_SelTimer);
	lv_obj_move_foreground(guider_ui.ui_Oven_Label_TimerSel);

	lv_obj_update_layout(guider_ui.ui_Oven_Group_Timer);
	lv_obj_update_snap(guider_ui.ui_Oven_Group_Timer, LV_ANIM_OFF);
	lv_event_send(guider_ui.ui_Oven_Group_Timer, LV_EVENT_SCROLL, NULL);
}

void ui_oven_set_mode(OVEN_MODE_T mode, OVEN_MODE_Dir_T dir)
{

	if(mode != kOVEN_ModeNull)
	{
		Oven_Mode = mode;
	}
	else
	{
		Oven_Mode = lv_obj_get_tile_id(guider_ui.ui_Oven_Tile_Mode);
		if(dir == kOVEN_ModeDirLeft)
		{
			if(Oven_Mode > 0)
			{
				Oven_Mode--;
			}
		}
		else if(dir == kOVEN_ModeDirRight)
		{
			if(Oven_Mode < 9)
			{
				Oven_Mode++;
			}
		}
	}
	lv_obj_set_tile_id(guider_ui.ui_Oven_Tile_Mode, Oven_Mode, 0 ,LV_ANIM_ON);
}

void ui_oven_door(OVEN_Door_T state)
{
	switch(state)
	{
	case kOVEN_DoorOpen:
		if(ui_oven_door_state == kOVEN_DoorOpen)
		{
			break;
		}
		ui_oven_anim_door(kOVEN_DoorOpen, 0);
		//TODO: Update Image of the Door on the menu.
		ui_oven_door_state = kOVEN_DoorOpen;
		ui_oven_light_state = kOVEN_LightOn;
		break;
	case kOVEN_DoorClose:
		if(ui_oven_door_state == kOVEN_DoorClose)
		{
			break;
		}
		ui_oven_anim_door(kOVEN_DoorClose, 0);
		//TODO: Update Image of the Door on the menu
		ui_oven_door_state = kOVEN_DoorClose;
		break;
	}
}

void ui_oven_set_light(OVEN_Light_T state)
{
	switch (state)
	{
	case kOVEN_lightOff:
		if(ui_oven_light_state == false)
		{
			break;
		}
		lv_obj_fade_out(guider_ui.ui_Oven_Img_Door, 0, 0);
		//TODO: Update Image of the Door on the menu
		ui_oven_light_state = kOVEN_lightOff;
		break;
	case kOVEN_LightOn:
		if(ui_oven_light_state == true)
		{
			break;
		}
		lv_obj_fade_in(guider_ui.ui_Oven_Img_Door, 0, 0);
		//TODO: Update Image of the Door on the menu
		ui_oven_light_state = kOVEN_LightOn;
		break;
	}
}

void ui_oven_set_state(OVEN_State_T state)
{
	if(state == kOVEN_Start)
	{
		lv_label_set_text(guider_ui.ui_Oven_Btn_State_label, "START");
		ui_oven_door(kOVEN_DoorClose);
	}
	else if (state == kOVEN_Stop)
	{
		lv_label_set_text(guider_ui.ui_Oven_Btn_State_label,  "STOP");
		ui_oven_door(kOVEN_DoorOpen);
	}
}

/*******************************************************************************
 * Static function
 ******************************************************************************/

uint16_t lv_obj_get_tile_id(lv_obj_t * obj)
{
	lv_obj_t * tile_obj =lv_tileview_get_tile_act(obj);

	lv_coord_t tx = lv_obj_get_x(tile_obj);
	lv_coord_t ty = lv_obj_get_y(tile_obj);

	uint32_t i;
	for(i = 0; i < lv_obj_get_child_cnt(obj); i++)
	{
		tile_obj = lv_obj_get_child(obj, i);
		lv_coord_t x = lv_obj_get_x(tile_obj);
		lv_coord_t y = lv_obj_get_y(tile_obj);
		if(x == tx && y == ty) {
			return 8 - i;
		}
	}
}

static void oven_wheel_scroll_event_cb(lv_event_t * e)
{
	lv_obj_t * cont = lv_event_get_target(e);

	lv_area_t cont_a;
	lv_obj_get_coords(cont, &cont_a);
	lv_coord_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;

	int32_t inv = lv_obj_get_style_flex_track_place(cont, 0) == LV_FLEX_ALIGN_START ? 1 : -1;
	lv_coord_t y_min = LV_COORD_MAX;
	lv_obj_t * y_min_obj = NULL;
	lv_coord_t r = lv_obj_get_height(cont) * 55 / 100;
	uint32_t i;
	uint32_t child_cnt = lv_obj_get_child_cnt(cont);
	for(i = 0; i < child_cnt; i++) {
		lv_obj_t * child = lv_obj_get_child(cont, i);
		if(lv_obj_has_flag(child, LV_OBJ_FLAG_FLOATING)) continue;
		lv_area_t child_a;
		lv_obj_get_coords(child, &child_a);

		lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;
		lv_coord_t diff_y = child_y_center - cont_y_center;
		diff_y = LV_ABS(diff_y);
		if(diff_y < y_min) {
			y_min = diff_y;
			y_min_obj = child;
		}

		/*Get the x of diff_y on a circle.*/
		lv_coord_t x;
		/*If diff_y is out of the circle use the last point of the circle (the radius)*/
		if(diff_y >= r) {
			x = r;
		}
		else {
			/*Use Pythagoras theorem to get x from radius and y*/
			uint32_t x_sqr = r * r - diff_y * diff_y;
			lv_sqrt_res_t res;
			lv_sqrt(x_sqr, &res, 0x8000);   /*Use lvgl's built in sqrt root function*/
			x = r - res.i;
		}

		/*Translate the item by the calculated X coordinate*/
		lv_obj_set_style_translate_x(child, inv * x, 0);
	}

	lv_obj_t * large_label = lv_event_get_user_data(e);
	lv_label_set_text(large_label, lv_label_get_text(y_min_obj));
}

static void ui_oven_anim_door(bool open, uint32_t delay)
{
	lv_anim_t * a;
	if(open)
	{
		/*Fade the first image to the background*/
		if(ui_oven_light_state == false)
		{
			lv_obj_fade_in(guider_ui.ui_Oven_Img_Door, FADE_ANIM_TIME, delay);
		}

		a = _ui_start_img_seq_anim(guider_ui.ui_Oven_Img_Door, oven_door, sizeof(oven_door) / sizeof(oven_door[0]), LV_DISP_DEF_REFR_PERIOD, false);
		a->act_time -= delay + FADE_ANIM_TIME;
	}
	else
	{
		a = _ui_start_img_seq_anim(guider_ui.ui_Oven_Img_Door, oven_door, sizeof(oven_door) / sizeof(oven_door[0]), LV_DISP_DEF_REFR_PERIOD, true);
		a->act_time -= delay;
	}
}

