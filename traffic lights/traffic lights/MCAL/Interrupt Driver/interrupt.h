/*
 * interrupt.h
 *
 * Created: 10/6/2022 1:47:38 PM
 *  Author: omara
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../registers.h"
#include "../types.h"


EN_Interrupt_t sei(); //Enable general interrupt
EN_Interrupt_t ISC(); //Choose interrupt sense (rising edge in our case)
EN_Interrupt_t En_Ext_INT(); //Enable external interrupt pin (INT0)
EN_Interrupt_t interrupt_init();

void __vector_1(void) __attribute__((signal, used));
#define EXT_INT_0 __vector_1
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)
ISR(EXT_INT_0);


#endif /* INTERRUPT_H_ */