# Copyright 2023 NXP
# NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
# accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
# activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
# comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
# terms, then you may not retain, install, activate or otherwise use the software.

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct
import fs_driver

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

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

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

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_zoom(v)

def anim_img_rotate_cb(obj, v):
    obj.set_angle(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.font_load(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.img_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = e.get_current_target()
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RES.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, current_time, show_second, use_ampm):
    hour = int(current_time[0])
    minute = int(current_time[1])
    second = int(current_time[2])
    ampm = current_time[3]
    second = second + 1
    if second == 60:
        second = 0
        minute = minute + 1
        if minute == 60:
            minute = 0
            hour = hour + 1
            if use_ampm:
                if hour == 12:
                    if ampm == 'AM':
                        ampm = 'PM'
                    elif ampm == 'PM':
                        ampm = 'AM'
                if hour > 12:
                    hour = hour % 12
    hour = hour % 24
    if use_ampm:
        if show_second:
            obj.set_text("%02d:%02d:%02d %s" %(hour, minute, second, ampm))
        else:
            obj.set_text("%02d:%02d %s" %(hour, minute, ampm))
    else:
        if show_second:
            obj.set_text("%02d:%02d:%02d" %(hour, minute, second))
        else:
            obj.set_text("%02d:%02d" %(hour, minute))
    current_time[0] = hour
    current_time[1] = minute
    current_time[2] = second
    current_time[3] = ampm

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def datetext_event_handler(e, obj):
    code = e.get_code()
    target = e.get_target()
    if code == lv.EVENT.FOCUSED:
        if obj is None:
            bg = lv.layer_top()
            bg.add_flag(lv.obj.FLAG.CLICKABLE)
            obj = lv.calendar(bg)
            scr = target.get_screen()
            scr_height = scr.get_height()
            scr_width = scr.get_width()
            obj.set_size(int(scr_width * 0.8), int(scr_height * 0.8))
            datestring = target.get_text()
            year = int(datestring.split('/')[0])
            month = int(datestring.split('/')[1])
            day = int(datestring.split('/')[2])
            obj.set_showed_date(year, month)
            highlighted_days=[lv.calendar_date_t({'year':year, 'month':month, 'day':day})]
            obj.set_highlighted_dates(highlighted_days, 1)
            obj.align(lv.ALIGN.CENTER, 0, 0)
            lv.calendar_header_arrow(obj)
            obj.add_event_cb(lambda e: datetext_calendar_event_handler(e, target), lv.EVENT.ALL, None)
            scr.update_layout()

def datetext_calendar_event_handler(e, obj):
    code = e.get_code()
    target = e.get_current_target()
    if code == lv.EVENT.VALUE_CHANGED:
        date = lv.calendar_date_t()
        if target.get_pressed_date(date) == lv.RES.OK:
            obj.set_text(f"{date.year}/{date.month}/{date.day}")
            bg = lv.layer_top()
            bg.clear_flag(lv.obj.FLAG.CLICKABLE)
            bg.set_style_bg_opa(lv.OPA.TRANSP, 0)
            target.delete()

def ui_Home_ta_event_cb(e,kb):
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

def ui_Hood_ta_event_cb(e,kb):
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

def ui_Aircon_ta_event_cb(e,kb):
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

def ui_Oven_ta_event_cb(e,kb):
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

# Create ui_Home
ui_Home = lv.obj()
ui_Home.set_size(1280, 720)
ui_Home.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Menu_Bg
ui_Home_ui_Image_Menu_Bg = lv.img(ui_Home)
ui_Home_ui_Image_Menu_Bg.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\menu_bg_1280_720.png"))
ui_Home_ui_Image_Menu_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Menu_Bg.set_pivot(50,50)
ui_Home_ui_Image_Menu_Bg.set_angle(0)
ui_Home_ui_Image_Menu_Bg.set_pos(0, 0)
ui_Home_ui_Image_Menu_Bg.set_size(1280, 720)
ui_Home_ui_Image_Menu_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Menu_Bg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Menu_Bg.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Group_Nxp_Logo
ui_Home_ui_Group_Nxp_Logo = lv.obj(ui_Home)
ui_Home_ui_Group_Nxp_Logo.set_pos(15, 325)
ui_Home_ui_Group_Nxp_Logo.set_size(388, 50)
ui_Home_ui_Group_Nxp_Logo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Group_Nxp_Logo, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Group_Nxp_Logo.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_border_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Nxp_Logo.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Home_ui_Image_Nxp_Logo
ui_Home_ui_Image_Nxp_Logo = lv.img(ui_Home_ui_Group_Nxp_Logo)
ui_Home_ui_Image_Nxp_Logo.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\nxp_75_27.png"))
ui_Home_ui_Image_Nxp_Logo.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Nxp_Logo.set_pivot(50,50)
ui_Home_ui_Image_Nxp_Logo.set_angle(0)
ui_Home_ui_Image_Nxp_Logo.set_pos(22, 10)
ui_Home_ui_Image_Nxp_Logo.set_size(75, 27)
ui_Home_ui_Image_Nxp_Logo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Nxp_Logo, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Nxp_Logo.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Smart_Kitchen_Demo
ui_Home_ui_Label_Smart_Kitchen_Demo = lv.label(ui_Home_ui_Group_Nxp_Logo)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_text("Smart Kitchen Demo")
ui_Home_ui_Label_Smart_Kitchen_Demo.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_pos(130, 7)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_size(240, 32)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Smart_Kitchen_Demo, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Smart_Kitchen_Demo.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Group_Aircon_Content
ui_Home_ui_Group_Aircon_Content = lv.obj(ui_Home)
ui_Home_ui_Group_Aircon_Content.set_pos(16, 29)
ui_Home_ui_Group_Aircon_Content.set_size(389, 272)
ui_Home_ui_Group_Aircon_Content.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Group_Aircon_Content, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Group_Aircon_Content.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_border_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Aircon_Content.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Home_ui_Image_Aircon_Text
ui_Home_ui_Image_Aircon_Text = lv.img(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Image_Aircon_Text.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\text_aircon_15_88.png"))
ui_Home_ui_Image_Aircon_Text.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Aircon_Text.set_pivot(50,50)
ui_Home_ui_Image_Aircon_Text.set_angle(0)
ui_Home_ui_Image_Aircon_Text.set_pos(23, 159)
ui_Home_ui_Image_Aircon_Text.set_size(15, 88)
ui_Home_ui_Image_Aircon_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Aircon_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Aircon_Text.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Aircon_Line
ui_Home_ui_Aircon_Line = lv.line(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Aircon_Line_line_points = [{"x":0, "y":0},{"x":0, "y":252},]
ui_Home_ui_Aircon_Line.set_points(ui_Home_ui_Aircon_Line_line_points, 2)
ui_Home_ui_Aircon_Line.set_pos(2, 8)
ui_Home_ui_Aircon_Line.set_size(21, 259)
ui_Home_ui_Aircon_Line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Aircon_Line, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Aircon_Line.set_style_line_width(14, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Aircon_Line.set_style_line_color(lv.color_hex(0x52DAFf), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Aircon_Line.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Aircon_Line.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_1
ui_Home_ui_Line_1 = lv.line(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Line_1_line_points = [{"x":0, "y":0},{"x":0, "y":100},]
ui_Home_ui_Line_1.set_points(ui_Home_ui_Line_1_line_points, 2)
ui_Home_ui_Line_1.set_pos(223, 152)
ui_Home_ui_Line_1.set_size(3, 108)
ui_Home_ui_Line_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_1.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_1.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_1.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_1.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Aircon_Mode
ui_Home_ui_Label_Aircon_Mode = lv.label(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Label_Aircon_Mode.set_text("MODE")
ui_Home_ui_Label_Aircon_Mode.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Aircon_Mode.set_pos(262, 143)
ui_Home_ui_Label_Aircon_Mode.set_size(100, 32)
ui_Home_ui_Label_Aircon_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Aircon_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Aircon_Mode.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_text_color(lv.color_hex(0x52DAFf), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Aircon_Fan
ui_Home_ui_Label_Aircon_Fan = lv.label(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Label_Aircon_Fan.set_text("FAN")
ui_Home_ui_Label_Aircon_Fan.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Aircon_Fan.set_pos(262, 202)
ui_Home_ui_Label_Aircon_Fan.set_size(100, 32)
ui_Home_ui_Label_Aircon_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Aircon_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Aircon_Fan.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_text_color(lv.color_hex(0x52DAFf), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Aircon_Mode_Text
ui_Home_ui_Label_Aircon_Mode_Text = lv.label(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Label_Aircon_Mode_Text.set_text("Dry")
ui_Home_ui_Label_Aircon_Mode_Text.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Aircon_Mode_Text.set_pos(281, 168)
ui_Home_ui_Label_Aircon_Mode_Text.set_size(60, 31)
ui_Home_ui_Label_Aircon_Mode_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Aircon_Mode_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Aircon_Mode_Text.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Mode_Text.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Aircon_Fan_Text
ui_Home_ui_Label_Aircon_Fan_Text = lv.label(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Label_Aircon_Fan_Text.set_text("Low")
ui_Home_ui_Label_Aircon_Fan_Text.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Aircon_Fan_Text.set_pos(268, 226)
ui_Home_ui_Label_Aircon_Fan_Text.set_size(89, 32)
ui_Home_ui_Label_Aircon_Fan_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Aircon_Fan_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Aircon_Fan_Text.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Fan_Text.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Aircon_Mode
ui_Home_ui_Image_Aircon_Mode = lv.img(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Image_Aircon_Mode.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_cool_27_31.png"))
ui_Home_ui_Image_Aircon_Mode.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Aircon_Mode.set_pivot(50,50)
ui_Home_ui_Image_Aircon_Mode.set_angle(0)
ui_Home_ui_Image_Aircon_Mode.set_pos(241, 157)
ui_Home_ui_Image_Aircon_Mode.set_size(27, 31)
ui_Home_ui_Image_Aircon_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Aircon_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Aircon_Mode.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Aircon_Fan
ui_Home_ui_Image_Aircon_Fan = lv.img(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Image_Aircon_Fan.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_fan_low_31_27.png"))
ui_Home_ui_Image_Aircon_Fan.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Aircon_Fan.set_pivot(50,50)
ui_Home_ui_Image_Aircon_Fan.set_angle(0)
ui_Home_ui_Image_Aircon_Fan.set_pos(241, 218)
ui_Home_ui_Image_Aircon_Fan.set_size(31, 27)
ui_Home_ui_Image_Aircon_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Aircon_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Aircon_Fan.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Aircon_Number1
ui_Home_ui_Label_Aircon_Number1 = lv.label(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Label_Aircon_Number1.set_text("25")
ui_Home_ui_Label_Aircon_Number1.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Aircon_Number1.set_pos(75, 155)
ui_Home_ui_Label_Aircon_Number1.set_size(120, 89)
ui_Home_ui_Label_Aircon_Number1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Aircon_Number1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Aircon_Number1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_text_color(lv.color_hex(0x52DAFf), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_text_font(test_font("Antonio_Regular", 80), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_Number1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Aircon_centigrade
ui_Home_ui_Label_Aircon_centigrade = lv.label(ui_Home_ui_Group_Aircon_Content)
ui_Home_ui_Label_Aircon_centigrade.set_text("°C")
ui_Home_ui_Label_Aircon_centigrade.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Aircon_centigrade.set_pos(156, 165)
ui_Home_ui_Label_Aircon_centigrade.set_size(64, 31)
ui_Home_ui_Label_Aircon_centigrade.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Aircon_centigrade, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Aircon_centigrade.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Aircon_centigrade.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Hood_Light_Menu
ui_Home_ui_Image_Hood_Light_Menu = lv.img(ui_Home)
ui_Home_ui_Image_Hood_Light_Menu.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\hood_menu_light_439_217.png"))
ui_Home_ui_Image_Hood_Light_Menu.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Hood_Light_Menu.set_pivot(50,50)
ui_Home_ui_Image_Hood_Light_Menu.set_angle(0)
ui_Home_ui_Image_Hood_Light_Menu.set_pos(424, 191)
ui_Home_ui_Image_Hood_Light_Menu.set_size(439, 217)
ui_Home_ui_Image_Hood_Light_Menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Hood_Light_Menu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Hood_Light_Menu.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Group_Oven_Content
ui_Home_ui_Group_Oven_Content = lv.obj(ui_Home)
ui_Home_ui_Group_Oven_Content.set_pos(16, 399)
ui_Home_ui_Group_Oven_Content.set_size(767, 305)
ui_Home_ui_Group_Oven_Content.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Group_Oven_Content, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Group_Oven_Content.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_border_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Oven_Content.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Home_ui_Image_Oven_Text
ui_Home_ui_Image_Oven_Text = lv.img(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Image_Oven_Text.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\text_oven_15_62.png"))
ui_Home_ui_Image_Oven_Text.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Oven_Text.set_pivot(50,50)
ui_Home_ui_Image_Oven_Text.set_angle(0)
ui_Home_ui_Image_Oven_Text.set_pos(23, 113)
ui_Home_ui_Image_Oven_Text.set_size(15, 62)
ui_Home_ui_Image_Oven_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Oven_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Oven_Text.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Oven_Line
ui_Home_ui_Oven_Line = lv.line(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Oven_Line_line_points = [{"x":0, "y":0},{"x":0, "y":285},]
ui_Home_ui_Oven_Line.set_points(ui_Home_ui_Oven_Line_line_points, 2)
ui_Home_ui_Oven_Line.set_pos(3, 8)
ui_Home_ui_Oven_Line.set_size(60, 291)
ui_Home_ui_Oven_Line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Oven_Line, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Oven_Line.set_style_line_width(14, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Oven_Line.set_style_line_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Oven_Line.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Oven_Line.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_4
ui_Home_ui_Line_4 = lv.line(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Line_4_line_points = [{"x":0, "y":0},{"x":198, "y":0},]
ui_Home_ui_Line_4.set_points(ui_Home_ui_Line_4_line_points, 2)
ui_Home_ui_Line_4.set_pos(62, 140)
ui_Home_ui_Line_4.set_size(198, 1)
ui_Home_ui_Line_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_4.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_4.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_4.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_4.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_5
ui_Home_ui_Line_5 = lv.line(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Line_5_line_points = [{"x":0, "y":0},{"x":0, "y":275},]
ui_Home_ui_Line_5.set_points(ui_Home_ui_Line_5_line_points, 2)
ui_Home_ui_Line_5.set_pos(283, 15)
ui_Home_ui_Line_5.set_size(2, 282)
ui_Home_ui_Line_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_5.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_5.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_5.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_5.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_6
ui_Home_ui_Line_6 = lv.line(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Line_6_line_points = [{"x":0, "y":0},{"x":150, "y":0},]
ui_Home_ui_Line_6.set_points(ui_Home_ui_Line_6_line_points, 2)
ui_Home_ui_Line_6.set_pos(308, 95)
ui_Home_ui_Line_6.set_size(157, 2)
ui_Home_ui_Line_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_6.set_style_line_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_6.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_6.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_6.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Time_Left
ui_Home_ui_Label_Time_Left = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Time_Left.set_text("TIME\nLEFT")
ui_Home_ui_Label_Time_Left.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Time_Left.set_pos(64, 180)
ui_Home_ui_Label_Time_Left.set_size(68, 44)
ui_Home_ui_Label_Time_Left.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Time_Left, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Time_Left.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Time_Left.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Status
ui_Home_ui_Label_Status = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Status.set_text("STATUS")
ui_Home_ui_Label_Status.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Status.set_pos(333, 12)
ui_Home_ui_Label_Status.set_size(100, 32)
ui_Home_ui_Label_Status.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Status, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Status.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Status.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Oven_Mode
ui_Home_ui_Label_Oven_Mode = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Oven_Mode.set_text("MODE")
ui_Home_ui_Label_Oven_Mode.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Oven_Mode.set_pos(333, 106)
ui_Home_ui_Label_Oven_Mode.set_size(100, 32)
ui_Home_ui_Label_Oven_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Oven_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Oven_Mode.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Mystat
ui_Home_ui_Label_Mystat = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Mystat.set_text("My stat")
ui_Home_ui_Label_Mystat.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Mystat.set_pos(333, 39)
ui_Home_ui_Label_Mystat.set_size(100, 32)
ui_Home_ui_Label_Mystat.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Mystat, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Mystat.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mystat.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Mode1
ui_Home_ui_Label_Mode1 = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Mode1.set_text("Fan Forced\nLower Element\nConvection")
ui_Home_ui_Label_Mode1.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Mode1.set_pos(328, 133)
ui_Home_ui_Label_Mode1.set_size(114, 96)
ui_Home_ui_Label_Mode1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Mode1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Mode1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mode1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Oven_Mode
ui_Home_ui_Image_Oven_Mode = lv.img(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Image_Oven_Mode.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_fan_upper_lower_62_62.png"))
ui_Home_ui_Image_Oven_Mode.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Oven_Mode.set_pivot(50,50)
ui_Home_ui_Image_Oven_Mode.set_angle(0)
ui_Home_ui_Image_Oven_Mode.set_pos(354, 228)
ui_Home_ui_Image_Oven_Mode.set_size(62, 62)
ui_Home_ui_Image_Oven_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Oven_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Oven_Mode.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Oven_Number1
ui_Home_ui_Label_Oven_Number1 = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Oven_Number1.set_text("250")
ui_Home_ui_Label_Oven_Number1.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Oven_Number1.set_pos(73, 33)
ui_Home_ui_Label_Oven_Number1.set_size(173, 92)
ui_Home_ui_Label_Oven_Number1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Oven_Number1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Oven_Number1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_text_font(test_font("Antonio_Regular", 80), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Number1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Oven_TimeLeft
ui_Home_ui_Label_Oven_TimeLeft = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Oven_TimeLeft.set_text("25")
ui_Home_ui_Label_Oven_TimeLeft.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Oven_TimeLeft.set_pos(146, 173)
ui_Home_ui_Label_Oven_TimeLeft.set_size(65, 61)
ui_Home_ui_Label_Oven_TimeLeft.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Oven_TimeLeft, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Oven_TimeLeft.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_text_font(test_font("Antonio_Regular", 45), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_TimeLeft.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Oven_Mins
ui_Home_ui_Label_Oven_Mins = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Oven_Mins.set_text("mins")
ui_Home_ui_Label_Oven_Mins.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Oven_Mins.set_pos(186, 196)
ui_Home_ui_Label_Oven_Mins.set_size(100, 32)
ui_Home_ui_Label_Oven_Mins.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Oven_Mins, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Oven_Mins.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_Mins.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Oven_centigrade
ui_Home_ui_Label_Oven_centigrade = lv.label(ui_Home_ui_Group_Oven_Content)
ui_Home_ui_Label_Oven_centigrade.set_text("°C")
ui_Home_ui_Label_Oven_centigrade.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Oven_centigrade.set_pos(201, 42)
ui_Home_ui_Label_Oven_centigrade.set_size(64, 31)
ui_Home_ui_Label_Oven_centigrade.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Oven_centigrade, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Oven_centigrade.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Oven_centigrade.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Group_Hood_Content
ui_Home_ui_Group_Hood_Content = lv.obj(ui_Home)
ui_Home_ui_Group_Hood_Content.set_pos(449, 20)
ui_Home_ui_Group_Hood_Content.set_size(328, 167)
ui_Home_ui_Group_Hood_Content.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Group_Hood_Content, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Group_Hood_Content.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_border_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Hood_Content.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Home_ui_Image_Hood_Text
ui_Home_ui_Image_Hood_Text = lv.img(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Image_Hood_Text.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\text_hood_15_68.png"))
ui_Home_ui_Image_Hood_Text.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Hood_Text.set_pivot(50,50)
ui_Home_ui_Image_Hood_Text.set_angle(0)
ui_Home_ui_Image_Hood_Text.set_pos(20, 45)
ui_Home_ui_Image_Hood_Text.set_size(15, 68)
ui_Home_ui_Image_Hood_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Hood_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Hood_Text.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Hood_Line
ui_Home_ui_Hood_Line = lv.line(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Hood_Line_line_points = [{"x":0, "y":0},{"x":0, "y":148},]
ui_Home_ui_Hood_Line.set_points(ui_Home_ui_Hood_Line_line_points, 2)
ui_Home_ui_Hood_Line.set_pos(-1, 6)
ui_Home_ui_Hood_Line.set_size(62, 156)
ui_Home_ui_Hood_Line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Hood_Line, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Hood_Line.set_style_line_width(14, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Hood_Line.set_style_line_color(lv.color_hex(0xACFF62), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Hood_Line.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Hood_Line.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_2
ui_Home_ui_Line_2 = lv.line(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Line_2_line_points = [{"x":0, "y":0},{"x":60, "y":0},]
ui_Home_ui_Line_2.set_points(ui_Home_ui_Line_2_line_points, 2)
ui_Home_ui_Line_2.set_pos(50, 80)
ui_Home_ui_Line_2.set_size(60, 5)
ui_Home_ui_Line_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_2.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_2.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_2.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_2.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_3
ui_Home_ui_Line_3 = lv.line(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Line_3_line_points = [{"x":0, "y":0},{"x":60, "y":0},]
ui_Home_ui_Line_3.set_points(ui_Home_ui_Line_3_line_points, 2)
ui_Home_ui_Line_3.set_pos(247, 80)
ui_Home_ui_Line_3.set_size(60, 5)
ui_Home_ui_Line_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_3.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_3.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_3.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_3.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Fan
ui_Home_ui_Label_Fan = lv.label(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Label_Fan.set_text("FAN")
ui_Home_ui_Label_Fan.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Fan.set_pos(225, 9)
ui_Home_ui_Label_Fan.set_size(100, 32)
ui_Home_ui_Label_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Fan.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_text_color(lv.color_hex(0xACFF62), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Fan.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Light
ui_Home_ui_Label_Light = lv.label(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Label_Light.set_text("LIGHT")
ui_Home_ui_Label_Light.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Light.set_pos(30, 9)
ui_Home_ui_Label_Light.set_size(100, 32)
ui_Home_ui_Label_Light.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Light, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Light.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_text_color(lv.color_hex(0xACFF62), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Light.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Hood_Light
ui_Home_ui_Image_Hood_Light = lv.img(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Image_Hood_Light.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_light_on_39_31.png"))
ui_Home_ui_Image_Hood_Light.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Hood_Light.set_pivot(50,50)
ui_Home_ui_Image_Hood_Light.set_angle(0)
ui_Home_ui_Image_Hood_Light.set_pos(61, 103)
ui_Home_ui_Image_Hood_Light.set_size(39, 31)
ui_Home_ui_Image_Hood_Light.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Hood_Light, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Hood_Light.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Hood_Fan
ui_Home_ui_Image_Hood_Fan = lv.img(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Image_Hood_Fan.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_fan_low_31_27.png"))
ui_Home_ui_Image_Hood_Fan.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Hood_Fan.set_pivot(50,50)
ui_Home_ui_Image_Hood_Fan.set_angle(0)
ui_Home_ui_Image_Hood_Fan.set_pos(261, 103)
ui_Home_ui_Image_Hood_Fan.set_size(31, 27)
ui_Home_ui_Image_Hood_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Hood_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Hood_Fan.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Hood_Light_Text
ui_Home_ui_Label_Hood_Light_Text = lv.label(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Label_Hood_Light_Text.set_text("Off")
ui_Home_ui_Label_Hood_Light_Text.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Hood_Light_Text.set_pos(51, 41)
ui_Home_ui_Label_Hood_Light_Text.set_size(58, 27)
ui_Home_ui_Label_Hood_Light_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Hood_Light_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Hood_Light_Text.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Light_Text.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Hood_Fan_Text
ui_Home_ui_Label_Hood_Fan_Text = lv.label(ui_Home_ui_Group_Hood_Content)
ui_Home_ui_Label_Hood_Fan_Text.set_text("Low")
ui_Home_ui_Label_Hood_Fan_Text.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Hood_Fan_Text.set_pos(249, 41)
ui_Home_ui_Label_Hood_Fan_Text.set_size(51, 32)
ui_Home_ui_Label_Hood_Fan_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Hood_Fan_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Hood_Fan_Text.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Hood_Fan_Text.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Group_Info
ui_Home_ui_Group_Info = lv.obj(ui_Home)
ui_Home_ui_Group_Info.set_pos(912, 0)
ui_Home_ui_Group_Info.set_size(300, 720)
ui_Home_ui_Group_Info.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Group_Info, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Group_Info.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_border_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Info.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Home_ui_Image_Weather_Icon
ui_Home_ui_Image_Weather_Icon = lv.img(ui_Home_ui_Group_Info)
ui_Home_ui_Image_Weather_Icon.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_weather_1_56_52.png"))
ui_Home_ui_Image_Weather_Icon.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Weather_Icon.set_pivot(50,50)
ui_Home_ui_Image_Weather_Icon.set_angle(0)
ui_Home_ui_Image_Weather_Icon.set_pos(22, 243)
ui_Home_ui_Image_Weather_Icon.set_size(56, 52)
ui_Home_ui_Image_Weather_Icon.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Weather_Icon, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Weather_Icon.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_7
ui_Home_ui_Line_7 = lv.line(ui_Home_ui_Group_Info)
ui_Home_ui_Line_7_line_points = [{"x":0, "y":0},{"x":255, "y":0},]
ui_Home_ui_Line_7.set_points(ui_Home_ui_Line_7_line_points, 2)
ui_Home_ui_Line_7.set_pos(22, 214)
ui_Home_ui_Line_7.set_size(263, 1)
ui_Home_ui_Line_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_7.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_7.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_7.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_7.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Line_8
ui_Home_ui_Line_8 = lv.line(ui_Home_ui_Group_Info)
ui_Home_ui_Line_8_line_points = [{"x":0, "y":0},{"x":255, "y":0},]
ui_Home_ui_Line_8.set_points(ui_Home_ui_Line_8_line_points, 2)
ui_Home_ui_Line_8.set_pos(22, 381)
ui_Home_ui_Line_8.set_size(263, 1)
ui_Home_ui_Line_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Line_8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Line_8.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_8.set_style_line_color(lv.color_hex(0x757575), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_8.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Line_8.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Label_Mic_Text
ui_Home_ui_Label_Mic_Text = lv.label(ui_Home_ui_Group_Info)
ui_Home_ui_Label_Mic_Text.set_text("\"Hey Oven\"\n\n\"Hey Hood\"\n\n\"Hey Aircon\"\n")
ui_Home_ui_Label_Mic_Text.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Label_Mic_Text.set_pos(78, 606)
ui_Home_ui_Label_Mic_Text.set_size(155, 101)
ui_Home_ui_Label_Mic_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Label_Mic_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Label_Mic_Text.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Label_Mic_Text.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Hood_Menu
ui_Home_ui_Image_Hood_Menu = lv.img(ui_Home)
ui_Home_ui_Image_Hood_Menu.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\hood_small_299_199.png"))
ui_Home_ui_Image_Hood_Menu.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Hood_Menu.set_pivot(50,50)
ui_Home_ui_Image_Hood_Menu.set_angle(0)
ui_Home_ui_Image_Hood_Menu.set_pos(479, 12)
ui_Home_ui_Image_Hood_Menu.set_size(299, 199)
ui_Home_ui_Image_Hood_Menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Hood_Menu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Hood_Menu.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Btn_Hood
ui_Home_ui_Btn_Hood = lv.btn(ui_Home)
ui_Home_ui_Btn_Hood_label = lv.label(ui_Home_ui_Btn_Hood)
ui_Home_ui_Btn_Hood_label.set_text("")
ui_Home_ui_Btn_Hood_label.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Btn_Hood_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Home_ui_Btn_Hood.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Home_ui_Btn_Hood.set_pos(457, 23)
ui_Home_ui_Btn_Hood.set_size(312, 158)
ui_Home_ui_Btn_Hood.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Btn_Hood, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Btn_Hood.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Hood.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Hood.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Hood.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Hood.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Hood.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Hood.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Aircon_Menu
ui_Home_ui_Image_Aircon_Menu = lv.img(ui_Home)
ui_Home_ui_Image_Aircon_Menu.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\aircon_small_318_125.png"))
ui_Home_ui_Image_Aircon_Menu.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Aircon_Menu.set_pivot(50,50)
ui_Home_ui_Image_Aircon_Menu.set_angle(0)
ui_Home_ui_Image_Aircon_Menu.set_pos(60, 42)
ui_Home_ui_Image_Aircon_Menu.set_size(318, 125)
ui_Home_ui_Image_Aircon_Menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Aircon_Menu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Aircon_Menu.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Oven_Menu
ui_Home_ui_Image_Oven_Menu = lv.img(ui_Home)
ui_Home_ui_Image_Oven_Menu.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\oven_light_menu_257_269.png"))
ui_Home_ui_Image_Oven_Menu.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Oven_Menu.set_pivot(50,50)
ui_Home_ui_Image_Oven_Menu.set_angle(0)
ui_Home_ui_Image_Oven_Menu.set_pos(506, 418)
ui_Home_ui_Image_Oven_Menu.set_size(257, 269)
ui_Home_ui_Image_Oven_Menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Oven_Menu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Oven_Menu.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Btn_Aircon
ui_Home_ui_Btn_Aircon = lv.btn(ui_Home)
ui_Home_ui_Btn_Aircon_label = lv.label(ui_Home_ui_Btn_Aircon)
ui_Home_ui_Btn_Aircon_label.set_text("")
ui_Home_ui_Btn_Aircon_label.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Btn_Aircon_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Home_ui_Btn_Aircon.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Home_ui_Btn_Aircon.set_pos(35, 41)
ui_Home_ui_Btn_Aircon.set_size(363, 240)
ui_Home_ui_Btn_Aircon.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Btn_Aircon, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Btn_Aircon.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Aircon.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Aircon.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Aircon.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Aircon.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Aircon.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Aircon.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Btn_Oven
ui_Home_ui_Btn_Oven = lv.btn(ui_Home)
ui_Home_ui_Btn_Oven_label = lv.label(ui_Home_ui_Btn_Oven)
ui_Home_ui_Btn_Oven_label.set_text("")
ui_Home_ui_Btn_Oven_label.set_long_mode(lv.label.LONG.WRAP)
ui_Home_ui_Btn_Oven_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Home_ui_Btn_Oven.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Home_ui_Btn_Oven.set_pos(497, 405)
ui_Home_ui_Btn_Oven.set_size(287, 295)
ui_Home_ui_Btn_Oven.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Btn_Oven, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Btn_Oven.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Oven.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Oven.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Oven.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Oven.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Oven.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Btn_Oven.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Menu_Swing
ui_Home_ui_Image_Menu_Swing = lv.img(ui_Home)
ui_Home_ui_Image_Menu_Swing.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\aircon_menu_swing_01_298_39.png"))
ui_Home_ui_Image_Menu_Swing.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Menu_Swing.set_pivot(50,50)
ui_Home_ui_Image_Menu_Swing.set_angle(0)
ui_Home_ui_Image_Menu_Swing.set_pos(72, 135)
ui_Home_ui_Image_Menu_Swing.set_size(298, 39)
ui_Home_ui_Image_Menu_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Menu_Swing, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Menu_Swing.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Group_Smog_menu_1
ui_Home_ui_Group_Smog_menu_1 = lv.obj(ui_Home)
ui_Home_ui_Group_Smog_menu_1.set_pos(494, 207)
ui_Home_ui_Group_Smog_menu_1.set_size(165, 152)
ui_Home_ui_Group_Smog_menu_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Group_Smog_menu_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Group_Smog_menu_1.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Home_ui_Image_Smog_menu_11
ui_Home_ui_Image_Smog_menu_11 = lv.img(ui_Home_ui_Group_Smog_menu_1)
ui_Home_ui_Image_Smog_menu_11.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_1_110_472.png"))
ui_Home_ui_Image_Smog_menu_11.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Smog_menu_11.set_pivot(50,50)
ui_Home_ui_Image_Smog_menu_11.set_angle(0)
ui_Home_ui_Image_Smog_menu_11.set_pos(31, 0)
ui_Home_ui_Image_Smog_menu_11.set_size(110, 472)
ui_Home_ui_Image_Smog_menu_11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Smog_menu_11, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Smog_menu_11.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Smog_menu_12
ui_Home_ui_Image_Smog_menu_12 = lv.img(ui_Home_ui_Group_Smog_menu_1)
ui_Home_ui_Image_Smog_menu_12.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_2_110_630.png"))
ui_Home_ui_Image_Smog_menu_12.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Smog_menu_12.set_pivot(0,0)
ui_Home_ui_Image_Smog_menu_12.set_angle(0)
ui_Home_ui_Image_Smog_menu_12.set_pos(31, 310)
ui_Home_ui_Image_Smog_menu_12.set_size(110, 630)
ui_Home_ui_Image_Smog_menu_12.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Smog_menu_12, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Smog_menu_12.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Group_Smog_menu_2
ui_Home_ui_Group_Smog_menu_2 = lv.obj(ui_Home)
ui_Home_ui_Group_Smog_menu_2.set_pos(599, 207)
ui_Home_ui_Group_Smog_menu_2.set_size(165, 161)
ui_Home_ui_Group_Smog_menu_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Group_Smog_menu_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Group_Smog_menu_2.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Home_ui_Group_Smog_menu_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Home_ui_Image_Smog_menu_21
ui_Home_ui_Image_Smog_menu_21 = lv.img(ui_Home_ui_Group_Smog_menu_2)
ui_Home_ui_Image_Smog_menu_21.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_1_110_472.png"))
ui_Home_ui_Image_Smog_menu_21.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Smog_menu_21.set_pivot(50,50)
ui_Home_ui_Image_Smog_menu_21.set_angle(0)
ui_Home_ui_Image_Smog_menu_21.set_pos(31, 0)
ui_Home_ui_Image_Smog_menu_21.set_size(110, 472)
ui_Home_ui_Image_Smog_menu_21.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Smog_menu_21, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Smog_menu_21.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Home_ui_Image_Smog_menu_22
ui_Home_ui_Image_Smog_menu_22 = lv.img(ui_Home_ui_Group_Smog_menu_2)
ui_Home_ui_Image_Smog_menu_22.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_2_110_630.png"))
ui_Home_ui_Image_Smog_menu_22.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Home_ui_Image_Smog_menu_22.set_pivot(0,0)
ui_Home_ui_Image_Smog_menu_22.set_angle(0)
ui_Home_ui_Image_Smog_menu_22.set_pos(31, 310)
ui_Home_ui_Image_Smog_menu_22.set_size(110, 630)
ui_Home_ui_Image_Smog_menu_22.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Home_ui_Image_Smog_menu_22, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Home_ui_Image_Smog_menu_22.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Home.update_layout()
# Create ui_Hood
ui_Hood = lv.obj()
ui_Hood.set_size(1280, 720)
ui_Hood.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Image_Hood_Bg
ui_Hood_ui_Image_Hood_Bg = lv.img(ui_Hood)
ui_Hood_ui_Image_Hood_Bg.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\hood_bg_1280_720.png"))
ui_Hood_ui_Image_Hood_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_ui_Image_Hood_Bg.set_pivot(50,50)
ui_Hood_ui_Image_Hood_Bg.set_angle(0)
ui_Hood_ui_Image_Hood_Bg.set_pos(0, 0)
ui_Hood_ui_Image_Hood_Bg.set_size(1280, 720)
ui_Hood_ui_Image_Hood_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Image_Hood_Bg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Image_Hood_Bg.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Image_Hood_Light
ui_Hood_ui_Image_Hood_Light = lv.img(ui_Hood)
ui_Hood_ui_Image_Hood_Light.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\hood_light_901_460.png"))
ui_Hood_ui_Image_Hood_Light.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_ui_Image_Hood_Light.set_pivot(50,50)
ui_Hood_ui_Image_Hood_Light.set_angle(0)
ui_Hood_ui_Image_Hood_Light.set_pos(2, 179)
ui_Hood_ui_Image_Hood_Light.set_size(901, 460)
ui_Hood_ui_Image_Hood_Light.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Image_Hood_Light, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Image_Hood_Light.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Group_Hood_Content
ui_Hood_ui_Group_Hood_Content = lv.obj(ui_Hood)
ui_Hood_ui_Group_Hood_Content.set_pos(664, 98)
ui_Hood_ui_Group_Hood_Content.set_size(548, 112)
ui_Hood_ui_Group_Hood_Content.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Group_Hood_Content, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Group_Hood_Content.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_border_color(lv.color_hex(0x4A4C4a), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_radius(20, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Hood_Content.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Hood_ui_Hood_Line
ui_Hood_ui_Hood_Line = lv.line(ui_Hood_ui_Group_Hood_Content)
ui_Hood_ui_Hood_Line_line_points = [{"x":0, "y":0},{"x":526, "y":0},]
ui_Hood_ui_Hood_Line.set_points(ui_Hood_ui_Hood_Line_line_points, 2)
ui_Hood_ui_Hood_Line.set_pos(9, 8)
ui_Hood_ui_Hood_Line.set_size(535, 14)
ui_Hood_ui_Hood_Line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Hood_Line, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Hood_Line.set_style_line_width(17, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Hood_Line.set_style_line_color(lv.color_hex(0xACFF62), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Hood_Line.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Hood_Line.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Slider_Hood_Fan
ui_Hood_ui_Slider_Hood_Fan = lv.slider(ui_Hood_ui_Group_Hood_Content)
ui_Hood_ui_Slider_Hood_Fan.set_range(0,2)
ui_Hood_ui_Slider_Hood_Fan.set_value(1, False)
ui_Hood_ui_Slider_Hood_Fan.set_pos(329, 37)
ui_Hood_ui_Slider_Hood_Fan.set_size(180, 16)
ui_Hood_ui_Slider_Hood_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Slider_Hood_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Slider_Hood_Fan.set_style_bg_opa(60, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_bg_color(lv.color_hex(0x52555A), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_radius(50, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_outline_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Hood_ui_Slider_Hood_Fan, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
ui_Hood_ui_Slider_Hood_Fan.set_style_bg_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_bg_color(lv.color_hex(0x73CA29), lv.PART.INDICATOR|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_radius(50, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Set style for ui_Hood_ui_Slider_Hood_Fan, Part: lv.PART.KNOB, State: lv.STATE.DEFAULT.
ui_Hood_ui_Slider_Hood_Fan.set_style_bg_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.KNOB|lv.STATE.DEFAULT)
ui_Hood_ui_Slider_Hood_Fan.set_style_radius(50, lv.PART.KNOB|lv.STATE.DEFAULT)

# Create ui_Hood_sw_1
ui_Hood_sw_1 = lv.switch(ui_Hood_ui_Group_Hood_Content)
ui_Hood_sw_1.set_pos(106, 43)
ui_Hood_sw_1.set_size(76, 34)
ui_Hood_sw_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_sw_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_sw_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_sw_1.set_style_bg_color(lv.color_hex(0x6A6A6a), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_sw_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_sw_1.set_style_radius(100, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_sw_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Hood_sw_1, Part: lv.PART.MAIN, State: lv.STATE.DISABLED.
ui_Hood_sw_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DISABLED)
ui_Hood_sw_1.set_style_bg_color(lv.color_hex(0xe6e2e6), lv.PART.MAIN|lv.STATE.DISABLED)
ui_Hood_sw_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DISABLED)
ui_Hood_sw_1.set_style_radius(100, lv.PART.MAIN|lv.STATE.DISABLED)
ui_Hood_sw_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DISABLED)
# Set style for ui_Hood_sw_1, Part: lv.PART.INDICATOR, State: lv.STATE.CHECKED.
ui_Hood_sw_1.set_style_bg_opa(255, lv.PART.INDICATOR|lv.STATE.CHECKED)
ui_Hood_sw_1.set_style_bg_color(lv.color_hex(0x73CA29), lv.PART.INDICATOR|lv.STATE.CHECKED)
ui_Hood_sw_1.set_style_border_width(0, lv.PART.INDICATOR|lv.STATE.CHECKED)

# Set style for ui_Hood_sw_1, Part: lv.PART.KNOB, State: lv.STATE.DEFAULT.
ui_Hood_sw_1.set_style_bg_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
ui_Hood_sw_1.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.KNOB|lv.STATE.DEFAULT)
ui_Hood_sw_1.set_style_border_width(0, lv.PART.KNOB|lv.STATE.DEFAULT)
ui_Hood_sw_1.set_style_radius(100, lv.PART.KNOB|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Line2
ui_Hood_ui_Line2 = lv.line(ui_Hood_ui_Group_Hood_Content)
ui_Hood_ui_Line2_line_points = [{"x":0, "y":0},{"x":0, "y":60},]
ui_Hood_ui_Line2.set_points(ui_Hood_ui_Line2_line_points, 2)
ui_Hood_ui_Line2.set_pos(209, 32)
ui_Hood_ui_Line2.set_size(8, 65)
ui_Hood_ui_Line2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Line2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Line2.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Line2.set_style_line_color(lv.color_hex(0x52555a), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Line2.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Line2.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Label_Light
ui_Hood_ui_Label_Light = lv.label(ui_Hood_ui_Group_Hood_Content)
ui_Hood_ui_Label_Light.set_text("LIGHT")
ui_Hood_ui_Label_Light.set_long_mode(lv.label.LONG.WRAP)
ui_Hood_ui_Label_Light.set_pos(4, 44)
ui_Hood_ui_Label_Light.set_size(100, 32)
ui_Hood_ui_Label_Light.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Label_Light, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Label_Light.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_text_color(lv.color_hex(0xACFF62), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_text_font(test_font("montserratMedium", 19), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Light.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Image_Hood_Text
ui_Hood_ui_Image_Hood_Text = lv.img(ui_Hood_ui_Group_Hood_Content)
ui_Hood_ui_Image_Hood_Text.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\text_fan_param_198_26.png"))
ui_Hood_ui_Image_Hood_Text.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_ui_Image_Hood_Text.set_pivot(50,50)
ui_Hood_ui_Image_Hood_Text.set_angle(0)
ui_Hood_ui_Image_Hood_Text.set_pos(323, 70)
ui_Hood_ui_Image_Hood_Text.set_size(198, 26)
ui_Hood_ui_Image_Hood_Text.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Image_Hood_Text, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Image_Hood_Text.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Label_Fan
ui_Hood_ui_Label_Fan = lv.label(ui_Hood_ui_Group_Hood_Content)
ui_Hood_ui_Label_Fan.set_text("FAN")
ui_Hood_ui_Label_Fan.set_long_mode(lv.label.LONG.WRAP)
ui_Hood_ui_Label_Fan.set_pos(216, 44)
ui_Hood_ui_Label_Fan.set_size(100, 32)
ui_Hood_ui_Label_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Label_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Label_Fan.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_text_color(lv.color_hex(0xACFF62), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_text_font(test_font("montserratMedium", 19), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Label_Fan.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Group_Smog1
ui_Hood_ui_Group_Smog1 = lv.obj(ui_Hood)
ui_Hood_ui_Group_Smog1.set_pos(189, 210)
ui_Hood_ui_Group_Smog1.set_size(195, 310)
ui_Hood_ui_Group_Smog1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Group_Smog1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Group_Smog1.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Hood_ui_Image_Smog11
ui_Hood_ui_Image_Smog11 = lv.img(ui_Hood_ui_Group_Smog1)
ui_Hood_ui_Image_Smog11.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_1_133_472.png"))
ui_Hood_ui_Image_Smog11.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_ui_Image_Smog11.set_pivot(50,50)
ui_Hood_ui_Image_Smog11.set_angle(0)
ui_Hood_ui_Image_Smog11.set_pos(31, 0)
ui_Hood_ui_Image_Smog11.set_size(133, 472)
ui_Hood_ui_Image_Smog11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Image_Smog11, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Image_Smog11.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Image_Smog12
ui_Hood_ui_Image_Smog12 = lv.img(ui_Hood_ui_Group_Smog1)
ui_Hood_ui_Image_Smog12.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_2_133_630.png"))
ui_Hood_ui_Image_Smog12.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_ui_Image_Smog12.set_pivot(0,0)
ui_Hood_ui_Image_Smog12.set_angle(0)
ui_Hood_ui_Image_Smog12.set_pos(31, 310)
ui_Hood_ui_Image_Smog12.set_size(133, 630)
ui_Hood_ui_Image_Smog12.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Image_Smog12, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Image_Smog12.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Group_Smog2
ui_Hood_ui_Group_Smog2 = lv.obj(ui_Hood)
ui_Hood_ui_Group_Smog2.set_pos(411, 210)
ui_Hood_ui_Group_Smog2.set_size(195, 310)
ui_Hood_ui_Group_Smog2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Group_Smog2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Group_Smog2.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Group_Smog2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Hood_ui_Image_Smog21
ui_Hood_ui_Image_Smog21 = lv.img(ui_Hood_ui_Group_Smog2)
ui_Hood_ui_Image_Smog21.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_1_133_472.png"))
ui_Hood_ui_Image_Smog21.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_ui_Image_Smog21.set_pivot(50,50)
ui_Hood_ui_Image_Smog21.set_angle(0)
ui_Hood_ui_Image_Smog21.set_pos(33, 0)
ui_Hood_ui_Image_Smog21.set_size(133, 472)
ui_Hood_ui_Image_Smog21.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Image_Smog21, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Image_Smog21.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Image_Smog22
ui_Hood_ui_Image_Smog22 = lv.img(ui_Hood_ui_Group_Smog2)
ui_Hood_ui_Image_Smog22.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\smog_2_133_630.png"))
ui_Hood_ui_Image_Smog22.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_ui_Image_Smog22.set_pivot(50,50)
ui_Hood_ui_Image_Smog22.set_angle(0)
ui_Hood_ui_Image_Smog22.set_pos(33, 310)
ui_Hood_ui_Image_Smog22.set_size(133, 630)
ui_Hood_ui_Image_Smog22.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Image_Smog22, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Image_Smog22.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_Img_Label_Bg
ui_Hood_Img_Label_Bg = lv.img(ui_Hood)
ui_Hood_Img_Label_Bg.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\title_bg_2_783_128.png"))
ui_Hood_Img_Label_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Hood_Img_Label_Bg.set_pivot(50,50)
ui_Hood_Img_Label_Bg.set_angle(0)
ui_Hood_Img_Label_Bg.set_pos(630, -15)
ui_Hood_Img_Label_Bg.set_size(783, 128)
ui_Hood_Img_Label_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_Img_Label_Bg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_Img_Label_Bg.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_Label_Hood
ui_Hood_Label_Hood = lv.label(ui_Hood)
ui_Hood_Label_Hood.set_text("Hood")
ui_Hood_Label_Hood.set_long_mode(lv.label.LONG.WRAP)
ui_Hood_Label_Hood.set_pos(679, 33)
ui_Hood_Label_Hood.set_size(100, 32)
ui_Hood_Label_Hood.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_Label_Hood, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_Label_Hood.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_text_font(test_font("Antonio_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_Label_Hood.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Hood_ui_Btn_Back1
ui_Hood_ui_Btn_Back1 = lv.btn(ui_Hood)
ui_Hood_ui_Btn_Back1_label = lv.label(ui_Hood_ui_Btn_Back1)
ui_Hood_ui_Btn_Back1_label.set_text("BACK")
ui_Hood_ui_Btn_Back1_label.set_long_mode(lv.label.LONG.WRAP)
ui_Hood_ui_Btn_Back1_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Hood_ui_Btn_Back1.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_pos(-41, 24)
ui_Hood_ui_Btn_Back1.set_size(155, 65)
ui_Hood_ui_Btn_Back1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Hood_ui_Btn_Back1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Hood_ui_Btn_Back1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_style_radius(65, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Hood_ui_Btn_Back1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Hood.update_layout()
# Create ui_Aircon
ui_Aircon = lv.obj()
ui_Aircon.set_size(1280, 720)
ui_Aircon.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_Bg
ui_Aircon_Img_Bg = lv.img(ui_Aircon)
ui_Aircon_Img_Bg.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\aircon_bg_1280_720.png"))
ui_Aircon_Img_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_Bg.set_pivot(50,50)
ui_Aircon_Img_Bg.set_angle(0)
ui_Aircon_Img_Bg.set_pos(0, 0)
ui_Aircon_Img_Bg.set_size(1280, 720)
ui_Aircon_Img_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_Bg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_Bg.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_Label_Bg
ui_Aircon_Img_Label_Bg = lv.img(ui_Aircon)
ui_Aircon_Img_Label_Bg.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\title_bg_799_130.png"))
ui_Aircon_Img_Label_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_Label_Bg.set_pivot(50,50)
ui_Aircon_Img_Label_Bg.set_angle(0)
ui_Aircon_Img_Label_Bg.set_pos(0, 590)
ui_Aircon_Img_Label_Bg.set_size(799, 130)
ui_Aircon_Img_Label_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_Label_Bg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_Label_Bg.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Air
ui_Aircon_Label_Air = lv.label(ui_Aircon)
ui_Aircon_Label_Air.set_text("Air Conditioner")
ui_Aircon_Label_Air.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Air.set_pos(565, 639)
ui_Aircon_Label_Air.set_size(180, 32)
ui_Aircon_Label_Air.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Air, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Air.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_text_font(test_font("Antonio_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Air.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_Swing
ui_Aircon_Img_Swing = lv.img(ui_Aircon)
ui_Aircon_Img_Swing.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\aircon_swing_1_632_113.png"))
ui_Aircon_Img_Swing.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_Swing.set_pivot(50,50)
ui_Aircon_Img_Swing.set_angle(0)
ui_Aircon_Img_Swing.set_pos(120, 380)
ui_Aircon_Img_Swing.set_size(632, 113)
ui_Aircon_Img_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_Swing, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_Swing.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Cont
ui_Aircon_Cont = lv.obj(ui_Aircon)
ui_Aircon_Cont.set_pos(826, 30)
ui_Aircon_Cont.set_size(409, 657)
ui_Aircon_Cont.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Cont, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Cont.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_border_color(lv.color_hex(0x4A4C4A), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_radius(20, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_bg_opa(250, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_bg_color(lv.color_hex(0x242424), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Cont.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Aircon_line
ui_Aircon_line = lv.line(ui_Aircon_Cont)
ui_Aircon_line_line_points = [{"x":0, "y":0},{"x":393, "y":0},]
ui_Aircon_line.set_points(ui_Aircon_line_line_points, 2)
ui_Aircon_line.set_pos(7, 7)
ui_Aircon_line.set_size(405, 24)
ui_Aircon_line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_line, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_line.set_style_line_width(17, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line.set_style_line_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Temp
ui_Aircon_Label_Temp = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Temp.set_text("25")
ui_Aircon_Label_Temp.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Temp.set_pos(12, 58)
ui_Aircon_Label_Temp.set_size(151, 123)
ui_Aircon_Label_Temp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Temp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Temp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_text_font(test_font("Antonio_Regular", 120), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Temp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Btn_TempUp
ui_Aircon_Btn_TempUp = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TempUp_label = lv.label(ui_Aircon_Btn_TempUp)
ui_Aircon_Btn_TempUp_label.set_text("")
ui_Aircon_Btn_TempUp_label.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Btn_TempUp_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Aircon_Btn_TempUp.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_pos(198, 100)
ui_Aircon_Btn_TempUp.set_size(74, 58)
ui_Aircon_Btn_TempUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Btn_TempUp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Btn_TempUp.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_style_bg_color(lv.color_hex(0x29BAE6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempUp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Btn_TempUp, Part: lv.PART.MAIN, State: lv.STATE.PRESSED.
ui_Aircon_Btn_TempUp.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempUp.set_style_bg_color(lv.color_hex(0x18C220), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempUp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempUp.set_style_radius(10, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempUp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempUp.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempUp.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.PRESSED)

# Create ui_Aircon_Label_SetTemp
ui_Aircon_Label_SetTemp = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_SetTemp.set_text("SET TEMPERATURE")
ui_Aircon_Label_SetTemp.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_SetTemp.set_pos(110, 22)
ui_Aircon_Label_SetTemp.set_size(203, 32)
ui_Aircon_Label_SetTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_SetTemp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_SetTemp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_text_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_SetTemp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Cen
ui_Aircon_Label_Cen = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Cen.set_text("ºC")
ui_Aircon_Label_Cen.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Cen.set_pos(121, 61)
ui_Aircon_Label_Cen.set_size(72, 53)
ui_Aircon_Label_Cen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Cen, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Cen.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_text_font(test_font("Alatsi_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Cen.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Btn_TempDown
ui_Aircon_Btn_TempDown = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TempDown_label = lv.label(ui_Aircon_Btn_TempDown)
ui_Aircon_Btn_TempDown_label.set_text("")
ui_Aircon_Btn_TempDown_label.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Btn_TempDown_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Aircon_Btn_TempDown.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_pos(295, 100)
ui_Aircon_Btn_TempDown.set_size(74, 58)
ui_Aircon_Btn_TempDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Btn_TempDown, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Btn_TempDown.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_style_bg_color(lv.color_hex(0x29BAE6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TempDown.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Btn_TempDown, Part: lv.PART.MAIN, State: lv.STATE.PRESSED.
ui_Aircon_Btn_TempDown.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempDown.set_style_bg_color(lv.color_hex(0x18C220), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempDown.set_style_border_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempDown.set_style_radius(10, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempDown.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempDown.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TempDown.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.PRESSED)

# Create ui_Aircon_Img_TemUp
ui_Aircon_Img_TemUp = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TemUp.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_up_28_14.png"))
ui_Aircon_Img_TemUp.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_TemUp.set_pivot(50,50)
ui_Aircon_Img_TemUp.set_angle(0)
ui_Aircon_Img_TemUp.set_pos(222, 122)
ui_Aircon_Img_TemUp.set_size(28, 14)
ui_Aircon_Img_TemUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_TemUp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_TemUp.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_TempDown
ui_Aircon_Img_TempDown = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TempDown.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_down_28_14.png"))
ui_Aircon_Img_TempDown.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_TempDown.set_pivot(50,50)
ui_Aircon_Img_TempDown.set_angle(0)
ui_Aircon_Img_TempDown.set_pos(319, 122)
ui_Aircon_Img_TempDown.set_size(28, 14)
ui_Aircon_Img_TempDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_TempDown, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_TempDown.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Roller_Mode
ui_Aircon_Roller_Mode = lv.roller(ui_Aircon_Cont)
ui_Aircon_Roller_Mode.set_options("COOL\nDRY\nFAN", lv.roller.MODE.INFINITE)
ui_Aircon_Roller_Mode.set_visible_row_count(3)
ui_Aircon_Roller_Mode.set_pos(40, 404)
ui_Aircon_Roller_Mode.set_width(100)
ui_Aircon_Roller_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Roller_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Roller_Mode.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_text_color(lv.color_hex(0x9D9D9D), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Roller_Mode, Part: lv.PART.SELECTED, State: lv.STATE.DEFAULT.
ui_Aircon_Roller_Mode.set_style_bg_opa(255, lv.PART.SELECTED|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_bg_color(lv.color_hex(0x20A1C5), lv.PART.SELECTED|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_text_color(lv.color_hex(0xFFFFFF), lv.PART.SELECTED|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.SELECTED|lv.STATE.DEFAULT)
ui_Aircon_Roller_Mode.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.SELECTED|lv.STATE.DEFAULT)

# Create ui_Aircon_Btn_Swing
ui_Aircon_Btn_Swing = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_Swing.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Aircon_Btn_Swing_label = lv.label(ui_Aircon_Btn_Swing)
ui_Aircon_Btn_Swing_label.set_text("ON")
ui_Aircon_Btn_Swing_label.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Btn_Swing_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Aircon_Btn_Swing.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_pos(99, 572)
ui_Aircon_Btn_Swing.set_size(78, 45)
ui_Aircon_Btn_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Btn_Swing, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Btn_Swing.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_style_bg_color(lv.color_hex(0x6A6A6A), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_style_text_color(lv.color_hex(0x9D9D9D), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_Swing.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Btn_Swing, Part: lv.PART.MAIN, State: lv.STATE.PRESSED.
ui_Aircon_Btn_Swing.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_Swing.set_style_bg_color(lv.color_hex(0x29BAE6), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_Swing.set_style_border_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_Swing.set_style_radius(10, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_Swing.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_Swing.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_Swing.set_style_text_font(test_font("Antonio_Regular", 20), lv.PART.MAIN|lv.STATE.PRESSED)
# Set style for ui_Aircon_Btn_Swing, Part: lv.PART.MAIN, State: lv.STATE.CHECKED.
ui_Aircon_Btn_Swing.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.CHECKED)
ui_Aircon_Btn_Swing.set_style_bg_color(lv.color_hex(0x29BAE6), lv.PART.MAIN|lv.STATE.CHECKED)
ui_Aircon_Btn_Swing.set_style_border_width(0, lv.PART.MAIN|lv.STATE.CHECKED)
ui_Aircon_Btn_Swing.set_style_radius(10, lv.PART.MAIN|lv.STATE.CHECKED)
ui_Aircon_Btn_Swing.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.CHECKED)
ui_Aircon_Btn_Swing.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.CHECKED)
ui_Aircon_Btn_Swing.set_style_text_font(test_font("Antonio_Regular", 20), lv.PART.MAIN|lv.STATE.CHECKED)

# Create ui_Aircon_Label_Swing
ui_Aircon_Label_Swing = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Swing.set_text("SWING")
ui_Aircon_Label_Swing.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Swing.set_pos(30, 576)
ui_Aircon_Label_Swing.set_size(73, 38)
ui_Aircon_Label_Swing.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Swing, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Swing.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_text_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Swing.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_line_1
ui_Aircon_line_1 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_1_line_points = [{"x":0, "y":0},{"x":360, "y":0},]
ui_Aircon_line_1.set_points(ui_Aircon_line_1_line_points, 2)
ui_Aircon_line_1.set_pos(23, 199)
ui_Aircon_line_1.set_size(371, 13)
ui_Aircon_line_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_line_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_line_1.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_1.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_1.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_line_2
ui_Aircon_line_2 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_2_line_points = [{"x":0, "y":0},{"x":360, "y":0},]
ui_Aircon_line_2.set_points(ui_Aircon_line_2_line_points, 2)
ui_Aircon_line_2.set_pos(23, 359)
ui_Aircon_line_2.set_size(371, 13)
ui_Aircon_line_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_line_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_line_2.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_2.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_2.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_line_3
ui_Aircon_line_3 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_3_line_points = [{"x":0, "y":0},{"x":360, "y":0},]
ui_Aircon_line_3.set_points(ui_Aircon_line_3_line_points, 2)
ui_Aircon_line_3.set_pos(23, 540)
ui_Aircon_line_3.set_size(371, 7)
ui_Aircon_line_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_line_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_line_3.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_3.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_3.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_line_4
ui_Aircon_line_4 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_4_line_points = [{"x":0, "y":0},{"x":0, "y":100},]
ui_Aircon_line_4.set_points(ui_Aircon_line_4_line_points, 2)
ui_Aircon_line_4.set_pos(242, 410)
ui_Aircon_line_4.set_size(29, 119)
ui_Aircon_line_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_line_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_line_4.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_4.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_4.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_line_5
ui_Aircon_line_5 = lv.line(ui_Aircon_Cont)
ui_Aircon_line_5_line_points = [{"x":0, "y":0},{"x":0, "y":50},]
ui_Aircon_line_5.set_points(ui_Aircon_line_5_line_points, 2)
ui_Aircon_line_5.set_pos(192, 568)
ui_Aircon_line_5.set_size(17, 67)
ui_Aircon_line_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_line_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_line_5.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_5.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_line_5.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Timer
ui_Aircon_Label_Timer = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Timer.set_text("SET TIMER")
ui_Aircon_Label_Timer.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Timer.set_pos(105, 202)
ui_Aircon_Label_Timer.set_size(203, 32)
ui_Aircon_Label_Timer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Timer, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Timer.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_text_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Timer.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Mode
ui_Aircon_Label_Mode = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Mode.set_text("SELECT MODE")
ui_Aircon_Label_Mode.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Mode.set_pos(123, 364)
ui_Aircon_Label_Mode.set_size(178, 34)
ui_Aircon_Label_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Mode.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_text_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Mode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Fan
ui_Aircon_Label_Fan = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Fan.set_text("FAN")
ui_Aircon_Label_Fan.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Fan.set_pos(204, 571)
ui_Aircon_Label_Fan.set_size(45, 38)
ui_Aircon_Label_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Fan.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_text_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Fan.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Slider_Fan
ui_Aircon_Slider_Fan = lv.slider(ui_Aircon_Cont)
ui_Aircon_Slider_Fan.set_range(0,2)
ui_Aircon_Slider_Fan.set_value(1, False)
ui_Aircon_Slider_Fan.set_pos(257, 579)
ui_Aircon_Slider_Fan.set_size(127, 16)
ui_Aircon_Slider_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Slider_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Slider_Fan.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_bg_color(lv.color_hex(0x6A6A6A), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_radius(50, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_outline_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Slider_Fan, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
ui_Aircon_Slider_Fan.set_style_bg_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_bg_color(lv.color_hex(0x29BAE6), lv.PART.INDICATOR|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_radius(50, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Slider_Fan, Part: lv.PART.KNOB, State: lv.STATE.DEFAULT.
ui_Aircon_Slider_Fan.set_style_bg_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.KNOB|lv.STATE.DEFAULT)
ui_Aircon_Slider_Fan.set_style_radius(50, lv.PART.KNOB|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Low
ui_Aircon_Label_Low = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Low.set_text("•\nLOW")
ui_Aircon_Label_Low.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Low.set_pos(249, 592)
ui_Aircon_Label_Low.set_size(29, 34)
ui_Aircon_Label_Low.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Low, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Low.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_text_font(test_font("Antonio_Regular", 12), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Low.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Medium
ui_Aircon_Label_Medium = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Medium.set_text("•\nMEDIUM")
ui_Aircon_Label_Medium.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Medium.set_pos(295, 592)
ui_Aircon_Label_Medium.set_size(53, 34)
ui_Aircon_Label_Medium.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Medium, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Medium.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_text_font(test_font("Antonio_Regular", 12), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Medium.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_High
ui_Aircon_Label_High = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_High.set_text("•\nHIGH")
ui_Aircon_Label_High.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_High.set_pos(363, 592)
ui_Aircon_Label_High.set_size(29, 34)
ui_Aircon_Label_High.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_High, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_High.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_text_font(test_font("Antonio_Regular", 12), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_High.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_Comp
ui_Aircon_Label_Comp = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_Comp.set_text("COMP")
ui_Aircon_Label_Comp.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_Comp.set_pos(302, 402)
ui_Aircon_Label_Comp.set_size(65, 30)
ui_Aircon_Label_Comp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_Comp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_Comp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_text_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_text_font(test_font("Antonio_Regular", 19), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_Comp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_On
ui_Aircon_Label_On = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_On.set_text("ON")
ui_Aircon_Label_On.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_On.set_pos(302, 424)
ui_Aircon_Label_On.set_size(65, 30)
ui_Aircon_Label_On.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_On, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_On.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_text_font(test_font("Antonio_Regular", 19), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_On.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_Comp
ui_Aircon_Img_Comp = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_Comp.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_cool_27_31.png"))
ui_Aircon_Img_Comp.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_Comp.set_pivot(50,50)
ui_Aircon_Img_Comp.set_angle(0)
ui_Aircon_Img_Comp.set_pos(272, 413)
ui_Aircon_Img_Comp.set_size(27, 31)
ui_Aircon_Img_Comp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_Comp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_Comp.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_FanSt
ui_Aircon_Label_FanSt = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_FanSt.set_text("FAN")
ui_Aircon_Label_FanSt.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_FanSt.set_pos(303, 462)
ui_Aircon_Label_FanSt.set_size(65, 30)
ui_Aircon_Label_FanSt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_FanSt, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_FanSt.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_text_color(lv.color_hex(0x52DAFF), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_text_font(test_font("Antonio_Regular", 19), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanSt.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_FanState
ui_Aircon_Label_FanState = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_FanState.set_text("LOW")
ui_Aircon_Label_FanState.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_FanState.set_pos(303, 485)
ui_Aircon_Label_FanState.set_size(65, 30)
ui_Aircon_Label_FanState.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_FanState, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_FanState.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_text_font(test_font("Antonio_Regular", 19), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_FanState.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_FanSt
ui_Aircon_Img_FanSt = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_FanSt.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_fan_low_31_27.png"))
ui_Aircon_Img_FanSt.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_FanSt.set_pivot(50,50)
ui_Aircon_Img_FanSt.set_angle(0)
ui_Aircon_Img_FanSt.set_pos(272, 474)
ui_Aircon_Img_FanSt.set_size(31, 27)
ui_Aircon_Img_FanSt.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_FanSt, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_FanSt.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Btn_TimerUp
ui_Aircon_Btn_TimerUp = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TimerUp_label = lv.label(ui_Aircon_Btn_TimerUp)
ui_Aircon_Btn_TimerUp_label.set_text("")
ui_Aircon_Btn_TimerUp_label.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Btn_TimerUp_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Aircon_Btn_TimerUp.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_pos(198, 260)
ui_Aircon_Btn_TimerUp.set_size(74, 58)
ui_Aircon_Btn_TimerUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Btn_TimerUp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Btn_TimerUp.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_style_bg_color(lv.color_hex(0x29BAE6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerUp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Btn_TimerUp, Part: lv.PART.MAIN, State: lv.STATE.PRESSED.
ui_Aircon_Btn_TimerUp.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerUp.set_style_bg_color(lv.color_hex(0x18C220), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerUp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerUp.set_style_radius(10, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerUp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerUp.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerUp.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.PRESSED)

# Create ui_Aircon_Img_TimerUp
ui_Aircon_Img_TimerUp = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TimerUp.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_up_28_14.png"))
ui_Aircon_Img_TimerUp.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_TimerUp.set_pivot(50,50)
ui_Aircon_Img_TimerUp.set_angle(0)
ui_Aircon_Img_TimerUp.set_pos(222, 281)
ui_Aircon_Img_TimerUp.set_size(28, 14)
ui_Aircon_Img_TimerUp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_TimerUp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_TimerUp.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Btn_TimerDown
ui_Aircon_Btn_TimerDown = lv.btn(ui_Aircon_Cont)
ui_Aircon_Btn_TimerDown_label = lv.label(ui_Aircon_Btn_TimerDown)
ui_Aircon_Btn_TimerDown_label.set_text("")
ui_Aircon_Btn_TimerDown_label.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Btn_TimerDown_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Aircon_Btn_TimerDown.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_pos(295, 260)
ui_Aircon_Btn_TimerDown.set_size(74, 58)
ui_Aircon_Btn_TimerDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Btn_TimerDown, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Btn_TimerDown.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_style_bg_color(lv.color_hex(0x29BAE6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Btn_TimerDown.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Aircon_Btn_TimerDown, Part: lv.PART.MAIN, State: lv.STATE.PRESSED.
ui_Aircon_Btn_TimerDown.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerDown.set_style_bg_color(lv.color_hex(0x18C220), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerDown.set_style_border_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerDown.set_style_radius(10, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerDown.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerDown.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Aircon_Btn_TimerDown.set_style_text_font(test_font("simsun", 16), lv.PART.MAIN|lv.STATE.PRESSED)

# Create ui_Aircon_Img_TimerDown
ui_Aircon_Img_TimerDown = lv.img(ui_Aircon_Cont)
ui_Aircon_Img_TimerDown.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_down_28_14.png"))
ui_Aircon_Img_TimerDown.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_TimerDown.set_pivot(50,50)
ui_Aircon_Img_TimerDown.set_angle(0)
ui_Aircon_Img_TimerDown.set_pos(319, 281)
ui_Aircon_Img_TimerDown.set_size(28, 14)
ui_Aircon_Img_TimerDown.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_TimerDown, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_TimerDown.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_TimerHour
ui_Aircon_Label_TimerHour = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_TimerHour.set_text("01")
ui_Aircon_Label_TimerHour.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_TimerHour.set_pos(19, 234)
ui_Aircon_Label_TimerHour.set_size(76, 103)
ui_Aircon_Label_TimerHour.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_TimerHour, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_TimerHour.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_text_font(test_font("Antonio_Regular", 80), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerHour.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_TimerPoints
ui_Aircon_Label_TimerPoints = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_TimerPoints.set_text(":")
ui_Aircon_Label_TimerPoints.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_TimerPoints.set_pos(93, 229)
ui_Aircon_Label_TimerPoints.set_size(23, 103)
ui_Aircon_Label_TimerPoints.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_TimerPoints, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_TimerPoints.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_text_font(test_font("Antonio_Regular", 80), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerPoints.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Label_TimerMin
ui_Aircon_Label_TimerMin = lv.label(ui_Aircon_Cont)
ui_Aircon_Label_TimerMin.set_text("15")
ui_Aircon_Label_TimerMin.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_Label_TimerMin.set_pos(118, 234)
ui_Aircon_Label_TimerMin.set_size(76, 103)
ui_Aircon_Label_TimerMin.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Label_TimerMin, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Label_TimerMin.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_text_font(test_font("Antonio_Regular", 80), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_Label_TimerMin.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_Fan
ui_Aircon_Img_Fan = lv.img(ui_Aircon)
ui_Aircon_Img_Fan.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\aircon_fan_1_98_98.png"))
ui_Aircon_Img_Fan.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_Fan.set_pivot(50,50)
ui_Aircon_Img_Fan.set_angle(0)
ui_Aircon_Img_Fan.set_pos(646, 218)
ui_Aircon_Img_Fan.set_size(98, 98)
ui_Aircon_Img_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_Fan.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_Img_Cool
ui_Aircon_Img_Cool = lv.img(ui_Aircon)
ui_Aircon_Img_Cool.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\aircon_cool_1_92_102.png"))
ui_Aircon_Img_Cool.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Aircon_Img_Cool.set_pivot(50,50)
ui_Aircon_Img_Cool.set_angle(0)
ui_Aircon_Img_Cool.set_pos(559, 213)
ui_Aircon_Img_Cool.set_size(92, 102)
ui_Aircon_Img_Cool.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_Img_Cool, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_Img_Cool.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Aircon_ui_Btn_Back2
ui_Aircon_ui_Btn_Back2 = lv.btn(ui_Aircon)
ui_Aircon_ui_Btn_Back2_label = lv.label(ui_Aircon_ui_Btn_Back2)
ui_Aircon_ui_Btn_Back2_label.set_text("BACK")
ui_Aircon_ui_Btn_Back2_label.set_long_mode(lv.label.LONG.WRAP)
ui_Aircon_ui_Btn_Back2_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Aircon_ui_Btn_Back2.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_pos(-38, 23)
ui_Aircon_ui_Btn_Back2.set_size(155, 65)
ui_Aircon_ui_Btn_Back2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Aircon_ui_Btn_Back2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Aircon_ui_Btn_Back2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_style_radius(65, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Aircon_ui_Btn_Back2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Aircon.update_layout()
# Create ui_Oven
ui_Oven = lv.obj()
ui_Oven.set_size(1280, 720)
ui_Oven.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Bg
ui_Oven_Img_Bg = lv.img(ui_Oven)
ui_Oven_Img_Bg.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\oven_bg_1280_720.png"))
ui_Oven_Img_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Bg.set_pivot(50,50)
ui_Oven_Img_Bg.set_angle(0)
ui_Oven_Img_Bg.set_pos(0, 0)
ui_Oven_Img_Bg.set_size(1280, 720)
ui_Oven_Img_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Bg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Bg.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Door
ui_Oven_Img_Door = lv.img(ui_Oven)
ui_Oven_Img_Door.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\oven_light_704_720.png"))
ui_Oven_Img_Door.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Door.set_pivot(50,50)
ui_Oven_Img_Door.set_angle(0)
ui_Oven_Img_Door.set_pos(5, -1)
ui_Oven_Img_Door.set_size(704, 720)
ui_Oven_Img_Door.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Door, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Door.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Fan
ui_Oven_Img_Fan = lv.img(ui_Oven)
ui_Oven_Img_Fan.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\oven_fan_light_1_120_119.png"))
ui_Oven_Img_Fan.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Fan.set_pivot(50,50)
ui_Oven_Img_Fan.set_angle(0)
ui_Oven_Img_Fan.set_pos(364, 344)
ui_Oven_Img_Fan.set_size(120, 119)
ui_Oven_Img_Fan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Fan.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Label_Bg
ui_Oven_Img_Label_Bg = lv.img(ui_Oven)
ui_Oven_Img_Label_Bg.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\title_bg_654_130.png"))
ui_Oven_Img_Label_Bg.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Label_Bg.set_pivot(50,50)
ui_Oven_Img_Label_Bg.set_angle(0)
ui_Oven_Img_Label_Bg.set_pos(0, 590)
ui_Oven_Img_Label_Bg.set_size(654, 130)
ui_Oven_Img_Label_Bg.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Label_Bg, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Label_Bg.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Oven
ui_Oven_Label_Oven = lv.label(ui_Oven)
ui_Oven_Label_Oven.set_text("Oven")
ui_Oven_Label_Oven.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Oven.set_pos(541, 639)
ui_Oven_Label_Oven.set_size(100, 32)
ui_Oven_Label_Oven.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Oven, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Oven.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_text_font(test_font("Antonio_Regular", 22), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Oven.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Group_Oven
ui_Oven_Group_Oven = lv.obj(ui_Oven)
ui_Oven_Group_Oven.set_pos(677, 17)
ui_Oven_Group_Oven.set_size(534, 686)
ui_Oven_Group_Oven.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Group_Oven, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Group_Oven.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_border_color(lv.color_hex(0x4A484A), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_radius(20, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Oven.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Oven_line
ui_Oven_line = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_line_points = [{"x":0, "y":0},{"x":519, "y":0},]
ui_Oven_line.set_points(ui_Oven_line_line_points, 2)
ui_Oven_line.set_pos(7, 7)
ui_Oven_line.set_size(530, 24)
ui_Oven_line.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_line, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_line.set_style_line_width(17, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line.set_style_line_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_CurrTemp
ui_Oven_Label_CurrTemp = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_CurrTemp.set_text("CURRENT TEMP.")
ui_Oven_Label_CurrTemp.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_CurrTemp.set_pos(34, 49)
ui_Oven_Label_CurrTemp.set_size(203, 32)
ui_Oven_Label_CurrTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_CurrTemp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_CurrTemp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrTemp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_line_5
ui_Oven_line_5 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_5_line_points = [{"x":0, "y":0},{"x":485, "y":0},]
ui_Oven_line_5.set_points(ui_Oven_line_5_line_points, 2)
ui_Oven_line_5.set_pos(23, 234)
ui_Oven_line_5.set_size(495, 13)
ui_Oven_line_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_line_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_line_5.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_5.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_5.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_line_4
ui_Oven_line_4 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_4_line_points = [{"x":0, "y":0},{"x":485, "y":0},]
ui_Oven_line_4.set_points(ui_Oven_line_4_line_points, 2)
ui_Oven_line_4.set_pos(23, 379)
ui_Oven_line_4.set_size(495, 13)
ui_Oven_line_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_line_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_line_4.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_4.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_4.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_line_3
ui_Oven_line_3 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_3_line_points = [{"x":0, "y":0},{"x":235, "y":0},]
ui_Oven_line_3.set_points(ui_Oven_line_3_line_points, 2)
ui_Oven_line_3.set_pos(269, 117)
ui_Oven_line_3.set_size(240, 7)
ui_Oven_line_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_line_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_line_3.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_3.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_3.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_line_2
ui_Oven_line_2 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_2_line_points = [{"x":0, "y":0},{"x":0, "y":160},]
ui_Oven_line_2.set_points(ui_Oven_line_2_line_points, 2)
ui_Oven_line_2.set_pos(252, 52)
ui_Oven_line_2.set_size(29, 169)
ui_Oven_line_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_line_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_line_2.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_2.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_2.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_line_1
ui_Oven_line_1 = lv.line(ui_Oven_Group_Oven)
ui_Oven_line_1_line_points = [{"x":0, "y":0},{"x":0, "y":300},]
ui_Oven_line_1.set_points(ui_Oven_line_1_line_points, 2)
ui_Oven_line_1.set_pos(267, 441)
ui_Oven_line_1.set_size(17, 146)
ui_Oven_line_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_line_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_line_1.set_style_line_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_1.set_style_line_color(lv.color_hex(0x656461), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_line_1.set_style_line_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Temp
ui_Oven_Label_Temp = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Temp.set_text("250")
ui_Oven_Label_Temp.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Temp.set_pos(7, 89)
ui_Oven_Label_Temp.set_size(214, 125)
ui_Oven_Label_Temp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Temp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Temp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_text_font(test_font("Antonio_Regular", 120), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Temp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Cen
ui_Oven_Label_Cen = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Cen.set_text("ºC")
ui_Oven_Label_Cen.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Cen.set_pos(175, 88)
ui_Oven_Label_Cen.set_size(72, 53)
ui_Oven_Label_Cen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Cen, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Cen.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_text_color(lv.color_hex(0xc9c5c5), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_text_font(test_font("Alatsi_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Cen.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Status
ui_Oven_Label_Status = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Status.set_text("STATUS")
ui_Oven_Label_Status.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Status.set_pos(287, 34)
ui_Oven_Label_Status.set_size(203, 32)
ui_Oven_Label_Status.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Status, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Status.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Status.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_CurrStat
ui_Oven_Label_CurrStat = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_CurrStat.set_text("My Stat")
ui_Oven_Label_CurrStat.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_CurrStat.set_pos(329, 67)
ui_Oven_Label_CurrStat.set_size(118, 53)
ui_Oven_Label_CurrStat.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_CurrStat, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_CurrStat.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_text_color(lv.color_hex(0xc9c5c5), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_text_font(test_font("Antonio_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_CurrStat.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Time
ui_Oven_Label_Time = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Time.set_text("TIME\nLEFT")
ui_Oven_Label_Time.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Time.set_pos(236, 132)
ui_Oven_Label_Time.set_size(118, 57)
ui_Oven_Label_Time.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Time, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Time.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Time.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Bar_Time
ui_Oven_Bar_Time = lv.bar(ui_Oven_Group_Oven)
ui_Oven_Bar_Time.set_style_anim_time(1000, 0)
ui_Oven_Bar_Time.set_mode(lv.bar.MODE.NORMAL)
ui_Oven_Bar_Time.set_value(30, lv.ANIM.OFF)
ui_Oven_Bar_Time.set_pos(274, 195)
ui_Oven_Bar_Time.set_size(225, 13)
ui_Oven_Bar_Time.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Bar_Time, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Bar_Time.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Bar_Time.set_style_bg_color(lv.color_hex(0x4A4441), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Bar_Time.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Bar_Time.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for ui_Oven_Bar_Time, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
ui_Oven_Bar_Time.set_style_bg_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
ui_Oven_Bar_Time.set_style_bg_color(lv.color_hex(0xFF9110), lv.PART.INDICATOR|lv.STATE.DEFAULT)
ui_Oven_Bar_Time.set_style_radius(10, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode
ui_Oven_Label_Mode = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Mode.set_text("MODE")
ui_Oven_Label_Mode.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode.set_pos(208, 240)
ui_Oven_Label_Mode.set_size(118, 57)
ui_Oven_Label_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Btn_ModeLeft
ui_Oven_Btn_ModeLeft = lv.imgbtn(ui_Oven_Group_Oven)
ui_Oven_Btn_ModeLeft.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.RELEASED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_left_18_35.png"), None)
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.PRESSED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_left_18_35.png"), None)
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_left_18_35.png"), None)
ui_Oven_Btn_ModeLeft.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_left_18_35.png"), None)
ui_Oven_Btn_ModeLeft.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Oven_Btn_ModeLeft_label = lv.label(ui_Oven_Btn_ModeLeft)
ui_Oven_Btn_ModeLeft_label.set_text("")
ui_Oven_Btn_ModeLeft_label.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Btn_ModeLeft_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Oven_Btn_ModeLeft.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Oven_Btn_ModeLeft.set_pos(27, 291)
ui_Oven_Btn_ModeLeft.set_size(18, 35)
ui_Oven_Btn_ModeLeft.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Btn_ModeLeft, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Btn_ModeLeft.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeLeft.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeLeft.set_style_text_font(test_font("simsun", 12), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeLeft.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeLeft.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for ui_Oven_Btn_ModeLeft, Part: lv.PART.MAIN, State: lv.STATE.PRESSED.
ui_Oven_Btn_ModeLeft.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.PRESSED)
ui_Oven_Btn_ModeLeft.set_style_text_color(lv.color_hex(0xFF33FF), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Oven_Btn_ModeLeft.set_style_text_font(test_font("simsun", 12), lv.PART.MAIN|lv.STATE.PRESSED)
ui_Oven_Btn_ModeLeft.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.PRESSED)
# Set style for ui_Oven_Btn_ModeLeft, Part: lv.PART.MAIN, State: lv.STATE.CHECKED.
ui_Oven_Btn_ModeLeft.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_ModeLeft.set_style_text_color(lv.color_hex(0xFF33FF), lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_ModeLeft.set_style_text_font(test_font("simsun", 12), lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_ModeLeft.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.CHECKED)

# Create ui_Oven_Btn_ModeRigth
ui_Oven_Btn_ModeRigth = lv.imgbtn(ui_Oven_Group_Oven)
ui_Oven_Btn_ModeRigth.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.RELEASED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_right_18_35.png"), None)
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.PRESSED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_right_18_35.png"), None)
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_right_18_35.png"), None)
ui_Oven_Btn_ModeRigth.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\arrow_right_18_35.png"), None)
ui_Oven_Btn_ModeRigth.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Oven_Btn_ModeRigth_label = lv.label(ui_Oven_Btn_ModeRigth)
ui_Oven_Btn_ModeRigth_label.set_text("")
ui_Oven_Btn_ModeRigth_label.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Btn_ModeRigth_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Oven_Btn_ModeRigth.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Oven_Btn_ModeRigth.set_pos(486, 291)
ui_Oven_Btn_ModeRigth.set_size(18, 35)
ui_Oven_Btn_ModeRigth.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Btn_ModeRigth, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Btn_ModeRigth.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeRigth.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeRigth.set_style_text_font(test_font("simsun", 12), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeRigth.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_ModeRigth.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Btn_State
ui_Oven_Btn_State = lv.imgbtn(ui_Oven_Group_Oven)
ui_Oven_Btn_State.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.RELEASED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\BTN_oven_134_51.png"), None)
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.PRESSED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\BTN_oven_134_51.png"), None)
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\BTN_oven_134_51.png"), None)
ui_Oven_Btn_State.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\BTN_oven_134_51.png"), None)
ui_Oven_Btn_State.add_flag(lv.obj.FLAG.CHECKABLE)
ui_Oven_Btn_State_label = lv.label(ui_Oven_Btn_State)
ui_Oven_Btn_State_label.set_text("START")
ui_Oven_Btn_State_label.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Btn_State_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Oven_Btn_State.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Oven_Btn_State.set_pos(203, 607)
ui_Oven_Btn_State.set_size(134, 51)
ui_Oven_Btn_State.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Btn_State, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Btn_State.set_style_img_recolor_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_State.set_style_img_recolor(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_State.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_State.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_State.set_style_text_font(test_font("Antonio_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_State.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Btn_State.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for ui_Oven_Btn_State, Part: lv.PART.MAIN, State: lv.STATE.CHECKED.
ui_Oven_Btn_State.set_style_img_recolor_opa(255, lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_State.set_style_img_recolor(lv.color_hex(0x35C915), lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_State.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_State.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_State.set_style_text_font(test_font("Antonio_Regular", 26), lv.PART.MAIN|lv.STATE.CHECKED)
ui_Oven_Btn_State.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.CHECKED)

# Create ui_Oven_Label_Settings
ui_Oven_Label_Settings = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Settings.set_text("SETTINGS")
ui_Oven_Label_Settings.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Settings.set_pos(206, 395)
ui_Oven_Label_Settings.set_size(118, 46)
ui_Oven_Label_Settings.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Settings, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Settings.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Settings.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_TimeLeft
ui_Oven_Label_TimeLeft = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_TimeLeft.set_text("15")
ui_Oven_Label_TimeLeft.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_TimeLeft.set_pos(319, 130)
ui_Oven_Label_TimeLeft.set_size(109, 51)
ui_Oven_Label_TimeLeft.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_TimeLeft, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_TimeLeft.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_text_font(test_font("Antonio_Regular", 40), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimeLeft.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Min
ui_Oven_Label_Min = lv.label(ui_Oven_Group_Oven)
ui_Oven_Label_Min.set_text("mins")
ui_Oven_Label_Min.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Min.set_pos(393, 146)
ui_Oven_Label_Min.set_size(63, 32)
ui_Oven_Label_Min.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Min, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Min.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_text_color(lv.color_hex(0xc9c5c5), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_text_font(test_font("Alatsi_Regular", 23), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Min.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Tile_Mode
ui_Oven_Tile_Mode = lv.tileview(ui_Oven)
ui_Oven_Tile_Mode_Mode_1 = ui_Oven_Tile_Mode.add_tile(0, 0, lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_2 = ui_Oven_Tile_Mode.add_tile(1, 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_3 = ui_Oven_Tile_Mode.add_tile(2, 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_4 = ui_Oven_Tile_Mode.add_tile(3, 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_5 = ui_Oven_Tile_Mode.add_tile(4, 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_6 = ui_Oven_Tile_Mode.add_tile(5, 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_7 = ui_Oven_Tile_Mode.add_tile(6, 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_8 = ui_Oven_Tile_Mode.add_tile(7, 0, lv.DIR.LEFT | lv.DIR.RIGHT)
ui_Oven_Tile_Mode_Mode_9 = ui_Oven_Tile_Mode.add_tile(8, 0, lv.DIR.LEFT)
ui_Oven_Tile_Mode.set_pos(728, 294)
ui_Oven_Tile_Mode.set_size(430, 86)
ui_Oven_Tile_Mode.set_scrollbar_mode(lv.SCROLLBAR_MODE.ON)
# Set style for ui_Oven_Tile_Mode, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Tile_Mode.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Tile_Mode.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Tile_Mode.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for ui_Oven_Tile_Mode, Part: lv.PART.SCROLLBAR, State: lv.STATE.DEFAULT.
ui_Oven_Tile_Mode.set_style_bg_opa(0, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)
ui_Oven_Tile_Mode.set_style_radius(0, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode1
ui_Oven_Img_Mode1 = lv.img(ui_Oven_Tile_Mode_Mode_1)
ui_Oven_Img_Mode1.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_fan_rear_62_62.png"))
ui_Oven_Img_Mode1.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode1.set_pivot(50,50)
ui_Oven_Img_Mode1.set_angle(0)
ui_Oven_Img_Mode1.set_pos(134, 12)
ui_Oven_Img_Mode1.set_size(62, 62)
ui_Oven_Img_Mode1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode1.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode1
ui_Oven_Label_Mode1 = lv.label(ui_Oven_Tile_Mode_Mode_1)
ui_Oven_Label_Mode1.set_text("Fan Forced\nRear Element")
ui_Oven_Label_Mode1.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode1.set_pos(211, 17)
ui_Oven_Label_Mode1.set_size(141, 52)
ui_Oven_Label_Mode1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode2
ui_Oven_Img_Mode2 = lv.img(ui_Oven_Tile_Mode_Mode_2)
ui_Oven_Img_Mode2.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_upper_lower_62_62.png"))
ui_Oven_Img_Mode2.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode2.set_pivot(50,50)
ui_Oven_Img_Mode2.set_angle(0)
ui_Oven_Img_Mode2.set_pos(134, 12)
ui_Oven_Img_Mode2.set_size(62, 62)
ui_Oven_Img_Mode2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode2.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode2
ui_Oven_Label_Mode2 = lv.label(ui_Oven_Tile_Mode_Mode_2)
ui_Oven_Label_Mode2.set_text("Upper & Lower\nElements\nConvection")
ui_Oven_Label_Mode2.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode2.set_pos(211, 7)
ui_Oven_Label_Mode2.set_size(141, 66)
ui_Oven_Label_Mode2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode3
ui_Oven_Label_Mode3 = lv.label(ui_Oven_Tile_Mode_Mode_3)
ui_Oven_Label_Mode3.set_text("Fan Forced\nUpper & Lower\nConvection")
ui_Oven_Label_Mode3.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode3.set_pos(211, 7)
ui_Oven_Label_Mode3.set_size(141, 66)
ui_Oven_Label_Mode3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode3
ui_Oven_Img_Mode3 = lv.img(ui_Oven_Tile_Mode_Mode_3)
ui_Oven_Img_Mode3.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_fan_upper_lower_62_62.png"))
ui_Oven_Img_Mode3.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode3.set_pivot(50,50)
ui_Oven_Img_Mode3.set_angle(0)
ui_Oven_Img_Mode3.set_pos(134, 12)
ui_Oven_Img_Mode3.set_size(62, 62)
ui_Oven_Img_Mode3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode3.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode4
ui_Oven_Img_Mode4 = lv.img(ui_Oven_Tile_Mode_Mode_4)
ui_Oven_Img_Mode4.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_fan_lower_62_62.png"))
ui_Oven_Img_Mode4.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode4.set_pivot(50,50)
ui_Oven_Img_Mode4.set_angle(0)
ui_Oven_Img_Mode4.set_pos(134, 12)
ui_Oven_Img_Mode4.set_size(62, 62)
ui_Oven_Img_Mode4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode4.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode4
ui_Oven_Label_Mode4 = lv.label(ui_Oven_Tile_Mode_Mode_4)
ui_Oven_Label_Mode4.set_text("Fan Forced\nLower Element\nConvection")
ui_Oven_Label_Mode4.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode4.set_pos(211, 7)
ui_Oven_Label_Mode4.set_size(141, 66)
ui_Oven_Label_Mode4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode4.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode4.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode5
ui_Oven_Img_Mode5 = lv.img(ui_Oven_Tile_Mode_Mode_5)
ui_Oven_Img_Mode5.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_gril_62_62.png"))
ui_Oven_Img_Mode5.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode5.set_pivot(50,50)
ui_Oven_Img_Mode5.set_angle(0)
ui_Oven_Img_Mode5.set_pos(134, 12)
ui_Oven_Img_Mode5.set_size(62, 62)
ui_Oven_Img_Mode5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode5.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode5
ui_Oven_Label_Mode5 = lv.label(ui_Oven_Tile_Mode_Mode_5)
ui_Oven_Label_Mode5.set_text("Grill")
ui_Oven_Label_Mode5.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode5.set_pos(220, 22)
ui_Oven_Label_Mode5.set_size(141, 34)
ui_Oven_Label_Mode5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode5.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode5.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode6
ui_Oven_Img_Mode6 = lv.img(ui_Oven_Tile_Mode_Mode_6)
ui_Oven_Img_Mode6.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_fan_gril_62_62.png"))
ui_Oven_Img_Mode6.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode6.set_pivot(50,50)
ui_Oven_Img_Mode6.set_angle(0)
ui_Oven_Img_Mode6.set_pos(134, 12)
ui_Oven_Img_Mode6.set_size(62, 62)
ui_Oven_Img_Mode6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode6.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode6
ui_Oven_Label_Mode6 = lv.label(ui_Oven_Tile_Mode_Mode_6)
ui_Oven_Label_Mode6.set_text("Fan Forced\nGrill")
ui_Oven_Label_Mode6.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode6.set_pos(211, 17)
ui_Oven_Label_Mode6.set_size(141, 52)
ui_Oven_Label_Mode6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode6.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode6.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode7
ui_Oven_Img_Mode7 = lv.img(ui_Oven_Tile_Mode_Mode_7)
ui_Oven_Img_Mode7.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_upper_62_62.png"))
ui_Oven_Img_Mode7.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode7.set_pivot(50,50)
ui_Oven_Img_Mode7.set_angle(0)
ui_Oven_Img_Mode7.set_pos(134, 12)
ui_Oven_Img_Mode7.set_size(62, 62)
ui_Oven_Img_Mode7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode7.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode7
ui_Oven_Label_Mode7 = lv.label(ui_Oven_Tile_Mode_Mode_7)
ui_Oven_Label_Mode7.set_text("Upper Outer\nElement")
ui_Oven_Label_Mode7.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode7.set_pos(211, 17)
ui_Oven_Label_Mode7.set_size(141, 52)
ui_Oven_Label_Mode7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode7.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode7.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode8
ui_Oven_Img_Mode8 = lv.img(ui_Oven_Tile_Mode_Mode_8)
ui_Oven_Img_Mode8.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_lower_62_62.png"))
ui_Oven_Img_Mode8.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode8.set_pivot(50,50)
ui_Oven_Img_Mode8.set_angle(0)
ui_Oven_Img_Mode8.set_pos(134, 12)
ui_Oven_Img_Mode8.set_size(62, 62)
ui_Oven_Img_Mode8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode8.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode8
ui_Oven_Label_Mode8 = lv.label(ui_Oven_Tile_Mode_Mode_8)
ui_Oven_Label_Mode8.set_text("Lower Outer\nElement")
ui_Oven_Label_Mode8.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode8.set_pos(211, 17)
ui_Oven_Label_Mode8.set_size(141, 52)
ui_Oven_Label_Mode8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode8.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode8.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Img_Mode9
ui_Oven_Img_Mode9 = lv.img(ui_Oven_Tile_Mode_Mode_9)
ui_Oven_Img_Mode9.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\icn_oven_defrost_62_62.png"))
ui_Oven_Img_Mode9.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_Mode9.set_pivot(50,50)
ui_Oven_Img_Mode9.set_angle(0)
ui_Oven_Img_Mode9.set_pos(134, 12)
ui_Oven_Img_Mode9.set_size(62, 62)
ui_Oven_Img_Mode9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_Mode9, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_Mode9.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_Mode9
ui_Oven_Label_Mode9 = lv.label(ui_Oven_Tile_Mode_Mode_9)
ui_Oven_Label_Mode9.set_text("Defrost")
ui_Oven_Label_Mode9.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_Mode9.set_pos(220, 22)
ui_Oven_Label_Mode9.set_size(141, 34)
ui_Oven_Label_Mode9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_Mode9, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_Mode9.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_text_font(test_font("Antonio_Regular", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_Mode9.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Group_TarTemp
ui_Oven_Group_TarTemp = lv.obj(ui_Oven)
ui_Oven_Group_TarTemp.set_pos(697, 427)
ui_Oven_Group_TarTemp.set_size(235, 240)
ui_Oven_Group_TarTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Group_TarTemp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Group_TarTemp.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_TarTemp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Oven_Img_TempWheel
ui_Oven_Img_TempWheel = lv.img(ui_Oven_Group_TarTemp)
ui_Oven_Img_TempWheel.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\wheel_bg_151_259.png"))
ui_Oven_Img_TempWheel.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_TempWheel.set_pivot(50,50)
ui_Oven_Img_TempWheel.set_angle(0)
ui_Oven_Img_TempWheel.set_pos(51, -11)
ui_Oven_Img_TempWheel.set_size(151, 259)
ui_Oven_Img_TempWheel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_TempWheel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_TempWheel.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_SelTemp
ui_Oven_Label_SelTemp = lv.label(ui_Oven_Group_TarTemp)
ui_Oven_Label_SelTemp.set_text("TARGET\nTEMP.")
ui_Oven_Label_SelTemp.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_SelTemp.set_pos(-11, 91)
ui_Oven_Label_SelTemp.set_size(118, 53)
ui_Oven_Label_SelTemp.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_SelTemp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_SelTemp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTemp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_TarCen
ui_Oven_Label_TarCen = lv.label(ui_Oven_Group_TarTemp)
ui_Oven_Label_TarCen.set_text("ºC")
ui_Oven_Label_TarCen.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_TarCen.set_pos(68, 111)
ui_Oven_Label_TarCen.set_size(55, 32)
ui_Oven_Label_TarCen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_TarCen, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_TarCen.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_text_color(lv.color_hex(0xc9c5c5), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_text_font(test_font("Alatsi_Regular", 23), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TarCen.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Group_Timer
ui_Oven_Group_Timer = lv.obj(ui_Oven)
ui_Oven_Group_Timer.set_pos(957, 427)
ui_Oven_Group_Timer.set_size(235, 240)
ui_Oven_Group_Timer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Group_Timer, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Group_Timer.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Group_Timer.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create ui_Oven_Img_TimerWheel
ui_Oven_Img_TimerWheel = lv.img(ui_Oven_Group_Timer)
ui_Oven_Img_TimerWheel.set_src(load_image(r"C:\Users\nxf93737\Documents\repos\full_appliance_1170\rt1170-graphics-voice-ui\AirconGUI\generated\MicroPython\wheel_bg_2_151_259.png"))
ui_Oven_Img_TimerWheel.add_flag(lv.obj.FLAG.CLICKABLE)
ui_Oven_Img_TimerWheel.set_pivot(50,50)
ui_Oven_Img_TimerWheel.set_angle(0)
ui_Oven_Img_TimerWheel.set_pos(39, -11)
ui_Oven_Img_TimerWheel.set_size(151, 259)
ui_Oven_Img_TimerWheel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Img_TimerWheel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Img_TimerWheel.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_SelTimer
ui_Oven_Label_SelTimer = lv.label(ui_Oven_Group_Timer)
ui_Oven_Label_SelTimer.set_text("SETUP\nTIMER")
ui_Oven_Label_SelTimer.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_SelTimer.set_pos(148, 91)
ui_Oven_Label_SelTimer.set_size(104, 53)
ui_Oven_Label_SelTimer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_SelTimer, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_SelTimer.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_text_color(lv.color_hex(0xFF9110), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_text_font(test_font("Antonio_Regular", 21), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_SelTimer.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_Label_TimerSel
ui_Oven_Label_TimerSel = lv.label(ui_Oven_Group_Timer)
ui_Oven_Label_TimerSel.set_text("mins")
ui_Oven_Label_TimerSel.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_Label_TimerSel.set_pos(114, 108)
ui_Oven_Label_TimerSel.set_size(63, 32)
ui_Oven_Label_TimerSel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_Label_TimerSel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_Label_TimerSel.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_text_color(lv.color_hex(0xc9c5c5), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_text_font(test_font("Alatsi_Regular", 23), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_Label_TimerSel.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create ui_Oven_ui_Btn_Back3
ui_Oven_ui_Btn_Back3 = lv.btn(ui_Oven)
ui_Oven_ui_Btn_Back3_label = lv.label(ui_Oven_ui_Btn_Back3)
ui_Oven_ui_Btn_Back3_label.set_text("BACK")
ui_Oven_ui_Btn_Back3_label.set_long_mode(lv.label.LONG.WRAP)
ui_Oven_ui_Btn_Back3_label.align(lv.ALIGN.CENTER, 0, 0)
ui_Oven_ui_Btn_Back3.set_style_pad_all(0, lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_pos(-41, 24)
ui_Oven_ui_Btn_Back3.set_size(155, 65)
ui_Oven_ui_Btn_Back3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for ui_Oven_ui_Btn_Back3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
ui_Oven_ui_Btn_Back3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_style_bg_color(lv.color_hex(0x181818), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_style_radius(65, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
ui_Oven_ui_Btn_Back3.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

ui_Oven.update_layout()

def ui_Home_ui_Btn_Hood_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.RELEASED):
        lv.scr_load_anim(ui_Hood, lv.SCR_LOAD_ANIM.NONE, 0, 0, False)

ui_Home_ui_Btn_Hood.add_event_cb(lambda e: ui_Home_ui_Btn_Hood_event_handler(e), lv.EVENT.ALL, None)

def ui_Home_ui_Btn_Aircon_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.RELEASED):
        lv.scr_load_anim(ui_Aircon, lv.SCR_LOAD_ANIM.NONE, 0, 0, False)

ui_Home_ui_Btn_Aircon.add_event_cb(lambda e: ui_Home_ui_Btn_Aircon_event_handler(e), lv.EVENT.ALL, None)

def ui_Home_ui_Btn_Oven_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.RELEASED):
        lv.scr_load_anim(ui_Oven, lv.SCR_LOAD_ANIM.NONE, 0, 0, False)

ui_Home_ui_Btn_Oven.add_event_cb(lambda e: ui_Home_ui_Btn_Oven_event_handler(e), lv.EVENT.ALL, None)

def ui_Hood_ui_Slider_Hood_Fan_event_handler(e):
    code = e.get_code()

ui_Hood_ui_Slider_Hood_Fan.add_event_cb(lambda e: ui_Hood_ui_Slider_Hood_Fan_event_handler(e), lv.EVENT.ALL, None)

def ui_Hood_sw_1_event_handler(e):
    code = e.get_code()

ui_Hood_sw_1.add_event_cb(lambda e: ui_Hood_sw_1_event_handler(e), lv.EVENT.ALL, None)

def ui_Hood_ui_Btn_Back1_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.RELEASED):
        lv.scr_load_anim(ui_Home, lv.SCR_LOAD_ANIM.NONE, 0, 0, False)

ui_Hood_ui_Btn_Back1.add_event_cb(lambda e: ui_Hood_ui_Btn_Back1_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_Btn_TempUp_event_handler(e):
    code = e.get_code()

ui_Aircon_Btn_TempUp.add_event_cb(lambda e: ui_Aircon_Btn_TempUp_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_Btn_TempDown_event_handler(e):
    code = e.get_code()

ui_Aircon_Btn_TempDown.add_event_cb(lambda e: ui_Aircon_Btn_TempDown_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_Roller_Mode_event_handler(e):
    code = e.get_code()

ui_Aircon_Roller_Mode.add_event_cb(lambda e: ui_Aircon_Roller_Mode_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_Btn_Swing_event_handler(e):
    code = e.get_code()

ui_Aircon_Btn_Swing.add_event_cb(lambda e: ui_Aircon_Btn_Swing_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_Slider_Fan_event_handler(e):
    code = e.get_code()

ui_Aircon_Slider_Fan.add_event_cb(lambda e: ui_Aircon_Slider_Fan_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_Btn_TimerUp_event_handler(e):
    code = e.get_code()

ui_Aircon_Btn_TimerUp.add_event_cb(lambda e: ui_Aircon_Btn_TimerUp_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_Btn_TimerDown_event_handler(e):
    code = e.get_code()

ui_Aircon_Btn_TimerDown.add_event_cb(lambda e: ui_Aircon_Btn_TimerDown_event_handler(e), lv.EVENT.ALL, None)

def ui_Aircon_ui_Btn_Back2_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.RELEASED):
        lv.scr_load_anim(ui_Home, lv.SCR_LOAD_ANIM.NONE, 0, 0, False)

ui_Aircon_ui_Btn_Back2.add_event_cb(lambda e: ui_Aircon_ui_Btn_Back2_event_handler(e), lv.EVENT.ALL, None)

def ui_Oven_Btn_ModeLeft_event_handler(e):
    code = e.get_code()

ui_Oven_Btn_ModeLeft.add_event_cb(lambda e: ui_Oven_Btn_ModeLeft_event_handler(e), lv.EVENT.ALL, None)

def ui_Oven_Btn_ModeRigth_event_handler(e):
    code = e.get_code()

ui_Oven_Btn_ModeRigth.add_event_cb(lambda e: ui_Oven_Btn_ModeRigth_event_handler(e), lv.EVENT.ALL, None)

def ui_Oven_Btn_State_event_handler(e):
    code = e.get_code()

ui_Oven_Btn_State.add_event_cb(lambda e: ui_Oven_Btn_State_event_handler(e), lv.EVENT.ALL, None)

def ui_Oven_ui_Btn_Back3_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.RELEASED):
        lv.scr_load_anim(ui_Home, lv.SCR_LOAD_ANIM.NONE, 0, 0, False)

ui_Oven_ui_Btn_Back3.add_event_cb(lambda e: ui_Oven_ui_Btn_Back3_event_handler(e), lv.EVENT.ALL, None)

# content from custom.py

# Load the default screen
lv.scr_load(ui_Home)

while SDL.check():
    time.sleep_ms(5)

