/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "main.h"
#include <stdio.h>

#include "../Drivers/LED/LED.h"
#include "../Drivers/USART/USART.h"
#include "../Drivers/PWM-LED/PWM-LED.h"

int main(void) {
  systick_config();

  nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2); // 优先级分组

  UINIO_USART_GPIO_Config(9600U); // 初始化 USART 串口，设置波特率为 9600
  
  /* 频率(10800/108)兆赫兹 * 周期(10000)微秒 = 亮度调整间隔为 0.01 秒 */
  UINIO_PWM_Config(108, 10000);   // PWM 初始化

  while (1) {
    UINIO_PWM_LED_Breathing(); // 调用 PWM 呼吸灯控制函数
  }
}
