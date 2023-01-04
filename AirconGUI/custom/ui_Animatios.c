/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ui_Animations.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void img_seq_anim_cb(void * var, int32_t v);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/
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

/*******************************************************************************
 * Static function
 ******************************************************************************/
static void img_seq_anim_cb(void * var, int32_t v)
{
	lv_obj_t * obj = var;
	lv_img_dsc_t ** imgs = obj->user_data;
	lv_img_set_src(obj, imgs[v]);
}

