/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef UI_ANIMATIONS_H_
#define UI_ANIMATIONS_H_

#include "gui_guider.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DARK_PANEL_ANIM_TIME	500
#define FADE_ANIM_TIME			300
#define SCREEN_TRANSITION_TIME	600

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

lv_anim_t * _ui_start_img_seq_anim(lv_obj_t * obj, const lv_img_dsc_t * imgs[], uint32_t img_cnt, uint32_t period_time, bool backward);

#endif /* UI_ANIMATIONS_H_ */
