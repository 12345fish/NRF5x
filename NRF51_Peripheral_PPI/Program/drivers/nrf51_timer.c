/*=====================================================================================================*/
/*=====================================================================================================*/
#include "nrf51_system.h"
#include "nrf51_clock.h"
#include "nrf51_timer.h"
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_TimeBaseInit
**功能 : Timer TimeBase Init
**輸入 : TIMER_TBInitStruct
**輸出 : None
**使用 : TIMER_TimeBaseInit(TIMERx, &TIMER_TimeBaseInitStruct);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_TimeBaseInit( NRF_TIMER_Type *TIMERx, TIMER_TimeBaseInitTypeDef *TIMER_TBInitStruct )
{
  TIMERx->MODE      = TIMER_TBInitStruct->Mode;
  TIMERx->PRESCALER = TIMER_TBInitStruct->Prescaler;
  TIMERx->BITMODE   = TIMER_TBInitStruct->BitWidth;

  TIMER_TimerClear(TIMERx);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_Cmd
**功能 : Enable / Disable Timer
**輸入 : TIMERx, state
**輸出 : None
**使用 : TIMER_Cmd(TIMERx, ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_Cmd( NRF_TIMER_Type *TIMERx, uint8_t state )
{
  if(state == ENABLE)
    TIMERx->TASKS_START = 1;
  else
    TIMERx->TASKS_STOP = 1;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_TimerClear
**功能 : Clear Timer
**輸入 : TIMERx
**輸出 : None
**使用 : TIMER_TimerClear(TIMERx);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_TimerClear( NRF_TIMER_Type *TIMERx )
{
  TIMERx->TASKS_CLEAR = 1;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_CCInit
**功能 : TIMER CC Init
**輸入 : TIMERx, TIMER_CH, TIMER_CC
**輸出 : None
**使用 : TIMER_CCInit(TIMERx, TIMERx_CH, 1000);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_CCInit( NRF_TIMER_Type *TIMERx, TIMER_CH_TypeDef TIMERx_CH, __IO uint32_t TIMER_CC )
{
  TIMERx->CC[TIMERx_CH] = TIMER_CC;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_EvenCheck
**功能 : TIMER CC Even Check
**輸入 : TIMERx, TIMER_CH
**輸出 : state
**使用 : while(TIMER_EvenCheck(TIMERx, TIMERx_CH) != SUCCESS); // Wait even
**====================================================================================================*/
/*====================================================================================================*/
uint8_t TIMER_EvenCheck( NRF_TIMER_Type *TIMERx, TIMER_CH_TypeDef TIMERx_CH )
{
  return ((TIMERx->EVENTS_COMPARE[TIMERx_CH] != 0) ? SUCCESS : ERROR);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_EvenClear
**功能 : TIMER CC Even Clear
**輸入 : TIMERx, TIMER_CH
**輸出 : State
**使用 : TIMER_EvenClear(TIMERx, TIMERx_CH);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_EvenClear( NRF_TIMER_Type *TIMERx, TIMER_CH_TypeDef TIMERx_CH )
{
  TIMERx->EVENTS_COMPARE[TIMERx_CH] = 0;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_CC0Interrupt
**功能 : Enable / Disable CC0 Interrupt
**輸入 : TIMERx, NewState
**輸出 : None
**使用 : TIMER_CC2Interrupt(TIMERx, ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_CC0Interrupt( NRF_TIMER_Type *TIMERx, uint8_t state )
{
  if(state == ENABLE)
    TIMERx->INTENSET = TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos;
  else
    TIMERx->INTENSET = TIMER_INTENCLR_COMPARE0_Enabled << TIMER_INTENCLR_COMPARE0_Pos;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_CC1Interrupt
**功能 : Enable / Disable CC1 Interrupt
**輸入 : TIMERx NewState
**輸出 : None
**使用 : TIMER_CC1Interrupt(TIMERx, ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_CC1Interrupt( NRF_TIMER_Type *TIMERx, uint8_t state )
{
  if(state == ENABLE)
    TIMERx->INTENSET = TIMER_INTENSET_COMPARE1_Enabled << TIMER_INTENSET_COMPARE1_Pos;
  else 
    TIMERx->INTENSET = TIMER_INTENCLR_COMPARE1_Enabled << TIMER_INTENCLR_COMPARE1_Pos;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_CC2Interrupt
**功能 : Enable / Disable CC2 Interrupt
**輸入 : TIMERx NewState
**輸出 : None
**使用 : TIMER_CC2Interrupt(TIMERx, ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_CC2Interrupt( NRF_TIMER_Type *TIMERx, uint8_t state )
{
  if(state == ENABLE)
    TIMERx->INTENSET = TIMER_INTENSET_COMPARE2_Enabled << TIMER_INTENSET_COMPARE2_Pos;
  else
    TIMERx->INTENSET = TIMER_INTENCLR_COMPARE2_Enabled << TIMER_INTENCLR_COMPARE2_Pos;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : TIMER_CC3Interrupt
**功能 : Enable / Disable CC3 Interrupt
**輸入 : TIMERx NewState
**輸出 : None
**使用 : TIMER_CC3Interrupt(TIMERx, ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void TIMER_CC3Interrupt( NRF_TIMER_Type *TIMERx, uint8_t state )
{
  if(state == ENABLE)
    TIMERx->INTENSET = TIMER_INTENSET_COMPARE3_Enabled << TIMER_INTENSET_COMPARE3_Pos;
  else
    TIMERx->INTENSET = TIMER_INTENCLR_COMPARE3_Enabled << TIMER_INTENCLR_COMPARE3_Pos;
}
/*=====================================================================================================*/
/*=====================================================================================================*/

