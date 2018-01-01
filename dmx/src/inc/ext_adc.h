/**  ----------------------------------------------------------
**  $Workfile: ext_adc.h $
**  $Modtime: 8-03-01 14:44 $
**  $Revision: 1 $
**  $Author: Noam $
**  -----------------------------------------------------------
*/
#ifndef EXT_ADC_H
#define EXT_ADC_H

#include "mb90540.h"
//#include "def.h"

#define DIR_OUT     1
#define DIR_IN      0         			// for direction regs

#define PULLUP_USE  1
#define PULLUP_NONE 0

//--------------------------------------------------------------------
// Microcontroller connections to adc10732 serial bus lines.
//--------------------------------------------------------------------
#ifdef OLD_BOARD
//-------------------------------------------------------------------
// Board revision 03
//-------------------------------------------------------------------
#define EXT_ADC_CLK		  		PDR8_P80	// serial clock
#define EXT_ADC_DIN	    		PDR9_P90	// serial data in
#define EXT_ADC_DOUT    		PDR9_P91	// serial data out
#define EXT_ADC_SARS    		PDR9_P92  	// status output
#define EXT_ADC_CS		  		PDR3_P33	// serial cs*
// direction registers
#define EXT_ADC_DIR_CLK		  	DDR8_D80	// serial clock
#define EXT_ADC_DIR_DIN	    	DDR9_D90	// serial data in
#define EXT_ADC_DIR_DOUT    	DDR9_D91	// serial data out
#define EXT_ADC_DIR_SARS    	DDR9_D92  	// status output
#define EXT_ADC_DIR_CS		  	DDR3_D33	// serial cs*
// pullup registers '1'= pullup
#define EXT_ADC_PULL_CLK		PUCR3_PU30	// serial clock
#define EXT_ADC_PULL_CS		  	PUCR3_PU33	// serial cs*
#else
//-------------------------------------------------------------------
// Board revision 06
//-------------------------------------------------------------------
#define EXT_ADC_CLK		  		PDR3_P30	// serial clock
#define EXT_ADC_DIN	    		PDR9_P90	// serial data in
#define EXT_ADC_DOUT    		PDR9_P91	// serial data out
#define EXT_ADC_SARS    		PDR9_P92  	// status output
#define EXT_ADC_CS		  		PDR3_P33	// serial cs*
// direction registers
#define EXT_ADC_DIR_CLK		  	DDR3_D30	// serial clock
#define EXT_ADC_DIR_DIN	    	DDR9_D90	// serial data in
#define EXT_ADC_DIR_DOUT    	DDR9_D91	// serial data out
#define EXT_ADC_DIR_SARS    	DDR9_D92  	// status output
#define EXT_ADC_DIR_CS		  	DDR3_D33	// serial cs*
// pullup registers '1'= pullup
#define EXT_ADC_PULL_CLK		PUCR3_PU30	// serial clock
#define EXT_ADC_PULL_CS		  	PUCR3_PU33	// serial cs*
#endif
//--------------------------------------------------------------------
// adc10732 multiplexor select
//--------------------------------------------------------------------
#define EXT_ADC_POWER_DOWN		0 			// power down all channels
#define EXT_ADC_SINGLE_CH0      3  			// single ended channel 0
#define EXT_ADC_SINGLE_CH1      7   		// single ended channel 1

//--------------------------------------------------------------------
// prototypes
//--------------------------------------------------------------------
void ext_adc_init(void);
void ext_adc_power(unsigned char selection);
unsigned int ext_adc_convert(unsigned char channel);

#endif
