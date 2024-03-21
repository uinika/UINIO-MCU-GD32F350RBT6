#include "USART.h"
#include "stdio.h"

/** 配置 USART 相关的 GPIO，参数 band_rate 是波特率 */
void UINIO_USART_GPIO_Config(uint32_t band_rate) {
  /* 开启时钟 */
  rcu_periph_clock_enable(UINIO_USART_TX_RCU); // 使能 TX 对应 GPIO 引脚的时钟
  rcu_periph_clock_enable(UINIO_USART_RX_RCU); // 使能 RX 对应 GPIO 引脚的时钟
  rcu_periph_clock_enable(UINIO_USART_RCU);    // 使能 USART 外设时钟

  /* 配置 GPIO 引脚的复用功能 */
  gpio_af_set(UINIO_USART_TX_PORT, UINIO_USART_AF, UINIO_USART_TX_PIN);
  gpio_af_set(UINIO_USART_RX_PORT, UINIO_USART_AF, UINIO_USART_RX_PIN);

  /* 配置 TX 和 RX 对应 GPIO 引脚的模式与速度 */
  gpio_mode_set(UINIO_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UINIO_USART_TX_PIN);             // 配置 TX 引脚为带上拉电阻的复用模式
  gpio_output_options_set(UINIO_USART_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, UINIO_USART_TX_PIN); // 配置 TX 引脚为推挽输出，速率为 50MHZ
  gpio_mode_set(UINIO_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UINIO_USART_RX_PIN);             // 配置 RX 引脚为带上拉电阻的复用模式
  gpio_output_options_set(UINIO_USART_RX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, UINIO_USART_RX_PIN); // 配置 RX 引脚为推挽输出，速率为 50MHZ

  /* 配置 USART 串行通信的参数 */
  usart_deinit(UINIO_USART);                         // 复位 USART 外设
  usart_baudrate_set(UINIO_USART, band_rate);        // 设置 USART 波特率
  usart_parity_config(UINIO_USART, USART_PM_NONE);   // 设置 USART 奇偶校验位
  usart_word_length_set(UINIO_USART, USART_WL_8BIT); // 设置 USART 数据位长度为 8 位
  usart_stop_bit_set(UINIO_USART, USART_STB_1BIT);   // 设置 USART 停止位长度为 1 位

  /* 使能和配置 USART串口 */
  usart_transmit_config(UINIO_USART, USART_TRANSMIT_ENABLE); // 使能 USART 发送功能
  usart_enable(UINIO_USART);                                 // 使能 USART 串口
}

/** 通过 USART 发送一个字节 */
void UINIO_USART_Send_Data(char data) {
  usart_data_transmit(UINIO_USART, (uint8_t)data);              // 通过 USART 发送数据
  while (RESET == usart_flag_get(UINIO_USART, USART_FLAG_TBE)); // 通过发送数据缓冲区空标志位来判断发送是否完成
}

/** 通过 USART 发送字符串 */
void UINIO_USART_Send_String(char *string) {
  /* 开始循环发送，当字符串为空或者指针地址为空时跳出 */
  while (string && *string) {
    UINIO_USART_Send_Data(*string++);  // 调用上面的函数，循环发送单个字符
  }
}

/** 通过重写 C 语言 printf() 不断循环调用的 fputc() 函数，实现串口数据输出的重定向 */
int fputc(int character, FILE *stream) {
  UINIO_USART_Send_Data(character);    // 调用上面的函数，发送单个字符
  return character;
}
