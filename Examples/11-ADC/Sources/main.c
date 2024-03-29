/*========== main.c ==========*/
#include "gd32f3x0.h"
#include "stdio.h"
#include "systick.h"

#include "../Drivers/ADC/ADC.h"
#include "../Drivers/USART/USART.h"

unsigned int UINIO_ADC_Filter(unsigned int number) {
  int index = 0;
  unsigned int value = 0;

  for(index = 0; index< number; index++) {
    value = value + UINIO_ADC_Value(ADC_CHANNEL_11);
    delay_1ms(1);
  }

  value = value / number;
  return value;
}

int main(void) {
  systick_config();
  UINIO_USART_GPIO_Config(9600U);
  UINIO_ADC_Config();

  uint16_t value = 0;

  while(1) {
    value = UINIO_ADC_Filter(50);
    printf("ADC_Value = %f\n",(( value / 4095.0 ) * 3.3) );
    delay_1ms(500);
  }
}
