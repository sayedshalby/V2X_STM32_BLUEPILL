#include "STD_Types.h"
#include "BIT_Math.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

static tenuErrorStatus GPIO_enuPinCheck(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy);


tenuErrorStatus GPIO_enuSetMode(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy, tenuGPIO_pinMode enuModeCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    if(enuModeCpy>GPIO_MODE_OUTPUT)
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        enuErrorStatLoc = GPIO_enuPinCheck(enuPortNumCpy, enuPinNumCpy);
    }

    if(enuErrorStatLoc == E_OK)
    {
        switch(enuPortNumCpy)
    	{
    	case GPIO_PORTA:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOA_REG->CRL = (GPIOA_REG->CRL & ~(3<<(enuPinNumCpy*4))) |enuModeCpy<<(enuPinNumCpy*4);
            }
            else
            {
                GPIOA_REG->CRH = (GPIOA_REG->CRH & ~(3<<(enuPinNumCpy*4))) |enuModeCpy<<(enuPinNumCpy*4);
            }
    		break;
    	case GPIO_PORTB:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOB_REG->CRL = (GPIOB_REG->CRL & ~(3<<(enuPinNumCpy*4))) |enuModeCpy<<(enuPinNumCpy*4);
            }
            else
            {
                GPIOB_REG->CRH = (GPIOB_REG->CRH & ~(3<<(enuPinNumCpy*4))) |enuModeCpy<<(enuPinNumCpy*4);
            }
            break;
    	case GPIO_PORTC:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOC_REG->CRL = (GPIOC_REG->CRL & ~(3<<(enuPinNumCpy*4))) |enuModeCpy<<(enuPinNumCpy*4);
            }
            else
            {
                GPIOC_REG->CRH = (GPIOC_REG->CRH & ~(3<<(enuPinNumCpy*4))) |enuModeCpy<<(enuPinNumCpy*4);
            }
            break;
    	default:
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    		break;
    	}
    }
    else
    {

    }

	return enuErrorStatLoc;
}

tenuErrorStatus GPIO_enuSetOutputType(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy, tenuGPIO_outputType enuOutputTypeCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    if(enuOutputTypeCpy>GPIO_OUTPUT_AF_OPEN_DRAIN)
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        enuErrorStatLoc = GPIO_enuPinCheck(enuPortNumCpy, enuPinNumCpy);
    }

    if(enuErrorStatLoc == E_OK)
    {
        switch(enuPortNumCpy)
    	{
    	case GPIO_PORTA:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOA_REG->CRL = (GPIOA_REG->CRL & ~(3<<(enuPinNumCpy*4+2))) |enuOutputTypeCpy<<(enuPinNumCpy*4+2);
            }
            else
            {
                GPIOA_REG->CRH = (GPIOA_REG->CRH & ~(3<<(enuPinNumCpy*4+2))) |enuOutputTypeCpy<<(enuPinNumCpy*4+2);
            }
    		break;
    	case GPIO_PORTB:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOB_REG->CRL = (GPIOB_REG->CRL & ~(3<<(enuPinNumCpy*4+2))) |enuOutputTypeCpy<<(enuPinNumCpy*4+2);
            }
            else
            {
                GPIOB_REG->CRH = (GPIOB_REG->CRH & ~(3<<(enuPinNumCpy*4+2))) |enuOutputTypeCpy<<(enuPinNumCpy*4+2);
            }
            break;
    	case GPIO_PORTC:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOC_REG->CRL = (GPIOC_REG->CRL & ~(3<<(enuPinNumCpy*4+2))) |enuOutputTypeCpy<<(enuPinNumCpy*4+2);
            }
            else
            {
                GPIOC_REG->CRH = (GPIOC_REG->CRH & ~(3<<(enuPinNumCpy*4+2))) |enuOutputTypeCpy<<(enuPinNumCpy*4+2);
            }
            break;
    	default:
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    		break;
    	}
    }

	return enuErrorStatLoc;
}

tenuErrorStatus GPIO_enuSetInputType(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy, tenuGPIO_inputType enuInputTypeCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    if(enuInputTypeCpy>GPIO_INPUT_TYPE_PULL_UP_DOWN)
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        enuErrorStatLoc = GPIO_enuPinCheck(enuPortNumCpy, enuPinNumCpy);
    }

    if(enuErrorStatLoc == E_OK)
    {
        switch(enuPortNumCpy)
    	{
    	case GPIO_PORTA:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOA_REG->CRL = (GPIOA_REG->CRL & ~(3<<(enuPinNumCpy*4+2))) |enuInputTypeCpy<<(enuPinNumCpy*4+2);
            }
            else
            {
                GPIOA_REG->CRH = (GPIOA_REG->CRH & ~(3<<(enuPinNumCpy*4+2))) |enuInputTypeCpy<<(enuPinNumCpy*4+2);
            }
    		break;
    	case GPIO_PORTB:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOB_REG->CRL = (GPIOB_REG->CRL & ~(3<<(enuPinNumCpy*4+2))) |enuInputTypeCpy<<(enuPinNumCpy*4+2);
            }
            else
            {
                GPIOB_REG->CRH = (GPIOB_REG->CRH & ~(3<<(enuPinNumCpy*4+2))) |enuInputTypeCpy<<(enuPinNumCpy*4+2);
            }
            break;
    	case GPIO_PORTC:
            if(enuPinNumCpy<=GPIO_PIN7)
            {
                GPIOC_REG->CRL = (GPIOC_REG->CRL & ~(3<<(enuPinNumCpy*4+2))) |enuInputTypeCpy<<(enuPinNumCpy*4+2);
            }
            else
            {
                GPIOC_REG->CRH = (GPIOC_REG->CRH & ~(3<<(enuPinNumCpy*4+2))) |enuInputTypeCpy<<(enuPinNumCpy*4+2);
            }
            break;
    	default:
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    		break;
    	}
    }

	return enuErrorStatLoc;
}

tenuErrorStatus GPIO_enuWritePinValue(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy, tenuGPIO_level enuPinValueCpy)
{
	tenuErrorStatus enuErrorStatLoc = E_OK;

    if(enuPinValueCpy>GPIO_HIGH)
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        enuErrorStatLoc = GPIO_enuPinCheck(enuPortNumCpy, enuPinNumCpy);
    }

    if(enuErrorStatLoc == E_OK)
    {
        switch(enuPortNumCpy)
    	{
    	case GPIO_PORTA:
            GPIOA_REG->ODR = (GPIOA_REG->ODR & ~(1<<(enuPinNumCpy))) |enuPinValueCpy<<(enuPinNumCpy);
    		break;
    	case GPIO_PORTB:
            GPIOB_REG->ODR = (GPIOB_REG->ODR & ~(1<<(enuPinNumCpy))) |enuPinValueCpy<<(enuPinNumCpy);
    		break;
    	case GPIO_PORTC:
            GPIOC_REG->ODR = (GPIOC_REG->ODR & ~(1<<(enuPinNumCpy))) |enuPinValueCpy<<(enuPinNumCpy);
    		break;
    	default:
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    		break;
    	}
    }

	return enuErrorStatLoc;
}

tenuErrorStatus GPIO_enuTogglePinValue(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;

    enuErrorStatLoc = GPIO_enuPinCheck(enuPortNumCpy, enuPinNumCpy);

    if(enuErrorStatLoc == E_OK)
    {
        switch(enuPortNumCpy)
    	{
    	case GPIO_PORTA:
            GPIOA_REG->ODR = (GPIOA_REG->ODR) ^ (1<<enuPinNumCpy);
    		break;
    	case GPIO_PORTB:
            GPIOB_REG->ODR = (GPIOB_REG->ODR) ^ (1<<enuPinNumCpy);
    		break;
    	case GPIO_PORTC:
            GPIOC_REG->ODR = (GPIOC_REG->ODR) ^ (1<<enuPinNumCpy);
    		break;
    	default:
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    		break;
    	}
    }

	return enuErrorStatLoc;
}

tenuErrorStatus GPIO_enuReadPinValue(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy, uint8* pu8PinValue)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    if(pu8PinValue == NULL_PTR)
    {
        enuErrorStatLoc = E_NOK_NULL_POINTER;
    }
    else
    {
        enuErrorStatLoc = GPIO_enuPinCheck(enuPortNumCpy, enuPinNumCpy);
    }

    if(enuErrorStatLoc == E_OK)
    {
        switch(enuPortNumCpy)
    	{
    	case GPIO_PORTA:
            *pu8PinValue = (GPIOA_REG->IDR>>enuPinNumCpy) & 1;
    		break;
    	case GPIO_PORTB:
            *pu8PinValue = (GPIOB_REG->IDR>>enuPinNumCpy) & 1;
    		break;
    	case GPIO_PORTC:
            *pu8PinValue = (GPIOC_REG->IDR>>enuPinNumCpy) & 1;
    		break;
    	default:
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    		break;
    	}
    }

	return enuErrorStatLoc;
}

static tenuErrorStatus GPIO_enuPinCheck(tenuGPIO_portNum enuPortNumCpy, tenuGPIO_pinNum enuPinNumCpy)
{
    tenuErrorStatus enuErrorStatLoc = E_OK;
    if(enuPinNumCpy>GPIO_PIN15)
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else if((enuPortNumCpy==GPIO_PORTA)&&(enuPinNumCpy>GPIO_PIN12))
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else if((enuPortNumCpy==GPIO_PORTB)&&((enuPinNumCpy==GPIO_PIN2)||(enuPinNumCpy==GPIO_PIN3)||(enuPinNumCpy==GPIO_PIN4)))
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else if((enuPortNumCpy==GPIO_PORTC)&&(enuPinNumCpy<GPIO_PIN13))
    {
        enuErrorStatLoc = E_NOK_PARAMETER_OUT_OF_RANGE;
    }
    else
    {
        enuErrorStatLoc = E_OK;
    }

    return enuErrorStatLoc;
}
