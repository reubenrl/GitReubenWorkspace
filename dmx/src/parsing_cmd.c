/*
 * parsing_cmd.c
 *
 *  Created on: Feb 25, 2015
 *      Author: reuben
 */
#include <string.h>
#include "debug_uart.h"

#include "rtc.h"
#include "vt100.h"
#include "cmnd_line.h"
#include "parsing_cmd.h"

#define CMDLINETIMEOUT		60		// 60 seconds
void eepromEraseAll(void);
void eepromReadDataStore(void);
void csvExport(void);
void timeUpdate(void);
void exitFunction(void);
void helpFunction(void);

void cmdLineMain(void)
{
	// initialize vt100 terminal
	vt100Init(uartSendStr);
	// start command line
	goCmdline();
}

static unsigned char Run;

void goCmdline(void)
{
	char *pBuff;
	unsigned char c;
	unsigned long cmd_line_timeout;

	// print initial message
	vt100ClearScreen();
	vt100SetCursorPos(1,0);

	// initialize cmdline system
	cmdlineInit();
	DBG_TXT("-----------------------------------------------");
	DBG_TXT("------   VT100 Protocol Connected    ----------");
	// direct command line output to uart
	cmdlineSetOutputFunc(uartSendByte);

	// add commands to the command database
	cmdlineAddCommand((unsigned char *)"q",	exitFunction);
	cmdlineAddCommand((unsigned char *)"h",	helpFunction);
	cmdlineAddCommand((unsigned char *)"3",	timeUpdate);

/*	cmdlineAddCommand((unsigned char *)"5",	input_output3_test);
	cmdlineAddCommand((unsigned char *)"6",	input_output4_test);
	cmdlineAddCommand((unsigned char *)"7",	battery_test);
	cmdlineAddCommand((unsigned char *)"8",	modem_setting_test);
	cmdlineAddCommand((unsigned char *)"9",	sleep_test);*/

	// send a CR to cmdline input to stimulate a prompt
	cmdlineInputFunc('\r');

	// set state to run
	Run = 1;

	uartFlushReceiveBuffer(UART_PRINT);
	cmd_line_timeout = get_tmr0_tick_sec() + CMDLINETIMEOUT;
	// main loop
	while(Run && (cmd_line_timeout > get_tmr0_tick_sec()))
	{
		// pass characters received on the uart into the cmdline processor
		while(uartReceiveByte(UART_PRINT, &c)){
			cmd_line_timeout = get_tmr0_tick_sec() + CMDLINETIMEOUT;
			cmdlineInputFunc(c);
		}
		// run the cmdline execution functions
		cmdlineMainLoop();
	}

	DBG_TXT("VT100 Protocol Disconnected!");
}

void exitFunction(void)
{
	// to exit, we set Run to 0
	Run = 0;
}

void helpFunction(void)
{
	vt100ClearScreen();
	vt100SetCursorPos(0,0);

	DBG_TXT("Available commands are:");
	DBG_TXT("h - available commands");
	DBG_TXT("3 - time update format dd/mm/yy hh:mm:ss");
	DBG_TXT("q - quit");
}

unsigned char *parsingStr(unsigned char str[], unsigned char parValue)
{
	unsigned char idx=0;
	while(!((str[idx] == parValue) || (str[idx] == '\0'))) idx++;
	if(str[idx]) return &str[idx];

	return NULL;
}

void timeUpdate(void)
{
	char strTmp[32];
	unsigned char *pTmp, idx;
	time_t time = {0};

	idx = 0;
	pTmp = cmdlineGetArgStr(1);
	if(pTmp == NULL) return;
	pTmp = strcpy(strTmp, pTmp);
	if(pTmp == NULL) return;

	pTmp = parsingStr(&strTmp[idx], '/');
	if(pTmp == NULL) return;
	*pTmp = '\0';
	time.day = (unsigned char)atoi(&strTmp[idx]);

	idx += pTmp - &strTmp[idx] + 1;
	pTmp = parsingStr(&strTmp[idx], '/');
	if(pTmp == NULL) return;
	*pTmp = '\0';
	time.month =(unsigned char)atoi(&strTmp[idx]);

	idx += pTmp - &strTmp[idx] + 1;
	time.year = (unsigned char)atoi(&strTmp[idx]);

	idx = 0;
	pTmp = cmdlineGetArgStr(2);
	if(pTmp == NULL) return;
	pTmp = strcpy(strTmp, pTmp);
	if(pTmp == NULL) return;

	pTmp = parsingStr(&strTmp[idx], ':');
	if(pTmp == NULL) return;
	*pTmp = '\0';
	time.hour = (unsigned char)atoi(&strTmp[idx]);

	idx += pTmp - &strTmp[idx] + 1;
	pTmp = parsingStr(&strTmp[idx], ':');
	if(pTmp == NULL) return;
	*pTmp = '\0';
	time.minute = (unsigned char)atoi(&strTmp[idx]);

	idx += pTmp - &strTmp[idx] + 1;
	rtc_set_time(&time, (unsigned char)atoi(&strTmp[idx]));

}
