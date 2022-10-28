/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <ui_Aircon.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void ui_aircon_swing_anim_start(uint32_t delay);
void ui_aircon_set_fan_speed(uint32_t frame_time);

void ui_aircon_swing_anim_close(void);
lv_anim_t * _ui_start_img_seq_anim(lv_obj_t * obj, const lv_img_dsc_t * imgs[], uint32_t img_cnt, uint32_t period_time, bool backward);
static void img_seq_anim_cb(void * var, int32_t v);
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t AirconTemp = 25;
uint32_t TimerHour = 1;
int32_t TimerMin = 15;

/*Declare Image for swing animation*/
LV_IMG_DECLARE(_aircon_swing_1_632x113);
LV_IMG_DECLARE(_aircon_swing_2_632x113);
LV_IMG_DECLARE(_aircon_swing_3_632x113);
LV_IMG_DECLARE(_aircon_swing_4_632x113);
LV_IMG_DECLARE(_aircon_swing_5_632x113);
LV_IMG_DECLARE(_aircon_swing_6_632x113);
LV_IMG_DECLARE(_aircon_swing_7_632x113);
LV_IMG_DECLARE(_aircon_swing_8_632x113);
LV_IMG_DECLARE(_aircon_swing_9_632x113);
LV_IMG_DECLARE(_aircon_swing_10_632x113);
LV_IMG_DECLARE(_aircon_swing_11_632x113);
LV_IMG_DECLARE(_aircon_swing_12_632x113);
LV_IMG_DECLARE(_aircon_swing_13_632x113);
LV_IMG_DECLARE(_aircon_swing_14_632x113);
LV_IMG_DECLARE(_aircon_swing_15_632x113);

static const lv_img_dsc_t * aircon_swing[] = {&_aircon_swing_1_632x113, &_aircon_swing_2_632x113, &_aircon_swing_3_632x113,
		&_aircon_swing_4_632x113, &_aircon_swing_5_632x113, &_aircon_swing_6_632x113,
		&_aircon_swing_7_632x113, &_aircon_swing_8_632x113, &_aircon_swing_9_632x113,
		&_aircon_swing_10_632x113, &_aircon_swing_11_632x113, &_aircon_swing_12_632x113,
		&_aircon_swing_13_632x113, &_aircon_swing_14_632x113, &_aircon_swing_15_632x113};

/*Declare images for cool animation*/
LV_IMG_DECLARE(_aircon_cool_1_92x102);
LV_IMG_DECLARE(_aircon_cool_2_92x102);
LV_IMG_DECLARE(_aircon_cool_3_92x102);
LV_IMG_DECLARE(_aircon_cool_4_92x102);
LV_IMG_DECLARE(_aircon_cool_5_92x102);
LV_IMG_DECLARE(_aircon_cool_6_92x102);

static const lv_img_dsc_t * aircon_cool[] = {&_aircon_cool_1_92x102, &_aircon_cool_2_92x102, &_aircon_cool_3_92x102,
		&_aircon_cool_4_92x102, &_aircon_cool_5_92x102, &_aircon_cool_6_92x102};

/*Declare images for fan animation*/
LV_IMG_DECLARE(_aircon_fan_1_98x98);
LV_IMG_DECLARE(_aircon_fan_2_98x98);
LV_IMG_DECLARE(_aircon_fan_3_98x98);
LV_IMG_DECLARE(_aircon_fan_4_98x98);
LV_IMG_DECLARE(_aircon_fan_5_98x98);
LV_IMG_DECLARE(_aircon_fan_6_98x98);

static const lv_img_dsc_t * aircon_fan[] = {&_aircon_fan_1_98x98, &_aircon_fan_2_98x98, &_aircon_fan_3_98x98,
		&_aircon_fan_4_98x98, &_aircon_fan_5_98x98, &_aircon_fan_6_98x98};

/*Declare images for Fan state*/
LV_IMG_DECLARE(_icn_fan_low_31x27);
LV_IMG_DECLARE(_icn_fan_high_31x27);

/*Declare images for compresor*/
LV_IMG_DECLARE(_icn_cool_27x31);
LV_IMG_DECLARE(_icn_dry_27x31);
LV_IMG_DECLARE(_icn_fan_27x31);

/*******************************************************************************
 * Function
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state)
{
	if(temp)
	{
		AirconTemp = temp;
	}
	else
	{
		switch (state)
		{
		case kAIRCON_TempDown:
			AirconTemp--;
			break;
		case kAIRCON_TempUp:
			AirconTemp++;
			break;
		}
	}
	lv_label_set_text_fmt(guider_ui.ui_Aircon_Label_Temp, "%02d",AirconTemp);

}

void ui_aircon_update_timer (uint32_t hour,  AIRCON_Timer_T state)
{
	if(hour)
	{
		TimerHour = hour;
	}
	else
	{
		switch (state)
		{
		case kAIRCON_TimerDown:
			TimerMin-=15;
			break;
		case kAIRCON_TimerUp:
			TimerMin+=15;
			break;
		}
	}

	if(TimerMin < 0)
	{
		TimerMin = 45;
		TimerHour--;
	}
	else if (TimerMin == 60)
	{
		TimerMin = 0;
		TimerHour++;
	}

	lv_label_set_text_fmt(guider_ui.ui_Aircon_Label_TimerHour, "%02d",TimerHour);
	lv_label_set_text_fmt(guider_ui.ui_Aircon_Label_TimerMin, "%02d",TimerMin);
}


void ui_aircon_swing (bool state)
{
	if(state == kAIRCON_SwingOff)
	{
		ui_aircon_swing_anim_close();
	}
	else if (state == kAIRCON_SwingOn)
	{
		ui_aircon_swing_anim_start(0);
	}
}

void ui_aricon_set_fan_speed (AIRCON_Fan_Speed_T speed)
{
	uint32_t frame_time;

	switch(speed)
	{
	case kAIRCON_FanLow:
		frame_time = 125;
		lv_label_set_text(guider_ui.ui_Aircon_Label_FanState, "LOW");
		lv_img_set_src(guider_ui.ui_Aircon_Img_FanSt, &_icn_fan_low_31x27);
		break;
	case kAIRCON_FanMedium:
		frame_time = 100;
		lv_label_set_text(guider_ui.ui_Aircon_Label_FanState, "MEDIUM");
		lv_img_set_src(guider_ui.ui_Aircon_Img_FanSt, &_icn_fan_low_31x27);
		break;
	case kAIRCON_FanHigh:
		frame_time = 75;
		lv_label_set_text(guider_ui.ui_Aircon_Label_FanState, "HIGH");
		lv_img_set_src(guider_ui.ui_Aircon_Img_FanSt, &_icn_fan_high_31x27);
		break;
	}

	lv_anim_t * a;
	ui_aircon_set_fan_speed(frame_time);
}

void ui_aircon_set_mode (AIRCON_Mode_T mode)
{
	switch(mode)
	{
	case kAIRCON_ModeCool:
		lv_label_set_text(guider_ui.ui_Aircon_Label_On, "ON");
		lv_img_set_src(guider_ui.ui_Aircon_Img_Comp, &_icn_cool_27x31);
		lv_obj_fade_in(guider_ui.ui_Aircon_Img_Cool, FADE_ANIM_TIME, 0);
		break;
	case kAIRCON_ModeDry:
		lv_label_set_text(guider_ui.ui_Aircon_Label_On, "ON");
		lv_img_set_src(guider_ui.ui_Aircon_Img_Comp, &_icn_dry_27x31);
		lv_obj_fade_in(guider_ui.ui_Aircon_Img_Cool, FADE_ANIM_TIME, 0);
		break;
	case kAIRCON_ModeFan:
		lv_label_set_text(guider_ui.ui_Aircon_Label_On, "OFF");
		lv_img_set_src(guider_ui.ui_Aircon_Img_Comp, &_icn_fan_27x31);
		lv_obj_fade_out(guider_ui.ui_Aircon_Img_Cool, FADE_ANIM_TIME, 0);
		break;
	}

}

void ui_aircon_star_cool(void)
{
	lv_anim_t * a;
	a = _ui_start_img_seq_anim(guider_ui.ui_Aircon_Img_Cool, aircon_cool, sizeof(aircon_cool) / sizeof(aircon_cool[0]), 100, false);
	a->repeat_cnt = LV_ANIM_REPEAT_INFINITE;
}

void ui_aircon_process_command (unsigned short cmd_id)
{
	switch (cmd_id)
	{
	case kVIT_IncreaseTemp:
		ui_aircon_update_temp(0, kAIRCON_TempUp);
		break;
	case kVIT_DecreaseTemp:
		ui_aircon_update_temp(0, kAIRCON_TempDown);
		break;
	case kVIT_SetTemp19:
		ui_aircon_update_temp(19, 0);
		break;
	case kVIT_SetFanToHigh:
		ui_aricon_set_fan_speed(kAIRCON_FanHigh);
		lv_slider_set_value(guider_ui.ui_Aircon_Slider_Fan,kAIRCON_FanHigh, 0);
		break;
	case kVIT_SetFanToMedium:
		ui_aricon_set_fan_speed(kAIRCON_FanMedium);
		lv_slider_set_value(guider_ui.ui_Aircon_Slider_Fan,kAIRCON_FanMedium, 0);
		break;
	case kVIT_SetFanToLow:
		ui_aricon_set_fan_speed(kAIRCON_FanLow);
		lv_slider_set_value(guider_ui.ui_Aircon_Slider_Fan,kAIRCON_FanLow, 0);
		break;
	case kVIT_SwingOn:
		ui_aircon_swing(kAIRCON_SwingOn);
		lv_obj_add_state(guider_ui.ui_Aircon_Btn_Swing,LV_STATE_CHECKED);
		break;
	case kVIT_SwingOff:
		ui_aircon_swing(kAIRCON_SwingOff);
		lv_obj_clear_state(guider_ui.ui_Aircon_Btn_Swing,LV_STATE_CHECKED);
		break;
	case kVIT_SetModeCool:
		ui_aircon_set_mode(kAIRCON_ModeCool);
		lv_roller_set_selected(guider_ui.ui_Aircon_Roller_Mode, kAIRCON_ModeCool, 0);
		break;
	case kVIT_SetModeDry:
		ui_aircon_set_mode(kAIRCON_ModeDry);
		lv_roller_set_selected(guider_ui.ui_Aircon_Roller_Mode, kAIRCON_ModeDry, 0);
		break;
	case kVIT_SetModeFan:
		ui_aircon_set_mode(kAIRCON_ModeFan);
		lv_roller_set_selected(guider_ui.ui_Aircon_Roller_Mode, kAIRCON_ModeFan, 0);
		break;
	case kVIT_SetTimer4:
		ui_aircon_update_timer(4, 0);
		break;
	}
}

/*******************************************************************************
 * Static function
 ******************************************************************************/

void ui_aircon_swing_anim_start(uint32_t delay)
{
	lv_anim_t * a = NULL;

	if(delay == 0) {
		uint32_t dim = sizeof(aircon_swing) / sizeof(aircon_swing[0]);
		uint32_t i;
		for(i = 0; i < dim; i++) {
			if(lv_img_get_src(guider_ui.ui_Aircon_Img_Swing) == aircon_swing[i]) {
				break;
			}
		}
		if(i == dim) i = 0;
		a = _ui_start_img_seq_anim(guider_ui.ui_Aircon_Img_Swing, aircon_swing, sizeof(aircon_swing) / sizeof(aircon_swing[0]), 90, false);
		a->current_value = i;
		a->act_time = i * 90;
		a->repeat_delay = 240;
		a->playback_delay = 240;
		lv_img_set_src(guider_ui.ui_Aircon_Img_Swing, aircon_swing[i]);
	} else {
		a = _ui_start_img_seq_anim(guider_ui.ui_Aircon_Img_Swing, aircon_swing, sizeof(aircon_swing) / sizeof(aircon_swing[0]), 90, false);
		a->act_time = -delay;
		a->repeat_delay = 240;
		a->playback_delay = 240;
	}

	a->playback_time = a->time;
	a->repeat_cnt = LV_ANIM_REPEAT_INFINITE;
}

void ui_aircon_set_fan_speed(uint32_t frame_time)
{
	lv_anim_t * a;
	a = _ui_start_img_seq_anim(guider_ui.ui_Aircon_Img_Fan, aircon_fan, sizeof(aircon_fan) / sizeof(aircon_fan[0]), frame_time, false);
	a->repeat_cnt = LV_ANIM_REPEAT_INFINITE;
}

void ui_aircon_swing_anim_close(void)
{
	uint32_t i;
	for(i = 0; i < sizeof(aircon_swing) / sizeof(aircon_swing[0]); i++) {
		if(lv_img_get_src(guider_ui.ui_Aircon_Img_Swing) == aircon_swing[i]) {
			i++;
			_ui_start_img_seq_anim(guider_ui.ui_Aircon_Img_Swing, aircon_swing, i, 30, true);
			break;
		}
	}
}

lv_anim_t * _ui_start_img_seq_anim(lv_obj_t * obj, const lv_img_dsc_t * imgs[], uint32_t img_cnt, uint32_t period_time, bool backward)
{
	obj->user_data = imgs;
	lv_anim_t a;
	lv_anim_init(&a);
	if(backward)  lv_anim_set_values(&a, img_cnt - 1, 0);
	else lv_anim_set_values(&a, 0, img_cnt - 1);
	lv_anim_set_exec_cb(&a, img_seq_anim_cb);
	lv_anim_set_var(&a, obj);
	lv_anim_set_user_data(&a, obj);
	lv_anim_set_time(&a, img_cnt * period_time);
	return lv_anim_start(&a);

}

static void img_seq_anim_cb(void * var, int32_t v)
{
	lv_obj_t * obj = var;
	lv_img_dsc_t ** imgs = obj->user_data;
	lv_img_set_src(obj, imgs[v]);
}

