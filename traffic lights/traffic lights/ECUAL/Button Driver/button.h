/*
 * button.h
 *
 * Created: 10/6/2022 1:50:41 PM
 *  Author: omara
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Driver/interrupt.h"

#define BUTTON_PORT portD
#define BUTTON_PIN 2


EN_Button_t Button_init(uint8_t buttonPort, uint8_t buttonPin);
uint8_t Button_read(uint8_t buttonPort, uint8_t buttonPin);


#endif /* BUTTON_H_ */