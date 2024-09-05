#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG__NXP_ALPHA_75X27
#define LV_ATTRIBUTE_IMG__NXP_ALPHA_75X27
#endif

extern const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG__NXP_ALPHA_75X27 unsigned char _nxp_alpha_75x27_map[];

const lv_img_dsc_t _nxp_alpha_75x27 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 75,
  .header.h = 27,
  .data_size = 2025 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = _nxp_alpha_75x27_map,
};
