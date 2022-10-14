/*
 * led.h
 *
 * Created: 10/6/2022 1:50:30 PM
 *  Author: omara
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"

#define LED_car portA
#define LED_ped portB
#define Green 0
#define Yellow 1
#define Red 2


EN_LED_t LED_init(uint8_t LEDport, uint8_t LEDpin);
EN_LED_t LED_on(uint8_t LEDport, uint8_t LEDpin);
EN_LED_t LED_off(uint8_t LEDport, uint8_t LEDpin);
EN_LED_t LED_blink(uint8_t LEDport, uint8_t LEDpin, uint8_t delay);
EN_LED_t LEDs_2blink(uint8_t LEDport1, uint8_t LEDpin1, uint8_t LEDport2, uint8_t LEDpin2,uint8_t delay);



#endif /* LED_H_ */
