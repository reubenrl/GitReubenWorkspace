/*
 * uartsw2.c
 *
 *  Created on: May 18, 2016
 *      Author: phytech
 */


#include "mb90540.h"

#include "global.h"

#include "uartsw2.h"

// Program ROM constants

// Global variables

// transmit status and data variables
static volatile unsigned char UartswTxBusy;
static volatile unsigned char UartswTxData;
static volatile unsigned char UartswTxBitNum;

// baud rate common to transmit and receive
static volatile unsigned short UartswBaudRateDiv;

// uartsw receive status and data variables
static volatile unsigned char  UartswRxBusy;
static volatile unsigned char  UartswRxData;
static volatile unsigned char  UartswRxBitNum;

// receive buffer
static cBuffer uartswRxBuffer;               ///< uartsw receive buffer
// automatically allocate space in ram for each buffer
static char uartswRxData[UARTSW_RX_BUFFER_SIZE];

// functions

//! enable and initialize the software uart1
void uart1swInit(void)
{
	// initialize the ports
	sbi(UARTSW_TX_DDR, UARTSW_TX_PIN);
	// initialize baud rate
	uartswSetBaudRate(9600);

	// setup the transmitter
	UartswTxBusy = FALSE;
	// disable OC1A interrupt
	cbi(TIMSK1, OCIE1A);

	// disable OC1B interrupt
	cbi(TIMSK1, OCIE1B);


	#ifdef UARTSW_INVERT
	// trigger on rising edge
	sbi(TCCR1B, ICES1);
	#else
	// trigger on falling edge
	cbi(TCCR1B, ICES1);
	#endif
	// enable ICP interrupt
	sbi(TIMSK1, ICIE1);

	// turn on interrupts
	sei();
}


//! turns off software UART
void uartswOff(void)
{
	// disable interrupts
	cbi(TIMSK1, OCIE1A);
	cbi(TIMSK1, OCIE1B);
	cbi(TIMSK1, ICIE1);
	// detach the service routines
	timerDetach(TIMER1OUTCOMPAREA_INT);
	timerDetach(TIMER1OUTCOMPAREB_INT);
	timerDetach(TIMER1INPUTCAPTURE_INT);
}

void uartswSetBaudRate(uint32_t baudrate)
{
	// set timer prescaler
	timer1SetPrescaler(TIMER_CLK_DIV1);
	// calculate division factor for requested baud rate, and set it
	UartswBaudRateDiv = (uint16_t)((16000000UL+(baudrate/2L))/(baudrate*1L));
}

//! returns the receive buffer structure
cBuffer* uartswGetRxBuffer(void)
{
	// return rx buffer pointer
	return &uartswRxBuffer;
}

void uartswSendByte(unsigned char  data)
{
	// wait until uart is ready
	while(UartswTxBusy);
	// set busy flag
	UartswTxBusy = TRUE;
	// save data
	UartswTxData = data;
	// set number of bits (+1 for stop bit)
	UartswTxBitNum = 9;

	// set the start bit
	#ifdef UARTSW_INVERT
	sbi(UARTSW_TX_PORT, UARTSW_TX_PIN);
	#else
	cbi(UARTSW_TX_PORT, UARTSW_TX_PIN);
	#endif

	// schedule the next bit
	outw(OCR1A, inw(TCNT1) + UartswBaudRateDiv);
	// enable OC1A interrupt
	sbi(TIMSK1, OCIE1A);
}

//! gets a byte (if available) from the uart receive buffer
unsigned char  uartswReceiveByte(unsigned char * rxData)
{
	// make sure we have a receive buffer
	if(uartswRxBuffer.size)
	{
		// make sure we have data
		if(uartswRxBuffer.datalength)
		{
			// get byte from beginning of buffer
			*rxData = bufferGetFromFront(&uartswRxBuffer);
			return TRUE;
		}
		else
		{
			// no data
			return FALSE;
		}
	}
	else
	{
		// no buffer
		return FALSE;
	}
}

void uartswTxBitService(void)
{
	if(UartswTxBitNum)
	{
		// there are bits still waiting to be transmitted
		if(UartswTxBitNum > 1)
		{
			// transmit data bits (inverted, LSB first)
			#ifdef UARTSW_INVERT
			if( !(UartswTxData & 0x01) )
			#else
			if( (UartswTxData & 0x01) )
			#endif
				sbi(UARTSW_TX_PORT, UARTSW_TX_PIN);
			else
				cbi(UARTSW_TX_PORT, UARTSW_TX_PIN);
			// shift bits down
			UartswTxData = UartswTxData>>1;
		}
		else
		{
			// transmit stop bit
			#ifdef UARTSW_INVERT
			cbi(UARTSW_TX_PORT, UARTSW_TX_PIN);
			#else
			sbi(UARTSW_TX_PORT, UARTSW_TX_PIN);
			#endif
		}
		// schedule the next bit
		outw(OCR1A, inw(OCR1A) + UartswBaudRateDiv);
		// count down
		UartswTxBitNum--;
	}
	else
	{
		// transmission is done
		// clear busy flag
		UartswTxBusy = FALSE;
	}
}

void uartswRxBitService(void)
{
	// this function runs on either:
	// - a rising edge interrupt
	// - OC1B
	if(!UartswRxBusy)
	{
		// this is a start bit
		// disable ICP interrupt
		cbi(TIMSK1, ICIE1);
		// schedule data bit sampling 1.5 bit periods from now
		outw(OCR1B, inw(TCNT1) + UartswBaudRateDiv + UartswBaudRateDiv/2);
		// clear OC1B interrupt flag
		sbi(TIFR1, OCF1B);
		// enable OC1B interrupt
		sbi(TIMSK1, OCIE1B);
		// set start bit flag
		UartswRxBusy = TRUE;
		// reset bit counter
		UartswRxBitNum = 0;
		// reset data
		UartswRxData = 0;
	}
	else
	{
		// start bit has already been received
		// we're in the data bits

		// shift data byte to make room for new bit
		UartswRxData = UartswRxData>>1;

		// sample the data line
		#ifdef UARTSW_INVERT
		if( !(inb(UARTSW_RX_PORTIN) & (1<<UARTSW_RX_PIN)) )
		#else
		if( (inb(UARTSW_RX_PORTIN) & (1<<UARTSW_RX_PIN)) )
		#endif
		{
			// serial line is marking
			// record '1' bit
			UartswRxData |= 0x80;
		}

		// increment bit counter
		UartswRxBitNum++;
		// schedule next bit sample
		outw(OCR1B, inw(OCR1B) + UartswBaudRateDiv);

		// check if we have a full byte
		if(UartswRxBitNum >= 8)
		{
			// save data in receive buffer
			bufferAddToEnd(&uartswRxBuffer, UartswRxData);
			// disable OC1B interrupt
			cbi(TIMSK1, OCIE1B);
			// clear ICP interrupt flag
			sbi(TIFR1, ICF1);
			// enable ICP interrupt
			sbi(TIMSK1, ICIE1);
			// clear start bit flag
			UartswRxBusy = FALSE;
		}
	}
}

/*
void uartswRxBitService(void)
{
	u16 thisBitTime;
	unsigned char  bitperiods;
	unsigned char  i;

	// bit transition was detected
	// record bit's edge time
	thisBitTime = inw(ICR1);

	cbi(PORTB, 0);

	if(!UartswRxStartBit)
	{
		// this is a start bit
		// switch to falling-edge trigger
		cbi(TCCR1B, ICES1);
		// record bit time
		UartswRxBitTime = thisBitTime;
		// set start bit flag
		UartswRxStartBit = TRUE;
		// reset bit counter
		UartswRxBitNum = 0;
		// reset data
		UartswRxData = 0;
	}
	else
	{
		// start bit has already been received
		// we're in the data bits

		// how many bit periods since last edge?
		bitperiods = (thisBitTime - UartswRxBitTime + UartswBaudRateDiv/2)/UartswBaudRateDiv;
		// set last edge time
		UartswRxBitTime = thisBitTime;

		if(bitperiods > 10)
		{
			// switch to trigger on rising edge
			sbi(TCCR1B, ICES1);
			// clear start bit flag
			UartswRxStartBit = FALSE;
		}
		else
		{


		if( inb(TCCR1B) & (1<<ICES1) )
		{
			// just triggered on a rising edge
			// previous bits were zero
			// shift in the data (data bits are inverted)
			for(i=0; i<bitperiods; i++)
			{
				UartswRxData = UartswRxData<<1;
				UartswRxData |= 0x01;
			}
			// switch to trigger on falling edge
			cbi(TCCR1B, ICES1);
		}
		else
		{
			// just triggered on a falling edge
			// previous bits were one
			// shift in the data (data bits are inverted)
			for(i=0; i<bitperiods; i++)
			{
				UartswRxData = UartswRxData<<1;
			}
			// switch to trigger on rising edge
			sbi(TCCR1B, ICES1);
		}

		// increment bit counter
		UartswRxBitNum += bitperiods;

		// check if we have a full byte + start bit
		if(bitperiods > 8)
		{
			// save data in receive buffer
			bufferAddToEnd(&uartswRxBuffer, UartswRxData);
			// switch to trigger on rising edge
			sbi(TCCR1B, ICES1);
			// clear start bit flag
			UartswRxStartBit = FALSE;
		}
		}
	}

	// turn off debug LEDs
	delay(10);
	sbi(PORTB, 0);
	sbi(PORTB, 1);
}
*/
