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

#ifndef LV_ATTRIBUTE_IMG__OVEN_DOOR_04_704X720
#define LV_ATTRIBUTE_IMG__OVEN_DOOR_04_704X720
#endif

extern const LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG__OVEN_DOOR_04_704X720 unsigned char _oven_door_04_704x720_map[];

const LV_ATTRIBUTE_LARGE_CONST lv_img_dsc_t _oven_door_04_704x720 = {
  .header.always_zero = 0,
  .header.w = 704,
  .header.h = 720,
  .data_size = 506880 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = _oven_door_04_704x720_map,
};
