// -------- system_dev.h
u32 tail_of_tasks=0;
u32 head_of_tasks=0;
u32 number_of_tasks=0;
void (*buffer_of_tasks[MAX_TASKS])();
// uart_1.h
u8 buffer_transmit_uart_1[MAX_TX_BUF_SIZE];
u8 tail_transmit_uart_1=0;
u8 head_transmit_uart_1=0;

u8 buffer_recive_uart_1[MAX_TX_BUF_SIZE];
u8 tail_recive_uart_1=0;
u8 head_recive_uart_1=0;