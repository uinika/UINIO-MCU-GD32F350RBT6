/*========== LED.c ==========*/
#include "LED.h"

void LED_GPIO_Config(void) {
    rcu_periph_clock_enable(RCU_LED);                                             // ʹ�� RCU ��λ��ʱ�ӵ�Ԫ
    gpio_mode_set(PORT_LED, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED);           // ���ø������ģʽ
    gpio_output_options_set(PORT_LED, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED); // ��������������ͣ�50MHz ����
}