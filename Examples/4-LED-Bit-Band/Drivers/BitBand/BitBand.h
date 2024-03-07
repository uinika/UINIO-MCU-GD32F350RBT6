#define BITBAND(address, bit_number) ((address & 0xF0000000) + 0x02000000 + ((address & 0x00FFFFFF) << 5) + (bit_number << 2)) // ��λ������ַ��λ���ת��Ϊλ����������ַ
#define ADDRESS_POINTER(address)         *((volatile unsigned long  *)(address))                                               // ����ַת��Ϊ unsigned long ����ָ��
#define BIT_ADDRESS(address, bit_number) ADDRESS_POINTER(BITBAND(address, bit_number))                                         // ʹ��ǰ�涨��ĺ궨����� BITBAND()����λ����������ַת��Ϊָ��

/* �˿�������ƼĴ��� GPIOx_OCTL ��ַ */
#define GPIOA_OCTL_ADDRESS (GPIOA + 0x14)
#define GPIOB_OCTL_ADDRESS (GPIOB + 0x14)
#define GPIOC_OCTL_ADDRESS (GPIOC + 0x14)
#define GPIOD_OCTL_ADDRESS (GPIOD + 0x14)
#define GPIOE_OCTL_ADDRESS (GPIOE + 0x14)
#define GPIOF_OCTL_ADDRESS (GPIOF + 0x14)

/* �˿�����״̬�Ĵ��� GPIOx_ISTAT ��ַ */
#define GPIOA_ISTAT_ADDRESS (GPIOA + 0x10)
#define GPIOB_ISTAT_ADDRESS (GPIOB + 0x10)
#define GPIOC_ISTAT_ADDRESS (GPIOC + 0x10)
#define GPIOD_ISTAT_ADDRESS (GPIOD + 0x10)
#define GPIOE_ISTAT_ADDRESS (GPIOE + 0x10)
#define GPIOF_ISTAT_ADDRESS (GPIOF + 0x10)

/* ���� GPIOA ����������� */
#define GPIOA_Out(number) BIT_ADDRESS(GPIOA_OCTL_ADDRESS, number)
#define GPIOA_In(number)  BIT_ADDRESS(GPIOA_ISTAT_ADDRESS, number)

/* ���� GPIOB ����������� */
#define GPIOB_Out(number) BIT_ADDRESS(GPIOB_OCTL_ADDRESS, number)
#define GPIOB_In(number)  BIT_ADDRESS(GPIOB_ISTAT_ADDRESS, number)

/* ���� GPIOC ����������� */
#define GPIOC_Out(number) BIT_ADDRESS(GPIOC_OCTL_ADDRESS, number)
#define GPIOC_In(number)  BIT_ADDRESS(GPIOC_ISTAT_ADDRESS, number)

/* ���� GPIOD ����������� */
#define GPIOD_Out(number) BIT_ADDRESS(GPIOD_OCTL_ADDRESS, number)
#define GPIOD_In(number)  BIT_ADDRESS(GPIOD_ISTAT_ADDRESS, number)

/* ���� GPIOF ����������� */
#define GPIOF_Out(number) BIT_ADDRESS(GPIOF_OCTL_ADDRESS, number)
#define GPIOF_In(number)  BIT_ADDRESS(GPIOF_ISTAT_ADDRESS, number)