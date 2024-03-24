/*========== EXTI-Key.h ==========*/
#ifndef UINIO_EXTI_KEY_H
#define UINIO_EXTI_KEY_H

#include "gd32f3x0.h"

#define UINIO_KEY_PORT GPIOA       // 按键对应的 GPIO 端口
#define UINIO_KEY_PIN  GPIO_PIN_0  // 按键对应的 GPIO 引脚
#define UINIO_KEY_RCU  RCU_GPIOA   // 按键对应 GPIO 端口的外设时钟

#define UINIO_KEY_EXTI_PORT_SOURCE EXTI_SOURCE_GPIOA   // 定义用于 EXTI 的 GPIO 端口
#define UINIO_KEY_EXTI_PIN_SOURCE  EXTI_SOURCE_PIN0    // 定义用于 EXTI 的 GPIO 引脚
#define UINIO_KEY_EXTI_LINE        EXTI_0              // 定义 EXTI 中断线 0
#define UINIO_KEY_EXTI_IRQN        EXTI0_1_IRQn        // 定义EXTI 线 0 和线 1 中断
#define UINIO_KEY_EXTI_IRQ_Handler EXTI0_1_IRQHandler  // 定义 EXTI 中断函数的名称

void UINIO_EXTI_Key_Scan(void);         // 按键扫描函数
void UINIO_EXTI_Key_GPIO_Config(void);  // 按键中断配置函数

#endif /* UINIO_EXTI_KEY_H */
