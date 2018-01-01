/*
 * cmnd_line.h
 *
 *  Created on: Dec 12, 2014
 *      Author: reuben
 */

#ifndef CMND_LINE_H_
#define CMND_LINE_H_

//--------------------------------------------------------------------------
// include project-specific configuration
//#include "cmdlineconf.h"
// constants/macros/typdefs
// size of command database
// (maximum number of commands the cmdline system can handle)
#define CMDLINE_MAX_COMMANDS	10

// maximum length (number of characters) of each command string
// (quantity must include one additional byte for a null terminator)
#define CMDLINE_MAX_CMD_LENGTH	15

// allotted buffer size for command entry
// (must be enough chars for typed commands and the arguments that follow)
#define CMDLINE_BUFFERSIZE		80

// number of lines of command history to keep
// (each history buffer is CMDLINE_BUFFERSIZE in size)
// ***** ONLY ONE LINE OF COMMAND HISTORY IS CURRENTLY SUPPORTED
#define CMDLINE_HISTORYSIZE		1
//-------------------------------------------------------------------------------

// constants/macros/typdefs
typedef void (*CmdlineFuncPtrType)(void);

// functions

//! initalize the command line system
void cmdlineInit(void);

//! add a new command to the database of known commands
// newCmdString should be a null-terminated command string with no whitespace
// newCmdFuncPtr should be a pointer to the function to execute when
//   the user enters the corresponding command tring
void cmdlineAddCommand(unsigned char* newCmdString, CmdlineFuncPtrType newCmdFuncPtr);

//! sets the function used for sending characters to the user terminal
void cmdlineSetOutputFunc(void (*output_func)(unsigned char, unsigned char));

//! call this function to pass input charaters from the user terminal
void cmdlineInputFunc(unsigned char c);

//! call this function in your program's main loop
void cmdlineMainLoop(void);

// internal commands
void cmdlineRepaint(void);
void cmdlineDoHistory(unsigned char action);
void cmdlineProcessInputString(void);
void cmdlinePrintPrompt(void);
void cmdlinePrintError(void);

// argument retrieval commands
//! returns a string pointer to argument number [argnum] on the command line
unsigned char* cmdlineGetArgStr(unsigned char argnum);
//! returns the decimal integer interpretation of argument number [argnum]
long cmdlineGetArgInt(unsigned char argnum);
//! returns the hex integer interpretation of argument number [argnum]
long cmdlineGetArgHex(unsigned char argnum);


#endif /* CMND_LINE_H_ */
