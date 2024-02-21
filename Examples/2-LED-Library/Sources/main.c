/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "../Drivers/LED/LED.h"

int main(void) {
    systick_config();  // 初始化系统滴答定时器
    LED_GPIO_Config(); // 初始化 LED 相关的 GPIO 引脚

    gpio_bit_set(GPIOB, GPIO_PIN_8);             // GPIOB8 输出高电平
    gpio_bit_reset(GPIOB, GPIO_PIN_8);           // GPIOB8 输出低电平

    gpio_bit_write(PORT_LED, PIN_LED, RESET);    // GPIOB8 输出低电平
    gpio_bit_write(PORT_LED, PIN_LED, SET);      // GPIOB8 输出高电平

    while(1) {}
}