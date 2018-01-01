/*
 * uart2_buffered.h
 *
 *  Created on: Jun 6, 2014
 *      Author: reuben
 */

#ifndef UART2_BUFFERED_H_
#define UART2_BUFFERED_H_

#include "buffer.h"

#define UART_PRINT		1

void uartInit(void);


cBuffer* uartGetRxBuffer(unsigned char nUart);
cBuffer* uartGetTxBuffer(unsigned char nUart);
void uartSendByte(unsigned char nUart, unsigned char txData);
unsigned char uartSendBuffer(unsigned char nUart, char *buffer, unsigned int nBytes);
void uart0SendByte(unsigned char data);
void uart1SendByte(unsigned char data);
int uart0GetByte(void);
int uart1GetByte(void);
unsigned char uartReceiveByte(unsigned char nUart, unsigned char* rxData);
void uartFlushReceiveBuffer(unsigned char nUart);
unsigned char uartReceiveBufferIsEmpty(unsigned char nUart);
void uartAddToTxBuffer(unsigned char nUart, unsigned char data);
void uart0AddToTxBuffer(unsigned char data);
void uart1AddToTxBuffer(unsigned char data);
void uartSendTxBuffer(unsigned char nUart);
void uartSendStr(unsigned char nUart, char *pStr);


#endif /* UART2_BUFFERED_H_ */
