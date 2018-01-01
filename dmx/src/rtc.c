/*
 * rtc.c
 *
 *  Created on: Dec 11, 2014
 *      Author: reuben
 */

//===================================================================
//  $Workfile: RTC.c $
//  $Modtime: 5-09-01 10:12 $
//  $Revision: 2 $
//  $Author: Noam $
//===================================================================
#include <stdio.h>
#include "mb90540.h"
#include "global.h"
#include "debug_uart.h"
#include "timer0.h"
#include "leds.h"
#include "rtc.h"



unsigned char BCD2num(unsigned char bcd_num);
unsigned char Num2BCD(unsigned char num);
void	rtc_clk_delay(void);

//-------------------------------------------------------------------
// 	rtc_init
// 	Purpose:
//   	Init RTC functionality
// 	Parameters:
//  	none
// 	Returns:
//-------------------------------------------------------------------
void rtc_init(void)
{
	unsigned char i, ret = 0;

	//------------------------------------------------------------------
	// RTC Directions
	//------------------------------------------------------------------
	RTC_WR_D = 1;
	RTC_RD_D = 1;
	RTC_CS_D = 1;
	//------------------------------------------------------------------
	// RTC Pullups in use
	//------------------------------------------------------------------
	RTC_WR_PULL = 1;
	RTC_RD_PULL = 1;
	RTC_CS_PULL = 1;                               // pull up

	//-----------------------------------------------------------------
	// read 8 bits to ensure rtc serial buffer synchronization!
	//-----------------------------------------------------------------
	RTC_WR = 1;
	RTC_IO_D = 0; 				// config IO as input

	for (i=0;i<8;i++){       	// read 8 bytes to reset the rtc
		RTC_RD = 1;
		rtc_clk_delay();
		ret |= RTC_IO;
		if (i < 7) ret <<= 1;
		RTC_RD = 0;
		rtc_clk_delay();
	} // end for

	//-----------------------------------------------------------------
	// write 0 to status register 0:
	//-----------------------------------------------------------------
	// ?!? 05092001
	//	rtc_write_byte(0x00, 0x00, 1);

	//-----------------------------------------------------------------
	// write disable set time ?!? 25/06/2001
	//-----------------------------------------------------------------
	rtc_write_byte(RTC_STATUS0_ADDR,RTC_TIME_SET_LOCK,1);
	rtc_write_byte(RTC_STATUS0_ADDR,RTC_TIME_SET_LOCK,1);

	//-----------------------------------------------------------------
	// copy RTC to RAM:
	//-----------------------------------------------------------------
	rtc_write_byte(RTC_COPY_CLOCK_TO_RAM, 0, 0);

	RTC_WR = 1;
	RTC_RD = 1;
} // rtc_init

//-------------------------------------------------------------------
// 	rtc_read_byte
// 	Purpose:
// 	Parameters:
// 	Returns:
//-------------------------------------------------------------------
unsigned char rtc_read_byte(unsigned char Addr)
{
	unsigned char i, ret = 0x00;
	unsigned char inbit;

	RTC_CS = 0;
	//-----------------------------------------------------------------
	// init a write addr cycle:
	//-----------------------------------------------------------------
	RTC_RD = 1;
	RTC_IO_D = 1;                                  // config IO as output
	RTC_WR = 1;

  //-----------------------------------------------------------------
	// first write the 4 bit address
  //-----------------------------------------------------------------
	for (i = 0;i < 4 ;i++ ) {
		RTC_IO = (Addr & 0x01);
		Addr >>= 1;
		RTC_WR = 0;
		rtc_clk_delay();
		RTC_WR = 1;
		rtc_clk_delay();
	} // end of: for (;;)

  //-----------------------------------------------------------------
	// now read the 8 bits
  //-----------------------------------------------------------------
	RTC_RD = 1;
	RTC_WR = 1;
	RTC_IO_D = 0;                                  // config IO as input

	for (i = 0;i < 8 ;i++ ) {
		RTC_RD = 0;
		rtc_clk_delay();
		inbit = RTC_IO;
		if (inbit == 1) {
			ret |= BV(i);
		}
		RTC_RD = 1;
		rtc_clk_delay();

	} // end of: for (;;) {

	RTC_RD = 1;
	RTC_CS = 1;
	return ret;
} // rtc_read_byte

//-------------------------------------------------------------------
// 	rtc_write_byte
// 	Purpose:
//   	Perform a full write cycle to the RTC
//  	Able to send only a 4 bit  / 12 bit cmd + address
// 	Parameters:
// 	Returns:
//-------------------------------------------------------------------
void rtc_write_byte(unsigned char Cmd, unsigned char byte2Write, unsigned char CmdType)
{
	unsigned char i, N;
	unsigned int str2Write;

	RTC_CS = 0;
	//-----------------------------------------------------------------
	// Write address & byte (12bits) or just address (4bits)
	//-----------------------------------------------------------------
	if (CmdType == 1) {
	  // building 12 bits:
		N = 12;
		str2Write = byte2Write;
		str2Write <<= 4;
		str2Write |= Cmd;
	}else{
		   // 4 bit command:
		   N = 4;
		   str2Write = Cmd;
	}

	RTC_RD = 1;
	RTC_IO_D = 1; // config IO to output
	RTC_WR = 1;

	for (i = 0;i < N ; i++) {
		RTC_IO = (str2Write & 0x01);
		str2Write >>= 1;
		RTC_WR = 0;
		rtc_clk_delay();
		RTC_WR = 1;
		rtc_clk_delay();
	} // end of: for (;;) {

	RTC_WR = 1;
	RTC_CS = 1;
} // rtc_write_byte

//-------------------------------------------------------------------
// 	rtc_get_time
// 	Purpose:
//  	Gets the time from the RTC:
// 	Parameters:
//  	none
// 	Returns:
//  	returns 0 if no change from last reading time.
//-------------------------------------------------------------------
unsigned char rtc_get_time(time_t *CurrentTime)
{
	unsigned char tmp;
  //-----------------------------------------------------------------
	// copy RTC to RAM:
  //-----------------------------------------------------------------
	rtc_write_byte(RTC_COPY_CLOCK_TO_RAM, 0, 0);
	msec_delay(RTC_DELAY);

  //-----------------------------------------------------------------
	// read the seconds:
  //-----------------------------------------------------------------
	tmp = rtc_read_byte(RTC_SEC_ADDR);
	CurrentTime->second = BCD2num(tmp);

  //-----------------------------------------------------------------
	// read the minutes:
  //-----------------------------------------------------------------
	tmp = rtc_read_byte(RTC_MINUTE_ADDR);
	CurrentTime->minute = BCD2num(tmp);

  //-----------------------------------------------------------------
	// read the hour:
  //-----------------------------------------------------------------
	tmp = rtc_read_byte(RTC_HOUR_ADDR);
	CurrentTime->hour = BCD2num(tmp);

  //-----------------------------------------------------------------
	// read the date:
  //-----------------------------------------------------------------
	tmp = rtc_read_byte(RTC_DATE_ADDR);
	CurrentTime->day = BCD2num(tmp);

  //-----------------------------------------------------------------
	// read the month:
  //-----------------------------------------------------------------
	tmp = rtc_read_byte(RTC_MONTH_ADDR);
	CurrentTime->month = BCD2num(tmp);

  //-----------------------------------------------------------------
	// read the year:
  //-----------------------------------------------------------------
	tmp = rtc_read_byte(RTC_YEAR_ADDR);
	CurrentTime->year = BCD2num(tmp);

	return 1;
} // rtc_get_time


//-------------------------------------------------------------------
// rtc_set_time
// Purpose:
// Parameters:
// Returns:
//-------------------------------------------------------------------
void rtc_set_time(time_t *NewTime, unsigned char secnd)
{
	unsigned char tmp;
#ifdef __DBG
	char tm[30];

	sprintf(tm, "%02d/%02d/%02d %02d:%02d.%02d\r\n", NewTime->day,
			NewTime->month, NewTime->year,NewTime->hour, NewTime->minute, secnd);
	UART_PRNT(tm);
#endif

  //-----------------------------------------------------------------
	// set the seconds
  //-----------------------------------------------------------------
	tmp = Num2BCD(secnd);
	rtc_write_byte(RTC_SEC_ADDR, tmp, 1);

  //-----------------------------------------------------------------
	// set the minutes:
  //-----------------------------------------------------------------
	tmp = Num2BCD(NewTime->minute);
	rtc_write_byte(RTC_MINUTE_ADDR, tmp, 1);

  //-----------------------------------------------------------------
	// set the hour:
  //-----------------------------------------------------------------
	tmp = Num2BCD(NewTime->hour);
	rtc_write_byte(RTC_HOUR_ADDR, tmp, 1);

  //-----------------------------------------------------------------
	// set the date:
  //-----------------------------------------------------------------
	tmp = Num2BCD(NewTime->day);
	rtc_write_byte(RTC_DATE_ADDR, tmp, 1);

  //-----------------------------------------------------------------
	// set the month:
  //-----------------------------------------------------------------
	tmp = Num2BCD(NewTime->month);
	rtc_write_byte(RTC_MONTH_ADDR, tmp, 1);

  //-----------------------------------------------------------------
	// set the year:
  //-----------------------------------------------------------------
	tmp = Num2BCD(NewTime->year);
	rtc_write_byte(RTC_YEAR_ADDR, tmp, 1);

  //-----------------------------------------------------------------
	// clear the lock bit (stat 0 bit 4): to enable setting time
  //-----------------------------------------------------------------
	rtc_write_byte(RTC_STATUS0_ADDR,0,1);
/*
  ?!? 05092001 I changed this
	tmp = rtc_read_byte(RTC_STATUS0_ADDR);
	tmp &= ~BV(4);
	rtc_write_byte(RTC_STATUS0_ADDR, tmp, 1);
*/

  //-----------------------------------------------------------------
	// copy RAM to RTC:
  //-----------------------------------------------------------------
	rtc_write_byte(RTC_COPY_RAM_TO_CLOCK, 0, 0);
	msec_delay(RTC_DELAY);

  //-----------------------------------------------------------------
	// set the lock bit again:
  //-----------------------------------------------------------------
	rtc_write_byte(RTC_STATUS0_ADDR,RTC_TIME_SET_LOCK,1);
/*
	tmp = rtc_read_byte(RTC_STATUS0_ADDR);
	tmp |= BV(4);
	rtc_write_byte(RTC_STATUS0_ADDR, tmp, 1);
*/
} // rtc_set_time

//-------------------------------------------------------------------
// 	rtc_get_status1
// 	Purpose:
//  	Reads RTC status register 1
// 	Parameters:
//  	none
// 	Returns:
//  	Returns the flags which indicate whether the time has changed since last copy
//-------------------------------------------------------------------
unsigned char rtc_get_status1(void)
{
	unsigned char stat;
	stat = rtc_read_byte(RTC_STATUS1_ADDR);
	return stat;
} // rtc_get_status1

//-------------------------------------------------------------------
// 	rtc_read_time
// 	Purpose:
// 	Parameters:
// 	Returns:
//-------------------------------------------------------------------
void rtc_read_time(time_t *T)
{
#ifdef __DBG
	char tm[48];
#endif
	if (rtc_get_time(T)){
#ifdef __DBG
		sprintf(tm, "%02d/%02d/%02d %02d:%02d.%02d\r\n\0",T->day, T->month, T->year, T->hour, T->minute,T->second);
		UART_PRNT(tm);
#endif
	}
} // rtc_read_time

//-------------------------------------------------------------------
// 	rtc_get_min
// 	Purpose:
// 	Parameters:
//  	none
// 	Returns:
//-------------------------------------------------------------------
unsigned char rtc_get_min(void)
{
	unsigned char tmp;
	tmp = rtc_read_byte(RTC_MINUTE_ADDR);
	return (BCD2num(tmp));
} // rtc_get_min

//-------------------------------------------------------------------
// 	rtc_get_sec
// 	Purpose:
// 	Parameters:
//  	none
// 	Returns:
//-------------------------------------------------------------------
unsigned char rtc_get_sec(void)
{
	unsigned char tmp;
	tmp = rtc_read_byte(RTC_SEC_ADDR);
	return (BCD2num(tmp));
} // rtc_get_sec

//-------------------------------------------------------------------
// 	rtc_clk_delay
// 	Purpose:
// 	Parameters:
//  	none
// 	Returns:
//-------------------------------------------------------------------
void rtc_clk_delay(void)
{
	__wait_nop();
} // rtc_clk_delay

//-------------------------------------------------------------------
// 	BCD2num
// 	Purpose:
//  	Converts number from BCD format to normal dec format:
// 	Parameters:
// 	Returns:
//-------------------------------------------------------------------
unsigned char BCD2num(unsigned char bcd_num)
{
	return ((bcd_num & 0xF0) >> 4)*10 + (bcd_num & 0x0F);
} // BCD2num

//-------------------------------------------------------------------
// 	Num2BCD
// 	Purpose:
// 	Parameters:
// 	Returns:
//-------------------------------------------------------------------
unsigned char Num2BCD(unsigned char num)
{
	return ((num/10) << 4) + num%10;
} // Num2BCD

