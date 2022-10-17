# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=1280,h=720)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(1280*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 1280
disp_drv.ver_res = 720
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


ui_Aircon = lv.obj()
ui_Aircon.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_aircon_main_main_default
style_ui_aircon_main_main_default = lv.style_t()
style_ui_aircon_main_main_default.init()
style_ui_aircon_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_main_main_default.set_bg_opa(0)

# add style for ui_Aircon
ui_Aircon.add_style(style_ui_aircon_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_Bg = lv.img(ui_Aircon)
ui_Aircon_Img_Bg.set_pos(int(0),int(0))
ui_Aircon_Img_Bg.set_size(1280,720)
ui_Aircon_Img_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf46725\\Documents\\MCUXpresso_Workspace\\MCUXpressoIDE_11.6.0_8187\\RT1170_Training\\evkmimxrt1170_lvgl_guider_cm7\\AirconGUI\\generated\\mPythonImages\\mp573311232.png','rb') as f:
        ui_Aircon_Img_Bg_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf46725\\Documents\\MCUXpresso_Workspace\\MCUXpressoIDE_11.6.0_8187\\RT1170_Training\\evkmimxrt1170_lvgl_guider_cm7\\AirconGUI\\generated\\mPythonImages\\mp573311232.png')
    sys.exit()

ui_Aircon_Img_Bg_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_Bg_img_data),
  'header': {'always_zero': 0, 'w': 1280, 'h': 720, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_Bg_img_data
})

ui_Aircon_Img_Bg.set_src(ui_Aircon_Img_Bg_img)
ui_Aircon_Img_Bg.set_pivot(50,50)
ui_Aircon_Img_Bg.set_angle(0)
# create style style_ui_aircon_img_bg_main_main_default
style_ui_aircon_img_bg_main_main_default = lv.style_t()
style_ui_aircon_img_bg_main_main_default.init()
style_ui_aircon_img_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_bg_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_bg_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_Bg
ui_Aircon_Img_Bg.add_style(style_ui_aircon_img_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_Lable_Bg = lv.img(ui_Aircon)
ui_Aircon_Img_Lable_Bg.set_pos(int(0),int(590))
ui_Aircon_Img_Lable_Bg.set_size(799,130)
ui_Aircon_Img_Lable_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_Lable_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf46725\\Documents\\MCUXpresso_Workspace\\MCUXpressoIDE_11.6.0_8187\\RT1170_Training\\evkmimxrt1170_lvgl_guider_cm7\\AirconGUI\\generated\\mPythonImages\\mp1189627177.png','rb') as f:
        ui_Aircon_Img_Lable_Bg_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf46725\\Documents\\MCUXpresso_Workspace\\MCUXpressoIDE_11.6.0_8187\\RT1170_Training\\evkmimxrt1170_lvgl_guider_cm7\\AirconGUI\\generated\\mPythonImages\\mp1189627177.png')
    sys.exit()

ui_Aircon_Img_Lable_Bg_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_Lable_Bg_img_data),
  'header': {'always_zero': 0, 'w': 799, 'h': 130, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_Lable_Bg_img_data
})

ui_Aircon_Img_Lable_Bg.set_src(ui_Aircon_Img_Lable_Bg_img)
ui_Aircon_Img_Lable_Bg.set_pivot(50,50)
ui_Aircon_Img_Lable_Bg.set_angle(0)
# create style style_ui_aircon_img_lable_bg_main_main_default
style_ui_aircon_img_lable_bg_main_main_default = lv.style_t()
style_ui_aircon_img_lable_bg_main_main_default.init()
style_ui_aircon_img_lable_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_lable_bg_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_lable_bg_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_Lable_Bg
ui_Aircon_Img_Lable_Bg.add_style(style_ui_aircon_img_lable_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Air = lv.label(ui_Aircon)
ui_Aircon_Label_Air.set_pos(int(565),int(639))
ui_Aircon_Label_Air.set_size(180,32)
ui_Aircon_Label_Air.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Air.set_text("Air Conditioner")
ui_Aircon_Label_Air.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_air_main_main_default
style_ui_aircon_label_air_main_main_default = lv.style_t()
style_ui_aircon_label_air_main_main_default.init()
style_ui_aircon_label_air_main_main_default.set_radius(0)
style_ui_aircon_label_air_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_air_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_air_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_air_main_main_default.set_bg_opa(0)
style_ui_aircon_label_air_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_air_main_main_default.set_text_font(lv.font_Amiko_Regular_18)
except AttributeError:
    try:
        style_ui_aircon_label_air_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_aircon_label_air_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_air_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_air_main_main_default.set_text_line_space(0)
style_ui_aircon_label_air_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_air_main_main_default.set_pad_left(0)
style_ui_aircon_label_air_main_main_default.set_pad_right(0)
style_ui_aircon_label_air_main_main_default.set_pad_top(8)
style_ui_aircon_label_air_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Air
ui_Aircon_Label_Air.add_style(style_ui_aircon_label_air_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_cont_1 = lv.obj(ui_Aircon)
ui_Aircon_cont_1.set_pos(int(826),int(30))
ui_Aircon_cont_1.set_size(409,657)
ui_Aircon_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_line = lv.line(ui_Aircon_cont_1)
ui_Aircon_line.set_pos(int(7),int(7))
ui_Aircon_line.set_size(405,24)
ui_Aircon_line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":393, "y":0}, 
			  ]
ui_Aircon_line.set_points(line_points, 2)
# create style style_ui_aircon_line_main_main_default
style_ui_aircon_line_main_main_default = lv.style_t()
style_ui_aircon_line_main_main_default.init()
style_ui_aircon_line_main_main_default.set_line_color(lv.color_make(0x52,0xDA,0xFF))
style_ui_aircon_line_main_main_default.set_line_width(17)
style_ui_aircon_line_main_main_default.set_line_rounded(True)

# add style for ui_Aircon_line
ui_Aircon_line.add_style(style_ui_aircon_line_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Temp = lv.label(ui_Aircon_cont_1)
ui_Aircon_Label_Temp.set_pos(int(25),int(87))
ui_Aircon_Label_Temp.set_size(151,123)
ui_Aircon_Label_Temp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Temp.set_text("25")
ui_Aircon_Label_Temp.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_temp_main_main_default
style_ui_aircon_label_temp_main_main_default = lv.style_t()
style_ui_aircon_label_temp_main_main_default.init()
style_ui_aircon_label_temp_main_main_default.set_radius(0)
style_ui_aircon_label_temp_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_temp_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_temp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_temp_main_main_default.set_bg_opa(0)
style_ui_aircon_label_temp_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_temp_main_main_default.set_text_font(lv.font_Antonio_Regular_120)
except AttributeError:
    try:
        style_ui_aircon_label_temp_main_main_default.set_text_font(lv.font_montserrat_120)
    except AttributeError:
        style_ui_aircon_label_temp_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_temp_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_temp_main_main_default.set_text_line_space(0)
style_ui_aircon_label_temp_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_temp_main_main_default.set_pad_left(0)
style_ui_aircon_label_temp_main_main_default.set_pad_right(0)
style_ui_aircon_label_temp_main_main_default.set_pad_top(8)
style_ui_aircon_label_temp_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Temp
ui_Aircon_Label_Temp.add_style(style_ui_aircon_label_temp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_btn_1 = lv.btn(ui_Aircon_cont_1)
ui_Aircon_btn_1.set_pos(int(200),int(114))
ui_Aircon_btn_1.set_size(74,58)
ui_Aircon_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_aircon_btn_1_main_main_default
style_ui_aircon_btn_1_main_main_default = lv.style_t()
style_ui_aircon_btn_1_main_main_default.init()
style_ui_aircon_btn_1_main_main_default.set_radius(10)
style_ui_aircon_btn_1_main_main_default.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_1_main_main_default.set_bg_opa(255)
style_ui_aircon_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_1_main_main_default.set_border_width(0)
style_ui_aircon_btn_1_main_main_default.set_border_opa(255)
style_ui_aircon_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for ui_Aircon_btn_1
ui_Aircon_btn_1.add_style(style_ui_aircon_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_btn_1_main_main_pressed
style_ui_aircon_btn_1_main_main_pressed = lv.style_t()
style_ui_aircon_btn_1_main_main_pressed.init()
style_ui_aircon_btn_1_main_main_pressed.set_radius(10)
style_ui_aircon_btn_1_main_main_pressed.set_bg_color(lv.color_make(0x18,0xC2,0x20))
style_ui_aircon_btn_1_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_1_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_1_main_main_pressed.set_bg_opa(255)
style_ui_aircon_btn_1_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_1_main_main_pressed.set_border_width(0)
style_ui_aircon_btn_1_main_main_pressed.set_border_opa(255)
style_ui_aircon_btn_1_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_1_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_btn_1
ui_Aircon_btn_1.add_style(style_ui_aircon_btn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

ui_Aircon_Sw_Swing = lv.switch(ui_Aircon_cont_1)
ui_Aircon_Sw_Swing.set_pos(int(125),int(549))
ui_Aircon_Sw_Swing.set_size(66,36)
ui_Aircon_Sw_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_aircon_sw_swing_main_main_default
style_ui_aircon_sw_swing_main_main_default = lv.style_t()
style_ui_aircon_sw_swing_main_main_default.init()
style_ui_aircon_sw_swing_main_main_default.set_radius(100)
style_ui_aircon_sw_swing_main_main_default.set_bg_color(lv.color_make(0x6A,0x6A,0x6A))
style_ui_aircon_sw_swing_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe2,0xe6))
style_ui_aircon_sw_swing_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_sw_swing_main_main_default.set_bg_opa(255)
style_ui_aircon_sw_swing_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_sw_swing_main_main_default.set_border_width(0)
style_ui_aircon_sw_swing_main_main_default.set_border_opa(0)

# add style for ui_Aircon_Sw_Swing
ui_Aircon_Sw_Swing.add_style(style_ui_aircon_sw_swing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_sw_swing_main_indicator_checked
style_ui_aircon_sw_swing_main_indicator_checked = lv.style_t()
style_ui_aircon_sw_swing_main_indicator_checked.init()
style_ui_aircon_sw_swing_main_indicator_checked.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_sw_swing_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_sw_swing_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_sw_swing_main_indicator_checked.set_bg_opa(255)
style_ui_aircon_sw_swing_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_sw_swing_main_indicator_checked.set_border_width(0)
style_ui_aircon_sw_swing_main_indicator_checked.set_border_opa(0)

# add style for ui_Aircon_Sw_Swing
ui_Aircon_Sw_Swing.add_style(style_ui_aircon_sw_swing_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_ui_aircon_sw_swing_main_knob_default
style_ui_aircon_sw_swing_main_knob_default = lv.style_t()
style_ui_aircon_sw_swing_main_knob_default.init()
style_ui_aircon_sw_swing_main_knob_default.set_radius(100)
style_ui_aircon_sw_swing_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_sw_swing_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_sw_swing_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_sw_swing_main_knob_default.set_bg_opa(255)
style_ui_aircon_sw_swing_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_sw_swing_main_knob_default.set_border_width(0)
style_ui_aircon_sw_swing_main_knob_default.set_border_opa(255)

# add style for ui_Aircon_Sw_Swing
ui_Aircon_Sw_Swing.add_style(style_ui_aircon_sw_swing_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

# create style style_ui_aircon_cont_1_main_main_default
style_ui_aircon_cont_1_main_main_default = lv.style_t()
style_ui_aircon_cont_1_main_main_default.init()
style_ui_aircon_cont_1_main_main_default.set_radius(20)
style_ui_aircon_cont_1_main_main_default.set_bg_color(lv.color_make(0x24,0x24,0x24))
style_ui_aircon_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_cont_1_main_main_default.set_bg_opa(250)
style_ui_aircon_cont_1_main_main_default.set_border_color(lv.color_make(0x4A,0x4C,0x4A))
style_ui_aircon_cont_1_main_main_default.set_border_width(1)
style_ui_aircon_cont_1_main_main_default.set_border_opa(255)
style_ui_aircon_cont_1_main_main_default.set_pad_left(0)
style_ui_aircon_cont_1_main_main_default.set_pad_right(0)
style_ui_aircon_cont_1_main_main_default.set_pad_top(0)
style_ui_aircon_cont_1_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_cont_1
ui_Aircon_cont_1.add_style(style_ui_aircon_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_Swing = lv.img(ui_Aircon)
ui_Aircon_Img_Swing.set_pos(int(120),int(380))
ui_Aircon_Img_Swing.set_size(632,113)
ui_Aircon_Img_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_Swing.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf46725\\Documents\\MCUXpresso_Workspace\\MCUXpressoIDE_11.6.0_8187\\RT1170_Training\\evkmimxrt1170_lvgl_guider_cm7\\AirconGUI\\generated\\mPythonImages\\mp1498185293.png','rb') as f:
        ui_Aircon_Img_Swing_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf46725\\Documents\\MCUXpresso_Workspace\\MCUXpressoIDE_11.6.0_8187\\RT1170_Training\\evkmimxrt1170_lvgl_guider_cm7\\AirconGUI\\generated\\mPythonImages\\mp1498185293.png')
    sys.exit()

ui_Aircon_Img_Swing_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_Swing_img_data),
  'header': {'always_zero': 0, 'w': 632, 'h': 113, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_Swing_img_data
})

ui_Aircon_Img_Swing.set_src(ui_Aircon_Img_Swing_img)
ui_Aircon_Img_Swing.set_pivot(50,50)
ui_Aircon_Img_Swing.set_angle(0)
# create style style_ui_aircon_img_swing_main_main_default
style_ui_aircon_img_swing_main_main_default = lv.style_t()
style_ui_aircon_img_swing_main_main_default.init()
style_ui_aircon_img_swing_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_swing_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_swing_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_Swing
ui_Aircon_Img_Swing.add_style(style_ui_aircon_img_swing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)






# content from custom.py

# Load the default screen
lv.scr_load(ui_Aircon)

while SDL.check():
    time.sleep_ms(5)
