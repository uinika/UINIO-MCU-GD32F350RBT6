/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "stdio.h"
#include "systick.h"

#include "../Drivers/ADC/ADC.h"
#include "../Drivers/USART/USART.h"

int main(void) {
  systick_config();               // 初始化系统滴答定时器
  UINIO_USART_GPIO_Config(9600U); // 配置 USART0，并将波特率设置为 9600
  UINIO_ADC_Config();             // 配置 ADC 外设

  uint16_t Voltage = 0;           // ADC 采集到的原始值（0 ~ 4095）

  while(1) {
    Voltage = UINIO_ADC_Value(ADC_CHANNEL_11);

    /* 通过串口打印出实际电压值 */
    printf("ADC_Value = %f\n",(( Voltage / 4095.0 ) * 3.3) ); // 接入 3.3V 采集的 ADC 值为 4095，接入 GND 采集的 ADC 值为 0

    delay_1ms(1000); // 延时 1 秒
  }
}
