#include "driver/serial.h"
#include "driver/config.h"


#include "stm32f10x.h"

void serial_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; 
    USART_InitTypeDef USART_InitStructure;

    /* config USART1 clock */ 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	/* Configure USART1 Rx (PA.10) as input floating */ 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 

	/* USART1 mode config */ 
	USART_InitStructure.USART_BaudRate = 115200; 
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; 
	USART_InitStructure.USART_StopBits = USART_StopBits_1; 
	USART_InitStructure.USART_Parity = USART_Parity_No ; 
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; 
	USART_Init(USART1, &USART_InitStructure); 
	USART_Cmd(USART1, ENABLE); 
}

