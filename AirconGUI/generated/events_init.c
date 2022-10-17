/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "ui_Aircon.h"



void events_init(lv_ui *ui)
{
}

static void ui_Aircon_btn_1_event_handler(lv_event_t *e)
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

static void ui_Aircon_Sw_Swing_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		ui_aircon_swing(lv_obj_has_state(obj, LV_STATE_CHECKED));
	}
		break;
	default:
		break;
	}
}

void events_init_ui_Aircon(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_Aircon_btn_1, ui_Aircon_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->ui_Aircon_Sw_Swing, ui_Aircon_Sw_Swing_event_handler, LV_EVENT_ALL, NULL);
}
