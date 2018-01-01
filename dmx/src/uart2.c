/*
 * uart2.c
 *
 *  Created on: Jun 3, 2014
 *      Author: reuben
 */

#include "mb90540.h"

/* globals */

unsigned char receive_data;
unsigned char ERROR = 0xC2;		/* clears all data leds */
//unsigned char data[] = {0x00,0x02,0x40,0x42,0x80,0x82,0xC0};
unsigned char data[] = {'R','E','U','B','E','N','\n'};
unsigned short index = 0;

/* interrupt functions */

__interrupt void Uart1_Transmit (void)
{
	SODR1 = data[index++];		/* sends data to the SOT1 */
	if(index > 6)
		index = 0;
}

__interrupt void Uart0_Transmit (void)
{
	UODR0 = data[index++];		/* sends data the SOT0 */
	if(index > 6)
		index = 0;
}

__interrupt void Uart0_Receive (void)
{
	if(USR0_ORFE)
	{
		UMC0_RFC = 0;			/* clear error flags */
	}
	else
	{
		receive_data = UIDR0;	/* write received data to buffer */
		PDR4 = receive_data;	/* buffer outputed to led's */
	}
}

__interrupt void Uart1_Receive (void)
{
	if(SSR1_ORE || SSR1_FRE)
	{
		SCR1_REC = 0;			/* clear error flag */
	}
	else
	{
		receive_data = SIDR1;	/* write received data to buffer */
		PDR4 = receive_data;	/* buffer outputed to led's */
	}
}

/*============================== PROCEDURES ======================================*/

void uartInit(void)
{
	/* initialize UART0 and UART1 with baud rate, mode, stop bits etc. */

	/* initialize UART0 */
	UMC0 = 0x5D;	/* serial mode control register (01011101) */
	USR0 = 0x0C;	/* status register (00011100) */
	URD0 = 0x4C;	/* rate and data register  (01001100) */

	/* initialize UART1 */
	SMR1 = 0x09;	/* serial mode register (00001001) */
	SCR1 = 0x33;	/* serial control register (00110011) */
	U1CDCR = 0x88;	/* UART1 prescaler control (10001000) */
	DDR4 = 0xE3;	/* direction register of PORT4 (11100011) */
	SSR1 = 0x03;	/* serial status register (00001011) */
}

/************************************************************************************/
