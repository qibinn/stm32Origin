//=============================================================================
//�ļ����ƣ�main.h
//���ܸ�Ҫ��STM32F103C8���ļ��
//��Ȩ���У�Դ�ع�����www.vcc-gnd.com
//��Ȩ���£�2013-02-20
//���Է�ʽ��J-Link OB ARM SW��ʽ 5MHz
//=============================================================================

//##date:2022-10-26 ver:0.1 ���ӻ����Ĵ����շ�����



//ͷ�ļ�
#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "GPIOLIKE51.h"


#include "uart_api.h"

//��������
void GPIO_Configuration(void);

//=============================================================================
//�ļ����ƣ�Delay
//���ܸ�Ҫ����ʱ
//����˵����nCount����ʱ����
//�������أ���
//=============================================================================

void Delay(uint32_t nCount)
{
    for(; nCount != 0; nCount--);
}



static uint8_t m_sscom[255];
static uint8_t m_sscom_cur_len;


static UartConfig_t m_dgg_uart = {

    .uart_handle = {
        .USART_BaudRate = 9600,
        .USART_WordLength = USART_WordLength_8b,
        .USART_StopBits = USART_StopBits_1,
        .USART_Parity = USART_Parity_No,
        .USART_Mode = USART_Mode_Tx|USART_Mode_Rx,
        .USART_HardwareFlowControl = USART_HardwareFlowControl_None
    },
    
    .receive_flag = false,
    .receive_size = 0,
    .receive_buff = m_sscom,
        
    
    .TxDone = NULL,
    .RxDone = NULL
};





//=============================================================================
//�ļ����ƣ�main
//���ܸ�Ҫ��������
//����˵������
//�������أ�int
//=============================================================================
int main(void)
{
    /*
    *���Ӵ��ڲ��Գ��� 
    *��ֲlog.c��Դ��Ŀ
    */  
    
    Uart_Init(&m_dgg_uart);
    
    
    /*
    //< PA9,PA10 Usart1
    GPIO_InitTypeDef GPIO_InitStructure; 
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;    
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1, ENABLE);
    
    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    USART_Init(USART1, &USART_InitStructure);
    
    USART_Cmd(USART1, ENABLE);

    
    //< NVIC�жϿ���-ʹ���жϽ�������
    
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;   
    NVIC_Init(&NVIC_InitStructure);
    
    USART_ITConfig(USART1, USART_IT_RXNE|USART_IT_IDLE, ENABLE);
    */
    
    
    GPIO_Configuration();
    while (1)
    {
        
        USART_SendData(USART1,0x36);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
        m_sscom[m_sscom_cur_len] = m_sscom[m_sscom_cur_len];
        
        
        PCout(13)=1;
        Delay(0xfffff);
        Delay(0xfffff);	
        PCout(13)=0;
        Delay(0xfffff);
        Delay(0xfffff);			
    }
}

//=============================================================================
//�ļ����ƣ�GPIO_Configuration
//���ܸ�Ҫ��GPIO��ʼ��
//����˵������
//�������أ���
//=============================================================================
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 						 
    //=============================================================================
    //LED -> PC13
    //=============================================================================			 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}



