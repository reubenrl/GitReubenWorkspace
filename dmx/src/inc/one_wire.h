/*
 * one_wire.h
 *
 *  Created on: Dec 1, 2014
 *      Author: reuben
 */

#ifndef ONE_WIRE_H_
#define ONE_WIRE_H_

#include "mb90540.h"

#define P50					0
#define P51					1
#define P52					2
#define P53					3
#define P54					4
#define P55					5
#define P56					6
#define P57					7

#define OWMASKBIT0			(1 << P50)
#define OWMASKBIT1			(1 << P51)
#define OWMASKBIT2			(1 << P52)
#define OWMASKBIT3			(1 << P53)
#define OWMASKBIT4			(1 << P54)
#define OWMASKBIT5			(1 << P55)
#define OWMASKBIT6			(1 << P56)
#define OWMASKBIT7			(1 << P57)

#define OWSETBIT(b)			PDR5 |= (1 << (b))
#define OWCLEARBIT(b)		PDR5 &= ~(1 << (b))

#define OWDIRBIT(b,d)		((d) ? (DDR5 |= (1 << (b))) : (DDR5 &= ~(1 << (b))))

#define OWOUTPUTBIT(b)		DDR5 &= ~(1 << (b))
#define OWINPUTBIT(b)		DDR5 |= (1 << (b))


#define OW_IO			PDR5_P50
#define OW_IO_DIR		DDR5_D50
#define owb(i)			OW_IO = (i)
#define OWSET			1
#define OWCLEAR			0
#define owbd(i)			OW_IO_DIR = (i)
#define OWDIROUT		1
#define OWDIRIN			0
#define owbin()			OW_IO

// Standard Speed
// write '1' slot
#define	WRITEONE_A 		6/2
#define	WRITEONE_B		114/2
// write '0' slot
#define	WRITEZERO_C 	80/2
#define	WRITEZERO_D 	40/2

	// read bit
#define READSTART_A		WRITEONE_A
#define READSAMPLE_E 	8/2
#define	READRECOVERY_F	112/2

//#define		G			0;
	// reset pulse
#define RSTZERO_H 		500/2
#define	RSTONE_I 		80/2
#define RSTRECOVERY_J 	400/2


void ow_init(unsigned char ow_port_bit);
//unsigned char OWTouchReset(void);
unsigned char OWTouchReset(unsigned char ow_io_bit);
unsigned char ow_read_rom(unsigned char ow_io_bit, unsigned char *p_buff_out, unsigned char buff_out_len);
unsigned char wo_read_scratchpad(unsigned char ow_io_bit, unsigned char *p_buff_out, unsigned char buff_out_len);


#endif /* ONE_WIRE_H_ */
