/*
 * app.h
 *
 * Created: 10/6/2022 1:46:54 PM
 *  Author: omara
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED Driver/led.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Interrupt Driver/interrupt.h"

#define redstate 1
#define greenstate 0
#define redyellowstate 2
#define greenyellowstate 3

void App_init();
void appStart();
void Normal_mode();
void ped_mode();
void clear_interrupt();
void wait_interrupt(uint8_t ts);
void LED_blink_interrupt(uint8_t LEDport, uint8_t LEDpin, uint8_t delay);

#endif /* APP_H_ */