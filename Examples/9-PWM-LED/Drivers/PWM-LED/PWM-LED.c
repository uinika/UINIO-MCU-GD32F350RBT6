/*========== PWM_LED.h ==========*/
#include "systick.h"
#include "../PWM-LED/PWM-LED.h"

/** 配置 PWM 功能对应的 GPIO 引脚 */
static void UINIO_PWM_GPIO_Config(void) {
  rcu_periph_clock_enable(UINIO_PWM_RCU);                                                   // 使能 PWM 对应 GPIO 引脚的外设时钟
  gpio_mode_set(UINIO_PWM_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, UINIO_PWM_PIN);               // 配置 GPIO 引脚为悬空的复用功能模式
  gpio_output_options_set(UINIO_PWM_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, UINIO_PWM_PIN); // 设置 GPIO 引脚的输出模式与速率
  gpio_af_set(UINIO_PWM_PORT, UINIO_PWM_AF, UINIO_PWM_PIN);                                 // 设置 GPIO 引脚的复用功能
}

/** 配置脉冲宽度调制 PWM 的工作参数，参数 UINIO_Clock_Prescale 为时钟预分频值，参数 UINIO_Clock_Period 为时钟周期 */
void UINIO_PWM_Config(uint16_t UINIO_Clock_Prescale, uint16_t UINIO_Clock_Period) {
  UINIO_PWM_GPIO_Config();  // 调用 PWM 对应 GPIO 引脚的配置函数

  rcu_periph_clock_enable(UINIO_PWM_TIMER_RCU);  // 使能定时器 TIMER1 外设时钟
  timer_deinit(UINIO_PWM_TIMER);                 // 复位定时器 TIMER1

  /* 配置 PWM 定时器参数 */
  timer_parameter_struct TimerParameter;               // 定义 timer_parameter_struct 定时器参数结构体
  TimerParameter.prescaler = UINIO_Clock_Prescale - 1; // 预分频值，由于该值从 0 开始计数，所以这里需要减去 1
  TimerParameter.alignedmode = TIMER_COUNTER_EDGE;     // 对齐模式，边缘对齐
  TimerParameter.counterdirection = TIMER_COUNTER_UP;  // 计数方向，向上计数
  TimerParameter.period = UINIO_Clock_Period - 1;      // 周期，同样由于该值从 0 开始计数，这里同样需要减去 1
  TimerParameter.clockdivision = TIMER_CKDIV_DIV1;     // 时钟分频因子
  TimerParameter.repetitioncounter = 0;                // 重复计数器值，取值范围为 0 ~ 255，配置为 x 就会重复 x+1 次进入中断
  timer_init(UINIO_PWM_TIMER, &TimerParameter);        // 初始化 PWM 相关的定时器

  /* 配置 PWM 输出通道 */
  timer_oc_parameter_struct TimerOutChannel;                                         // 输出通道配置结构体 timer_oc_parameter_struct
  TimerOutChannel.ocpolarity = TIMER_OC_POLARITY_HIGH;                               // 设置通道输出极性为高电平
  TimerOutChannel.outputstate = TIMER_CCX_ENABLE;                                    // 使能通道输出功能
  timer_channel_output_config(UINIO_PWM_TIMER, UINIO_PWM_CHANNEL, &TimerOutChannel); // 开始配置定时器通道的输出功能

  /* 配置占空比 */
  timer_channel_output_pulse_value_config(UINIO_PWM_TIMER, UINIO_PWM_CHANNEL, 0);                  // 配置定时器输出通道的脉冲值
  timer_channel_output_mode_config(UINIO_PWM_TIMER, UINIO_PWM_CHANNEL, TIMER_OC_MODE_PWM0);        // 配置定时器输出通道的比较模式
  timer_channel_output_shadow_config(UINIO_PWM_TIMER, UINIO_PWM_CHANNEL, TIMER_OC_SHADOW_DISABLE); // 配置定时器输出通道的影子寄存器

  /* 只有高级定时器使用 */
  // timer_primary_output_config(TIMER0,ENABLE);
  timer_auto_reload_shadow_enable(UINIO_PWM_TIMER); // 使能定时器自动重载影子
  timer_enable(UINIO_PWM_TIMER);                    // 使能定时器
}

/** PWM 呼吸灯控制函数 */
void UINIO_PWM_LED_Breathing(void) {
  static uint8_t Direct = 0; // 方向
  static uint16_t Value = 0; // 脉冲值

  /* 逐渐变亮 */
  if (Direct == 0) {
    Value += 300; // 该值越大 LED 越亮
    if (Value > 10000) {
      Direct = 1; // 切换至渐暗模式
    }
  }
  /* 逐渐变暗 */
  else {
    Value -= 300; // 该值越小 LED 越暗
    if (Value <= 0) {
      Direct = 0; // 切换至渐亮模式
    }
  }

  timer_channel_output_pulse_value_config(UINIO_PWM_TIMER, UINIO_PWM_CHANNEL, Value); // 配置定时器通道输出的脉冲值
  delay_1ms(50);                                                                      // 系统滴答定时器延时 50 毫秒
}
