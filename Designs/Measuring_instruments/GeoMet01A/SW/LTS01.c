float LTS01_get_temp()
{
unsigned int8 MSB;
unsigned int8 LSB;
signed int16  data;

   i2c_start();
   I2C_Write(LTS01A_address);
   I2C_write(0x00);
   i2c_stop();
   i2c_start();
   I2C_Write(LTS01A_address+1);
   MSB=i2c_read(1);
   LSB=i2c_read(0);
   i2c_stop(); 

   data = MAKE16(MSB,LSB);

 return (data * 0.00390625 );

}
