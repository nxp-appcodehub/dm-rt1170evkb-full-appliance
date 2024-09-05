/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_LARGE_CONST
#define LV_ATTRIBUTE_LARGE_CONST
#endif

#ifndef LV_ATTRIBUTE_IMG__OVEN_MENU_DOOR_9_257X269
#define LV_ATTRIBUTE_IMG__OVEN_MENU_DOOR_9_257X269
#endif

extern const LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG__OVEN_MENU_DOOR_9_257X269 unsigned char _oven_menu_door_9_257x269_map[];
const LV_ATTRIBUTE_LARGE_CONST lv_img_dsc_t _oven_menu_door_9_257x269 = {
  .header.always_zero = 0,
  .header.w = 257,
  .header.h = 269,
  .data_size = 69133 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = _oven_menu_door_9_257x269_map,
};
