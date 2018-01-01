/**  ----------------------------------------------------------
**  $Workfile: e2.h $
**  $Modtime: 18-04-02 10:48 $
**  $Revision: 2 $
**  $Author: Noam $
**  -----------------------------------------------------------
*/
#ifndef I2C_SW_H
#define I2C_SW_H


#define UNPROTECTED		0 		// not write protected
#define PROTECTED     	1 		// write protected


#define DIR_OUT     	1
#define DIR_IN      	0 		// for direction regs
#define AT24CxxADDR		0xA0	// fixed address for AT24Cxx EEPROMs
#define DEVICEADDR      AT24CxxADDR

// Microcontroller connections to AT24Cxx serial bus lines.
#ifdef OLD_BOARD
//-------------------------------------------------------------------
// Board revision 03
//-------------------------------------------------------------------
#define SCL           PDR8_P82                   // serial clock
#define SDA           PDR0_P02                   // serial data
#define WR_PROTECT    PDR0_P07                   // write protect

#define SCL_DIRECTION        DDR8_D82            // serial clock
#define SDA_DIRECTION        DDR0_D02            // serial data
#define WR_PROTECT_DIRECTION DDR0_D07            // write protect

#define SCL_PULLUP           PUCR0_PU02          // serial clock does not have a pullup!
#define SDA_PULLUP           PUCR0_PU02          // serial data
#define WR_PROTECT_PULLUP    PUCR0_PU07          // write protect


#else
//-------------------------------------------------------------------
// Board revision 06
//-------------------------------------------------------------------
#define SCL             	PDR3_P32            // serial clock
#define SDA               	PDR0_P02            // serial data
#define WR_PROTECT       	PDR3_P36            // write protect

#define SCL_DIR        		DDR3_D32            // serial clock
#define SDA_DIR        		DDR0_D02            // serial data
#define WR_PROTECT_DIR 		DDR3_D36            // write protect

#define SCL_PULLUP       	PUCR3_PU32          // serial clock
#define SDA_PULLUP      	PUCR0_PU02          // serial data
#define WR_PROTECT_PULLUP	PUCR3_PU36          // write protect
#endif

//void i2c_init(void);
void i2c_init(void);
void i2c_nak(void);
void i2c_ack(void);
unsigned char i2c_get_byte(void);
unsigned char i2c_send_byte(unsigned char data);
void i2c_stop(void);
unsigned char i2c_start(void);

#endif
