/*========== SysTick.h ==========*/
#ifndef SysTick_H
#define SysTick_H
#include "gd32f3x0.h"

void SysTick_Delay_US(__IO uint32_t us); // ΢�뼶��ʱ������ us �ĵ�λΪ΢��
void SysTick_Delay_MS(__IO uint32_t ms); // ���뼶��ʱ������ ms �ĵ�λΪ����

#endif /* SysTick_H */