/*
 * pwm.h
 *
 *  Created on: Jan 21, 2015
 *      Author: reuben
 */

#ifndef PWM_H_
#define PWM_H_

#define PWM_PERIOD   	16000000UL/16UL/10000UL	// T = ms => Fq = 10000Hz
// PPGC0
#define 	PEN0	7	// enables PPG (ch0) count operation.
#define 	PE00	5	// PPG0 pin output enable bit
#define		PIE0	4	// PPG (ch0) interrupt
#define 	PUF0 	3	// PPG counter underflow bit

// PPGC1
#define 	PEN1	15	// enables the counter operation of the PPG (ch1)
#define 	PE10	13	// PPG0 pin output enable bit
#define 	PIE1	12	// PPG (ch1) interrupt
#define 	PUF1 	11	// PPG (ch1) counter
#define 	MD1 	10	// Operation mode selection bits
#define 	MD0 	9

// PPG01
#define 	PCS2	7
#define 	PCS1 	6
#define 	PCS0	5
#define 	PCM2	4
#define 	PCM1	3
#define 	PCM0 	2

void pwmInit(void);
void pwmSetDutyCycle(unsigned char pwmCycle);

#endif /* PWM_H_ */
