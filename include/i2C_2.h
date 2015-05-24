void I2C2_EV_IRQHandler()
  {
  switch(I2C2->SR1)
    {
    // case I2C_SR1_TXE:
    //   {
      // green_on();
      // I2C2->DR=tx_data_i2c[head_of_I2C2_tx];
      // head_of_I2C2_tx++;
      // if(head_of_I2C2_tx==8)
      //   head_of_I2C2_tx=0;
      // number_of_I2C2_tx--;
      // if( number_of_I2C2_tx == 0)
      //   {
      //   (void) I2C2->SR1;
      //   I2C2->CR1 |= I2C_CR1_STOP;
      //   I2C2->CR2&= ~(I2C_CR2_ITBUFEN | I2C_CR2_ITEVTEN);   // прерывание по пустому буферу - флаг - TxE
      //   I2C2->CR1&=~I2C_CR1_PE;
      //   I2C2->CR1|=I2C_CR1_PE;
      //   }
      // }
    // break;
    case I2C_SR1_RXNE:
      green_on();
      buffer_i2c2=I2C2->DR;
      I2C2->CR1 |= I2C_CR1_STOP;
      I2C2->CR2&= ~(I2C_CR2_ITBUFEN | I2C_CR2_ITEVTEN);
    break;
    case I2C_SR1_BTF:
      I2C2->CR1 |= I2C_CR1_STOP;
      I2C2->CR2&= ~(I2C_CR2_ITBUFEN | I2C_CR2_ITEVTEN);
    break;
    case I2C_SR1_STOPF:
      I2C2->CR1 |= I2C_CR1_STOP;
      I2C2->CR2&= ~(I2C_CR2_ITBUFEN | I2C_CR2_ITEVTEN);
    break;
    }
  }
void read_i2C2(char device_adress, char register_adress)
  {
  I2C2->CR1 |= I2C_CR1_START;
  while(!(I2C2->SR1 & I2C_SR1_SB));
  I2C2->CR1|=I2C_CR1_ACK;
  // (void) I2C2->SR1;
  I2C2->DR = (device_adress);
  while (!(I2C2->SR1 & I2C_SR1_ADDR)); // ожидаем окончания передачи адреса
  (void) I2C2->SR1;  // по даташиту это надо читать...
  (void) I2C2->SR2;  //
  I2C2->DR = (register_adress) | 1;
  while (!(I2C2->SR1 & I2C_SR1_ADDR)); // ожидаем окончания передачи адреса
  (void) I2C2->SR1;  // по даташиту это надо читать...
  (void) I2C2->SR2;  //
  I2C1->CR1 |= I2C_CR1_STOP;

  I2C1->CR1&=~I2C_CR1_PE;
  I2C1->CR1|=I2C_CR1_PE;
  }


// void i2C2_tx(char adress, char data, char tx_or_rx)
//     {
//     I2C2->CR1 |= I2C_CR1_START;
//     while(!(I2C2->SR1 & I2C_SR1_SB));
//     (void) I2C2->SR1;
//     I2C2->DR = (adress<<1);
//     while (!(I2C2->SR1 & I2C_SR1_ADDR)); // ожидаем окончания передачи адреса
//     (void) I2C2->SR1;  // по даташиту это надо читать...
//     (void) I2C2->SR2;  //

//     // I2C2->CR2|= I2C_CR2_ITBUFEN | I2C_CR2_ITEVTEN;   // прерывание по пустому буферу - флаг - TxE
//     }