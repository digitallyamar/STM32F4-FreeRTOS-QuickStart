/*****************************************************************************
 * stm32f4.h: SOC specific parameter descriptions.
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

#ifndef __STM32F4__H
#define __STM32F4__H

#include <stdint.h>

#define AHB3_BASE               0xA0000000
#define AHB2_BASE               0x50000000
#define AHB1_BASE               0x40020000
#define APB2_BASE               0x40010000
#define APB1_BASE               0x40000000


/************************************************************************/
/*************************** AHB3 Peripherals ***************************/
/************************************************************************/

/* FSMC */
#define FSMC_BASE                (AHB3_BASE)


/************************************************************************/
/*************************** AHB2 Peripherals ***************************/
/************************************************************************/

/* RNG */
#define RNG_BASE                (AHB2_BASE + 0x60800)

/* HASH */
#define HASH_BASE               (AHB2_BASE + 0x60400)

/* CRYP */
#define CRYP_BASE               (AHB2_BASE + 0x60000)

/* DCMI */
#define DCMI_BASE               (AHB2_BASE + 0x50000)

/* USB OTG HS */
#define OTG_FS_BASE             (AHB2_BASE)


/************************************************************************/
/*************************** APB2 Peripherals ***************************/
/************************************************************************/

/* USB OTG HS */
#define OTG_HS_BASE             (AHB1_BASE + 0x20000)

/* DMA2D */
#define DMA2D_BASE              (AHB1_BASE + 0xB000)

/* Ethernet MAC */
#define ETH_BASE                (AHB1_BASE + 0x8000)

/* DMA2 */
#define DMA2_BASE               (AHB1_BASE + 0x4000)

/* DMA1 */
#define DMA1_BASE               (AHB1_BASE + 0x4000)

/* BKPSRAM */
#define BKPSRAM_BASE            (AHB1_BASE + 0x4000)

/* Flash Interface */
#define FLASH_INT_BASE          (AHB1_BASE + 0x3C00)

/* RCC */
#define RCC_BASE                (AHB1_BASE + 0x3800)

/* CRC */
#define CRC_BASE                (AHB1_BASE + 0x3000)

/* GPIOK */
#define GPIOK_BASE              (AHB1_BASE + 0x2800)

/* GPIOJ */
#define GPIOJ_BASE              (AHB1_BASE + 0x2400)

/* GPIOI */
#define GPIOI_BASE              (AHB1_BASE + 0x2000)

/* GPIOH */
#define GPIOH_BASE              (AHB1_BASE + 0x1C00)

/* GPIOG */
#define GPIOG_BASE              (AHB1_BASE + 0x1800)

/* GPIOF */
#define GPIOF_BASE              (AHB1_BASE + 0x1400)

/* GPIOE */
#define GPIOE_BASE              (AHB1_BASE + 0x1000)

/* GPIOD */
#define GPIOD_BASE              (AHB1_BASE + 0x0C00)

/* GPIOC */
#define GPIOC_BASE              (AHB1_BASE + 0x0800)

/* GPIOB */
#define GPIOB_BASE              (AHB1_BASE + 0x0400)

/* GPIOA */
#define GPIOA_BASE              (AHB1_BASE)

/* LCD-TFT */
#define LCD_BASE                (APB2_BASE + 0x6800)

/* SAI1 */
#define SAI1_BASE               (APB2_BASE + 0x5800)

/* SPI6 */
#define SPI6_BASE               (APB2_BASE + 0x5400)

/* SPI5 */
#define SPI5_BASE               (APB2_BASE + 0x5000)

/* TIM11 */
#define TIM11_BASE              (APB2_BASE + 0x4800)

/* TIM10 */
#define TIM10_BASE              (APB2_BASE + 0x4400)

/* TIM9 */
#define TIM9_BASE               (APB2_BASE + 0x4000)

/* EXTI */
#define EXTI_BASE               (APB2_BASE + 0x3C00)

/* SYSCFG */
#define SYSCFG_BASE             (APB2_BASE + 0x3800)

/* SPI4 */
#define SPI4_BASE               (APB2_BASE + 0x3400)

/* SPI1 */
#define SPI1_BASE               (APB2_BASE + 0x3000)

/* SDIO */
#define SDIO_BASE               (APB2_BASE + 0x2C00)

/* ADC */
#define ADC_BASE                (APB2_BASE + 0x2000)

/* USART6 */
#define USART6_BASE             (APB2_BASE + 0x1400)

/* USART1 */
#define USART1_BASE             (APB2_BASE + 0x1000)

/* TIM8 */
#define TIM8_BASE               (APB2_BASE + 0x0400)

/* TIM1 */
#define TIM1_BASE               (APB2_BASE)


/************************************************************************/
/*************************** APB1 Peripherals ***************************/
/************************************************************************/

/* UART7 */
#define UART8_BASE              (APB1_BASE + 0x7C00)

/* UART7 */
#define UART7_BASE              (APB1_BASE + 0x7800)

/* DAC */
#define DAC_BASE                (APB1_BASE + 0x7400)

/* PWR */
#define PWR_BASE                (APB1_BASE + 0x7000)

/* CAN2 */
#define CAN2_BASE               (APB1_BASE + 0x6800)

/* CAN1 */
#define CAN1_BASE               (APB1_BASE + 0x6400)

/* I2C3 */
#define I2C3_BASE               (APB1_BASE + 0x5C00)

/* I2C2 */
#define I2C2_BASE               (APB1_BASE + 0x5800)

/* I2C1 */
#define I2C1_BASE               (APB1_BASE + 0x5400)

/* UART5 */
#define UART5_BASE              (APB1_BASE + 0x5000)

/* UART4 */
#define UART4_BASE              (APB1_BASE + 0x4C00)

/* USART3 */
#define USART3_BASE             (APB1_BASE + 0x4800)

/* USART2 */
#define USART2_BASE             (APB1_BASE + 0x4400)

/* I2S3ext */
#define I2S3Ext_BASE            (APB1_BASE + 0x4000)

/* SPI3 */
#define SPI3_BASE               (APB1_BASE + 0x3C00)

/* SPI2 */
#define SPI2_BASE               (APB1_BASE + 0x3800)

/* I2S2ext */
#define I2S2Ext_BASE            (APB1_BASE + 0x2C00)

/* IWDG */
#define IWDG_BASE               (APB1_BASE + 0x3000)

/* WWDG */
#define WWDG_BASE               (APB1_BASE + 0x2C00)

/* RTC & BKUP */
#define RTC_BASE                (APB1_BASE + 0x2800)

/* Timers */
#define TIM14_BASE              (APB1_BASE + 0x2000)
#define TIM13_BASE              (APB1_BASE + 0x1C00)
#define TIM12_BASE              (APB1_BASE + 0x1800)
#define TIM7_BASE               (APB1_BASE + 0x1400)
#define TIM6_BASE               (APB1_BASE + 0x1000)
#define TIM5_BASE               (APB1_BASE + 0xC00)
#define TIM4_BASE               (APB1_BASE + 0x800)
#define TIM3_BASE               (APB1_BASE + 0x400)
#define TIM2_BASE               (APB1_BASE)





typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t RSVD0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t RSVD1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t RSVD2;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t RSVD3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    volatile uint32_t RSVD4;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t RSVD5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t RSVD6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
} RCC_REG_T;


typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDER;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_REG_T;

#define RCC                     ((RCC_REG_T *) RCC_BASE)
#define GPIOA                   ((GPIO_REG_T *) GPIOA_BASE)
#define GPIOB                   ((GPIO_REG_T *) GPIOB_BASE)
#define GPIOC                   ((GPIO_REG_T *) GPIOC_BASE)
#define GPIOD                   ((GPIO_REG_T *) GPIOD_BASE)
#define GPIOE                   ((GPIO_REG_T *) GPIOE_BASE)
#define GPIOF                   ((GPIO_REG_T *) GPIOF_BASE)
#define GPIOG                   ((GPIO_REG_T *) GPIOG_BASE)
#define GPIOH                   ((GPIO_REG_T *) GPIOH_BASE)
#define GPIOI                   ((GPIO_REG_T *) GPIOI_BASE)
#define GPIOJ                   ((GPIO_REG_T *) GPIOJ_BASE)
#define GPIOK                   ((GPIO_REG_T *) GPIOK_BASE)

void stm32f4_system_init(void);

#endif      //__STM32F4_H__