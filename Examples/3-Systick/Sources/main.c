/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"
#include "../Drivers/SysTick/SysTick.h"

int main(void) {
    systick_config();  // 初始化系统滴答定时器
    LED_GPIO_Config(); // 初始化 LED 相关的 GPIO 引脚

    while(1) {
        gpio_bit_write(PORT_LED, PIN_LED, SET);      // GPIOB8 输出高电平
        SysTick_Delay_MS(1000);
        gpio_bit_write(PORT_LED, PIN_LED, RESET);    // GPIOB8 输出低电平
        SysTick_Delay_US(1000000);
    }
}