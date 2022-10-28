#include "uart_api.h"


int Uart_Init( UartConfig_t* uart_config )
{
    if(NULL == uart_config)
    {
        return -1;
    }
    IRQn_Type irqn;
    
    switch( uart_config->uart_id )
	{
        case USART_1:
            
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
            irqn = USART1_IRQn;
        
        break;
        
        default:
        break;
    }
    
    //< ³õÊ¼»¯tx,rxµÄIO
    
    
    USART_Init(USART1,&(uart_config->uart_handle));

    // System interrupt init
	uint32_t priority = 0;
    
    
    
}