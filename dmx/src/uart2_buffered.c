/*
 * uart2_buffered.c
 *
 *  Created on: Jun 4, 2014
 *      Author: reuben
 */

/*! \file uart2_buffered.c \brief Dual UART driver with buffer support. */
//*****************************************************************************
/*
 * File Name	: 'uart2_buffered.c'
 * Title		: Dual UART driver with buffer support
 * Author		: Reuben - Copyright (C) 2000-2014
 * Created		: Jun 4, 2014
 * Revised		: Jun 4, 2014
 * Version		: 1.0
 * Target MCU	: ATMEL AVR Series - Adapted to Fujitsu MB90F543
 * Editor Tabs	: 4
 *
 * Description	: This is a UART driver for AVR-series processors with two
 *				  hardware UARTs.
 *				  Adapted to Fujitsu microcontroller.
*/
//*****************************************************************************

#include "mb90540.h"
#include "global.h"
#include "eclipse_cpu.h"
#include "uarts_config.h"
#include "uart2_buffered.h"

// UART global variables
// flag variables
unsigned char   uartReadyTx[2];
unsigned char   uartBufferedTx[2];
// receive and transmit buffers
cBuffer uartRxBuffer[2];
cBuffer uartTxBuffer[2];
unsigned short uartRxOverflow[2];

// using internal ram,
// automatically allocate space in ram for each buffer
static char uart0RxData[UART0_RX_BUFFER_SIZE];
static char uart0TxData[UART0_TX_BUFFER_SIZE];
static char uart1RxData[UART1_RX_BUFFER_SIZE];
static char uart1TxData[UART1_TX_BUFFER_SIZE];

typedef void (*voidFuncPtru08)(unsigned char);
volatile static voidFuncPtru08 UartRxFunc[2];

void uart1InitBuffers(void);
void uart0InitBuffers(void);
void uart0Init(void);
void uart1Init(void);

void uartSetRxHandler(unsigned char nUart, void (*rx_func)(unsigned char c));


void uartInit(void)
{
	// uarts initializes
	uart0Init();
	uart1Init();
}

/*
 * DMX512 is a unidirectional asynchronous serial communication protocol.
 * The transmission rate is 250k Baud (11 bits data: 1 start bit, 8 data bits and 2 stop bits)
 */
void uart0Init(void)
{
	unsigned char c;

	// initialize the buffers
	uart0InitBuffers();
	// initialize user receive handlers
	UartRxFunc[UART_0] = 0;
	// initialize states
	uartReadyTx[UART_0] 	= TRUE;
	uartBufferedTx[UART_0] 	= FALSE;

	// clear overflow count
	uartRxOverflow[UART_0] 	= 0;

	//-----------------------------------------------------------------
   	// initialize UART0 e.g. mode, baud rate, stop bit, data length etc.
   	//-----------------------------------------------------------------
   	DDR4_D40	= 1;     	// Make SOT0 as output
   	//URD0 		= 0x3C;		// set baud rate to 9600 (00111100)

   	/*
   	 * URD0 (rate and data register 0)
   	 * 8	- D8 	(9-bit data length)
   	 * 9	- P 	(parity)
   	 * 10	- BCH0 	(baud rate clock)
   	 * 11	- RC0 	(rate control)
   	 * 12	- RC1 	(rate control)
   	 * 13	- RC2 	(rate control)
   	 * 14	- RC3 	(rate control)
   	 * 15	- BCH 	(baud rate clock)
   	 */

	 /*
	  * URD0_D8 = 0;
	  * URD0_P = 0;
	  * URD0_RC0 = 1;
	  * URD0_RC1 = 1;
	  * URD0_RC2 = 0;
	  * URD0_RC3 = 0;
	  * URD0_BCH0 = 1;
	  * URD0_BCH = 1;
	*/
   	URD0 = 0xCC; // set baud rate to 250000 b/s

   	/*
   	 * UMC0 (serial mode control register 0)
   	 * 0 - SOE 	(serial output enable)
   	 * 1 - SCKE (SCLK enable)
   	 * 2 - RFC 	(receiver flag clear)
   	 * 3 - SMDE (synchronous mode enable)
   	 * 4 - MC0 	(mode control)
   	 * 5 - MC1 	(mode control)
   	 * 6 - SBL 	(stop bit length)
   	 * 7 - PEN 	(parity enable)
   	 */
	UMC0 		= 0x59;  	// set various bits (01011001), 2 stop bit

   	if(USR0_RDRF) c = UIDR0;
   	USR0_RIE 	= 1; 		// Receive interrupt enable

}

void uart1Init(void)
{
	unsigned char c;
	// initialize the buffers
	uart1InitBuffers();
	// initialize user receive handlers
	UartRxFunc[UART_1] = 0;

	// initialize states
	uartReadyTx[UART_1] = TRUE;
	uartBufferedTx[UART_1] = FALSE;
	// clear overflow count
	uartRxOverflow[UART_1] = 0;

	/*
	 * SMR1 (serial mode register)
	 * 0 - SOE (serial output enable)
	 * 1 - SCKE (SCLK enable)
	 * 2 - RESERVA
	 * 3 - CS0 (clock select)
	 * 4 - CS1 (clock select)
	 * 5 - CS2 (clock select)
	 * 6 - MD0 (mode select)
	 * 7 - MD1 (mode select)
	 */

	/*
	 * SCR1 (serial control register 1)
	 * 8  - TXE (transmit enable)
	 * 9  - RXE (receiver enable)
	 * 10 - REC (receiver error clear)
	 * 11 - A/D (address/data)
	 * 12 - CL (character length)
	 * 13 - SBL (stop bit length)
	 * 14 - P (parity)
	 * 15 - PEN (parity enable)
	 */

	/*
	 * SSR1 (serial status register 1)
	 * 8  - TIE (transmit interrupt enable)
	 * 9  - RIE (receiver interrupt enable)
	 * 10 -
	 * 11 - TDRE - transmit data register empty)
	 * 12 - RDRF (receiver data register full)
	 * 13 - FRE (framing error)
	 * 14 - ORE (over run error)
	 * 15 - PE (parity error)
	 */

	/*
	 * CDCR (communication prescaler control register)
	 * 8  - DIV0 (divide)
	 * 9  - DIV1 (divide)
	 * 10 - DIV2 (divide)
	 * 11 - DIV3 (divide)
	 * 12 -
	 * 13 -
	 * 14 -
	 * 15 - MD (machine clock divide mode select)
	 */
	//-----------------------------------------------------------------
   	// initialize UART1 e.g. operation mode, baud rate, stop bit, data length etc.
   	// b.r. 9600
   	//-----------------------------------------------------------------
   	DDR4_D45 	= 1;    	// Make SOT1 working
   	SMR1 		= 0x01;   	// serial mode register (00000001)

   	SCR1 		= 0x17;  	// serial control register (00010111)
	U1CDCR 		= 0x88; 	// prescaler control register (10001000) 9600 bps
	SSR1 		= 0x08;

	if(SSR1_RDRF) c = SIDR1;
  	SSR1_RIE		= 1;		// Receiver Interrupt enabled
}

void uart0InitBuffers(void)
{
	// initialize the UART0 buffers
		bufferInit(&uartRxBuffer[UART_0], (unsigned char *)uart0RxData, UART0_RX_BUFFER_SIZE);
		bufferInit(&uartTxBuffer[UART_0], (unsigned char *)uart0TxData, UART0_TX_BUFFER_SIZE);
}

void uart1InitBuffers(void)
{
		// initialize the UART1 buffers
		bufferInit(&uartRxBuffer[UART_1], (unsigned char *)uart1RxData, UART1_RX_BUFFER_SIZE);
		bufferInit(&uartTxBuffer[UART_1], (unsigned char *)uart1TxData, UART1_TX_BUFFER_SIZE);
}

void uartSetRxHandler(unsigned char nUart, void (*rx_func)(unsigned char c))
{
	// make sure the uart number is within bounds
	if(nUart < 2)
	{
		// set the receive interrupt to run the supplied user function
		UartRxFunc[nUart] = rx_func;
	}
}

cBuffer* uartGetRxBuffer(unsigned char nUart)
{
	// return rx buffer pointer
	return &uartRxBuffer[nUart];
}

cBuffer* uartGetTxBuffer(unsigned char nUart)
{
	// return tx buffer pointer
	return &uartTxBuffer[nUart];
}

void uartSendByte(unsigned char nUart, unsigned char txData)
{
	// wait for the transmitter to be ready
	while(!uartReadyTx[nUart]);

	// send byte
	if(nUart){
		while(!SSR1_TDRE);
		SODR1 = txData;		/* sends data to the SOT1 */

	}else{
		while(!USR0_TDRE);
		UODR0 = txData;
	}

	// set ready state to FALSE
	uartReadyTx[nUart] = FALSE;
	if(nUart){
		SSR1_TIE	= 1;	// Transmit Interrupt enabled
	}else{
		USR0_TIE 	= 1;	// Transmitter interrupt enable
	}

}

void uart0SendByte(unsigned char data)
{
	// send byte on UART0
	uartSendByte(UART_0, data);
}

void uart1SendByte(unsigned char data)
{
	// send byte on UART1
	uartSendByte(UART_1, data);
}

int uart0GetByte(void)
{
	// get single byte from receive buffer (if available)
	unsigned char c;

	if(uartReceiveByte(UART_0,&c))
		return c;
	else
		return -1;
}

int uart1GetByte(void)
{
	// get single byte from receive buffer (if available)
	unsigned char c;

	if(uartReceiveByte(UART_1,&c))
		return c;
	else
		return -1;
}


unsigned char uartReceiveByte(unsigned char nUart, unsigned char* rxData)
{
	// make sure we have a receive buffer
	if(uartRxBuffer[nUart].size)
	{
		// make sure we have data
		if(uartRxBuffer[nUart].datalength)
		{
			// get byte from beginning of buffer
			*rxData = bufferGetFromFront(&uartRxBuffer[nUart]);
			return TRUE;
		}
		else
			return FALSE;			// no data
	}
	else
		return FALSE;				// no buffer
}

void uartFlushReceiveBuffer(unsigned char nUart)
{
	// flush all data from receive buffer
	bufferFlush(&uartRxBuffer[nUart]);
}

unsigned char uartReceiveBufferIsEmpty(unsigned char nUart)
{
	if(uartRxBuffer[nUart].datalength == 0) return 1;
	return 0;
}

void uartAddToTxBuffer(unsigned char nUart, unsigned char data)
{
	// add data byte to the end of the tx buffer
	bufferAddToEnd(&uartTxBuffer[nUart], data);
}

void uart0AddToTxBuffer(unsigned char data)
{
	uartAddToTxBuffer(UART_0,data);
}

void uart1AddToTxBuffer(unsigned char data)
{
	uartAddToTxBuffer(UART_1,data);
}

void uartSendTxBuffer(unsigned char nUart)
{
	// turn on buffered transmit
	uartBufferedTx[nUart] = TRUE;
	// send the first byte to get things going by interrupts
	uartSendByte(nUart, bufferGetFromFront(&uartTxBuffer[nUart]));
}

unsigned char uartSendBuffer(unsigned char nUart, char *buffer, unsigned int nBytes)
{
	register unsigned char first;
	register unsigned int i;

	while(!uartReadyTx[nUart]);
	// check if there's space (and that we have any bytes to send at all)
	if( ( (uartTxBuffer[nUart].datalength + nBytes) < (uartTxBuffer[nUart].size) && nBytes)){
		// grab first character
		//first = *buffer++;
		// copy user buffer to uart transmit buffer
		//for(i = 0; i < nBytes-1; i++)
		for(i = 0; i < nBytes; i++)
		{
			// put data bytes at end of buffer
			bufferAddToEnd(&uartTxBuffer[nUart], *buffer++);
		}

		// send the first byte to get things going by interrupts
		uartBufferedTx[nUart] = TRUE;
		first = bufferGetFromFront(&uartTxBuffer[nUart]); /* add for reuben */
		uartSendByte(nUart, first);

		// return success
		return TRUE;
	}
	else
	{
		// return failure
		return FALSE;
	}
}

void uartSendStr(unsigned char nUart, char *pStr)
{
	while(*pStr){
		uartSendByte(nUart, *pStr++);
	}
}


// UART Transmit Complete Interrupt Function
void uartTransmitService(unsigned char nUart)
{
	// check if buffered tx is enabled
	if(uartBufferedTx[nUart]){
		// check if there's data left in the buffer
		if(uartTxBuffer[nUart].datalength){
			// send byte from top of buffer
			if(nUart){
				while(!SSR1_TDRE);
				SODR1 = bufferGetFromFront(&uartTxBuffer[UART_1]);
			}else{
				while(!USR0_TDRE);
				UODR0 = bufferGetFromFront(&uartTxBuffer[UART_0]);
			}
		}else{
			if(nUart)
				SSR1_TIE = 0;	// Disable UART1 TX Interrupt.
			else
				USR0_TIE = 0;	// Disable UART0 TX Interrupt.

			// no data left
			uartBufferedTx[nUart] = FALSE;
			// return to ready state
			uartReadyTx[nUart] = TRUE;
		}
	}else{
		// we're using single-byte tx mode
		// indicate transmit complete, back to ready
		uartReadyTx[nUart] = TRUE;

		if(nUart)
			SSR1_TIE = 0;	// Disable UART1 TX Interrupt.
		else
			USR0_TIE = 0;	// Disable UART0 TX Interrupt.

	}
}

// UART Receive Complete Interrupt Function
void uartReceiveService(unsigned char nUart)
{
	unsigned char c;

	// get received char
	if(nUart){
	    if(SSR1_ORE || SSR1_FRE) {	// overrun error.
	        SCR1_REC = 0;   		// reset error flags.
	        return;
	    }
	    else
            c = SIDR1;
	}else{
	    if(USR0_ORFE){		// overrun error.
            UMC0_RFC = 0;   // reset error flags.
            return;
	    }
        else
            c = UIDR0;
	}

	// if there's a user function to handle this receive event
	if(UartRxFunc[nUart]){
		// call it and pass the received data
		UartRxFunc[nUart](c);
	}else{
		// otherwise do default processing
		// put received char in buffer
		// check if there's space
		if( !bufferAddToEnd(&uartRxBuffer[nUart], c) ){
			// no space in buffer
			// count overflow
			uartRxOverflow[nUart]++;
		}
	}
}


__interrupt void Uart0_Transmit (void)
{
	// service UART0 transmit interrupt
	uartTransmitService(UART_0);
}

__interrupt void Uart1_Transmit (void)
{
	// service UART1 transmit interrupt
	uartTransmitService(UART_1);
}

__interrupt void Uart0_Receive (void)
{
	// service UART0 receive interrupt
	uartReceiveService(UART_0);

}

__interrupt void Uart1_Receive (void)
{
	// service UART1 receive interrupt
	uartReceiveService(UART_1);

}
