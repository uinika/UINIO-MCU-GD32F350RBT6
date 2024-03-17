/*========== LED.h ==========*/
#ifndef UINIO_Driver_LED_H
#define UINIO_Driver_LED_H

#include "gd32f3x0.h"
#include "systick.h"

#define UINIO_RCU_BASE (unsigned int)0x40021000U                      // RCU 寄存器的基地址
#define UINIO_RCU_AHBEN *(unsigned int *)(UINIO_RCU_BASE + 0x14U)     // AHB 使能寄存器地址

#define UINIO_GPIOB_BASE (unsigned int)0x48000400U                    // GPIOB 的基地址
#define UINIO_GPIOB_CTL *(unsigned int *)(UINIO_GPIOB_BASE + 0x00U)   // GPIOB 控制寄存器的地址
#define UINIO_GPIOB_PUD *(unsigned int *)(UINIO_GPIOB_BASE + 0x0CU)   // GPIOB 的上下拉寄存器的地址
#define UINIO_GPIOB_OMODE *(unsigned int *)(UINIO_GPIOB_BASE + 0x04U) // GPIOB 的输出模式寄存器的地址
#define UINIO_GPIOB_OSPD *(unsigned int *)(UINIO_GPIOB_BASE + 0x08U)  // GPIOB 的速度寄存器的地址
#define UINIO_GPIOB_OCTL *(unsigned int *)(UINIO_GPIOB_BASE + 0x14U)  // GPIOB 的输出控制寄存器的地址
#define UINIO_GPIOB_BOP *(unsigned int *)(UINIO_GPIOB_BASE + 0x18U)   // GPIOB 的位操作寄存器的地址

void UINIO_LED_GPIO_Config(void); // LED 相关的 GPIO 端口配置函数

#endif /* UINIO_Driver_LED_H */
