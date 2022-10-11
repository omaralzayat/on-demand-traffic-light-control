/*
 * timer.h
 *
 * Created: 10/6/2022 1:47:22 PM
 *  Author: omara
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../registers.h"
#include "../types.h"

#define NUMBER_OF_OVERFLOWS 4


EN_Timer_t timer_init();
EN_Timer_t timer_wait(unsigned int ts);


#endif /* TIMER_H_ */