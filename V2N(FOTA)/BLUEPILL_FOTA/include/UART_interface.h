#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define UART3_RX_PORT GPIO_PORTB
#define UART3_RX_PIN  GPIO_PIN11

#define UART3_TX_PORT GPIO_PORTB
#define UART3_TX_PIN  GPIO_PIN10

void UART3_voidInit(void);

void UART3_voidDisable(void);

void UART3_voidEnable(void);

void UART3_voidTransmitSynch(uint8 u8DataCpy);

uint8 UART3_u8ReceiveSynch(void);

void UART3_voidTransmitStringSynch(const uint8* pu8DataCpy);

uint8 UART3_u8GetData(void);

void UART3_voidReceiveIntEnable(void);

void UART3_voidReceiveIntDisable(void);

void UART3_voidSetCallBack(pf pfUART3ISRCpy);

uint32* UART3_pu32DMAReceiveAddress(void);

#endif
