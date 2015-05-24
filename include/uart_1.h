void send_uart_1(char data)
	{
	while(!(USART1->SR & USART_SR_TC))
		{}
	USART1->DR = data;
	}