/*========== gd32f3x0_it.c ==========*/
/* interrupt service routines */
#include "gd32f3x0_it.h"
#include "main.h"
#include "systick.h"
#include <stdio.h>

extern FlagStatus UINIO_Transfer_Complete;

void DMA_Channel1_2_IRQHandler(void) {
  /* 判断 DMA 通道传输是否已经完成，参数 DMA_INT_FLAG_FTF 是传输完成中断标志位 */
  if(dma_interrupt_flag_get(DMA_CH1, DMA_INT_FLAG_FTF)) {
    dma_interrupt_flag_clear(DMA_CH1, DMA_INT_FLAG_G); // 清除 DMA 通道全局中断标志位状态
    UINIO_Transfer_Complete = SET;
  }
}

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void) {
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void) {
  /* if Hard Fault exception occurs, go to infinite loop */
  while(1) {
  }
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void) {
  /* if Memory Manage exception occurs, go to infinite loop */
  while(1) {
  }
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void) {
  /* if Bus Fault exception occurs, go to infinite loop */
  while(1) {
  }
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void) {
  /* if Usage Fault exception occurs, go to infinite loop */
  while(1) {
  }
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void) {
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void) {
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void) {
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void) {
  delay_decrement();
}
