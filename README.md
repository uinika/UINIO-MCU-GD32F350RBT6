# UINIO-MCU-GD32F350RBT6 评估板

这是一款基于 [**兆易创新**](https://www.gigadevice.com.cn/) 国产 **LQFP64** 封装的 **GD32F350RBT6** 微控制器评估板电路设计，该微控制器基于 **ARM Cortex-M4** 内核，主频高达 `108MHz`，片上载有 `128K` 容量的 Flash 存储器，以及 `16K` 的 SRAM 存储器，并且各拥有两组 `USART`、`I2C`、`SPI`，以及一组 `I2S`、`12 位 ADC`、`12 位 DAC`，同时支持 **USB 2.0 FS OTG**。

![](./Images/PCB-3D-1.png)

![](./Images/PCB-3D-2.png)

## 开发板简介

1. 引出了 **GD32F350RBT6** 芯片上的全部引脚资源；
2. **VSSA** 模拟地引脚使用了 `1KΩ 100Mhz` 的磁珠进行单点接地；
3. 使用 `8MHz` 与 `32.768KHz` 两枚贴片晶振，并且分别进行了简单的**包地**处理；
4. 已经将 MCU 的 **USB 2.0 FS OTG** 连接至 USB Type-C 接口，并且加入用于 USB 枚举的 `1.5 KΩ` 上拉电阻，并且进行了**等长布线**；
5. 单独提供了 4 线制的 **SWD** 下载接口，便于调试的时候快速进行连接；
