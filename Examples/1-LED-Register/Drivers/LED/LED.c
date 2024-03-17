/*========== LED.c ==========*/
#include "LED.h"

/* LED 相关的 GPIO 端口配置函数 */
void UINIO_LED_GPIO_Config(void) {
  /* AHB 总线使能寄存器 RCU_AHBEN */
  UINIO_RCU_AHBEN |= (0x01 << 18);         // RCU_AHBEN 寄存器的第 18 位置为 1

  /* 配置端口控制寄存器 GPIOB_CTL */
  UINIO_GPIOB_CTL &= ~(0x03 << (2*8));     // 把 GPIOB_CTL 的第 17 和 16 位置为 00
  UINIO_GPIOB_CTL |= (0x01 << (2*8));      // 配置 GPIOB_CTL 的第 17 和 16 位为 01

  /* 配置端口上下拉寄存器 GPIOB_PUD */
  UINIO_GPIOB_PUD &= ~(0x03 << (2 * 8));   // 将 GPIOB_PUD 的第 17 和 16 位清零
  UINIO_GPIOB_PUD |= (0x00 << (2 * 8));    // 配置 GPIOB_PUD 的第 17 和 16 位为 00

  /* 端口输出模式寄存器 GPIOB_OMODE */
  UINIO_GPIOB_OMODE &= ~(0x01 << 8);       // 将 GPIOB_OMODE 的第 8 位置为 0

  /* 端口速度寄存器 GPIOB_OSPD */
  UINIO_GPIOB_OSPD &=  (0x03 << (2 * 8));  // 向 GPIOB_OSPD 的第 17 和 16 位写入 11
}
