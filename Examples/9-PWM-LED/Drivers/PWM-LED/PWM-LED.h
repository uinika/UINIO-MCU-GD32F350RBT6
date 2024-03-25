/*========== PWM_LED.h ==========*/
#ifndef UINIO_PWM_LED_H
#define UINIO_PWM_LED_H

#include "gd32f3x0.h"

#define UINIO_PWM_RCU  RCU_GPIOA   // PWM 端口时钟
#define UINIO_PWM_PORT GPIOA       // PWM 端口
#define UINIO_PWM_PIN  GPIO_PIN_5  // PWM 引脚
#define UINIO_PWM_AF   GPIO_AF_1   // PWM 引脚复用

#define UINIO_PWM_TIMER_RCU RCU_TIMER1  // 定时器时钟
#define UINIO_PWM_TIMER     TIMER1      // 定时器
#define UINIO_PWM_CHANNEL   TIMER_CH_0  // 定时器通道

void UINIO_PWM_Config(uint16_t pre, uint16_t per); // PWM配置
void UINIO_PWM_LED_Breathing(void);                // 呼吸灯函数

#endif /* UINIO_PWM_LED_H */
