void init_RCC()
    {
    RCC->CR |= HSEBYP | HSEON;      // включаем HSE
    RCC->CFGR|= SW_0;               // тактируем SYS_CLK от HSE

    RCC->APB2ENR |= SPI1_EN;         // вкл тактирование spi_1
    RCC->AHB1ENR |= GPIOA_EN;        // вкл тактирование PORTA
    RCC->AHB1ENR |= GPIOB_EN;        // вкл тактирование PORTB
    RCC->AHB1ENR |= GPIOD_EN;        // вкл тактирование PORTD
    RCC->AHB1ENR |= GPIOE_EN;        // вкл тактирование PORTD
    RCC->APB2ENR |= USART1_EN;       // вкл тактирование uart_1



    }
void init_GPIO()
    {
    // port A
    // 5,6,7 - SPI for acselerometer
    GPIOA->MODER |= GPIO_MODER_MODER7_1 | GPIO_MODER_MODER6_1 | GPIO_MODER_MODER5_1;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5_0 | GPIO_OSPEEDER_OSPEEDR6_0 | GPIO_OSPEEDER_OSPEEDR7_0;
    GPIOA->AFR[0] |= AF5_5 | AF5_6 | AF5_7;
    // port B
    // 6,7 - uart
    GPIOB->AFR[0]|= AF7_7 | AF7_6;
    GPIOB->OSPEEDR|=FAST_SPEED_7 | FAST_SPEED_6;
    GPIOB->MODER|= GPIO_MODER_MODER7_1 | GPIO_MODER_MODER6_1 ;//

    // D
    // 12,13,14,15 - LED's
    GPIOD->MODER|=(1<<30) | (1<<28);
    GPIOD->OSPEEDR|=(1<<30)| (1<<28);
    GPIOD->PUPDR|=(1<<30)| (1<<28);
    // E
    // 1,2 - acselerometer INT ,3 - acselerometer CS
    GPIOE->MODER |= GPIO_MODER_MODER1_1 | GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_0;
    GPIOE->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1_0 | GPIO_OSPEEDER_OSPEEDR2_0 | GPIO_OSPEEDER_OSPEEDR3_0;

    }
// portb 6,7
void init_UART1()
	{
    USART1->BRR =((HSE_VALUE+BAUDRATE_USART_1/16)/BAUDRATE_USART_1 );    // делитель на 9600
	//USART1->BRR = 0x00001117;
    USART1->CR1|= UE | TE ;//| PCE;
	}
//porta 5,6,7
// 7 - MOSI
// 6 - MISO
// 5 - SCK
void init_SPI()
    {
    SPI1->CR1 |= DFF | MSTR | SPE;
    }