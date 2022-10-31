/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

#include "vit_proc.h"
#include "fsl_soc_src.h"
#include "ui_Aircon.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;

/*
 * AUDIO PLL setting: Frequency = Fref * (DIV_SELECT + NUM / DENOM) / (2^POST)
 *                              = 24 * (32 + 77/100)  / 2
 *                              = 393.24MHZ
 */
const clock_audio_pll_config_t audioPllConfig = {
		.loopDivider = 32,  /* PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
		.postDivider = 1,   /* Divider after the PLL, should only be 0, 1, 2, 3, 4, 5 */
		.numerator   = 77,  /* 30 bit numerator of fractional loop divider. */
		.denominator = 100, /* 30 bit denominator of fractional loop divider */
};

EventGroupHandle_t GPH_Process = NULL;
extern PL_UINT16 cmd_id;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/


#if LV_USE_LOG
static void print_cb(const char *buf)
{
	PRINTF("\r%s\n", buf);
}
#endif

static void Graphics_Process (void *pvParameters)
{

	EventBits_t event_bits;

	for(;;)
	{
		event_bits = xEventGroupWaitBits(GPH_Process,  VIT_CMD_DETECT, pdTRUE, pdFALSE, portMAX_DELAY);

		if((event_bits & VIT_CMD_DETECT) == VIT_CMD_DETECT)
		{
			ui_aircon_process_command(cmd_id);
		}
	}
}
static void AppTask(void *param)
{
#if LV_USE_LOG
	lv_log_register_print_cb(print_cb);
#endif

	lv_port_pre_init();
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	s_lvgl_initialized = true;

	setup_ui(&guider_ui);
	events_init(&guider_ui);
	custom_init(&guider_ui);

	for (;;)
	{
		lv_task_handler();
	}
}

/*******************************************************************************
 * Code
 ******************************************************************************/

/* The function sets the cacheable memory to shareable, this suggestion is referred from chapter 2.2.1 Memory regions,
 * types and attributes in Cortex-M7 Devices, Generic User Guide */
void BOARD_ConfigUSBMPU()
{
	/* Disable I cache and D cache */
	SCB_DisableICache();
	SCB_DisableDCache();

	/* Disable MPU */
	ARM_MPU_Disable();
	/* MPU configure:
	 * Use ARM_MPU_RASR(DisableExec, AccessPermission, TypeExtField, IsShareable, IsCacheable, IsBufferable,
	 * SubRegionDisable, Size) API in core_cm7.h. param DisableExec       Instruction access (XN) disable
	 * bit,0=instruction fetches enabled, 1=instruction fetches disabled. param AccessPermission  Data access
	 * permissions, allows you to configure read/write access for User and Privileged mode. Use MACROS defined in
	 * core_cm7.h: ARM_MPU_AP_NONE/ARM_MPU_AP_PRIV/ARM_MPU_AP_URO/ARM_MPU_AP_FULL/ARM_MPU_AP_PRO/ARM_MPU_AP_RO Combine
	 * TypeExtField/IsShareable/IsCacheable/IsBufferable to configure MPU memory access attributes. TypeExtField
	 * IsShareable  IsCacheable  IsBufferable   Memory Attribtue    Shareability        Cache 0             x 0 0
	 * Strongly Ordered    shareable 0             x           0           1              Device             shareable
	 *     0             0           1           0              Normal             not shareable   Outer and inner write
	 * through no write allocate 0             0           1           1              Normal             not shareable
	 * Outer and inner write back no write allocate 0             1           1           0              Normal
	 * shareable       Outer and inner write through no write allocate 0             1           1           1 Normal
	 * shareable       Outer and inner write back no write allocate 1             0           0           0 Normal not
	 * shareable   outer and inner noncache 1             1           0           0              Normal shareable outer
	 * and inner noncache 1             0           1           1              Normal             not shareable   outer
	 * and inner write back write/read acllocate 1             1           1           1              Normal shareable
	 * outer and inner write back write/read acllocate 2             x           0           0              Device not
	 * shareable Above are normal use settings, if your want to see more details or want to config different
	 * inner/outter cache policy. please refer to Table 4-55 /4-56 in arm cortex-M7 generic user guide
	 * <dui0646b_cortex_m7_dgug.pdf> param SubRegionDisable  Sub-region disable field. 0=sub-region is enabled,
	 * 1=sub-region is disabled. param Size              Region size of the region to be configured. use
	 * ARM_MPU_REGION_SIZE_xxx MACRO in core_cm7.h.
	 */
	MPU->RBAR = ARM_MPU_RBAR(7, 0x80000000U);
	MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 1, 1, 1, 0, ARM_MPU_REGION_SIZE_32MB);
	/* Enable MPU */
	ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

	/* Enable I cache and D cache */
	SCB_EnableDCache();
	SCB_EnableICache();
}

/*!
 * @brief Main function
 */
int main(void)
{
	BaseType_t stat;

	/* Init board hardware. */
	BOARD_ConfigMPU();
	BOARD_ConfigUSBMPU();
	BOARD_BootClockRUN();

	/*
	 * Reset the displaymix, otherwise during debugging, the
	 * debugger may not reset the display, then the behavior
	 * is not right.
	 */
	SRC_AssertSliceSoftwareReset(SRC, kSRC_DisplaySlice);

	BOARD_InitLpuartPins();
	BOARD_InitMicPins();
	BOARD_InitMipiPanelPins();
	BOARD_MIPIPanelTouch_I2C_Init();
	BOARD_InitDebugConsole();

	CLOCK_InitAudioPll(&audioPllConfig);

	/* 24.576m mic root clock */
	CLOCK_SetRootClockMux(kCLOCK_Root_Mic, 6);
	CLOCK_SetRootClockDiv(kCLOCK_Root_Mic, 16);

	PRINTF("\r\n Coffee Machine Demo\r\n");

	GPH_Process = xEventGroupCreate();


	if (xTaskCreate(VIT_Task, "VIT_Task", configMINIMAL_STACK_SIZE + 1024, NULL, configMAX_PRIORITIES - 4, NULL) !=
			pdPASS)
	{
		PRINTF("\r\nFailed to create VIT task\r\n");
		while (1)
			;
	}


	if (xTaskCreate(Graphics_Process, "Graphics_Process", configMINIMAL_STACK_SIZE + 400, NULL, configMAX_PRIORITIES - 5, NULL) !=
			pdPASS)
	{
		PRINTF("\r\nFailed to create application task\r\n");
		while (1)
			;
	}

	if (xTaskCreate(AppTask, "lvgl", configMINIMAL_STACK_SIZE + 1024, NULL, configMAX_PRIORITIES - 6, NULL) !=
			pdPASS)
	{
		PRINTF("\r\nFailed to create VIT task\r\n");
		while (1)
			;
	}

	vTaskStartScheduler();

	for (;;)
	{
	} /* should never get here */
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
	if (s_lvgl_initialized)
	{
		lv_tick_inc(1);
	}
}
