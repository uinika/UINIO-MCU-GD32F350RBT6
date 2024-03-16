/*========== UINIO_LED.c ==========*/
#include "LED.h"

/* LED 对应 GPIO 引脚的配置函数 */
void UINIO_LED_GPIO_Config(void) {
  rcu_periph_clock_enable(UINIO_RCU_LED);                                             // 使能 RCU 复位和时钟单元
  gpio_mode_set(UINIO_PORT_LED, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, UINIO_PIN_LED);           // 配置浮空输出模式
  gpio_output_options_set(UINIO_PORT_LED, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, UINIO_PIN_LED); // 设置推挽输出类型，50MHz 速率
}
