/*
 * timer.c
 *
 * Created: 10/6/2022 1:48:43 PM
 *  Author: omara
 */ 
#include "timer.h"

unsigned int overflowCounter = 0;


EN_Timer_t timer_init(){
	TCCR0 = 0x00; //Set to normal mode
	TCNT0 = 0x0C; //Set initial value
	return Timer_OK;
}

EN_Timer_t set_prescaler(){
	TCCR0 |= (1<<0) | (1<<2);
}

EN_Timer_t timer_wait(unsigned int ts){
	set_prescaler();
	while(overflowCounter < (ts*NUMBER_OF_OVERFLOWS)){
		while((TIFR & (1<<0)) == 0);
		//Clear overflow flag
		timer_reset();
		overflowCounter++;
	}

	counter_reset();
	overflowCounter = 0;
	return Timer_OK;
}

EN_Timer_t timer_reset(){
	TIFR |= (1<<0);
	TCNT0 = 0x0C;
	return Timer_OK;
}
EN_Timer_t counter_reset(){
		TCCR0 = 0x00;
		return Timer_OK;
}
