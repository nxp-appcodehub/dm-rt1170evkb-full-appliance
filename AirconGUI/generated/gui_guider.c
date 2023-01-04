/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void init_scr_del_flag(lv_ui *ui){
	ui->ui_Oven_del = true;
	ui->ui_Aircon_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_ui_Oven(ui);
	lv_scr_load(ui->ui_Oven);
}
