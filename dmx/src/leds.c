/*
 * leds.c
 *
 *  Created on: Jun 10, 2014
 *      Author: reuben
 */

#include "mb90540.h"
#include "timer0.h"
#include "leds.h"


#define led_off(n)	PDR2  |= (1<<(n));
#define led_on(n)	PDR2  &= ~(1<<(n));


static unsigned int led_stat[LED_NUM_MAX];
//volatile static unsigned long led_duty_cycle;
//volatile static unsigned int tick_seconds;

void ledInit(void)
{
	 DDR2 = 0xFF;	// configuration port2 as output
	 PDR2 = 0xFF; 	// off all the leds

}

void ledControl(unsigned char led_num, unsigned int ledTon)
{
	if(led_num > 0) led_stat[led_num - 1] = ledTon;
}


//unsigned char ledNum, unsigned char ledTon, unsigned char ledToff, unsigned char ledTc
void ledTasking(unsigned long tick_sec)
{
	unsigned char i;

	for(i=0;i<LED_NUM_MAX;i++){
		if(led_stat[i]){
			if(led_stat[i] == -1){
				led_on(i);
			}else if(led_stat[i] & (unsigned int)tick_sec){
					led_on(i);
				}else led_off(i);


		}else led_off(i);
	}
}
