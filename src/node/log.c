#include "node/log.h"
#include "stm32f10x.h"

/* this function is used by C lib's printf() function, should enable MicroLib in Arm Keil option page*/
int fputc(int ch, FILE *f)
{
    USART_SendData(USART1, (unsigned char) ch);
    while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);
    return (ch);
}


