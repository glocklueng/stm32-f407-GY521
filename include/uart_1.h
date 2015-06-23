
void iteration_head_recive_uart_1()
	{
	head_recive_uart_1++;
	if(head_recive_uart_1==MAX_RX_BUF_SIZE)
		head_recive_uart_1=0;
	}

void send_uart_1(char data)
	{
	while(!(USART1->SR & USART_SR_TC))
		{}
	USART1->DR = data;
	}

void send_string_uart_1(char *data)
	{
	while( (*data)!=0x03)
		{
                buffer_transmit_uart_1[tail_transmit_uart_1] = (*data++);
		tail_transmit_uart_1++;
		if( tail_transmit_uart_1 == MAX_TX_BUF_SIZE)
			tail_transmit_uart_1=0;
		}
	tail_transmit_uart_1++;
	if( tail_transmit_uart_1 == MAX_TX_BUF_SIZE)
		tail_transmit_uart_1=0;
	buffer_transmit_uart_1[tail_transmit_uart_1]=0x03;
	USART1->CR1|= USART_CR1_TXEIE;
	}

void scan_uart1()
	{
	switch( buffer_recive_uart_1[head_recive_uart_1] )
		{
		case 'e':
			{
			iteration_head_recive_uart_1();
			iteration_head_recive_uart_1();
			}
		break;
		case 'q':
			{
			iteration_head_recive_uart_1();
			iteration_head_recive_uart_1();
			}
		break;
		}
	}