/**  ----------------------------------------------------------
**  $Workfile: ADC.h $
**  $Modtime: 17-04-01 12:14 $
**  $Revision: 1 $
**  $Author: Noam $
**  -----------------------------------------------------------
*/
#ifndef ADC_H
#define ADC_H

#define NUM_OF_INT_ADC_CHNL		8
#define NUM_OF_ADC_CHNL 		NUM_OF_INT_ADC_CHNL + 2

#define INT_ADC_SINGLE_CH1		1
#define INT_ADC_SINGLE_CH2		2
#define INT_ADC_SINGLE_CH3		3
#define INT_ADC_SINGLE_CH4		4
#define INT_ADC_SINGLE_CH5		5
#define INT_ADC_SINGLE_CH6		6
#define INT_ADC_SINGLE_CH7		7
#define INT_ADC_SINGLE_CH8		8

//-------------------------------------------------------------------
// Prototypes
//-------------------------------------------------------------------
void adc_single_chnl(unsigned char channel);
void adc_read_all_chnls(void);
unsigned int *adc_get_chnls_buff(void);


#endif
