/*========== Key.c ==========*/
#include "Key.h"
#include "../LED/LED.h"

/* 按键对应 GPIO 引脚的配置函数 */
void UINIO_Key_GPIO_Config(void) {
  rcu_periph_clock_enable(UINIO_KEY_RCU);                                            // 使能外设时钟
  gpio_mode_set(UINIO_KEY_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, UINIO_KEY_PIN); // 配置 GPIO 为输入下拉模式
}

/* 按键扫描函数 */
void UINIO_Key_Scan(void) {
  /* 判断按键引脚的电平状态（高电平按下，低电平松开） */
  if (gpio_input_bit_get(UINIO_KEY_PORT, UINIO_KEY_PIN) == SET) { // 按键按下
    delay_1ms(20);                                            // 软件延迟 20 毫秒进行消抖

    /* 再次判断按键引脚的电平状态 */
    if (gpio_input_bit_get(UINIO_KEY_PORT, UINIO_KEY_PIN) == SET) {
      gpio_bit_toggle(UINIO_PORT_LED, UINIO_PIN_LED);                    // 翻转 LED 对应 GPIO 引脚的电平状态

      while (gpio_input_bit_get(UINIO_KEY_PORT, UINIO_KEY_PIN) == SET);  // 判断按键是否被松开
    }
  }
}
