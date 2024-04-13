#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_BASE_ADDRESS (0xE000E100)

#define AIRCR (*((volatile uint32*)0xE000ED0C))

typedef struct{
	uint32 ISER[3];
	uint32 Reserved0[29];
	uint32 ICER[3];
	uint32 Reserved1[29];
	uint32 ISPR[3];
	uint32 Reserved2[29];
	uint32 ICPR[3];
	uint32 Reserved3[29];
	uint32 IABR[3];
	uint32 Reserved4[61];
	uint8 IPR[84];
}tstrNVIC_registers;

#define NVIC_REG ((volatile tstrNVIC_registers*)NVIC_BASE_ADDRESS)

#define NVIC_VECTKEY 0x05FA0000

#endif
