/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#include "ui_Hood.h"
#include "ui_Aircon.h"

#include "ui_Oven.h"

void events_init(lv_ui *ui)
{
}

void video_play(lv_ui *ui)
{

}

static void ui_Home_ui_Btn_Hood_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.ui_Hood_del == true)
				setup_scr_ui_Hood(&guider_ui);
			lv_scr_load_anim(guider_ui.ui_Hood, LV_SCR_LOAD_ANIM_NONE, 100, 100, false);
			guider_ui.ui_Home_del = false;
		}
	}
		break;
	default:
		break;
	}
}

static void ui_Home_ui_Btn_Aircon_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.ui_Aircon_del == true)
				setup_scr_ui_Aircon(&guider_ui);
			lv_scr_load_anim(guider_ui.ui_Aircon, LV_SCR_LOAD_ANIM_NONE, 100, 100, false);
			guider_ui.ui_Home_del = false;
		}
	}
		break;
	default:
		break;
	}
}

static void ui_Home_ui_Btn_Oven_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.ui_Oven_del == true)
				setup_scr_ui_Oven(&guider_ui);
			lv_scr_load_anim(guider_ui.ui_Oven, LV_SCR_LOAD_ANIM_NONE, 100, 100, false);
			guider_ui.ui_Home_del = false;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_ui_Home(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_Home_ui_Btn_Hood, ui_Home_ui_Btn_Hood_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Home_ui_Btn_Aircon, ui_Home_ui_Btn_Aircon_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Home_ui_Btn_Oven, ui_Home_ui_Btn_Oven_event_handler, LV_EVENT_ALL, ui);
}

static void ui_Hood_ui_Slider_Hood_Fan_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		ui_hood_set_fan_speed(lv_slider_get_value(obj));
	}
		break;
	default:
		break;
	}
}

static void ui_Hood_sw_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		ui_hood_set_light(lv_obj_has_state(obj, LV_STATE_CHECKED));
	}
		break;
	default:
		break;
	}
}

static void ui_Hood_ui_Btn_Back1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.ui_Home_del == true)
				setup_scr_ui_Home(&guider_ui);
			lv_scr_load_anim(guider_ui.ui_Home, LV_SCR_LOAD_ANIM_NONE, 100, 100, false);
			guider_ui.ui_Hood_del = false;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_ui_Hood(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_Hood_ui_Slider_Hood_Fan, ui_Hood_ui_Slider_Hood_Fan_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Hood_sw_1, ui_Hood_sw_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Hood_ui_Btn_Back1, ui_Hood_ui_Btn_Back1_event_handler, LV_EVENT_ALL, ui);
}

static void ui_Aircon_Btn_TempUp_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		ui_aircon_update_temp (0, kAIRCON_TempUp);
	}
		break;
	default:
		break;
	}
}

static void ui_Aircon_Btn_TempDown_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		ui_aircon_update_temp (0, kAIRCON_TempDown);
	}
		break;
	default:
		break;
	}
}

static void ui_Aircon_Roller_Mode_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		ui_aircon_set_mode(lv_roller_get_selected(obj));
	}
		break;
	default:
		break;
	}
}

static void ui_Aircon_Btn_Swing_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		ui_aircon_swing(lv_obj_has_state(obj, LV_STATE_CHECKED));
	}
		break;
	default:
		break;
	}
}

static void ui_Aircon_Slider_Fan_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		ui_aricon_set_fan_speed(lv_slider_get_value(obj));
	}
		break;
	default:
		break;
	}
}

static void ui_Aircon_Btn_TimerUp_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		ui_aircon_update_timer(0,kAIRCON_TimerUp);
	}
		break;
	default:
		break;
	}
}

static void ui_Aircon_Btn_TimerDown_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		ui_aircon_update_timer(0,kAIRCON_TimerDown);
	}
		break;
	default:
		break;
	}
}

static void ui_Aircon_ui_Btn_Back2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.ui_Home_del == true)
				setup_scr_ui_Home(&guider_ui);
			lv_scr_load_anim(guider_ui.ui_Home, LV_SCR_LOAD_ANIM_NONE, 100, 100, false);
			guider_ui.ui_Aircon_del = false;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_ui_Aircon(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_Aircon_Btn_TempUp, ui_Aircon_Btn_TempUp_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Aircon_Btn_TempDown, ui_Aircon_Btn_TempDown_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Aircon_Roller_Mode, ui_Aircon_Roller_Mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Aircon_Btn_Swing, ui_Aircon_Btn_Swing_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Aircon_Slider_Fan, ui_Aircon_Slider_Fan_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Aircon_Btn_TimerUp, ui_Aircon_Btn_TimerUp_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Aircon_Btn_TimerDown, ui_Aircon_Btn_TimerDown_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Aircon_ui_Btn_Back2, ui_Aircon_ui_Btn_Back2_event_handler, LV_EVENT_ALL, ui);
}

static void ui_Oven_Btn_ModeLeft_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		ui_oven_set_mode(kOVEN_ModeNull, kOVEN_ModeDirLeft);
	}
		break;
	default:
		break;
	}
}

static void ui_Oven_Btn_ModeRigth_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		ui_oven_set_mode(kOVEN_ModeNull, kOVEN_ModeDirRight);
	}
		break;
	default:
		break;
	}
}

static void ui_Oven_Btn_State_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		ui_oven_set_state(!lv_obj_has_state(obj, LV_STATE_CHECKED));
	}
		break;
	default:
		break;
	}
}

static void ui_Oven_ui_Btn_Back3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.ui_Home_del == true)
				setup_scr_ui_Home(&guider_ui);
			lv_scr_load_anim(guider_ui.ui_Home, LV_SCR_LOAD_ANIM_NONE, 100, 100, false);
			guider_ui.ui_Oven_del = false;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_ui_Oven(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_Oven_Btn_ModeLeft, ui_Oven_Btn_ModeLeft_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Oven_Btn_ModeRigth, ui_Oven_Btn_ModeRigth_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Oven_Btn_State, ui_Oven_Btn_State_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_Oven_ui_Btn_Back3, ui_Oven_ui_Btn_Back3_event_handler, LV_EVENT_ALL, ui);
}
