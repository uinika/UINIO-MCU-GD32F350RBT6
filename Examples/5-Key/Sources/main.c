/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"
#include "../Drivers/Key/Key.h"
#include "../Drivers/SysTick/SysTick.h"

int main(void) {
  systick_config();         // 滴答定时器初始化
  UINIO_LED_GPIO_Config();  // 配置 LED 相关的外设
  UINIO_Key_GPIO_Config();  // 配置按键相关的外设

  while (1) {
    UINIO_Key_Scan();       // 循环扫描按键状态
  }
}
