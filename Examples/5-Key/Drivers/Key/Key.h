/*========== Key.c ==========*/
#ifndef UINIO_KEY_H
#define UINIO_KEY_H

#include "gd32f3x0.h"
#include "systick.h"

#define UINIO_KEY_RCU  RCU_GPIOB   // 指定开关对应的 GPIO 端口时钟
#define UINIO_KEY_PORT GPIOB       // 指定开关对应的 GPIO 端口
#define UINIO_KEY_PIN  GPIO_PIN_9  // 指定开关对应的 GPIO 引脚

void UINIO_Key_GPIO_Config(void);  // 调用开关对应 GPIO 引脚的配置函数
void UINIO_Key_Scan(void);         // 扫描按键状态

#endif /* UINIO_KEY_H */
