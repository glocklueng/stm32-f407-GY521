#include "stm32f4xx.h"
#include "defines.h"
#include "parameters.h"
#include "initialization.h"
#include "system_dev.h"
#include "uart_1.h"


void USART1_IRQHandler(void)
	{
	if(USART1->SR & USART_SR_RXNE)
		{
		u8 buf;
		if(tail_recive_uart_1 == MAX_RX_BUF_SIZE)
			tail_recive_uart_1=0;
		buffer_recive_uart_1[tail_recive_uart_1] = USART1->DR;
		if(buffer_recive_uart_1[tail_recive_uart_1] == 0x03)
			scan_uart1();
		tail_recive_uart_1++;
		blue_off();
		return;
		}
	if(USART1->SR & USART_SR_TXE)
		{
		red_on();
		USART1->DR = buffer_transmit_uart_1[head_transmit_uart_1];
		head_transmit_uart_1++;
		if(head_transmit_uart_1 == MAX_TX_BUF_SIZE)
			head_transmit_uart_1=0;
		if(head_transmit_uart_1 == tail_transmit_uart_1)
			{
			USART1->CR1 &= ~USART_CR1_TXEIE;
			red_off();
			}
		return;
		}
	}

int main()
{
char data[8]={'t','e','s','t','e','d',0x03};
init_RCC();
init_GPIO();
// add_task(green_on);
// add_task(red_on);
// add_task(orange_on);
// add_task(blue_on);
init_UART1();
__enable_irq();
send_string_uart_1(data);
send_string_uart_1(data);
send_string_uart_1(data);


while(1)
    {
    while(!number_of_tasks)
        {}
    (*buffer_of_tasks[head_of_tasks])();
    delete_task();
    }
return 0;
}
