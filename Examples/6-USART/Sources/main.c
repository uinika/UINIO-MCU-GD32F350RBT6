/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include "main.h"
#include <stdio.h>

#include "../Drivers/USART/USART.h"

int main(void) {
  UINIO_USART_GPIO_Config(9600U);  // 配置 USART0，并将波特率设置为 9600

  unsigned short count1 = 0;       // 声明短整型测试变量 count1
  float count2 = 0.0;              // 声明浮点型测试变量 count2

  while (1) {
    /* 依次发送单个字符 `H` `a` `n` `k` */
    UINIO_USART_Send_Data('H');
    UINIO_USART_Send_Data('a');
    UINIO_USART_Send_Data('n');
    UINIO_USART_Send_Data('k');
    UINIO_USART_Send_Data('\n');

    UINIO_USART_Send_String("UinIO.com\n");                   // 发送字符串 UinIO.com
    
    /* 测试 printf() 串口打印重定向 */
    count1++;                                                 // 短整型测试变量自增 1
    count2 += 1.0F;                                           // 浮点型测试变量自增 1
    printf("count1 = %d, count2 = %.2f \n", count1, count2);  // 向 USART 串行接口打印格式化信息
  }
}
