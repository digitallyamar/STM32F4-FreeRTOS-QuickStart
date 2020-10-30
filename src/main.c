/*****************************************************************************
 * main.c: Entry point to the application code that is going to run on top of 
 * FreeRTOS over STM32F4 based board.
 *****************************************************************************
 * Copyright (C) 2020-2021
 *  
 * Author: DigitallyAmar (@digitallyamar)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include "stm32f4.h"
#include "gpio.h"
#include "rcc.h"
#include "FreeRTOS.h"
#include "task.h"

uint32_t SystemCoreClock = 150000000;

#define mainLED_TASK_PRIORITY			(tskIDLE_PRIORITY + 1)

void vLEDFlashTask(void *p) {
    portTickType xLastWakeTime;
    const portTickType xFrequency = pdMS_TO_TICKS(100);
	xLastWakeTime = xTaskGetTickCount();

    for(;;) {
        //Turn ON PA6 & Turn OFF PA7
        GPIOA->ODR &= ~(1 << GPIO_PIN_6);
        GPIOA->ODR |= (1 << GPIO_PIN_7);

        vTaskDelayUntil(&xLastWakeTime, xFrequency);

        //Turn OFF PA6 & Turn ON PA7
        GPIOA->ODR |= (1 << GPIO_PIN_6);
        GPIOA->ODR &= ~(1 << GPIO_PIN_7);

		vTaskDelayUntil(&xLastWakeTime, xFrequency);

    }

    vTaskDelete( NULL );
}

int main(void) {
    // Enable system clocks
    stm32f4_system_init();

    // Enable clock for GPIOA
    RCC->AHB1ENR |= GPIOA_CLK_ENABLE;

    // Configure GPIOs for LEDs at PA6 & PA7
    gpio_set_mode(GPIOA, GPIO_PIN_6, GPIO_MODE_OUTPUT);
    gpio_set_mode(GPIOA, GPIO_PIN_7, GPIO_MODE_OUTPUT);

    //Turn OFF PA6 & PA7
    GPIOA->ODR |= (1 << GPIO_PIN_6);
    GPIOA->ODR |= (1 << GPIO_PIN_7);

    xTaskCreate( vLEDFlashTask, "LEDx", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, ( TaskHandle_t * ) NULL );

	/* Start the scheduler. */
	vTaskStartScheduler();

    return 0;
}

void vApplicationIdleHook( void );

void vApplicationIdleHook( void )
{
	//vCoRoutineSchedule();
}
