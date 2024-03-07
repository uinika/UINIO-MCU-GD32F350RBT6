#define BITBAND(address, bit_number) ((address & 0xF0000000) + 0x02000000 + ((address & 0x00FFFFFF) << 5) + (bit_number << 2)) // 将位带区地址和位序号转换为位带别名区地址
#define ADDRESS_POINTER(address)         *((volatile unsigned long  *)(address))                                               // 将地址转换为 unsigned long 类型指针
#define BIT_ADDRESS(address, bit_number) ADDRESS_POINTER(BITBAND(address, bit_number))                                         // 使用前面定义的宏定义语句 BITBAND()，将位带别名区地址转换为指针

/* 端口输出控制寄存器 GPIOx_OCTL 地址 */
#define GPIOA_OCTL_ADDRESS (GPIOA + 0x14)
#define GPIOB_OCTL_ADDRESS (GPIOB + 0x14)
#define GPIOC_OCTL_ADDRESS (GPIOC + 0x14)
#define GPIOD_OCTL_ADDRESS (GPIOD + 0x14)
#define GPIOE_OCTL_ADDRESS (GPIOE + 0x14)
#define GPIOF_OCTL_ADDRESS (GPIOF + 0x14)

/* 端口输入状态寄存器 GPIOx_ISTAT 地址 */
#define GPIOA_ISTAT_ADDRESS (GPIOA + 0x10)
#define GPIOB_ISTAT_ADDRESS (GPIOB + 0x10)
#define GPIOC_ISTAT_ADDRESS (GPIOC + 0x10)
#define GPIOD_ISTAT_ADDRESS (GPIOD + 0x10)
#define GPIOE_ISTAT_ADDRESS (GPIOE + 0x10)
#define GPIOF_ISTAT_ADDRESS (GPIOF + 0x10)

/* 控制 GPIOA 的输入与输出 */
#define GPIOA_Out(number) BIT_ADDRESS(GPIOA_OCTL_ADDRESS, number)
#define GPIOA_In(number)  BIT_ADDRESS(GPIOA_ISTAT_ADDRESS, number)

/* 控制 GPIOB 的输入与输出 */
#define GPIOB_Out(number) BIT_ADDRESS(GPIOB_OCTL_ADDRESS, number)
#define GPIOB_In(number)  BIT_ADDRESS(GPIOB_ISTAT_ADDRESS, number)

/* 控制 GPIOC 的输入与输出 */
#define GPIOC_Out(number) BIT_ADDRESS(GPIOC_OCTL_ADDRESS, number)
#define GPIOC_In(number)  BIT_ADDRESS(GPIOC_ISTAT_ADDRESS, number)

/* 控制 GPIOD 的输入与输出 */
#define GPIOD_Out(number) BIT_ADDRESS(GPIOD_OCTL_ADDRESS, number)
#define GPIOD_In(number)  BIT_ADDRESS(GPIOD_ISTAT_ADDRESS, number)

/* 控制 GPIOF 的输入与输出 */
#define GPIOF_Out(number) BIT_ADDRESS(GPIOF_OCTL_ADDRESS, number)
#define GPIOF_In(number)  BIT_ADDRESS(GPIOF_ISTAT_ADDRESS, number)