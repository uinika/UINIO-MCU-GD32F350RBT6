/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"
#include "../Drivers/SysTick/SysTick.h"
#include "../Drivers/BitBand/BitBand.h"

int main(void) {
    systick_config();  // ��ʼ��ϵͳ�δ�ʱ��
    LED_GPIO_Config(); // ��ʼ�� LED ��ص� GPIO ����

    while(1) {
        GPIOB_Out(8) = 1;      // GPIOB8 ����ߵ�ƽ
        SysTick_Delay_MS(1000);
        GPIOB_Out(8) = 0;      // GPIOB8 ����͵�ƽ
        SysTick_Delay_MS(1000);
    }
}