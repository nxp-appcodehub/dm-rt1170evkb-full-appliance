#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG__OVEN_LIGHT_ALPHA_704X720
#define LV_ATTRIBUTE_IMG__OVEN_LIGHT_ALPHA_704X720
#endif

extern const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG__OVEN_LIGHT_ALPHA_704X720 unsigned char _oven_light_alpha_704x720_map[];

const lv_img_dsc_t _oven_light_alpha_704x720 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 704,
  .header.h = 720,
  .data_size = 506880 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = _oven_light_alpha_704x720_map,
};
