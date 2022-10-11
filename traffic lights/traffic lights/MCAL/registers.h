/*
 * registers.h
 *
 * Created: 10/7/2022 3:08:01 PM
 *  Author: omara
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

// register A
#define PINA *((volatile uint8_t*) (0x39))
#define DDRA *((volatile uint8_t*) (0x3A))
#define PORTA *((volatile uint8_t*) (0x3B))

// register B
#define PINB *((volatile uint8_t*) (0x36))
#define DDRB *((volatile uint8_t*) (0x37))
#define PORTB *((volatile uint8_t*) (0x38))

// register D
#define PIND *((volatile uint8_t*) (0x30))
#define DDRD *((volatile uint8_t*) (0x31))
#define PORTD *((volatile uint8_t*) (0x32))

//Timer registers
#define TCCR0 *((volatile uint8_t*) (0x53))
#define TCNT0 *((volatile uint8_t*) (0x52))
#define TIFR *((volatile uint8_t*) (0x58))

//status register
#define SREG *((volatile uint8_t*) (0x5F))

//interrupt registers
#define MCUCR *((volatile uint8_t*) (0x55))
#define GICR *((volatile uint8_t*) (0x5B))


#endif /* REGISTERS_H_ */