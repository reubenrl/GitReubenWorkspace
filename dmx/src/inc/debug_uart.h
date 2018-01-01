/*
 * debug_uart.h
 *
 *  Created on: Jun 9, 2014
 *      Author: reuben
 */

#ifndef DEBUG_UART_H_
#define DEBUG_UART_H_

#include "uart2_buffered.h"

#define MAX_DEBUG_STR 64

#define UART_PRNT(s)	uartDbgPrint(s)
#define DBG_TXT(s)		uartDbgMessage(s)
void uartMessage(const char str[]);
#define UART_MSG(s)		uartMessage(s);
void debug_bin2hex(unsigned char bin2hex);
void debug_bin2hex_w(unsigned int bin2hex_w);

#endif /* DEBUG_UART_H_ */
