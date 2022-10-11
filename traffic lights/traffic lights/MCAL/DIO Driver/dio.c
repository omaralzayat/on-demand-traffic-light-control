/*
 * dio.c
 *
 * Created: 10/6/2022 1:48:15 PM
 *  Author: omara
 */ 

#include "dio.h"

EN_DIO_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch (portNumber)
	{
		case portA:
			if (direction == IN)
			{
				DDRA &= ~(1<<pinNumber);
			} 
			else if (direction == OUT)
			{
				DDRA |= (1<< pinNumber);
			}
		break;
		case portB:
			if (direction == IN)
			{
				DDRB &= ~(1<<pinNumber);
			}
			else if (direction == OUT)
			{
				DDRB |= (1<< pinNumber);
			}
		break;
		case portD:
		if (direction == IN)
		{
			DDRD &= ~(1<<pinNumber);
		}
		else if (direction == OUT)
		{
			DDRD |= (1<< pinNumber);
		}
		break;
	}
	return DIO_OK;
}

EN_DIO_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch (portNumber)
	{
		case portA:
			if (value == LOW)
			{
				PORTA &= ~(1<<pinNumber);
			}
			else if (value == HIGH)
			{
				PORTA |= (1<< pinNumber);
			}
		break;
		case portB:
			if (value == LOW)
			{
				PORTB &= ~(1<<pinNumber);
			}
			else if (value == HIGH)
			{
				PORTB |= (1<< pinNumber);
			}
		break;
	}
	return DIO_OK;
}

EN_DIO_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch (portNumber)
	{
		case portA:
			PORTA ^= (1<< pinNumber);
		break;
		case portB:
			PORTB ^= (1<< pinNumber);
		break;
	}
	return DIO_OK;
}
EN_DIO_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
	switch (portNumber)
	{
		case portA:
		*value = (PINA&(1<<pinNumber))>>pinNumber;
		break;
		case portB:
		*value = (PINB&(1<<pinNumber))>>pinNumber;
		break;
		case portD:
		*value = (PIND&(1<<pinNumber))>>pinNumber;
		break;
	}
	DIO_OK;
}
