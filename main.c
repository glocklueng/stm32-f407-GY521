#include "stm32f4xx.h"
#include "defines.h"
#include "parameters.h"
#include "initialization.h"
#include "system_dev.h"
#include "uart_1.h"
#include "i2C_2.h"


void TIM6_DAC_IRQHandler(void)
	{
	counter++;
	if(counter==2)
		{
		add_task(red_on);
		}
	if(counter==4)
		{
		char data[8]={'t','e','s','t','e','d',0x03};
		counter=0;
		send_string_uart_1(data);
		add_task(red_off);
		}
	TIM6->SR &= ~TIM_SR_UIF;
	return;
	}

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
char data[2]={0,0x03};
init_RCC();
init_GPIO();
init_UART1();
init_i2C_2();
init_TIM6();

__enable_irq();
i2C2_tx(0xD0,0x6B,0x00);	//

i2C2_tx(0xD0,0x1B,0xE0);
data[0] = read_i2C2(0xD0,0x1B);
send_string_uart_1(data);
data[0] = read_i2C2(0xD0,0x75);
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
