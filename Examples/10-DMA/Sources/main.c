/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "../Drivers/USART/USART.h"

#define GetArrayNumber(arr_nanme)  (uint32_t)(sizeof(arr_nanme) / sizeof(*(arr_nanme)))

uint8_t UINIO_String[] = "UinIO.com : Copy current string from RAM to USART by DMA.\n"; // 需要通过 DMA 传输给 USART 的字符串
__IO FlagStatus UINIO_Transfer_Complete = RESET;                                        // 固件库中预定义的枚举类型变量，取值为 SET 或者 RESET

int main(void) {
  UINIO_USART_GPIO_Config(9600U);             // 调用 USART 串口配置函数

  rcu_periph_clock_enable(RCU_DMA);           // 使能 DMA 相关的外部时钟
  nvic_irq_enable(DMA_Channel1_2_IRQn, 0, 0); // 配置 DMA 中断服务程序

  /* 初始化 DMA 通道 */
  dma_deinit(DMA_CH1);
  dma_parameter_struct DMA_Init_Struct;
  DMA_Init_Struct.direction    = DMA_MEMORY_TO_PERIPHERAL;         // 设置 DMA 通道数据传输方向为【读取存储器写入外设】
  DMA_Init_Struct.memory_addr  = (uint32_t)UINIO_String;           // 设置存储器基地址为字符串首地址
  DMA_Init_Struct.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;       // 配置外设地址生成算法模式为递增
  DMA_Init_Struct.memory_width = DMA_MEMORY_WIDTH_8BIT;            // 存储器数据传输宽度为 8 位（串口每次传送 1 个字节 8 位）
  DMA_Init_Struct.number       = GetArrayNumber(UINIO_String);     // 设置 DMA 通道数据传输量
  DMA_Init_Struct.periph_addr  = (uint32_t)(&USART_TDATA(USART0)); // 设置外设基地址
  DMA_Init_Struct.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;      // 设置外设地址生成算法为固定地址模式
  DMA_Init_Struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;        // 外设数据传输宽度为 8 位
  DMA_Init_Struct.priority     = DMA_PRIORITY_ULTRA_HIGH;          // 配置 DMA 传输通道优先级为最高
  dma_init(DMA_CH1, &DMA_Init_Struct);                             // 开始初始化 DMA 通道 1

  /* 配置 DMA 模式 */
  dma_circulation_disable(DMA_CH1);      // 禁用 DMA 循环模式
  dma_memory_to_memory_disable(DMA_CH1); // 禁用存储器到存储器的 DMA 传输

  usart_dma_transmit_config(USART0, USART_DENT_ENABLE); // 使能串口 USART0 的 DMA 发送功能
  dma_interrupt_enable(DMA_CH1, DMA_INT_FTF);           // 使能 DMA1 通道传输完成中断
  dma_channel_enable(DMA_CH1);                          // 使能 DMA1 通道本身

  /* 等待传输完成 */
  while(RESET == UINIO_Transfer_Complete);
}
