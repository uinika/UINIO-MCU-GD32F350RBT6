/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"
#include "../Drivers/SysTick/SysTick.h"

int main(void) {
    systick_config();  // ��ʼ��ϵͳ�δ�ʱ��
    LED_GPIO_Config(); // ��ʼ�� LED ��ص� GPIO ����

    while(1) {
        gpio_bit_write(PORT_LED, PIN_LED, SET);      // GPIOB8 ����ߵ�ƽ
        SysTick_Delay_MS(1000);
        gpio_bit_write(PORT_LED, PIN_LED, RESET);    // GPIOB8 ����͵�ƽ
        SysTick_Delay_US(1000000);
    }
}