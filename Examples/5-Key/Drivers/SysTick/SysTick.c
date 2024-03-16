#include "SysTick.h"

/* 微秒级延时，参数 us 的单位为微秒 */
void SysTick_Delay_US (__IO uint32_t us) {
  uint32_t index;
  SysTick_Config(SystemCoreClock/1000000U);      // 调用 core_cm4.h 头文件中定义的 SysTick_Config() 函数

  for (index = 0; index < us; index++) {
    while ( !((SysTick->CTRL) & (1UL << 16)) );  // 当计数值减小到 0 时，CRTL 寄存器相应的位会被置为 1
  }

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;     // 失能 SysTick 系统滴答定时器
}

/* 毫秒级延时，参数 ms 的单位为毫秒 */
void SysTick_Delay_MS (__IO uint32_t ms) {
  uint32_t index;
  SysTick_Config(SystemCoreClock/1000U);         // 调用 core_cm4.h 头文件中定义的 SysTick_Config() 函数

  for (index = 0; index < ms; index++) {
    while ( !((SysTick->CTRL) & (1UL << 16)) );  // 当计数值减小到 0 时，CRTL 寄存器相应的位会被置为 1
  }

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;     // 失能 SysTick 系统滴答定时器
}
