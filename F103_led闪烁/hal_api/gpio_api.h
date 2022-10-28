#ifndef STM32L0_GPIO_API_H
#define STM32L0_GPIO_API_H

/*************************** 头文件 ***************************/
#include <stdint.h>
#include "stm32f10x_gpio.h"
/************************ 数据类型定义 ************************/

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
