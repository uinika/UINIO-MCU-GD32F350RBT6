/*========== ADC.c ==========*/
#include "stdio.h"
#include "ADC.h"

/** ADC 外设配置函数 */
void UINIO_ADC_Config(void) {
  rcu_periph_clock_enable(RCU_GPIOC);         // 使能 GPIOC 外设时钟
  rcu_periph_clock_enable(RCU_ADC);           // 使能 ADC 外设时钟
  rcu_adc_clock_config(RCU_ADCCK_APB2_DIV4);  // 选择 APB 总线频率的 4 分频作为 ADC 的时钟源

  gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1);  // 配置 GPIOC1 为不带上下拉电阻的模拟输入模式

  adc_special_function_config(ADC_SCAN_MODE, ENABLE);        // 使能 ADC 特殊功能的扫描模式
  adc_data_alignment_config(ADC_DATAALIGN_RIGHT);            // 配置 ADC 数据对齐方式为右对齐
  adc_resolution_config(ADC_RESOLUTION_12B);                 // 配置 ADC 分辨率为 12 位
  adc_channel_length_config(ADC_REGULAR_CHANNEL, 1);         // 配置规则通道组的通道长度为 1
  adc_external_trigger_config(ADC_REGULAR_CHANNEL, DISABLE); // 失能 ADC 外部触发，即只能通过软件触发

  adc_enable();             // 使能 ADC 外设
  adc_calibration_enable(); // 使能 ADC 校准
}

/** 获取 ADC 的值，参数 ADC_CHANNEL_x 用于指定采集通道 */
unsigned int UINIO_ADC_Value(uint8_t  ADC_CHANNEL_x) {

  adc_regular_channel_config(0, ADC_CHANNEL_x, ADC_SAMPLETIME_1POINT5); // 配置 ADC 规则通道组，选择通道 0，并且指定采样时间为 1.5 个周期
  adc_software_trigger_enable(ADC_REGULAR_CHANNEL);                     // 使能 ADC 软件触发功能

  /* 根据 ADC 状态标志位，等待 ADC 采样完成 */
  while ( adc_flag_get(ADC_FLAG_EOC) == RESET ) {}

  unsigned int ADC_Value = adc_regular_data_read(); // 读 ADC 规则组的采样数据
  return ADC_Value;                                 // 返回 ADC 采样数据
}
