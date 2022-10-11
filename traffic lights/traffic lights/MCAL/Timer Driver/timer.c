/*
 * timer.c
 *
 * Created: 10/6/2022 1:48:43 PM
 *  Author: omara
 */ 
#include "timer.h"
#include "../DIO Driver/dio.h"

unsigned int overflowCounter = 0;
extern uint8_t pressed = 0;


EN_Timer_t timer_init(){
	TCCR0 = 0x00; //Set to normal mode
	TCNT0 = 0x0C; //Set initial value
	return Timer_OK;
}

EN_Timer_t timer_wait(unsigned int ts){
	TCCR0 |= (1<<0) | (1<<2); //1024 prescaler
	uint8_t val;
	while(overflowCounter < (ts*NUMBER_OF_OVERFLOWS)){
		//interrupt during wait time
		if(pressed){
			while((TIFR & (1<<0)) == 0){
				DIO_read('D', 2, &val);
				if(!val){
					overflowCounter = 0;
					TIFR |= (1<<0);
					TCNT0 = 0x0C;
					TCCR0 = 0x00;
					ped_mode();
					break;
				}
				
			}
			if(!val){
				break;
			}
			else{
			clear_interrupt();
			}
		}
		//End of interrupt statement can be removed to use as a normal timer drive
		while((TIFR & (1<<0)) == 0);
		
		//Clear overflow flag
		TIFR |= (1<<0);
		TCNT0 = 0x0C;
		overflowCounter++;
	}

	overflowCounter = 0;
	TCCR0 = 0x00;
	return Timer_OK;
}
