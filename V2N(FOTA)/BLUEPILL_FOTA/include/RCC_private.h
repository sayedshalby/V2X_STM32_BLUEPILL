#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define RCC_BASE_ADDRESS (0x40021000)

typedef struct
{
	uint32 CR;
	uint32 CFGR;
	uint32 CIR;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 AHBENR;
	uint32 APB2ENR;
    uint32 APB1ENR;
	uint32 BDCR;
	uint32 CSR;
}tstrRCC_registers;

#define RCC_HSEBYP 18
#define RCC_HSERDY 17
#define RCC_HSEON  16
#define RCC_HSIRDY 1
#define RCC_HSION  0

#define SWITCH_MASK 0xFFFFFFFC

#define RCC_REG ((volatile tstrRCC_registers*)RCC_BASE_ADDRESS)

#define RCC_SYS_CLK_HSE 1
#define RCC_SYS_CLK_HSI 0

#endif
