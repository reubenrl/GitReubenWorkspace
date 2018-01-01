/*
 * vt100.c
 *
 *  Created on: Dec 13, 2014
 *      Author: reuben
 */


#include "mb90540.h"
#include "debug_uart.h"
#include "vt100.h"


// function pointer to single character output routine
static void (*vt100OutputFunc)(unsigned char nUart, char *p);

// Global variables

// Functions
void vt100Init(void(*output_func)(unsigned char nUart, char *p))
{
	vt100OutputFunc = output_func;
	// initializes terminal to "power-on" settings
	// ESC c
	vt100OutputFunc(UART_PRINT, "\x1B\x63");
}

void vt100ClearScreen(void)
{
	// ESC [ 2 J
	vt100OutputFunc(UART_PRINT,"\x1B[2J");
}

void vt100SetAttr(unsigned char attr)
{
	char strTmp[32];
	// ESC [ Ps m
	if(sprintf(&strTmp[0],"\x1B[%dm",attr)) vt100OutputFunc(UART_PRINT,strTmp);
}

void vt100SetCursorMode(unsigned char visible)
{
	if(visible){// ESC [ ? 25 h
		vt100OutputFunc(UART_PRINT,"\x1B[?25h");
	}else{// ESC [ ? 25 l
		vt100OutputFunc(UART_PRINT,"\x1B[?25l");
	}
}

void vt100SetCursorPos(unsigned char line, unsigned char col)
{
	char strTmp[32];
	// ESC [ Pl ; Pc H
	if(sprintf(&strTmp[0],"\x1B[%d;%dH",line,col)) vt100OutputFunc(UART_PRINT,strTmp);
}
