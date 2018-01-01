/*
 * timer0.c
 *
 *  Created on: Jun 9, 2014
 *      Author: reuben
 */

#include "mb90540.h"
#include "eclipse_cpu.h"
#include "leds.h"
#include "timer0.h"

static unsigned int milisec_delay, seconds_delay;
static unsigned long tmr0_tick_msec;
static unsigned long tmr0_tick_sec;
static unsigned long saved_tmr0_tick_msec;
static unsigned char counterEvery30sec;

//-------------------------------------------------------------------
// timer0_init
// Purpose:
//  Initialize reload timer0 to 1ms
// Parameters:
// Returns:
//-------------------------------------------------------------------
void timer0_init(void)
{
	TMRLR0 = 16000000UL/32UL/1000UL - 1UL ; 	//0x01F4;  // set reload value [0x01F4 --> 1 msec resolution]
	TMCSR0 = 0x081B;  // prescaler 2us at 16 MHz

	counterEvery30sec = 0;
	milisec_delay = seconds_delay = 0;
	tmr0_tick_msec = tmr0_tick_sec = 0;

	TMCSR0_INTE = 1;
} // timer0_init

unsigned long get_tmr0_tick_msec(void)
{
	return tmr0_tick_msec;
}

void set_tmr0_tick_msec(unsigned long tick2set)
{
	tmr0_tick_msec = tick2set;
}

unsigned long get_tmr0_tick_sec(void)
{
	return tmr0_tick_sec;
}

void set_tmr0_tick_sec(unsigned long tick2set)
{
	tmr0_tick_sec = tick2set;
}

//-------------------------------------------------------------------
// timer0
// Purpose:
// Timer0 timer overflow interrupt 1ms resolution
// Parameters:
// Returns:
//-------------------------------------------------------------------
__interrupt void timer0(void)
{
	tmr0_tick_msec++;

	if(!(tmr0_tick_msec % 1000UL)){// over 1 second
		tmr0_tick_sec++;
		ledTasking(tmr0_tick_sec);

		if(!(tmr0_tick_sec % 30UL)) counterEvery30sec = 1; //over 30 seconds
	}

	if (seconds_delay){
		if(!((tmr0_tick_msec - saved_tmr0_tick_msec) % 1000UL)) seconds_delay--;
	}else saved_tmr0_tick_msec =  tmr0_tick_msec;

	if (milisec_delay)	milisec_delay--;

	TMCSR0_UF = 0;		// reset underflow interrupt request flag
} // timer0


//-------------------------------------------------------------------
// 	msec_delay
// 	Purpose:
//  	Waits miliseconds. The resolution is -+ 1ms.
//  	Uses the hardware timer0 for calculating the time.
// 	Parameters:
// 	 msec - the amount of time in msec to wait;
// 	Returns:
//-------------------------------------------------------------------

void msec_delay(unsigned int msec)
{
	milisec_delay = msec;
	while (milisec_delay);
} // msec_delay

//-------------------------------------------------------------------
// 	sec_delay
// 	Purpose:
//  	Waits seconds. The resolution is -+ 1sec.
//  	Uses the hardware timer0 for calculating the time.
// 	Parameters:
// 	 sec - the amount of time in seconds to wait;
// 	Returns:
//-------------------------------------------------------------------
void sec_delay(unsigned int sec)
{
	seconds_delay = sec;
	while (seconds_delay);
}


unsigned char getCounterEvery30sec(void)
{
	if(counterEvery30sec){
		counterEvery30sec = 0;
		return 1;
	}else return 0;
}
