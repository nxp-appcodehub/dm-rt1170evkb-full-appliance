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
void ui_aircon_swing_anim_close(void);
lv_anim_t * _ui_start_img_seq_anim(lv_obj_t * obj, const lv_img_dsc_t * imgs[], uint32_t img_cnt, uint32_t period_time, bool backward);
static void img_seq_anim_cb(void * var, int32_t v);
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t AirconTemp = 25;

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

/*******************************************************************************
 * Function
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state)
{
	if(temp != 0)
	{
		AirconTemp = temp;
	}
	else
	{
		if(state == kAIRCON_TempDown)
		{
			AirconTemp--;
		}
		else if(state == kAIRCON_TempUp)
		{
			AirconTemp++;
		}
	}
	lv_label_set_text_fmt(guider_ui.ui_Aircon_Label_Temp, "%02d",AirconTemp);

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

