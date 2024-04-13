#include "STD_Types.h"
#include "BIT_Math.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

static uint16 UART_u16BRRValue(uint32 u32BaudRateCpy);

pf pfUART3ISRGlb = NULL_PTR;

void UART3_voidInit(void)
{
	/*Disable UART*/
	CLR_BIT(UART3_REG->CR1,CR1_UE);

	/*Word length*/
	UART3_REG->CR1 = (UART3_REG->CR1 & ~(1<<CR1_M)) | (UART3_WORD_LENGTH<<CR1_M);

	/*Baud Rate*/
	UART3_REG->BRR = UART_u16BRRValue(UART3_BAUDRATE);

	/*Parity*/
	UART3_REG->CR1 = (UART3_REG->CR1 & ~(1<<CR1_PCE)) | (UART3_PARITY_STATE<<CR1_PCE);

	/*Stop bits*/
	UART3_REG->CR2 = (UART3_REG->CR2 & ~(0b11<<CR2_STOP)) | (UART3_STOP_BITS_MODE<<CR2_STOP);

	/*Receiver*/
	UART3_REG->CR1 = (UART3_REG->CR1 & ~(1<<CR1_RE)) | (UART3_RECEIVER_STATE<<CR1_RE);

	/*Transmitter*/
	UART3_REG->CR1 = (UART3_REG->CR1 & ~(1<<CR1_TE)) | (UART3_TRANSMITTER_STATE<<CR1_TE);

	/*Interrupts*/
	UART3_REG->CR1 = (UART3_REG->CR1 & ~(1<<CR1_RXNEIE)) | (UART3_RECEIVE_INTERRUPT<<CR1_RXNEIE);
	UART3_REG->CR1 = (UART3_REG->CR1 & ~(1<<CR1_TXEIE)) | (UART3_TRANSMIT_INTERRUPT<<CR1_TXEIE);

	/*Enable UART*/
	UART3_REG->CR1 = (UART3_REG->CR1 & ~(1<<CR1_UE)) | (UART3_STATE<<CR1_UE);
}

void UART3_voidDisable(void)
{
	CLR_BIT(UART3_REG->CR1,CR1_UE);
}

void UART3_voidEnable(void)
{
	SET_BIT(UART3_REG->CR1,CR1_UE);
}

void UART3_voidTransmitSynch(uint8 u8DataCpy)
{
	/*Send Data*/
	UART3_REG->DR = u8DataCpy;

	/*Transmit Flag*/
	while(GET_BIT(UART3_REG->SR, SR_TXE)==0);
}

uint8 UART3_u8ReceiveSynch(void)
{
	/*Receive Flag*/
	while(GET_BIT(UART3_REG->SR, SR_RXNE)==0);

	/*Read Data*/
	return ((uint8) UART3_REG->DR);
}

void UART3_voidTransmitStringSynch(const uint8* pu8DataCpy)
{
	uint8 u8IndxLoc = 0;
	while(1)
	{
		/*Send Data*/
		UART3_REG->DR = pu8DataCpy[u8IndxLoc];

		/*Transmit Flag*/
		while(GET_BIT(UART3_REG->SR, SR_TXE)==0);

		u8IndxLoc++;

		if(pu8DataCpy[u8IndxLoc] == '\0')
		{
			break;
		}
	}
}

uint8 UART3_u8GetData(void)
{
	/*Read Data*/
	return ((uint8) UART3_REG->DR);
}

void UART3_voidReceiveIntEnable(void)
{
	SET_BIT(UART3_REG->CR1, CR1_RXNEIE);
}

void UART3_voidReceiveIntDisable(void)
{
	CLR_BIT(UART3_REG->CR1, CR1_RXNEIE);
}

void UART3_voidSetCallBack(pf pfUART3ISRCpy)
{
	pfUART3ISRGlb = pfUART3ISRCpy;
}

void USART3_IRQHandler(void){

	if(pfUART3ISRGlb!=NULL_PTR)
	{
		pfUART3ISRGlb();
	}

}

static uint16 UART_u16BRRValue(uint32 u32BaudRateCpy)
{
	uint16 u16RetValLoc;

	uint32 u32MantissaLoc = (8000000u)/(16*u32BaudRateCpy) ;

	uint32 u32FractionLoc = (((8000000u)*100/(16*u32BaudRateCpy))%100)*16 ;

	if( u32FractionLoc > 1500 )
	{
		u32MantissaLoc += 1 ;
		u32FractionLoc  = 0 ;
	}

	u16RetValLoc = ( u32MantissaLoc << 4  ) | ( u32FractionLoc / 100 ) ;

	return u16RetValLoc;
}
