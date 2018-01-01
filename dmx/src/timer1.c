/*
 * timer1.c
 *
 *  Created on: Nov 29, 2014
 *      Author: reuben
 */

#include "mb90540.h"
#include "eclipse_cpu.h"
#include "timer1.h"

volatile static unsigned int usec_delay;
volatile static unsigned int ow_usec_timeout;

//-------------------------------------------------------------------
// timer1_init
// Purpose:
//  Initialise reload timer1 to 1us
// Parameters:
// Returns:
//-------------------------------------------------------------------
void timer1_init(void)
{
	usec_delay = 0;
	ow_usec_timeout = 0;
	TMRLR1 = 0x08;  // set reload value [0x08 --> 1 usec resolution]
	TMCSR1 = 0x001B;  // prescaler 125ns at 16 MHz
	//TMCSR1 = 0x0018;  // prescaler 125ns at 16 MHz
	//TMCSR1_INTE = 1;
} // timer1_init

void timer1_stop(void)
{
	TMCSR1_CNTE = 0;
	TMCSR1_INTE = 0;

}

void timer1_start(void)
{
	TMCSR1_INTE = 1;
	TMCSR1_CNTE = 1;
}


//-------------------------------------------------------------------
// timer1
// Purpose:
//  Timer1 timer overflow interrupt 1us resolution
// Parameters:
// Returns:
//-------------------------------------------------------------------
__interrupt void timer1(void)
{
	TMCSR1_INTE = 0;
	TMCSR1_UF = 0;		// reset underflow interrupt request flag
	if (usec_delay)	usec_delay--;
	if (ow_usec_timeout) ow_usec_timeout--;

	TMCSR1_INTE = 1;
} // timer1


//-------------------------------------------------------------------
// us_delay
// Purpose:
// 	Waits usec microseconds. The resolution is -+ 1us.
//  Uses the hardware timer1 for calculating the time.
// Parameters:
//  usec - the amount of time in usec to wait;
// Returns:
//-------------------------------------------------------------------

void us_delay(unsigned int usec)
{
	usec_delay = usec;
	while (usec_delay);
} // us_delay
