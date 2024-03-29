/*========== ADC.h ==========*/
#ifndef UINIO_ADC_H
#define UINIO_ADC_H

#include "gd32f3x0.h"

void UINIO_ADC_Config(void);                         // ADC 外设配置函数
unsigned int UINIO_ADC_Value(uint8_t ADC_CHANNEL_x); // 获取指定 ADC 通道的采集值

#endif /* UINIO_ADC_H */
