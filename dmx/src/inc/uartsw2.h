/*
 * uartsw2.h
 *
 *  Created on: May 18, 2016
 *      Author: phytech
 */

#ifndef UARTSW2_H_
#define UARTSW2_H_


#include "global.h"
#include "buffer.h"

// include configuration
#include "uartswconf.h"

// constants/macros/typdefs

// functions

//! enable and initialize the software uart
void uartswInit(void);
//! create and initialize the uart buffers
void uartswInitBuffers(void);
//! turns off software UART
void uartswOff(void);
//! returns the receive buffer structure
cBuffer* uartswGetRxBuffer(void);
//! sets the uart baud rate
void uartswSetBaudRate(uint32_t baudrate);
//! sends a single byte over the uart
void uartswSendByte(unsigned char  data);

//! gets a single byte from the uart receive buffer
// Function returns TRUE if data was available, FALSE if not.
// Actual data is returned in variable pointed to by "data".
// example usage:
// char myReceivedByte;
// uartswReceiveByte( &myReceivedByte );
unsigned char  uartswReceiveByte(unsigned char * rxData);

//! internal transmit bit handler
void uartswTxBitService(void);
//! internal receive bit handler
void uartswRxBitService(void);

#endif /* UARTSW2_H_ */
