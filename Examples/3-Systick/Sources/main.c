/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "main.h"

#include "../Drivers/LED/LED.h"
#include "../Drivers/SysTick/SysTick.h"

int main(void) {
  UINIO_LED_GPIO_Config();  // 初始化 LED 相关的 GPIO 引脚

  while(1) {
    gpio_bit_write(UINIO_LED_PORT, UINIO_LED_PIN, SET);      // GPIOB8 输出高电平
    UINIO_SysTick_Delay_ms(1000);

    gpio_bit_write(UINIO_LED_PORT, UINIO_LED_PIN, RESET);    // GPIOB8 输出低电平
    UINIO_SysTick_Delay_us(1000000);
  }
}
