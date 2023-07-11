# UINIO-MCU-GD32F350RBT6 评估板

[**UINIO-MCU-GD32F350RBT6**](https://github.com/uinika/UINIO-MCU-GD32F350RBT6) 是一款基于 [**兆易创新**](https://www.gigadevice.com.cn/) 国产 **LQFP64** 封装的 **GD32F350RBT6** 微控制器的核心板电路设计，该微控制器基于 **ARM Cortex-M4** 内核架构，主频高达 `108MHz`，片上载有 `128K` 容量的 Flash 存储器，以及 `16K` 的 SRAM 存储器，并且拥有 2 组 `USART`、`I2C`、`SPI`，以及 1 组 `I2S`、`12 位 ADC`、`12 位 DAC`，同时支持 **USB 2.0 FS OTG** 协议。

![](./Images/PCB-3D-1.png)

![](./Images/PCB-3D-2.png)

## 开发板简介

1. 引出了 **GD32F350RBT6** 芯片上的全部 GPIO 引脚资源
2. **VSSA** 模拟地引脚使用了 `1KΩ 100Mhz` 的磁珠进行单点接地；
3. 单独提供有 4 线制 **SWD** 下载接口，便于快速与 **DAP-Link** 进行连接；
4. 使用 `8MHz` 与 `32.768KHz` 两枚贴片晶振，并且分别进行了简单的**包地**处理；
5. 主控芯片的 **USB 2.0 FS OTG** 被连接至 **USB Type-C** 接口，并且加入用于 USB 枚举的 `1.5 KΩ` 上拉电阻；
