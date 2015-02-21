/*=====================================================================================================*/
/*=====================================================================================================*/
#include "nrf51_system.h"
#include "nrf51_spi.h"
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SPI_Init
**功能 : SPI Init
**輸入 : *SPIx, *SPI_InitStruct
**輸出 : None
**使用 : SPI_Init(NRF_SPI0, &SPI_InitStruct);
**====================================================================================================*/
/*====================================================================================================*/
void SPI_Init( NRF_SPI_Type *SPIx, SPI_InitTypeDef *SPI_InitStruct )
{
  SPIx->PSELSCK   = SPI_InitStruct->SPI_PinSCK;
  SPIx->PSELMOSI  = SPI_InitStruct->SPI_PinMOSI;
  SPIx->PSELMISO  = SPI_InitStruct->SPI_PinMISO;
  SPIx->FREQUENCY = SPI_InitStruct->SPI_Freguency;
  SPIx->CONFIG = (SPI_InitStruct->SPI_CPOL      << SPI_CONFIG_CPOL_Pos) | 
                 (SPI_InitStruct->SPI_CPHA      << SPI_CONFIG_CPHA_Pos) | 
                 (SPI_InitStruct->SPI_BitOrder  << SPI_CONFIG_ORDER_Pos);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SPI_Cmd
**功能 : Enable / Disable SPI
**輸入 : *SPIx, NewState
**輸出 : None
**使用 : SPI_Cmd(NRF_SPI0, ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void SPI_Cmd( NRF_SPI_Type *SPIx, FunctionalState NewState )
{
  if(NewState == ENABLE)
    SPIx->ENABLE = (SPI_ENABLE_ENABLE_Enabled  << SPI_ENABLE_ENABLE_Pos);
  else
    SPIx->ENABLE = (SPI_ENABLE_ENABLE_Disabled << SPI_ENABLE_ENABLE_Pos);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SPI_IntCmd
**功能 : Enable / Disable SPI Interrupt
**輸入 : *SPIx, NewState
**輸出 : None
**使用 : SPI_IntCmd(NRF_SPI0, ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void SPI_CmdIRQ( NRF_SPI_Type *SPIx, FunctionalState NewState )
{
  if(NewState == ENABLE)
    SPIx->INTENSET = (SPI_INTENSET_READY_Enabled << SPI_INTENSET_READY_Pos);
  else
    SPIx->INTENCLR = (SPI_INTENCLR_READY_Enabled << SPI_INTENCLR_READY_Pos);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SPI_EvenCheck
**功能 : Even Check
**輸入 : *SPIx
**輸出 : State
**使用 : SPI_EvenCheck(NRF_SPI0);
**====================================================================================================*/
/*====================================================================================================*/
uint8_t SPI_EvenCheck( NRF_SPI_Type *SPIx )
{
  if(SPIx->EVENTS_READY == 1)
    return SUCCESS;
  else
    return ERROR;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SPI_EvenClear
**功能 : Even Clear
**輸入 : *SPIx
**輸出 : None
**使用 : SPI_EvenClear(NRF_SPI0);
**====================================================================================================*/
/*====================================================================================================*/
void SPI_EvenClear( NRF_SPI_Type *SPIx )
{
  SPIx->EVENTS_READY = 0;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SPI_RW
**功能 : SPI Read / Write
**輸入 : *SPIx, WriteByte
**輸出 : State
**使用 : ReadData = SPI_RW(NRF_SPI0, 0x00);
**====================================================================================================*/
/*====================================================================================================*/
uint8_t SPI_RW( NRF_SPI_Type *SPIx, uint8_t WriteByte )
{
//  while(SPI_EvenCheck(SPIx) != SUCCESS);
  SPIx->TXD = WriteByte;
  while(SPI_EvenCheck(SPIx) != SUCCESS);
  SPIx->RXD;  // RX buf

  return SPIx->RXD;
}
/*=====================================================================================================*/
/*=====================================================================================================*/
