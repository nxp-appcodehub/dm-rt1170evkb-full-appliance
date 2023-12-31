/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *ui_Home;
	bool ui_Home_del;
	lv_obj_t *ui_Home_ui_Image_Menu_Bg;
	lv_obj_t *ui_Home_ui_Group_Nxp_Logo;
	lv_obj_t *ui_Home_ui_Image_Nxp_Logo;
	lv_obj_t *ui_Home_ui_Label_Smart_Kitchen_Demo;
	lv_obj_t *ui_Home_ui_Group_Aircon_Content;
	lv_obj_t *ui_Home_ui_Image_Aircon_Text;
	lv_obj_t *ui_Home_ui_Aircon_Line;
	lv_obj_t *ui_Home_ui_Line_1;
	lv_obj_t *ui_Home_ui_Label_Aircon_Mode;
	lv_obj_t *ui_Home_ui_Label_Aircon_Fan;
	lv_obj_t *ui_Home_ui_Label_Aircon_Mode_Text;
	lv_obj_t *ui_Home_ui_Label_Aircon_Fan_Text;
	lv_obj_t *ui_Home_ui_Image_Aircon_Mode;
	lv_obj_t *ui_Home_ui_Image_Aircon_Fan;
	lv_obj_t *ui_Home_ui_Label_Aircon_Number1;
	lv_obj_t *ui_Home_ui_Label_Aircon_centigrade;
	lv_obj_t *ui_Home_ui_Image_Hood_Light_Menu;
	lv_obj_t *ui_Home_ui_Group_Oven_Content;
	lv_obj_t *ui_Home_ui_Image_Oven_Text;
	lv_obj_t *ui_Home_ui_Oven_Line;
	lv_obj_t *ui_Home_ui_Line_4;
	lv_obj_t *ui_Home_ui_Line_5;
	lv_obj_t *ui_Home_ui_Line_6;
	lv_obj_t *ui_Home_ui_Label_Time_Left;
	lv_obj_t *ui_Home_ui_Label_Status;
	lv_obj_t *ui_Home_ui_Label_Oven_Mode;
	lv_obj_t *ui_Home_ui_Label_Mystat;
	lv_obj_t *ui_Home_ui_Label_Mode1;
	lv_obj_t *ui_Home_ui_Image_Oven_Mode;
	lv_obj_t *ui_Home_ui_Label_Oven_Number1;
	lv_obj_t *ui_Home_ui_Label_Oven_TimeLeft;
	lv_obj_t *ui_Home_ui_Label_Oven_Mins;
	lv_obj_t *ui_Home_ui_Label_Oven_centigrade;
	lv_obj_t *ui_Home_ui_Group_Hood_Content;
	lv_obj_t *ui_Home_ui_Image_Hood_Text;
	lv_obj_t *ui_Home_ui_Hood_Line;
	lv_obj_t *ui_Home_ui_Line_2;
	lv_obj_t *ui_Home_ui_Line_3;
	lv_obj_t *ui_Home_ui_Label_Fan;
	lv_obj_t *ui_Home_ui_Label_Light;
	lv_obj_t *ui_Home_ui_Image_Hood_Light;
	lv_obj_t *ui_Home_ui_Image_Hood_Fan;
	lv_obj_t *ui_Home_ui_Label_Hood_Light_Text;
	lv_obj_t *ui_Home_ui_Label_Hood_Fan_Text;
	lv_obj_t *ui_Home_ui_Group_Info;
	lv_obj_t *ui_Home_ui_Image_Weather_Icon;
	lv_obj_t *ui_Home_ui_Line_7;
	lv_obj_t *ui_Home_ui_Line_8;
	lv_obj_t *ui_Home_ui_Label_Mic_Text;
	lv_obj_t *ui_Home_ui_Image_Hood_Menu;
	lv_obj_t *ui_Home_ui_Btn_Hood;
	lv_obj_t *ui_Home_ui_Btn_Hood_label;
	lv_obj_t *ui_Home_ui_Image_Aircon_Menu;
	lv_obj_t *ui_Home_ui_Image_Oven_Menu;
	lv_obj_t *ui_Home_ui_Btn_Aircon;
	lv_obj_t *ui_Home_ui_Btn_Aircon_label;
	lv_obj_t *ui_Home_ui_Btn_Oven;
	lv_obj_t *ui_Home_ui_Btn_Oven_label;
	lv_obj_t *ui_Home_ui_Image_Menu_Swing;
	lv_obj_t *ui_Home_ui_Group_Smog_menu_1;
	lv_obj_t *ui_Home_ui_Image_Smog_menu_11;
	lv_obj_t *ui_Home_ui_Image_Smog_menu_12;
	lv_obj_t *ui_Home_ui_Group_Smog_menu_2;
	lv_obj_t *ui_Home_ui_Image_Smog_menu_21;
	lv_obj_t *ui_Home_ui_Image_Smog_menu_22;
	lv_obj_t *ui_Hood;
	bool ui_Hood_del;
	lv_obj_t *ui_Hood_ui_Image_Hood_Bg;
	lv_obj_t *ui_Hood_ui_Image_Hood_Light;
	lv_obj_t *ui_Hood_ui_Group_Hood_Content;
	lv_obj_t *ui_Hood_ui_Hood_Line;
	lv_obj_t *ui_Hood_ui_Slider_Hood_Fan;
	lv_obj_t *ui_Hood_sw_1;
	lv_obj_t *ui_Hood_ui_Line2;
	lv_obj_t *ui_Hood_ui_Label_Light;
	lv_obj_t *ui_Hood_ui_Image_Hood_Text;
	lv_obj_t *ui_Hood_ui_Label_Fan;
	lv_obj_t *ui_Hood_ui_Group_Smog1;
	lv_obj_t *ui_Hood_ui_Image_Smog11;
	lv_obj_t *ui_Hood_ui_Image_Smog12;
	lv_obj_t *ui_Hood_ui_Group_Smog2;
	lv_obj_t *ui_Hood_ui_Image_Smog21;
	lv_obj_t *ui_Hood_ui_Image_Smog22;
	lv_obj_t *ui_Hood_Lottie_Mic;
	lv_obj_t *ui_Hood_Img_Label_Bg;
	lv_obj_t *ui_Hood_Label_Hood;
	lv_obj_t *ui_Hood_ui_Btn_Back1;
	lv_obj_t *ui_Hood_ui_Btn_Back1_label;
	lv_obj_t *ui_Aircon;
	bool ui_Aircon_del;
	lv_obj_t *ui_Aircon_Img_Bg;
	lv_obj_t *ui_Aircon_Img_Label_Bg;
	lv_obj_t *ui_Aircon_Label_Air;
	lv_obj_t *ui_Aircon_Img_Swing;
	lv_obj_t *ui_Aircon_Cont;
	lv_obj_t *ui_Aircon_line;
	lv_obj_t *ui_Aircon_Label_Temp;
	lv_obj_t *ui_Aircon_Btn_TempUp;
	lv_obj_t *ui_Aircon_Btn_TempUp_label;
	lv_obj_t *ui_Aircon_Label_SetTemp;
	lv_obj_t *ui_Aircon_Label_Cen;
	lv_obj_t *ui_Aircon_Btn_TempDown;
	lv_obj_t *ui_Aircon_Btn_TempDown_label;
	lv_obj_t *ui_Aircon_Img_TemUp;
	lv_obj_t *ui_Aircon_Img_TempDown;
	lv_obj_t *ui_Aircon_Roller_Mode;
	lv_obj_t *ui_Aircon_Btn_Swing;
	lv_obj_t *ui_Aircon_Btn_Swing_label;
	lv_obj_t *ui_Aircon_Label_Swing;
	lv_obj_t *ui_Aircon_line_1;
	lv_obj_t *ui_Aircon_line_2;
	lv_obj_t *ui_Aircon_line_3;
	lv_obj_t *ui_Aircon_line_4;
	lv_obj_t *ui_Aircon_line_5;
	lv_obj_t *ui_Aircon_Label_Timer;
	lv_obj_t *ui_Aircon_Label_Mode;
	lv_obj_t *ui_Aircon_Label_Fan;
	lv_obj_t *ui_Aircon_Slider_Fan;
	lv_obj_t *ui_Aircon_Label_Low;
	lv_obj_t *ui_Aircon_Label_Medium;
	lv_obj_t *ui_Aircon_Label_High;
	lv_obj_t *ui_Aircon_Label_Comp;
	lv_obj_t *ui_Aircon_Label_On;
	lv_obj_t *ui_Aircon_Img_Comp;
	lv_obj_t *ui_Aircon_Label_FanSt;
	lv_obj_t *ui_Aircon_Label_FanState;
	lv_obj_t *ui_Aircon_Img_FanSt;
	lv_obj_t *ui_Aircon_Btn_TimerUp;
	lv_obj_t *ui_Aircon_Btn_TimerUp_label;
	lv_obj_t *ui_Aircon_Img_TimerUp;
	lv_obj_t *ui_Aircon_Btn_TimerDown;
	lv_obj_t *ui_Aircon_Btn_TimerDown_label;
	lv_obj_t *ui_Aircon_Img_TimerDown;
	lv_obj_t *ui_Aircon_Label_TimerHour;
	lv_obj_t *ui_Aircon_Label_TimerPoints;
	lv_obj_t *ui_Aircon_Label_TimerMin;
	lv_obj_t *ui_Aircon_Img_Fan;
	lv_obj_t *ui_Aircon_Img_Cool;
	lv_obj_t *ui_Aircon_ui_Btn_Back2;
	lv_obj_t *ui_Aircon_ui_Btn_Back2_label;
	lv_obj_t *ui_Aircon_Lottie_Mic;
	lv_obj_t *ui_Oven;
	bool ui_Oven_del;
	lv_obj_t *ui_Oven_Img_Bg;
	lv_obj_t *ui_Oven_Img_Door;
	lv_obj_t *ui_Oven_Img_Fan;
	lv_obj_t *ui_Oven_Img_Label_Bg;
	lv_obj_t *ui_Oven_Label_Oven;
	lv_obj_t *ui_Oven_Group_Oven;
	lv_obj_t *ui_Oven_line;
	lv_obj_t *ui_Oven_Label_CurrTemp;
	lv_obj_t *ui_Oven_line_5;
	lv_obj_t *ui_Oven_line_4;
	lv_obj_t *ui_Oven_line_3;
	lv_obj_t *ui_Oven_line_2;
	lv_obj_t *ui_Oven_line_1;
	lv_obj_t *ui_Oven_Label_Temp;
	lv_obj_t *ui_Oven_Label_Cen;
	lv_obj_t *ui_Oven_Label_Status;
	lv_obj_t *ui_Oven_Label_CurrStat;
	lv_obj_t *ui_Oven_Label_Time;
	lv_obj_t *ui_Oven_Bar_Time;
	lv_obj_t *ui_Oven_Label_Mode;
	lv_obj_t *ui_Oven_Btn_ModeLeft;
	lv_obj_t *ui_Oven_Btn_ModeLeft_label;
	lv_obj_t *ui_Oven_Btn_ModeRigth;
	lv_obj_t *ui_Oven_Btn_ModeRigth_label;
	lv_obj_t *ui_Oven_Btn_State;
	lv_obj_t *ui_Oven_Btn_State_label;
	lv_obj_t *ui_Oven_Label_Settings;
	lv_obj_t *ui_Oven_Label_TimeLeft;
	lv_obj_t *ui_Oven_Label_Min;
	lv_obj_t *ui_Oven_Tile_Mode;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_1;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_2;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_3;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_4;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_5;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_6;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_7;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_8;
	lv_obj_t *ui_Oven_Tile_Mode_Mode_9;
	lv_obj_t *ui_Oven_Img_Mode1;
	lv_obj_t *ui_Oven_Label_Mode1;
	lv_obj_t *ui_Oven_Img_Mode2;
	lv_obj_t *ui_Oven_Label_Mode2;
	lv_obj_t *ui_Oven_Label_Mode3;
	lv_obj_t *ui_Oven_Img_Mode3;
	lv_obj_t *ui_Oven_Img_Mode4;
	lv_obj_t *ui_Oven_Label_Mode4;
	lv_obj_t *ui_Oven_Img_Mode5;
	lv_obj_t *ui_Oven_Label_Mode5;
	lv_obj_t *ui_Oven_Img_Mode6;
	lv_obj_t *ui_Oven_Label_Mode6;
	lv_obj_t *ui_Oven_Img_Mode7;
	lv_obj_t *ui_Oven_Label_Mode7;
	lv_obj_t *ui_Oven_Img_Mode8;
	lv_obj_t *ui_Oven_Label_Mode8;
	lv_obj_t *ui_Oven_Img_Mode9;
	lv_obj_t *ui_Oven_Label_Mode9;
	lv_obj_t *ui_Oven_Group_TarTemp;
	lv_obj_t *ui_Oven_Img_TempWheel;
	lv_obj_t *ui_Oven_Label_SelTemp;
	lv_obj_t *ui_Oven_Label_TarCen;
	lv_obj_t *ui_Oven_Group_Timer;
	lv_obj_t *ui_Oven_Img_TimerWheel;
	lv_obj_t *ui_Oven_Label_SelTimer;
	lv_obj_t *ui_Oven_Label_TimerSel;
	lv_obj_t *ui_Oven_Lottie_Mic;
	lv_obj_t *ui_Oven_ui_Btn_Back3;
	lv_obj_t *ui_Oven_ui_Btn_Back3_label;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_ui_Home(lv_ui *ui);
void setup_scr_ui_Hood(lv_ui *ui);
void setup_scr_ui_Aircon(lv_ui *ui);
void setup_scr_ui_Oven(lv_ui *ui);
LV_IMG_DECLARE(_menu_bg_alpha_1280x720);
LV_IMG_DECLARE(_nxp_alpha_75x27);
LV_IMG_DECLARE(_text_aircon_alpha_15x88);
LV_IMG_DECLARE(_icn_cool_alpha_27x31);
LV_IMG_DECLARE(_icn_fan_low_alpha_31x27);
LV_IMG_DECLARE(_hood_menu_light_alpha_439x217);
LV_IMG_DECLARE(_text_oven_alpha_15x62);
LV_IMG_DECLARE(_icn_oven_fan_upper_lower_alpha_62x62);
LV_IMG_DECLARE(_text_hood_alpha_15x68);
LV_IMG_DECLARE(_icn_light_on_alpha_39x31);
LV_IMG_DECLARE(_icn_fan_low_alpha_31x27);
LV_IMG_DECLARE(_icn_weather_1_alpha_56x52);
LV_IMG_DECLARE(_hood_small_alpha_299x199);
LV_IMG_DECLARE(_aircon_small_alpha_318x125);
LV_IMG_DECLARE(_oven_light_menu_alpha_257x269);
LV_IMG_DECLARE(_aircon_menu_swing_01_alpha_298x39);
LV_IMG_DECLARE(_smog_1_alpha_110x472);
LV_IMG_DECLARE(_smog_2_alpha_110x630);
LV_IMG_DECLARE(_smog_1_alpha_110x472);
LV_IMG_DECLARE(_smog_2_alpha_110x630);
LV_IMG_DECLARE(_hood_bg_alpha_1280x720);
LV_IMG_DECLARE(_hood_light_alpha_901x460);
LV_IMG_DECLARE(_text_fan_param_alpha_198x26);
LV_IMG_DECLARE(_smog_1_alpha_133x472);
LV_IMG_DECLARE(_smog_2_alpha_133x630);
LV_IMG_DECLARE(_smog_1_alpha_133x472);
LV_IMG_DECLARE(_smog_2_alpha_133x630);
#define LV_LOT_DECLARE(array_name) extern const uint8_t array_name[];
LV_LOT_DECLARE(lottie_lf30_gbhpz7py);
LV_IMG_DECLARE(_title_bg_2_alpha_783x128);
LV_IMG_DECLARE(_aircon_bg_alpha_1280x720);
LV_IMG_DECLARE(_title_bg_alpha_799x130);
LV_IMG_DECLARE(_aircon_swing_1_alpha_632x113);
LV_IMG_DECLARE(_arrow_up_alpha_28x14);
LV_IMG_DECLARE(_arrow_down_alpha_28x14);
LV_IMG_DECLARE(_icn_cool_alpha_27x31);
LV_IMG_DECLARE(_icn_fan_low_alpha_31x27);
LV_IMG_DECLARE(_arrow_up_alpha_28x14);
LV_IMG_DECLARE(_arrow_down_alpha_28x14);
LV_IMG_DECLARE(_aircon_fan_1_alpha_98x98);
LV_IMG_DECLARE(_aircon_cool_1_alpha_92x102);
#define LV_LOT_DECLARE(array_name) extern const uint8_t array_name[];
LV_LOT_DECLARE(lottie_KNiPNozN4m);
LV_IMG_DECLARE(_oven_bg_alpha_1280x720);
LV_IMG_DECLARE(_oven_light_alpha_704x720);
LV_IMG_DECLARE(_oven_fan_light_1_alpha_120x119);
LV_IMG_DECLARE(_title_bg_alpha_654x130);
LV_IMG_DECLARE(_arrow_left_alpha_18x35);
LV_IMG_DECLARE(_arrow_left_alpha_18x35);
LV_IMG_DECLARE(_arrow_left_alpha_18x35);
LV_IMG_DECLARE(_arrow_left_alpha_18x35);
LV_IMG_DECLARE(_arrow_right_alpha_18x35);
LV_IMG_DECLARE(_arrow_right_alpha_18x35);
LV_IMG_DECLARE(_arrow_right_alpha_18x35);
LV_IMG_DECLARE(_arrow_right_alpha_18x35);
LV_IMG_DECLARE(_BTN_oven_alpha_134x51);
LV_IMG_DECLARE(_BTN_oven_alpha_134x51);
LV_IMG_DECLARE(_BTN_oven_alpha_134x51);
LV_IMG_DECLARE(_BTN_oven_alpha_134x51);
LV_IMG_DECLARE(_icn_oven_fan_rear_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_upper_lower_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_fan_upper_lower_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_fan_lower_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_gril_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_fan_gril_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_upper_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_lower_alpha_62x62);
LV_IMG_DECLARE(_icn_oven_defrost_alpha_62x62);
LV_IMG_DECLARE(_wheel_bg_alpha_151x259);
LV_IMG_DECLARE(_wheel_bg_2_alpha_151x259);
#define LV_LOT_DECLARE(array_name) extern const uint8_t array_name[];
LV_LOT_DECLARE(lottie_lf30_gbhpz7py);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_80)
LV_FONT_DECLARE(lv_font_Antonio_Regular_45)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_19)
LV_FONT_DECLARE(lv_font_Antonio_Regular_22)
LV_FONT_DECLARE(lv_font_simsun_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_120)
LV_FONT_DECLARE(lv_font_simsun_12)
LV_FONT_DECLARE(lv_font_Antonio_Regular_21)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_26)
LV_FONT_DECLARE(lv_font_Antonio_Regular_15)
LV_FONT_DECLARE(lv_font_Antonio_Regular_20)
LV_FONT_DECLARE(lv_font_Antonio_Regular_12)
LV_FONT_DECLARE(lv_font_Antonio_Regular_19)
LV_FONT_DECLARE(lv_font_Antonio_Regular_26)
LV_FONT_DECLARE(lv_font_Antonio_Regular_40)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_23)
LV_FONT_DECLARE(lv_font_Antonio_Regular_18)


#ifdef __cplusplus
}
#endif
#endif
