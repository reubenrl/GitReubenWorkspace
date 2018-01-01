/*
 * timer0.h
 *
 *  Created on: Jun 9, 2014
 *      Author: reuben
 */

#ifndef TIMER0_H_
#define TIMER0_H_

void timer0_init(void);
unsigned long get_tmr0_tick_msec(void);
void set_tmr0_tick_msec(unsigned long tick2set);
unsigned long get_tmr0_tick_sec(void);
void set_tmr0_tick_sec(unsigned long tick2set);;
void msec_delay(unsigned int msec);
void sec_delay(unsigned int sec);

unsigned char getCounterEvery30sec(void);





#endif /* TIMER0_H_ */
