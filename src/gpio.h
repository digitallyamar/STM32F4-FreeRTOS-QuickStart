#ifndef __GPIO__H
#define __GPIO__H

#define GPIO_MODE_INTPUT        0
#define GPIO_MODE_OUTPUT        1
#define GPIO_MODE_ALTFUN        2
#define GPIO_MODE_ANALOG        3

#define GPIO_MODE_MASK          0x3
#define GPIO_MODE_BITS_SIZE     2

#define GPIO_PIN_0              0
#define GPIO_PIN_1              1
#define GPIO_PIN_2              2
#define GPIO_PIN_3              3
#define GPIO_PIN_4              4
#define GPIO_PIN_5              5
#define GPIO_PIN_6              6
#define GPIO_PIN_7              7
#define GPIO_PIN_8              8
#define GPIO_PIN_9              9
#define GPIO_PIN_10             10
#define GPIO_PIN_11             11
#define GPIO_PIN_12             12
#define GPIO_PIN_13             13
#define GPIO_PIN_14             14
#define GPIO_PIN_15             15

#define GPIO_AFMODE_AF0         0
#define GPIO_AFMODE_AF1         1
#define GPIO_AFMODE_AF2         2
#define GPIO_AFMODE_AF3         3
#define GPIO_AFMODE_AF4         4
#define GPIO_AFMODE_AF5         5
#define GPIO_AFMODE_AF6         6
#define GPIO_AFMODE_AF7         7
#define GPIO_AFMODE_AF8         8
#define GPIO_AFMODE_AF9         9
#define GPIO_AFMODE_AF10        10
#define GPIO_AFMODE_AF11        11
#define GPIO_AFMODE_AF12        12
#define GPIO_AFMODE_AF13        13
#define GPIO_AFMODE_AF14        14
#define GPIO_AFMODE_AF15        15

#define GPIO_AFMODE_MASK        0xF
#define GPIO_AFMODE_BITS_SIZE   4

void gpio_set_mode(GPIO_REG_T *gpio, int pin, int mode);
void gpio_set_af_mode(GPIO_REG_T *gpio, int pin, int af_mode);

#endif