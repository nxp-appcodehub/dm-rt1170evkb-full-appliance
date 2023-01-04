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


ui_Oven = lv.obj()
ui_Oven.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_oven_main_main_default
style_ui_oven_main_main_default = lv.style_t()
style_ui_oven_main_main_default.init()
style_ui_oven_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_ui_oven_main_main_default.set_bg_opa(0)

# add style for ui_Oven
ui_Oven.add_style(style_ui_oven_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Img_Bg = lv.img(ui_Oven)
ui_Oven_Img_Bg.set_pos(int(0),int(0))
ui_Oven_Img_Bg.set_size(1280,720)
ui_Oven_Img_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1049503462.png','rb') as f:
        ui_Oven_Img_Bg_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1049503462.png')
    sys.exit()

ui_Oven_Img_Bg_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Bg_img_data),
  'header': {'always_zero': 0, 'w': 1280, 'h': 720, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Bg_img_data
})

ui_Oven_Img_Bg.set_src(ui_Oven_Img_Bg_img)
ui_Oven_Img_Bg.set_pivot(50,50)
ui_Oven_Img_Bg.set_angle(0)
# create style style_ui_oven_img_bg_main_main_default
style_ui_oven_img_bg_main_main_default = lv.style_t()
style_ui_oven_img_bg_main_main_default.init()
style_ui_oven_img_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_bg_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_bg_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Bg
ui_Oven_Img_Bg.add_style(style_ui_oven_img_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Img_Door = lv.img(ui_Oven)
ui_Oven_Img_Door.set_pos(int(5),int(-1))
ui_Oven_Img_Door.set_size(704,720)
ui_Oven_Img_Door.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Door.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1534861193.png','rb') as f:
        ui_Oven_Img_Door_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1534861193.png')
    sys.exit()

ui_Oven_Img_Door_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Door_img_data),
  'header': {'always_zero': 0, 'w': 704, 'h': 720, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Door_img_data
})

ui_Oven_Img_Door.set_src(ui_Oven_Img_Door_img)
ui_Oven_Img_Door.set_pivot(50,50)
ui_Oven_Img_Door.set_angle(0)
# create style style_ui_oven_img_door_main_main_default
style_ui_oven_img_door_main_main_default = lv.style_t()
style_ui_oven_img_door_main_main_default.init()
style_ui_oven_img_door_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_door_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_door_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Door
ui_Oven_Img_Door.add_style(style_ui_oven_img_door_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Img_Fan = lv.img(ui_Oven)
ui_Oven_Img_Fan.set_pos(int(364),int(344))
ui_Oven_Img_Fan.set_size(120,119)
ui_Oven_Img_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Fan.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-159985281.png','rb') as f:
        ui_Oven_Img_Fan_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-159985281.png')
    sys.exit()

ui_Oven_Img_Fan_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Fan_img_data),
  'header': {'always_zero': 0, 'w': 120, 'h': 119, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Fan_img_data
})

ui_Oven_Img_Fan.set_src(ui_Oven_Img_Fan_img)
ui_Oven_Img_Fan.set_pivot(50,50)
ui_Oven_Img_Fan.set_angle(0)
# create style style_ui_oven_img_fan_main_main_default
style_ui_oven_img_fan_main_main_default = lv.style_t()
style_ui_oven_img_fan_main_main_default.init()
style_ui_oven_img_fan_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_fan_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_fan_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Fan
ui_Oven_Img_Fan.add_style(style_ui_oven_img_fan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Img_Lable_Bg = lv.img(ui_Oven)
ui_Oven_Img_Lable_Bg.set_pos(int(0),int(590))
ui_Oven_Img_Lable_Bg.set_size(654,130)
ui_Oven_Img_Lable_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Lable_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1787584403.png','rb') as f:
        ui_Oven_Img_Lable_Bg_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1787584403.png')
    sys.exit()

ui_Oven_Img_Lable_Bg_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Lable_Bg_img_data),
  'header': {'always_zero': 0, 'w': 654, 'h': 130, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Lable_Bg_img_data
})

ui_Oven_Img_Lable_Bg.set_src(ui_Oven_Img_Lable_Bg_img)
ui_Oven_Img_Lable_Bg.set_pivot(50,50)
ui_Oven_Img_Lable_Bg.set_angle(0)
# create style style_ui_oven_img_lable_bg_main_main_default
style_ui_oven_img_lable_bg_main_main_default = lv.style_t()
style_ui_oven_img_lable_bg_main_main_default.init()
style_ui_oven_img_lable_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_lable_bg_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_lable_bg_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Lable_Bg
ui_Oven_Img_Lable_Bg.add_style(style_ui_oven_img_lable_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Oven = lv.label(ui_Oven)
ui_Oven_Label_Oven.set_pos(int(541),int(639))
ui_Oven_Label_Oven.set_size(100,32)
ui_Oven_Label_Oven.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Oven.set_text("Oven")
ui_Oven_Label_Oven.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_oven_main_main_default
style_ui_oven_label_oven_main_main_default = lv.style_t()
style_ui_oven_label_oven_main_main_default.init()
style_ui_oven_label_oven_main_main_default.set_radius(0)
style_ui_oven_label_oven_main_main_default.set_bg_color(lv.color_make(0x4a,0x60,0x73))
style_ui_oven_label_oven_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_oven_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_oven_main_main_default.set_bg_opa(0)
style_ui_oven_label_oven_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_oven_main_main_default.set_text_font(lv.font_Antonio_Regular_22)
except AttributeError:
    try:
        style_ui_oven_label_oven_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_ui_oven_label_oven_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_oven_main_main_default.set_text_letter_space(2)
style_ui_oven_label_oven_main_main_default.set_text_line_space(0)
style_ui_oven_label_oven_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_oven_main_main_default.set_pad_left(0)
style_ui_oven_label_oven_main_main_default.set_pad_right(0)
style_ui_oven_label_oven_main_main_default.set_pad_top(8)
style_ui_oven_label_oven_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Oven
ui_Oven_Label_Oven.add_style(style_ui_oven_label_oven_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Group_Oven = lv.obj(ui_Oven)
ui_Oven_Group_Oven.set_pos(int(677),int(17))
ui_Oven_Group_Oven.set_size(534,686)
ui_Oven_Group_Oven.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_line = lv.line(ui_Oven_Group_Oven)
ui_Oven_line.set_pos(int(7),int(7))
ui_Oven_line.set_size(530,24)
ui_Oven_line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":519, "y":0}, 
			  ]
ui_Oven_line.set_points(line_points, 2)
# create style style_ui_oven_line_main_main_default
style_ui_oven_line_main_main_default = lv.style_t()
style_ui_oven_line_main_main_default.init()
style_ui_oven_line_main_main_default.set_line_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_line_main_main_default.set_line_width(17)
style_ui_oven_line_main_main_default.set_line_rounded(True)

# add style for ui_Oven_line
ui_Oven_line.add_style(style_ui_oven_line_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_CurrTemp = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_CurrTemp.set_pos(int(34),int(49))
ui_Oven_Label_CurrTemp.set_size(203,32)
ui_Oven_Label_CurrTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_CurrTemp.set_text("CURRENT TEMP.")
ui_Oven_Label_CurrTemp.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_currtemp_main_main_default
style_ui_oven_label_currtemp_main_main_default = lv.style_t()
style_ui_oven_label_currtemp_main_main_default.init()
style_ui_oven_label_currtemp_main_main_default.set_radius(0)
style_ui_oven_label_currtemp_main_main_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_label_currtemp_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_currtemp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_currtemp_main_main_default.set_bg_opa(0)
style_ui_oven_label_currtemp_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_currtemp_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_oven_label_currtemp_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_oven_label_currtemp_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_currtemp_main_main_default.set_text_letter_space(2)
style_ui_oven_label_currtemp_main_main_default.set_text_line_space(0)
style_ui_oven_label_currtemp_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_currtemp_main_main_default.set_pad_left(0)
style_ui_oven_label_currtemp_main_main_default.set_pad_right(0)
style_ui_oven_label_currtemp_main_main_default.set_pad_top(8)
style_ui_oven_label_currtemp_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_CurrTemp
ui_Oven_Label_CurrTemp.add_style(style_ui_oven_label_currtemp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_line_5 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_5.set_pos(int(23),int(234))
ui_Oven_line_5.set_size(495,13)
ui_Oven_line_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":485, "y":0}, 
			  ]
ui_Oven_line_5.set_points(line_points, 2)
# create style style_ui_oven_line_5_main_main_default
style_ui_oven_line_5_main_main_default = lv.style_t()
style_ui_oven_line_5_main_main_default.init()
style_ui_oven_line_5_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_oven_line_5_main_main_default.set_line_width(3)
style_ui_oven_line_5_main_main_default.set_line_rounded(False)

# add style for ui_Oven_line_5
ui_Oven_line_5.add_style(style_ui_oven_line_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_line_4 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_4.set_pos(int(23),int(379))
ui_Oven_line_4.set_size(495,13)
ui_Oven_line_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":485, "y":0}, 
			  ]
ui_Oven_line_4.set_points(line_points, 2)
# create style style_ui_oven_line_4_main_main_default
style_ui_oven_line_4_main_main_default = lv.style_t()
style_ui_oven_line_4_main_main_default.init()
style_ui_oven_line_4_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_oven_line_4_main_main_default.set_line_width(3)
style_ui_oven_line_4_main_main_default.set_line_rounded(False)

# add style for ui_Oven_line_4
ui_Oven_line_4.add_style(style_ui_oven_line_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_line_3 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_3.set_pos(int(269),int(117))
ui_Oven_line_3.set_size(240,7)
ui_Oven_line_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":235, "y":0}, 
			  ]
ui_Oven_line_3.set_points(line_points, 2)
# create style style_ui_oven_line_3_main_main_default
style_ui_oven_line_3_main_main_default = lv.style_t()
style_ui_oven_line_3_main_main_default.init()
style_ui_oven_line_3_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_oven_line_3_main_main_default.set_line_width(3)
style_ui_oven_line_3_main_main_default.set_line_rounded(False)

# add style for ui_Oven_line_3
ui_Oven_line_3.add_style(style_ui_oven_line_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_line_2 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_2.set_pos(int(252),int(52))
ui_Oven_line_2.set_size(29,169)
ui_Oven_line_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":160}, 
			  ]
ui_Oven_line_2.set_points(line_points, 2)
# create style style_ui_oven_line_2_main_main_default
style_ui_oven_line_2_main_main_default = lv.style_t()
style_ui_oven_line_2_main_main_default.init()
style_ui_oven_line_2_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_oven_line_2_main_main_default.set_line_width(3)
style_ui_oven_line_2_main_main_default.set_line_rounded(False)

# add style for ui_Oven_line_2
ui_Oven_line_2.add_style(style_ui_oven_line_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_line_1 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_1.set_pos(int(267),int(441))
ui_Oven_line_1.set_size(17,146)
ui_Oven_line_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":300}, 
			  ]
ui_Oven_line_1.set_points(line_points, 2)
# create style style_ui_oven_line_1_main_main_default
style_ui_oven_line_1_main_main_default = lv.style_t()
style_ui_oven_line_1_main_main_default.init()
style_ui_oven_line_1_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_oven_line_1_main_main_default.set_line_width(3)
style_ui_oven_line_1_main_main_default.set_line_rounded(False)

# add style for ui_Oven_line_1
ui_Oven_line_1.add_style(style_ui_oven_line_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Temp = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Temp.set_pos(int(7),int(89))
ui_Oven_Label_Temp.set_size(214,125)
ui_Oven_Label_Temp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Temp.set_text("250")
ui_Oven_Label_Temp.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_temp_main_main_default
style_ui_oven_label_temp_main_main_default = lv.style_t()
style_ui_oven_label_temp_main_main_default.init()
style_ui_oven_label_temp_main_main_default.set_radius(0)
style_ui_oven_label_temp_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_temp_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_temp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_temp_main_main_default.set_bg_opa(0)
style_ui_oven_label_temp_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_temp_main_main_default.set_text_font(lv.font_Antonio_Regular_120)
except AttributeError:
    try:
        style_ui_oven_label_temp_main_main_default.set_text_font(lv.font_montserrat_120)
    except AttributeError:
        style_ui_oven_label_temp_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_temp_main_main_default.set_text_letter_space(2)
style_ui_oven_label_temp_main_main_default.set_text_line_space(0)
style_ui_oven_label_temp_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_temp_main_main_default.set_pad_left(0)
style_ui_oven_label_temp_main_main_default.set_pad_right(0)
style_ui_oven_label_temp_main_main_default.set_pad_top(8)
style_ui_oven_label_temp_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Temp
ui_Oven_Label_Temp.add_style(style_ui_oven_label_temp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Cen = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Cen.set_pos(int(175),int(88))
ui_Oven_Label_Cen.set_size(72,53)
ui_Oven_Label_Cen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Cen.set_text("ºC")
ui_Oven_Label_Cen.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_cen_main_main_default
style_ui_oven_label_cen_main_main_default = lv.style_t()
style_ui_oven_label_cen_main_main_default.init()
style_ui_oven_label_cen_main_main_default.set_radius(0)
style_ui_oven_label_cen_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_cen_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_cen_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_cen_main_main_default.set_bg_opa(0)
style_ui_oven_label_cen_main_main_default.set_text_color(lv.color_make(0xc9,0xc5,0xc5))
try:
    style_ui_oven_label_cen_main_main_default.set_text_font(lv.font_Alatsi_Regular_26)
except AttributeError:
    try:
        style_ui_oven_label_cen_main_main_default.set_text_font(lv.font_montserrat_26)
    except AttributeError:
        style_ui_oven_label_cen_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_cen_main_main_default.set_text_letter_space(2)
style_ui_oven_label_cen_main_main_default.set_text_line_space(0)
style_ui_oven_label_cen_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_cen_main_main_default.set_pad_left(0)
style_ui_oven_label_cen_main_main_default.set_pad_right(0)
style_ui_oven_label_cen_main_main_default.set_pad_top(8)
style_ui_oven_label_cen_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Cen
ui_Oven_Label_Cen.add_style(style_ui_oven_label_cen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Status = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Status.set_pos(int(287),int(34))
ui_Oven_Label_Status.set_size(203,32)
ui_Oven_Label_Status.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Status.set_text("STATUS")
ui_Oven_Label_Status.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_status_main_main_default
style_ui_oven_label_status_main_main_default = lv.style_t()
style_ui_oven_label_status_main_main_default.init()
style_ui_oven_label_status_main_main_default.set_radius(0)
style_ui_oven_label_status_main_main_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_label_status_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_status_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_status_main_main_default.set_bg_opa(0)
style_ui_oven_label_status_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_status_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_oven_label_status_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_oven_label_status_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_status_main_main_default.set_text_letter_space(2)
style_ui_oven_label_status_main_main_default.set_text_line_space(0)
style_ui_oven_label_status_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_status_main_main_default.set_pad_left(0)
style_ui_oven_label_status_main_main_default.set_pad_right(0)
style_ui_oven_label_status_main_main_default.set_pad_top(8)
style_ui_oven_label_status_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Status
ui_Oven_Label_Status.add_style(style_ui_oven_label_status_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_CurrStat = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_CurrStat.set_pos(int(329),int(67))
ui_Oven_Label_CurrStat.set_size(118,53)
ui_Oven_Label_CurrStat.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_CurrStat.set_text("My Stat")
ui_Oven_Label_CurrStat.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_currstat_main_main_default
style_ui_oven_label_currstat_main_main_default = lv.style_t()
style_ui_oven_label_currstat_main_main_default.init()
style_ui_oven_label_currstat_main_main_default.set_radius(0)
style_ui_oven_label_currstat_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_currstat_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_currstat_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_currstat_main_main_default.set_bg_opa(0)
style_ui_oven_label_currstat_main_main_default.set_text_color(lv.color_make(0xc9,0xc5,0xc5))
try:
    style_ui_oven_label_currstat_main_main_default.set_text_font(lv.font_Antonio_Regular_26)
except AttributeError:
    try:
        style_ui_oven_label_currstat_main_main_default.set_text_font(lv.font_montserrat_26)
    except AttributeError:
        style_ui_oven_label_currstat_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_currstat_main_main_default.set_text_letter_space(2)
style_ui_oven_label_currstat_main_main_default.set_text_line_space(0)
style_ui_oven_label_currstat_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_currstat_main_main_default.set_pad_left(0)
style_ui_oven_label_currstat_main_main_default.set_pad_right(0)
style_ui_oven_label_currstat_main_main_default.set_pad_top(8)
style_ui_oven_label_currstat_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_CurrStat
ui_Oven_Label_CurrStat.add_style(style_ui_oven_label_currstat_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Time = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Time.set_pos(int(236),int(132))
ui_Oven_Label_Time.set_size(118,57)
ui_Oven_Label_Time.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Time.set_text("TIME\nLEFT")
ui_Oven_Label_Time.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_time_main_main_default
style_ui_oven_label_time_main_main_default = lv.style_t()
style_ui_oven_label_time_main_main_default.init()
style_ui_oven_label_time_main_main_default.set_radius(0)
style_ui_oven_label_time_main_main_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_label_time_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_time_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_time_main_main_default.set_bg_opa(0)
style_ui_oven_label_time_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_time_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_oven_label_time_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_oven_label_time_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_time_main_main_default.set_text_letter_space(2)
style_ui_oven_label_time_main_main_default.set_text_line_space(0)
style_ui_oven_label_time_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_time_main_main_default.set_pad_left(0)
style_ui_oven_label_time_main_main_default.set_pad_right(0)
style_ui_oven_label_time_main_main_default.set_pad_top(8)
style_ui_oven_label_time_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Time
ui_Oven_Label_Time.add_style(style_ui_oven_label_time_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Bar_Time = lv.bar(ui_Oven_Group_Oven)
ui_Oven_Bar_Time.set_pos(int(274),int(195))
ui_Oven_Bar_Time.set_size(225,13)
ui_Oven_Bar_Time.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Bar_Time.set_style_anim_time(1000, 0)
ui_Oven_Bar_Time.set_mode(lv.bar.MODE.NORMAL)
ui_Oven_Bar_Time.set_value(30, lv.ANIM.OFF)
# create style style_ui_oven_bar_time_main_main_default
style_ui_oven_bar_time_main_main_default = lv.style_t()
style_ui_oven_bar_time_main_main_default.init()
style_ui_oven_bar_time_main_main_default.set_radius(10)
style_ui_oven_bar_time_main_main_default.set_bg_color(lv.color_make(0x4A,0x44,0x41))
style_ui_oven_bar_time_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_bar_time_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_bar_time_main_main_default.set_bg_opa(255)

# add style for ui_Oven_Bar_Time
ui_Oven_Bar_Time.add_style(style_ui_oven_bar_time_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_bar_time_main_indicator_default
style_ui_oven_bar_time_main_indicator_default = lv.style_t()
style_ui_oven_bar_time_main_indicator_default.init()
style_ui_oven_bar_time_main_indicator_default.set_radius(10)
style_ui_oven_bar_time_main_indicator_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_bar_time_main_indicator_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_bar_time_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_bar_time_main_indicator_default.set_bg_opa(255)

# add style for ui_Oven_Bar_Time
ui_Oven_Bar_Time.add_style(style_ui_oven_bar_time_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

ui_Oven_Label_Mode = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Mode.set_pos(int(208),int(240))
ui_Oven_Label_Mode.set_size(118,57)
ui_Oven_Label_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode.set_text("MODE")
ui_Oven_Label_Mode.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode_main_main_default
style_ui_oven_label_mode_main_main_default = lv.style_t()
style_ui_oven_label_mode_main_main_default.init()
style_ui_oven_label_mode_main_main_default.set_radius(0)
style_ui_oven_label_mode_main_main_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_label_mode_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_mode_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_oven_label_mode_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_oven_label_mode_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_mode_main_main_default.set_pad_left(0)
style_ui_oven_label_mode_main_main_default.set_pad_right(0)
style_ui_oven_label_mode_main_main_default.set_pad_top(8)
style_ui_oven_label_mode_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode
ui_Oven_Label_Mode.add_style(style_ui_oven_label_mode_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Btn_ModeLeft = lv.imgbtn(ui_Oven_Group_Oven)
ui_Oven_Btn_ModeLeft.set_pos(int(27),int(291))
ui_Oven_Btn_ModeLeft.set_size(18,35)
ui_Oven_Btn_ModeLeft.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png','rb') as f:
        ui_Oven_Btn_ModeLeft_imgReleased_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png')
    sys.exit()

ui_Oven_Btn_ModeLeft_imgReleased = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeLeft_imgReleased_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeLeft_imgReleased_data
})
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.RELEASED, None, ui_Oven_Btn_ModeLeft_imgReleased, None)

try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png','rb') as f:
        ui_Oven_Btn_ModeLeft_imgPressed_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png')
    sys.exit()

ui_Oven_Btn_ModeLeft_imgPressed = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeLeft_imgPressed_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeLeft_imgPressed_data
})
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.PRESSED, None, ui_Oven_Btn_ModeLeft_imgPressed, None)


try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png','rb') as f:
        ui_Oven_Btn_ModeLeft_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png')
    sys.exit()

ui_Oven_Btn_ModeLeft_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeLeft_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeLeft_imgCheckedReleased_data
})
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, ui_Oven_Btn_ModeLeft_imgCheckedReleased, None)

try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png','rb') as f:
        ui_Oven_Btn_ModeLeft_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp462361614.png')
    sys.exit()

ui_Oven_Btn_ModeLeft_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeLeft_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeLeft_imgCheckedPressed_data
})
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, ui_Oven_Btn_ModeLeft_imgCheckedPressed, None)

ui_Oven_Btn_ModeLeft.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_ui_oven_btn_modeleft_main_main_default
style_ui_oven_btn_modeleft_main_main_default = lv.style_t()
style_ui_oven_btn_modeleft_main_main_default.init()
style_ui_oven_btn_modeleft_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_ui_oven_btn_modeleft_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_ui_oven_btn_modeleft_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ui_oven_btn_modeleft_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_btn_modeleft_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_btn_modeleft_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_btn_modeleft_main_main_default.set_img_recolor_opa(0)
style_ui_oven_btn_modeleft_main_main_default.set_img_opa(255)

# add style for ui_Oven_Btn_ModeLeft
ui_Oven_Btn_ModeLeft.add_style(style_ui_oven_btn_modeleft_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_btn_modeleft_main_main_pressed
style_ui_oven_btn_modeleft_main_main_pressed = lv.style_t()
style_ui_oven_btn_modeleft_main_main_pressed.init()
style_ui_oven_btn_modeleft_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_ui_oven_btn_modeleft_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_ui_oven_btn_modeleft_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ui_oven_btn_modeleft_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_ui_oven_btn_modeleft_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_btn_modeleft_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_ui_oven_btn_modeleft_main_main_pressed.set_img_recolor_opa(0)
style_ui_oven_btn_modeleft_main_main_pressed.set_img_opa(255)

# add style for ui_Oven_Btn_ModeLeft
ui_Oven_Btn_ModeLeft.add_style(style_ui_oven_btn_modeleft_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_ui_oven_btn_modeleft_main_main_checked
style_ui_oven_btn_modeleft_main_main_checked = lv.style_t()
style_ui_oven_btn_modeleft_main_main_checked.init()
style_ui_oven_btn_modeleft_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_ui_oven_btn_modeleft_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_ui_oven_btn_modeleft_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ui_oven_btn_modeleft_main_main_checked.set_text_font(lv.font_montserrat_16)
style_ui_oven_btn_modeleft_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_btn_modeleft_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_ui_oven_btn_modeleft_main_main_checked.set_img_recolor_opa(0)
style_ui_oven_btn_modeleft_main_main_checked.set_img_opa(255)

# add style for ui_Oven_Btn_ModeLeft
ui_Oven_Btn_ModeLeft.add_style(style_ui_oven_btn_modeleft_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

ui_Oven_Btn_ModeRigth = lv.imgbtn(ui_Oven_Group_Oven)
ui_Oven_Btn_ModeRigth.set_pos(int(486),int(291))
ui_Oven_Btn_ModeRigth.set_size(18,35)
ui_Oven_Btn_ModeRigth.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png','rb') as f:
        ui_Oven_Btn_ModeRigth_imgReleased_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png')
    sys.exit()

ui_Oven_Btn_ModeRigth_imgReleased = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeRigth_imgReleased_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeRigth_imgReleased_data
})
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.RELEASED, None, ui_Oven_Btn_ModeRigth_imgReleased, None)

try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png','rb') as f:
        ui_Oven_Btn_ModeRigth_imgPressed_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png')
    sys.exit()

ui_Oven_Btn_ModeRigth_imgPressed = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeRigth_imgPressed_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeRigth_imgPressed_data
})
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.PRESSED, None, ui_Oven_Btn_ModeRigth_imgPressed, None)


try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png','rb') as f:
        ui_Oven_Btn_ModeRigth_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png')
    sys.exit()

ui_Oven_Btn_ModeRigth_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeRigth_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeRigth_imgCheckedReleased_data
})
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, ui_Oven_Btn_ModeRigth_imgCheckedReleased, None)

try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png','rb') as f:
        ui_Oven_Btn_ModeRigth_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-827193017.png')
    sys.exit()

ui_Oven_Btn_ModeRigth_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_ModeRigth_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_ModeRigth_imgCheckedPressed_data
})
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, ui_Oven_Btn_ModeRigth_imgCheckedPressed, None)

ui_Oven_Btn_ModeRigth.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_ui_oven_btn_moderigth_main_main_default
style_ui_oven_btn_moderigth_main_main_default = lv.style_t()
style_ui_oven_btn_moderigth_main_main_default.init()
style_ui_oven_btn_moderigth_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_ui_oven_btn_moderigth_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_ui_oven_btn_moderigth_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ui_oven_btn_moderigth_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_btn_moderigth_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_btn_moderigth_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_btn_moderigth_main_main_default.set_img_recolor_opa(0)
style_ui_oven_btn_moderigth_main_main_default.set_img_opa(255)

# add style for ui_Oven_Btn_ModeRigth
ui_Oven_Btn_ModeRigth.add_style(style_ui_oven_btn_moderigth_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Btn_State = lv.imgbtn(ui_Oven_Group_Oven)
ui_Oven_Btn_State.set_pos(int(203),int(607))
ui_Oven_Btn_State.set_size(134,51)
ui_Oven_Btn_State.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png','rb') as f:
        ui_Oven_Btn_State_imgReleased_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png')
    sys.exit()

ui_Oven_Btn_State_imgReleased = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_State_imgReleased_data),
  'header': {'always_zero': 0, 'w': 134, 'h': 51, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_State_imgReleased_data
})
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.RELEASED, None, ui_Oven_Btn_State_imgReleased, None)

try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png','rb') as f:
        ui_Oven_Btn_State_imgPressed_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png')
    sys.exit()

ui_Oven_Btn_State_imgPressed = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_State_imgPressed_data),
  'header': {'always_zero': 0, 'w': 134, 'h': 51, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_State_imgPressed_data
})
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.PRESSED, None, ui_Oven_Btn_State_imgPressed, None)


try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png','rb') as f:
        ui_Oven_Btn_State_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png')
    sys.exit()

ui_Oven_Btn_State_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_State_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 134, 'h': 51, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_State_imgCheckedReleased_data
})
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, ui_Oven_Btn_State_imgCheckedReleased, None)

try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png','rb') as f:
        ui_Oven_Btn_State_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1154903261.png')
    sys.exit()

ui_Oven_Btn_State_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(ui_Oven_Btn_State_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 134, 'h': 51, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Btn_State_imgCheckedPressed_data
})
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, ui_Oven_Btn_State_imgCheckedPressed, None)

ui_Oven_Btn_State.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Oven_Btn_State_label = lv.label(ui_Oven_Btn_State)
ui_Oven_Btn_State_label.set_text("START")
ui_Oven_Btn_State.set_style_pad_all(0, lv.STATE.ANY)
ui_Oven_Btn_State_label.align(lv.ALIGN.CENTER,0,0)
# create style style_ui_oven_btn_state_main_main_default
style_ui_oven_btn_state_main_main_default = lv.style_t()
style_ui_oven_btn_state_main_main_default.init()
style_ui_oven_btn_state_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_btn_state_main_main_default.set_text_font(lv.font_Antonio_Regular_26)
except AttributeError:
    try:
        style_ui_oven_btn_state_main_main_default.set_text_font(lv.font_montserrat_26)
    except AttributeError:
        style_ui_oven_btn_state_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_btn_state_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_btn_state_main_main_default.set_img_recolor(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_btn_state_main_main_default.set_img_recolor_opa(255)
style_ui_oven_btn_state_main_main_default.set_img_opa(255)

# add style for ui_Oven_Btn_State
ui_Oven_Btn_State.add_style(style_ui_oven_btn_state_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_btn_state_main_main_checked
style_ui_oven_btn_state_main_main_checked = lv.style_t()
style_ui_oven_btn_state_main_main_checked.init()
style_ui_oven_btn_state_main_main_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_btn_state_main_main_checked.set_text_font(lv.font_Antonio_Regular_26)
except AttributeError:
    try:
        style_ui_oven_btn_state_main_main_checked.set_text_font(lv.font_montserrat_26)
    except AttributeError:
        style_ui_oven_btn_state_main_main_checked.set_text_font(lv.font_montserrat_16)
style_ui_oven_btn_state_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_btn_state_main_main_checked.set_img_recolor(lv.color_make(0x35,0xC9,0x15))
style_ui_oven_btn_state_main_main_checked.set_img_recolor_opa(255)
style_ui_oven_btn_state_main_main_checked.set_img_opa(255)

# add style for ui_Oven_Btn_State
ui_Oven_Btn_State.add_style(style_ui_oven_btn_state_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

ui_Oven_Label_Settings = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Settings.set_pos(int(206),int(395))
ui_Oven_Label_Settings.set_size(118,46)
ui_Oven_Label_Settings.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Settings.set_text("SETTINGS")
ui_Oven_Label_Settings.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_settings_main_main_default
style_ui_oven_label_settings_main_main_default = lv.style_t()
style_ui_oven_label_settings_main_main_default.init()
style_ui_oven_label_settings_main_main_default.set_radius(0)
style_ui_oven_label_settings_main_main_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_label_settings_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_settings_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_settings_main_main_default.set_bg_opa(0)
style_ui_oven_label_settings_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_settings_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_oven_label_settings_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_oven_label_settings_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_settings_main_main_default.set_text_letter_space(2)
style_ui_oven_label_settings_main_main_default.set_text_line_space(0)
style_ui_oven_label_settings_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_settings_main_main_default.set_pad_left(0)
style_ui_oven_label_settings_main_main_default.set_pad_right(0)
style_ui_oven_label_settings_main_main_default.set_pad_top(8)
style_ui_oven_label_settings_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Settings
ui_Oven_Label_Settings.add_style(style_ui_oven_label_settings_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_TimeLeft = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_TimeLeft.set_pos(int(319),int(130))
ui_Oven_Label_TimeLeft.set_size(109,51)
ui_Oven_Label_TimeLeft.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_TimeLeft.set_text("15")
ui_Oven_Label_TimeLeft.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_timeleft_main_main_default
style_ui_oven_label_timeleft_main_main_default = lv.style_t()
style_ui_oven_label_timeleft_main_main_default.init()
style_ui_oven_label_timeleft_main_main_default.set_radius(0)
style_ui_oven_label_timeleft_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_timeleft_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_timeleft_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_timeleft_main_main_default.set_bg_opa(0)
style_ui_oven_label_timeleft_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_timeleft_main_main_default.set_text_font(lv.font_Antonio_Regular_40)
except AttributeError:
    try:
        style_ui_oven_label_timeleft_main_main_default.set_text_font(lv.font_montserrat_40)
    except AttributeError:
        style_ui_oven_label_timeleft_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_timeleft_main_main_default.set_text_letter_space(2)
style_ui_oven_label_timeleft_main_main_default.set_text_line_space(0)
style_ui_oven_label_timeleft_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_timeleft_main_main_default.set_pad_left(0)
style_ui_oven_label_timeleft_main_main_default.set_pad_right(0)
style_ui_oven_label_timeleft_main_main_default.set_pad_top(8)
style_ui_oven_label_timeleft_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_TimeLeft
ui_Oven_Label_TimeLeft.add_style(style_ui_oven_label_timeleft_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Min = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Min.set_pos(int(393),int(146))
ui_Oven_Label_Min.set_size(63,32)
ui_Oven_Label_Min.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Min.set_text("mins")
ui_Oven_Label_Min.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_min_main_main_default
style_ui_oven_label_min_main_main_default = lv.style_t()
style_ui_oven_label_min_main_main_default.init()
style_ui_oven_label_min_main_main_default.set_radius(0)
style_ui_oven_label_min_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_min_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_min_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_min_main_main_default.set_bg_opa(0)
style_ui_oven_label_min_main_main_default.set_text_color(lv.color_make(0xc9,0xc5,0xc5))
try:
    style_ui_oven_label_min_main_main_default.set_text_font(lv.font_Alatsi_Regular_23)
except AttributeError:
    try:
        style_ui_oven_label_min_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_ui_oven_label_min_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_min_main_main_default.set_text_letter_space(2)
style_ui_oven_label_min_main_main_default.set_text_line_space(0)
style_ui_oven_label_min_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_min_main_main_default.set_pad_left(0)
style_ui_oven_label_min_main_main_default.set_pad_right(0)
style_ui_oven_label_min_main_main_default.set_pad_top(8)
style_ui_oven_label_min_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Min
ui_Oven_Label_Min.add_style(style_ui_oven_label_min_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_group_oven_main_main_default
style_ui_oven_group_oven_main_main_default = lv.style_t()
style_ui_oven_group_oven_main_main_default.init()
style_ui_oven_group_oven_main_main_default.set_radius(20)
style_ui_oven_group_oven_main_main_default.set_bg_color(lv.color_make(0x18,0x18,0x18))
style_ui_oven_group_oven_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_ui_oven_group_oven_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_group_oven_main_main_default.set_bg_opa(255)
style_ui_oven_group_oven_main_main_default.set_border_color(lv.color_make(0x4A,0x48,0x4A))
style_ui_oven_group_oven_main_main_default.set_border_width(2)
style_ui_oven_group_oven_main_main_default.set_border_opa(0)
style_ui_oven_group_oven_main_main_default.set_pad_left(0)
style_ui_oven_group_oven_main_main_default.set_pad_right(0)
style_ui_oven_group_oven_main_main_default.set_pad_top(0)
style_ui_oven_group_oven_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Group_Oven
ui_Oven_Group_Oven.add_style(style_ui_oven_group_oven_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode = lv.tileview(ui_Oven)
ui_Oven_Tile_Mode.set_pos(int(728),int(294))
ui_Oven_Tile_Mode.set_size(430,86)
ui_Oven_Tile_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.ON)
ui_Oven_Tile_Mode_Mode_9 = ui_Oven_Tile_Mode.add_tile(8 , 0, lv.DIR.LEFT)
ui_Oven_Img_Mode9 = lv.img(ui_Oven_Tile_Mode_Mode_9)
ui_Oven_Img_Mode9.set_pos(int(134),int(12))
ui_Oven_Img_Mode9.set_size(62,62)
ui_Oven_Img_Mode9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-175755905.png','rb') as f:
        ui_Oven_Img_Mode9_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-175755905.png')
    sys.exit()

ui_Oven_Img_Mode9_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode9_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode9_img_data
})

ui_Oven_Img_Mode9.set_src(ui_Oven_Img_Mode9_img)
ui_Oven_Img_Mode9.set_pivot(50,50)
ui_Oven_Img_Mode9.set_angle(0)
# create style style_ui_oven_img_mode9_main_main_default
style_ui_oven_img_mode9_main_main_default = lv.style_t()
style_ui_oven_img_mode9_main_main_default.init()
style_ui_oven_img_mode9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode9_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode9_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode9
ui_Oven_Img_Mode9.add_style(style_ui_oven_img_mode9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode9 = lv.label(ui_Oven_Tile_Mode_Mode_9)
ui_Oven_Label_Mode9.set_pos(int(220),int(22))
ui_Oven_Label_Mode9.set_size(141,34)
ui_Oven_Label_Mode9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode9.set_text("Defrost")
ui_Oven_Label_Mode9.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode9_main_main_default
style_ui_oven_label_mode9_main_main_default = lv.style_t()
style_ui_oven_label_mode9_main_main_default.init()
style_ui_oven_label_mode9_main_main_default.set_radius(0)
style_ui_oven_label_mode9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode9_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode9_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode9_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode9_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode9_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode9_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode9_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode9_main_main_default.set_pad_left(0)
style_ui_oven_label_mode9_main_main_default.set_pad_right(0)
style_ui_oven_label_mode9_main_main_default.set_pad_top(8)
style_ui_oven_label_mode9_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode9
ui_Oven_Label_Mode9.add_style(style_ui_oven_label_mode9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_8 = ui_Oven_Tile_Mode.add_tile(7 , 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Img_Mode8 = lv.img(ui_Oven_Tile_Mode_Mode_8)
ui_Oven_Img_Mode8.set_pos(int(134),int(12))
ui_Oven_Img_Mode8.set_size(62,62)
ui_Oven_Img_Mode8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp724664477.png','rb') as f:
        ui_Oven_Img_Mode8_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp724664477.png')
    sys.exit()

ui_Oven_Img_Mode8_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode8_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode8_img_data
})

ui_Oven_Img_Mode8.set_src(ui_Oven_Img_Mode8_img)
ui_Oven_Img_Mode8.set_pivot(50,50)
ui_Oven_Img_Mode8.set_angle(0)
# create style style_ui_oven_img_mode8_main_main_default
style_ui_oven_img_mode8_main_main_default = lv.style_t()
style_ui_oven_img_mode8_main_main_default.init()
style_ui_oven_img_mode8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode8_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode8_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode8
ui_Oven_Img_Mode8.add_style(style_ui_oven_img_mode8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode8 = lv.label(ui_Oven_Tile_Mode_Mode_8)
ui_Oven_Label_Mode8.set_pos(int(211),int(17))
ui_Oven_Label_Mode8.set_size(141,52)
ui_Oven_Label_Mode8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode8.set_text("Lower Outer\nElement")
ui_Oven_Label_Mode8.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode8_main_main_default
style_ui_oven_label_mode8_main_main_default = lv.style_t()
style_ui_oven_label_mode8_main_main_default.init()
style_ui_oven_label_mode8_main_main_default.set_radius(0)
style_ui_oven_label_mode8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode8_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode8_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode8_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode8_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode8_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode8_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode8_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode8_main_main_default.set_pad_left(0)
style_ui_oven_label_mode8_main_main_default.set_pad_right(0)
style_ui_oven_label_mode8_main_main_default.set_pad_top(8)
style_ui_oven_label_mode8_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode8
ui_Oven_Label_Mode8.add_style(style_ui_oven_label_mode8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_7 = ui_Oven_Tile_Mode.add_tile(6 , 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Img_Mode7 = lv.img(ui_Oven_Tile_Mode_Mode_7)
ui_Oven_Img_Mode7.set_pos(int(134),int(12))
ui_Oven_Img_Mode7.set_size(62,62)
ui_Oven_Img_Mode7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-23454914.png','rb') as f:
        ui_Oven_Img_Mode7_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-23454914.png')
    sys.exit()

ui_Oven_Img_Mode7_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode7_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode7_img_data
})

ui_Oven_Img_Mode7.set_src(ui_Oven_Img_Mode7_img)
ui_Oven_Img_Mode7.set_pivot(50,50)
ui_Oven_Img_Mode7.set_angle(0)
# create style style_ui_oven_img_mode7_main_main_default
style_ui_oven_img_mode7_main_main_default = lv.style_t()
style_ui_oven_img_mode7_main_main_default.init()
style_ui_oven_img_mode7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode7_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode7_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode7
ui_Oven_Img_Mode7.add_style(style_ui_oven_img_mode7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode7 = lv.label(ui_Oven_Tile_Mode_Mode_7)
ui_Oven_Label_Mode7.set_pos(int(211),int(17))
ui_Oven_Label_Mode7.set_size(141,52)
ui_Oven_Label_Mode7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode7.set_text("Upper Outer\nElement")
ui_Oven_Label_Mode7.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode7_main_main_default
style_ui_oven_label_mode7_main_main_default = lv.style_t()
style_ui_oven_label_mode7_main_main_default.init()
style_ui_oven_label_mode7_main_main_default.set_radius(0)
style_ui_oven_label_mode7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode7_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode7_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode7_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode7_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode7_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode7_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode7_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode7_main_main_default.set_pad_left(0)
style_ui_oven_label_mode7_main_main_default.set_pad_right(0)
style_ui_oven_label_mode7_main_main_default.set_pad_top(8)
style_ui_oven_label_mode7_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode7
ui_Oven_Label_Mode7.add_style(style_ui_oven_label_mode7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_6 = ui_Oven_Tile_Mode.add_tile(5 , 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Img_Mode6 = lv.img(ui_Oven_Tile_Mode_Mode_6)
ui_Oven_Img_Mode6.set_pos(int(134),int(12))
ui_Oven_Img_Mode6.set_size(62,62)
ui_Oven_Img_Mode6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp876849070.png','rb') as f:
        ui_Oven_Img_Mode6_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp876849070.png')
    sys.exit()

ui_Oven_Img_Mode6_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode6_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode6_img_data
})

ui_Oven_Img_Mode6.set_src(ui_Oven_Img_Mode6_img)
ui_Oven_Img_Mode6.set_pivot(50,50)
ui_Oven_Img_Mode6.set_angle(0)
# create style style_ui_oven_img_mode6_main_main_default
style_ui_oven_img_mode6_main_main_default = lv.style_t()
style_ui_oven_img_mode6_main_main_default.init()
style_ui_oven_img_mode6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode6_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode6_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode6
ui_Oven_Img_Mode6.add_style(style_ui_oven_img_mode6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode6 = lv.label(ui_Oven_Tile_Mode_Mode_6)
ui_Oven_Label_Mode6.set_pos(int(211),int(17))
ui_Oven_Label_Mode6.set_size(141,52)
ui_Oven_Label_Mode6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode6.set_text("Fan Forced\nGrill")
ui_Oven_Label_Mode6.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode6_main_main_default
style_ui_oven_label_mode6_main_main_default = lv.style_t()
style_ui_oven_label_mode6_main_main_default.init()
style_ui_oven_label_mode6_main_main_default.set_radius(0)
style_ui_oven_label_mode6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode6_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode6_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode6_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode6_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode6_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode6_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode6_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode6_main_main_default.set_pad_left(0)
style_ui_oven_label_mode6_main_main_default.set_pad_right(0)
style_ui_oven_label_mode6_main_main_default.set_pad_top(8)
style_ui_oven_label_mode6_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode6
ui_Oven_Label_Mode6.add_style(style_ui_oven_label_mode6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_5 = ui_Oven_Tile_Mode.add_tile(4 , 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Img_Mode5 = lv.img(ui_Oven_Tile_Mode_Mode_5)
ui_Oven_Img_Mode5.set_pos(int(134),int(12))
ui_Oven_Img_Mode5.set_size(62,62)
ui_Oven_Img_Mode5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-84176894.png','rb') as f:
        ui_Oven_Img_Mode5_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-84176894.png')
    sys.exit()

ui_Oven_Img_Mode5_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode5_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode5_img_data
})

ui_Oven_Img_Mode5.set_src(ui_Oven_Img_Mode5_img)
ui_Oven_Img_Mode5.set_pivot(50,50)
ui_Oven_Img_Mode5.set_angle(0)
# create style style_ui_oven_img_mode5_main_main_default
style_ui_oven_img_mode5_main_main_default = lv.style_t()
style_ui_oven_img_mode5_main_main_default.init()
style_ui_oven_img_mode5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode5_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode5_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode5
ui_Oven_Img_Mode5.add_style(style_ui_oven_img_mode5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode5 = lv.label(ui_Oven_Tile_Mode_Mode_5)
ui_Oven_Label_Mode5.set_pos(int(220),int(22))
ui_Oven_Label_Mode5.set_size(141,34)
ui_Oven_Label_Mode5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode5.set_text("Grill")
ui_Oven_Label_Mode5.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode5_main_main_default
style_ui_oven_label_mode5_main_main_default = lv.style_t()
style_ui_oven_label_mode5_main_main_default.init()
style_ui_oven_label_mode5_main_main_default.set_radius(0)
style_ui_oven_label_mode5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode5_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode5_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode5_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode5_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode5_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode5_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode5_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode5_main_main_default.set_pad_left(0)
style_ui_oven_label_mode5_main_main_default.set_pad_right(0)
style_ui_oven_label_mode5_main_main_default.set_pad_top(8)
style_ui_oven_label_mode5_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode5
ui_Oven_Label_Mode5.add_style(style_ui_oven_label_mode5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_4 = ui_Oven_Tile_Mode.add_tile(3 , 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Img_Mode4 = lv.img(ui_Oven_Tile_Mode_Mode_4)
ui_Oven_Img_Mode4.set_pos(int(134),int(12))
ui_Oven_Img_Mode4.set_size(62,62)
ui_Oven_Img_Mode4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp451698289.png','rb') as f:
        ui_Oven_Img_Mode4_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp451698289.png')
    sys.exit()

ui_Oven_Img_Mode4_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode4_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode4_img_data
})

ui_Oven_Img_Mode4.set_src(ui_Oven_Img_Mode4_img)
ui_Oven_Img_Mode4.set_pivot(50,50)
ui_Oven_Img_Mode4.set_angle(0)
# create style style_ui_oven_img_mode4_main_main_default
style_ui_oven_img_mode4_main_main_default = lv.style_t()
style_ui_oven_img_mode4_main_main_default.init()
style_ui_oven_img_mode4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode4_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode4_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode4
ui_Oven_Img_Mode4.add_style(style_ui_oven_img_mode4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode4 = lv.label(ui_Oven_Tile_Mode_Mode_4)
ui_Oven_Label_Mode4.set_pos(int(211),int(7))
ui_Oven_Label_Mode4.set_size(141,66)
ui_Oven_Label_Mode4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode4.set_text("Fan Forced\nLower Element\nConvection")
ui_Oven_Label_Mode4.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode4_main_main_default
style_ui_oven_label_mode4_main_main_default = lv.style_t()
style_ui_oven_label_mode4_main_main_default.init()
style_ui_oven_label_mode4_main_main_default.set_radius(0)
style_ui_oven_label_mode4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode4_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode4_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode4_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode4_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode4_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode4_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode4_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode4_main_main_default.set_pad_left(0)
style_ui_oven_label_mode4_main_main_default.set_pad_right(0)
style_ui_oven_label_mode4_main_main_default.set_pad_top(8)
style_ui_oven_label_mode4_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode4
ui_Oven_Label_Mode4.add_style(style_ui_oven_label_mode4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_3 = ui_Oven_Tile_Mode.add_tile(2 , 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Label_Mode3 = lv.label(ui_Oven_Tile_Mode_Mode_3)
ui_Oven_Label_Mode3.set_pos(int(211),int(7))
ui_Oven_Label_Mode3.set_size(141,66)
ui_Oven_Label_Mode3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode3.set_text("Fan Forced\nUpper & Lower\nConvection")
ui_Oven_Label_Mode3.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode3_main_main_default
style_ui_oven_label_mode3_main_main_default = lv.style_t()
style_ui_oven_label_mode3_main_main_default.init()
style_ui_oven_label_mode3_main_main_default.set_radius(0)
style_ui_oven_label_mode3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode3_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode3_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode3_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode3_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode3_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode3_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode3_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode3_main_main_default.set_pad_left(0)
style_ui_oven_label_mode3_main_main_default.set_pad_right(0)
style_ui_oven_label_mode3_main_main_default.set_pad_top(8)
style_ui_oven_label_mode3_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode3
ui_Oven_Label_Mode3.add_style(style_ui_oven_label_mode3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Img_Mode3 = lv.img(ui_Oven_Tile_Mode_Mode_3)
ui_Oven_Img_Mode3.set_pos(int(134),int(12))
ui_Oven_Img_Mode3.set_size(62,62)
ui_Oven_Img_Mode3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-456369772.png','rb') as f:
        ui_Oven_Img_Mode3_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-456369772.png')
    sys.exit()

ui_Oven_Img_Mode3_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode3_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode3_img_data
})

ui_Oven_Img_Mode3.set_src(ui_Oven_Img_Mode3_img)
ui_Oven_Img_Mode3.set_pivot(50,50)
ui_Oven_Img_Mode3.set_angle(0)
# create style style_ui_oven_img_mode3_main_main_default
style_ui_oven_img_mode3_main_main_default = lv.style_t()
style_ui_oven_img_mode3_main_main_default.init()
style_ui_oven_img_mode3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode3_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode3_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode3
ui_Oven_Img_Mode3.add_style(style_ui_oven_img_mode3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_2 = ui_Oven_Tile_Mode.add_tile(1 , 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Img_Mode2 = lv.img(ui_Oven_Tile_Mode_Mode_2)
ui_Oven_Img_Mode2.set_pos(int(134),int(12))
ui_Oven_Img_Mode2.set_size(62,62)
ui_Oven_Img_Mode2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1732105536.png','rb') as f:
        ui_Oven_Img_Mode2_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1732105536.png')
    sys.exit()

ui_Oven_Img_Mode2_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode2_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode2_img_data
})

ui_Oven_Img_Mode2.set_src(ui_Oven_Img_Mode2_img)
ui_Oven_Img_Mode2.set_pivot(50,50)
ui_Oven_Img_Mode2.set_angle(0)
# create style style_ui_oven_img_mode2_main_main_default
style_ui_oven_img_mode2_main_main_default = lv.style_t()
style_ui_oven_img_mode2_main_main_default.init()
style_ui_oven_img_mode2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode2_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode2_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode2
ui_Oven_Img_Mode2.add_style(style_ui_oven_img_mode2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode2 = lv.label(ui_Oven_Tile_Mode_Mode_2)
ui_Oven_Label_Mode2.set_pos(int(211),int(7))
ui_Oven_Label_Mode2.set_size(141,66)
ui_Oven_Label_Mode2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode2.set_text("Upper & Lower\nElements\nConvection")
ui_Oven_Label_Mode2.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode2_main_main_default
style_ui_oven_label_mode2_main_main_default = lv.style_t()
style_ui_oven_label_mode2_main_main_default.init()
style_ui_oven_label_mode2_main_main_default.set_radius(0)
style_ui_oven_label_mode2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode2_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode2_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode2_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode2_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode2_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode2_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode2_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode2_main_main_default.set_pad_left(0)
style_ui_oven_label_mode2_main_main_default.set_pad_right(0)
style_ui_oven_label_mode2_main_main_default.set_pad_top(8)
style_ui_oven_label_mode2_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode2
ui_Oven_Label_Mode2.add_style(style_ui_oven_label_mode2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Tile_Mode_Mode_1 = ui_Oven_Tile_Mode.add_tile(0, 0, lv.DIR.RIGHT)
ui_Oven_Img_Mode1 = lv.img(ui_Oven_Tile_Mode_Mode_1)
ui_Oven_Img_Mode1.set_pos(int(134),int(12))
ui_Oven_Img_Mode1.set_size(62,62)
ui_Oven_Img_Mode1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_Mode1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1367845884.png','rb') as f:
        ui_Oven_Img_Mode1_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1367845884.png')
    sys.exit()

ui_Oven_Img_Mode1_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_Mode1_img_data),
  'header': {'always_zero': 0, 'w': 62, 'h': 62, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_Mode1_img_data
})

ui_Oven_Img_Mode1.set_src(ui_Oven_Img_Mode1_img)
ui_Oven_Img_Mode1.set_pivot(50,50)
ui_Oven_Img_Mode1.set_angle(0)
# create style style_ui_oven_img_mode1_main_main_default
style_ui_oven_img_mode1_main_main_default = lv.style_t()
style_ui_oven_img_mode1_main_main_default.init()
style_ui_oven_img_mode1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_mode1_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_mode1_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_Mode1
ui_Oven_Img_Mode1.add_style(style_ui_oven_img_mode1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_Mode1 = lv.label(ui_Oven_Tile_Mode_Mode_1)
ui_Oven_Label_Mode1.set_pos(int(211),int(17))
ui_Oven_Label_Mode1.set_size(141,52)
ui_Oven_Label_Mode1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_Mode1.set_text("Fan Forced\nRear Element")
ui_Oven_Label_Mode1.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_mode1_main_main_default
style_ui_oven_label_mode1_main_main_default = lv.style_t()
style_ui_oven_label_mode1_main_main_default.init()
style_ui_oven_label_mode1_main_main_default.set_radius(0)
style_ui_oven_label_mode1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_mode1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_mode1_main_main_default.set_bg_opa(0)
style_ui_oven_label_mode1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_oven_label_mode1_main_main_default.set_text_font(lv.font_Antonio_Regular_18)
except AttributeError:
    try:
        style_ui_oven_label_mode1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_ui_oven_label_mode1_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_mode1_main_main_default.set_text_letter_space(2)
style_ui_oven_label_mode1_main_main_default.set_text_line_space(0)
style_ui_oven_label_mode1_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_ui_oven_label_mode1_main_main_default.set_pad_left(0)
style_ui_oven_label_mode1_main_main_default.set_pad_right(0)
style_ui_oven_label_mode1_main_main_default.set_pad_top(8)
style_ui_oven_label_mode1_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_Mode1
ui_Oven_Label_Mode1.add_style(style_ui_oven_label_mode1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_tile_mode_main_main_default
style_ui_oven_tile_mode_main_main_default = lv.style_t()
style_ui_oven_tile_mode_main_main_default.init()
style_ui_oven_tile_mode_main_main_default.set_radius(0)
style_ui_oven_tile_mode_main_main_default.set_bg_color(lv.color_make(0xf6,0xf6,0xf6))
style_ui_oven_tile_mode_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0xf6,0xf6))
style_ui_oven_tile_mode_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_tile_mode_main_main_default.set_bg_opa(0)

# add style for ui_Oven_Tile_Mode
ui_Oven_Tile_Mode.add_style(style_ui_oven_tile_mode_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_tile_mode_main_scrollbar_default
style_ui_oven_tile_mode_main_scrollbar_default = lv.style_t()
style_ui_oven_tile_mode_main_scrollbar_default.init()
style_ui_oven_tile_mode_main_scrollbar_default.set_radius(0)
style_ui_oven_tile_mode_main_scrollbar_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_ui_oven_tile_mode_main_scrollbar_default.set_bg_opa(0)

# add style for ui_Oven_Tile_Mode
ui_Oven_Tile_Mode.add_style(style_ui_oven_tile_mode_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

ui_Oven_Group_TarTemp = lv.obj(ui_Oven)
ui_Oven_Group_TarTemp.set_pos(int(697),int(427))
ui_Oven_Group_TarTemp.set_size(235,240)
ui_Oven_Group_TarTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_TempWheel = lv.img(ui_Oven_Group_TarTemp)
ui_Oven_Img_TempWheel.set_pos(int(51),int(-11))
ui_Oven_Img_TempWheel.set_size(151,259)
ui_Oven_Img_TempWheel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_TempWheel.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp466056730.png','rb') as f:
        ui_Oven_Img_TempWheel_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp466056730.png')
    sys.exit()

ui_Oven_Img_TempWheel_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_TempWheel_img_data),
  'header': {'always_zero': 0, 'w': 151, 'h': 259, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_TempWheel_img_data
})

ui_Oven_Img_TempWheel.set_src(ui_Oven_Img_TempWheel_img)
ui_Oven_Img_TempWheel.set_pivot(50,50)
ui_Oven_Img_TempWheel.set_angle(0)
# create style style_ui_oven_img_tempwheel_main_main_default
style_ui_oven_img_tempwheel_main_main_default = lv.style_t()
style_ui_oven_img_tempwheel_main_main_default.init()
style_ui_oven_img_tempwheel_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_tempwheel_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_tempwheel_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_TempWheel
ui_Oven_Img_TempWheel.add_style(style_ui_oven_img_tempwheel_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_SelTemp = lv.label(ui_Oven_Group_TarTemp)
ui_Oven_Label_SelTemp.set_pos(int(-11),int(91))
ui_Oven_Label_SelTemp.set_size(118,53)
ui_Oven_Label_SelTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_SelTemp.set_text("TARGET\nTEMP.")
ui_Oven_Label_SelTemp.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_seltemp_main_main_default
style_ui_oven_label_seltemp_main_main_default = lv.style_t()
style_ui_oven_label_seltemp_main_main_default.init()
style_ui_oven_label_seltemp_main_main_default.set_radius(0)
style_ui_oven_label_seltemp_main_main_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_label_seltemp_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_seltemp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_seltemp_main_main_default.set_bg_opa(0)
style_ui_oven_label_seltemp_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_seltemp_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_oven_label_seltemp_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_oven_label_seltemp_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_seltemp_main_main_default.set_text_letter_space(2)
style_ui_oven_label_seltemp_main_main_default.set_text_line_space(0)
style_ui_oven_label_seltemp_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_seltemp_main_main_default.set_pad_left(0)
style_ui_oven_label_seltemp_main_main_default.set_pad_right(0)
style_ui_oven_label_seltemp_main_main_default.set_pad_top(8)
style_ui_oven_label_seltemp_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_SelTemp
ui_Oven_Label_SelTemp.add_style(style_ui_oven_label_seltemp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_TarCen = lv.label(ui_Oven_Group_TarTemp)
ui_Oven_Label_TarCen.set_pos(int(68),int(111))
ui_Oven_Label_TarCen.set_size(55,32)
ui_Oven_Label_TarCen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_TarCen.set_text("ºC")
ui_Oven_Label_TarCen.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_tarcen_main_main_default
style_ui_oven_label_tarcen_main_main_default = lv.style_t()
style_ui_oven_label_tarcen_main_main_default.init()
style_ui_oven_label_tarcen_main_main_default.set_radius(0)
style_ui_oven_label_tarcen_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_tarcen_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_tarcen_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_tarcen_main_main_default.set_bg_opa(0)
style_ui_oven_label_tarcen_main_main_default.set_text_color(lv.color_make(0xc9,0xc5,0xc5))
try:
    style_ui_oven_label_tarcen_main_main_default.set_text_font(lv.font_Alatsi_Regular_23)
except AttributeError:
    try:
        style_ui_oven_label_tarcen_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_ui_oven_label_tarcen_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_tarcen_main_main_default.set_text_letter_space(2)
style_ui_oven_label_tarcen_main_main_default.set_text_line_space(0)
style_ui_oven_label_tarcen_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_tarcen_main_main_default.set_pad_left(0)
style_ui_oven_label_tarcen_main_main_default.set_pad_right(0)
style_ui_oven_label_tarcen_main_main_default.set_pad_top(8)
style_ui_oven_label_tarcen_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_TarCen
ui_Oven_Label_TarCen.add_style(style_ui_oven_label_tarcen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_group_tartemp_main_main_default
style_ui_oven_group_tartemp_main_main_default = lv.style_t()
style_ui_oven_group_tartemp_main_main_default.init()
style_ui_oven_group_tartemp_main_main_default.set_radius(0)
style_ui_oven_group_tartemp_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_ui_oven_group_tartemp_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_ui_oven_group_tartemp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_group_tartemp_main_main_default.set_bg_opa(0)
style_ui_oven_group_tartemp_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_group_tartemp_main_main_default.set_border_width(2)
style_ui_oven_group_tartemp_main_main_default.set_border_opa(0)
style_ui_oven_group_tartemp_main_main_default.set_pad_left(0)
style_ui_oven_group_tartemp_main_main_default.set_pad_right(0)
style_ui_oven_group_tartemp_main_main_default.set_pad_top(0)
style_ui_oven_group_tartemp_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Group_TarTemp
ui_Oven_Group_TarTemp.add_style(style_ui_oven_group_tartemp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Group_Timer = lv.obj(ui_Oven)
ui_Oven_Group_Timer.set_pos(int(957),int(427))
ui_Oven_Group_Timer.set_size(235,240)
ui_Oven_Group_Timer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_TimerWheel = lv.img(ui_Oven_Group_Timer)
ui_Oven_Img_TimerWheel.set_pos(int(39),int(-11))
ui_Oven_Img_TimerWheel.set_size(151,259)
ui_Oven_Img_TimerWheel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Img_TimerWheel.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp150866893.png','rb') as f:
        ui_Oven_Img_TimerWheel_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp150866893.png')
    sys.exit()

ui_Oven_Img_TimerWheel_img = lv.img_dsc_t({
  'data_size': len(ui_Oven_Img_TimerWheel_img_data),
  'header': {'always_zero': 0, 'w': 151, 'h': 259, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Oven_Img_TimerWheel_img_data
})

ui_Oven_Img_TimerWheel.set_src(ui_Oven_Img_TimerWheel_img)
ui_Oven_Img_TimerWheel.set_pivot(50,50)
ui_Oven_Img_TimerWheel.set_angle(0)
# create style style_ui_oven_img_timerwheel_main_main_default
style_ui_oven_img_timerwheel_main_main_default = lv.style_t()
style_ui_oven_img_timerwheel_main_main_default.init()
style_ui_oven_img_timerwheel_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_oven_img_timerwheel_main_main_default.set_img_recolor_opa(0)
style_ui_oven_img_timerwheel_main_main_default.set_img_opa(255)

# add style for ui_Oven_Img_TimerWheel
ui_Oven_Img_TimerWheel.add_style(style_ui_oven_img_timerwheel_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_SelTimer = lv.label(ui_Oven_Group_Timer)
ui_Oven_Label_SelTimer.set_pos(int(148),int(91))
ui_Oven_Label_SelTimer.set_size(104,53)
ui_Oven_Label_SelTimer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_SelTimer.set_text("SETUP\nTIMER")
ui_Oven_Label_SelTimer.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_seltimer_main_main_default
style_ui_oven_label_seltimer_main_main_default = lv.style_t()
style_ui_oven_label_seltimer_main_main_default.init()
style_ui_oven_label_seltimer_main_main_default.set_radius(0)
style_ui_oven_label_seltimer_main_main_default.set_bg_color(lv.color_make(0xFF,0x91,0x10))
style_ui_oven_label_seltimer_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_seltimer_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_seltimer_main_main_default.set_bg_opa(0)
style_ui_oven_label_seltimer_main_main_default.set_text_color(lv.color_make(0xFF,0x91,0x10))
try:
    style_ui_oven_label_seltimer_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_oven_label_seltimer_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_oven_label_seltimer_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_seltimer_main_main_default.set_text_letter_space(2)
style_ui_oven_label_seltimer_main_main_default.set_text_line_space(0)
style_ui_oven_label_seltimer_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_seltimer_main_main_default.set_pad_left(0)
style_ui_oven_label_seltimer_main_main_default.set_pad_right(0)
style_ui_oven_label_seltimer_main_main_default.set_pad_top(8)
style_ui_oven_label_seltimer_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_SelTimer
ui_Oven_Label_SelTimer.add_style(style_ui_oven_label_seltimer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven_Label_TimerSel = lv.label(ui_Oven_Group_Timer)
ui_Oven_Label_TimerSel.set_pos(int(114),int(108))
ui_Oven_Label_TimerSel.set_size(63,32)
ui_Oven_Label_TimerSel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Oven_Label_TimerSel.set_text("mins")
ui_Oven_Label_TimerSel.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_oven_label_timersel_main_main_default
style_ui_oven_label_timersel_main_main_default = lv.style_t()
style_ui_oven_label_timersel_main_main_default.init()
style_ui_oven_label_timersel_main_main_default.set_radius(0)
style_ui_oven_label_timersel_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_timersel_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_label_timersel_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_label_timersel_main_main_default.set_bg_opa(0)
style_ui_oven_label_timersel_main_main_default.set_text_color(lv.color_make(0xc9,0xc5,0xc5))
try:
    style_ui_oven_label_timersel_main_main_default.set_text_font(lv.font_Alatsi_Regular_23)
except AttributeError:
    try:
        style_ui_oven_label_timersel_main_main_default.set_text_font(lv.font_montserrat_23)
    except AttributeError:
        style_ui_oven_label_timersel_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_oven_label_timersel_main_main_default.set_text_letter_space(2)
style_ui_oven_label_timersel_main_main_default.set_text_line_space(0)
style_ui_oven_label_timersel_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_oven_label_timersel_main_main_default.set_pad_left(0)
style_ui_oven_label_timersel_main_main_default.set_pad_right(0)
style_ui_oven_label_timersel_main_main_default.set_pad_top(8)
style_ui_oven_label_timersel_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Label_TimerSel
ui_Oven_Label_TimerSel.add_style(style_ui_oven_label_timersel_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_oven_group_timer_main_main_default
style_ui_oven_group_timer_main_main_default = lv.style_t()
style_ui_oven_group_timer_main_main_default.init()
style_ui_oven_group_timer_main_main_default.set_radius(0)
style_ui_oven_group_timer_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_ui_oven_group_timer_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_ui_oven_group_timer_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_oven_group_timer_main_main_default.set_bg_opa(0)
style_ui_oven_group_timer_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_oven_group_timer_main_main_default.set_border_width(2)
style_ui_oven_group_timer_main_main_default.set_border_opa(0)
style_ui_oven_group_timer_main_main_default.set_pad_left(0)
style_ui_oven_group_timer_main_main_default.set_pad_right(0)
style_ui_oven_group_timer_main_main_default.set_pad_top(0)
style_ui_oven_group_timer_main_main_default.set_pad_bottom(0)

# add style for ui_Oven_Group_Timer
ui_Oven_Group_Timer.add_style(style_ui_oven_group_timer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

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
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1062060990.png','rb') as f:
        ui_Aircon_Img_Bg_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-1062060990.png')
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
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-729390869.png','rb') as f:
        ui_Aircon_Img_Lable_Bg_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-729390869.png')
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
    style_ui_aircon_label_air_main_main_default.set_text_font(lv.font_Antonio_Regular_22)
except AttributeError:
    try:
        style_ui_aircon_label_air_main_main_default.set_text_font(lv.font_montserrat_22)
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

ui_Aircon_Img_Swing = lv.img(ui_Aircon)
ui_Aircon_Img_Swing.set_pos(int(120),int(380))
ui_Aircon_Img_Swing.set_size(632,113)
ui_Aircon_Img_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_Swing.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp388186255.png','rb') as f:
        ui_Aircon_Img_Swing_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp388186255.png')
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

ui_Aircon_Cont = lv.obj(ui_Aircon)
ui_Aircon_Cont.set_pos(int(826),int(30))
ui_Aircon_Cont.set_size(409,657)
ui_Aircon_Cont.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_line = lv.line(ui_Aircon_Cont)
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

ui_Aircon_Label_Temp = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Temp.set_pos(int(12),int(58))
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

ui_Aircon_Btn_TempUp = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TempUp.set_pos(int(198),int(100))
ui_Aircon_Btn_TempUp.set_size(74,58)
ui_Aircon_Btn_TempUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_aircon_btn_tempup_main_main_default
style_ui_aircon_btn_tempup_main_main_default = lv.style_t()
style_ui_aircon_btn_tempup_main_main_default.init()
style_ui_aircon_btn_tempup_main_main_default.set_radius(10)
style_ui_aircon_btn_tempup_main_main_default.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_btn_tempup_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempup_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_tempup_main_main_default.set_bg_opa(255)
style_ui_aircon_btn_tempup_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempup_main_main_default.set_border_width(0)
style_ui_aircon_btn_tempup_main_main_default.set_border_opa(255)
style_ui_aircon_btn_tempup_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_tempup_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_tempup_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_tempup_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_btn_tempup_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for ui_Aircon_Btn_TempUp
ui_Aircon_Btn_TempUp.add_style(style_ui_aircon_btn_tempup_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_btn_tempup_main_main_pressed
style_ui_aircon_btn_tempup_main_main_pressed = lv.style_t()
style_ui_aircon_btn_tempup_main_main_pressed.init()
style_ui_aircon_btn_tempup_main_main_pressed.set_radius(10)
style_ui_aircon_btn_tempup_main_main_pressed.set_bg_color(lv.color_make(0x18,0xC2,0x20))
style_ui_aircon_btn_tempup_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempup_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_tempup_main_main_pressed.set_bg_opa(255)
style_ui_aircon_btn_tempup_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempup_main_main_pressed.set_border_width(0)
style_ui_aircon_btn_tempup_main_main_pressed.set_border_opa(255)
style_ui_aircon_btn_tempup_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_tempup_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_tempup_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_tempup_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Btn_TempUp
ui_Aircon_Btn_TempUp.add_style(style_ui_aircon_btn_tempup_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

ui_Aircon_Label_SetTemp = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_SetTemp.set_pos(int(110),int(22))
ui_Aircon_Label_SetTemp.set_size(203,32)
ui_Aircon_Label_SetTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_SetTemp.set_text("SET TEMPERATURE")
ui_Aircon_Label_SetTemp.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_settemp_main_main_default
style_ui_aircon_label_settemp_main_main_default = lv.style_t()
style_ui_aircon_label_settemp_main_main_default.init()
style_ui_aircon_label_settemp_main_main_default.set_radius(0)
style_ui_aircon_label_settemp_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_settemp_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_settemp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_settemp_main_main_default.set_bg_opa(0)
style_ui_aircon_label_settemp_main_main_default.set_text_color(lv.color_make(0x52,0xDA,0xFF))
try:
    style_ui_aircon_label_settemp_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_label_settemp_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_label_settemp_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_settemp_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_settemp_main_main_default.set_text_line_space(0)
style_ui_aircon_label_settemp_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_settemp_main_main_default.set_pad_left(0)
style_ui_aircon_label_settemp_main_main_default.set_pad_right(0)
style_ui_aircon_label_settemp_main_main_default.set_pad_top(8)
style_ui_aircon_label_settemp_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_SetTemp
ui_Aircon_Label_SetTemp.add_style(style_ui_aircon_label_settemp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Cen = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Cen.set_pos(int(121),int(61))
ui_Aircon_Label_Cen.set_size(72,53)
ui_Aircon_Label_Cen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Cen.set_text("ºC")
ui_Aircon_Label_Cen.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_cen_main_main_default
style_ui_aircon_label_cen_main_main_default = lv.style_t()
style_ui_aircon_label_cen_main_main_default.init()
style_ui_aircon_label_cen_main_main_default.set_radius(0)
style_ui_aircon_label_cen_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_cen_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_cen_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_cen_main_main_default.set_bg_opa(0)
style_ui_aircon_label_cen_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_cen_main_main_default.set_text_font(lv.font_Alatsi_Regular_26)
except AttributeError:
    try:
        style_ui_aircon_label_cen_main_main_default.set_text_font(lv.font_montserrat_26)
    except AttributeError:
        style_ui_aircon_label_cen_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_cen_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_cen_main_main_default.set_text_line_space(0)
style_ui_aircon_label_cen_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_cen_main_main_default.set_pad_left(0)
style_ui_aircon_label_cen_main_main_default.set_pad_right(0)
style_ui_aircon_label_cen_main_main_default.set_pad_top(8)
style_ui_aircon_label_cen_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Cen
ui_Aircon_Label_Cen.add_style(style_ui_aircon_label_cen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Btn_TempDown = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TempDown.set_pos(int(295),int(100))
ui_Aircon_Btn_TempDown.set_size(74,58)
ui_Aircon_Btn_TempDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_aircon_btn_tempdown_main_main_default
style_ui_aircon_btn_tempdown_main_main_default = lv.style_t()
style_ui_aircon_btn_tempdown_main_main_default.init()
style_ui_aircon_btn_tempdown_main_main_default.set_radius(10)
style_ui_aircon_btn_tempdown_main_main_default.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_btn_tempdown_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempdown_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_tempdown_main_main_default.set_bg_opa(255)
style_ui_aircon_btn_tempdown_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempdown_main_main_default.set_border_width(0)
style_ui_aircon_btn_tempdown_main_main_default.set_border_opa(255)
style_ui_aircon_btn_tempdown_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_tempdown_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_tempdown_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_tempdown_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_btn_tempdown_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for ui_Aircon_Btn_TempDown
ui_Aircon_Btn_TempDown.add_style(style_ui_aircon_btn_tempdown_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_btn_tempdown_main_main_pressed
style_ui_aircon_btn_tempdown_main_main_pressed = lv.style_t()
style_ui_aircon_btn_tempdown_main_main_pressed.init()
style_ui_aircon_btn_tempdown_main_main_pressed.set_radius(10)
style_ui_aircon_btn_tempdown_main_main_pressed.set_bg_color(lv.color_make(0x18,0xC2,0x20))
style_ui_aircon_btn_tempdown_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempdown_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_tempdown_main_main_pressed.set_bg_opa(255)
style_ui_aircon_btn_tempdown_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_tempdown_main_main_pressed.set_border_width(0)
style_ui_aircon_btn_tempdown_main_main_pressed.set_border_opa(255)
style_ui_aircon_btn_tempdown_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_tempdown_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_tempdown_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_tempdown_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Btn_TempDown
ui_Aircon_Btn_TempDown.add_style(style_ui_aircon_btn_tempdown_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

ui_Aircon_Img_TemUp = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TemUp.set_pos(int(222),int(122))
ui_Aircon_Img_TemUp.set_size(28,14)
ui_Aircon_Img_TemUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_TemUp.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp691787330.png','rb') as f:
        ui_Aircon_Img_TemUp_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp691787330.png')
    sys.exit()

ui_Aircon_Img_TemUp_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_TemUp_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_TemUp_img_data
})

ui_Aircon_Img_TemUp.set_src(ui_Aircon_Img_TemUp_img)
ui_Aircon_Img_TemUp.set_pivot(50,50)
ui_Aircon_Img_TemUp.set_angle(0)
# create style style_ui_aircon_img_temup_main_main_default
style_ui_aircon_img_temup_main_main_default = lv.style_t()
style_ui_aircon_img_temup_main_main_default.init()
style_ui_aircon_img_temup_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_temup_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_temup_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_TemUp
ui_Aircon_Img_TemUp.add_style(style_ui_aircon_img_temup_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_TempDown = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TempDown.set_pos(int(319),int(122))
ui_Aircon_Img_TempDown.set_size(28,14)
ui_Aircon_Img_TempDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_TempDown.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-430806071.png','rb') as f:
        ui_Aircon_Img_TempDown_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-430806071.png')
    sys.exit()

ui_Aircon_Img_TempDown_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_TempDown_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_TempDown_img_data
})

ui_Aircon_Img_TempDown.set_src(ui_Aircon_Img_TempDown_img)
ui_Aircon_Img_TempDown.set_pivot(50,50)
ui_Aircon_Img_TempDown.set_angle(0)
# create style style_ui_aircon_img_tempdown_main_main_default
style_ui_aircon_img_tempdown_main_main_default = lv.style_t()
style_ui_aircon_img_tempdown_main_main_default.init()
style_ui_aircon_img_tempdown_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_tempdown_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_tempdown_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_TempDown
ui_Aircon_Img_TempDown.add_style(style_ui_aircon_img_tempdown_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Roller_Mode = lv.roller(ui_Aircon_Cont)
ui_Aircon_Roller_Mode.set_pos(int(40),int(404))
ui_Aircon_Roller_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Roller_Mode.set_options("COOL\nDRY\nFAN", lv.roller.MODE.INFINITE)
ui_Aircon_Roller_Mode.set_visible_row_count(3)
# create style style_ui_aircon_roller_mode_main_main_default
style_ui_aircon_roller_mode_main_main_default = lv.style_t()
style_ui_aircon_roller_mode_main_main_default.init()
style_ui_aircon_roller_mode_main_main_default.set_radius(5)
style_ui_aircon_roller_mode_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_ui_aircon_roller_mode_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_roller_mode_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_roller_mode_main_main_default.set_bg_opa(255)
style_ui_aircon_roller_mode_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_ui_aircon_roller_mode_main_main_default.set_border_width(2)
style_ui_aircon_roller_mode_main_main_default.set_border_opa(255)
style_ui_aircon_roller_mode_main_main_default.set_text_color(lv.color_make(0x9D,0x9D,0x9D))
try:
    style_ui_aircon_roller_mode_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_roller_mode_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_roller_mode_main_main_default.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Roller_Mode
ui_Aircon_Roller_Mode.add_style(style_ui_aircon_roller_mode_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_roller_mode_main_selected_default
style_ui_aircon_roller_mode_main_selected_default = lv.style_t()
style_ui_aircon_roller_mode_main_selected_default.init()
style_ui_aircon_roller_mode_main_selected_default.set_bg_color(lv.color_make(0x20,0xA1,0xC5))
style_ui_aircon_roller_mode_main_selected_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_roller_mode_main_selected_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_roller_mode_main_selected_default.set_bg_opa(255)
style_ui_aircon_roller_mode_main_selected_default.set_text_color(lv.color_make(0xFF,0xFF,0xFF))
try:
    style_ui_aircon_roller_mode_main_selected_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_roller_mode_main_selected_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_roller_mode_main_selected_default.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Roller_Mode
ui_Aircon_Roller_Mode.add_style(style_ui_aircon_roller_mode_main_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

ui_Aircon_Btn_Swing = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_Swing.set_pos(int(99),int(572))
ui_Aircon_Btn_Swing.set_size(78,45)
ui_Aircon_Btn_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Btn_Swing.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Aircon_Btn_Swing_label = lv.label(ui_Aircon_Btn_Swing)
ui_Aircon_Btn_Swing_label.set_text("ON")
ui_Aircon_Btn_Swing.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing_label.align(lv.ALIGN.CENTER,0,0)
# create style style_ui_aircon_btn_swing_main_main_default
style_ui_aircon_btn_swing_main_main_default = lv.style_t()
style_ui_aircon_btn_swing_main_main_default.init()
style_ui_aircon_btn_swing_main_main_default.set_radius(10)
style_ui_aircon_btn_swing_main_main_default.set_bg_color(lv.color_make(0x6A,0x6A,0x6A))
style_ui_aircon_btn_swing_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_swing_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_swing_main_main_default.set_bg_opa(255)
style_ui_aircon_btn_swing_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_swing_main_main_default.set_border_width(0)
style_ui_aircon_btn_swing_main_main_default.set_border_opa(0)
style_ui_aircon_btn_swing_main_main_default.set_text_color(lv.color_make(0x9D,0x9D,0x9D))
try:
    style_ui_aircon_btn_swing_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_btn_swing_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_btn_swing_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_btn_swing_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for ui_Aircon_Btn_Swing
ui_Aircon_Btn_Swing.add_style(style_ui_aircon_btn_swing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_btn_swing_main_main_pressed
style_ui_aircon_btn_swing_main_main_pressed = lv.style_t()
style_ui_aircon_btn_swing_main_main_pressed.init()
style_ui_aircon_btn_swing_main_main_pressed.set_radius(10)
style_ui_aircon_btn_swing_main_main_pressed.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_btn_swing_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_swing_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_swing_main_main_pressed.set_bg_opa(255)
style_ui_aircon_btn_swing_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_swing_main_main_pressed.set_border_width(0)
style_ui_aircon_btn_swing_main_main_pressed.set_border_opa(0)
style_ui_aircon_btn_swing_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_swing_main_main_pressed.set_text_font(lv.font_Antonio_Regular_20)
except AttributeError:
    try:
        style_ui_aircon_btn_swing_main_main_pressed.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_ui_aircon_btn_swing_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Btn_Swing
ui_Aircon_Btn_Swing.add_style(style_ui_aircon_btn_swing_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_ui_aircon_btn_swing_main_main_checked
style_ui_aircon_btn_swing_main_main_checked = lv.style_t()
style_ui_aircon_btn_swing_main_main_checked.init()
style_ui_aircon_btn_swing_main_main_checked.set_radius(10)
style_ui_aircon_btn_swing_main_main_checked.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_btn_swing_main_main_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_swing_main_main_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_swing_main_main_checked.set_bg_opa(255)
style_ui_aircon_btn_swing_main_main_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_swing_main_main_checked.set_border_width(0)
style_ui_aircon_btn_swing_main_main_checked.set_border_opa(0)
style_ui_aircon_btn_swing_main_main_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_swing_main_main_checked.set_text_font(lv.font_Antonio_Regular_20)
except AttributeError:
    try:
        style_ui_aircon_btn_swing_main_main_checked.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_ui_aircon_btn_swing_main_main_checked.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Btn_Swing
ui_Aircon_Btn_Swing.add_style(style_ui_aircon_btn_swing_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

ui_Aircon_Label_Swing = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Swing.set_pos(int(30),int(576))
ui_Aircon_Label_Swing.set_size(73,38)
ui_Aircon_Label_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Swing.set_text("SWING")
ui_Aircon_Label_Swing.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_swing_main_main_default
style_ui_aircon_label_swing_main_main_default = lv.style_t()
style_ui_aircon_label_swing_main_main_default.init()
style_ui_aircon_label_swing_main_main_default.set_radius(0)
style_ui_aircon_label_swing_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_swing_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_swing_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_swing_main_main_default.set_bg_opa(0)
style_ui_aircon_label_swing_main_main_default.set_text_color(lv.color_make(0x52,0xDA,0xFF))
try:
    style_ui_aircon_label_swing_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_label_swing_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_label_swing_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_swing_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_swing_main_main_default.set_text_line_space(0)
style_ui_aircon_label_swing_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_swing_main_main_default.set_pad_left(0)
style_ui_aircon_label_swing_main_main_default.set_pad_right(0)
style_ui_aircon_label_swing_main_main_default.set_pad_top(8)
style_ui_aircon_label_swing_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Swing
ui_Aircon_Label_Swing.add_style(style_ui_aircon_label_swing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_line_1 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_1.set_pos(int(23),int(199))
ui_Aircon_line_1.set_size(371,13)
ui_Aircon_line_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":360, "y":0}, 
			  ]
ui_Aircon_line_1.set_points(line_points, 2)
# create style style_ui_aircon_line_1_main_main_default
style_ui_aircon_line_1_main_main_default = lv.style_t()
style_ui_aircon_line_1_main_main_default.init()
style_ui_aircon_line_1_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_aircon_line_1_main_main_default.set_line_width(3)
style_ui_aircon_line_1_main_main_default.set_line_rounded(False)

# add style for ui_Aircon_line_1
ui_Aircon_line_1.add_style(style_ui_aircon_line_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_line_2 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_2.set_pos(int(23),int(359))
ui_Aircon_line_2.set_size(371,13)
ui_Aircon_line_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":360, "y":0}, 
			  ]
ui_Aircon_line_2.set_points(line_points, 2)
# create style style_ui_aircon_line_2_main_main_default
style_ui_aircon_line_2_main_main_default = lv.style_t()
style_ui_aircon_line_2_main_main_default.init()
style_ui_aircon_line_2_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_aircon_line_2_main_main_default.set_line_width(3)
style_ui_aircon_line_2_main_main_default.set_line_rounded(False)

# add style for ui_Aircon_line_2
ui_Aircon_line_2.add_style(style_ui_aircon_line_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_line_3 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_3.set_pos(int(23),int(540))
ui_Aircon_line_3.set_size(371,7)
ui_Aircon_line_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":360, "y":0}, 
			  ]
ui_Aircon_line_3.set_points(line_points, 2)
# create style style_ui_aircon_line_3_main_main_default
style_ui_aircon_line_3_main_main_default = lv.style_t()
style_ui_aircon_line_3_main_main_default.init()
style_ui_aircon_line_3_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_aircon_line_3_main_main_default.set_line_width(3)
style_ui_aircon_line_3_main_main_default.set_line_rounded(False)

# add style for ui_Aircon_line_3
ui_Aircon_line_3.add_style(style_ui_aircon_line_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_line_4 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_4.set_pos(int(242),int(410))
ui_Aircon_line_4.set_size(29,119)
ui_Aircon_line_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":100}, 
			  ]
ui_Aircon_line_4.set_points(line_points, 2)
# create style style_ui_aircon_line_4_main_main_default
style_ui_aircon_line_4_main_main_default = lv.style_t()
style_ui_aircon_line_4_main_main_default.init()
style_ui_aircon_line_4_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_aircon_line_4_main_main_default.set_line_width(3)
style_ui_aircon_line_4_main_main_default.set_line_rounded(False)

# add style for ui_Aircon_line_4
ui_Aircon_line_4.add_style(style_ui_aircon_line_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_line_5 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_5.set_pos(int(192),int(568))
ui_Aircon_line_5.set_size(17,67)
ui_Aircon_line_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":50}, 
			  ]
ui_Aircon_line_5.set_points(line_points, 2)
# create style style_ui_aircon_line_5_main_main_default
style_ui_aircon_line_5_main_main_default = lv.style_t()
style_ui_aircon_line_5_main_main_default.init()
style_ui_aircon_line_5_main_main_default.set_line_color(lv.color_make(0x65,0x64,0x61))
style_ui_aircon_line_5_main_main_default.set_line_width(3)
style_ui_aircon_line_5_main_main_default.set_line_rounded(False)

# add style for ui_Aircon_line_5
ui_Aircon_line_5.add_style(style_ui_aircon_line_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Timer = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Timer.set_pos(int(105),int(202))
ui_Aircon_Label_Timer.set_size(203,32)
ui_Aircon_Label_Timer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Timer.set_text("SET TIMER")
ui_Aircon_Label_Timer.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_timer_main_main_default
style_ui_aircon_label_timer_main_main_default = lv.style_t()
style_ui_aircon_label_timer_main_main_default.init()
style_ui_aircon_label_timer_main_main_default.set_radius(0)
style_ui_aircon_label_timer_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timer_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timer_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_timer_main_main_default.set_bg_opa(0)
style_ui_aircon_label_timer_main_main_default.set_text_color(lv.color_make(0x52,0xDA,0xFF))
try:
    style_ui_aircon_label_timer_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_label_timer_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_label_timer_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_timer_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_timer_main_main_default.set_text_line_space(0)
style_ui_aircon_label_timer_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_timer_main_main_default.set_pad_left(0)
style_ui_aircon_label_timer_main_main_default.set_pad_right(0)
style_ui_aircon_label_timer_main_main_default.set_pad_top(8)
style_ui_aircon_label_timer_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Timer
ui_Aircon_Label_Timer.add_style(style_ui_aircon_label_timer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Mode = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Mode.set_pos(int(123),int(364))
ui_Aircon_Label_Mode.set_size(178,34)
ui_Aircon_Label_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Mode.set_text("SELECT MODE")
ui_Aircon_Label_Mode.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_mode_main_main_default
style_ui_aircon_label_mode_main_main_default = lv.style_t()
style_ui_aircon_label_mode_main_main_default.init()
style_ui_aircon_label_mode_main_main_default.set_radius(0)
style_ui_aircon_label_mode_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_mode_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_mode_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_mode_main_main_default.set_bg_opa(0)
style_ui_aircon_label_mode_main_main_default.set_text_color(lv.color_make(0x52,0xDA,0xFF))
try:
    style_ui_aircon_label_mode_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_label_mode_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_label_mode_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_mode_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_mode_main_main_default.set_text_line_space(0)
style_ui_aircon_label_mode_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_mode_main_main_default.set_pad_left(0)
style_ui_aircon_label_mode_main_main_default.set_pad_right(0)
style_ui_aircon_label_mode_main_main_default.set_pad_top(8)
style_ui_aircon_label_mode_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Mode
ui_Aircon_Label_Mode.add_style(style_ui_aircon_label_mode_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Fan = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Fan.set_pos(int(204),int(571))
ui_Aircon_Label_Fan.set_size(45,38)
ui_Aircon_Label_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Fan.set_text("FAN")
ui_Aircon_Label_Fan.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_fan_main_main_default
style_ui_aircon_label_fan_main_main_default = lv.style_t()
style_ui_aircon_label_fan_main_main_default.init()
style_ui_aircon_label_fan_main_main_default.set_radius(0)
style_ui_aircon_label_fan_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_fan_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_fan_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_fan_main_main_default.set_bg_opa(0)
style_ui_aircon_label_fan_main_main_default.set_text_color(lv.color_make(0x52,0xDA,0xFF))
try:
    style_ui_aircon_label_fan_main_main_default.set_text_font(lv.font_Antonio_Regular_21)
except AttributeError:
    try:
        style_ui_aircon_label_fan_main_main_default.set_text_font(lv.font_montserrat_21)
    except AttributeError:
        style_ui_aircon_label_fan_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_fan_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_fan_main_main_default.set_text_line_space(0)
style_ui_aircon_label_fan_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_fan_main_main_default.set_pad_left(0)
style_ui_aircon_label_fan_main_main_default.set_pad_right(0)
style_ui_aircon_label_fan_main_main_default.set_pad_top(8)
style_ui_aircon_label_fan_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Fan
ui_Aircon_Label_Fan.add_style(style_ui_aircon_label_fan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Slider_Fan = lv.slider(ui_Aircon_Cont)
ui_Aircon_Slider_Fan.set_pos(int(257),int(579))
ui_Aircon_Slider_Fan.set_size(127,16)
ui_Aircon_Slider_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Slider_Fan.set_range(0, 2)
ui_Aircon_Slider_Fan.set_value(1, False)

# create style style_ui_aircon_slider_fan_main_main_default
style_ui_aircon_slider_fan_main_main_default = lv.style_t()
style_ui_aircon_slider_fan_main_main_default.init()
style_ui_aircon_slider_fan_main_main_default.set_radius(50)
style_ui_aircon_slider_fan_main_main_default.set_bg_color(lv.color_make(0x6A,0x6A,0x6A))
style_ui_aircon_slider_fan_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_slider_fan_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_slider_fan_main_main_default.set_bg_opa(255)
style_ui_aircon_slider_fan_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_slider_fan_main_main_default.set_outline_width(0)
style_ui_aircon_slider_fan_main_main_default.set_outline_opa(0)

# add style for ui_Aircon_Slider_Fan
ui_Aircon_Slider_Fan.add_style(style_ui_aircon_slider_fan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_slider_fan_main_indicator_default
style_ui_aircon_slider_fan_main_indicator_default = lv.style_t()
style_ui_aircon_slider_fan_main_indicator_default.init()
style_ui_aircon_slider_fan_main_indicator_default.set_radius(50)
style_ui_aircon_slider_fan_main_indicator_default.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_slider_fan_main_indicator_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_slider_fan_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_slider_fan_main_indicator_default.set_bg_opa(255)

# add style for ui_Aircon_Slider_Fan
ui_Aircon_Slider_Fan.add_style(style_ui_aircon_slider_fan_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_ui_aircon_slider_fan_main_knob_default
style_ui_aircon_slider_fan_main_knob_default = lv.style_t()
style_ui_aircon_slider_fan_main_knob_default.init()
style_ui_aircon_slider_fan_main_knob_default.set_radius(50)
style_ui_aircon_slider_fan_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_slider_fan_main_knob_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_slider_fan_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_slider_fan_main_knob_default.set_bg_opa(255)

# add style for ui_Aircon_Slider_Fan
ui_Aircon_Slider_Fan.add_style(style_ui_aircon_slider_fan_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

ui_Aircon_Label_Low = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Low.set_pos(int(249),int(592))
ui_Aircon_Label_Low.set_size(29,34)
ui_Aircon_Label_Low.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Low.set_text("•\nLOW")
ui_Aircon_Label_Low.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_low_main_main_default
style_ui_aircon_label_low_main_main_default = lv.style_t()
style_ui_aircon_label_low_main_main_default.init()
style_ui_aircon_label_low_main_main_default.set_radius(0)
style_ui_aircon_label_low_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_low_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_low_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_low_main_main_default.set_bg_opa(0)
style_ui_aircon_label_low_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_low_main_main_default.set_text_font(lv.font_Antonio_Regular_12)
except AttributeError:
    try:
        style_ui_aircon_label_low_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ui_aircon_label_low_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_low_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_low_main_main_default.set_text_line_space(0)
style_ui_aircon_label_low_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_low_main_main_default.set_pad_left(0)
style_ui_aircon_label_low_main_main_default.set_pad_right(0)
style_ui_aircon_label_low_main_main_default.set_pad_top(8)
style_ui_aircon_label_low_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Low
ui_Aircon_Label_Low.add_style(style_ui_aircon_label_low_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Medium = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Medium.set_pos(int(295),int(592))
ui_Aircon_Label_Medium.set_size(53,34)
ui_Aircon_Label_Medium.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Medium.set_text("•\nMEDIUM")
ui_Aircon_Label_Medium.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_medium_main_main_default
style_ui_aircon_label_medium_main_main_default = lv.style_t()
style_ui_aircon_label_medium_main_main_default.init()
style_ui_aircon_label_medium_main_main_default.set_radius(0)
style_ui_aircon_label_medium_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_medium_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_medium_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_medium_main_main_default.set_bg_opa(0)
style_ui_aircon_label_medium_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_medium_main_main_default.set_text_font(lv.font_Antonio_Regular_12)
except AttributeError:
    try:
        style_ui_aircon_label_medium_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ui_aircon_label_medium_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_medium_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_medium_main_main_default.set_text_line_space(0)
style_ui_aircon_label_medium_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_medium_main_main_default.set_pad_left(0)
style_ui_aircon_label_medium_main_main_default.set_pad_right(0)
style_ui_aircon_label_medium_main_main_default.set_pad_top(8)
style_ui_aircon_label_medium_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Medium
ui_Aircon_Label_Medium.add_style(style_ui_aircon_label_medium_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_High = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_High.set_pos(int(363),int(592))
ui_Aircon_Label_High.set_size(29,34)
ui_Aircon_Label_High.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_High.set_text("•\nHIGH")
ui_Aircon_Label_High.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_high_main_main_default
style_ui_aircon_label_high_main_main_default = lv.style_t()
style_ui_aircon_label_high_main_main_default.init()
style_ui_aircon_label_high_main_main_default.set_radius(0)
style_ui_aircon_label_high_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_high_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_high_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_high_main_main_default.set_bg_opa(0)
style_ui_aircon_label_high_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_high_main_main_default.set_text_font(lv.font_Antonio_Regular_12)
except AttributeError:
    try:
        style_ui_aircon_label_high_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_ui_aircon_label_high_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_high_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_high_main_main_default.set_text_line_space(0)
style_ui_aircon_label_high_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_high_main_main_default.set_pad_left(0)
style_ui_aircon_label_high_main_main_default.set_pad_right(0)
style_ui_aircon_label_high_main_main_default.set_pad_top(8)
style_ui_aircon_label_high_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_High
ui_Aircon_Label_High.add_style(style_ui_aircon_label_high_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_Comp = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Comp.set_pos(int(302),int(402))
ui_Aircon_Label_Comp.set_size(65,30)
ui_Aircon_Label_Comp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_Comp.set_text("COMP")
ui_Aircon_Label_Comp.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_comp_main_main_default
style_ui_aircon_label_comp_main_main_default = lv.style_t()
style_ui_aircon_label_comp_main_main_default.init()
style_ui_aircon_label_comp_main_main_default.set_radius(0)
style_ui_aircon_label_comp_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_comp_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_comp_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_comp_main_main_default.set_bg_opa(0)
style_ui_aircon_label_comp_main_main_default.set_text_color(lv.color_make(0x52,0xDA,0xFF))
try:
    style_ui_aircon_label_comp_main_main_default.set_text_font(lv.font_Antonio_Regular_19)
except AttributeError:
    try:
        style_ui_aircon_label_comp_main_main_default.set_text_font(lv.font_montserrat_19)
    except AttributeError:
        style_ui_aircon_label_comp_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_comp_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_comp_main_main_default.set_text_line_space(0)
style_ui_aircon_label_comp_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_comp_main_main_default.set_pad_left(0)
style_ui_aircon_label_comp_main_main_default.set_pad_right(0)
style_ui_aircon_label_comp_main_main_default.set_pad_top(8)
style_ui_aircon_label_comp_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_Comp
ui_Aircon_Label_Comp.add_style(style_ui_aircon_label_comp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_On = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_On.set_pos(int(302),int(424))
ui_Aircon_Label_On.set_size(65,30)
ui_Aircon_Label_On.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_On.set_text("ON")
ui_Aircon_Label_On.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_on_main_main_default
style_ui_aircon_label_on_main_main_default = lv.style_t()
style_ui_aircon_label_on_main_main_default.init()
style_ui_aircon_label_on_main_main_default.set_radius(0)
style_ui_aircon_label_on_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_on_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_on_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_on_main_main_default.set_bg_opa(0)
style_ui_aircon_label_on_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_on_main_main_default.set_text_font(lv.font_Antonio_Regular_19)
except AttributeError:
    try:
        style_ui_aircon_label_on_main_main_default.set_text_font(lv.font_montserrat_19)
    except AttributeError:
        style_ui_aircon_label_on_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_on_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_on_main_main_default.set_text_line_space(0)
style_ui_aircon_label_on_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_on_main_main_default.set_pad_left(0)
style_ui_aircon_label_on_main_main_default.set_pad_right(0)
style_ui_aircon_label_on_main_main_default.set_pad_top(8)
style_ui_aircon_label_on_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_On
ui_Aircon_Label_On.add_style(style_ui_aircon_label_on_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_Comp = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_Comp.set_pos(int(272),int(413))
ui_Aircon_Img_Comp.set_size(27,31)
ui_Aircon_Img_Comp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_Comp.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp197672255.png','rb') as f:
        ui_Aircon_Img_Comp_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp197672255.png')
    sys.exit()

ui_Aircon_Img_Comp_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_Comp_img_data),
  'header': {'always_zero': 0, 'w': 27, 'h': 31, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_Comp_img_data
})

ui_Aircon_Img_Comp.set_src(ui_Aircon_Img_Comp_img)
ui_Aircon_Img_Comp.set_pivot(50,50)
ui_Aircon_Img_Comp.set_angle(0)
# create style style_ui_aircon_img_comp_main_main_default
style_ui_aircon_img_comp_main_main_default = lv.style_t()
style_ui_aircon_img_comp_main_main_default.init()
style_ui_aircon_img_comp_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_comp_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_comp_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_Comp
ui_Aircon_Img_Comp.add_style(style_ui_aircon_img_comp_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_FanSt = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_FanSt.set_pos(int(303),int(462))
ui_Aircon_Label_FanSt.set_size(65,30)
ui_Aircon_Label_FanSt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_FanSt.set_text("FAN")
ui_Aircon_Label_FanSt.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_fanst_main_main_default
style_ui_aircon_label_fanst_main_main_default = lv.style_t()
style_ui_aircon_label_fanst_main_main_default.init()
style_ui_aircon_label_fanst_main_main_default.set_radius(0)
style_ui_aircon_label_fanst_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_fanst_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_fanst_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_fanst_main_main_default.set_bg_opa(0)
style_ui_aircon_label_fanst_main_main_default.set_text_color(lv.color_make(0x52,0xDA,0xFF))
try:
    style_ui_aircon_label_fanst_main_main_default.set_text_font(lv.font_Antonio_Regular_19)
except AttributeError:
    try:
        style_ui_aircon_label_fanst_main_main_default.set_text_font(lv.font_montserrat_19)
    except AttributeError:
        style_ui_aircon_label_fanst_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_fanst_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_fanst_main_main_default.set_text_line_space(0)
style_ui_aircon_label_fanst_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_fanst_main_main_default.set_pad_left(0)
style_ui_aircon_label_fanst_main_main_default.set_pad_right(0)
style_ui_aircon_label_fanst_main_main_default.set_pad_top(8)
style_ui_aircon_label_fanst_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_FanSt
ui_Aircon_Label_FanSt.add_style(style_ui_aircon_label_fanst_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_FanState = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_FanState.set_pos(int(303),int(485))
ui_Aircon_Label_FanState.set_size(65,30)
ui_Aircon_Label_FanState.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_FanState.set_text("LOW")
ui_Aircon_Label_FanState.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_fanstate_main_main_default
style_ui_aircon_label_fanstate_main_main_default = lv.style_t()
style_ui_aircon_label_fanstate_main_main_default.init()
style_ui_aircon_label_fanstate_main_main_default.set_radius(0)
style_ui_aircon_label_fanstate_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_fanstate_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_fanstate_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_fanstate_main_main_default.set_bg_opa(0)
style_ui_aircon_label_fanstate_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_fanstate_main_main_default.set_text_font(lv.font_Antonio_Regular_19)
except AttributeError:
    try:
        style_ui_aircon_label_fanstate_main_main_default.set_text_font(lv.font_montserrat_19)
    except AttributeError:
        style_ui_aircon_label_fanstate_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_fanstate_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_fanstate_main_main_default.set_text_line_space(0)
style_ui_aircon_label_fanstate_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_fanstate_main_main_default.set_pad_left(0)
style_ui_aircon_label_fanstate_main_main_default.set_pad_right(0)
style_ui_aircon_label_fanstate_main_main_default.set_pad_top(8)
style_ui_aircon_label_fanstate_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_FanState
ui_Aircon_Label_FanState.add_style(style_ui_aircon_label_fanstate_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_FanSt = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_FanSt.set_pos(int(272),int(474))
ui_Aircon_Img_FanSt.set_size(31,27)
ui_Aircon_Img_FanSt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_FanSt.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1260856760.png','rb') as f:
        ui_Aircon_Img_FanSt_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1260856760.png')
    sys.exit()

ui_Aircon_Img_FanSt_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_FanSt_img_data),
  'header': {'always_zero': 0, 'w': 31, 'h': 27, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_FanSt_img_data
})

ui_Aircon_Img_FanSt.set_src(ui_Aircon_Img_FanSt_img)
ui_Aircon_Img_FanSt.set_pivot(50,50)
ui_Aircon_Img_FanSt.set_angle(0)
# create style style_ui_aircon_img_fanst_main_main_default
style_ui_aircon_img_fanst_main_main_default = lv.style_t()
style_ui_aircon_img_fanst_main_main_default.init()
style_ui_aircon_img_fanst_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_fanst_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_fanst_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_FanSt
ui_Aircon_Img_FanSt.add_style(style_ui_aircon_img_fanst_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Btn_TimerUp = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TimerUp.set_pos(int(198),int(260))
ui_Aircon_Btn_TimerUp.set_size(74,58)
ui_Aircon_Btn_TimerUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_aircon_btn_timerup_main_main_default
style_ui_aircon_btn_timerup_main_main_default = lv.style_t()
style_ui_aircon_btn_timerup_main_main_default.init()
style_ui_aircon_btn_timerup_main_main_default.set_radius(10)
style_ui_aircon_btn_timerup_main_main_default.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_btn_timerup_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerup_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_timerup_main_main_default.set_bg_opa(255)
style_ui_aircon_btn_timerup_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerup_main_main_default.set_border_width(0)
style_ui_aircon_btn_timerup_main_main_default.set_border_opa(255)
style_ui_aircon_btn_timerup_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_timerup_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_timerup_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_timerup_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_btn_timerup_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for ui_Aircon_Btn_TimerUp
ui_Aircon_Btn_TimerUp.add_style(style_ui_aircon_btn_timerup_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_btn_timerup_main_main_pressed
style_ui_aircon_btn_timerup_main_main_pressed = lv.style_t()
style_ui_aircon_btn_timerup_main_main_pressed.init()
style_ui_aircon_btn_timerup_main_main_pressed.set_radius(10)
style_ui_aircon_btn_timerup_main_main_pressed.set_bg_color(lv.color_make(0x18,0xC2,0x20))
style_ui_aircon_btn_timerup_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerup_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_timerup_main_main_pressed.set_bg_opa(255)
style_ui_aircon_btn_timerup_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerup_main_main_pressed.set_border_width(0)
style_ui_aircon_btn_timerup_main_main_pressed.set_border_opa(255)
style_ui_aircon_btn_timerup_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_timerup_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_timerup_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_timerup_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Btn_TimerUp
ui_Aircon_Btn_TimerUp.add_style(style_ui_aircon_btn_timerup_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

ui_Aircon_Img_TimerUp = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TimerUp.set_pos(int(222),int(281))
ui_Aircon_Img_TimerUp.set_size(28,14)
ui_Aircon_Img_TimerUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_TimerUp.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp691787330.png','rb') as f:
        ui_Aircon_Img_TimerUp_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp691787330.png')
    sys.exit()

ui_Aircon_Img_TimerUp_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_TimerUp_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_TimerUp_img_data
})

ui_Aircon_Img_TimerUp.set_src(ui_Aircon_Img_TimerUp_img)
ui_Aircon_Img_TimerUp.set_pivot(50,50)
ui_Aircon_Img_TimerUp.set_angle(0)
# create style style_ui_aircon_img_timerup_main_main_default
style_ui_aircon_img_timerup_main_main_default = lv.style_t()
style_ui_aircon_img_timerup_main_main_default.init()
style_ui_aircon_img_timerup_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_timerup_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_timerup_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_TimerUp
ui_Aircon_Img_TimerUp.add_style(style_ui_aircon_img_timerup_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Btn_TimerDown = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TimerDown.set_pos(int(295),int(260))
ui_Aircon_Btn_TimerDown.set_size(74,58)
ui_Aircon_Btn_TimerDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_ui_aircon_btn_timerdown_main_main_default
style_ui_aircon_btn_timerdown_main_main_default = lv.style_t()
style_ui_aircon_btn_timerdown_main_main_default.init()
style_ui_aircon_btn_timerdown_main_main_default.set_radius(10)
style_ui_aircon_btn_timerdown_main_main_default.set_bg_color(lv.color_make(0x29,0xBA,0xE6))
style_ui_aircon_btn_timerdown_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerdown_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_timerdown_main_main_default.set_bg_opa(255)
style_ui_aircon_btn_timerdown_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerdown_main_main_default.set_border_width(0)
style_ui_aircon_btn_timerdown_main_main_default.set_border_opa(255)
style_ui_aircon_btn_timerdown_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_timerdown_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_timerdown_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_timerdown_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_btn_timerdown_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for ui_Aircon_Btn_TimerDown
ui_Aircon_Btn_TimerDown.add_style(style_ui_aircon_btn_timerdown_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_btn_timerdown_main_main_pressed
style_ui_aircon_btn_timerdown_main_main_pressed = lv.style_t()
style_ui_aircon_btn_timerdown_main_main_pressed.init()
style_ui_aircon_btn_timerdown_main_main_pressed.set_radius(10)
style_ui_aircon_btn_timerdown_main_main_pressed.set_bg_color(lv.color_make(0x18,0xC2,0x20))
style_ui_aircon_btn_timerdown_main_main_pressed.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerdown_main_main_pressed.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_btn_timerdown_main_main_pressed.set_bg_opa(255)
style_ui_aircon_btn_timerdown_main_main_pressed.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_btn_timerdown_main_main_pressed.set_border_width(0)
style_ui_aircon_btn_timerdown_main_main_pressed.set_border_opa(255)
style_ui_aircon_btn_timerdown_main_main_pressed.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_btn_timerdown_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_ui_aircon_btn_timerdown_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_ui_aircon_btn_timerdown_main_main_pressed.set_text_font(lv.font_montserrat_16)

# add style for ui_Aircon_Btn_TimerDown
ui_Aircon_Btn_TimerDown.add_style(style_ui_aircon_btn_timerdown_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

ui_Aircon_Img_TimerDown = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TimerDown.set_pos(int(319),int(281))
ui_Aircon_Img_TimerDown.set_size(28,14)
ui_Aircon_Img_TimerDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_TimerDown.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-430806071.png','rb') as f:
        ui_Aircon_Img_TimerDown_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp-430806071.png')
    sys.exit()

ui_Aircon_Img_TimerDown_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_TimerDown_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_TimerDown_img_data
})

ui_Aircon_Img_TimerDown.set_src(ui_Aircon_Img_TimerDown_img)
ui_Aircon_Img_TimerDown.set_pivot(50,50)
ui_Aircon_Img_TimerDown.set_angle(0)
# create style style_ui_aircon_img_timerdown_main_main_default
style_ui_aircon_img_timerdown_main_main_default = lv.style_t()
style_ui_aircon_img_timerdown_main_main_default.init()
style_ui_aircon_img_timerdown_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_timerdown_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_timerdown_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_TimerDown
ui_Aircon_Img_TimerDown.add_style(style_ui_aircon_img_timerdown_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_TimerHour = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_TimerHour.set_pos(int(19),int(234))
ui_Aircon_Label_TimerHour.set_size(76,103)
ui_Aircon_Label_TimerHour.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_TimerHour.set_text("01")
ui_Aircon_Label_TimerHour.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_timerhour_main_main_default
style_ui_aircon_label_timerhour_main_main_default = lv.style_t()
style_ui_aircon_label_timerhour_main_main_default.init()
style_ui_aircon_label_timerhour_main_main_default.set_radius(0)
style_ui_aircon_label_timerhour_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timerhour_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timerhour_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_timerhour_main_main_default.set_bg_opa(0)
style_ui_aircon_label_timerhour_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_timerhour_main_main_default.set_text_font(lv.font_Antonio_Regular_80)
except AttributeError:
    try:
        style_ui_aircon_label_timerhour_main_main_default.set_text_font(lv.font_montserrat_80)
    except AttributeError:
        style_ui_aircon_label_timerhour_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_timerhour_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_timerhour_main_main_default.set_text_line_space(0)
style_ui_aircon_label_timerhour_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_timerhour_main_main_default.set_pad_left(0)
style_ui_aircon_label_timerhour_main_main_default.set_pad_right(0)
style_ui_aircon_label_timerhour_main_main_default.set_pad_top(8)
style_ui_aircon_label_timerhour_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_TimerHour
ui_Aircon_Label_TimerHour.add_style(style_ui_aircon_label_timerhour_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_TimerPoints = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_TimerPoints.set_pos(int(93),int(229))
ui_Aircon_Label_TimerPoints.set_size(23,103)
ui_Aircon_Label_TimerPoints.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_TimerPoints.set_text(":")
ui_Aircon_Label_TimerPoints.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_timerpoints_main_main_default
style_ui_aircon_label_timerpoints_main_main_default = lv.style_t()
style_ui_aircon_label_timerpoints_main_main_default.init()
style_ui_aircon_label_timerpoints_main_main_default.set_radius(0)
style_ui_aircon_label_timerpoints_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timerpoints_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timerpoints_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_timerpoints_main_main_default.set_bg_opa(0)
style_ui_aircon_label_timerpoints_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_timerpoints_main_main_default.set_text_font(lv.font_Antonio_Regular_80)
except AttributeError:
    try:
        style_ui_aircon_label_timerpoints_main_main_default.set_text_font(lv.font_montserrat_80)
    except AttributeError:
        style_ui_aircon_label_timerpoints_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_timerpoints_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_timerpoints_main_main_default.set_text_line_space(0)
style_ui_aircon_label_timerpoints_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_timerpoints_main_main_default.set_pad_left(0)
style_ui_aircon_label_timerpoints_main_main_default.set_pad_right(0)
style_ui_aircon_label_timerpoints_main_main_default.set_pad_top(8)
style_ui_aircon_label_timerpoints_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_TimerPoints
ui_Aircon_Label_TimerPoints.add_style(style_ui_aircon_label_timerpoints_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Label_TimerMin = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_TimerMin.set_pos(int(118),int(234))
ui_Aircon_Label_TimerMin.set_size(76,103)
ui_Aircon_Label_TimerMin.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Label_TimerMin.set_text("15")
ui_Aircon_Label_TimerMin.set_long_mode(lv.label.LONG.WRAP)
# create style style_ui_aircon_label_timermin_main_main_default
style_ui_aircon_label_timermin_main_main_default = lv.style_t()
style_ui_aircon_label_timermin_main_main_default.init()
style_ui_aircon_label_timermin_main_main_default.set_radius(0)
style_ui_aircon_label_timermin_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timermin_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_ui_aircon_label_timermin_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_label_timermin_main_main_default.set_bg_opa(0)
style_ui_aircon_label_timermin_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_ui_aircon_label_timermin_main_main_default.set_text_font(lv.font_Antonio_Regular_80)
except AttributeError:
    try:
        style_ui_aircon_label_timermin_main_main_default.set_text_font(lv.font_montserrat_80)
    except AttributeError:
        style_ui_aircon_label_timermin_main_main_default.set_text_font(lv.font_montserrat_16)
style_ui_aircon_label_timermin_main_main_default.set_text_letter_space(2)
style_ui_aircon_label_timermin_main_main_default.set_text_line_space(0)
style_ui_aircon_label_timermin_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_ui_aircon_label_timermin_main_main_default.set_pad_left(0)
style_ui_aircon_label_timermin_main_main_default.set_pad_right(0)
style_ui_aircon_label_timermin_main_main_default.set_pad_top(8)
style_ui_aircon_label_timermin_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Label_TimerMin
ui_Aircon_Label_TimerMin.add_style(style_ui_aircon_label_timermin_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_ui_aircon_cont_main_main_default
style_ui_aircon_cont_main_main_default = lv.style_t()
style_ui_aircon_cont_main_main_default.init()
style_ui_aircon_cont_main_main_default.set_radius(20)
style_ui_aircon_cont_main_main_default.set_bg_color(lv.color_make(0x24,0x24,0x24))
style_ui_aircon_cont_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_cont_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_ui_aircon_cont_main_main_default.set_bg_opa(250)
style_ui_aircon_cont_main_main_default.set_border_color(lv.color_make(0x4A,0x4C,0x4A))
style_ui_aircon_cont_main_main_default.set_border_width(1)
style_ui_aircon_cont_main_main_default.set_border_opa(255)
style_ui_aircon_cont_main_main_default.set_pad_left(0)
style_ui_aircon_cont_main_main_default.set_pad_right(0)
style_ui_aircon_cont_main_main_default.set_pad_top(0)
style_ui_aircon_cont_main_main_default.set_pad_bottom(0)

# add style for ui_Aircon_Cont
ui_Aircon_Cont.add_style(style_ui_aircon_cont_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_Fan = lv.img(ui_Aircon)
ui_Aircon_Img_Fan.set_pos(int(646),int(218))
ui_Aircon_Img_Fan.set_size(98,98)
ui_Aircon_Img_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_Fan.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1263449412.png','rb') as f:
        ui_Aircon_Img_Fan_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1263449412.png')
    sys.exit()

ui_Aircon_Img_Fan_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_Fan_img_data),
  'header': {'always_zero': 0, 'w': 98, 'h': 98, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_Fan_img_data
})

ui_Aircon_Img_Fan.set_src(ui_Aircon_Img_Fan_img)
ui_Aircon_Img_Fan.set_pivot(50,50)
ui_Aircon_Img_Fan.set_angle(0)
# create style style_ui_aircon_img_fan_main_main_default
style_ui_aircon_img_fan_main_main_default = lv.style_t()
style_ui_aircon_img_fan_main_main_default.init()
style_ui_aircon_img_fan_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_fan_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_fan_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_Fan
ui_Aircon_Img_Fan.add_style(style_ui_aircon_img_fan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon_Img_Cool = lv.img(ui_Aircon)
ui_Aircon_Img_Cool.set_pos(int(559),int(213))
ui_Aircon_Img_Cool.set_size(92,102)
ui_Aircon_Img_Cool.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
ui_Aircon_Img_Cool.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1073890122.png','rb') as f:
        ui_Aircon_Img_Cool_img_data = f.read()
except:
    print('Could not open C:\\Repos\\Future_training\\AirconGUI\\generated\\mPythonImages\\mp1073890122.png')
    sys.exit()

ui_Aircon_Img_Cool_img = lv.img_dsc_t({
  'data_size': len(ui_Aircon_Img_Cool_img_data),
  'header': {'always_zero': 0, 'w': 92, 'h': 102, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': ui_Aircon_Img_Cool_img_data
})

ui_Aircon_Img_Cool.set_src(ui_Aircon_Img_Cool_img)
ui_Aircon_Img_Cool.set_pivot(50,50)
ui_Aircon_Img_Cool.set_angle(0)
# create style style_ui_aircon_img_cool_main_main_default
style_ui_aircon_img_cool_main_main_default = lv.style_t()
style_ui_aircon_img_cool_main_main_default.init()
style_ui_aircon_img_cool_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_ui_aircon_img_cool_main_main_default.set_img_recolor_opa(0)
style_ui_aircon_img_cool_main_main_default.set_img_opa(255)

# add style for ui_Aircon_Img_Cool
ui_Aircon_Img_Cool.add_style(style_ui_aircon_img_cool_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)














# content from custom.py

# Load the default screen
lv.scr_load(ui_Oven)

while SDL.check():
    time.sleep_ms(5)
