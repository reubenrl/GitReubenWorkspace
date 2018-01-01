//===================================================================
//  $Workfile: e2.c $
//  $Modtime: 3-04-01 16:11 $
//  $Revision: 1 $
//  $Author: Noam $
//===================================================================

//--------------------------------------------------------------------
// E2.C         
//
// This collection of routines allows a microcontroller to read
// and write the AT24Cxx family of serial CMOS EEPROMS.
// All five AT24Cxx device operations are supported. Byte Write, Current
// Address Read and Random Read are implemented by the functions WRITE_BYTE,
// READ_CURRENT and READ_RANDOM, respectively. Page Write and Sequential Read
// are special cases of functions WRITE_BLOCK and READ_BLOCK, respectively.
// WRITE_BLOCK and READ_BLOCK process from one byte to the number of bytes
// in a page and transfer data between the AT24Cxx and the RAM buffer.
//
// The code supports multiple AT24Cxx devices per bus, each with a unique
// address determined by the wiring of the address pins (A0, A1, A2). The
// three-bit programmable address is passed to the WRITE_BYTE, READ_CURRENT,
// READ_RANDOM, WRITE_BLOCK and READ_BLOCK functions, where it is combined
// with the AT24Cxx fixed address (FADDR) and used to address a device on the
// bus. Refer to the AT24Cxx family data sheets for additional information on
// device addressing.
//
// The code meets all AT24Cxx family timing requirements when executed by an
// AT89Cx051 microcontroller with a 12 MHz clock. Code modifications may be
// required if a faster clock is substituted.
//--------------------------------------------------------------------

#include "mb90540.h"
#include "i2c_sw.h"


static int i2c_dly;
#define i2c_delay_2usec(a)		i2c_dly = (a); while(i2c_dly--){ __wait_nop();} // 2 usec.

//--------------------------------------------------------------------
// i2c_init
// Purpose:
//  Initializes the I2C bus
// Parameters:
//  none
// Returns:
//--------------------------------------------------------------------
void i2c_init(void)
{
	// Initialize AT24Cxx serial bus lines.
	SDA = 1;  						// high
	SCL = 1;    					// high
	WR_PROTECT = PROTECTED;  		// write protected
	SCL_DIR = DIR_OUT;
	SDA_DIR = DIR_OUT;
	WR_PROTECT_DIR = DIR_OUT;
	PUCR0_PU02 = 1;   				// DATA (P02) uses pullup resistor
	PUCR0_PU07 = 1;            		// WP   (P07) uses pullup resistor
} // i2c_init

//--------------------------------------------------------------------
//	i2c_device_busy
// 	Purpose:
//  	Checks if the device returns ACK indicating that it is ready.
// 	Parameters:
//  	dev_addr - the address of the chip to be checked
// 	Returns:
//  	1 = indicate that the bus is not available
//     		or that the addressed device failed to acknowledge.
//     		This means the eeprom has not finished a write.
//  	0 = device is ready
//--------------------------------------------------------------------
unsigned char i2c_device_busy(unsigned char dev_addr)
{
	if (i2c_start()){
		i2c_stop();                         	//
		return (1);                       		// abort if bus not available
	}

	if (i2c_send_byte(dev_addr | 0x01)){    		// send device address (read)
		i2c_stop();                        		// abort if no acknowledge - busy
		return (1);
	}                                  			// abort if no acknowledge

	i2c_stop();                         		//
	return (0);                        			// not busy!
} // i2c_device_busy




//-------------------------------------------------------------------
//	i2c_start
// 	Purpose:
//  	Sends e2_start, defined as high-to-low SDA with SCL high.
//  	Return with SCL, SDA low.
// 	Parameters:
//  	none
// 	Returns:
//  	1 = to indicate that the bus is not available
//      	or that the addressed device failed to acknowledge.
//  	0 = OK
//-------------------------------------------------------------------
unsigned char i2c_start(void)
{
	SDA = 1;
	SDA_DIR = DIR_OUT;
	SCL = 1;
	// Verify bus available.
	if (!SDA || !SCL) return 1;   	// error if not high
	i2c_delay_2usec(40/2); 		 	// enforce setup delay and cycle delay 40usec
	SDA = 0;
	i2c_delay_2usec(200/2); 		// enforce hold delay 200usec
	SCL = 0;

	return 0;                  		// set OK
} // i2c_start

//-------------------------------------------------------------------
//	i2c_stop
// 	Purpose:
//  	Sends STOP, defined as low-to-high SDA with SCL high.
//  	SCL expected low on entry. Return with SCL, SDA high.
// 	Parameters:
//  	none
// 	Returns:
//  	1 = to indicate that the bus is not available
//      	or that the addressed device failed to acknowledge.
//  	0 = OK
//-------------------------------------------------------------------
void i2c_stop(void)
{
	SDA_DIR = DIR_OUT;
	SDA = 0;
	i2c_delay_2usec(80/2)	// enforce SCL low and data setup 80usec
	SCL = 1;
	i2c_delay_2usec(200/2)	// enforce setup delay 200usec
	SDA = 1;
}  // i2c_stop

//-------------------------------------------------------------------
// 	i2c_send_byte
// 	Purpose:
//  	Shifts out a byte to the AT24Cxx, most significant bit first.
//  	SCL, SDA expected low on entry. Return with SCL low.
// 	Parameters:
//  	byte_in - byte to be written
// 	Returns:
//  	1 = to indicate failure by slave to acknowledge.
//  	0 = OK
//-------------------------------------------------------------------
unsigned char i2c_send_byte(unsigned char byte_in)
{
	unsigned char i;
	SDA_DIR = DIR_OUT;
	for(i=0;i<8;i++){    				// bit count
		if (byte_in & 0x80) SDA = 1; 	// output bit 1
		else SDA = 0;      				// output bit 0
		byte_in <<= 1;
		i2c_delay_2usec(40/2);  		// enforce SCL low and data setup
		SCL = 1;                     	// raise clock
		i2c_delay_2usec(160/2);       	// enforce SCL high 160usec
		SCL = 0;                      	// drop clock
	}       
	
	SDA_DIR = DIR_IN;               	// release SDA for ACK input
	i2c_delay_2usec(80/2);          	// enforce SCL low and delay 80usec
	SCL = 1;                        	// raise ACK clock
	i2c_delay_2usec(160/2);          	// enforce SCL high 160usec
	i = (SDA & 0x01);               	// get ACK bit
	SCL = 0;                       		// drop ACK clock
	
	return i;
}


//-------------------------------------------------------------------
// 	i2c_get_byte
// 	Purpose:
//  	Shifts in a byte from the AT24Cxx, most significant bit first.
//  	SCL expected low on entry. Return with SCL low.
// 	Parameters:
//  	none
// 	Returns:
//  	data byte received
//-------------------------------------------------------------------
unsigned char i2c_get_byte(void)
{
	unsigned char i, data=0;
 
	SDA_DIR = DIR_IN;  					// make SDA an input
	for(i=0;i<8;i++){           		// bit count
		i2c_delay_2usec(120/2);     	// enforce SCL low and data setup 120usec
		SCL = 1;                      	// raise clock
		i2c_delay_2usec(80/2);   		// enforce SCL high 80usec
		data <<= 1;        				// move bit into byte
		if (SDA)  data |= 0x01;   		// input bit
		SCL = 0;         				// drop clock
	}                                 	// next bit
 return data;
}


//-------------------------------------------------------------------
// 	i2c_ack
// 	Purpose:
// 	 	Clock out an acknowledge bit (low).
//  	SCL expected low on entry. Return with SCL, SDA low.
// 	Parameters:
//  	none
// 	Returns:
//  	none
//-------------------------------------------------------------------
void i2c_ack(void)
{
	SDA = 0;             		// ACK bit
	SDA_DIR = DIR_OUT;
	i2c_delay_2usec(80/2); 		// enforce SCL low and data setup 80usec
	SCL = 1;               		// raise clock
	i2c_delay_2usec(160/2);  	// enforce SCL high 160usec
	SCL = 0;                  	// drop clock
} // i2c_ACK

//-------------------------------------------------------------------
// 	i2c_nak
// 	Purpose:
//  	Clock out a negative acknowledge bit (high).
//  	SCL expected low on entry. Return with SCL low, SDA high.
// 	Parameters:
//  	none
// 	Returns:
//  	none
//-------------------------------------------------------------------
void i2c_nak(void)
{
	SDA = 1;         		// NAK bit
	SDA_DIR = DIR_OUT;
	i2c_delay_2usec(80/2); 	// enforce SCL low and data setup
	SCL = 1;              	// raise clock
	i2c_delay_2usec(160/2);	// enforce SCL high
	SCL = 0;               	// drop clock
} // i2c_nak



