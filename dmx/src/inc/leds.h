/*
 * leds.h
 *
 *  Created on: Jun 11, 2014
 *      Author: reuben
 */

#ifndef LEDS_H_
#define LEDS_H_

#define LED_NUM_MAX		8

#define LED1			1
#define LED2			2
#define LED3			3
#define LED4			4
#define LED5			5
#define LED6			6
#define LED7			7
#define LED8			8

#define LED_ON			-1
#define LED_OFF	 		0

// #define ledControl(n,s) led_stat[(n - 1)] = (s)
void ledControl(unsigned char led_num, unsigned int ledTon);

void ledInit(void);
void ledTasking(unsigned long tick_sec);


#endif /* LEDS_H_ */
