/*========== UINIO_LED.c ==========*/
#include "LED.h"

/* LED 对应 GPIO 引脚的配置函数 */
void UINIO_LED_GPIO_Config(void) {
  rcu_periph_clock_enable(UINIO_LED_RCU);                                                   // 使能 GIPO 外设对应的 RCU 复位和时钟单元
  gpio_mode_set(UINIO_LED_Port, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, UINIO_LED_Pin);           // 配置 GPIO 为浮空输出模式
  gpio_output_options_set(UINIO_LED_Port, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, UINIO_LED_Pin); // 设置 GPIO 的输出模式为推挽输出，速度为 50MHz
}
