/*
 * Copyright 2023 NXP
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
#include "fsl_soc_src.h"


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

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


#if LV_USE_LOG
static void print_cb(const char *buf)
{
	PRINTF("\r%s\n", buf);
}
#endif



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
	BOARD_InitMipiPanelPins();
	BOARD_MIPIPanelTouch_I2C_Init();
	BOARD_InitTestPins();
	BOARD_InitLEDPins();
	BOARD_InitDebugConsole();

	D0_On();	D1_On();	D2_On();	D3_On();	D4_On();	D5_On();
	D0_Off();	D1_Off();	D2_Off();	D3_Off();	D4_Off();	D5_Off();

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
