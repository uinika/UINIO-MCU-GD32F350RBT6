/*========== LED.h ==========*/
#ifndef _Driver_LED_H
#define _Driver_LED_H

#include "gd32f3x0.h"
#include "systick.h"

#define Driver_RCU_BASE (unsigned int)0x40021000U                       // RCU �Ĵ����Ļ���ַ
#define Driver_RCU_AHBEN *(unsigned int *)(Driver_RCU_BASE + 0x14U)     // AHB ʹ�ܼĴ�����ַ

#define Driver_GPIOB_BASE (unsigned int)0x48000400U                     // GPIOB �Ļ���ַ
#define Driver_GPIOB_CTL *(unsigned int *)(Driver_GPIOB_BASE + 0x00U)   // GPIOB ���ƼĴ����ĵ�ַ
#define Driver_GPIOB_PUD *(unsigned int *)(Driver_GPIOB_BASE + 0x0CU)   // GPIOB ���������Ĵ����ĵ�ַ
#define Driver_GPIOB_OMODE *(unsigned int *)(Driver_GPIOB_BASE + 0x04U) // GPIOB �����ģʽ�Ĵ����ĵ�ַ
#define Driver_GPIOB_OSPD *(unsigned int *)(Driver_GPIOB_BASE + 0x08U)  // GPIOB ���ٶȼĴ����ĵ�ַ
#define Driver_GPIOB_OCTL *(unsigned int *)(Driver_GPIOB_BASE + 0x14U)  // GPIOB ��������ƼĴ����ĵ�ַ
#define Driver_GPIOB_BOP *(unsigned int *)(Driver_GPIOB_BASE + 0x18U)   // GPIOB ��λ�����Ĵ����ĵ�ַ

void LED_GPIO_Config(void); // LED ��ص� GPIO �˿����ú���

#endif /* _Driver_LED_H */