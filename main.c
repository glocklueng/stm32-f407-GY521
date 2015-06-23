#include "stm32f4xx.h"
#include "defines.h"
#include "parameters.h"
#include "initialization.h"
#include "system_dev.h"
#include "uart_1.h"
#include "i2C_2.h"
#include "tasks.h"


void TIM6_DAC_IRQHandler(void)
	{
        if(start)
          counter++;
        flag++;

	if(counter==1)
		{
                add_task(blue_on);
		}
	if(counter==3)
		{
		counter=0;
		add_task(blue_off);
		add_task(read_data_acc);		// read_data_gyro // read_data_acc
		start=0;
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
int i=0;
char data[2]={0,0x03};
init_RCC();
init_GPIO();
init_UART1();
init_i2C_2();
init_TIM6();

__enable_irq();
i2C2_tx(0xD0,0x6B,0x00);
flag=0;
while(flag!=3);
i2C2_tx(0xD0,0x1B,0xE0);
flag=0;
while(flag!=3);
i2C2_tx(0xD0,0x1C,0xE0);
flag=0;
while(flag!=3);

/*
i2C2_tx(0xD0,0x1B,0xE0);
i2C2_tx(0xD0,0x1C,0xE0);
i2C2_tx(0xD0,0x0D,0xFF);
i2C2_tx(0xD0,0x0E,0xFF);
i2C2_tx(0xD0,0x0F,0xFF);
i2C2_tx(0xD0,0x10,0x3F);
*/

i2C2_tx(0xD0,0x1A,0x06);
start=true;
while(1)
    {
    while(!number_of_tasks)
        {}
    (*buffer_of_tasks[head_of_tasks])();
    delete_task();
    }
return 0;
}
