#include "STD_Types.h"
#include "BIT_Math.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "FMI_interface.h"
#include "UART_interface.h"
#include "APARSER_Interface.h"

#include "BL_interface.h"
#include "BL_private.h"
#include "BL_config.h"

static uint8 au8DataBufferGlb[100];
static uint8 u8NewRecordFlagGlb = 0;
static uint8 u8TimeOutCntrGlb = 0;
static uint32 u32CntrGlb = 0;
static uint8 u8AppExistFlagGlb = 0;
volatile pf pfMainAppGlb = 0;

void BL_voidInit(void)
{
	/*RCC*/
	RCC_voidInit();
	RCC_voidEnable(APB2,APB2_GPIOA);
	RCC_voidEnable(APB2,APB2_GPIOB);
	RCC_voidEnable(APB1,APB1_USART3);
	RCC_voidEnable(AHB,AHB_FLITF);

	/*Bootloader LED Configuration*/
	GPIO_enuSetMode(BL_LED_PORT, BL_LED_PIN, GPIO_MODE_OUTPUT);
	GPIO_enuSetOutputType(BL_LED_PORT, BL_LED_PIN, GPIO_OUTPUT_TYPE_PUSH_PULL);

	/*UART1 RX/TX Configuration*/
	GPIO_enuSetMode(UART3_RX_PORT, UART3_TX_PIN, GPIO_MODE_OUTPUT);
	GPIO_enuSetOutputType(UART3_RX_PORT, UART3_TX_PIN, GPIO_OUTPUT_AF_PUSH_PULL);
	GPIO_enuSetMode(UART3_RX_PORT, UART3_RX_PIN, GPIO_MODE_INPUT);
	GPIO_enuSetInputType(UART3_RX_PORT, UART3_RX_PIN, GPIO_INPUT_TYPE_FLOAT);

	UART3_voidInit();
	UART3_voidSetCallBack(BL_voidUART_ISR);

	/*NVIC*/
	NVIC_voidSetInterruptGroupMode(Group0Sub16);
	NVIC_voidSetInterruptPriority(NVIC_POSITION_USART3,0,0);
	NVIC_voidEnable(NVIC_POSITION_USART3);

	u8AppExistFlagGlb = BL_u8CheckAppArea();

}

void BL_voidStart(void)
{
	uint8 u8ParserCheckLoc = 0;

	while(1)
	{
		/*New record received*/
		if(u8NewRecordFlagGlb==1)
		{
			u8NewRecordFlagGlb=0;

			/*Parse record*/
			u8ParserCheckLoc = APARSER_u8ParseRecord(au8DataBufferGlb);

			/*Check Sum*/
			if(u8ParserCheckLoc!=0xFF)
			{
				UART3_voidTransmitStringSynch("OK");
			}
			else
			{
				UART3_voidTransmitStringSynch("NOK");
			}


			if((u8AppExistFlagGlb==1) && (u8ParserCheckLoc==0)) /*If Data Overwritten ==> Clear App Flag*/
			{
				u8AppExistFlagGlb=0;
			}
			else if(u8ParserCheckLoc==1) /*If File ended ==> Set App Flag*/
			{
				u8AppExistFlagGlb=1;
			}
		}

		/*Time Out*/
		if(u8TimeOutCntrGlb==TIME_OUT_SECONDS)
		{
			u8TimeOutCntrGlb = 0;
			if(u8AppExistFlagGlb==1)
			{
				BL_voidCallMainApp();
			}
		}

		/*Time out counter*/
		u32CntrGlb++;
		if(u32CntrGlb==200000) /*200000 ===> 1 second*/
		{
			u32CntrGlb = 0;
			u8TimeOutCntrGlb++;
			GPIO_enuTogglePinValue(BL_LED_PORT, BL_LED_PIN);
		}
	}
}


static void BL_voidCallMainApp(void)
{
	/*RCC Disable*/
	GPIO_enuWritePinValue(BL_LED_PORT, BL_LED_PIN, GPIO_LOW);
	UART3_voidDisable();
	RCC_voidDisable(APB2,APB2_GPIOA);
	RCC_voidDisable(APB2,APB2_USART1);
	RCC_voidDisable(AHB,AHB_FLITF);

	/*Jumb to main application*/
	SCB_VTOR = MAIN_APP_ADDRESS;
	pfMainAppGlb = *(pf*)(MAIN_APP_ADDRESS+4);
	pfMainAppGlb();

}

static uint8 BL_u8CheckAppArea(void)
{
	uint8 u8IndxCntrLoc = 0;
	uint8 u8EmptyCntrLoc = 0;
	uint8 u8RetLoc = 0;

	for(u8IndxCntrLoc=0; u8IndxCntrLoc<10; u8IndxCntrLoc++)
	{
		if(((uint32*)(MAIN_APP_ADDRESS))[u8IndxCntrLoc] == BL_EMPTY_WORD_VALUE)
		{
			u8EmptyCntrLoc++;
		}
		else
		{
			break;
		}
	}

	if(u8EmptyCntrLoc==10)
	{
		u8RetLoc=0;
	}
	else
	{
		u8RetLoc=1;
	}

	return u8RetLoc;
}

static void BL_voidUART_ISR(void)
{
	static uint8 u8BufferCntrLoc = 0;

	/*Reset timeout counter*/
	u8TimeOutCntrGlb=0;
	u32CntrGlb = 0;

	/*Receive UART data*/
	au8DataBufferGlb[u8BufferCntrLoc] = UART3_u8GetData();
	u8BufferCntrLoc++;

	/*Check for end of record*/

	if(au8DataBufferGlb[u8BufferCntrLoc-1]=='\n')
	{
		if(au8DataBufferGlb[u8BufferCntrLoc-2]=='\r')
		{
			au8DataBufferGlb[u8BufferCntrLoc-2]='\n';
			au8DataBufferGlb[u8BufferCntrLoc-1]=0;
		}
		if(au8DataBufferGlb[u8BufferCntrLoc-3]=='\r')
		{
			au8DataBufferGlb[u8BufferCntrLoc-3]='\n';
			au8DataBufferGlb[u8BufferCntrLoc-2]=0;
		}
		u8NewRecordFlagGlb=1;
		u8BufferCntrLoc=0;
		/*

		 */
	}


}

