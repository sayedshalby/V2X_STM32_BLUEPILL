#ifndef FMI_INTERFACE_H_
#define FMI_INTERFACE_H_

void FMI_voidPageErase(uint8 u8PageNumCpy);

void FMI_voidSectorErase(uint8 u8SectorNumCpy);

void FMI_voidDataWrite(uint16* pau16DataCpy, uint16 u16DataLengthCpy, uint32 u32AddressCpy);

void FMI_voidFullErase(void);

#endif
