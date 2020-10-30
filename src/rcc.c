#include "stm32f4.h"
#include "rcc.h"

void rcc_hsi_clock_on(void) {
    // Turn ON the HSI ON bit
    RCC->CR |= RCC_HSI_ON;

    // Wait for HSI oscillator to be ready
    while (!(RCC->CR & RCC_HSI_RDY));    
}

void rcc_hsi_clock_off(void) {
    // Turn OFF the HSI ON bit
    RCC->CR &= RCC_HSI_OFF;

    // Wait for HSI oscillator to be turned off
    while (RCC->CR & RCC_HSI_RDY);
}

void rcc_hse_clock_on(void) {
    // Turn ON the HSE ON bit
    RCC->CR |= RCC_HSE_ON;

    // Wait for HSE oscillator to be ready
    while (!(RCC->CR & RCC_HSE_RDY));
}

void rcc_pll_clock_on(void) {
    // Turn ON the HSE ON bit
    RCC->CR |= RCC_PLL_ON;

    // Wait for HSE oscillator to be ready
    while (!(RCC->CR & RCC_PLL_RDY));
}

void rcc_css_on(void) {
    // Turn ON the CSS ON bit
    RCC->CR |= RCC_CSS_ON;
}

void rcc_set_sysclk_src(int clk) {
    // Switch clock to clk
    RCC->CFGR &= SYS_CLK_SW_MASK;
    RCC->CFGR |= clk;

    // Wait for new SYS clock cfg. to be ready
    while ((RCC->CFGR & (SYS_CLK_SWS_MASK)) != (clk << SYS_CLK_SWS_SHIFT));
}

void rcc_apb1_peri_clk_enable(int peri_clk_enable) {
    RCC->APB1ENR |= peri_clk_enable;
}

void rcc_apb2_peri_clk_enable(int peri_clk_enable) {
    RCC->APB2ENR |= peri_clk_enable;
}

void rcc_ahb1_peri_clk_enable(int peri_clk_enable) {
    RCC->AHB1ENR |= peri_clk_enable;
}

void rcc_ahb2_peri_clk_enable(int peri_clk_enable) {
    RCC->AHB2ENR |= peri_clk_enable;
}


void rcc_clk_set_pllm(int pllm) {
    // Clear PLLM bit values
    RCC->PLLCFGR &= RCC_PLLM_CLR_MASK;

    // Set only values between bits[5:0] that belongs to PLLM
    RCC->PLLCFGR |= ((pllm  << RCC_PLLM_SHIFT) & RCC_PLLM_SET_MASK);
}

void rcc_clk_set_plln(int plln) {
    // Clear PLLN bit values
    RCC->PLLCFGR &= RCC_PLLN_CLR_MASK;

    // Set only values between bits[14:6] that belongs to PLLN
    RCC->PLLCFGR |= ((plln << RCC_PLLN_SHIFT) & RCC_PLLN_SET_MASK);
}

void rcc_clk_set_pllp(int pllp) {
    // Clear PLLP bit values
    RCC->PLLCFGR &= RCC_PLLP_CLR_MASK;

    // Set only values between bits[17:16] that belongs to PLLP
    RCC->PLLCFGR |= ((pllp << RCC_PLLP_SHIFT) & RCC_PLLP_SET_MASK);
}


void rcc_clk_set_pllq(int pllq) {
    // Clear PLLP bit values
    RCC->PLLCFGR &= RCC_PLLQ_CLR_MASK;

    // Set only values between bits[27:24] that belongs to PLLQ
    RCC->PLLCFGR |= ((pllq << RCC_PLLQ_SHIFT) & RCC_PLLQ_SET_MASK);
}

void rcc_clk_set_pllsrc(int pllsrc) {
    if (pllsrc == RCC_PLLSRC_HSE) {
        RCC->PLLCFGR |= RCC_PLLSRC_HSE;
    }
    else {
        RCC->PLLCFGR &= RCC_PLLSRC_HSI;
    }
}

void rcc_clk_set_hpre(int hpre) {
    // Clear HPRE bit values
    RCC->CFGR &= RCC_HPRE_CLR_MASK;

   // Set only values between bits[7:4] that belongs to HPRE
    RCC->CFGR |= ((hpre << RCC_HPRE_SHIFT) & RCC_HPRE_SET_MASK);
}

void rcc_clk_set_ppre1(int ppre1) {
    // Clear HPRE bit values
    RCC->CFGR &= RCC_PPRE1_CLR_MASK;

   // Set only values between bits[12:10] that belongs to HPRE
    RCC->CFGR |= ((ppre1 << RCC_PPRE1_SHIFT) & RCC_PPRE1_SET_MASK);
}

void rcc_clk_set_ppre2(int ppre2) {
    // Clear HPRE bit values
    RCC->CFGR &= RCC_PPRE2_CLR_MASK;

   // Set only values between bits[15:13] that belongs to HPRE
    RCC->CFGR |= ((ppre2 << RCC_PPRE2_SHIFT) & RCC_PPRE2_SET_MASK);
}