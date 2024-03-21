/*========== EXTI-Key.c ==========*/
#include "stdio.h"

#include "../LED/LED.h"
#include "../EXTI-Key/EXTI-Key.h"

/** 按键中断配置函数 */
void UINIO_EXTI_Key_GPIO_Config(void) {
  rcu_periph_clock_enable(UINIO_KEY_RCU);  // 使能按键对应的 GPIO 外设时钟
  rcu_periph_clock_enable(RCU_CFGCMP);     // 使能 CGFCMP 系统配置外设时钟

  gpio_mode_set(UINIO_KEY_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, UINIO_KEY_PIN);  // 配置按键对应的 GPIO 引脚为带下拉电阻的输入模式，默认为低电平
  nvic_irq_enable(UINIO_KEY_EXTI_IRQN, 3U, 3U);                                       // 使能 NVIC 中断，抢占优先级 1，子优先级 1

  syscfg_exti_line_config(UINIO_KEY_EXTI_PORT_SOURCE, UINIO_KEY_EXTI_PIN_SOURCE);  // 配置 GPIO 引脚作为 EXTI 外部中断
  exti_init(UINIO_KEY_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_BOTH);                  // 初始化 EXTI 外部中断线
  exti_interrupt_enable(UINIO_KEY_EXTI_LINE);                                      // 使能 EXTI 外部中断
  exti_interrupt_flag_clear(UINIO_KEY_EXTI_LINE);                                  // 清除 EXTI 外部中断标志位
}

/** 按键中断处理函数 */
void UINIO_KEY_EXTI_IRQ_Handler(void) {
  /* 如果中断标志位为 1，那么表示按键被按下 */
  if (exti_interrupt_flag_get(UINIO_KEY_EXTI_LINE) == SET) {
    /* 当按键被按下时，执行的任务 */
    if (gpio_input_bit_get(UINIO_KEY_PORT, UINIO_KEY_PIN) == SET) {
      gpio_bit_toggle(UINIO_LED_PORT, UINIO_LED_PIN);  // 翻转 LED 电平状态
      printf("Key Press\n");                           // 打印 Key Press
    }
    /* 当按键被松开时，执行的任务 */
    else {
      printf("Key Release\n");                         // 串口打印 Key Release
    }
    exti_interrupt_flag_clear(UINIO_KEY_EXTI_LINE);    // 清除 EXTI 外部中断标志位
  }
}

