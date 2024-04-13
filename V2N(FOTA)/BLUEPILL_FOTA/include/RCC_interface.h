#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


typedef enum
{
	AHB=0,
	APB1,
	APB2
}BUS_t;

/*****************************AHB*******************************/
#define AHB_DMA1   0
#define AHB_DMA2   1
#define AHB_SRAM   2
#define AHB_FLITF  4
#define AHB_CRC    6
#define AHB_FSMC   8
#define AHB_SDIO   10

/*****************************APB1*******************************/
#define APB1_TIM2     0
#define APB1_TIM3     1
#define APB1_TIM4     2
#define APB1_TIM5     3
#define APB1_TIM6     4
#define APB1_TIM7     5
#define APB1_TIM12    6
#define APB1_TIM13    7
#define APB1_TIM14    8
#define APB1_WWDG     11
#define APB1_SPI2     14
#define APB1_SPI3     15
#define APB1_USART2   17
#define APB1_USART3   18
#define APB1_USART4   19
#define APB1_USART5   20
#define APB1_I2C1     21
#define APB1_I2C2     22
#define APB1_USB      23
#define APB1_CAN      25
#define APB1_BKP      27
#define APB1_PWR      28
#define APB1_DAC      29

/*****************************APB2*******************************/
#define APB2_AFIO     0
#define APB2_GPIOA    2
#define APB2_GPIOB    3
#define APB2_GPIOC    4
#define APB2_GPIOD    5
#define APB2_GPIOE    6
#define APB2_GPIOF    7
#define APB2_GPIOG    8
#define APB2_ADC1     9
#define APB2_ADC2     10
#define APB2_TIM1     11
#define APB2_SPI1     12
#define APB2_TIM8     13
#define APB2_USART1   14
#define APB2_ADC3     16
#define APB2_TIM9     19
#define APB2_TIM10    20
#define APB2_TIM11    21

void RCC_voidInit(void);
void RCC_voidEnable(BUS_t enuBusCpy, uint16 u16PeripheralCpy);
void RCC_voidDisable(BUS_t enuBusCpy, uint16 u16PeripheralCpy);


#endif
