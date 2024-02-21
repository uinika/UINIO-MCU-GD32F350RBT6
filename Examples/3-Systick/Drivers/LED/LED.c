/*========== LED.c ==========*/
#include "LED.h"

void LED_GPIO_Config(void) {
    rcu_periph_clock_enable(RCU_LED);                                             // 使能 RCU 复位和时钟单元
    gpio_mode_set(PORT_LED, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED);           // 配置浮空输出模式
    gpio_output_options_set(PORT_LED, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED); // 设置推挽输出类型，50MHz 速率
}