// system_dev.h
#define MAX_TASKS 32	 // макс кол-во задач

// GPIO
#define AF7_7 (1<<30)|(1<<29)|(1<<28)	// altertative func portb 7
#define AF7_6 (1<<26)|(1<<25)|(1<<24)	// altertative func portb 6
#define AF4_10 (1<<10)	// altertative func portb 10
#define AF4_11 (1<<14)	// altertative func portb 11

#define FAST_SPEED_7 (1<<15)
#define FAST_SPEED_6 (1<<13)
#define FAST_SPEED_10 (1<<21)
#define FAST_SPEED_11 (1<<23)

#define AF5_5 (5<<20)
#define AF5_6 (5<<24)
#define AF5_7 (5<<13)
//#define
#define PORTD_15_on (1<<15)		// диоды
#define PORTD_15_off ~(1<<15)
#define PORTD_14_on (1<<14)
#define PORTD_14_off ~(1<<14)
#define PORTD_13_on (1<<13)
#define PORTD_13_off ~(1<<13)
#define PORTD_12_on (1<<12)
#define PORTD_12_off ~(1<<12)
// RCC
#define I2C2_EN (1<<22)		// тиактирование i2C_2
#define SPI1_EN (1<<12)		// тактирование SPI1
#define USART1_EN (1<<4)	// тактирование uart1 в RCC
#define GPIOD_EN (1<<3)  	// вкл тактирование PORTD
#define GPIOB_EN (1<<1)  	// вкл тактирование PORTB
#define GPIOA_EN 1			// вкл тактирование PORTA
#define GPIOE_EN (1<<4)		// вкл тактирование PORTE
#define HSEBYP  (1<<18)		// тоже дл€ HSE
#define HSEON (1<<16)		// вкл HSE
#define HSION (1)
#define SW_0 (1)			// выбор источника тактировани€
#define SW_1 (1<<1)			//
// UART_1
#define MAX_RX_BUF_SIZE 32	// максимальный размер буфера приЄма
#define MAX_TX_BUF_SIZE 32	// максимальный размер буфера отправки
#define MASK_SR_INTERRUPT_UART (1<<7) | (0x1F)		// маска дл€ проверки флагов прерываний в SR
#define RE (1<<2)		// разрешаем приЄм
#define UE (1<<13)		// вкл uart1
#define TE (1<<3)		// разрешаем передачу
	// #define RXNEIE (1<<5)	// прерывание по приЄму
#define SYS_CLK 8000000UL               // частота кварца
#define HSE_VALUE 8000000UL				// HSE на 8ћ√ц
#define BAUDRATE_USART_1 9600UL         // скорость UASRT_1
#define PCE (1<<10)
//#define

// SPI_1
#define DFF (1<<11)	// data frame 8/16 bit
#define MSTR (1<<2)	// master
#define SPE (1<<6)	// SPI enable
#define TXE (1<<1)

// i2C

//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
//#define
