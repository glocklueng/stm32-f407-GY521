// system_dev.h
#define MAX_TASKS 32	 // макс кол-во задач

// GPIO
#define AF7_7 (1<<30)|(1<<29)|(1<<28)	// altertative func portb 7
#define AF7_6 (1<<26)|(1<<25)|(1<<24)	// altertative func portb 6

#define FAST_SPEED_7 (1<<15)
#define FAST_SPEED_6 (1<<13)

#define AF5_5 (5<<20)
#define AF5_6 (5<<24)
#define AF5_7 (5<<13)
//#define
#define PORTD_15_on (1<<15)		// диоды
#define PORTD_15_off ~(1<<15)
#define PORTD_14_on (1<<14)
#define PORTD_14_off ~(1<<14)
// RCC
#define SPI1_EN (1<<12)		// тактирование SPI1
#define USART1_EN (1<<4)	// тактирование uart1 в RCC
#define GPIOD_EN (1<<3)  	// вкл тактирование PORTD
#define GPIOB_EN (1<<1)  	// вкл тактирование PORTB
#define GPIOA_EN 1			// вкл тактирование PORTA
#define GPIOE_EN (1<<4)		// вкл тактирование PORTE
#define HSEBYP  (1<<18)		// тоже для HSE
#define HSEON (1<<16)		// вкл HSE
#define HSION (1)
#define SW_0 (1)			// выбор источника тактирования
#define SW_1 (1<<1)			//
// UART_1

#define UE (1<<13)		// вкл uart1
#define TE (1<<3)		// разрешаем передачу
#define SYS_CLK 8000000UL               // частота кварца
// #define HSE_VALUE 8000000UL				// HSE на 8МГц
#define BAUDRATE_USART_1 9600UL         // скорость UASRT_1
#define PCE (1<<10)
//#define

// SPI_1

#define DFF (1<<11)	// data frame 8/16 bit
#define MSTR (1<<2)	// master
#define SPE (1<<6)	// SPI enable
#define TXE (1<<1)
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
//#define
