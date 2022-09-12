/*
 * 27-ADC_EX_2.c
 *
 * Created: 8/18/2022 4:02:04 AM
 * Author : Islam Ashraf 
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "ADC_driver.h"

unsigned short temperature;
int main(void)
{
   LCD_vInit();
   ADC_vInit();
   LCD_vSend_string("temperature=");
    while (1) 
    {
		temperature=(ADC_u16read()*(0.25));
		if (temperature<10)
		{
			 LCD_movecursor(1,13);
			 LCD_vSend_char(0x30);
			 LCD_vSend_char((temperature)+48);
			 LCD_vSend_char(0xDF);
			 LCD_vSend_char(0x43);
			 
		}
		else if (temperature<100)
		{
			 LCD_movecursor(1,13);
			 LCD_vSend_char((temperature/10)+48);
			 LCD_vSend_char((temperature%10)+48);
			 LCD_vSend_char(0xDF);
			 LCD_vSend_char(0x43);
		}
    }
}

