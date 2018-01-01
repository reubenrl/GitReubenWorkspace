/*
 * dim_main.c
 *
 *  Created on: May 9, 2016
 *      Author: phytech
 */


#include "mb90540.h"

#include "uart2_buffered.h"
#include "debug_uart.h"
#include "timer0.h"
#include "leds.h"


void main(void)
{
	unsigned char button;

	timer0_init();
	ledInit();
	uartInit(); /* initialize the two UARTs of the MB90540 */

	InitIrqLevels(); 	/* initialize IRQs 			*/
	 __set_il(7); 		/* allow all levels 		*/
	 __EI(); 			/* global enable interrupts */

	 ledControl(LED1, 1);
#ifdef __DBG
	 DBG_TXT("hello work...");
#endif

	// SW3 Test Button pullup & input
	DDR3_D37 = 0;         	// SW3 as input
	PUCR3_PU37 = 1;     	// pull up
	__wait_nop();
	__wait_nop();
	button = 0;

#ifdef __DBG
	 DBG_TXT("Waiting sync time...");
#endif

	if(!PDR3_P37){
		__wait_nop();
		while(!PDR3_P37){ __wait_nop();}
		button = 1;
	}

}
