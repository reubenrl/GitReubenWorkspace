//===================================================================
//  $Workfile: ADC.c $
//  $Modtime: 23-04-01 7:45 $
//  $Revision: 1 $
//  $Author: Noam $
//===================================================================

#include <stdio.h>
#include "mb90540.h"
#include "eclipse_cpu.h"
#include "ADC.h"
#include "ext_adc.h"


static unsigned int adc_chnls_buff[NUM_OF_ADC_CHNL];
volatile unsigned char adc_ptr;

//-------------------------------------------------------------------
// adc_read_ext
// Purpose:
//  Read the external ADC.
// Parameters:
// Returns:
//-------------------------------------------------------------------
void adc_read_ext(void)
{
  // watchdog_cnt = 0;                              // watchdog hit in timer0!
	adc_chnls_buff[8] = ext_adc_convert(EXT_ADC_SINGLE_CH0);
  //watchdog_cnt = 0;                              // watchdog hit in timer0!
	adc_chnls_buff[9] = ext_adc_convert(EXT_ADC_SINGLE_CH1);
  //watchdog_cnt = 0;                              // watchdog hit in timer0!
} // adc_read_ext


//-------------------------------------------------------------------
// irq_adcint
// Purpose:
//  Internal ADC end of conversion interrupt.
// Parameters:
// Returns:
//-------------------------------------------------------------------
__interrupt void irq_adcint(void)
{  
	while (ADCS1_INT == 0);				    			// wait for completion
		
	adc_chnls_buff[adc_ptr] = (ADCR1 & 0x03) << 8;		// built 16 Bit
	// ADCR1 (16 Bit) OR ADCR0 (8 Bit)
	adc_chnls_buff[adc_ptr] =  adc_chnls_buff[adc_ptr] | ADCR0;
	if (adc_ptr==7){                               		// restart after last channel was scanned
		ADCS1 = 0x00;		                       		// software activation , interrupt disable
	}
	adc_ptr++;                                     		// will be 8 when finished
	ADCS1_INT = 0;						           		// clear interrupt flag
} // irq_adcint

//-------------------------------------------------------------------
// adc_read_all
// Purpose:
//  Reads all ADC channels  
// Parameters:
// Returns:
//-------------------------------------------------------------------
void adc_read_all_chnls(void)
{
	adc_ptr = 0;   		// first channel
	ADER  = 0xFF;
	ADCS0 = 07;     	// single mode,start=0 & end =7
	ADCS1 = 0x20;		// software activation , interrupt enable
	ADCR1 = 0x08;    	// 10-Bit resolution, sampl. 64 cycles, comp. 352 cycles
	ADCS1_STRT = 1;   	// start reading ADC
	adc_read_ext();
} // adc_read_all

//-------------------------------------------------------------------
// adc_read1
// Purpose:
//  Reads one ADC channel
// Parameters:
//  channel 0..7 internal 8,9 external
// Returns:
//-------------------------------------------------------------------

void adc_single_chnl(unsigned char channel)
{
	if (channel>=NUM_OF_ADC_CHNL)                   // legal channels only
		return;
	if (channel<NUM_OF_INT_ADC_CHNL){               // internal ADC 0..7
		ADER  = 0xFF;
		ADCS0 = (channel<<3);                         // single mode,start & end same channel
		ADCS0 |= channel;                             // single mode,start & end same channel
		ADCS1 = 0x00;                                 // no interrupt, software activation
		ADCR1 = 0x08;                                 // 10-Bit resolution, sampl. 64 cycles, comp. 352 cycles
		ADCS1_STRT = 1;                               // start reading ADC
		while (ADCS1_INT == 0){			              //  wait for convertion end
			//watchdog_cnt = 0;                       // watchdog hit in timer0!
		}
		adc_chnls_buff[channel] = (ADCR1 & 0x03) << 8; 	// built 16 Bit
		adc_chnls_buff[channel] = adc_chnls_buff[channel] | ADCR0;// ADCR1 (16 Bit) OR ADCR0 (8 Bit)
		ADCS1_INT = 0;					                       // clear convert bit
	}else{                                          // read from the external A2D
		if (channel==8)
			adc_chnls_buff[channel] = ext_adc_convert(EXT_ADC_SINGLE_CH0);
		else
			adc_chnls_buff[channel] = ext_adc_convert(EXT_ADC_SINGLE_CH1);
 }
} // adc_read1

unsigned int *adc_get_chnls_buff(void)
{
	return &adc_chnls_buff[0];
}
