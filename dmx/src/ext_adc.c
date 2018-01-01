//===================================================================
//  $Workfile: ext_adc.c $
//  $Modtime: 8-03-01 14:52 $
//  $Revision: 1 $
//  $Author: Noam $
//===================================================================

#include "mb90540.h"
//#include "def.h"
#include "ext_adc.h"

//-------------------------------------------------------------------
// ext_adc_init
// Purpose:
//  Initiate all I/O registers.
// Parameters:
// Returns:
//-------------------------------------------------------------------
void ext_adc_init(void)
{
	//------------------------------------------------------------------
	// all latches to '1'
	//------------------------------------------------------------------
	EXT_ADC_CLK   = 1;
	EXT_ADC_DIN	= 1;
	EXT_ADC_DOUT  = 1;
	EXT_ADC_SARS  = 1;
	EXT_ADC_CS	= 1;
	//------------------------------------------------------------------
	// define lines' direction
	//------------------------------------------------------------------
	EXT_ADC_DIR_CLK	= DIR_OUT;
	EXT_ADC_DIR_DIN	= DIR_OUT;                 // this is the ad_ex's input our output
	EXT_ADC_DIR_DOUT	= DIR_IN;                  // this is the ad_ex's output our input
	EXT_ADC_DIR_SARS	= DIR_IN;
	EXT_ADC_DIR_CS	= DIR_OUT;
	//------------------------------------------------------------------
	// define pullups
	//------------------------------------------------------------------
	EXT_ADC_PULL_CLK	= PULLUP_USE;
	EXT_ADC_PULL_CS		= PULLUP_USE;
	//------------------------------------------------------------------
	// enable ad_ex and power up on channel0
	//------------------------------------------------------------------
	ext_adc_power(EXT_ADC_SINGLE_CH0);             // power down adc
	ext_adc_power(EXT_ADC_SINGLE_CH1);             // power down adc
} // ext_adc_init

//-------------------------------------------------------------------
// ext_adc_power
// Purpose:
//  Outputs to the ad_ex chip the value_out for selecting the channel or power down
//  Maximum Clk 2.5Mhz -> 400ns 
//  Exits with ad_ex clock & cs hi!
// Parameters:
//  selection - the 5 bit value outputed.
// Returns:
//-------------------------------------------------------------------
void ext_adc_power(unsigned char selection)
{
	unsigned char i;
  
	EXT_ADC_CLK   = 1; 				// clk hi
	EXT_ADC_CS    = 0;   			// enable chip
	__wait_nop();         			// wait 62.5 ns

	for(i=0;i<5;i++){     			// output all 5 bits
		EXT_ADC_CLK = 0;        	// clk lo
		if(selection & 0x01){  		// check value
			EXT_ADC_DIN = 1;   		// output bit 1
		}else{
			EXT_ADC_DIN = 0;  		// output bit 0
		}
		__wait_nop();     			// wait 62.5 ns
		__wait_nop();           	// wait 62.5 ns
		EXT_ADC_CLK   = 1;     		// clk hi
		selection >>= 1;       		// next bit
	}// for

	EXT_ADC_CS    = 1;         		// disable chip
} // ext_adc_power

//--------------------------------------------------------------------
// ext_adc_convert
// Purpose:
//  Converts the requested external ADC channel.  
//  Maximum Clk 2.5Mhz -> 400ns 
// Parameters:
//  channel - channel number
// Returns:
//  The value converted.
//--------------------------------------------------------------------
unsigned int ext_adc_convert(unsigned char channel)
{
	unsigned char	i;
	unsigned int	value = 0;
  
	EXT_ADC_CLK   = 1;                             // clk hi
	EXT_ADC_CS    = 0;                             // enable chip
	__wait_nop();                                  // wait 62.5 ns
	//------------------------------------------------------------------
	// output channel select
	//------------------------------------------------------------------
	for (i=0;i<5;i++){                             // output all 5 bits
		EXT_ADC_CLK = 0;                             // clk lo
		if (channel & 0x01){                         // check value
			EXT_ADC_DIN = 1;                           // output bit 1
		}else{
			EXT_ADC_DIN = 0;                        // output bit 0
		}
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		EXT_ADC_CLK   = 1;                           // clk hi
		channel >>= 1;                               // next bit
	}                                              // for
  //------------------------------------------------------------------
  // Sample and hold acquisition time 4.5 clocks
  //------------------------------------------------------------------
	for (i=0;i<4;i++){                             // wait 4 clocks
		EXT_ADC_CLK   = 0;                           // clk lo
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		EXT_ADC_CLK   = 1;                           // clk hi
	}                                              // for
  //------------------------------------------------------------------
  // Conversion time 12 clocks
  //------------------------------------------------------------------
	for (i=0;i<12;i++) {                           // wait 12 clocks
		EXT_ADC_CLK   = 0;                           // clk lo
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		EXT_ADC_CLK   = 1;                           // clk hi
	}  // for
  //------------------------------------------------------------------
  // 1/2 bit 
  //------------------------------------------------------------------   
    EXT_ADC_CLK   = 0;                           // clk lo
	__wait_nop();                                // wait 62.5 ns
	__wait_nop();                                // wait 62.5 ns
	__wait_nop();                                // wait 62.5 ns
	__wait_nop();                                // wait 62.5 ns
	__wait_nop();                                // wait 62.5 ns
  //------------------------------------------------------------------
  // read 10 bits & sign (11) clocks
  //------------------------------------------------------------------
	for (i=0;i<11;i++){                            // read 11 clocks
		EXT_ADC_CLK   = 1;                           // clk hi
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		__wait_nop();                                // wait 62.5 ns
		if (EXT_ADC_DOUT){                           // ad_ex output
			value |= (1<<i);
		}
		EXT_ADC_CLK   = 0;                           // clk lo
	}                                              // for

 	EXT_ADC_CLK   = 1;                             // clk hi
 	EXT_ADC_CS    = 1;                             // disable chip
 	return value;
} // ext_adc_convert


