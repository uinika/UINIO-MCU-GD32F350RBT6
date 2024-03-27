/*========== TIMER_LED.h ==========*/
#ifndef UINIO_TIMER_LED_H
#define UINIO_TIMER_LED_H

#include "gd32f3x0.h"

#define UINIO_TIMER_RCU         RCU_TIMER5             // 定时器 Timer5 时钟
#define UINIO_TIMER             TIMER5                 // 定时器 Timer5
#define UINIO_TIMER_IRQ         TIMER5_DAC_IRQn        // 定时器 Timer5 中断
#define UINIO_TIMER_IRQ_Handler TIMER5_DAC_IRQHandler  // 定时器 Timer5 中断服务函数

// #define UINIO_TIMER_RCU         RCU_TIMER2           // 定时器 Timer2 时钟
// #define UINIO_TIMER             TIMER2               // 定时器 Timer2
// #define UINIO_TIMER_IRQ         TIMER2_IRQn          // 定时器 Timer2 中断
// #define UINIO_TIMER_IRQ_Handler TIMER2_IRQHandler    // 定时器 Timer2 中断服务函数

void UINIO_Basic_Timer_Config(uint16_t pre, uint16_t per); // 基本定时器配置函数

#endif /* UINIO_TIMER_LED_H */
