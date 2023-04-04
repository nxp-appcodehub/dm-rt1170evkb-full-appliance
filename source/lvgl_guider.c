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
#include "vit_proc.h"
#include "fsl_soc_src.h"
#include "ui_Aircon.h"
#if VIT_DEVICE_AIRCON
#include "ui_Aircon.h"
#endif
#if VIT_DEVICE_OVEN
#include "ui_Oven.h"
#endif
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
    vTaskSetApplicationTaskTag( NULL, ( void * ) 2 );

	EventBits_t event_bits;

	for(;;)
	{
		event_bits = xEventGroupWaitBits(GPH_Process, VIT_WW_DETECT | VIT_CMD_DETECT, pdTRUE, pdFALSE, portMAX_DELAY);

		if((event_bits & VIT_WW_DETECT) == VIT_WW_DETECT)
		{
            GPIO_PinWrite(BOARD_USER_LED_GPIO, BOARD_USER_LED_GPIO_PIN, 1U);
			lv_obj_set_style_opa(guider_ui.ui_Oven_Lottie_Mic, LV_OPA_100, 0);
		}

		if((event_bits & VIT_CMD_DETECT) == VIT_CMD_DETECT)
		{
           GPIO_PinWrite(BOARD_USER_LED_GPIO, BOARD_USER_LED_GPIO_PIN, 0U);
#if VIT_DEVICE_AIRCON
			ui_aircon_process_command(cmd_id);
#endif
#if VIT_DEVICE_OVEN
			ui_oven_process_command(cmd_id);
			lv_obj_set_style_opa(guider_ui.ui_Oven_Lottie_Mic, LV_OPA_TRANSP, 0);
#endif
		}
	}
}
static void AppTask(void *param)
{
#if LV_USE_LOG
	lv_log_register_print_cb(print_cb);
#endif

	vTaskSetApplicationTaskTag( NULL, ( void * ) 1 );

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
        vTaskDelay(1);

	}
}

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{
	BaseType_t stat;
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};

	/* Init board hardware. */
	BOARD_ConfigMPU();
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
	BOARD_InitTestPins();
	BOARD_InitLEDPins();
	BOARD_InitDebugConsole();

	D0_On();	D1_On();	D2_On();	D3_On();	D4_On();	D5_On();
	D0_Off();	D1_Off();	D2_Off();	D3_Off();	D4_Off();	D5_Off();

	CLOCK_InitAudioPll(&audioPllConfig);

	/* 24.576m mic root clock */
	CLOCK_SetRootClockMux(kCLOCK_Root_Mic, 6);
	CLOCK_SetRootClockDiv(kCLOCK_Root_Mic, 16);

    /* Display support */
    if (DEMO_PANEL == DEMO_PANEL_RK055AHD091)
    {
        PRINTF("Using RK055HDMIPI4M LCD Panel (Not Recommended for New Designs).\r\n");

    }
    else if (DEMO_PANEL == DEMO_PANEL_RK055MHD091)
    {
        PRINTF("Using RK055HDMIPI4MA0 LCD Panel.\r\n");

    }
    else
    {
        PRINTF("Display not supported for this demo.\r\n");
    }

    /* Init output LED GPIO. */
    GPIO_PinInit(BOARD_USER_LED_GPIO, BOARD_USER_LED_GPIO_PIN, &led_config);


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
