/*
 * serialTest.c
 *
 *  Created on: Jun 7, 2014
 *      Author: reuben
 */
#include "mb90540.h"

void uartInit(void)
{
	/* initialize UART0 and UART1 with baud rate, mode, stop bits etc. */

	/* initialize UART0 */
	DDR4_D40 = 1;                                 // Make SOT0 as output
	URD0 = 0x3C;	/* rate and data register  (01001100) */
	UMC0 = 0x19;	/* serial mode control register (01011101) */



	/* initialize UART1 */
	/*
	SMR1 = 0x09;	 serial mode register (00001001)
	SCR1 = 0x33;	 serial control register (00110011)
	U1CDCR = 0x88;	 UART1 prescaler control (10001000)
	DDR4 = 0xE3;	 direction register of PORT4 (11100011)
	SSR1 = 0x03;	 serial status register (00001011) */
}
