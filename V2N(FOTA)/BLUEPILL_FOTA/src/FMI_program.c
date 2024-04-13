#include "STD_Types.h"
#include "BIT_Math.h"

#include "FMI_interface.h"
#include "FMI_private.h"
#include "FMI_config.h"

void FMI_voidPageErase(uint8 u8PageNumCpy)
{
	/*Wait on BSY flag*/
	while(GET_BIT(FMI_REG->SR,SR_BSY)==1);

	/*If FMI locked ===> unlock*/
	if(GET_BIT(FMI_REG->CR,CR_LOCK)==1)
	{
		FMI_REG->KEYR = FMI_FPECKEY1;
		FMI_REG->KEYR = FMI_FPECKEY2;
	}

	/*Erase mode*/
	SET_BIT(FMI_REG->CR, CR_PER);

    /*Page address*/
	FMI_REG->AR = (uint32)(u8PageNumCpy * 1024) + 0x08000000u ;

	/*Start erase*/
	SET_BIT(FMI_REG->CR, CR_STRT);

	/*Wait on BSY flag*/
	while(GET_BIT(FMI_REG->SR,SR_BSY)==1);

	/*Clear end of operation flag*/
	SET_BIT(FMI_REG->SR, SR_EOP);

	/*Deactivate erase bit*/
	CLR_BIT(FMI_REG->CR, CR_PER);
}

void FMI_voidSectorErase(uint8 u8SectorNumCpy)
{
	uint8 u8CntrLoc = 0;

    for(u8CntrLoc=0; u8CntrLoc<8; u8CntrLoc++)
    {
        FMI_voidPageErase(u8CntrLoc+(u8SectorNumCpy*16));
    }
}

void FMI_voidDataWrite(uint16* pau16DataCpy, uint16 u16DataLengthCpy, uint32 u32AddressCpy)
{
	uint16 u16CntrLoc;

	/*Wait on BSY flag*/
	while(GET_BIT(FMI_REG->SR,SR_BSY)==1);

	/*If FMI locked ===> unlock*/
	if(GET_BIT(FMI_REG->CR,CR_LOCK)==1)
	{
		FMI_REG->KEYR = FMI_FPECKEY1;
		FMI_REG->KEYR = FMI_FPECKEY2;
	}

	/*Programming mode*/
	SET_BIT(FMI_REG->CR, CR_PG);

	/*Write Data*/
	for(u16CntrLoc=0; u16CntrLoc<u16DataLengthCpy; u16CntrLoc++)
	{
		((volatile uint16*)u32AddressCpy)[u16CntrLoc] = pau16DataCpy[u16CntrLoc];

		/*Wait on BSY flag*/
		while(GET_BIT(FMI_REG->SR,SR_BSY)==1);

		/*Clear end of operation flag*/
		SET_BIT(FMI_REG->SR, SR_EOP);
	}

	/*Deactivate programming bit*/
	CLR_BIT(FMI_REG->CR, CR_PG);
}

void FMI_voidFullErase(void)
{
	uint8 u8CntrLoc;

	for(u8CntrLoc=0; u8CntrLoc<128; u8CntrLoc++)
	{
		FMI_voidPageErase(u8CntrLoc);
	}
}
