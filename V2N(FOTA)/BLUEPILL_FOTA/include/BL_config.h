#ifndef BL_CONFIG_H_
#define BL_CONFIG_H_


#define TIME_OUT_SECONDS 2

#define MAIN_APP_ADDRESS ((uint32)0x08002000)

#define BL_LED_PORT GPIO_PORTA
#define BL_LED_PIN GPIO_PIN1

/*
 *(uint32) 0xFFFFFFFF  -> For Hardware
 *(uint32) 0x00000000  -> For Simulation
 */
#define BL_EMPTY_WORD_VALUE ((uint32) 0x00000000)


#endif /* BL_CONFIG_H_ */
