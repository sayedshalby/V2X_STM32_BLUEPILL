#ifndef APARSER_INTERFACE_H_
#define APARSER_INTERFACE_H_

uint8 APARSER_u8AsciiToHex(uint8 Copy_u8Asci) ;

uint8 APARSER_u8ParseRecord(uint8 * Copy_u8BufRecord) ;

void APARSERvoidParseHighAddress(uint8* Copy_u8BufData);

void APARSER_voidParseData(uint8* Copy_u8BufData) ;

uint8 APARSER_u8CheckSum(uint8* Copy_u8BufData);


#endif /* APARSER_INTERFACE_H_ */
