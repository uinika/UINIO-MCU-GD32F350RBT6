/*========== UINIO_LED.h ==========*/
#ifndef UINIO_LED_H
#define UINIO_LED_H

#include "gd32f3x0.h"
#include "systick.h"

#define UINIO_RCU_LED RCU_GPIOB    // GPIOB 时钟
#define UINIO_PORT_LED GPIOB       // GPIOB 端口
#define UINIO_PIN_LED GPIO_PIN_8   // GPIOB 引脚

void UINIO_LED_GPIO_Config(void);  // 配置 LED 关联的 GPIO 引脚
#endif /* UINIO_LED_H */
