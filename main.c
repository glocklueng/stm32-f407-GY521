#include "stm32f4xx.h"
#include "defines.h"
#include "parameters.h"
#include "initialization.h"
#include "system_dev.h"
#include "uart_1.h"

int main()
{
init_GPIO();
init_RCC();

return 0;
}
