#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG__MENU_BG_ALPHA_1280X720
#define LV_ATTRIBUTE_IMG__MENU_BG_ALPHA_1280X720
#endif

extern const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG__MENU_BG_ALPHA_1280X720 unsigned char _menu_bg_alpha_1280x720_map[];

const lv_img_dsc_t _menu_bg_alpha_1280x720 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 1280,
  .header.h = 720,
  .data_size = 921600 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = _menu_bg_alpha_1280x720_map,
};
