/*
 * debug_uart.c
 *
 *  Created on: Jun 9, 2014
 *      Author: reuben
 */

#include <stdio.h>
#include <string.h>

#include "uarts_config.h"
#include "debug_uart.h"

static char strDbgText[MAX_DEBUG_STR];

const char *pNewLine = "\r\n";

void uartDbgMessage(const char str[]);
void uartDbgPrint(char str[]);


void uartMessage(const char str[])
{
	(void)uartSendBuffer(1, str, strlen(str));
}

void uartDbgMessage(const char str[])
{
	if(strcpy(strDbgText, pNewLine) != NULL){
		if(strcpy(&strDbgText[2], str) != NULL){
			if( strcat(strDbgText,pNewLine) != NULL){
				(void)uartSendBuffer(UART_1, strDbgText, strlen(strDbgText));
			}
		}
	}
}

void uartDbgPrint(char str[])
{
	if(strcpy(strDbgText, pNewLine) != NULL){
		if(strcpy(&strDbgText[2], str) != NULL){
			if( strcat(strDbgText,pNewLine) != NULL){
				uartSendBuffer(UART_1, strDbgText, strlen(strDbgText));
			}
		}
	}
}

void debug_bin2hex(unsigned char bin2hex)
{
 char str[5];

 if(sprintf(str, "%02X", bin2hex) != NULL) UART_PRNT(str);

}

void debug_bin2hex_w(unsigned int bin2hex_w)
{
 char         str[16];

 if(sprintf(str, "\n\r%04X\n\r", bin2hex_w) != NULL) UART_PRNT(str);

}

void debug_hex2dec(unsigned char bin_in)
{
	char str[5];

	str[0] = (bin_in/100)%10 + 48;
	str[1] = (bin_in/10)%10 + 48;
	str[2] = bin_in%10 + 48;
	str[3] = '\0';
	
	UART_PRNT(str);
}

