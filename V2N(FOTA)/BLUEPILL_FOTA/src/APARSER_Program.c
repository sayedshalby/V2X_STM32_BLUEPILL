/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "STD_Types.h"
#include "BIT_Math.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/


#include "FMI_interface.h"
#include "APARSER_Interface.h"
#include "UART_interface.h"



uint32 GLB_u32Address  = 0x08000000;

uint16 GLB_u16Data[100] ;

uint8 APARSER_u8AsciiToHex(uint8 Copy_u8Asci) //0--->9 -48   A--->F -55
{

	uint8 LOC_u8Result = 0 ;

	if((Copy_u8Asci >=48) && (Copy_u8Asci <=57) )
	{
		LOC_u8Result = Copy_u8Asci - 48 ;
	}
	else
	{
		LOC_u8Result = Copy_u8Asci  - 55 ;
	}

	return LOC_u8Result ;

}



uint8 APARSER_u8ParseRecord(uint8 * Copy_u8BufRecord)
{
	uint8 u8RetValueLoc=0;

	if(APARSER_u8CheckSum(Copy_u8BufRecord)==0)
	{
		switch(Copy_u8BufRecord[8])
		{
		case '0' :
			u8RetValueLoc=0;
			APARSER_voidParseData(Copy_u8BufRecord);
			break ;
		case '1' : /*End Of File*/
			u8RetValueLoc=1;
			break ;
		case '4' : /*Set High Address part*/
			APARSERvoidParseHighAddress(Copy_u8BufRecord);
			u8RetValueLoc=4;
			break ;
		}
	}
	else
	{
		u8RetValueLoc=0xFF;
	}

	return u8RetValueLoc;
}

void APARSERvoidParseHighAddress(uint8* Copy_u8BufData)
{
	/*For Address 4 Digits*/
	uint8 LOC_u8Digit0 ;
	uint8 LOC_u8Digit1 ;
	uint8 LOC_u8Digit2 ;
	uint8 LOC_u8Digit3 ;

	/*Receive High part Address Address*/
	LOC_u8Digit0 = APARSER_u8AsciiToHex(Copy_u8BufData[9]);
	LOC_u8Digit1 = APARSER_u8AsciiToHex(Copy_u8BufData[10]);
	LOC_u8Digit2 = APARSER_u8AsciiToHex(Copy_u8BufData[11]);
	LOC_u8Digit3 = APARSER_u8AsciiToHex(Copy_u8BufData[12]);

	GLB_u32Address &= 0x0000FFFF ;
	GLB_u32Address |= (LOC_u8Digit0<<28) | (LOC_u8Digit1<<24) | (LOC_u8Digit2<<20) |(LOC_u8Digit3<<16)  ;
}

void APARSER_voidParseData(uint8* Copy_u8BufData)
{
	/******************************************************************************************************/
	/*######################################## Local Variables ###########################################*/
	/******************************************************************************************************/

	/*For Character Count*/
	uint8 LOC_u8CCDigitHigh ;
	uint8 LOC_u8CCDigitLow ;
	uint8 LOC_u8CharacterCount ;

	/*For Address 4 Digits*/
	uint8 LOC_u8Digit0 ;
	uint8 LOC_u8Digit1 ;
	uint8 LOC_u8Digit2 ;
	uint8 LOC_u8Digit3 ;

	uint16 LOC_u16LowAddress;

	/*Iterator For Data  Loop*/
	uint8 LOC_u8Result = 0 ;


	/******************************************************************************************************/
	/*############################################### Parsing ############################################*/
	/******************************************************************************************************/
	/*Receive CC*/
	LOC_u8CCDigitHigh = APARSER_u8AsciiToHex(Copy_u8BufData[1]) ;
	LOC_u8CCDigitLow  = APARSER_u8AsciiToHex(Copy_u8BufData[2]);
	LOC_u8CharacterCount =  LOC_u8CCDigitHigh<<4 | LOC_u8CCDigitLow ;
	/*Receive Low part Address Address*/
	LOC_u8Digit0 = APARSER_u8AsciiToHex(Copy_u8BufData[3]);
	LOC_u8Digit1 = APARSER_u8AsciiToHex(Copy_u8BufData[4]);
	LOC_u8Digit2 = APARSER_u8AsciiToHex(Copy_u8BufData[5]);
	LOC_u8Digit3 = APARSER_u8AsciiToHex(Copy_u8BufData[6]);

	LOC_u16LowAddress = (LOC_u8Digit0<<12) | (LOC_u8Digit1<<8) | (LOC_u8Digit2<<4) |(LOC_u8Digit3);

	GLB_u32Address &= 0xFFFF0000 ;

	GLB_u32Address |= LOC_u16LowAddress  ;
	if(LOC_u16LowAddress % 0x400 ==0)
	{
		FMI_voidPageErase(LOC_u16LowAddress/0x400);
	}

	for(LOC_u8Result = 0 ; LOC_u8Result < (LOC_u8CharacterCount / 2) ; LOC_u8Result++  )
	{
		/*Receive  Half Word Data [4 Digits]*/
		LOC_u8Digit0 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 9]);
		LOC_u8Digit1 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 10]);
		LOC_u8Digit2 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 11]);
		LOC_u8Digit3 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 12]);
		/*because little Endian*/
		GLB_u16Data[LOC_u8Result] = (LOC_u8Digit2<<12) | (LOC_u8Digit3<<8) | (LOC_u8Digit0<<4) |(LOC_u8Digit1)  ;
	}
	FMI_voidDataWrite(GLB_u16Data, (LOC_u8CharacterCount / 2), GLB_u32Address);
}

uint8 APARSER_u8CheckSum(uint8* Copy_u8BufData)
{
	uint8 u8RetLoc = 0;
	uint8 u8CheckSum = 0;
	uint32 u32SumLoc=0;
	uint8 u8CntrLoc=1;


	while(Copy_u8BufData[u8CntrLoc+2]!='\n')
	{
		u32SumLoc += APARSER_u8AsciiToHex(Copy_u8BufData[u8CntrLoc])<<4 | APARSER_u8AsciiToHex(Copy_u8BufData[u8CntrLoc+1]);

		u8CntrLoc+=2;
	}
	u8CheckSum = APARSER_u8AsciiToHex(Copy_u8BufData[u8CntrLoc])<<4 | APARSER_u8AsciiToHex(Copy_u8BufData[u8CntrLoc+1]);
	u32SumLoc = (uint8) (~(u32SumLoc%256)+1);

	if(u8CheckSum!=u32SumLoc)
	{
		u8RetLoc = 1;
	}

	return u8RetLoc;
}
