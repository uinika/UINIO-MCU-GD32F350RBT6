/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"

int main(void) {
    systick_config();  // ��ʼ��ϵͳ�δ�ʱ��
    LED_GPIO_Config(); // ��ʼ�� LED ��ص� GPIO ����

    gpio_bit_set(GPIOB, GPIO_PIN_8);             // GPIOB8 ����ߵ�ƽ
    gpio_bit_reset(GPIOB, GPIO_PIN_8);           // GPIOB8 ����͵�ƽ

    gpio_bit_write(PORT_LED, PIN_LED, RESET);    // GPIOB8 ����͵�ƽ
    gpio_bit_write(PORT_LED, PIN_LED, SET);      // GPIOB8 ����ߵ�ƽ

    while(1) {}
}