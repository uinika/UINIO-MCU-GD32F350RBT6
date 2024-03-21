/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "main.h"
#include <stdio.h>

#include "../Drivers/LED/LED.h"
#include "../Drivers/USART/USART.h"
#include "../Drivers/EXTI-Key/EXTI-Key.h"

int main(void) {
  /* 配置优先级分组（2 位用于抢占优先级，2 位用于响应优先级） */
  nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);

  UINIO_LED_GPIO_Config();         // 初始化 LED 对应的 GPIO 引脚资源
  UINIO_EXTI_Key_GPIO_Config();    // 初始化按键中断配置
  UINIO_USART_GPIO_Config(9600U);  // 初始化 USART 串口，设置波特率为 9600

  while (1) {};
}
