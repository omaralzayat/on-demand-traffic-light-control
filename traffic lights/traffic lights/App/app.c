/*
 * app.c
 *
 * Created: 10/6/2022 1:46:37 PM
 *  Author: omara
 */ 
#include "app.h"

uint8_t state = greenyellowstate;
uint8_t pressed;
uint8_t interrupted = 0;

void appStart()
{
	//initialize LED, Button and Timer drivers
	LED_init(LED_car, Green);
	LED_init(LED_car, Yellow);
	LED_init(LED_car, Red);
	LED_init(LED_ped, Green);
	LED_init(LED_ped, Yellow);
	LED_init(LED_ped, Red);
	Button_init(BUTTON_PORT,BUTTON_PIN);
	timer_init();
	while(1)
	{
		//operate in normal mode if not interrupted
		Normal_mode();
	}

}

void Normal_mode()
{
	switch (state){
		case redstate: //if the red-LED was on make yellow blink for five seconds
			state = greenyellowstate;
			LED_blink(LED_car, Yellow, 5);
			LED_off(LED_car, Yellow);
		break;
		case greenstate: //if green-LED was on make yellow blink for 5 seconds
			state = redyellowstate;
			LED_blink(LED_car, Yellow, 5);
			LED_off(LED_car, Yellow);
		break;
		case redyellowstate: //if yellow is blinking after red was on make green on for five seconds
			state = redstate;
			LED_on(LED_car, Red);
			timer_wait(5);
			LED_off(LED_car, Red);
		break;
		case greenyellowstate: //if yellow is blinking after green was on make red on for five seconds
			state = greenstate;
			LED_on(LED_ped, Red);
			LED_on(LED_car, Green);
			timer_wait(5);
			LED_off(LED_car, Green);
		break;

	}
}

//ped_mode called inside of the timer_wait function if the button is pressed
void ped_mode(){
	pressed = 0;
	interrupted = 1;
	switch (state)
	{
		case greenstate: case redyellowstate: case greenyellowstate: //if it was green or yellow on make both yellows blink for 5secs and then pedestrian green and car
		LED_off(LED_ped, Red);										 //red on for 5secs
		LED_off(LED_car, Green);
		LEDs_2blink(LED_car, Yellow, LED_ped, Yellow, 5);
		LED_off(LED_ped, Yellow);
		LED_off(LED_car, Yellow);
		LED_on(LED_car, Red);
		LED_on(LED_ped, Green);
		timer_wait(5);
		LED_off(LED_ped, Green);
		LED_off(LED_car, Red);
		break;
		case redstate: //if car red-LED was on open pedestrian green-LED for 5secs
		LED_off(LED_ped, Red);
		LED_on(LED_ped, Green);
		timer_wait(5);
		LED_off(LED_ped, Green);
		break;
		default:
		break;
	}
	//open car green LED afterwards
	LED_on(LED_ped, Red);
	state = greenyellowstate;
	interrupted = 0;
}

ISR(EXT_INT_0)
{
	if (!interrupted)
	{
		pressed = 1;
	}
}

void clear_interrupt(){
	pressed = 0;
}