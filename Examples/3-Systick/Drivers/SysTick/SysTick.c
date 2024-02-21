#include "SysTick.h"

/* ΢�뼶��ʱ������ us �ĵ�λΪ΢�� */
void SysTick_Delay_US (__IO uint32_t us) {
    uint32_t index;
    SysTick_Config(SystemCoreClock/1000000U);         // ���� core_cm4.h ͷ�ļ��ж���� SysTick_Config() ����

    for (index = 0; index < us; index++) {
        while ( !((SysTick->CTRL) & (1UL << 16)) );  // ������ֵ��С�� 0 ʱ��CRTL �Ĵ�����Ӧ��λ�ᱻ��Ϊ 1
    }

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;       // ʧ�� SysTick ϵͳ�δ�ʱ��
}

/* ���뼶��ʱ������ ms �ĵ�λΪ���� */
void SysTick_Delay_MS (__IO uint32_t ms) {
    uint32_t index;
    SysTick_Config(SystemCoreClock/1000U);            // ���� core_cm4.h ͷ�ļ��ж���� SysTick_Config() ����

    for (index = 0; index < ms; index++) {
        while ( !((SysTick->CTRL) & (1UL << 16)) );  // ������ֵ��С�� 0 ʱ��CRTL �Ĵ�����Ӧ��λ�ᱻ��Ϊ 1
    }

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;       // ʧ�� SysTick ϵͳ�δ�ʱ��
}