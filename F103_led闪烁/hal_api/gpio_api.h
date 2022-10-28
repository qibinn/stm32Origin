#ifndef STM32L0_GPIO_API_H
#define STM32L0_GPIO_API_H

/*************************** ͷ�ļ� ***************************/
#include <stdint.h>
#include "stm32f10x_gpio.h"
/************************ �������Ͷ��� ************************/

/*!
 * Define the IRQ priority on the GPIO
 */
typedef enum eGpioIrqPriority
{
    IRQ_VERY_LOW_PRIORITY = 0,
    IRQ_LOW_PRIORITY,
    IRQ_MEDIUM_PRIORITY,
    IRQ_HIGH_PRIORITY,
    IRQ_VERY_HIGH_PRIORITY
	
}IrqPriority_t;


#endif
