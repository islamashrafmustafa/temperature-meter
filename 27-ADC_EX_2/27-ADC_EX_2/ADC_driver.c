/*
 * ADC_driver.c
 *
 * Created: 8/17/2022 3:03:40 PM
 *  Author: Islam ashraf
 */ 

#include <avr/io.h>
#include "std_macros.h"

void ADC_vInit(void)
{
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}


unsigned short ADC_u16read(void)
{
	unsigned short read_val;
	SET_BIT(ADCSRA,ADSC);
	while (IS_BIT_CLR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	read_val=ADCL;
	read_val|=(ADCH<<8);
	return read_val;
}