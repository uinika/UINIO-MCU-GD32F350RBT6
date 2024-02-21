/*========== LED.c ==========*/
#include "LED.h"

/* LED ��ص� GPIO �˿����ú��� */
void LED_GPIO_Config(void) {
    /* AHB ����ʹ�ܼĴ��� RCU_AHBEN */
    Driver_RCU_AHBEN |= (0x01 << 18);         // RCU_AHBEN �Ĵ����ĵ� 18 λ��Ϊ 1

    /* ���ö˿ڿ��ƼĴ��� GPIOB_CTL */
    Driver_GPIOB_CTL &= ~(0x03 << (2*8));     // �� GPIOB_CTL �ĵ� 17 �� 16 λ��Ϊ 00
    Driver_GPIOB_CTL |= (0x01 << (2*8));      // ���� GPIOB_CTL �ĵ� 17 �� 16 λΪ 01

    /* ���ö˿��������Ĵ��� GPIOB_PUD */
    Driver_GPIOB_PUD &= ~(0x03 << (2 * 8));   // �� GPIOB_PUD �ĵ� 17 �� 16 λ����
    Driver_GPIOB_PUD |= (0x00 << (2 * 8));    // ���� GPIOB_PUD �ĵ� 17 �� 16 λΪ 00

    /* �˿����ģʽ�Ĵ��� GPIOB_OMODE */
    Driver_GPIOB_OMODE &= ~(0x01 << 8);       // �� GPIOB_OMODE �ĵ� 8 λ��Ϊ 0

    /* �˿��ٶȼĴ��� GPIOB_OSPD */
    Driver_GPIOB_OSPD &=  (0x03 << (2 * 8));  // �� GPIOB_OSPD �ĵ� 17 �� 16 λд�� 11
}