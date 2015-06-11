void read_data_acc()
	{
	u8 data[9];
	acc_x=acc_y=acc_z=0;
	data[0] = (acc_x |= read_i2C2(0xD0,0x3B)<<8);
	data[1] = (acc_x |= read_i2C2(0xD0,0x3C));
	data[2] = 0;
	data[3] = (acc_y |= read_i2C2(0xD0,0x3D)<<8);
	data[4] = (acc_y |= read_i2C2(0xD0,0x3E));
	data[5] = 0;
	data[6] = (acc_z |= read_i2C2(0xD0,0x3F)<<8);
	data[7] = (acc_z |= read_i2C2(0xD0,0x40));
	data[8] = 0x03;

	send_string_uart_1(data);
	}
void read_data_gyro()
	{
	u8 data[9];
	gyro_x=gyro_y=gyro_z=0;
	data[0] = (gyro_x |= read_i2C2(0xD0,0x43)<<8);
	data[1] = (gyro_x |= read_i2C2(0xD0,0x44));
	data[2] = 0;
	data[3] = (gyro_y |= read_i2C2(0xD0,0x45)<<8);
	data[4] = (gyro_y |= read_i2C2(0xD0,0x46));
	data[5] = 0;
	data[6] = (gyro_z |= read_i2C2(0xD0,0x47)<<8);
	data[7] = (gyro_z |= read_i2C2(0xD0,0x48));
	data[8] = 0x03;

	send_string_uart_1(data);
	}