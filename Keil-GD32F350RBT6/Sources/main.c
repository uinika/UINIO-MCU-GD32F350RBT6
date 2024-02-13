/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"

int main(void) {
    systick_config();  // ����ϵͳ�δ�ʱ��
    LED_GPIO_Config(); // �������� LED �� GPIO �˿�

    /* �˿�������ƼĴ��� GPIOB_OCTL ��ʽ���� LED */
    Driver_GPIOB_OCTL &= ~(0x01 << 8);      // ����͵�ƽ��LED Ϩ��
    Driver_GPIOB_OCTL |=  (0x01 << 8);      // ����ߵ�ƽ��LED ����

    /* �˿�λ�����Ĵ��� GPIOB_BOP ��ʽ���� LED */
    Driver_GPIOB_BOP |= (0x01 << (8 + 16)); // ����͵�ƽ��LED Ϩ��
    Driver_GPIOB_BOP |= (0x01 << 8);        // ����ߵ�ƽ��LED ����

    while(1) {}
}