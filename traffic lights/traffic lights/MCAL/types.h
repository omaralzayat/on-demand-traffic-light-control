/*
 * types.h
 *
 * Created: 10/7/2022 3:07:06 PM
 *  Author: omara
 */ 


#ifndef TYPES_H_
#define TYPES_H_


typedef unsigned char uint8_t;
typedef enum EN_DIO_t{
	DIO_OK, DIO_ERROR
}EN_DIO_t;

typedef enum EN_Interrupt_t{
	Interrupt_OK, Interrupt_ERROR
}EN_Interrupt_t;

typedef enum EN_Timer_t{
	Timer_OK, Timer_ERROR
}EN_Timer_t;

typedef enum EN_LED_t{
	LED_OK, LED_ERROR
}EN_LED_t;

typedef enum EN_Button_t{
	Button_OK, Button_ERROR
}EN_Button_t;


#endif /* TYPES_H_ */