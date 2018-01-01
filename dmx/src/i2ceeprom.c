/*
 * i2ceeprom.c
 *
 *  Created on: Dec 10, 2014
 *      Author: reuben
 */

#include "mb90540.h"
#include "timer0.h"
#include "debug_uart.h"
#include "i2c_sw.h"
#include "i2ceeprom.h"

#define DEBUG_E2
//-------------------------------------------------------------------
//	eeprom_write_byte
// 	Purpose:
//  	AT24Cxx Byte Write function.
//  	Does not wait for write cycle to complete.
// 	Parameters:
//  	data - data to be written
//  	addr_hi - address hi
//  	addr_lo - address lo
// 	Returns:
//  	1 = to indicate that the bus is not available
//      or that the addressed device failed to acknowledge.
//  	0 = OK
//-------------------------------------------------------------------
unsigned char eeprom_write_byte(unsigned char data, unsigned char addr_hi, unsigned char addr_lo)
{
	WR_PROTECT = UNPROTECTED; 				// no protection
	if ( i2c_start() ){
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD Start err!");
		#endif
	}else if ( i2c_send_byte(DEVICEADDR) ) { 	// send device address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD Device Address error!");
		#endif                  // write protected
	}else if ( i2c_send_byte(addr_hi) ) {  	// send hi byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD AddrHi error!");
		#endif
	}else if ( i2c_send_byte(addr_lo) ) {  	// send low byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD AddrLo error!");
		#endif
	}else if ( i2c_send_byte(data) ){ 		// send low byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD data error!");
		#endif
	}else return (0);

	i2c_stop();                         	// leave in stopped state
	WR_PROTECT = PROTECTED;               	// write protected
	return (1);
} // eeprom_write_byte

//-------------------------------------------------------------------
//	eeprom_read_current
// 	Purpose:
//  	AT24Cxx Current Address Read function.
// 	Parameters:
//  	data_out - data read
// 	Returns:
//  	1 = to indicate that the bus is not available
//      	or that the addressed device failed to acknowledge.
//  	0 = OK
//-------------------------------------------------------------------
unsigned char eeprom_read_current(unsigned char *data_out)
{
	if (i2c_start()){
		#ifdef DEBUG_E2
		DBG_TXT("EEprom ReadCurrent BAD Start err!");
		#endif
	}else if (i2c_send_byte(DEVICEADDR | 0x01)){	// send device address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Read Current BAD AddrHi err!");
		#endif
	}else{
		*data_out = i2c_get_byte();       	// receive data byte
		i2c_nak();                  	// do not acknowledge byte
		i2c_stop();        				// leave in stopped state
		 return (0);
	}

	return (1);
} // eeprom_read_current

//-------------------------------------------------------------------
//	eeprom_read_random
// 	Purpose:
//  	AT24Cxx Random Read function.
// 	Parameters:
//  	data_out	- data read
//  	addr_hi 	- address hi
//  	addr_lo 	- address lo
// 	Returns:
//  	1 = to indicate that the bus is not available
//      	or that the addressed device failed to acknowledge.
//  	0 = OK
//-------------------------------------------------------------------
unsigned char eeprom_read_random(unsigned char *data_out ,unsigned char addr_hi,unsigned char addr_lo)
{
	// Send dummy write command to set internal address.
	if (i2c_start()){
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read NO START err!");
		#endif
	}else if (i2c_send_byte(DEVICEADDR)){                       // send device address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read BAD Device Addr!");
		#endif
	}else if (i2c_send_byte(addr_hi)){                     // send high byte of address                              // abort if no acknowledge
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read BAD AddrHi err!");
		#endif
	}else if (i2c_send_byte(addr_lo)){                     // send low byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read BAD AddrLo err!");
		#endif
	}else{
		 // Call Current Address Read function.
		 return eeprom_read_current(data_out);
	}

	return (1);
} // eeprom_read_random

//-------------------------------------------------------------------
// eeprom_write_page
// Purpose:
//  Writes up to 32 bytes on the same page.
//  Can NOT cross page borders.
//  Does not wait until Write is finished!
//  Must wait after each write_page!
// Parameters:
//  data - data to be written
//  dataLen - amount of bytes to write on this page
//  addr_hi - address hi
//  addr_lo - address lo
// Returns:
//  1 = to indicate that the bus is not available
//      or that the addressed device failed to acknowledge.
//  0 = OK
//-------------------------------------------------------------------
unsigned char eeprom_write_page(unsigned char *buff_in, unsigned char buff_in_len, unsigned char addr_hi, unsigned char addr_lo)
{
	unsigned char i, eeprom_write_error = 1;

	WR_PROTECT = UNPROTECTED;         			// no protection
	if (i2c_start()){
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD Start err!");
		#endif
	}else if (i2c_send_byte(DEVICEADDR)){          	// send device address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD Device Addr err!");
		#endif
	}else if (i2c_send_byte(addr_hi)){        	// send hi byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD AddrHi err!");
		#endif
	}else if (i2c_send_byte(addr_lo)){       	// send low byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Write BAD AddrLo err!");
		#endif
	}else{
		for (i = 0; i < buff_in_len ; i++) {
			if (i2c_send_byte(buff_in[i])){  	// send low byte of address
				#ifdef DEBUG_E2
				DBG_TXT("EEprom Write BAD data err!");
				#endif
				break;
			}else eeprom_write_error = 0;
		} // end for
	}

	i2c_stop();                     			// leave in stopped state
	WR_PROTECT = PROTECTED;             		// write protected
	return (eeprom_write_error);
} // eeprom_write_page

//-------------------------------------------------------------------
// 	eeprom_write_pages
// 	Purpose:
//  	Writes across page boundaries.
//  	Waits until all the data is written.
// 	Parameters:
//  	buff_in 	- data to be written
//  	buff_in_len - amount of bytes to write
//  	addr 		- address
// 	Returns:
//  	1 = Error
//  	0 = OK
//-------------------------------------------------------------------
unsigned char eeprom_write_pages(unsigned char *buff_in, unsigned char  buff_in_len, t_data_type eaddr)
{
	unsigned char  num,i,offset = 0;
	t_data_type cur_addr;

	while (buff_in_len){        					// until all bytes written
		cur_addr = eaddr;
		num = 0;
		for (i=0;i<buff_in_len;i++){        		// check how many bytes to write each time
			cur_addr.word ++;
			num++;
			if (num>=E2_PAGE_SIZE ||            	// more or equal to page size?
			!(cur_addr.word%E2_PAGE_SIZE))          // on page border?
				break;
		}// end for
		if (eeprom_write_page((unsigned char*)&buff_in[offset],num,
				eaddr.byte.msb,eaddr.byte.lsb)){
			return 1;
		}

		msec_delay(10);
		eaddr.word += num;
		offset     += num;
		buff_in_len   -= num;
	}// end wile
  return 0;                                      // OK
} // eeprom_write_pages

//-------------------------------------------------------------------
// 	eeprom_read_page
// 	Purpose:
//  	Reads dataLen bytes from the address
// 	Parameters:
//  	buff_out 		- data to be written
//  	buff_out_len 	- amount of bytes to read
//  	addr_hi 		- address hi
//  	addr_lo 		- address lo
// 	Returns:
//  	1 = to indicate that the bus is not available
//      	or that the addressed device failed to acknowledge.
//  	0 = OK
//-------------------------------------------------------------------
unsigned char eeprom_read_page(unsigned char *buff_out, unsigned char buff_out_len, unsigned char addr_hi, unsigned char addr_lo)
{
	unsigned char i;

	if (i2c_start()){
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read NO START err!");
		#endif
	}else if (i2c_send_byte(DEVICEADDR)){                       // send device address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read BAD Device Addr!");
		#endif
	}else if (i2c_send_byte(addr_hi)){                     // send low byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read BAD AddrHi err!");
		#endif
	}else if (i2c_send_byte(addr_lo)){                     // send low byte of address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Random Read BAD AddrLo err!");
		#endif
	}else if (i2c_start()) {
		#ifdef DEBUG_E2
		DBG_TXT("E2 Read page BAD Start 2 err!");
		#endif                               // abort if bus not available
	}else if (i2c_send_byte(DEVICEADDR | 0x01)){                // send device address
		#ifdef DEBUG_E2
		DBG_TXT("EEprom Read Current BAD AddrHi err!");
		#endif
	}else{
		 for (i = 0; i < buff_out_len; i++) {
			 buff_out[i] = i2c_get_byte();                      // receive data byte
			 if (i < (buff_out_len-1)) {
				 i2c_ack();                                   // ack for more data
			 }
		 } // end of: for
		 i2c_stop();
		 return 0;
	}

	i2c_stop();

	return 1;
} // eeprom_read_page

//-------------------------------------------------------------------
// 	eeprom_erase_all
// 	Purpose:
//  	Programs all e2prom bytes to 0xFF!
// 	Parameters:
//  	none
// 	Returns:
//  	1 = Failure
//  	0 = OK
//-------------------------------------------------------------------
unsigned char eeprom_erase_all(void)
{
	t_data_type    addr;

	unsigned int  i;
	const unsigned char value[64] =
						{0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF, 	//  8
                         0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,  	//  16
                         0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,  	//  24
                         0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF, 	//  32
                         0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,  	//  40
                         0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,  	//  48
                         0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF, 	//  56
                         0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF  	//  64
                        };

	#ifdef EPROM_8K
	//-------------------------------------------------------------------
	// Board revision 03 8K
	//-------------------------------------------------------------------
	addr.word = 0;
	for (i=0;i<256;i++){
		addr.word = 0 + (i*32);
		if (eeprom_write_page((unsigned char*)value,32,addr.bytes[MSB_WORD_BYTES], addr.bytes[LSB_WORD_BYTES]))
				return 1;             	// write failure
		msec_delay(10);                     	// write delay
		//   addr.word += 32;
	}
	#else
//-------------------------------------------------------------------
// Board revision 06 64K
//-------------------------------------------------------------------
	for (i=0;i<512;i++){
		addr.word = i*64;
#ifdef DEBUG_E2
		UART_MSG("-");
#endif
		if (eeprom_write_page((unsigned char*)value,64,addr.byte.msb, addr.byte.lsb))
			return 1;  	// write failure
		msec_delay(10);  	// write delay
	}
#ifdef DEBUG_E2
		UART_MSG("\r\n");
#endif
	#endif
	return 0;   		// return OK!
} // eeprom_erase_all

