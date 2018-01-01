/*
 * cmnd_line.c
 *
 *  Created on: Dec 12, 2014
 *      Author: reuben
 */

#include "mb90540.h"			// include I/O definitions (port names, pin names, etc)
#include <string.h>			// include standard C string functions
#include <stdlib.h>			// include stdlib for string conversion functions
#include "debug_uart.h"
#include "cmnd_line.h"

// defines
#define ASCII_BEL				0x07
#define ASCII_BS				0x08
#define ASCII_CR				0x0D
#define ASCII_LF				0x0A
#define ASCII_ESC				0x1B
#define ASCII_DEL				0x7F

#define VT100_ARROWUP			'A'
#define VT100_ARROWDOWN			'B'
#define VT100_ARROWRIGHT		'C'
#define VT100_ARROWLEFT			'D'

#define CMDLINE_HISTORY_SAVE	0
#define CMDLINE_HISTORY_PREV	1
#define CMDLINE_HISTORY_NEXT	2


// Global variables

// strings
const unsigned char CmdlinePrompt[] 		= "cmd>";
const unsigned char CmdlineNotice[] 		= "cmdline: ";
const unsigned char CmdlineCmdNotFound[] 	= "command not found";

// command list
// -commands are null-terminated strings
static char CmdlineCommandList[CMDLINE_MAX_COMMANDS][CMDLINE_MAX_CMD_LENGTH];
// command function pointer list
static CmdlineFuncPtrType CmdlineFunctionList[CMDLINE_MAX_COMMANDS];
// number of commands currently registered
unsigned char CmdlineNumCommands;

unsigned char CmdlineBuffer[CMDLINE_BUFFERSIZE];
unsigned char CmdlineBufferLength;
unsigned char CmdlineBufferEditPos;
unsigned char CmdlineInputVT100State;
unsigned char CmdlineHistory[CMDLINE_HISTORYSIZE][CMDLINE_BUFFERSIZE];
CmdlineFuncPtrType CmdlineExecFunction;

// Functions

// function pointer to single character output routine
// function pointer to single character output routine
static void (*cmdlineOutputFunc)(unsigned char, unsigned char);

//static void (*cmdlineOutputFunc)(unsigned char c);

void cmdlineInit(void)
{
	// reset vt100 processing state
	CmdlineInputVT100State = 0;
	// initialize input buffer
	CmdlineBufferLength = 0;
	CmdlineBufferEditPos = 0;
	// initialize executing function
	CmdlineExecFunction = 0;
	// initialize command list
	CmdlineNumCommands = 0;
}

void cmdlineAddCommand(unsigned char* newCmdString, CmdlineFuncPtrType newCmdFuncPtr)
{
	// add command string to end of command list
	strcpy(CmdlineCommandList[CmdlineNumCommands], newCmdString);
	// add command function ptr to end of function list
	CmdlineFunctionList[CmdlineNumCommands] = newCmdFuncPtr;
	// increment number of registered commands
	CmdlineNumCommands++;
}

void cmdlineSetOutputFunc(void (*output_func)(unsigned char, unsigned char))
{
	// set new output function
	cmdlineOutputFunc = output_func;

	// should we really do this?
	// print a prompt
	cmdlinePrintPrompt();
}

void cmdlineInputFunc(unsigned char c)
{
	unsigned char i;
	// process the received character

	// VT100 handling
	// are we processing a VT100 command?
	if(CmdlineInputVT100State == 2)
	{
		// we have already received ESC and [
		// now process the vt100 code
		switch(c)
		{
		case VT100_ARROWUP:
			cmdlineDoHistory(CMDLINE_HISTORY_PREV);
			break;
		case VT100_ARROWDOWN:
			cmdlineDoHistory(CMDLINE_HISTORY_NEXT);
			break;
		case VT100_ARROWRIGHT:
			// if the edit position less than current string length
			if(CmdlineBufferEditPos < CmdlineBufferLength)
			{
				// increment the edit position
				CmdlineBufferEditPos++;
				// move cursor forward one space (no erase)
				cmdlineOutputFunc(UART_PRINT, ASCII_ESC);
				cmdlineOutputFunc(UART_PRINT, '[');
				cmdlineOutputFunc(UART_PRINT, VT100_ARROWRIGHT);
			}
			else
			{
				// else, ring the bell
				cmdlineOutputFunc(UART_PRINT, ASCII_BEL);
			}
			break;
		case VT100_ARROWLEFT:
			// if the edit position is non-zero
			if(CmdlineBufferEditPos)
			{
				// decrement the edit position
				CmdlineBufferEditPos--;
				// move cursor back one space (no erase)
				cmdlineOutputFunc(UART_PRINT, ASCII_BS);
			}
			else
			{
				// else, ring the bell
				cmdlineOutputFunc(UART_PRINT, ASCII_BEL);
			}
			break;
		default:
			break;
		}
		// done, reset state
		CmdlineInputVT100State = 0;
		return;
	}
	else if(CmdlineInputVT100State == 1)
	{
		// we last received [ESC]
		if(c == '[')
		{
			CmdlineInputVT100State = 2;
			return;
		}
		else
			CmdlineInputVT100State = 0;
	}
	else
	{
		// anything else, reset state
		CmdlineInputVT100State = 0;
	}

	// Regular handling
	if( (c >= 0x20) && (c < 0x7F) )
	{
		// character is printable
		// is this a simple append
		if(CmdlineBufferEditPos == CmdlineBufferLength)
		{
			// echo character to the output
			cmdlineOutputFunc(UART_PRINT, c);
			// add it to the command line buffer
			CmdlineBuffer[CmdlineBufferEditPos++] = c;
			// update buffer length
			CmdlineBufferLength++;
		}
		else
		{
			// edit/cursor position != end of buffer
			// we're inserting characters at a mid-line edit position
			// make room at the insert point
			CmdlineBufferLength++;
			for(i=CmdlineBufferLength; i>CmdlineBufferEditPos; i--)
				CmdlineBuffer[i] = CmdlineBuffer[i-1];
			// insert character
			CmdlineBuffer[CmdlineBufferEditPos++] = c;
			// repaint
			cmdlineRepaint();
			// reposition cursor
			for(i=CmdlineBufferEditPos; i<CmdlineBufferLength; i++)
				cmdlineOutputFunc(UART_PRINT, ASCII_BS);
		}
	}
	// handle special characters
	else if(c == ASCII_CR)
	{
		// user pressed [ENTER]
		// echo CR and LF to terminal
		cmdlineOutputFunc(UART_PRINT, ASCII_CR);
		cmdlineOutputFunc(UART_PRINT, ASCII_LF);
		// add null termination to command
		CmdlineBuffer[CmdlineBufferLength++] = 0;
		CmdlineBufferEditPos++;
		// command is complete, process it
		cmdlineProcessInputString();
		// reset buffer
		CmdlineBufferLength = 0;
		CmdlineBufferEditPos = 0;
	}
	else if(c == ASCII_BS)
	{
		if(CmdlineBufferEditPos)
		{
			// is this a simple delete (off the end of the line)
			if(CmdlineBufferEditPos == CmdlineBufferLength)
			{
				// destructive backspace
				// echo backspace-space-backspace
				cmdlineOutputFunc(UART_PRINT, ASCII_BS);
				cmdlineOutputFunc(UART_PRINT, ' ');
				cmdlineOutputFunc(UART_PRINT, ASCII_BS);
				// decrement our buffer length and edit position
				CmdlineBufferLength--;
				CmdlineBufferEditPos--;
			}
			else
			{
				// edit/cursor position != end of buffer
				// we're deleting characters at a mid-line edit position
				// shift characters down, effectively deleting
				CmdlineBufferLength--;
				CmdlineBufferEditPos--;
				for(i=CmdlineBufferEditPos; i<CmdlineBufferLength; i++)
					CmdlineBuffer[i] = CmdlineBuffer[i+1];
				// repaint
				cmdlineRepaint();
				// add space to clear leftover characters
				cmdlineOutputFunc(UART_PRINT, ' ');
				// reposition cursor
				for(i=CmdlineBufferEditPos; i<(CmdlineBufferLength+1); i++)
					cmdlineOutputFunc(UART_PRINT, ASCII_BS);
			}
		}
		else
		{
			// else, ring the bell
			cmdlineOutputFunc(UART_PRINT, ASCII_BEL);
		}
	}
	else if(c == ASCII_DEL)
	{
		// not yet handled
	}
	else if(c == ASCII_ESC)
	{
		CmdlineInputVT100State = 1;
	}
}

void cmdlineRepaint(void)
{
	unsigned char* ptr;
	unsigned char i;

	// carriage return
	cmdlineOutputFunc(UART_PRINT, ASCII_CR);
	// print fresh prompt
	cmdlinePrintPrompt();
	// print the new command line buffer
	i = CmdlineBufferLength;
	ptr = CmdlineBuffer;
	while(i--) cmdlineOutputFunc(UART_PRINT, *ptr++);
}

void cmdlineDoHistory(unsigned char action)
{
	switch(action)
	{
	case CMDLINE_HISTORY_SAVE:
		// copy CmdlineBuffer to history if not null string
		if( strlen(CmdlineBuffer) )
			strcpy(CmdlineHistory[0], CmdlineBuffer);
		break;
	case CMDLINE_HISTORY_PREV:
		// copy history to current buffer
		strcpy(CmdlineBuffer, CmdlineHistory[0]);
		// set the buffer position to the end of the line
		CmdlineBufferLength = strlen(CmdlineBuffer);
		CmdlineBufferEditPos = CmdlineBufferLength;
		// "re-paint" line
		cmdlineRepaint();
		break;
	case CMDLINE_HISTORY_NEXT:
		break;
	}
}

void cmdlineProcessInputString(void)
{
	unsigned char cmdIndex;
	unsigned char i=0;

	// save command in history
	cmdlineDoHistory(CMDLINE_HISTORY_SAVE);

	// find the end of the command (excluding arguments)
	// find first whitespace character in CmdlineBuffer
	while( !((CmdlineBuffer[i] == ' ') || (CmdlineBuffer[i] == 0)) ) i++;

	if(!i)
	{
		// command was null or empty
		// output a new prompt
		cmdlinePrintPrompt();
		// we're done
		return;
	}

	// search command list for match with entered command
	for(cmdIndex=0; cmdIndex<CmdlineNumCommands; cmdIndex++)
	{
		if( !strncmp(CmdlineCommandList[cmdIndex], CmdlineBuffer, i) )
		{
			// user-entered command matched a command in the list (database)
			// run the corresponding function
			CmdlineExecFunction = CmdlineFunctionList[cmdIndex];
			// new prompt will be output after user function runs
			// and we're done
			return;
		}
	}

	// if we did not get a match
	// output an error message
	cmdlinePrintError();
	// output a new prompt
	cmdlinePrintPrompt();
}

void cmdlineMainLoop(void)
{
	// do we have a command/function to be executed
	if(CmdlineExecFunction)
	{
		// run it
		CmdlineExecFunction();
		// reset
		CmdlineExecFunction = 0;
		// output new prompt
		cmdlinePrintPrompt();
	}
}

void cmdlinePrintPrompt(void)
{
	const unsigned char *ptr;
	// print a new command prompt
	ptr = CmdlinePrompt;
	//while(pgm_read_byte(ptr)) cmdlineOutputFunc( pgm_read_byte(ptr++) );
	while(*ptr) cmdlineOutputFunc(UART_PRINT,  *ptr++ );
}

void cmdlinePrintError(void)
{
	const unsigned char *ptr;

	// print a notice header
	// (u08*) cast used to avoid compiler warning
	ptr = CmdlineNotice;
	//while(pgm_read_byte(ptr)) cmdlineOutputFunc( pgm_read_byte(ptr++) );
	while(*ptr) cmdlineOutputFunc( UART_PRINT, *ptr++ );

	// print the offending command
	ptr = CmdlineBuffer;
	while((*ptr) && (*ptr != ' ')) cmdlineOutputFunc(UART_PRINT, *ptr++);

	cmdlineOutputFunc(UART_PRINT, ':');
	cmdlineOutputFunc(UART_PRINT, ' ');

	// print the not-found message
	// (u08*) cast used to avoid compiler warning
	ptr = CmdlineCmdNotFound;
	//while(pgm_read_byte(ptr)) cmdlineOutputFunc( pgm_read_byte(ptr++) );
	while(*ptr) cmdlineOutputFunc(UART_PRINT, *ptr++);

	cmdlineOutputFunc(UART_PRINT, '\r');
	cmdlineOutputFunc(UART_PRINT, '\n');
}

// argument retrieval commands

// return string pointer to argument [argnum]
unsigned char* cmdlineGetArgStr(unsigned char argnum)
{
	// find the offset of argument number [argnum]
	unsigned char idx=0;
	unsigned char arg;

	// find the first non-whitespace character
	while( (CmdlineBuffer[idx] != 0) && (CmdlineBuffer[idx] == ' ')) idx++;

	// we are at the first argument
	for(arg=0; arg<argnum; arg++)
	{
		// find the next whitespace character
		while( (CmdlineBuffer[idx] != 0) && (CmdlineBuffer[idx] != ' ')) idx++;
		// find the first non-whitespace character
		while( (CmdlineBuffer[idx] != 0) && (CmdlineBuffer[idx] == ' ')) idx++;
	}
	// we are at the requested argument or the end of the buffer
	return &CmdlineBuffer[idx];
}

// return argument [argnum] interpreted as a decimal integer
long cmdlineGetArgInt(unsigned char argnum)
{
	unsigned char* endptr;
	return strtol(cmdlineGetArgStr(argnum), &endptr, 10);
}

// return argument [argnum] interpreted as a hex integer
long cmdlineGetArgHex(unsigned char argnum)
{
	char* endptr;
	return strtol(cmdlineGetArgStr(argnum), &endptr, 16);
}
