/* THIS SAMPLE CODE IS PROVIDED AS IS AND IS SUBJECT TO ALTERATIONS. FUJITSU */
/* MICROELECTRONICS ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR */
/* ELIGIBILITY FOR ANY PURPOSES.                                             */
/*                 (C) Fujitsu Microelectronics Europe GmbH                  */
/*------------------------------------------------------------------------
  VECTORS.C
  - Interrupt level (priority) setting
  - Interrupt vector definition

  26.07.99  1.00   HLO    V30L10   original version, no resource assignment
------------------------------------------------------------------------*/


#include "mb90540.h"
#include "eclipse_cpu.h"

/*------------------------------------------------------------------------
   InitIrqLevels()

   This function  pre-sets all interrupt control registers. It can be used
   to set all interrupt priorities in static applications. If this file
   contains assignments to dedicated resources, verify  that the
   appropriate controller is used.

   NOTE: value 7 disables the interrupt and value 0 sets highest priority.
   NOTE: Two resource interrupts always share one ICR register.
*/
void InitIrqLevels(void)
{
/*  ICRxx               shared IRQs for ICR */

    ICR00 = 7;      /*  IRQ11
                        IRQ12 */
    ICR01 = 7;      /*  IRQ13     
                        IRQ14 */
    ICR02 = 7;      /*  IRQ15
                        IRQ16 */
    ICR03 = 5;      /*  IRQ17	-> Timer 0 reload int
                        IRQ18 */
    ICR04 = 7;      /*  IRQ19
                        IRQ20 */
    ICR05 = 0;      /*  IRQ21	-> PWM/PPG01
                        IRQ22 */
    ICR06 = 7;      /*  IRQ23
                        IRQ24 */
    ICR07 = 7;      /*  IRQ25
                        IRQ26 */
    ICR08 = 7;      /*  IRQ27
                        IRQ28 */
    ICR09 = 7;      /*  IRQ29
                        IRQ30 */
    ICR10 = 7;      /*  IRQ31
                        IRQ32 */
    ICR11 = 7;      /*  IRQ33
                        IRQ34 */
    ICR12 = 7;      /*  IRQ35	-> Timer 1 reload int
                        IRQ36 */
    ICR13 = 6;      /*  IRQ37	-> UART0
                        IRQ38 */
    ICR14 = 6;      /*  IRQ39	-> UART1
                        IRQ40 */
    ICR15 = 7;      /*  IRQ41
                        IRQ42 */
}
/*------------------------------------------------------------------------
   Prototypes
   
   Add your own prototypes here. Each vector definition needs is proto-
   type. Either do it here or include a header file containing them.

*/
__interrupt void DefaultIRQHandler (void);

__interrupt void timer0(void);
__interrupt void timer1(void);
__interrupt void irq_adcint(void);
__interrupt void Uart1_Transmit (void);
__interrupt void Uart0_Transmit (void);
__interrupt void Uart0_Receive (void);
__interrupt void Uart1_Receive (void);
__interrupt void pwmIrq(void);

/*------------------------------------------------------------------------
   Vector definiton

   Use following statements to define vectors. All resource related
   vectors are predefined. Remaining software interrupts can be added here
   as well.
   NOTE: If software interrupts 0 to 7 are defined here, this might 
   conflict with the reset vector in the start-up file.
*/

#pragma intvect DefaultIRQHandler  	9    /* software interrupt 9         */
#pragma intvect DefaultIRQHandler 	10    /* exeception handler           */
#pragma intvect DefaultIRQHandler 	11    /* CAN #0 (receive complete)    */
#pragma intvect DefaultIRQHandler 	12    /* CAN #0 (transmission complete
                                               /node status transition) */
#pragma intvect DefaultIRQHandler 	13    /* CAN #1 (receive complete)    */
#pragma intvect DefaultIRQHandler 	14    /* CAN #1 (transmission complete
                                               /node status transition) */
#pragma intvect DefaultIRQHandler 	15    /* external interrupt INT0/INT1 */
#pragma intvect DefaultIRQHandler 	16    /* timebase timer               */
#pragma intvect timer0				17
//#pragma intvect DefaultIRQHandler 17    /* 16-bit reload timer #0       */

//#pragma intvect DefaultIRQHandler 18    /* A/D converter                */
#pragma intvect irq_adcint 		  	18    /* A/D converter                */
#pragma intvect DefaultIRQHandler 	19    /* I/O timer                    */
#pragma intvect DefaultIRQHandler 	20    /* external interrupt INT2/INT3 */
#pragma intvect DefaultIRQHandler 	21    /* serial I/O                   */
#pragma intvect pwmIrq 				22    /* PPG #0/1                     */
//#pragma intvect DefaultIRQHandler 22    /* PPG #0/1                     */
#pragma intvect DefaultIRQHandler 	23    /* input capture CH.0           */
#pragma intvect DefaultIRQHandler 	24    /* external interrupt INT4/INT5 */
#pragma intvect DefaultIRQHandler 	25    /* input capture CH.1           */
#pragma intvect DefaultIRQHandler 	26    /* PPG #2/3                     */
#pragma intvect DefaultIRQHandler 	27    /* external interrupt INT6/INT7 */
#pragma intvect DefaultIRQHandler 	28    /* watch timer                  */
#pragma intvect DefaultIRQHandler 	29    /* PPG #4/5                     */
#pragma intvect DefaultIRQHandler 	30    /* input capture CH.2/3         */
#pragma intvect DefaultIRQHandler 	31    /* PPG #6/7                     */
#pragma intvect DefaultIRQHandler 	32    /* output compare CH.0          */
#pragma intvect DefaultIRQHandler 	33    /* output compare CH.1          */
#pragma intvect DefaultIRQHandler 	34    /* input capture CH.4/5         */
#pragma intvect DefaultIRQHandler 	35    /* output compare CH.2/3 or input capture CH.6/7 */
#pragma intvect timer1 			  	36    /* 16-bit reload timer #1       */
//#pragma intvect DefaultIRQHandler 36    /* 16-bit reload timer #1       */

#pragma intvect Uart0_Receive     	37     /*UART #0 (receive complete)*/
#pragma intvect Uart0_Transmit    	38     /*UART #0 (transmission compl.)*/
#pragma intvect Uart1_Receive     	39     /*UART #1 (receive complete)*/
#pragma intvect Uart1_Transmit    	40     /*UART #1 (transmission compl.)*/

/*
#pragma intvect DefaultIRQHandler 37     UART #0 (receive complete)
#pragma intvect DefaultIRQHandler 38     UART #0 (transmission compl.)
#pragma intvect DefaultIRQHandler 39     UART #1 (receive complete)
#pragma intvect DefaultIRQHandler 40     UART #1 (transmission compl.)

*/

#pragma intvect DefaultIRQHandler 41    /* IRQ41-handler                */
#pragma intvect DefaultIRQHandler 42    /* delayed interrupt            */

/*------------------------------------------------------------------------
   DefaultIRQHandler()

   This function is a place holder for all vector definitions. Either use
   your own place holder or add necessary code here.
*/
__interrupt void DefaultIRQHandler (void)
{
    __DI();                              /* disable interrupts */
  	PDR2 = 0;
    while(1)
    	__wait_nop();                    /* halt system */

}
