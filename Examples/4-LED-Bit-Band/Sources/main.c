/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"
#include "../Drivers/SysTick/SysTick.h"

/* ƫ���� = GPIOB ����ַ 0x48000400 + GPIOx_OCTL ƫ���� 0x14 - Ƭ��������ʼ��ַ 0x40000000 */
#define GPIOB_OCTL_OFFSET ((GPIOB + 0x14) - 0x40000000)

/* λ�����������ֵ�ַ = λ����������ʼ��ַ + (λ����Ŀ��λ�����ֽڵĵ�ַƫ���� �� 32) + (Ŀ��λ�ڶ�Ӧ�ֽڵ��е�λ�� �� 4) */
#define BIT_ADDRESS(byte_offset, bit_number) (volatile unsigned long *)(0x42000000 + (byte_offset << 5) + (bit_number << 2))

/* ���� GPIOB �˿�ָ�����ŵ����״̬������ GPIOB_OUT(8) */
#define GPIOB_OUT(number) *(BIT_ADDRESS(GPIOB_OCTL_OFFSET, number))

int main(void) {
    systick_config();  // ��ʼ��ϵͳ�δ�ʱ��
    LED_GPIO_Config(); // ��ʼ�� LED ��ص� GPIO ����

    while(1) {
        GPIOB_OUT(8) = 1;      // GPIOB8 ����ߵ�ƽ
        delay_1ms(1000);
        GPIOB_OUT(8) = 0;      // GPIOB8 ����͵�ƽ
        delay_1ms(1000);
    }
}