#include "stm32f4.h"
#include "gpio.h"

void gpio_set_mode(GPIO_REG_T *gpio, int pin, int mode) {
    gpio->MODER &= (~((GPIO_MODE_MASK) << (pin * GPIO_MODE_BITS_SIZE)));
    gpio->MODER |= (mode << (pin * GPIO_MODE_BITS_SIZE));

}

void gpio_set_af_mode(GPIO_REG_T *gpio, int pin, int af_mode) {
    
    if (pin < 8) {
        gpio->AFRL &= (~((GPIO_AFMODE_MASK) << (pin * GPIO_AFMODE_BITS_SIZE)));
        gpio->AFRL |= (af_mode << (pin * GPIO_AFMODE_BITS_SIZE));
    }
    else {
        gpio->AFRH &= (~((GPIO_AFMODE_MASK) << (pin * GPIO_AFMODE_BITS_SIZE)));
        gpio->AFRH |= (af_mode << (pin * GPIO_AFMODE_BITS_SIZE));
    }
}

