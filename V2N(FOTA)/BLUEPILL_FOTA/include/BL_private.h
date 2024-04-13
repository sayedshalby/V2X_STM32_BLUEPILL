#ifndef BL_PRIVATE_H_
#define BL_PRIVATE_H_

#define SCB_VTOR *((volatile uint32*)0xE000ED08)

static void BL_voidCallMainApp(void);
static uint8 BL_u8CheckAppArea(void);
static void BL_voidUART_ISR(void);


#endif /* BL_PRIVATE_H_ */
