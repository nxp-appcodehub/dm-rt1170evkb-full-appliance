#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG__OVEN_LIGHT_MENU_ALPHA_257X269
#define LV_ATTRIBUTE_IMG__OVEN_LIGHT_MENU_ALPHA_257X269
#endif

extern const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG__OVEN_LIGHT_MENU_ALPHA_257X269 unsigned char _oven_light_menu_alpha_257x269_map[];

const lv_img_dsc_t _oven_light_menu_alpha_257x269 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 257,
  .header.h = 269,
  .data_size = 69133 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = _oven_light_menu_alpha_257x269_map,
};
