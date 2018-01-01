/*
 * one_wire.c
 *
 *  Created on: Nov 29, 2014
 *      Author: reuben
 */

#include "one_wire.h"
#include "global.h"
#include "timer0.h"
#include "debug_uart.h"


static int ow_dly;
#define ow_delay(a)		ow_dly = (a); while(ow_dly--){ __wait_nop();}


// Pause for exactly 'tick' number of ticks = 0.25us

void ow_init(unsigned char ow_port_bit)
{
	if(ow_port_bit & OWMASKBIT0){
		OWINPUTBIT(P50);
		OWSETBIT(P50);
	}
	if(ow_port_bit & OWMASKBIT1){
		OWINPUTBIT(P51);
		OWSETBIT(P51);
	}
	if(ow_port_bit & OWMASKBIT2){
		OWINPUTBIT(P52);
		OWSETBIT(P52);
	}
	if(ow_port_bit & OWMASKBIT3){
		OWINPUTBIT(P53);
		OWSETBIT(P53);
	}
	if(ow_port_bit & OWMASKBIT4){
		OWINPUTBIT(P54);
		OWSETBIT(P54);
	}
	if(ow_port_bit & OWMASKBIT5){
		OWINPUTBIT(P55);
		OWSETBIT(P55);
	}
	if(ow_port_bit & OWMASKBIT6){
		OWINPUTBIT(P56);
		OWSETBIT(P56);
	}
	if(ow_port_bit & OWMASKBIT7){
		OWINPUTBIT(P57);
		OWSETBIT(P57);
	}
}

//-----------------------------------------------------------------------------
// Generate a 1-Wire reset, return 1 if no presence detect was found,
// return 0 otherwise.
// (NOTE: Does not handle alarm presence from DS2404/DS1994)
//
unsigned char OWTouchReset(unsigned char ow_io_bit)
{
	unsigned char result;

	OWDIRBIT(ow_io_bit, OWDIROUT);
	OWCLEARBIT(ow_io_bit);				// Drives DQ low
	ow_delay(RSTZERO_H);				// 500 usec
	__DI();                   			/* disable interrupts */
	OWSETBIT(ow_io_bit);				// Releases the bus
	OWDIRBIT(ow_io_bit, OWDIRIN);
	ow_delay(RSTONE_I);					// 80 usec
	result = PDR5 & (1 << ow_io_bit);	// Sample for presence pulse from slave
	 __EI(); 							/* global enable interrupts */
	ow_delay(RSTRECOVERY_J);			// Complete the reset sequence recovery 240 usec

	return result; // Return sample presence pulse result
}

//-----------------------------------------------------------------------------
// Send a 1-Wire write bit. Provide 10us recovery time.
//
static void OWWriteBit(unsigned char ow_io_bit, unsigned char owbit)
{
	__DI();                   		/* disable interrupts */
	OWDIRBIT(ow_io_bit, OWDIROUT);
	if(owbit){// Write '1' bit
		OWCLEARBIT(ow_io_bit);		// Drives DQ low
		ow_delay(WRITEONE_A);
      	OWSETBIT(ow_io_bit);		// Releases the bus
     	ow_delay(WRITEONE_B); 		// Complete the time slot
	}else{// Write '0' bit
		OWCLEARBIT(ow_io_bit);	 	// Drives DQ low
    	ow_delay(WRITEZERO_C);
    	OWSETBIT(ow_io_bit);		// Releases the bus
     	ow_delay(WRITEZERO_D);		// Complete the time slot
  	}
	OWDIRBIT(ow_io_bit, OWDIRIN);
	 __EI(); 						/* global enable interrupts */
}
//      10 13 14 C4 17 99 AA CHKS
//---------------------------------------------------
// Read a bit from the 1-Wire bus and return it.
//
static unsigned char OWReadBit(unsigned char ow_io_bit)
{
	unsigned char result;
	__DI();                   			/* disable interrupts */
	OWDIRBIT(ow_io_bit, OWDIROUT);
	OWCLEARBIT(ow_io_bit);				// Drives DQ low
	ow_delay(READSTART_A);
	OWSETBIT(ow_io_bit);				// Releases the bus
	OWDIRBIT(ow_io_bit, OWDIRIN);
 	ow_delay(READSAMPLE_E);
 	result = PDR5 & (1 << ow_io_bit);	// Sample the bit value from the slave
 	ow_delay(READRECOVERY_F);			// Complete the time slot and 60us recovery
 	 __EI(); 							/* global enable interrupts */
  	return  result;
}

//-----------------------------------------------------------------------------
// Write 1-Wire data byte
//
void OWWriteByte(unsigned char ow_io_bit, unsigned char owbyte)
{
	unsigned char bit_cnt, tmp;

   	// Loop to write each bit in the byte, LS-bit first
	for(bit_cnt=0; bit_cnt < 8; bit_cnt++){
		tmp = owbyte & 0x01;
		OWWriteBit(ow_io_bit, tmp);
		// shift the data byte for the next bit
		owbyte >>= 1;
	}
}

//-----------------------------------------------------------------------------
// Read 1-Wire data byte and return it
//
unsigned char OWReadByte(unsigned char ow_io_bit)
{
	unsigned char bit_cnt, result=0;

	for ( bit_cnt = 0;  bit_cnt < 8;  bit_cnt++){
		// shift the result to get it ready for the next bit
		result >>= 1;
		// if result is one, then set MS bit
		if (OWReadBit(ow_io_bit)) result |= 0x80;
	}

	return result;
}

//-----------------------------------------------------------------------------
// Write a 1-Wire data byte and return the sampled result.
//
unsigned char OWTouchByte(unsigned char ow_io_bit, unsigned char data)
{
	unsigned char loop, result=0;

	for (loop = 0; loop < 8; loop++){
		// shift the result to get it ready for the next bit
		result >>= 1;

		// If sending a '1' then read a bit else write a '0'
		if (data & 0x01){
			if (OWReadBit(ow_io_bit))
				result |= 0x80;
		}
		else
			OWWriteBit(ow_io_bit, 0);

		// shift the data byte for the next bit
		data >>= 1;
	}
	return result;
}



unsigned char ow_read_rom(unsigned char ow_io_bit, unsigned char *p_buff_out, unsigned char buff_out_len)
{
	unsigned char i;

	// select the device
	if (OWTouchReset(ow_io_bit)){ 	// Reset the 1-Wire bus
#ifdef __DBG
		DBG_TXT("ow_read_rom(OWTouchReset fail)");
#endif
		return 0; 					// Return if no devices found
	}
	OWWriteByte(ow_io_bit, 0x33);	//  send READ ROM COMMAND
	for(i=0;i<200;i++)  __wait_nop();
    // read rom code
     for(i = 0; i <  buff_out_len; i++) *p_buff_out++ = OWReadByte(ow_io_bit);

     return 1;
}

unsigned char wo_start_conv(unsigned char ow_io_bit)
{
	if (OWTouchReset(ow_io_bit)){ 	// Reset the 1-Wire bus
#ifdef __DBG
		DBG_TXT("wo_start_conv(OWTouchReset fail)");
#endif
		return 0; 					// Return if no devices found
	}
	OWWriteByte(ow_io_bit, 0xCC);	//  send Skip ROM command.

	OWWriteByte(ow_io_bit, 0x44);	//  send Convert T command.

	msec_delay(700UL);

	return 1;

}

unsigned char wo_read_scratchpad(unsigned char ow_io_bit, unsigned char *p_buff_out, unsigned char buff_out_len)
{
	unsigned char i;

	if (!wo_start_conv(ow_io_bit)) return 0;

	if (OWTouchReset(ow_io_bit)){ 	// Reset the 1-Wire bus
#ifdef __DBG
		DBG_TXT("wo_read_scratchpad(OWTouchReset fail - 1)");
#endif
		return 0; 					// Return if no devices found
	}
	OWWriteByte(ow_io_bit, 0xCC);	//  send Skip ROM command.
	OWWriteByte(ow_io_bit, 0xBE);	//  send Read Scratchpad command.

	 for(i = 0; i < buff_out_len; i++)  *p_buff_out++ = OWReadByte(ow_io_bit);

	if (OWTouchReset(ow_io_bit)){ 	// Reset the 1-Wire bus
#ifdef __DBG
		DBG_TXT("wo_read_scratchpad(OWTouchReset fail - 2)");
#endif
		return 0; 					// Return if no devices found
	}
	return 1;
}
