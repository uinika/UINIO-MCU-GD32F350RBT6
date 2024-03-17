/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "main.h"

#include "../Drivers/LED/LED.h"
#include "../Drivers/SysTick/SysTick.h"
#include "../Drivers/BitBand/BitBand.h"

int main(void) {
  UINIO_LED_GPIO_Config(); // 初始化 LED 相关的 GPIO 引脚

  while(1) {
    GPIOB_Out(8) = 1;      // GPIOB8 输出高电平
    UINIO_SysTick_Delay_ms(1000);

    GPIOB_Out(8) = 0;      // GPIOB8 输出低电平
    UINIO_SysTick_Delay_ms(1000);
  }
}
