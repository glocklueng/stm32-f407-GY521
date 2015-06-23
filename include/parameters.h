// -------- system_dev.h
u32 tail_of_tasks=0;
u32 head_of_tasks=0;
u32 number_of_tasks=0;
void (*buffer_of_tasks[MAX_TASKS])();
// uart_1.h
u8 buffer_transmit_uart_1[MAX_TX_BUF_SIZE];
u8 tail_transmit_uart_1=0;
u8 head_transmit_uart_1=0;

u8 buffer_recive_uart_1[MAX_RX_BUF_SIZE];
u8 tail_recive_uart_1=0;
u8 head_recive_uart_1=0;

// i2c2
u8 buffer_recive_i2c2[MAX_RX_BUF_SIZE];
u8 buffer_i2c2=0;

// TIM6
u8 counter=0;
u8 flag=0;
bool start=false;
// data
u16 acc_x=0;
u16 acc_y=0;
u16 acc_z=0;

u16 gyro_x=0;
u16 gyro_y=0;
u16 gyro_z=0;

u16 last_acc_x[SIZE];
u16 last_acc_y[SIZE];
u16 last_acc_z[SIZE];

u16 counter_filter;

bool start_filter=false;

u16 last_gyro_x[SIZE];
u16 last_gyro_y[SIZE];
u16 last_gyro_z[SIZE];