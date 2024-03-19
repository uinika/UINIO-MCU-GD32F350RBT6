/*========== UINIO_LED.h ==========*/
#ifndef UINIO_LED_H
#define UINIO_LED_H

#include "gd32f3x0.h"
#include "systick.h"

#define UINIO_LED_RCU  RCU_GPIOB   // 宏定义 LED 对应的 GPIO 端口时钟
#define UINIO_LED_PORT GPIOB       // 宏定义 LED 对应的 GPIO 端口
#define UINIO_LED_PIN  GPIO_PIN_8  // 宏定义 LED 对应的 GPIO 引脚

void UINIO_LED_GPIO_Config(void);  // LED 关联 GPIO 引脚的配置函数
#endif /* UINIO_LED_H */
