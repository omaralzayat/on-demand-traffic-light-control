/*
 * dio.h
 *
 * Created: 10/6/2022 1:47:10 PM
 *  Author: omara
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../registers.h"
#include "../types.h"

#define portA 'A'
#define portB 'B'
#define portD 'D'

//direction defines
#define IN 0
#define OUT 1

//values defines
#define LOW 0
#define HIGH 1

//error state enumerate

EN_DIO_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);	//Direction initialization
EN_DIO_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);	//Write register
EN_DIO_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber);		//toggle the pin output
EN_DIO_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value);	//Read register

#endif /* DIO_H_ */