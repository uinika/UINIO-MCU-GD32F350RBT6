/*========== SysTick.h ==========*/
#ifndef UINIO_SysTick_H
#define UINIO_SysTick_H
#include "gd32f3x0.h"

void UINIO_SysTick_Delay_us(__IO uint32_t us); // 微秒级延时，参数 us 的单位为微秒
void UINIO_SysTick_Delay_ms(__IO uint32_t ms); // 毫秒级延时，参数 ms 的单位为毫秒

#endif /* UINIO_SysTick_H */
