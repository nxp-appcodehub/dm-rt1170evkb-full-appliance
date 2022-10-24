/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */
#ifndef GUIDER_FONTS_H
#define GUIDER_FONTS_H
#ifdef __cplusplus
extern "C" {
#endif

#if LVGL_VERSION_MAJOR == 7
#include "lv_font/lv_font.h"
#else
#include "font/lv_font.h"
#endif

LV_FONT_DECLARE(lv_font_Amiko_Regular_18)
LV_FONT_DECLARE(lv_font_simsun_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_120)
LV_FONT_DECLARE(lv_font_Antonio_Regular_21)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_26)
LV_FONT_DECLARE(lv_font_Antonio_Regular_15)
LV_FONT_DECLARE(lv_font_simsun_12)
LV_FONT_DECLARE(lv_font_Antonio_Regular_20)
LV_FONT_DECLARE(lv_font_Antonio_Regular_12)
LV_FONT_DECLARE(lv_font_Antonio_Regular_19)


#ifdef __cplusplus
}
#endif
#endif
