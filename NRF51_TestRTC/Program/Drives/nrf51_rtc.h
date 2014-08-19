/* #include "nrf51_rtc.h" */

#ifndef __NRF51_RTC_H
#define __NRF51_RTC_H

#include "nrf51_typedef.h"
/*====================================================================================================*/
/*====================================================================================================*/
typedef enum {
  RTC_CH0 = 0,
  RTC_CH1,
  RTC_CH2,
  RTC_CH3
} RTC_CH_TypeDef;
/*====================================================================================================*/
/*====================================================================================================*/
void RTC_Config( void );
void RTC_Cmd( FunctionalState NewState );
void RTC_CntClear( void );
u8   RTC_TickEvenCheck( void );
void RTC_TickEvenClear( void );
u8   RTC_CompEvenCheck( RTC_CH_TypeDef RTC_CH );
void RTC_CompEvenClear( RTC_CH_TypeDef RTC_CH );
/*====================================================================================================*/
/*====================================================================================================*/
#endif	 