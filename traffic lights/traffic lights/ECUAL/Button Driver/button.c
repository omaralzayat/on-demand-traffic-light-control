/*
 * button.c
 *
 * Created: 10/6/2022 1:50:09 PM
 *  Author: omara
 */ 
#include "button.h"

EN_Button_t Button_init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPort, buttonPin, IN); //initialize DIO pin
	//Initialize Interrupt
	sei();
	ISC();
	En_Ext_INT();
	return Button_OK;
}

uint8_t Button_read(uint8_t buttonPort, uint8_t buttonPin)
{
	uint8_t value = 0;
	DIO_read(buttonPort, buttonPin, &value);
	return value;
}
