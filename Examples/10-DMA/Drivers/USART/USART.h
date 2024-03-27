#ifndef UINIO_USART_H
#define UINIO_USART_H

#include "gd32f3x0.h"
#include "systick.h"

#define UINIO_USART USART0             // 定义 USART 外设资源
#define UINIO_USART_RCU RCU_USART0     // 定义 USART0 的外设时钟
#define UINIO_USART_AF GPIO_AF_1       // 定义 GPIO 引脚的复用功能

/* 定义 TX 和 RX 对应的 GPIO 外设时钟 */
#define UINIO_USART_TX_RCU RCU_GPIOA
#define UINIO_USART_RX_RCU RCU_GPIOA

/* 定义 TX 和 RX 对应的 GPIO 接口*/
#define UINIO_USART_TX_PORT GPIOA
#define UINIO_USART_RX_PORT GPIOA

/* 定义 TX 和 RX 对应的 GPIO 引脚*/
#define UINIO_USART_TX_PIN GPIO_PIN_9
#define UINIO_USART_RX_PIN GPIO_PIN_10

void UINIO_USART_GPIO_Config(uint32_t band_rate); // USART 外设资源配置函数
void UINIO_USART_Send_Data(char ucch);            // 用于发送 1 个字节的函数
void UINIO_USART_Send_String(char *ucstr);        // 用于发送字符串的函数

#endif /* UINIO_USART_H */
