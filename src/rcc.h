#ifndef __RCC_H__

#define RCC_HSI_ON              (1 << 0)
#define RCC_HSI_RDY             (1 << 1)
#define RCC_HSI_OFF             ~(1 << 0)

#define RCC_HSE_ON              (1 << 16)
#define RCC_HSE_RDY             (1 << 17)

#define RCC_CSS_ON              (1 << 19)

#define RCC_PLL_ON              (1 << 24)
#define RCC_PLL_RDY             (1 << 25)


#define RCC_PLLM_CLR_MASK       0xFFFFFFC0
#define RCC_PLLM_SET_MASK       0x0000003F
#define RCC_PLLN_CLR_MASK       0xFFFF003F
#define RCC_PLLN_SET_MASK       0x00007FC0
#define RCC_PLLP_CLR_MASK       0xFFFCFFFF
#define RCC_PLLP_SET_MASK       0x00030000
#define RCC_PLLQ_CLR_MASK       0xF0FFFFFF
#define RCC_PLLQ_SET_MASK       0x0F000000

#define RCC_PLLM_SHIFT          0
#define RCC_PLLN_SHIFT          6
#define RCC_PLLP_SHIFT          16
#define RCC_PLLQ_SHIFT          24

#define RCC_HPRE_CLR_MASK       0xFFFFFF0F
#define RCC_HPRE_SET_MASK       0x000000F0

#define RCC_PPRE1_CLR_MASK       0xFFFFE3FF
#define RCC_PPRE1_SET_MASK       0x00001C00

#define RCC_PPRE2_CLR_MASK       0xFFFF1FFF
#define RCC_PPRE2_SET_MASK       0x0000E000

#define RCC_HPRE_SHIFT          4
#define RCC_PPRE1_SHIFT         10
#define RCC_PPRE2_SHIFT         13

#define RCC_CFGR_HPRE_DIV_NONE  0
#define RCC_CFGR_HPRE_DIV_2     2
#define RCC_CFGR_HPRE_DIV_4     4
#define RCC_CFGR_HPRE_DIV_8     8
#define RCC_CFGR_HPRE_DIV_16    16
#define RCC_CFGR_HPRE_DIV_64    64
#define RCC_CFGR_HPRE_DIV_128   128
#define RCC_CFGR_HPRE_DIV_256   256
#define RCC_CFGR_HPRE_DIV_512   512

#define RCC_CFGR_PPRE_DIV_NONE  0
#define RCC_CFGR_PPRE_DIV_2     4
#define RCC_CFGR_PPRE_DIV_4     5
#define RCC_CFGR_PPRE_DIV_8     6
#define RCC_CFGR_PPRE_DIV_16    7

#define RCC_PLLSRC_HSI              ~(1 << 22)
#define RCC_PLLSRC_HSE              (1 << 22)

#define SYS_CLK_SW_HSI          0
#define SYS_CLK_SW_HSE          1
#define SYS_CLK_SW_PLL          2

#define SYS_CLK_SW_MASK         0xFFFFFFFC
#define SYS_CLK_SWS_MASK        0xC
#define SYS_CLK_SWS_SHIFT        0x2

// APB1 Periperhals Clock Enable
#define TIM2_CLK_ENABLE         (1 << 0)
#define TIM3_CLK_ENABLE         (1 << 1)
#define TIM4_CLK_ENABLE         (1 << 2)
#define TIM5_CLK_ENABLE         (1 << 3)
#define TIM6_CLK_ENABLE         (1 << 4)
#define TIM7_CLK_ENABLE         (1 << 5)
#define TIM12_CLK_ENABLE        (1 << 6)
#define TIM13_CLK_ENABLE        (1 << 7)
#define TIM14_CLK_ENABLE        (1 << 8)
#define WWDG_CLK_ENABLE         (1 << 11)
#define SPI12_CLK_ENABLE        (1 << 14)
#define SPI13_CLK_ENABLE        (1 << 15)
#define USART2_CLK_ENABLE       (1 << 17)
#define USART3_CLK_ENABLE       (1 << 18)
#define UART4_CLK_ENABLE        (1 << 19)
#define UART5_CLK_ENABLE        (1 << 20)
#define I2C1_CLK_ENABLE         (1 << 21)
#define I2C2_CLK_ENABLE         (1 << 22)
#define I2C3_CLK_ENABLE         (1 << 23)
#define CAN1_CLK_ENABLE         (1 << 25)
#define CAN2_CLK_ENABLE         (1 << 26)
#define PWR_CLK_ENABLE          (1 << 28)
#define DAC_CLK_ENABLE          (1 << 29)

// AHB1 Periperhals Clock Enable
#define GPIOA_CLK_ENABLE        (1 << 0)
#define GPIOB_CLK_ENABLE        (1 << 1)
#define GPIOC_CLK_ENABLE        (1 << 2)
#define GPIOD_CLK_ENABLE        (1 << 3)
#define GPIOE_CLK_ENABLE        (1 << 4)
#define GPIOF_CLK_ENABLE        (1 << 5)
#define GPIOG_CLK_ENABLE        (1 << 6)
#define GPIOH_CLK_ENABLE        (1 << 7)
#define GPIOI_CLK_ENABLE        (1 << 8)
#define GPIOJ_CLK_ENABLE        (1 << 9)
#define GPIOK_CLK_ENABLE        (1 << 10)
#define CRC_CLK_ENABLE          (1 << 12)
#define BKPSRAMEN_CLK_ENABLE    (1 << 18)
#define CCMDATARAMEN_CLK_ENABLE (1 << 20)
#define DMA1EN_CLK_ENABLE       (1 << 21)
#define DMA2EN_CLK_ENABLE       (1 << 22)
#define DMA2DEN_CLK_ENABLE      (1 << 23)
#define ETHMACEN_CLK_ENABLE     (1 << 25)
#define ETHMACTXEN_CLK_ENABLE   (1 << 26)
#define ETHMACRXEN_CLK_ENABLE   (1 << 27)
#define ETHMACPTPEN_CLK_ENABLE  (1 << 28)
#define OTGHSEN_CLK_ENABLE      (1 << 29)
#define OTGHSULPIEN_CLK_ENABLE  (1 << 30)

// AHB2 Periperhals Clock Enable
#define TIM1_CLK_ENABLE         (1 << 0)
#define TIM8_CLK_ENABLE         (1 << 1)
#define USART1_CLK_ENABLE       (1 << 4)
#define USART6_CLK_ENABLE       (1 << 5)
#define ADC1_CLK_ENABLE         (1 << 8)
#define ADC2_CLK_ENABLE         (1 << 9)
#define ADC3_CLK_ENABLE         (1 << 10)
#define SDIO_CLK_ENABLE         (1 << 11)
#define SPI1_CLK_ENABLE         (1 << 12)
#define SPI4_CLK_ENABLE         (1 << 13)
#define SYSCFG_CLK_ENABLE       (1 << 14)
#define TIM9_CLK_ENABLE         (1 << 16)
#define TIM10_CLK_ENABLE        (1 << 17)
#define TIM11_CLK_ENABLE        (1 << 18)
#define SPI5_CLK_ENABLE         (1 << 20)
#define SPI6_CLK_ENABLE         (1 << 21)
#define SAI1_CLK_ENABLE         (1 << 22)
#define LTDC_CLK_ENABLE         (1 << 26)

void rcc_hsi_clock_on(void);
void rcc_hse_clock_on(void);
void rcc_pll_clock_on(void);
void rcc_css_on(void);

void rcc_hsi_clock_off(void);

void rcc_set_sysclk_src(int clk);
void rcc_apb1_peri_clk_enable(int peri_clk_enable);
void rcc_apb2_peri_clk_enable(int peri_clk_enable);
void rcc_ahb1_peri_clk_enable(int peri_clk_enable);
void rcc_ahb2_peri_clk_enable(int peri_clk_enable);

void rcc_clk_set_pllm(int pllm);
void rcc_clk_set_plln(int plln);
void rcc_clk_set_pllp(int pllp);
void rcc_clk_set_pllq(int pllq);

void rcc_clk_set_hpre(int hpre);
void rcc_clk_set_ppre1(int ppre1);
void rcc_clk_set_ppre2(int ppre2);

void rcc_clk_set_pllsrc(int pllsrc);


#endif  //__RCC_H__