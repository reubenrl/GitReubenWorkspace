/*
 * rtc.h
 *
 *  Created on: Dec 11, 2014
 *      Author: reuben
 */

#ifndef RTC_H_
#define RTC_H_


#define RTC_WR		  	PDR0_P03
#define RTC_WR_D	  	DDR0_D03
#define RTC_WR_PULL 	PUCR0_PU03
#define RTC_RD		  	PDR0_P04
#define RTC_RD_D	  	DDR0_D04
#define RTC_RD_PULL 	PUCR0_PU04
#define RTC_IO		  	PDR0_P05
#define RTC_IO_D	  	DDR0_D05
#define RTC_CS		  	PDR3_P35
#define RTC_CS_D	  	DDR3_D35
#define RTC_CS_PULL 	PUCR3_PU35

#define RTC_DELAY		1
#define RTC_TIME_SET_LOCK    (1 << 4) 	// bit 4

//-------------------------------------------------------------------
// General Time Structure
//-------------------------------------------------------------------
typedef struct{
	unsigned char year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
}time_t ;

//-------------------------------------------------------------------
// interrog_struct
//-------------------------------------------------------------------
typedef struct{
  time_t     	start_time;		// 6
  time_t     	next_time;  	// 6
  time_t      	last_time;   	// 6
  unsigned int 	interval;   	// 2
  unsigned char	per_day;     	// 1
  unsigned char	times_today;  	// 1
}interrog_struct;


//-------------------------------------------------------------------
// rec_depth_struct
//-------------------------------------------------------------------
typedef struct{
  unsigned int   cur_count; 		// 2 byte
  unsigned int   interrog_count;  	// 2 byte
  unsigned int   max_count;        	// 2 byte
}rec_depth_struct;



#define TIME_EQUAL    			0 // when time stamps are equal
#define TIME_A_LATER  			1 // when a > b
#define TIME_B_LATER  			2 // when b > a


#define RTC_STATUS0_ADDR		0x00
#define RTC_STATUS1_ADDR		0x01
#define RTC_SEC_ADDR			0x02
#define RTC_MINUTE_ADDR			0x03
#define RTC_HOUR_ADDR			0x04
#define RTC_DATE_ADDR			0x05
#define RTC_MONTH_ADDR			0x06
#define RTC_YEAR_ADDR			0x07
#define RTC_DAY_OF_WEEK			0x08
#define RTC_WEEK_OF_YEAR		0x09

#define RTC_COPY_RAM_TO_CLOCK	0x0E
#define RTC_COPY_CLOCK_TO_RAM	0x0F

void rtc_init(void);
unsigned char rtc_read_byte(unsigned char Addr);
void rtc_write_byte	(unsigned char Cmd, unsigned char byte2Write, unsigned char CmdType);
unsigned char rtc_get_time(time_t *CurrentTime);
void rtc_set_time (time_t	*NewTime, unsigned char secnd);

unsigned char rtc_get_status1(void);
void rtc_read_time(time_t *T);
unsigned char rtc_get_sec(void);


#endif /* RTC_H_ */
