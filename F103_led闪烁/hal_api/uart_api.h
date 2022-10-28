//########################################################################################
//<@version:0.1
//<@date:2022-10-27
//<@brief:按照邓工的uart_api理一遍实现过程
//########################################################################################

#ifndef UART_API_H
#define UART_API_H

#include "stm32f10x_usart.h"
#include "gpio_api.h"
#include <stdbool.h>
#include <stddef.h>


typedef enum eUartID
{
	USART_1 = 0,
	USART_2,
	LPUART_1
	
}UartID_t;


//< uart configure
typedef struct UartConfig_s
{
    USART_InitTypeDef   uart_handle;
    const UartID_t      uart_id;           /// UART ID
    
    IrqPriority_t       irq_priority;      /// Uart Irq priority
    
    
    bool                receive_flag;      /// UART receive flag, 1 means a frame is received
    
    int                 receive_size;      /// size of data received
	uint8_t*            receive_buff;      /// buffer to store received data
    
    
    
    void (*TxDone)(void);                 /// callback for uart transmit complete
	void (*RxDone)(void); 
    
}UartConfig_t;




int Uart_Init( UartConfig_t* uart_config );



#endif
