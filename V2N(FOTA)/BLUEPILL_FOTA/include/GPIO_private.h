#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS (0x40010800)
#define GPIOB_BASE_ADDRESS (0x40010C00)
#define GPIOC_BASE_ADDRESS (0x40011000)

typedef struct{
	uint32 CRL;
	uint32 CRH;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 BRR;
	uint32 LCKR;
}tstrGPIO_registers;

#define GPIOA_REG ((volatile tstrGPIO_registers*)GPIOA_BASE_ADDRESS)
#define GPIOB_REG ((volatile tstrGPIO_registers*)GPIOB_BASE_ADDRESS)
#define GPIOC_REG ((volatile tstrGPIO_registers*)GPIOC_BASE_ADDRESS)

#endif
