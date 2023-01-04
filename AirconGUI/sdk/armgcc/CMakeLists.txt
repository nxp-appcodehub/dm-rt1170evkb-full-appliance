# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/build)
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(lvgl_guider_cm7)

set(MCUX_BUILD_TYPES flexspi_nor_sdram_debug flexspi_nor_sdram_release)

set(MCUX_SDK_PROJECT_NAME lvgl_guider_cm7.elf)

if (NOT DEFINED SdkRootDirPath)
SET(SdkRootDirPath ${ProjDirPath}/../../../../../..)
endif()

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

option(USE_LOTTIE_WIDGET "Enable the lottie widget" OFF)

file(GLOB SOURCES
${ProjDirPath}/../../custom/*.c
${ProjDirPath}/../../custom/*.h
${ProjDirPath}/../../generated/*.c
${ProjDirPath}/../../generated/*.h
${ProjDirPath}/../../generated/images/*.c
${ProjDirPath}/../../generated/images/*.h
${ProjDirPath}/../../generated/guider_fonts/*.c
${ProjDirPath}/../../generated/guider_fonts/*.h
${ProjDirPath}/../../generated/guider_customer_fonts/*.c
${ProjDirPath}/../../generated/guider_customer_fonts/*.h
)

add_executable(${MCUX_SDK_PROJECT_NAME}
"${ProjDirPath}/../Core/board/board.c"
"${ProjDirPath}/../Core/board/board.h"
"${ProjDirPath}/../Core/board/clock_config.c"
"${ProjDirPath}/../Core/board/clock_config.h"
"${ProjDirPath}/../Core/board/dcd.c"
"${ProjDirPath}/../Core/board/dcd.h"
"${ProjDirPath}/../Core/board/display_support.c"
"${ProjDirPath}/../Core/board/display_support.h"
"${ProjDirPath}/../Core/board/lvgl_support.c"
"${ProjDirPath}/../Core/board/lvgl_support.h"
"${ProjDirPath}/../Core/board/pin_mux.c"
"${ProjDirPath}/../Core/board/pin_mux.h"
"${ProjDirPath}/../Core/board/vglite_support.c"
"${ProjDirPath}/../Core/board/vglite_support.h"
"${ProjDirPath}/../Core/source/FreeRTOSConfig.h"
"${ProjDirPath}/../Core/source/h264_dec.cpp"
"${ProjDirPath}/../Core/source/h264_dec.h"
"${ProjDirPath}/../Core/source/lv_conf.h"
"${ProjDirPath}/../Core/source/lvgl_demo_utils.c"
"${ProjDirPath}/../Core/source/lvgl_demo_utils.h"
"${ProjDirPath}/../Core/source/lvgl_freertos.c"
"${ProjDirPath}/../Core/source/lvgl_freertos.h"
"${ProjDirPath}/../Core/source/lvgl_guider.c"
${SOURCES}
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
${ProjDirPath}/../Core/board
${ProjDirPath}/../Core/source
${ProjDirPath}/../../generated
${ProjDirPath}/../../custom
${ProjDirPath}/../../generated/guider_customer_fonts
${ProjDirPath}/../../generated/guider_fonts
)

set(CMAKE_MODULE_PATH
${ProjDirPath}/
${ProjDirPath}/../Core/CMSIS
${ProjDirPath}/../Core/board
${ProjDirPath}/../Core/component/lists
${ProjDirPath}/../Core/component/serial_manager
${ProjDirPath}/../Core/component/uart
${ProjDirPath}/../Core/device
${ProjDirPath}/../Core/drivers
${ProjDirPath}/../Core/freertos/freertos-kernel
${ProjDirPath}/../Core/lvgl
${ProjDirPath}/../Core/rlottie
${ProjDirPath}/startup
${ProjDirPath}/../Core/touchpanel
${ProjDirPath}/../Core/utilities
${ProjDirPath}/../Core/vglite
${ProjDirPath}/../Core/video
${ProjDirPath}/../Core/xip
)

# include modules
include(driver_video-common_MIMXRT1176_cm7)

include(driver_display-common_MIMXRT1176_cm7)

include(driver_display-rm68191_MIMXRT1176_cm7)

include(driver_mipi_dsi_split_MIMXRT1176_cm7)

include(driver_display-mipi-dsi-cmd_MIMXRT1176_cm7)

include(driver_common_MIMXRT1176_cm7)

include(driver_display-rm68200_MIMXRT1176_cm7)

include(driver_dc-fb-lcdifv2_MIMXRT1176_cm7)

include(driver_gt911_MIMXRT1176_cm7)

include(driver_lpi2c_MIMXRT1176_cm7)

include(driver_soc_src_MIMXRT1176_cm7)

include(driver_cache_armv7_m7_MIMXRT1176_cm7)

include(driver_pxp_MIMXRT1176_cm7)

include(driver_elcdif_MIMXRT1176_cm7)

include(driver_dc-fb-elcdif_MIMXRT1176_cm7)

include(middleware_vglite_MIMXRT1176_cm7)

include(driver_display-hx8394_MIMXRT1176_cm7)

include(middleware_freertos-kernel_heap_4_MIMXRT1176_cm7)

include(driver_clock_MIMXRT1176_cm7)

include(middleware_lvgl_MIMXRT1176_cm7)

include(device_MIMXRT1176_CMSIS_MIMXRT1176_cm7)

include(utility_debug_console_MIMXRT1176_cm7)

include(component_lpuart_adapter_MIMXRT1176_cm7)

include(component_serial_manager_MIMXRT1176_cm7)

include(component_lists_MIMXRT1176_cm7)

include(component_serial_manager_uart_MIMXRT1176_cm7)

include(driver_lpuart_MIMXRT1176_cm7)

include(device_MIMXRT1176_startup_MIMXRT1176_cm7)

include(driver_iomuxc_MIMXRT1176_cm7)

include(utility_assert_MIMXRT1176_cm7)

include(driver_igpio_MIMXRT1176_cm7)

include(driver_xip_device_MIMXRT1176_cm7)

include(driver_xip_board_evkmimxrt1170_MIMXRT1176_cm7)

include(driver_pmu_1_MIMXRT1176_cm7)

include(driver_dcdc_soc_MIMXRT1176_cm7)

include(driver_xmcd_evkmimxrt1170_MIMXRT1176_cm7)

include(driver_anatop_ai_MIMXRT1176_cm7)

include(CMSIS_Include_core_cm_MIMXRT1176_cm7)

include(driver_soc_mipi_csi2rx_MIMXRT1176_cm7)

include(driver_dc-fb-common_MIMXRT1176_cm7)

include(driver_lcdifv2_MIMXRT1176_cm7)

include(driver_memory_MIMXRT1176_cm7)

include(middleware_freertos-kernel_MIMXRT1176_cm7)

include(middleware_freertos-kernel_extension_MIMXRT1176_cm7)

include(utilities_misc_utilities_MIMXRT1176_cm7)

include(device_MIMXRT1176_system_MIMXRT1176_cm7)

include(middleware_rlottie_MIMXRT1176_cm7)

IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)
SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")
ENDIF()

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

if(USE_LOTTIE_WIDGET)
target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${ProjDirPath}/../../lib/arm/gcc/librlottie.a)
endif()

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


