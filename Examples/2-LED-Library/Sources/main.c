/*========== main.c ==========*/
#include "gd32f3x0.h"

#include "main.h"
#include "../Drivers/LED/LED.h"

int main(void) {
  UINIO_LED_GPIO_Config();  // 初始化 LED 相关的 GPIO 引脚

  gpio_bit_set(UINIO_LED_PORT, UINIO_LED_PIN);             // GPIOB8 输出高电平
  gpio_bit_reset(UINIO_LED_PORT, UINIO_LED_PIN);           // GPIOB8 输出低电平

  gpio_bit_write(UINIO_LED_PORT, UINIO_LED_PIN, RESET);    // GPIOB8 输出低电平
  gpio_bit_write(UINIO_LED_PORT, UINIO_LED_PIN, SET);      // GPIOB8 输出高电平

  while(1) {}
}
