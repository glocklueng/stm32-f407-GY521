void add_task( void (*pf)())     // добавление задачи на выполнение
   {
   if(tail_of_tasks == MAX_TASKS )
      tail_of_tasks=0;
   buffer_of_tasks[tail_of_tasks]=pf;
   tail_of_tasks++;
   number_of_tasks++;
   }

void delete_task()             // удаление задачи
    {
    if(head_of_tasks == MAX_TASKS)
        head_of_tasks=0;
    buffer_of_tasks[head_of_tasks]=0;
    head_of_tasks++;
    number_of_tasks--;
    }



void red_on()     // просто тестовые задачи
    {
    GPIOD->ODR |= PORTD_14_on;
    }

void red_off()    // просто тестовые задачи
    {
    GPIOD->ODR &= PORTD_14_off;
    }


void blue_on()     // просто тестовые задачи
    {
    GPIOD->ODR |= PORTD_15_on;
    }
void blue_off()
    {
    GPIOD->ODR &= PORTD_15_off;
    }
void orange_on()
    {
    GPIOD->ODR |= PORTD_13_on;
    }
void orange_off()
    {
    GPIOD->ODR &= PORTD_13_off;
    }
void green_on()
    {
    GPIOD->ODR |= PORTD_12_on;
    }
void green_off()
    {
    GPIOD->ODR &= PORTD_12_off;
    }