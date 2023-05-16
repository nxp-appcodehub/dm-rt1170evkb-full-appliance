/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <ui_Hood.h>
#include "ui_Animations.h"
#include "gui_guider.h"


LV_IMG_DECLARE(_hood_light_901x460);
LV_IMG_DECLARE(_hood_menu_light_439x217);
LV_IMG_DECLARE(_hood_bg_1280x720);
LV_IMG_DECLARE(_text_fan_param_198x26);
LV_IMG_DECLARE(_smog_1_133X472);
LV_IMG_DECLARE(_smog_2_133X630);


bool ui_hood_light_state = kHOOD_lightOff;

void ui_hood_init (void)
{
	setup_scr_ui_Hood(&guider_ui);
	guider_ui.ui_Hood_del = false;

	ui_hood_set_light(kHOOD_lightOff);
	ui_hood_set_fan_speed (kHOOD_FanLow);
	lv_obj_set_style_opa(guider_ui.ui_Hood_Lottie_Mic, LV_OPA_TRANSP, 0);
	lv_obj_clear_flag(guider_ui.ui_Hood_ui_Group_Smog1, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_clear_flag(guider_ui.ui_Hood_ui_Group_Smog2, LV_OBJ_FLAG_SCROLLABLE);

	lv_obj_set_height(guider_ui.ui_Hood_ui_Image_Smog11, 944);
	lv_obj_set_height(guider_ui.ui_Hood_ui_Image_Smog12, 1260);

	lv_obj_set_height(guider_ui.ui_Hood_ui_Image_Smog21, 944);
	lv_obj_set_height(guider_ui.ui_Hood_ui_Image_Smog22, 1260);

	lv_obj_set_height(guider_ui.ui_Home_ui_Image_Smog_menu_11, 944);
	lv_obj_set_height(guider_ui.ui_Home_ui_Image_Smog_menu_12, 1260);

	lv_obj_set_height(guider_ui.ui_Home_ui_Image_Smog_menu_21, 944);
	lv_obj_set_height(guider_ui.ui_Home_ui_Image_Smog_menu_22, 1260);

}
void ui_hood_set_light(HOOD_Light_T state)
{
	switch (state)
	{
	case kHOOD_lightOff:
		lv_obj_fade_out(guider_ui.ui_Hood_ui_Image_Hood_Light, 0, 0);
		ui_hood_light_state = kHOOD_LightOn;
		lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Light_Text, "Off\n");
		lv_obj_fade_out(guider_ui.ui_Home_ui_Image_Hood_Light_Menu, 0, 0);
		break;
	case kHOOD_LightOn:
		lv_obj_fade_in(guider_ui.ui_Hood_ui_Image_Hood_Light, 0, 0);
		ui_hood_light_state = kHOOD_lightOff;
		lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Light_Text, "On\n");
		lv_obj_fade_in(guider_ui.ui_Home_ui_Image_Hood_Light_Menu, 0, 0);
		break;
	}
}

void ui_hood_set_fan_speed (HOOD_Fan_Speed_T speed)
{
	if( kHOOD_FanOff == speed || kHOOD_FanLow == speed){

		if(lv_obj_get_style_opa(guider_ui.ui_Hood_ui_Group_Smog1, 0) != LV_OPA_COVER) {
			lv_obj_fade_in(guider_ui.ui_Hood_ui_Group_Smog1, FADE_ANIM_TIME, 0);
			lv_obj_fade_in(guider_ui.ui_Home_ui_Group_Smog_menu_1, FADE_ANIM_TIME, 0);
		}
		if(lv_obj_get_style_opa(guider_ui.ui_Hood_ui_Group_Smog2, 0) != LV_OPA_COVER) {
			lv_obj_fade_in(guider_ui.ui_Hood_ui_Group_Smog2, FADE_ANIM_TIME, 0);
			lv_obj_fade_in(guider_ui.ui_Home_ui_Group_Smog_menu_2, FADE_ANIM_TIME, 0);
		}
	}
	switch(speed)
	{
	case kHOOD_FanOff:
		_ui_smog1_anim(guider_ui.ui_Hood_ui_Image_Smog11, false);
		_ui_smog2_anim(guider_ui.ui_Hood_ui_Image_Smog12, false);
		_ui_smog1_anim(guider_ui.ui_Hood_ui_Image_Smog21, false);
		_ui_smog2_anim(guider_ui.ui_Hood_ui_Image_Smog22, false);

		_ui_smog1_anim(guider_ui.ui_Home_ui_Image_Smog_menu_11, false);
		_ui_smog2_anim(guider_ui.ui_Home_ui_Image_Smog_menu_12, false);
		_ui_smog1_anim(guider_ui.ui_Home_ui_Image_Smog_menu_21, false);
		_ui_smog2_anim(guider_ui.ui_Home_ui_Image_Smog_menu_22, false);
		lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Fan_Text, "Off\n");
		break;
	case kHOOD_FanLow:
		_ui_smog1_anim(guider_ui.ui_Hood_ui_Image_Smog11, true);
		_ui_smog2_anim(guider_ui.ui_Hood_ui_Image_Smog12, true);
		_ui_smog1_anim(guider_ui.ui_Hood_ui_Image_Smog21, true);
		_ui_smog2_anim(guider_ui.ui_Hood_ui_Image_Smog22, true);

		_ui_smog1_anim(guider_ui.ui_Home_ui_Image_Smog_menu_11, true);
		_ui_smog2_anim(guider_ui.ui_Home_ui_Image_Smog_menu_12, true);
		_ui_smog1_anim(guider_ui.ui_Home_ui_Image_Smog_menu_21, true);
		_ui_smog2_anim(guider_ui.ui_Home_ui_Image_Smog_menu_22, true);
		lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Fan_Text, "Low\n");
		break;
	case kHOOD_FanHigh:
		lv_obj_fade_out(guider_ui.ui_Hood_ui_Group_Smog1, FADE_ANIM_TIME, 0);
		lv_obj_fade_out(guider_ui.ui_Hood_ui_Group_Smog2, FADE_ANIM_TIME, 0);
		lv_obj_fade_out(guider_ui.ui_Home_ui_Group_Smog_menu_1, FADE_ANIM_TIME, 0);
		lv_obj_fade_out(guider_ui.ui_Home_ui_Group_Smog_menu_2, FADE_ANIM_TIME, 0);

		lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Fan_Text, "High\n");
		break;
	}
}

void _ui_smog1_anim(lv_obj_t * obj, bool fast)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, fast ? 5000 : 15000);
    lv_anim_set_var(&PropertyAnimation_0, obj);
    lv_anim_set_exec_cb(&PropertyAnimation_0, lv_obj_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -472);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);

    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);

    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

void _ui_smog2_anim(lv_obj_t * obj, bool fast)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, fast ? 9000 : 27000);
    lv_anim_set_var(&PropertyAnimation_0, obj);
    lv_anim_set_exec_cb(&PropertyAnimation_0, lv_obj_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -630);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);

    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);

    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

void ui_hood_process_command(unsigned short cmd_id){
	switch (cmd_id)
		{
		case kVIT_Light_On:
			ui_hood_set_light(kHOOD_LightOn);
			lv_obj_add_state(guider_ui.ui_Hood_sw_1,LV_STATE_CHECKED);
			lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Light_Text, "On\n");
			break;
		case kVIT_Light_Off:
			ui_hood_set_light(kHOOD_lightOff);
			lv_obj_clear_state(guider_ui.ui_Hood_sw_1,LV_STATE_CHECKED);
			lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Light_Text, "Off\n");
			break;
		case kVIT_SetFanOff:
			ui_hood_set_fan_speed (kHOOD_FanOff);
			lv_slider_set_value(guider_ui.ui_Hood_ui_Slider_Hood_Fan,kHOOD_FanOff, 0);
			lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Fan_Text, "Off\n");
			break;
		case kVIT_SetFanLow:
			ui_hood_set_fan_speed (kHOOD_FanLow);
			lv_slider_set_value(guider_ui.ui_Hood_ui_Slider_Hood_Fan,kHOOD_FanLow, 0);
			lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Fan_Text, "Low\n");
			break;
		case kVIT_SetFanHigh:
			ui_hood_set_fan_speed (kHOOD_FanHigh);
			lv_slider_set_value(guider_ui.ui_Hood_ui_Slider_Hood_Fan,kHOOD_FanHigh, 0);
			lv_label_set_text(guider_ui.ui_Home_ui_Label_Hood_Fan_Text, "High\n");
			break;
		}
}
