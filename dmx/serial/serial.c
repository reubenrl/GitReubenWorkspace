/*
 * serial.c
 *
 *  Created on: May 9, 2016
 *      Author: phytech
 */
#include "mb90540.h"

unsigned char  RxBuffer[RX_BUFSIZE];
// Serial buffer
typedef struct{
	unsigned char* ptrBuff;
	unsigned char buffLen;
}t_com_buff;


typedef struct{
	unsigned char RxBufferOut;
	unsigned char RxBufferIn;
}t_com_ctrl;


// UART Receive Complete Interrupt Function
void serialReceiveService(unsigned char nUart)
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


      next = RxBufferIn + 1;
      if (next == RX_BUFSIZE)
		{
          next = 0;
		}

      if (next == RxBufferOut)
      {
          g_u8UartError |= E_BUFFEROVERFLOW;

      }
      else
      {
          // Byte in the Buffer.
          au8RxBuffer[RxBufferIn] = u8UartData;
          u8RxBufferIn = u8NextPos;
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
    unsigned char next, data;

    g_u8UartError	= UCSRA & (FRAME_ERROR | OVERRUN_ERROR);
    u8UartData		= UDR;

   if(!g_u8UartError)
   {
       // Buffer position
       u8NextPos = u8RxBufferIn + 1;
       if (u8NextPos == RX_BUFSIZE)
		{
           u8NextPos = 0;
		}

       if (u8NextPos == u8RxBufferOut)
       {
           g_u8UartError |= E_BUFFEROVERFLOW;

       }
       else
       {
           // Byte in the Buffer.
           au8RxBuffer[u8RxBufferIn] = u8UartData;
           u8RxBufferIn = u8NextPos;
       }
   }




	// service UART0 receive interrupt
	uartReceiveService(UART_0);

/*	if(sUartTimeouts[UART_0].Enable){
 		sUartTimeouts[UART_0].ReadTimeout = UART0_TIMEOUT_50MS;
 		sUartTimeouts[UART_0].TimeoutOn = TRUE;
 	}*/

}

__interrupt void Uart1_Receive (void)
{
	// service UART1 receive interrupt
	uartReceiveService(UART_1);

/*	if(sUartTimeouts[UART_1].Enable){
		sUartTimeouts[UART_1].ReadTimeout = UART1_TIMEOUT_100MS;
		sUartTimeouts[UART_1].TimeoutOn = TRUE;
 	}*/
}
