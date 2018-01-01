/*
 * i2ceeprom.h
 *
 *  Created on: Dec 10, 2014
 *      Author: reuben
 */

#ifndef I2CEEPROM_H_
#define I2CEEPROM_H_

#include "global.h"

#ifdef EPROM_8K
//-------------------------------------------------------------------
// EEPROM 8K
//-------------------------------------------------------------------
#define E2_PAGE_SIZE         32
#define E2_SENSOR_PAGE_SIZE  32
#define ONE_SENSOR_PAGES     5                         // 5 * 32 = 160
#define SENSOR_DATA_SIZE     ONE_SENSOR_PAGES*32U      // 160
#define SENSOR_HEADER_SIZE   8                         // id(4) status(1) interval(1) wr_addr(2)
#define SENSOR_MAX_RECORDS   66                        // 160-8-20=132/2=66
#define SENSOR_ALERT_REC_DEPTH 50

#define E2_CONFIG_ADDR            0x0100U        // 128 bytes of config
#define E2_CONFIG_MIRROR_ADDR     0x0180U        // 128 bytes of config mirror
#define E2_1ST_SENSOR_ADDR        0x0200U        // 512

#else
//-------------------------------------------------------------------
// EEPROM 64K - 64byte pages but sensor is still arranged in 32byte pages
//-------------------------------------------------------------------
#define E2_PAGE_SIZE         		64
#define E2_SENSOR_PAGE_SIZE  		32
#define E2_PAGE_BOUNDARY_NOT 		0xFFE0               	// 0..31 notted
#define ONE_SENSOR_PAGES     		21                    	// 21 * 32 = 672
#define SENSOR_DATA_SIZE     		ONE_SENSOR_PAGES*32U  	// 672
#define SENSOR_HEADER_SIZE   		10                    	// id(4) status(1) interval(1) wr_addr(2) additional-status(1) spare(1)
#define SENSOR_MAX_RECORDS   		289                    	// 672-10-(4*21)=580/2=290
#define SENSOR_ALERT_REC_DEPTH 		218                  	// 3/4 full
#define RECORDS_IN_NOTFIRST_PAGE  	14                   	// (E2_SENSOR_PAGE_SIZE - TIME) / 2
#define RECORDS_IN_FIRST_PAGE     	9                    	// (E2_SENSOR_PAGE_SIZE - HEADER - TIME) / 2

#define E2_CONFIG_ADDR            	0x0100U        // 128 bytes of config
#define E2_CONFIG_MIRROR_ADDR     	0x0180U        // 128 bytes of config mirror
#define E2_1ST_SENSOR_ADDR        	0x0200U        // 0x200..0x7FFF
#endif


//-------------------------------------------------------------------
// prototypes
//-------------------------------------------------------------------
unsigned char eeprom_read_random(unsigned char *data_out ,unsigned char addr_hi,unsigned char addr_lo);
unsigned char eeprom_read_current(unsigned char *data_out);
unsigned char eeprom_write_byte(unsigned char data, unsigned char addr_hi, unsigned char addr_lo);
unsigned char eeprom_erase_all(void);
//byte sensor_get_interval(long_bytes id,byte *interval);

unsigned char eeprom_write_page(unsigned char *buff_in, unsigned char buff_in_len, unsigned char addr_hi, unsigned char addr_lo);
unsigned char eeprom_write_pages(unsigned char *buff_in, unsigned char  buff_in_len, t_data_type eaddr);
unsigned char eeprom_read_page(unsigned char *buff_out, unsigned char buff_out_len, unsigned char addr_hi, unsigned char addr_lo);


#endif /* I2CEEPROM_H_ */
