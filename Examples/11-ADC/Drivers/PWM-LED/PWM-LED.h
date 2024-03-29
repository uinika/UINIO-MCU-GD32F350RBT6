/*========== PWM_LED.h ==========*/
#ifndef UINIO_PWM_LED_H
#define UINIO_PWM_LED_H

#include "gd32f3x0.h"

#define UINIO_PWM_RCU  RCU_GPIOA   // 定义 PWM 对应 GPIOA 端口的外设时钟
#define UINIO_PWM_PORT GPIOA       // 定义 PWM 对应的 GPIOA 端口
#define UINIO_PWM_PIN  GPIO_PIN_5  // 定义 PWM 对应的 GPIO 引脚
#define UINIO_PWM_AF   GPIO_AF_2   // 定义 PWM 对应 GPIO 引脚的复用功能 2

#define UINIO_PWM_TIMER_RCU RCU_TIMER1  // 定义通用定时器 TIMER1 的外设时钟
#define UINIO_PWM_TIMER     TIMER1      // 定义通用定时器 TIMER1 自身
#define UINIO_PWM_CHANNEL   TIMER_CH_0  // 定义定时器的通道 0

void UINIO_PWM_Config(uint16_t UINIO_Clock_Prescale, uint16_t UINIO_Clock_Period); // 预定义 PWM 工作参数配置函数
void UINIO_PWM_LED_Breathing(void);                                                // 预定义 PWM 呼吸灯控制函数

#endif /* UINIO_PWM_LED_H */
