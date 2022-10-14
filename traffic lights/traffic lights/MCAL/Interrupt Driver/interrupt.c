/*
 * interrupt.c
 *
 * Created: 10/6/2022 1:48:04 PM
 *  Author: omara
 */ 
#include "interrupt.h"

EN_Interrupt_t sei()
 {
	SREG |= (1<<7); //Set interrupt flag to 1
	return Interrupt_OK;
 }
 
EN_Interrupt_t ISC()
{
	MCUCR |= (1<<0) | (1<<1); //ISC00 and ISC01 = 1 1 for rising edge
	return Interrupt_OK;
}

EN_Interrupt_t En_Ext_INT()
{
	GICR |= (1<<6); //Set bit 6 to 1 to enable INT0
	return Interrupt_OK;
}

EN_Interrupt_t interrupt_init(){
		sei();
		ISC();
		En_Ext_INT();
		return Interrupt_OK;
}
