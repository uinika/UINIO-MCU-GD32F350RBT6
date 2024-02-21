/*========== LED.h ==========*/
#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "gd32f3x0.h"
#include "systick.h"

#define RCU_LED RCU_GPIOB    // GPIOB 时钟
#define PORT_LED GPIOB       // GPIOB 端口
#define PIN_LED GPIO_PIN_8   // GPIOB 引脚

void LED_GPIO_Config(void);  // 配置 LED 关联的 GPIO 引脚

#endif /* BSP_LED_H */