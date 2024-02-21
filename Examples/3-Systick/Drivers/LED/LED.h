/*========== LED.h ==========*/
#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "gd32f3x0.h"
#include "systick.h"

#define RCU_LED RCU_GPIOB    // GPIOB ʱ��
#define PORT_LED GPIOB       // GPIOB �˿�
#define PIN_LED GPIO_PIN_8   // GPIOB ����

void LED_GPIO_Config(void);  // ���� LED ������ GPIO ����

#endif /* BSP_LED_H */