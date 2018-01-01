/*
 * pwm.c
 *
 *  Created on: Jan 17, 2015
 *      Author: reuben
 */
#include "mb90540.h"
#include "eclipse_cpu.h"
#include "leds.h"
#include "pwm.h"


//static unsigned int pwmPulseLow;
//static unsigned int pwmPulseHigh;
static unsigned  long pwmTogle;

void pwmSetDutyCycleCounter(unsigned int low, unsigned int high);

void pwmInit(void)
{
	pwmTogle = 0;

	/*
	 * Peripheral clock/16 (1 µs machine clock, 16 MHz)
	 *
	 */
	PPG01 = (1<<PCS2)|(1<<PCM2);

	//PRL01 = RELOAD;
	/*
	 * 16-bit PPG 1-channel mode
	 * Enables the counter operation of the PPG (ch1)
	 */
	PPGC01 = (1<<MD1)|(1<<MD0);
	//PPGC01 = (1<<PEN1)|(1<<PE10)|(1<<MD1)|(1<<MD0)|(1<<PEN0)|(1<<PE00);
	pwmSetDutyCycle(255); // off

	//PPGC01 |= (1<<PIE1)|(1<<PIE0);
//	PRLL0 = 0x7F; PRLH0 = 0xFF;
//	PRLL1 = PRLH1 = 0xFF;
	/*
	* 8-bit PPG 2-channel independent mode
	* Enables PPG (ch0) count operation
	* Enables PPG (ch1)count operation
	* PPG (ch0) interrupt
	* PPG (ch1) interrupt
	*/
	//PPGC01 = (1<<PEN1)|(1<<PIE1)|(1<<PEN0)|(1<<PIE0);
	//PPGC01 = (1<<PEN0)|(1<<PIE0);

	/*
	//  PPG01 (PPG0, 1 clock select register)
	//  PCM2 to 0 (PPG count mode): Count clock selection bit
	PPG01_PCM2 = 0; // Peripheral clock/16 (1-µs machine clock, 16 MHz)
	PPG01_PCS2 = 0;
	// PPGC1 (PPG1 operation mode control register)
	// (PPG count mode): Operation mode selection bit
	// 16-bit PPG 1ch mode.
	PPGC1_MD0 = 1;
	PPGC1_MD1 = 1;
	PPGC1_PIE1 = 1;*/

}

__interrupt void pwmIrq(void)
{
	pwmTogle++;

	if(pwmTogle & 0x800) PDR2_P23 = LED_ON;
	else PDR2_P23 = LED_OFF;

	PPGC01 &= ~((1<<PUF1)|(1<<PUF0));

}

void pwmSetDutyCycleCounter(unsigned int low, unsigned int high)
{
		PPGC01 |= (1<<PEN1)|(1<<PE10)|(1<<PEN0)|(1<<PE00);

		PRL01  = 	(unsigned long)
	        		( ( ((unsigned long)low <<8)   & 0x00FF0000L )
	        		+ ( low                        & 0x000000FFL )
	        		+ ( ((unsigned long)high <<16) & 0xFF000000L )
	        		+ ( (high << 8)                & 0x0000FF00L ) );
}


void pwmSetDutyCycle(unsigned char pwmCycle)
{
	//unsigned long pulseHigh;
	unsigned long pulseLow = ((unsigned long)(PWM_PERIOD*pwmCycle))/255UL;
	unsigned long pulseHigh = PWM_PERIOD - pulseLow ; // pulseLow = 0 to T; T = PWM_PERIOD

	pwmSetDutyCycleCounter((unsigned int)pulseLow, (unsigned int)pulseHigh);
}
