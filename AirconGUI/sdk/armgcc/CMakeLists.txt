# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (MCUXPRESSO_CMAKE_FORMAT_MAJOR_VERSION 2)
SET (MCUXPRESSO_CMAKE_FORMAT_MINOR_VERSION 0)

if(CMAKE_SCRIPT_MODE_FILE)
message("${MCUXPRESSO_CMAKE_FORMAT_MAJOR_VERSION}")
return()
endif()


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
SET(SdkRootDirPath ${ProjDirPath}/)
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

set_source_files_properties("${ProjDirPath}/../Core/source/lv_conf.h" PROPERTIES COMPONENT_CONFIG_FILE "middleware_lvgl_template")
set_source_files_properties("${ProjDirPath}/../Core/board/lvgl_support.h" PROPERTIES COMPONENT_CONFIG_FILE "middleware_lvgl_template")
set_source_files_properties("${ProjDirPath}/../Core/board/lvgl_support.c" PROPERTIES COMPONENT_CONFIG_FILE "middleware_lvgl_template")
set_source_files_properties("${ProjDirPath}/../Core/source/FreeRTOSConfig.h" PROPERTIES COMPONENT_CONFIG_FILE "middleware_freertos-kernel_template")

include(${ProjDirPath}/all_lib_device.cmake)

IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)
SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")
ENDIF()

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

if(USE_LOTTIE_WIDGET)
target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${ProjDirPath}/../../lib/arm/gcc/librlottie.a)
endif()

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


