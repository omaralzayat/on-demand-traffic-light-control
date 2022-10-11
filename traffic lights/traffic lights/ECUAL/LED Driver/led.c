/*
 * led.c
 *
 * Created: 10/6/2022 1:49:53 PM
 *  Author: omara
 */ 
#include "led.h"

EN_LED_t LED_init(uint8_t LEDport, uint8_t LEDpin)
{
	DIO_init(LEDport, LEDpin, OUT);
	return LED_OK;
}

EN_LED_t LED_on(uint8_t LEDport, uint8_t LEDpin)
{
	DIO_write(LEDport, LEDpin, HIGH);
	return LED_OK;
}

EN_LED_t LED_off(uint8_t LEDport, uint8_t LEDpin)
{
	DIO_write(LEDport, LEDpin, LOW);
	return LED_OK;
}

EN_LED_t LED_blink(uint8_t LEDport, uint8_t LEDpin, uint8_t delay)
{
	uint8_t count = 0;
	while (count < delay)
	{
		DIO_toggle(LEDport, LEDpin);
		timer_wait(1);
		count++;
	}
	return LED_OK;
}

EN_LED_t LEDs_2blink(uint8_t LEDport1, uint8_t LEDpin1, uint8_t LEDport2, uint8_t LEDpin2,uint8_t delay)
{
	uint8_t count = 0;
	while (count < delay)
	{
		DIO_toggle(LEDport1, LEDpin1);
		DIO_toggle(LEDport2, LEDpin2);
		timer_wait(1);
		count++;
	}
	return LED_OK;
}
