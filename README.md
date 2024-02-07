# UINIO-MCU-GD32F350RBT6 核心板

[**UINIO-MCU-GD32F350RBT6**](https://gitee.com/uinika/UINIO-MCU-GD32F350RBT6) 是一款基于 [**兆易创新**](https://www.gigadevice.com.cn/) 国产 **LQFP64** 封装的 **GD32F350RBT6** 微控制器的核心板电路设计，该微控制器基于 **ARM Cortex-M4** 内核架构，主频高达 `108MHz`，片上载有 `128K` 容量的 Flash 存储器，以及 `16K` 的 SRAM 存储器，并且各拥有 2 组 `USART`、`I2C`、`SPI`，以及 1 组 `I2S`、`12 位 ADC`、`12 位 DAC`，同时支持 **USB 2.0 FS OTG** 协议，总体上属于 GPIO 引脚数量较多，但是外设资源有所取舍的主控芯片产品。

![](./Images/PCB-3D-1.png)

![](./Images/PCB-3D-2.png)

> **注意**：相比较于采用 **ARM Cortex-M3** 内核架构的 **GD32F103C8T6** 等产品，使用 **ARM Cortex-M4** 内核的 **GD32F350RBT6** 携带有浮点计算单元（**FPU**，Float Point Unit），在处理数学计算时能够大幅度提升运算性能。

## 启动配置

**UINIO-MCU-STM32F401CCU6** 通过板载 `BOOT0` 按钮和**用户选项字节** `BOOT1_n` 位来配置启动方式，默认情况下是从片上的 Flash 闪存进行启动，具体的配置信息可以参见下表：

| BOOT0 | BOOT1_n | 启动方式                 |
| :---: | :-----: | :----------------------- |
|  `0`  |   `X`   | 片上 Flash 闪存          |
|  `1`  |   `0`   | 系统存储器/ISP           |
|  `1`  |   `1`   | 片上 SRAM 静态随机存储器 |

## 设计概要

1. 引出了兆易创新 **GD32F350RBT6** 型微控制器上面的全部 GPIO 引脚资源；
2. 单独提供有四线制的 **SWD** 下载接口，便于快速与 [UINIO-DAP-Link](http://uinio.com/Project/UINIO-DAP-Link) 建立连接；
3. 分别使用了 `8MHz` 与 `32.768KHz` 两枚贴片晶振作为系统外部时钟与实时时钟；
4. 板载一枚 **BOOT0** 启动配置按钮，以及一枚 **NRST** 复位按钮；
5. 模拟电源引脚 `VDDA` 使用了对 `100Mhz` 高频杂散信号存在 `1KΩ` 阻抗的**磁珠**进行单点接地；

## 参考技术文档

[UinIO.com 电子技术实验室](http://uinio.com/) 为 UINIO-MCU-GD32F103CBT6 开源项目提供了如下一系列技术参考资料：

1. [《兆易创新 UINIO-MCU-GD32 标准库开发指南》](http://uinio.com/Project/UINIO-MCU-GD32/)
2. [《ARM 调试工具 UINIO-DAP-Link 应用详解》](http://uinio.com/Project/UINIO-DAP-Link/)
3. [《BOM 交互式物料清单与 PCB 布线在线预览》](http://uinio.com/archives/BOM/UINIO-MCU-GD32F350RBT6.html)
