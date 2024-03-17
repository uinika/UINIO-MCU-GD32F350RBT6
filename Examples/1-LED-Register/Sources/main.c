/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "main.h"

#include "../Drivers/LED/LED.h"

int main(void) {
  systick_config();        // 配置系统滴答定时器
  UINIO_LED_GPIO_Config(); // 配置连接 LED 的 GPIO 端口

  /* 端口输出控制寄存器 GPIOB_OCTL 方式控制 LED */
  UINIO_GPIOB_OCTL &= ~(0x01 << 8);      // 输出低电平，LED 熄灭
  UINIO_GPIOB_OCTL |=  (0x01 << 8);      // 输出高电平，LED 点亮

  /* 端口位操作寄存器 GPIOB_BOP 方式控制 LED */
  UINIO_GPIOB_BOP |= (0x01 << (8 + 16)); // 输出低电平，LED 熄灭
  UINIO_GPIOB_BOP |= (0x01 << 8);        // 输出高电平，LED 点亮

  while(1) {}
}
