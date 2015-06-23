#include <math.h>
void read_data_acc()
	{
	char data[10];
        int i=0;
	orange_on();
	
        acc_z=0;
        acc_x=0;
        acc_y=0;
        
        acc_x |= (read_i2C2(0xD0,0x3B)<<8);
        delay
        acc_x |= read_i2C2(0xD0,0x3C);
        delay
        delay
        delay
        
        acc_y |= (read_i2C2(0xD0,0x3D)<<8);  
        delay
        acc_y |= read_i2C2(0xD0,0x3E);
        delay
        delay
        delay
        
        acc_z |= (read_i2C2(0xD0,0x3F)<<8);
        delay
        acc_z |= read_i2C2(0xD0,0x40);
        

        last_acc_x[counter_filter] = acc_x;
        last_acc_y[counter_filter] = acc_y;
        last_acc_z[counter_filter] = acc_z;
        ///*
        if(start_filter){
          u32 sum;
          sum=0;
          
          //----------------------
          for(i=0;i<SIZE;i++){
            sum+=last_acc_x[counter_filter];
          }
          sum/=SIZE;
          if (abs(sum - acc_x) >100 )
            acc_x=sum;
          //----------------------
          sum=0;
          for(i=0;i<SIZE;i++){
            sum+=last_acc_y[counter_filter];
          }
          sum/=SIZE;
          if (abs(sum - acc_y) >100)
            acc_y=sum;
          //----------------------
          sum=0;
          for(i=0;i<SIZE;i++){
            sum+=last_acc_z[counter_filter];
          }
          sum/=SIZE;
          if (abs(sum - acc_z) >100)
            acc_z=sum;
        
          
        }
        // */
        //for()
        
        data[0] = 'x';
	data[1] = (acc_x>>8);
        data[2] = (0xff & acc_x);
        data[3] = 'y';
	data[4] = (acc_y>>8);
        data[5] = (0xff & acc_y);

        data[6] = 'z';
	data[7] = (acc_z>>8);

        data[8] = (0xff & acc_z);
	data[9] = 0x03;
       
        
	orange_off();
        counter_filter++;
        if(counter_filter==SIZE){
          counter_filter=0;
          start_filter=true;
        }
        send_string_uart_1(data);
        }
void read_data_gyro()
	{
	char data[9];
	orange_on();
	gyro_x=0;
        gyro_y=0;
        gyro_z=0;
	data[0] = (gyro_x |= read_i2C2(0xD0,0x43)<<8);
	data[1] = (gyro_x |= read_i2C2(0xD0,0x44));
	data[2] = 0;
	data[3] = (gyro_y |= read_i2C2(0xD0,0x45)<<8);
	data[4] = (gyro_y |= read_i2C2(0xD0,0x46));
	data[5] = 0;
	data[6] = (gyro_z |= read_i2C2(0xD0,0x47)<<8);
	data[7] = (gyro_z |= read_i2C2(0xD0,0x48));
	data[8] = 0x03;

	orange_off();
	send_string_uart_1(data);
	}