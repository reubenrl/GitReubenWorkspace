/* FFMC-16 IO-MAP HEADER FILE                                                */
/* ==========================                                                */
/* CREATED BY IO-WIZARD V2.16                                                */
/* Id: mb90540.asm,v 4.3 2003/08/29 13:07:36 dfisch Exp $ */
/* ***********************************************************               */
/*               FUJITSU MIKROELEKTRONIK GMBH                                */
/*               Am Siebenstein 6-10, 63303 Dreieich                         */
/*               Tel.:++49/6103/690-0,Fax - 122                              */
/*                                                                           */
/* The following software is for demonstration purposes only.                */
/* It is not fully tested, nor validated in order to fullfill                */
/* its task under all circumstances. Therefore, this software                */
/* or any part of it must only be used in an evaluation                      */
/* laboratory environment.                                                   */
/* This software is subject to the rules of our standard                     */
/* DISCLAIMER, that is delivered with our SW-tools (on the CD                */
/* "Micros Documentation & Software V3.0" see "\START.HTM" or                */
/* see our Internet Page -                                                   */
/* http://www.fujitsu-ede.com/products/micro/disclaimer.html                 */
/* ***********************************************************               */
/* ----------------------------------------------------------------------    */
/* Id: mb90540.iow,v 4.2 2003/08/29 13:03:36 dfisch Exp                      */
/* ----------------------------------------------------------------------    */
/* History:                                                                  */
/* Date      Version     Author      Description                             */
/* 01-12-98  1.0 initial version                                             */
/*           wtc: bitgroup removed because of same name as byte macro        */
/*                                                                           */
/* 23-01-99  2.0                                                             */
/* 	- CAN includes changed (structures for whole area)                       */
/* 	- SMR0 (mistake) changed to SMR1                                         */
/* 03-02-99  2.1                                                             */
/* 	- LWORD macros and identifier changed to DWORD                           */
/* 	- ICR resource used as include                                           */
/* 	- CAN includes statements splitted (successive statements are ignored with old version) */
/* 14.04.99  2.2	JRO                                                         */
/* 	- generation of header and c file with IO-Wizard V 1.9                   */
/*                                                                           */
/* 29.04.99  2.3	VSA                                                         */
/* 	- bitdefinitions for parallelports are changed to Pxx, Dxx               */
/* 30.04.99  2.4	VSA                                                         */
/* 	- 3903h PRHL1 -> PRLH1                                                   */
/* 	- 3907h PRHL3 -> PRLH3                                                   */
/* 	- 390Bh PRHL5 -> PRLH5                                                   */
/* 	- 390Fh PRHL7 -> PRLH7                                                   */
/* 	- 1FF0h: PADR0 3 (3 byte array)                                          */
/* 	- 1FF3h: PADR1 3 (3 byte array)                                          */
/* 	- PADR2, PADR3, PADR4, PADR5 are deleted                                 */
/* 	- address of SCDCR from 2Ah to 2Bh changed                               */
/* 	- ADCS1 -> ADCS0                                                         */
/* 	- ADCS2 -> ADCS1                                                         */
/* 	- ADCR1 -> ADCR0                                                         */
/* 	- ADCR2 -> ADCR1                                                         */
/* 	- ARSR, HACR, ECSR are deleted                                           */
/* 	- address of OCCP1 are from 3929h to 392Ah changed                       */
/* 	-    -    -  OCCP2  -  from 392Ah to 392Ch    -                          */
/* 	-    -    -  OCCP3  -  from 392Bh to 392Eh    -                          */
/* 07.05.99 2.5    	VSA                                                      */
/* 	- disclaimer added                                                       */
/* 15.07.99 2.6		VSA                                                         */
/* 	- _elvr is changed to elvr                                               */
/* 	- _canlx are changed to canlx                                            */
/* 	- PADRx 3 are renamed to PADRx_L 1, PADRx_M 1, PADRx_H 1                 */
/* 16.08.99 2.7		VSA                                                         */
/* 	- ARSR, HACR, ECSR are inserted                                          */
/* 23.08.99 2.8		VSA                                                         */
/* 	- SMCS bitdefinitions modified                                           */
/* 	- security section added                                                 */
/* 03.07.00 2.9 	VSA                                                         */
/* 	- ADC unit included (adc_01.h)                                           */
/* 27.10.00 3.0         NMP                                                  */
/*              - ADC Macro ammended                                         */
/* 08.11.00 3.1 - Rebuild to remove incorrect comments                       */
/* 16.03.01 3.4                                                              */
/*           - Updated ADC Macro, RESV bit in ADCS1 added                    */
/* 28.03.01 3.5    TKA      Section IOXTND splitted into IOXTND and IOXTND2 because of area in case of external bus used */
/* 23.07.02 3.6    HWe      new adc_01.h, icr.h (RMW-Problem)                */
/* 29.01.03 3.7    HWE      wordaccess to PPGCx/y: PPGC01, .. , PPGC67       */
/* 29.01.03 3.7    HWE      wordaccess to PPG Reload: PRL0, .. , PRL7        */
/* 29.01.03 3.7    HWE      longwordaccess to PPG Reload: PRL01, .. , PRL67  */
/* Id: mb90540.iow,v 4.0 2003/05/07 15:24:00 dfisch Exp                      */
/*      - CVS and make controlled, specific security includefile             */
/* Id: mb90540.iow,v 4.2 2003/08/29 13:03:36 dfisch Exp                      */
/*      - Register ARSR, HACR, ECSR: Bitdefinitions deleted (Write-only)     */
/*      - include security_mb90540.asm                                       */
/* ----------------------------------------------------------------------    */
/* Id: elvr.h,v 2.1 2003/06/27 14:30:51 dfisch Exp                           */
/* ----------------------------------------------------------------------    */
/* External Interrupt Input Level register                                   */
/*                                                                           */
/* This declaration is intended to be included in IO-Wizard source           */
/* files.                                                                    */
/* V0.1 still missing prefix '_'                                             */
/* V1.0 symbol prefix '_' added                                              */
/* V1.2 "extern" changed to pre-defined macro of IO-Wizrad, re-              */
/*      quires IO-Wizard 1.7 or later                                        */
/* Id: elvr.h,v 2.0 2003/05/06 09:03:53 dfisch Exp                           */
/*      - CVS and make controlled                                            */
/* Id: elvr.h,v 2.1 2003/06/27 14:30:51 dfisch Exp                           */
/*      - adapted to BITFIELD_ORDER_MSB                                      */
/* ----------------------------------------------------------------------    */
/* Id: adc_01.h,v 2.2 2003/08/19 09:46:21 dfisch Exp                         */
/* ----------------------------------------------------------------------    */
/* DESCRIPTION:  Interrupt Control Register Declaration                      */
/*                                                                           */
/* AUTHOR:       Fujitsu Mikroelektronik GmbH                                */
/*                                                                           */
/* HISTORY:                                                                  */
/* Version 1.0      03.07.00   : original version                            */
/*         1.1      01.11.00   : Structure alignment                         */
/* Version 1.2      22.07.2002 : HW  ADCS0, ADCR-Bitdefinitions as const, no RMV allowed */
/* Id: adc_01.h,v 2.0 2003/05/06 13:59:57 dfisch Exp                         */
/*      - CVS and make controlled                                            */
/* Id: adc_01.h,v 2.1 2003/06/27 14:30:51 dfisch Exp                         */
/*      - adapted to BITFIELD_ORDER_MSB                                      */
/* Id: adc_01.h,v 2.2 2003/08/19 09:46:21 dfisch Exp                         */
/*      - ADCS1 Bit-defs as const, only Byte-write                           */
/* ----------------------------------------------------------------------    */
/* Id: ICR.H,v 2.1 2003/06/27 14:30:51 dfisch Exp                            */
/* ----------------------------------------------------------------------    */
/*                                                                           */
/* DESCRIPTION:  Interrupt Control Register Declaration                      */
/*                                                                           */
/* AUTHOR:       Fujitsu Mikroelektronik GmbH                                */
/*                                                                           */
/* HISTORY:                                                                  */
/* Version 1.0      26.01.99:                                                */
/*      - original version                                                   */
/* Version 1.2      11.02.99                                                 */
/*      - "extern" changed to pre-defined macro of IO-Wizard                 */
/*        (__IO_EXTERN), requires IO-Wizard 1.7 or later                     */
/*                                                                           */
/* Version 1.3      17.07.2002  HW  Bitdefinitions as const, no RMV allowed  */
/* Id: ICR.H,v 2.0 2003/05/06 09:03:53 dfisch Exp                            */
/*      - CVS and make controlled                                            */
/* Id: ICR.H,v 2.1 2003/06/27 14:30:51 dfisch Exp                            */
/*      - adapted to BITFIELD_ORDER_MSB                                      */
/* ----------------------------------------------------------------------    */
/* Id: CANSTR.H,v 3.1 2003/06/27 14:30:51 dfisch Exp                         */
/* ----------------------------------------------------------------------    */
/* CANIO: control structures of CAN for LX-controllers                       */
/*                                                                           */
/* Version: 1.0            23.01.99     HL                                   */
/*      - original version                                                   */
/* Version: 2.0            26.02.99     HL                                   */
/*      - unsigned int replace by IO_WORD (FR/LX have diff int)              */
/*      - unsigned char replace by IO_BYTE                                   */
/* Version: 2.1            26.08.02     HLo                                  */
/*      - const specifier used for RTEC union                                */
/*      - REC and TEC of RTEC changed from bit group to Byte type            */
/*      - short type addded to DTR register for compatibility                */
/* Id: CANSTR.H,v 3.0 2003/05/06 09:02:30 dfisch Exp                         */
/*      - CVS and make controlled                                            */
/* Id: CANSTR.H,v 3.1 2003/06/27 14:30:51 dfisch Exp                         */
/*      - adapted to BITFIELD_ORDER_MSB                                      */
/* ----------------------------------------------------------------------    */
/* Id: canmac01.h,v 5.0 2003/05/06 09:01:20 dfisch Exp                       */
/* ----------------------------------------------------------------------    */
/* CANIO: control structures for LX-controllers                              */
/*        version 1.0 to 2.2 for double CAN                                  */
/*                                                                           */
/* Version: 1.0            23.01.99     FMG, HLO                             */
/*      - original version                                                   */
/* Version: 1.1            27.01.99     FMG, tka                             */
/*      - idrx0 changed to IDRX0                                             */
/* Version: 1.2            11.02.99     FMG, HLO                             */
/*      - "extern" declaration changed to predefined macros of               */
/*        IO-Wizard, requires IO-Wizard 1.7 or later                         */
/*      - DRT1_LWPTR changed to DTR1_DWPTR macro                             */
/* Version: 2.0            28.05.01     HLO                                  */
/*      - LX-version adopted to FR                                           */
/*      - __IO_EXTENDED changed to __IO_EXTERN, CAN is on external bus       */
/* Version: 2.1            08.06.01     HLO                                  */
/*      - macro for short type in DTR added                                  */
/* Version: 2.2            11.06.01     MEN                                  */
/*      - DLC changed to IO_WORD                                             */
/* Version: 3.0            05.08.02     DF                                   */
/*      - removed CAN1                                                       */
/* Version: 3.1            23.08.02     DF                                   */
/*      - DTR_LWPTR and DTR_DWPTR for compatibility                          */
/* Version: 4.0            23.08.02     HLO                                  */
/*      - changed to batch generation                                        */
/* Id: canmac01.h,v 5.0 2003/05/06 09:01:20 dfisch Exp                       */
/*      - CVS and make controlled                                            */
/* ----------------------------------------------------------------------    */
/* Id: security_mb90540.asm,v 1.1 2003/08/29 13:06:01 dfisch Exp             */
/* ----------------------------------------------------------------------    */
/* Id: security_mb90540.asm,v 1.1 2003/08/29 13:06:01 dfisch Exp             */
/*      - CVS and make controlled                                            */
/*      - new families added                                                 */
/*      - Security DISABLED/ENABLED prepared                                 */
 .PROGRAM MB90540
 .TITLE   MB90540

;------------------------
; IO-AREA DEFINITIONS :
;------------------------



 .section IOBASE, IO, locate=0x0000  ; /*  PORT DATA */
 .GLOBAL __pdr0,     __pdr1,     __pdr2,     __pdr3,     __pdr4,     __pdr5
 .GLOBAL __pdr6,     __pdr7,     __pdr8,     __pdr9,     __pdra,     __ddr0
 .GLOBAL __ddr1,     __ddr2,     __ddr3,     __ddr4,     __ddr5,     __ddr6
 .GLOBAL __ddr7,     __ddr8,     __ddr9,     __ddra,     __ader,     __pucr0
 .GLOBAL __pucr1,    __pucr2,    __pucr3,    __umc0,     __usr0,     __uidr0
 .GLOBAL __uodr0,    __urd0,     __smr1,     __scr1,     __sidr1,    __sodr1
 .GLOBAL __ssr1,     __u1cdcr,   __ses1,     __scdcr,    __smcs,     __sdr
 .GLOBAL __ses2,     __enir,     __eirr,     __elvr,     __adcs,     __adcs0
 .GLOBAL __adcs1,    __adcr,     __adcr0,    __adcr1,    __ppgc01,   __ppgc0
 .GLOBAL __ppgc1,    __ppg01,    __ppgc23,   __ppgc2,    __ppgc3,    __ppg23
 .GLOBAL __ppgc45,   __ppgc4,    __ppgc5,    __ppg45,    __ppgc67,   __ppgc6
 .GLOBAL __ppgc7,    __ppg67,    __ics01,    __ics23,    __ics45,    __ics67
 .GLOBAL __tmcsr0,   __tmr0,     __tmrlr0,   __tmcsr1,   __tmr1,     __tmrlr1
 .GLOBAL __ocs0,     __ocs1,     __ocs2,     __ocs3,     __tcdt,     __tccs
 .GLOBAL __romm,     __canl0,    __canl1,    __pacsr,    __dirr,     __lpmcr
 .GLOBAL __ckscr,    __arsr,     __hacr,     __ecsr,     __wdtc,     __tbtc
 .GLOBAL __wtc,      __fmcs,     __icr

__pdr0   .res.b 1             ;000000  /*  PORT DATA */
PDR0    .equ 0x0000
__pdr1   .res.b 1             ;000001
PDR1    .equ 0x0001
__pdr2   .res.b 1             ;000002
PDR2    .equ 0x0002
__pdr3   .res.b 1             ;000003
PDR3    .equ 0x0003
__pdr4   .res.b 1             ;000004
PDR4    .equ 0x0004
__pdr5   .res.b 1             ;000005
PDR5    .equ 0x0005
__pdr6   .res.b 1             ;000006
PDR6    .equ 0x0006
__pdr7   .res.b 1             ;000007
PDR7    .equ 0x0007
__pdr8   .res.b 1             ;000008
PDR8    .equ 0x0008
__pdr9   .res.b 1             ;000009
PDR9    .equ 0x0009
__pdra   .res.b 1             ;00000A
PDRA    .equ 0x000A
 .org 0x0010
__ddr0   .res.b 1             ;000010  /*  PORT DIRECTION */
DDR0    .equ 0x0010
__ddr1   .res.b 1             ;000011
DDR1    .equ 0x0011
__ddr2   .res.b 1             ;000012
DDR2    .equ 0x0012
__ddr3   .res.b 1             ;000013
DDR3    .equ 0x0013
__ddr4   .res.b 1             ;000014
DDR4    .equ 0x0014
__ddr5   .res.b 1             ;000015
DDR5    .equ 0x0015
__ddr6   .res.b 1             ;000016
DDR6    .equ 0x0016
__ddr7   .res.b 1             ;000017
DDR7    .equ 0x0017
__ddr8   .res.b 1             ;000018
DDR8    .equ 0x0018
__ddr9   .res.b 1             ;000019
DDR9    .equ 0x0019
__ddra   .res.b 1             ;00001A
DDRA    .equ 0x001A
__ader   .res.b 1             ;00001B
ADER    .equ 0x001B
__pucr0   .res.b 1             ;00001C  /*  PULL-UP CONTROL */
PUCR0    .equ 0x001C
__pucr1   .res.b 1             ;00001D
PUCR1    .equ 0x001D
__pucr2   .res.b 1             ;00001E
PUCR2    .equ 0x001E
__pucr3   .res.b 1             ;00001F
PUCR3    .equ 0x001F
__umc0   .res.b 1             ;000020  /*  UART0 */
UMC0    .equ 0x0020
__usr0   .res.b 1             ;000021
USR0    .equ 0x0021
__uidr0   .res.b 1             ;000022
UIDR0    .equ 0x0022
 .org 0x0022
__uodr0   .res.b 1             ;000022
UODR0    .equ 0x0022
__urd0   .res.b 1             ;000023
URD0    .equ 0x0023
__smr1   .res.b 1             ;000024  /*  UART1 SCI with clock selection */
SMR1    .equ 0x0024
__scr1   .res.b 1             ;000025
SCR1    .equ 0x0025
__sidr1   .res.b 1             ;000026
SIDR1    .equ 0x0026
 .org 0x0026
__sodr1   .res.b 1             ;000026
SODR1    .equ 0x0026
__ssr1   .res.b 1             ;000027
SSR1    .equ 0x0027
__u1cdcr   .res.b 1             ;000028
U1CDCR    .equ 0x0028
__ses1   .res.b 1             ;000029
SES1    .equ 0x0029
 .org 0x002B
__scdcr   .res.b 1             ;00002B  /*  SIO with clock selection */
SCDCR    .equ 0x002B
__smcs   .res.b 2             ;00002C
SMCS    .equ 0x002C
__sdr   .res.b 1             ;00002E
SDR    .equ 0x002E
__ses2   .res.b 1             ;00002F
SES2    .equ 0x002F
__enir   .res.b 1             ;000030  /*  DTP, External Interrupts */
ENIR    .equ 0x0030
__eirr   .res.b 1             ;000031
EIRR    .equ 0x0031
__elvr   .res.b 2             ;000032
ELVR    .equ 0x0032
__adcs   .res.b 2             ;000034  /* AD Converter */
ADCS    .equ 0x0034
 .org 0x0034
__adcs0   .res.b 1             ;000034
ADCS0    .equ 0x0034
__adcs1   .res.b 1             ;000035
ADCS1    .equ 0x0035
__adcr   .res.b 2             ;000036
ADCR    .equ 0x0036
 .org 0x0036
__adcr0   .res.b 1             ;000036
ADCR0    .equ 0x0036
__adcr1   .res.b 1             ;000037
ADCR1    .equ 0x0037
__ppgc01   .res.b 2             ;000038  /*  PPG control */
PPGC01    .equ 0x0038
 .org 0x0038
__ppgc0   .res.b 1             ;000038
PPGC0    .equ 0x0038
__ppgc1   .res.b 1             ;000039
PPGC1    .equ 0x0039
__ppg01   .res.b 1             ;00003A
PPG01    .equ 0x003A
 .org 0x003C
__ppgc23   .res.b 2             ;00003C
PPGC23    .equ 0x003C
 .org 0x003C
__ppgc2   .res.b 1             ;00003C
PPGC2    .equ 0x003C
__ppgc3   .res.b 1             ;00003D
PPGC3    .equ 0x003D
__ppg23   .res.b 1             ;00003E
PPG23    .equ 0x003E
 .org 0x0040
__ppgc45   .res.b 2             ;000040
PPGC45    .equ 0x0040
 .org 0x0040
__ppgc4   .res.b 1             ;000040
PPGC4    .equ 0x0040
__ppgc5   .res.b 1             ;000041
PPGC5    .equ 0x0041
__ppg45   .res.b 1             ;000042
PPG45    .equ 0x0042
 .org 0x0044
__ppgc67   .res.b 2             ;000044
PPGC67    .equ 0x0044
 .org 0x0044
__ppgc6   .res.b 1             ;000044
PPGC6    .equ 0x0044
__ppgc7   .res.b 1             ;000045
PPGC7    .equ 0x0045
__ppg67   .res.b 1             ;000046
PPG67    .equ 0x0046
 .org 0x004C
__ics01   .res.b 1             ;00004C
ICS01    .equ 0x004C
__ics23   .res.b 1             ;00004D
ICS23    .equ 0x004D
__ics45   .res.b 1             ;00004E
ICS45    .equ 0x004E
__ics67   .res.b 1             ;00004F
ICS67    .equ 0x004F
__tmcsr0   .res.b 2             ;000050
TMCSR0    .equ 0x0050
__tmr0   .res.b 2             ;000052
TMR0    .equ 0x0052
 .org 0x0052
__tmrlr0   .res.b 2             ;000052
TMRLR0    .equ 0x0052
__tmcsr1   .res.b 2             ;000054
TMCSR1    .equ 0x0054
__tmr1   .res.b 2             ;000056
TMR1    .equ 0x0056
 .org 0x0056
__tmrlr1   .res.b 2             ;000056
TMRLR1    .equ 0x0056
__ocs0   .res.b 1             ;000058  /*  Output compare */
OCS0    .equ 0x0058
__ocs1   .res.b 1             ;000059
OCS1    .equ 0x0059
__ocs2   .res.b 1             ;00005A
OCS2    .equ 0x005A
__ocs3   .res.b 1             ;00005B
OCS3    .equ 0x005B
 .org 0x006C
__tcdt   .res.b 2             ;00006C  /* IO timer */
TCDT    .equ 0x006C
__tccs   .res.b 1             ;00006E
TCCS    .equ 0x006E
__romm   .res.b 1             ;00006F  /*  ROM Mirror */
ROMM    .equ 0x006F
__canl0   .res.b 0x10          ;000070  /*  CAN status/control 0, lower part */
CANL0    .equ 0x0070
__canl1   .res.b 0x10          ;000080  /*  CAN status/control 1, lower part */
CANL1    .equ 0x0080
 .org 0x009E
__pacsr   .res.b 1             ;00009E  /*  ROM Correction */
PACSR    .equ 0x009E
__dirr   .res.b 1             ;00009F
DIRR    .equ 0x009F
__lpmcr   .res.b 1             ;0000A0
LPMCR    .equ 0x00A0
__ckscr   .res.b 1             ;0000A1
CKSCR    .equ 0x00A1
 .org 0x00A5
__arsr   .res.b 1             ;0000A5  /* External Bus I/F */
ARSR    .equ 0x00A5
__hacr   .res.b 1             ;0000A6
HACR    .equ 0x00A6
__ecsr   .res.b 1             ;0000A7
ECSR    .equ 0x00A7
__wdtc   .res.b 1             ;0000A8
WDTC    .equ 0x00A8
__tbtc   .res.b 1             ;0000A9
TBTC    .equ 0x00A9
__wtc   .res.b 1             ;0000AA
WTC    .equ 0x00AA
 .org 0x00AE
__fmcs   .res.b 1             ;0000AE  /* Flash Control Register */
FMCS    .equ 0x00AE
 .org 0x00B0
__icr   .res.b 0x10          ;0000B0  /* Interrupt Control Registers */
ICR    .equ 0x00B0

 .section IOXTND, DATA, locate=0x1FF0  ; /* ROM CORRECTION */
 .GLOBAL __padr0_l,  __padr0_m,  __padr0_h,  __padr1_l,  __padr1_m,  __padr1_h

__padr0_l   .res.b 1             ;001FF0  /* ROM CORRECTION */
PADR0_L    .equ 0x1FF0
__padr0_m   .res.b 1             ;001FF1
PADR0_M    .equ 0x1FF1
__padr0_h   .res.b 1             ;001FF2
PADR0_H    .equ 0x1FF2
__padr1_l   .res.b 1             ;001FF3
PADR1_L    .equ 0x1FF3
__padr1_m   .res.b 1             ;001FF4
PADR1_M    .equ 0x1FF4
__padr1_h   .res.b 1             ;001FF5
PADR1_H    .equ 0x1FF5

 .section IOXTND2, DATA, locate=0x3900  ; /*  PPG data */
 .GLOBAL __prl01,    __prl0,     __prll0,    __prlh0,    __prl1,     __prll1
 .GLOBAL __prlh1,    __prl23,    __prl2,     __prll2,    __prlh2,    __prl3
 .GLOBAL __prll3,    __prlh3,    __prl45,    __plr4,     __prll4,    __prlh4
 .GLOBAL __prl5,     __prll5,    __prlh5,    __prl67,    __prl6,     __prll6
 .GLOBAL __prlh6,    __prl7,     __prll7,    __prlh7,    __ipcp0,    __ipcp1
 .GLOBAL __ipcp2,    __ipcp3,    __ipcp4,    __ipcp5,    __ipcp6,    __ipcp7
 .GLOBAL __occp0,    __occp1,    __occp2,    __occp3,    __canm0,    ___dmyc0
 .GLOBAL ___dmyc1,   ___dmyc2,   __canh0,    __canm1,    ___dmyc3,   ___dmyc4
 .GLOBAL ___dmyc5,   __canh1,    ___endio

__prl01   .res.b 4             ;003900  /*  PPG data */
PRL01    .equ 0x3900
 .org 0x3900
__prl0   .res.b 2             ;003900
PRL0    .equ 0x3900
 .org 0x3900
__prll0   .res.b 1             ;003900
PRLL0    .equ 0x3900
__prlh0   .res.b 1             ;003901
PRLH0    .equ 0x3901
__prl1   .res.b 2             ;003902
PRL1    .equ 0x3902
 .org 0x3902
__prll1   .res.b 1             ;003902
PRLL1    .equ 0x3902
__prlh1   .res.b 1             ;003903
PRLH1    .equ 0x3903
__prl23   .res.b 4             ;003904
PRL23    .equ 0x3904
 .org 0x3904
__prl2   .res.b 2             ;003904
PRL2    .equ 0x3904
 .org 0x3904
__prll2   .res.b 1             ;003904
PRLL2    .equ 0x3904
__prlh2   .res.b 1             ;003905
PRLH2    .equ 0x3905
__prl3   .res.b 2             ;003906
PRL3    .equ 0x3906
 .org 0x3906
__prll3   .res.b 1             ;003906
PRLL3    .equ 0x3906
__prlh3   .res.b 1             ;003907
PRLH3    .equ 0x3907
__prl45   .res.b 4             ;003908
PRL45    .equ 0x3908
 .org 0x3908
__plr4   .res.b 2             ;003908
PLR4    .equ 0x3908
 .org 0x3908
__prll4   .res.b 1             ;003908
PRLL4    .equ 0x3908
__prlh4   .res.b 1             ;003909
PRLH4    .equ 0x3909
__prl5   .res.b 2             ;00390A
PRL5    .equ 0x390A
 .org 0x390A
__prll5   .res.b 1             ;00390A
PRLL5    .equ 0x390A
__prlh5   .res.b 1             ;00390B
PRLH5    .equ 0x390B
__prl67   .res.b 4             ;00390C
PRL67    .equ 0x390C
 .org 0x390C
__prl6   .res.b 2             ;00390C
PRL6    .equ 0x390C
 .org 0x390C
__prll6   .res.b 1             ;00390C
PRLL6    .equ 0x390C
__prlh6   .res.b 1             ;00390D
PRLH6    .equ 0x390D
__prl7   .res.b 2             ;00390E
PRL7    .equ 0x390E
 .org 0x390E
__prll7   .res.b 1             ;00390E
PRLL7    .equ 0x390E
__prlh7   .res.b 1             ;00390F
PRLH7    .equ 0x390F
 .org 0x3918
__ipcp0   .res.b 2             ;003918
IPCP0    .equ 0x3918
__ipcp1   .res.b 2             ;00391A
IPCP1    .equ 0x391A
__ipcp2   .res.b 2             ;00391C
IPCP2    .equ 0x391C
__ipcp3   .res.b 2             ;00391E
IPCP3    .equ 0x391E
__ipcp4   .res.b 2             ;003920
IPCP4    .equ 0x3920
__ipcp5   .res.b 2             ;003922
IPCP5    .equ 0x3922
__ipcp6   .res.b 2             ;003924
IPCP6    .equ 0x3924
__ipcp7   .res.b 2             ;003926
IPCP7    .equ 0x3926
__occp0   .res.b 2             ;003928
OCCP0    .equ 0x3928
__occp1   .res.b 2             ;00392A
OCCP1    .equ 0x392A
__occp2   .res.b 2             ;00392C
OCCP2    .equ 0x392C
__occp3   .res.b 2             ;00392E
OCCP3    .equ 0x392E
 .org 0x3A00
__canm0   .res.b 0x40          ;003A00  /*  CAN message buffer 0 */
CANM0    .equ 0x3A00
___dmyc0   .res.b 0x40          ;003A40
_DMYC0    .equ 0x3A40
___dmyc1   .res.b 0x40          ;003A80
_DMYC1    .equ 0x3A80
___dmyc2   .res.b 0x40          ;003AC0
_DMYC2    .equ 0x3AC0
__canh0   .res.b 0x1C          ;003B00  /*  CAN status/control 0, higher part */
CANH0    .equ 0x3B00
 .org 0x3C00
__canm1   .res.b 0x40          ;003C00  /*  CAN message buffer 1 */
CANM1    .equ 0x3C00
___dmyc3   .res.b 0x40          ;003C40
_DMYC3    .equ 0x3C40
___dmyc4   .res.b 0x40          ;003C80
_DMYC4    .equ 0x3C80
___dmyc5   .res.b 0x40          ;003CC0
_DMYC5    .equ 0x3CC0
__canh1   .res.b 0x1C          ;003D00  /*  CAN status/control 1, higher part */
CANH1    .equ 0x3D00
 .org 0x3FFF
___endio   .res.b 1             ;003FFF
_ENDIO    .equ 0x3FFF
; /* include : security_mb90540.asm */

#if defined __CPU_MB90F543__ || __CPU_MB90F543G__ || __CPU_MB90F543GS__
 .section SECURITY, CONST, locate=0xFE0000  ; /*  Security Control Byte */
  .DATA.W 0xFF55 ; Security DISABLED
 ; .DATA.W 0x01FF ; Security ENABLED

#elif defined __CPU_MB90V540__ ||  __CPU_MB90V540G__
 .section SECURITY, CONST, locate=0xFE0000  ; /*  Security Control Byte */
 .RES.W 1
 
#elif defined __CPU_MB90543__ ||  __CPU_MB90543G__ ||  __CPU_MB90543GS__

#else 
 #error *** Please specify CPU-type in Project-setup !!! ***
#endif



 .end
