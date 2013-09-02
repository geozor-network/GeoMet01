#include "main.h"

#define LCD_ENABLE_PIN  PIN_E0                                    ////
#define LCD_RS_PIN      PIN_E1                                    ////
#define LCD_RW_PIN      PIN_E2                                    ////
#define LCD_DATA4       PIN_D4                                    ////
#define LCD_DATA5       PIN_D5                                    ////
#define LCD_DATA6       PIN_D6                                    ////
#define LCD_DATA7       PIN_D7 
#include <lcd.c>

#include "../SHT25.h"
#include "../LTS01.h"
#include "./HMC5883L.h"
#include <math.h>


void main()
{
float temp1, temp2, humidity;
int16 i=0; 

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_ccp1(CCP_OFF);
   setup_comparator(NC_NC_NC_NC);      // This device COMP currently not supported by the PICWizard
   setup_oscillator(OSC_8MHZ);


   printf("GeoMet01A\r\n");
   printf("(c) Kaklik 2013\r\n");
   printf("www.mlab.cz\r\n");
   
   // Init the HMC5883L.  Set Mode register for
   // continuous measurements.
   hmc5883l_write_reg(HMC5883L_CFG_A_REG, 0x18);      // no average, maximal update range
   hmc5883l_write_reg(HMC5883L_CFG_B_REG, 0x00);      // minimal range
   hmc5883l_write_reg(HMC5883L_MODE_REG, 0x00);

   lcd_init();
   lcd_putc("(c) Kaklik 2013");
   lcd_gotoxy(3,2);
   lcd_putc("www.mlab.cz");
   Delay_ms(2000);
   lcd_init();

   while (TRUE)
   {
     lcd_gotoxy(1,1);
     temp1 = SHT25_get_temp();
     humidity = SHT25_get_hum();
     temp2= LTS01_get_temp();
     hmc5883l_read_data(); 
   
     printf(lcd_putc,"%f C %f \%%",temp1, humidity);
     lcd_gotoxy(1,2);
     printf(lcd_putc," %f C",temp2);
     printf("%ld %f %f %f ",i, temp1, humidity, temp2);
     printf("%Ld %Ld %Ld \n\r", compass.x, compass.y, compass.z);
     i++;
     Delay_ms(100);
   }

}
