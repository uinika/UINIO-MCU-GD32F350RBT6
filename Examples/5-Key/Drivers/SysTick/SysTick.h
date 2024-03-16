/*========== SysTick.h ==========*/
#ifndef SysTick_H
#define SysTick_H
#include "gd32f3x0.h"

void SysTick_Delay_US(__IO uint32_t us); // 微秒级延时，参数 us 的单位为微秒
void SysTick_Delay_MS(__IO uint32_t ms); // 毫秒级延时，参数 ms 的单位为毫秒

#endif /* SysTick_H */
