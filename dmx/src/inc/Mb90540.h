/* FFMC-16 IO-MAP HEADER FILE                                                */
/* ==========================                                                */
/* SOFTUNE WORKBENCH FORMAT                                                  */
/* C-DEFINITIONS FOR IO-SYMBOLS                                              */
/* CREATED BY IO-WIZARD V2.16                                                */
/* Id: mb90540.h,v 4.3 2003/08/29 13:07:36 dfisch Exp $ */
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


#ifndef   __MB90XXX_H
#  define __MB90XXX_H
/*
- Please define __IO_NEAR in LARGE and COMPACT memory model, if the default
  data bank (DTB) is 00. This will result in better performance in these
  models.
- Please define __IO_FAR in SMALL and MEDIUM memory model, if the default
  data bank (DTB) is other than 00. This might be the case in systems with
  external RAM, which are not using internal RAM as default data area.
- Please define neither __IO_NEAR nor __IO_FAR in all other cases. This
  will work with almost all configurations.
*/

#  ifdef  __IO_NEAR
#    ifdef  __IO_FAR
#      error __IO_NEAR and __IO_FAR must not be defined at the same time
#    else
#      define ___IOWIDTH __near
#    endif
#  else
#    ifdef __IO_FAR
#      define ___IOWIDTH __far
#    else                               /* specified by memory model */
#      define ___IOWIDTH
#    endif
#  endif
#  ifdef  __IO_DEFINE
#    define __IO_EXTERN
#    define __IO_EXTENDED volatile ___IOWIDTH
#  else
#    define __IO_EXTERN   extern      /* for data, which can have __io */
#    define __IO_EXTENDED extern volatile ___IOWIDTH
#  endif

typedef unsigned char		IO_BYTE;
typedef unsigned short		IO_WORD;
typedef unsigned long		IO_LWORD;
typedef const unsigned short	IO_WORD_READ;

/* REGISTER BIT STRUCTURES */

typedef union{   /*  PORT DATA */
    IO_BYTE	byte;
    struct{
    	IO_BYTE _P00 :1;
    	IO_BYTE _P01 :1;
    	IO_BYTE _P02 :1;
    	IO_BYTE _P03 :1;
    	IO_BYTE _P04 :1;
    	IO_BYTE _P05 :1;
    	IO_BYTE _P06 :1;
    	IO_BYTE _P07 :1;
    }bit;
 }PDR0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P10 :1;
    IO_BYTE _P11 :1;
    IO_BYTE _P12 :1;
    IO_BYTE _P13 :1;
    IO_BYTE _P14 :1;
    IO_BYTE _P15 :1;
    IO_BYTE _P16 :1;
    IO_BYTE _P17 :1;
  }bit;
 }PDR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P20 :1;
    IO_BYTE _P21 :1;
    IO_BYTE _P22 :1;
    IO_BYTE _P23 :1;
    IO_BYTE _P24 :1;
    IO_BYTE _P25 :1;
    IO_BYTE _P26 :1;
    IO_BYTE _P27 :1;
  }bit;
 }PDR2STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P30 :1;
    IO_BYTE _P31 :1;
    IO_BYTE _P32 :1;
    IO_BYTE _P33 :1;
    IO_BYTE _P34 :1;
    IO_BYTE _P35 :1;
    IO_BYTE _P36 :1;
    IO_BYTE _P37 :1;
  }bit;
 }PDR3STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P40 :1;
    IO_BYTE _P41 :1;
    IO_BYTE _P42 :1;
    IO_BYTE _P43 :1;
    IO_BYTE _P44 :1;
    IO_BYTE _P45 :1;
    IO_BYTE _P46 :1;
    IO_BYTE _P47 :1;
  }bit;
 }PDR4STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P50 :1;
    IO_BYTE _P51 :1;
    IO_BYTE _P52 :1;
    IO_BYTE _P53 :1;
    IO_BYTE _P54 :1;
    IO_BYTE _P55 :1;
    IO_BYTE _P56 :1;
    IO_BYTE _P57 :1;
  }bit;
 }PDR5STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P60 :1;
    IO_BYTE _P61 :1;
    IO_BYTE _P62 :1;
    IO_BYTE _P63 :1;
    IO_BYTE _P64 :1;
    IO_BYTE _P65 :1;
    IO_BYTE _P66 :1;
    IO_BYTE _P67 :1;
  }bit;
 }PDR6STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P70 :1;
    IO_BYTE _P71 :1;
    IO_BYTE _P72 :1;
    IO_BYTE _P73 :1;
    IO_BYTE _P74 :1;
    IO_BYTE _P75 :1;
    IO_BYTE _P76 :1;
    IO_BYTE _P77 :1;
  }bit;
 }PDR7STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P80 :1;
    IO_BYTE _P81 :1;
    IO_BYTE _P82 :1;
    IO_BYTE _P83 :1;
    IO_BYTE _P84 :1;
    IO_BYTE _P85 :1;
    IO_BYTE _P86 :1;
    IO_BYTE _P87 :1;
  }bit;
 }PDR8STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _P90 :1;
    IO_BYTE _P91 :1;
    IO_BYTE _P92 :1;
    IO_BYTE _P93 :1;
    IO_BYTE _P94 :1;
    IO_BYTE _P95 :1;
    IO_BYTE _P96 :1;
    IO_BYTE _P97 :1;
  }bit;
 }PDR9STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _PA0 :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
 }PDRASTR;
typedef union{   /*  PORT DIRECTION */
    IO_BYTE	byte;
    struct{
    IO_BYTE _D00 :1;
    IO_BYTE _D01 :1;
    IO_BYTE _D02 :1;
    IO_BYTE _D03 :1;
    IO_BYTE _D04 :1;
    IO_BYTE _D05 :1;
    IO_BYTE _D06 :1;
    IO_BYTE _D07 :1;
  }bit;
 }DDR0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D10 :1;
    IO_BYTE _D11 :1;
    IO_BYTE _D12 :1;
    IO_BYTE _D13 :1;
    IO_BYTE _D14 :1;
    IO_BYTE _D15 :1;
    IO_BYTE _D16 :1;
    IO_BYTE _D17 :1;
  }bit;
 }DDR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D20 :1;
    IO_BYTE _D21 :1;
    IO_BYTE _D22 :1;
    IO_BYTE _D23 :1;
    IO_BYTE _D24 :1;
    IO_BYTE _D25 :1;
    IO_BYTE _D26 :1;
    IO_BYTE _D27 :1;
  }bit;
 }DDR2STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D30 :1;
    IO_BYTE _D31 :1;
    IO_BYTE _D32 :1;
    IO_BYTE _D33 :1;
    IO_BYTE _D34 :1;
    IO_BYTE _D35 :1;
    IO_BYTE _D36 :1;
    IO_BYTE _D37 :1;
  }bit;
 }DDR3STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D40 :1;
    IO_BYTE _D41 :1;
    IO_BYTE _D42 :1;
    IO_BYTE _D43 :1;
    IO_BYTE _D44 :1;
    IO_BYTE _D45 :1;
    IO_BYTE _D46 :1;
    IO_BYTE _D47 :1;
  }bit;
 }DDR4STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D50 :1;
    IO_BYTE _D51 :1;
    IO_BYTE _D52 :1;
    IO_BYTE _D53 :1;
    IO_BYTE _D54 :1;
    IO_BYTE _D55 :1;
    IO_BYTE _D56 :1;
    IO_BYTE _D57 :1;
  }bit;
 }DDR5STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D60 :1;
    IO_BYTE _D61 :1;
    IO_BYTE _D62 :1;
    IO_BYTE _D63 :1;
    IO_BYTE _D64 :1;
    IO_BYTE _D65 :1;
    IO_BYTE _D66 :1;
    IO_BYTE _D67 :1;
  }bit;
 }DDR6STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D70 :1;
    IO_BYTE _D71 :1;
    IO_BYTE _D72 :1;
    IO_BYTE _D73 :1;
    IO_BYTE _D74 :1;
    IO_BYTE _D75 :1;
    IO_BYTE _D76 :1;
    IO_BYTE _D77 :1;
  }bit;
 }DDR7STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D80 :1;
    IO_BYTE _D81 :1;
    IO_BYTE _D82 :1;
    IO_BYTE _D83 :1;
    IO_BYTE _D84 :1;
    IO_BYTE _D85 :1;
    IO_BYTE _D86 :1;
    IO_BYTE _D87 :1;
  }bit;
 }DDR8STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D90 :1;
    IO_BYTE _D91 :1;
    IO_BYTE _D92 :1;
    IO_BYTE _D93 :1;
    IO_BYTE _D94 :1;
    IO_BYTE _D95 :1;
    IO_BYTE _D96 :1;
    IO_BYTE _D97 :1;
  }bit;
 }DDR9STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _DA0 :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
 }DDRASTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _ADE0 :1;
    IO_BYTE _ADE1 :1;
    IO_BYTE _ADE2 :1;
    IO_BYTE _ADE3 :1;
    IO_BYTE _ADE4 :1;
    IO_BYTE _ADE5 :1;
    IO_BYTE _ADE6 :1;
    IO_BYTE _ADE7 :1;
  }bit;
 }ADERSTR;
typedef union{   /*  PULL-UP CONTROL */
    IO_BYTE	byte;
    struct{
    IO_BYTE _PU00 :1;
    IO_BYTE _PU01 :1;
    IO_BYTE _PU02 :1;
    IO_BYTE _PU03 :1;
    IO_BYTE _PU04 :1;
    IO_BYTE _PU05 :1;
    IO_BYTE _PU06 :1;
    IO_BYTE _PU07 :1;
  }bit;
 }PUCR0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _PU10 :1;
    IO_BYTE _PU11 :1;
    IO_BYTE _PU12 :1;
    IO_BYTE _PU13 :1;
    IO_BYTE _PU14 :1;
    IO_BYTE _PU15 :1;
    IO_BYTE _PU16 :1;
    IO_BYTE _PU17 :1;
  }bit;
 }PUCR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _PU20 :1;
    IO_BYTE _PU21 :1;
    IO_BYTE _PU22 :1;
    IO_BYTE _PU23 :1;
    IO_BYTE _PU24 :1;
    IO_BYTE _PU25 :1;
    IO_BYTE _PU26 :1;
    IO_BYTE _PU27 :1;
  }bit;
 }PUCR2STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _PU30 :1;
    IO_BYTE _PU31 :1;
    IO_BYTE _PU32 :1;
    IO_BYTE _PU33 :1;
    IO_BYTE _PU34 :1;
    IO_BYTE _PU35 :1;
    IO_BYTE _PU36 :1;
    IO_BYTE _PU37 :1;
  }bit;
 }PUCR3STR;
typedef union{   /*  UART0 */
    IO_BYTE	byte;
    struct{
    IO_BYTE _SOE :1;
    IO_BYTE _SCKE :1;
    IO_BYTE _RFC :1;
    IO_BYTE _SMDE :1;
    IO_BYTE _MC0 :1;
    IO_BYTE _MC1 :1;
    IO_BYTE _SBL :1;
    IO_BYTE _PEN :1;
  }bit;
 }UMC0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _TBF :1;
    IO_BYTE _RBF :1;
    IO_BYTE _TIE :1;
    IO_BYTE _RIE :1;
    IO_BYTE _TDRE :1;
    IO_BYTE _PE :1;
    IO_BYTE _ORFE :1;
    IO_BYTE _RDRF :1;
  }bit;
 }USR0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D0 :1;
    IO_BYTE _D1 :1;
    IO_BYTE _D2 :1;
    IO_BYTE _D3 :1;
    IO_BYTE _D4 :1;
    IO_BYTE _D5 :1;
    IO_BYTE _D6 :1;
    IO_BYTE _D7 :1;
  }bit;
 }UIDR0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D0 :1;
    IO_BYTE _D1 :1;
    IO_BYTE _D2 :1;
    IO_BYTE _D3 :1;
    IO_BYTE _D4 :1;
    IO_BYTE _D5 :1;
    IO_BYTE _D6 :1;
    IO_BYTE _D7 :1;
  }bit;
 }UODR0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D8 :1;
    IO_BYTE _P :1;
    IO_BYTE _BCH0 :1;
    IO_BYTE _RC0 :1;
    IO_BYTE _RC1 :1;
    IO_BYTE _RC2 :1;
    IO_BYTE _RC3 :1;
    IO_BYTE _BCH :1;
  }bit;
 }URD0STR;
typedef union{   /*  UART1 SCI with clock selection */
    IO_BYTE	byte;
    struct{
    IO_BYTE _SOE :1;
    IO_BYTE _SCKE :1;
    IO_BYTE  :1;
    IO_BYTE _CS0 :1;
    IO_BYTE _CS1 :1;
    IO_BYTE _CS2 :1;
    IO_BYTE _MD0 :1;
    IO_BYTE _MD1 :1;
  }bit;
  struct{
    IO_BYTE :3;
    IO_BYTE _CS :3;
    IO_BYTE _MD :2;
  }bitc;
 }SMR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _TXE :1;
    IO_BYTE _RXE :1;
    IO_BYTE _REC :1;
    IO_BYTE _AD :1;
    IO_BYTE _CL :1;
    IO_BYTE _SBL :1;
    IO_BYTE _P :1;
    IO_BYTE _PEN :1;
  }bit;
 }SCR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D0 :1;
    IO_BYTE _D1 :1;
    IO_BYTE _D2 :1;
    IO_BYTE _D3 :1;
    IO_BYTE _D4 :1;
    IO_BYTE _D5 :1;
    IO_BYTE _D6 :1;
    IO_BYTE _D7 :1;
  }bit;
 }SIDR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D0 :1;
    IO_BYTE _D1 :1;
    IO_BYTE _D2 :1;
    IO_BYTE _D3 :1;
    IO_BYTE _D4 :1;
    IO_BYTE _D5 :1;
    IO_BYTE _D6 :1;
    IO_BYTE _D7 :1;
  }bit;
 }SODR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _TIE :1;
    IO_BYTE _RIE :1;
    IO_BYTE  :1;
    IO_BYTE _TDRE :1;
    IO_BYTE _RDRF :1;
    IO_BYTE _FRE :1;
    IO_BYTE _ORE :1;
    IO_BYTE _PE :1;
  }bit;
 }SSR1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _DIV0 :1;
    IO_BYTE _DIV1 :1;
    IO_BYTE _DIV2 :1;
    IO_BYTE _DIV3 :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _MD :1;
  }bit;
  struct{
    IO_BYTE _DIV :4;
  }bitc;
 }U1CDCRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _NEG :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
 }SES1STR;
typedef union{   /*  SIO with clock selection */
    IO_BYTE	byte;
    struct{
    IO_BYTE _DIV0 :1;
    IO_BYTE _DIV1 :1;
    IO_BYTE _DIV2 :1;
    IO_BYTE _DIV3 :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _MD :1;
  }bit;
  struct{
    IO_BYTE _DIV :4;
  }bitc;
 }SCDCRSTR;
typedef union{  
    IO_WORD	word;
    struct{
    IO_WORD _SCOE :1;
    IO_WORD _SOE :1;
    IO_WORD _BDS :1;
    IO_WORD _MODE :1;
    IO_WORD  :1;
    IO_WORD  :1;
    IO_WORD  :1;
    IO_WORD  :1;
    IO_WORD _STRT :1;
    IO_WORD _STOP :1;
    IO_WORD _BUSY :1;
    IO_WORD _SIR :1;
    IO_WORD _SIE :1;
    IO_WORD _SMD0 :1;
    IO_WORD _SMD1 :1;
    IO_WORD _SMD2 :1;
  }bit;
  struct{
    IO_WORD :13;
    IO_WORD _SMD :3;
  }bitc;
 }SMCSSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _D0 :1;
    IO_BYTE _D1 :1;
    IO_BYTE _D2 :1;
    IO_BYTE _D3 :1;
    IO_BYTE _D4 :1;
    IO_BYTE _D5 :1;
    IO_BYTE _D6 :1;
    IO_BYTE _D7 :1;
  }bit;
 }SDRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _NEG :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
 }SES2STR;
typedef union{   /*  DTP, External Interrupts */
    IO_BYTE	byte;
    struct{
    IO_BYTE _EN0 :1;
    IO_BYTE _EN1 :1;
    IO_BYTE _EN2 :1;
    IO_BYTE _EN3 :1;
    IO_BYTE _EN4 :1;
    IO_BYTE _EN5 :1;
    IO_BYTE _EN6 :1;
    IO_BYTE _EN7 :1;
  }bit;
 }ENIRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _ER0 :1;
    IO_BYTE _ER1 :1;
    IO_BYTE _ER2 :1;
    IO_BYTE _ER3 :1;
    IO_BYTE _ER4 :1;
    IO_BYTE _ER5 :1;
    IO_BYTE _ER6 :1;
    IO_BYTE _ER7 :1;
  }bit;
 }EIRRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PUF0 :1;
    IO_BYTE _PIE0 :1;
    IO_BYTE _PE00 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN0 :1;
  }bit;
 }PPGC0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE _MD0 :1;
    IO_BYTE _MD1 :1;
    IO_BYTE _PUF1 :1;
    IO_BYTE _PIE1 :1;
    IO_BYTE _PE10 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN1 :1;
  }bit;
  struct{
    IO_BYTE :1;
    IO_BYTE _MD :2;
  }bitc;
 }PPGC1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PCM0 :1;
    IO_BYTE _PCM1 :1;
    IO_BYTE _PCM2 :1;
    IO_BYTE _PCS0 :1;
    IO_BYTE _PCS1 :1;
    IO_BYTE _PCS2 :1;
  }bit;
  struct{
    IO_BYTE :2;
    IO_BYTE _PCM :3;
    IO_BYTE _PCS :3;
  }bitc;
 }PPG01STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PUF2 :1;
    IO_BYTE _PIE2 :1;
    IO_BYTE _PE20 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN2 :1;
  }bit;
 }PPGC2STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE _MD0 :1;
    IO_BYTE _MD1 :1;
    IO_BYTE _PUF3 :1;
    IO_BYTE _PIE3 :1;
    IO_BYTE _PE30 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN3 :1;
  }bit;
  struct{
    IO_BYTE :1;
    IO_BYTE _MD :2;
  }bitc;
 }PPGC3STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PCM0 :1;
    IO_BYTE _PCM1 :1;
    IO_BYTE _PCM2 :1;
    IO_BYTE _PCS0 :1;
    IO_BYTE _PCS1 :1;
    IO_BYTE _PCS2 :1;
  }bit;
  struct{
    IO_BYTE :2;
    IO_BYTE _PCM :3;
    IO_BYTE _PCS :3;
  }bitc;
 }PPG23STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PUF4 :1;
    IO_BYTE _PIE4 :1;
    IO_BYTE _PE40 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN4 :1;
  }bit;
 }PPGC4STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE _MD0 :1;
    IO_BYTE _MD1 :1;
    IO_BYTE _PUF5 :1;
    IO_BYTE _PIE5 :1;
    IO_BYTE _PE50 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN5 :1;
  }bit;
  struct{
    IO_BYTE :1;
    IO_BYTE _MD :2;
  }bitc;
 }PPGC5STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PCM0 :1;
    IO_BYTE _PCM1 :1;
    IO_BYTE _PCM2 :1;
    IO_BYTE _PCS0 :1;
    IO_BYTE _PCS1 :1;
    IO_BYTE _PCS2 :1;
  }bit;
  struct{
    IO_BYTE :2;
    IO_BYTE _PCM :3;
    IO_BYTE _PCS :3;
  }bitc;
 }PPG45STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PUF6 :1;
    IO_BYTE _PIE6 :1;
    IO_BYTE _PE60 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN6 :1;
  }bit;
 }PPGC6STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE _MD0 :1;
    IO_BYTE _MD1 :1;
    IO_BYTE _PUF7 :1;
    IO_BYTE _PIE7 :1;
    IO_BYTE _PE70 :1;
    IO_BYTE  :1;
    IO_BYTE _PEN7 :1;
  }bit;
  struct{
    IO_BYTE :1;
    IO_BYTE _MD :2;
  }bitc;
 }PPGC7STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _PCM0 :1;
    IO_BYTE _PCM1 :1;
    IO_BYTE _PCM2 :1;
    IO_BYTE _PCS0 :1;
    IO_BYTE _PCS1 :1;
    IO_BYTE _PCS2 :1;
  }bit;
  struct{
    IO_BYTE :2;
    IO_BYTE _PCM :3;
    IO_BYTE _PCS :3;
  }bitc;
 }PPG67STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _EG00 :1;
    IO_BYTE _EG01 :1;
    IO_BYTE _EG10 :1;
    IO_BYTE _EG11 :1;
    IO_BYTE _ICE0 :1;
    IO_BYTE _ICE1 :1;
    IO_BYTE _ICP0 :1;
    IO_BYTE _ICP1 :1;
  }bit;
  struct{
    IO_BYTE _EG0 :2;
    IO_BYTE _EG1 :2;
  }bitc;
 }ICS01STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _EG20 :1;
    IO_BYTE _EG21 :1;
    IO_BYTE _EG30 :1;
    IO_BYTE _EG31 :1;
    IO_BYTE _ICE2 :1;
    IO_BYTE _ICE3 :1;
    IO_BYTE _ICP2 :1;
    IO_BYTE _ICP3 :1;
  }bit;
  struct{
    IO_BYTE _EG2 :2;
    IO_BYTE _EG3 :2;
  }bitc;
 }ICS23STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _EG40 :1;
    IO_BYTE _EG41 :1;
    IO_BYTE _EG50 :1;
    IO_BYTE _EG51 :1;
    IO_BYTE _ICE4 :1;
    IO_BYTE _ICE5 :1;
    IO_BYTE _ICP4 :1;
    IO_BYTE _ICP5 :1;
  }bit;
  struct{
    IO_BYTE _EG4 :2;
    IO_BYTE _EG5 :2;
  }bitc;
 }ICS45STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _EG60 :1;
    IO_BYTE _EG61 :1;
    IO_BYTE _EG70 :1;
    IO_BYTE _EG71 :1;
    IO_BYTE _ICE6 :1;
    IO_BYTE _ICE7 :1;
    IO_BYTE _ICP6 :1;
    IO_BYTE _ICP7 :1;
  }bit;
  struct{
    IO_BYTE _EG6 :2;
    IO_BYTE _EG7 :2;
  }bitc;
 }ICS67STR;
typedef union{  
    IO_WORD	word;
    struct{
    IO_WORD _TRG :1;
    IO_WORD _CNTE :1;
    IO_WORD _UF :1;
    IO_WORD _INTE :1;
    IO_WORD _RELD :1;
    IO_WORD _OUTL :1;
    IO_WORD _OUTE :1;
    IO_WORD _MOD0 :1;
    IO_WORD _MOD1 :1;
    IO_WORD _MOD2 :1;
    IO_WORD _CSL0 :1;
    IO_WORD _CSL1 :1;
    IO_WORD  :1;
    IO_WORD  :1;
    IO_WORD  :1;
    IO_WORD  :1;
  }bit;
  struct{
    IO_WORD :7;
    IO_WORD _MOD :3;
    IO_WORD _CSL :2;
  }bitc;
 }TMCSR0STR;
typedef union{  
    IO_WORD	word;
    struct{
    IO_WORD _TRG :1;
    IO_WORD _CNTE :1;
    IO_WORD _UF :1;
    IO_WORD _INTE :1;
    IO_WORD _RELD :1;
    IO_WORD _OUTL :1;
    IO_WORD _OUTE :1;
    IO_WORD _MOD0 :1;
    IO_WORD _MOD1 :1;
    IO_WORD _MOD2 :1;
    IO_WORD _CSL0 :1;
    IO_WORD _CSL1 :1;
    IO_WORD  :1;
    IO_WORD  :1;
    IO_WORD  :1;
    IO_WORD  :1;
  }bit;
  struct{
    IO_WORD :7;
    IO_WORD _MOD :3;
    IO_WORD _CSL :2;
  }bitc;
 }TMCSR1STR;
typedef union{   /*  Output compare */
    IO_BYTE	byte;
    struct{
    IO_BYTE _CST0 :1;
    IO_BYTE _CST1 :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _ICE0 :1;
    IO_BYTE _ICE1 :1;
    IO_BYTE _ICP0 :1;
    IO_BYTE _ICP1 :1;
  }bit;
  struct{
    IO_BYTE _CST :2;
    IO_BYTE :2;
    IO_BYTE _ICE :2;
    IO_BYTE _ICP :2;
  }bitc;
 }OCS0STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _OTD0 :1;
    IO_BYTE _OTD1 :1;
    IO_BYTE _OTE0 :1;
    IO_BYTE _OTE1 :1;
    IO_BYTE _CMOD :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
  struct{
    IO_BYTE _OTD :2;
    IO_BYTE _OTE :2;
  }bitc;
 }OCS1STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _CST0 :1;
    IO_BYTE _CST1 :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE _ICE0 :1;
    IO_BYTE _ICE1 :1;
    IO_BYTE _ICP0 :1;
    IO_BYTE _ICP1 :1;
  }bit;
  struct{
    IO_BYTE _CST :2;
    IO_BYTE :2;
    IO_BYTE _ICE :2;
    IO_BYTE _ICP :2;
  }bitc;
 }OCS2STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _OTD0 :1;
    IO_BYTE _OTD1 :1;
    IO_BYTE _OTE0 :1;
    IO_BYTE _OTE1 :1;
    IO_BYTE _CMOD :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
  struct{
    IO_BYTE _OTD :2;
    IO_BYTE _OTE :2;
  }bitc;
 }OCS3STR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _CLK0 :1;
    IO_BYTE _CLK1 :1;
    IO_BYTE _CLR :1;
    IO_BYTE _MODE :1;
    IO_BYTE _STOP :1;
    IO_BYTE _IVFE :1;
    IO_BYTE _IVF :1;
    IO_BYTE  :1;
  }bit;
  struct{
    IO_BYTE _CLK :2;
  }bitc;
 }TCCSSTR;
typedef union{   /*  ROM Mirror */
    IO_BYTE	byte;
    struct{
    IO_BYTE _MI :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
 }ROMMSTR;
typedef union{   /*  ROM Correction */
    IO_BYTE	byte;
    struct{
    IO_BYTE  :1;
    IO_BYTE _AD0E :1;
    IO_BYTE  :1;
    IO_BYTE _AD1E :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
 }PACSRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _R0 :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
 }DIRRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _SSR :1;
    IO_BYTE _CG0 :1;
    IO_BYTE _CG1 :1;
    IO_BYTE _TMD :1;
    IO_BYTE _RST :1;
    IO_BYTE _SPL :1;
    IO_BYTE _SLP :1;
    IO_BYTE _STP :1;
  }bit;
  struct{
    IO_BYTE :1;
    IO_BYTE _CG :2;
  }bitc;
 }LPMCRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _CS0 :1;
    IO_BYTE _CS1 :1;
    IO_BYTE _MCS :1;
    IO_BYTE _SCS :1;
    IO_BYTE _WS0 :1;
    IO_BYTE _WS1 :1;
    IO_BYTE _MCM :1;
    IO_BYTE _SCM :1;
  }bit;
  struct{
    IO_BYTE _CS :2;
    IO_BYTE :2;
    IO_BYTE _WS :2;
  }bitc;
 }CKSCRSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _WT0 :1;
    IO_BYTE _WT1 :1;
    IO_BYTE _WTE :1;
    IO_BYTE _SRST :1;
    IO_BYTE _ERST :1;
    IO_BYTE _WRST :1;
    IO_BYTE _STBR :1;
    IO_BYTE _PONR :1;
  }bit;
  struct{
    IO_BYTE _WT :2;
  }bitc;
 }WDTCSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _TBC0 :1;
    IO_BYTE _TBC1 :1;
    IO_BYTE _TBR :1;
    IO_BYTE _TBOF :1;
    IO_BYTE _TBIE :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
    IO_BYTE  :1;
  }bit;
  struct{
    IO_BYTE _TBC :2;
  }bitc;
 }TBTCSTR;
typedef union{  
    IO_BYTE	byte;
    struct{
    IO_BYTE _WTC0 :1;
    IO_BYTE _WTC1 :1;
    IO_BYTE _WTC2 :1;
    IO_BYTE _WTR :1;
    IO_BYTE _WTOF :1;
    IO_BYTE _WTIE :1;
    IO_BYTE _SCE :1;
    IO_BYTE _WDCS :1;
  }bit;
 }WTCSTR;
typedef union{   /* Flash Control Register */
    IO_BYTE	byte;
    struct{
    IO_BYTE _LPM0 :1;
    IO_BYTE  :1;
    IO_BYTE _LPM1 :1;
    IO_BYTE  :1;
    IO_BYTE _RDY :1;
    IO_BYTE _WE :1;
    IO_BYTE _RDYINT :1;
    IO_BYTE _INTE :1;
  }bit;
 }FMCSSTR;

/* C-DECLARATIONS */

__IO_EXTERN __io PDR0STR _pdr0;   /*  PORT DATA */
#define PDR0 _pdr0.byte
#define PDR0_P00 _pdr0.bit._P00
#define PDR0_P01 _pdr0.bit._P01
#define PDR0_P02 _pdr0.bit._P02
#define PDR0_P03 _pdr0.bit._P03
#define PDR0_P04 _pdr0.bit._P04
#define PDR0_P05 _pdr0.bit._P05
#define PDR0_P06 _pdr0.bit._P06
#define PDR0_P07 _pdr0.bit._P07
__IO_EXTERN __io PDR1STR _pdr1;  
#define PDR1 _pdr1.byte
#define PDR1_P10 _pdr1.bit._P10
#define PDR1_P11 _pdr1.bit._P11
#define PDR1_P12 _pdr1.bit._P12
#define PDR1_P13 _pdr1.bit._P13
#define PDR1_P14 _pdr1.bit._P14
#define PDR1_P15 _pdr1.bit._P15
#define PDR1_P16 _pdr1.bit._P16
#define PDR1_P17 _pdr1.bit._P17
__IO_EXTERN __io PDR2STR _pdr2;  
#define PDR2 _pdr2.byte
#define PDR2_P20 _pdr2.bit._P20
#define PDR2_P21 _pdr2.bit._P21
#define PDR2_P22 _pdr2.bit._P22
#define PDR2_P23 _pdr2.bit._P23
#define PDR2_P24 _pdr2.bit._P24
#define PDR2_P25 _pdr2.bit._P25
#define PDR2_P26 _pdr2.bit._P26
#define PDR2_P27 _pdr2.bit._P27
__IO_EXTERN __io PDR3STR _pdr3;  
#define PDR3 _pdr3.byte
#define PDR3_P30 _pdr3.bit._P30
#define PDR3_P31 _pdr3.bit._P31
#define PDR3_P32 _pdr3.bit._P32
#define PDR3_P33 _pdr3.bit._P33
#define PDR3_P34 _pdr3.bit._P34
#define PDR3_P35 _pdr3.bit._P35
#define PDR3_P36 _pdr3.bit._P36
#define PDR3_P37 _pdr3.bit._P37
__IO_EXTERN __io PDR4STR _pdr4;  
#define PDR4 _pdr4.byte
#define PDR4_P40 _pdr4.bit._P40
#define PDR4_P41 _pdr4.bit._P41
#define PDR4_P42 _pdr4.bit._P42
#define PDR4_P43 _pdr4.bit._P43
#define PDR4_P44 _pdr4.bit._P44
#define PDR4_P45 _pdr4.bit._P45
#define PDR4_P46 _pdr4.bit._P46
#define PDR4_P47 _pdr4.bit._P47
__IO_EXTERN __io PDR5STR _pdr5;  
#define PDR5 _pdr5.byte
#define PDR5_P50 _pdr5.bit._P50
#define PDR5_P51 _pdr5.bit._P51
#define PDR5_P52 _pdr5.bit._P52
#define PDR5_P53 _pdr5.bit._P53
#define PDR5_P54 _pdr5.bit._P54
#define PDR5_P55 _pdr5.bit._P55
#define PDR5_P56 _pdr5.bit._P56
#define PDR5_P57 _pdr5.bit._P57
__IO_EXTERN __io PDR6STR _pdr6;  
#define PDR6 _pdr6.byte
#define PDR6_P60 _pdr6.bit._P60
#define PDR6_P61 _pdr6.bit._P61
#define PDR6_P62 _pdr6.bit._P62
#define PDR6_P63 _pdr6.bit._P63
#define PDR6_P64 _pdr6.bit._P64
#define PDR6_P65 _pdr6.bit._P65
#define PDR6_P66 _pdr6.bit._P66
#define PDR6_P67 _pdr6.bit._P67
__IO_EXTERN __io PDR7STR _pdr7;  
#define PDR7 _pdr7.byte
#define PDR7_P70 _pdr7.bit._P70
#define PDR7_P71 _pdr7.bit._P71
#define PDR7_P72 _pdr7.bit._P72
#define PDR7_P73 _pdr7.bit._P73
#define PDR7_P74 _pdr7.bit._P74
#define PDR7_P75 _pdr7.bit._P75
#define PDR7_P76 _pdr7.bit._P76
#define PDR7_P77 _pdr7.bit._P77
__IO_EXTERN __io PDR8STR _pdr8;  
#define PDR8 _pdr8.byte
#define PDR8_P80 _pdr8.bit._P80
#define PDR8_P81 _pdr8.bit._P81
#define PDR8_P82 _pdr8.bit._P82
#define PDR8_P83 _pdr8.bit._P83
#define PDR8_P84 _pdr8.bit._P84
#define PDR8_P85 _pdr8.bit._P85
#define PDR8_P86 _pdr8.bit._P86
#define PDR8_P87 _pdr8.bit._P87
__IO_EXTERN __io PDR9STR _pdr9;  
#define PDR9 _pdr9.byte
#define PDR9_P90 _pdr9.bit._P90
#define PDR9_P91 _pdr9.bit._P91
#define PDR9_P92 _pdr9.bit._P92
#define PDR9_P93 _pdr9.bit._P93
#define PDR9_P94 _pdr9.bit._P94
#define PDR9_P95 _pdr9.bit._P95
#define PDR9_P96 _pdr9.bit._P96
#define PDR9_P97 _pdr9.bit._P97
__IO_EXTERN __io PDRASTR _pdra;  
#define PDRA _pdra.byte
#define PDRA_PA0 _pdra.bit._PA0
__IO_EXTERN __io DDR0STR _ddr0;   /*  PORT DIRECTION */
#define DDR0 _ddr0.byte
#define DDR0_D00 _ddr0.bit._D00
#define DDR0_D01 _ddr0.bit._D01
#define DDR0_D02 _ddr0.bit._D02
#define DDR0_D03 _ddr0.bit._D03
#define DDR0_D04 _ddr0.bit._D04
#define DDR0_D05 _ddr0.bit._D05
#define DDR0_D06 _ddr0.bit._D06
#define DDR0_D07 _ddr0.bit._D07
__IO_EXTERN __io DDR1STR _ddr1;  
#define DDR1 _ddr1.byte
#define DDR1_D10 _ddr1.bit._D10
#define DDR1_D11 _ddr1.bit._D11
#define DDR1_D12 _ddr1.bit._D12
#define DDR1_D13 _ddr1.bit._D13
#define DDR1_D14 _ddr1.bit._D14
#define DDR1_D15 _ddr1.bit._D15
#define DDR1_D16 _ddr1.bit._D16
#define DDR1_D17 _ddr1.bit._D17
__IO_EXTERN __io DDR2STR _ddr2;  
#define DDR2 _ddr2.byte
#define DDR2_D20 _ddr2.bit._D20
#define DDR2_D21 _ddr2.bit._D21
#define DDR2_D22 _ddr2.bit._D22
#define DDR2_D23 _ddr2.bit._D23
#define DDR2_D24 _ddr2.bit._D24
#define DDR2_D25 _ddr2.bit._D25
#define DDR2_D26 _ddr2.bit._D26
#define DDR2_D27 _ddr2.bit._D27
__IO_EXTERN __io DDR3STR _ddr3;  
#define DDR3 _ddr3.byte
#define DDR3_D30 _ddr3.bit._D30
#define DDR3_D31 _ddr3.bit._D31
#define DDR3_D32 _ddr3.bit._D32
#define DDR3_D33 _ddr3.bit._D33
#define DDR3_D34 _ddr3.bit._D34
#define DDR3_D35 _ddr3.bit._D35
#define DDR3_D36 _ddr3.bit._D36
#define DDR3_D37 _ddr3.bit._D37
__IO_EXTERN __io DDR4STR _ddr4;  
#define DDR4 _ddr4.byte
#define DDR4_D40 _ddr4.bit._D40
#define DDR4_D41 _ddr4.bit._D41
#define DDR4_D42 _ddr4.bit._D42
#define DDR4_D43 _ddr4.bit._D43
#define DDR4_D44 _ddr4.bit._D44
#define DDR4_D45 _ddr4.bit._D45
#define DDR4_D46 _ddr4.bit._D46
#define DDR4_D47 _ddr4.bit._D47
__IO_EXTERN __io DDR5STR _ddr5;  
#define DDR5 _ddr5.byte
#define DDR5_D50 _ddr5.bit._D50
#define DDR5_D51 _ddr5.bit._D51
#define DDR5_D52 _ddr5.bit._D52
#define DDR5_D53 _ddr5.bit._D53
#define DDR5_D54 _ddr5.bit._D54
#define DDR5_D55 _ddr5.bit._D55
#define DDR5_D56 _ddr5.bit._D56
#define DDR5_D57 _ddr5.bit._D57
__IO_EXTERN __io DDR6STR _ddr6;  
#define DDR6 _ddr6.byte
#define DDR6_D60 _ddr6.bit._D60
#define DDR6_D61 _ddr6.bit._D61
#define DDR6_D62 _ddr6.bit._D62
#define DDR6_D63 _ddr6.bit._D63
#define DDR6_D64 _ddr6.bit._D64
#define DDR6_D65 _ddr6.bit._D65
#define DDR6_D66 _ddr6.bit._D66
#define DDR6_D67 _ddr6.bit._D67
__IO_EXTERN __io DDR7STR _ddr7;  
#define DDR7 _ddr7.byte
#define DDR7_D70 _ddr7.bit._D70
#define DDR7_D71 _ddr7.bit._D71
#define DDR7_D72 _ddr7.bit._D72
#define DDR7_D73 _ddr7.bit._D73
#define DDR7_D74 _ddr7.bit._D74
#define DDR7_D75 _ddr7.bit._D75
#define DDR7_D76 _ddr7.bit._D76
#define DDR7_D77 _ddr7.bit._D77
__IO_EXTERN __io DDR8STR _ddr8;  
#define DDR8 _ddr8.byte
#define DDR8_D80 _ddr8.bit._D80
#define DDR8_D81 _ddr8.bit._D81
#define DDR8_D82 _ddr8.bit._D82
#define DDR8_D83 _ddr8.bit._D83
#define DDR8_D84 _ddr8.bit._D84
#define DDR8_D85 _ddr8.bit._D85
#define DDR8_D86 _ddr8.bit._D86
#define DDR8_D87 _ddr8.bit._D87
__IO_EXTERN __io DDR9STR _ddr9;  
#define DDR9 _ddr9.byte
#define DDR9_D90 _ddr9.bit._D90
#define DDR9_D91 _ddr9.bit._D91
#define DDR9_D92 _ddr9.bit._D92
#define DDR9_D93 _ddr9.bit._D93
#define DDR9_D94 _ddr9.bit._D94
#define DDR9_D95 _ddr9.bit._D95
#define DDR9_D96 _ddr9.bit._D96
#define DDR9_D97 _ddr9.bit._D97
__IO_EXTERN __io DDRASTR _ddra;  
#define DDRA _ddra.byte
#define DDRA_DA0 _ddra.bit._DA0
__IO_EXTERN __io ADERSTR _ader;  
#define ADER _ader.byte
#define ADER_ADE0 _ader.bit._ADE0
#define ADER_ADE1 _ader.bit._ADE1
#define ADER_ADE2 _ader.bit._ADE2
#define ADER_ADE3 _ader.bit._ADE3
#define ADER_ADE4 _ader.bit._ADE4
#define ADER_ADE5 _ader.bit._ADE5
#define ADER_ADE6 _ader.bit._ADE6
#define ADER_ADE7 _ader.bit._ADE7
__IO_EXTERN __io PUCR0STR _pucr0;   /*  PULL-UP CONTROL */
#define PUCR0 _pucr0.byte
#define PUCR0_PU00 _pucr0.bit._PU00
#define PUCR0_PU01 _pucr0.bit._PU01
#define PUCR0_PU02 _pucr0.bit._PU02
#define PUCR0_PU03 _pucr0.bit._PU03
#define PUCR0_PU04 _pucr0.bit._PU04
#define PUCR0_PU05 _pucr0.bit._PU05
#define PUCR0_PU06 _pucr0.bit._PU06
#define PUCR0_PU07 _pucr0.bit._PU07
__IO_EXTERN __io PUCR1STR _pucr1;  
#define PUCR1 _pucr1.byte
#define PUCR1_PU10 _pucr1.bit._PU10
#define PUCR1_PU11 _pucr1.bit._PU11
#define PUCR1_PU12 _pucr1.bit._PU12
#define PUCR1_PU13 _pucr1.bit._PU13
#define PUCR1_PU14 _pucr1.bit._PU14
#define PUCR1_PU15 _pucr1.bit._PU15
#define PUCR1_PU16 _pucr1.bit._PU16
#define PUCR1_PU17 _pucr1.bit._PU17
__IO_EXTERN __io PUCR2STR _pucr2;  
#define PUCR2 _pucr2.byte
#define PUCR2_PU20 _pucr2.bit._PU20
#define PUCR2_PU21 _pucr2.bit._PU21
#define PUCR2_PU22 _pucr2.bit._PU22
#define PUCR2_PU23 _pucr2.bit._PU23
#define PUCR2_PU24 _pucr2.bit._PU24
#define PUCR2_PU25 _pucr2.bit._PU25
#define PUCR2_PU26 _pucr2.bit._PU26
#define PUCR2_PU27 _pucr2.bit._PU27
__IO_EXTERN __io PUCR3STR _pucr3;  
#define PUCR3 _pucr3.byte
#define PUCR3_PU30 _pucr3.bit._PU30
#define PUCR3_PU31 _pucr3.bit._PU31
#define PUCR3_PU32 _pucr3.bit._PU32
#define PUCR3_PU33 _pucr3.bit._PU33
#define PUCR3_PU34 _pucr3.bit._PU34
#define PUCR3_PU35 _pucr3.bit._PU35
#define PUCR3_PU36 _pucr3.bit._PU36
#define PUCR3_PU37 _pucr3.bit._PU37
__IO_EXTERN __io UMC0STR _umc0;   /*  UART0 */
#define UMC0 _umc0.byte
#define UMC0_SOE _umc0.bit._SOE
#define UMC0_SCKE _umc0.bit._SCKE
#define UMC0_RFC _umc0.bit._RFC
#define UMC0_SMDE _umc0.bit._SMDE
#define UMC0_MC0 _umc0.bit._MC0
#define UMC0_MC1 _umc0.bit._MC1
#define UMC0_SBL _umc0.bit._SBL
#define UMC0_PEN _umc0.bit._PEN
__IO_EXTERN __io USR0STR _usr0;  
#define USR0 _usr0.byte
#define USR0_TBF _usr0.bit._TBF
#define USR0_RBF _usr0.bit._RBF
#define USR0_TIE _usr0.bit._TIE
#define USR0_RIE _usr0.bit._RIE
#define USR0_TDRE _usr0.bit._TDRE
#define USR0_PE _usr0.bit._PE
#define USR0_ORFE _usr0.bit._ORFE
#define USR0_RDRF _usr0.bit._RDRF
__IO_EXTERN __io UIDR0STR _uidr0;  
#define UIDR0 _uidr0.byte
#define UIDR0_D0 _uidr0.bit._D0
#define UIDR0_D1 _uidr0.bit._D1
#define UIDR0_D2 _uidr0.bit._D2
#define UIDR0_D3 _uidr0.bit._D3
#define UIDR0_D4 _uidr0.bit._D4
#define UIDR0_D5 _uidr0.bit._D5
#define UIDR0_D6 _uidr0.bit._D6
#define UIDR0_D7 _uidr0.bit._D7
__IO_EXTERN __io UODR0STR _uodr0;  
#define UODR0 _uodr0.byte
#define UODR0_D0 _uodr0.bit._D0
#define UODR0_D1 _uodr0.bit._D1
#define UODR0_D2 _uodr0.bit._D2
#define UODR0_D3 _uodr0.bit._D3
#define UODR0_D4 _uodr0.bit._D4
#define UODR0_D5 _uodr0.bit._D5
#define UODR0_D6 _uodr0.bit._D6
#define UODR0_D7 _uodr0.bit._D7
__IO_EXTERN __io URD0STR _urd0;  
#define URD0 _urd0.byte
#define URD0_D8 _urd0.bit._D8
#define URD0_P _urd0.bit._P
#define URD0_BCH0 _urd0.bit._BCH0
#define URD0_RC0 _urd0.bit._RC0
#define URD0_RC1 _urd0.bit._RC1
#define URD0_RC2 _urd0.bit._RC2
#define URD0_RC3 _urd0.bit._RC3
#define URD0_BCH _urd0.bit._BCH
__IO_EXTERN __io SMR1STR _smr1;   /*  UART1 SCI with clock selection */
#define SMR1 _smr1.byte
#define SMR1_SOE _smr1.bit._SOE
#define SMR1_SCKE _smr1.bit._SCKE
#define SMR1_CS0 _smr1.bit._CS0
#define SMR1_CS1 _smr1.bit._CS1
#define SMR1_CS2 _smr1.bit._CS2
#define SMR1_MD0 _smr1.bit._MD0
#define SMR1_MD1 _smr1.bit._MD1
#define SMR1_CS _smr1.bitc._CS
#define SMR1_MD _smr1.bitc._MD
__IO_EXTERN __io SCR1STR _scr1;  
#define SCR1 _scr1.byte
#define SCR1_TXE _scr1.bit._TXE
#define SCR1_RXE _scr1.bit._RXE
#define SCR1_REC _scr1.bit._REC
#define SCR1_AD _scr1.bit._AD
#define SCR1_CL _scr1.bit._CL
#define SCR1_SBL _scr1.bit._SBL
#define SCR1_P _scr1.bit._P
#define SCR1_PEN _scr1.bit._PEN
__IO_EXTERN __io SIDR1STR _sidr1;  
#define SIDR1 _sidr1.byte
#define SIDR1_D0 _sidr1.bit._D0
#define SIDR1_D1 _sidr1.bit._D1
#define SIDR1_D2 _sidr1.bit._D2
#define SIDR1_D3 _sidr1.bit._D3
#define SIDR1_D4 _sidr1.bit._D4
#define SIDR1_D5 _sidr1.bit._D5
#define SIDR1_D6 _sidr1.bit._D6
#define SIDR1_D7 _sidr1.bit._D7
__IO_EXTERN __io SODR1STR _sodr1;  
#define SODR1 _sodr1.byte
#define SODR1_D0 _sodr1.bit._D0
#define SODR1_D1 _sodr1.bit._D1
#define SODR1_D2 _sodr1.bit._D2
#define SODR1_D3 _sodr1.bit._D3
#define SODR1_D4 _sodr1.bit._D4
#define SODR1_D5 _sodr1.bit._D5
#define SODR1_D6 _sodr1.bit._D6
#define SODR1_D7 _sodr1.bit._D7
__IO_EXTERN __io SSR1STR _ssr1;  
#define SSR1 _ssr1.byte
#define SSR1_TIE _ssr1.bit._TIE
#define SSR1_RIE _ssr1.bit._RIE
#define SSR1_TDRE _ssr1.bit._TDRE
#define SSR1_RDRF _ssr1.bit._RDRF
#define SSR1_FRE _ssr1.bit._FRE
#define SSR1_ORE _ssr1.bit._ORE
#define SSR1_PE _ssr1.bit._PE
__IO_EXTERN __io U1CDCRSTR _u1cdcr;  
#define U1CDCR _u1cdcr.byte
#define U1CDCR_DIV0 _u1cdcr.bit._DIV0
#define U1CDCR_DIV1 _u1cdcr.bit._DIV1
#define U1CDCR_DIV2 _u1cdcr.bit._DIV2
#define U1CDCR_DIV3 _u1cdcr.bit._DIV3
#define U1CDCR_MD _u1cdcr.bit._MD
#define U1CDCR_DIV _u1cdcr.bitc._DIV
__IO_EXTERN __io SES1STR _ses1;  
#define SES1 _ses1.byte
#define SES1_NEG _ses1.bit._NEG
__IO_EXTERN __io SCDCRSTR _scdcr;   /*  SIO with clock selection */
#define SCDCR _scdcr.byte
#define SCDCR_DIV0 _scdcr.bit._DIV0
#define SCDCR_DIV1 _scdcr.bit._DIV1
#define SCDCR_DIV2 _scdcr.bit._DIV2
#define SCDCR_DIV3 _scdcr.bit._DIV3
#define SCDCR_MD _scdcr.bit._MD
#define SCDCR_DIV _scdcr.bitc._DIV
__IO_EXTERN __io SMCSSTR _smcs;  
#define SMCS _smcs.word
#define SMCS_SCOE _smcs.bit._SCOE
#define SMCS_SOE _smcs.bit._SOE
#define SMCS_BDS _smcs.bit._BDS
#define SMCS_MODE _smcs.bit._MODE
#define SMCS_STRT _smcs.bit._STRT
#define SMCS_STOP _smcs.bit._STOP
#define SMCS_BUSY _smcs.bit._BUSY
#define SMCS_SIR _smcs.bit._SIR
#define SMCS_SIE _smcs.bit._SIE
#define SMCS_SMD0 _smcs.bit._SMD0
#define SMCS_SMD1 _smcs.bit._SMD1
#define SMCS_SMD2 _smcs.bit._SMD2
#define SMCS_SMD _smcs.bitc._SMD
__IO_EXTERN __io SDRSTR _sdr;  
#define SDR _sdr.byte
#define SDR_D0 _sdr.bit._D0
#define SDR_D1 _sdr.bit._D1
#define SDR_D2 _sdr.bit._D2
#define SDR_D3 _sdr.bit._D3
#define SDR_D4 _sdr.bit._D4
#define SDR_D5 _sdr.bit._D5
#define SDR_D6 _sdr.bit._D6
#define SDR_D7 _sdr.bit._D7
__IO_EXTERN __io SES2STR _ses2;  
#define SES2 _ses2.byte
#define SES2_NEG _ses2.bit._NEG
__IO_EXTERN __io ENIRSTR _enir;   /*  DTP, External Interrupts */
#define ENIR _enir.byte
#define ENIR_EN0 _enir.bit._EN0
#define ENIR_EN1 _enir.bit._EN1
#define ENIR_EN2 _enir.bit._EN2
#define ENIR_EN3 _enir.bit._EN3
#define ENIR_EN4 _enir.bit._EN4
#define ENIR_EN5 _enir.bit._EN5
#define ENIR_EN6 _enir.bit._EN6
#define ENIR_EN7 _enir.bit._EN7
__IO_EXTERN __io EIRRSTR _eirr;  
#define EIRR _eirr.byte
#define EIRR_ER0 _eirr.bit._ER0
#define EIRR_ER1 _eirr.bit._ER1
#define EIRR_ER2 _eirr.bit._ER2
#define EIRR_ER3 _eirr.bit._ER3
#define EIRR_ER4 _eirr.bit._ER4
#define EIRR_ER5 _eirr.bit._ER5
#define EIRR_ER6 _eirr.bit._ER6
#define EIRR_ER7 _eirr.bit._ER7
/* include : ELVR.H */

#ifndef __ELVR_H
#define __ELVR_H

typedef union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD LB7 :1;
      IO_WORD LA7 :1;
      IO_WORD LB6 :1;
      IO_WORD LA6 :1;
      IO_WORD LB5 :1;
      IO_WORD LA5 :1;
      IO_WORD LB4 :1;
      IO_WORD LA4 :1;
      IO_WORD LB3 :1;
      IO_WORD LA3 :1;
      IO_WORD LB2 :1;
      IO_WORD LA2 :1;
      IO_WORD LB1 :1;
      IO_WORD LA1 :1;
      IO_WORD LB0 :1;
      IO_WORD LA0 :1;
#else
      IO_WORD LA0 :1;
      IO_WORD LB0 :1;
      IO_WORD LA1 :1;
      IO_WORD LB1 :1;
      IO_WORD LA2 :1;
      IO_WORD LB2 :1;
      IO_WORD LA3 :1;
      IO_WORD LB3 :1;
      IO_WORD LA4 :1;
      IO_WORD LB4 :1;
      IO_WORD LA5 :1;
      IO_WORD LB5 :1;
      IO_WORD LA6 :1;
      IO_WORD LB6 :1;
      IO_WORD LA7 :1;
      IO_WORD LB7 :1;
#endif
    }bit;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD LALB7 :2;
      IO_WORD LALB6 :2;
      IO_WORD LALB5 :2;
      IO_WORD LALB4 :2;
      IO_WORD LALB3 :2;
      IO_WORD LALB2 :2;
      IO_WORD LALB1 :2;
      IO_WORD LALB0 :2;
#else
      IO_WORD LALB0 :2;
      IO_WORD LALB1 :2;
      IO_WORD LALB2 :2;
      IO_WORD LALB3 :2;
      IO_WORD LALB4 :2;
      IO_WORD LALB5 :2;
      IO_WORD LALB6 :2;
      IO_WORD LALB7 :2;
#endif
    } bitc;
} ELVRSTR;

__IO_EXTERN __io ELVRSTR _elvr;  
#define ELVR        _elvr.word
#define ELVR_LA0    _elvr.bit.LA0
#define ELVR_LB0    _elvr.bit.LB0
#define ELVR_LA1    _elvr.bit.LA1
#define ELVR_LB1    _elvr.bit.LB1
#define ELVR_LA2    _elvr.bit.LA2
#define ELVR_LB2    _elvr.bit.LB2
#define ELVR_LA3    _elvr.bit.LA3
#define ELVR_LB3    _elvr.bit.LB3
#define ELVR_LA4    _elvr.bit.LA4
#define ELVR_LB4    _elvr.bit.LB4
#define ELVR_LA5    _elvr.bit.LA5
#define ELVR_LB5    _elvr.bit.LB5
#define ELVR_LA6    _elvr.bit.LA6
#define ELVR_LB6    _elvr.bit.LB6
#define ELVR_LA7    _elvr.bit.LA7
#define ELVR_LB7    _elvr.bit.LB7
#define ELVR_LALB0  _elvr.bitc.LALB0
#define ELVR_LALB1  _elvr.bitc.LALB1
#define ELVR_LALB2  _elvr.bitc.LALB2
#define ELVR_LALB3  _elvr.bitc.LALB3
#define ELVR_LALB4  _elvr.bitc.LALB4
#define ELVR_LALB5  _elvr.bitc.LALB5
#define ELVR_LALB6  _elvr.bitc.LALB6
#define ELVR_LALB7  _elvr.bitc.LALB7

#endif
/* include : ADC_01.H */


#ifndef __ADC_H
#define __ADC_H

typedef union{   /*  */
    IO_WORD	word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_WORD BUSY :1;
    const IO_WORD INT  :1;
    const IO_WORD INTE :1;
    const IO_WORD PAUS :1;
    const IO_WORD STS1 :1;
    const IO_WORD STS0 :1;
    const IO_WORD STRT :1;
    const IO_WORD RESV :1; 
    const IO_WORD MD1  :1;
    const IO_WORD MD0  :1;
    const IO_WORD ANS2 :1;
    const IO_WORD ANS1 :1;
    const IO_WORD ANS0 :1;
    const IO_WORD ANE2 :1;
    const IO_WORD ANE1 :1;
    const IO_WORD ANE0 :1;
#else
    const IO_WORD ANE0 :1;
    const IO_WORD ANE1 :1;
    const IO_WORD ANE2 :1;
    const IO_WORD ANS0 :1;
    const IO_WORD ANS1 :1;
    const IO_WORD ANS2 :1;
    const IO_WORD MD0  :1;
    const IO_WORD MD1  :1;
    const IO_WORD RESV :1; 
    const IO_WORD STRT :1;
    const IO_WORD STS0 :1;
    const IO_WORD STS1 :1;
    const IO_WORD PAUS :1;
    const IO_WORD INTE :1;
    const IO_WORD INT  :1;
    const IO_WORD BUSY :1;
#endif
   }bit;
  struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_WORD :4;
    const IO_WORD STS :2;
    const IO_WORD :1;
    const IO_WORD :1;
    const IO_WORD MD :2;
    const IO_WORD ANS :3;
    const IO_WORD ANE :3;
#else
    const IO_WORD ANE :3;
    const IO_WORD ANS :3;
    const IO_WORD MD :2;
    const IO_WORD :1;
    const IO_WORD :1;
    const IO_WORD STS :2;
#endif
  }bitc;
 }ADCSSTR;

typedef union{  
    IO_BYTE	byte;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_BYTE MD1 :1;
    const IO_BYTE MD0 :1;
    const IO_BYTE ANS2 :1;
    const IO_BYTE ANS1 :1;
    const IO_BYTE ANS0 :1;
    const IO_BYTE ANE2 :1;
    const IO_BYTE ANE1 :1;
    const IO_BYTE ANE0 :1;
#else
    const IO_BYTE ANE0 :1;
    const IO_BYTE ANE1 :1;
    const IO_BYTE ANE2 :1;
    const IO_BYTE ANS0 :1;
    const IO_BYTE ANS1 :1;
    const IO_BYTE ANS2 :1;
    const IO_BYTE MD0 :1;
    const IO_BYTE MD1 :1;
#endif
  }bit;
  struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_BYTE MD :2;
    const IO_BYTE ANS :3;
    const IO_BYTE ANE :3;
#else
    const IO_BYTE ANE :3;
    const IO_BYTE ANS :3;
    const IO_BYTE MD :2;
#endif
  }bitc;
 }ADCS0STR;

typedef union{  
    IO_BYTE	byte;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_BYTE BUSY :1;
    const IO_BYTE INT :1;
    const IO_BYTE INTE :1;
    const IO_BYTE PAUS :1;
    const IO_BYTE STS1 :1;
    const IO_BYTE STS0 :1;
    const IO_BYTE STRT :1;
    const IO_BYTE RESV :1;
#else
    const IO_BYTE RESV :1;
    const IO_BYTE STRT :1;
    const IO_BYTE STS0 :1;
    const IO_BYTE STS1 :1;
    const IO_BYTE PAUS :1;
    const IO_BYTE INTE :1;
    const IO_BYTE INT :1;
    const IO_BYTE BUSY :1;
#endif
  }bit;
  struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_BYTE :4;
    const IO_BYTE STS :2;
#else
    const IO_BYTE :2;
    const IO_BYTE STS :2;
#endif
  }bitc;
 }ADCS1STR;

typedef union{  
    IO_WORD	word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_WORD S10 :1;
    const IO_WORD ST1 :1;
    const IO_WORD ST0 :1;
    const IO_WORD CT1 :1;
    const IO_WORD CT0 :1;
    const IO_WORD  :1;
    const IO_WORD D9 :1;
    const IO_WORD D8 :1;
    const IO_WORD D7 :1;
    const IO_WORD D6 :1;
    const IO_WORD D5 :1;
    const IO_WORD D4 :1;
    const IO_WORD D3 :1;
    const IO_WORD D2 :1;
    const IO_WORD D1 :1;
    const IO_WORD D0 :1;
#else
    const IO_WORD D0 :1;
    const IO_WORD D1 :1;
    const IO_WORD D2 :1;
    const IO_WORD D3 :1;
    const IO_WORD D4 :1;
    const IO_WORD D5 :1;
    const IO_WORD D6 :1;
    const IO_WORD D7 :1;
    const IO_WORD D8 :1;
    const IO_WORD D9 :1;
    const IO_WORD  :1;
    const IO_WORD CT0 :1;
    const IO_WORD CT1 :1;
    const IO_WORD ST0 :1;
    const IO_WORD ST1 :1;
    const IO_WORD S10 :1;
#endif
  }bit;
  struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_WORD ST :2;
    const IO_WORD CT :2;
#else
    const IO_WORD :11;
    const IO_WORD CT :2;
    const IO_WORD ST :2;
#endif
  }bitc;
 }ADCRSTR;

typedef union{  
    const IO_BYTE	byte;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_BYTE D7 :1;
    const IO_BYTE D6 :1;
    const IO_BYTE D5 :1;
    const IO_BYTE D4 :1;
    const IO_BYTE D3 :1;
    const IO_BYTE D2 :1;
    const IO_BYTE D1 :1;
    const IO_BYTE D0 :1;
#else
    const IO_BYTE D0 :1;
    const IO_BYTE D1 :1;
    const IO_BYTE D2 :1;
    const IO_BYTE D3 :1;
    const IO_BYTE D4 :1;
    const IO_BYTE D5 :1;
    const IO_BYTE D6 :1;
    const IO_BYTE D7 :1;
#endif
  }bit;
 }ADCR0STR;

typedef union{  
    IO_BYTE	byte;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_BYTE S10 :1;
    const IO_BYTE ST1 :1;
    const IO_BYTE ST0 :1;
    const IO_BYTE CT1 :1;
    const IO_BYTE CT0 :1;
    const IO_BYTE  :1;
    const IO_BYTE D9 :1;
    const IO_BYTE D8 :1;
#else
    const IO_BYTE D8 :1;
    const IO_BYTE D9 :1;
    const IO_BYTE  :1;
    const IO_BYTE CT0 :1;
    const IO_BYTE CT1 :1;
    const IO_BYTE ST0 :1;
    const IO_BYTE ST1 :1;
    const IO_BYTE S10 :1;
#endif
  }bit;
  struct{
#if defined(__BITFIELD_ORDER_MSB__)
    const IO_BYTE ST :2;
    const IO_BYTE CT :2;
#else
    const IO_BYTE :1;
    const IO_BYTE :1;
    const IO_BYTE :1;
    const IO_BYTE CT :2;
    const IO_BYTE ST :2;
#endif
  }bitc;
 }ADCR1STR;

__IO_EXTERN __io ADCSSTR _adcs;
#define ADCS _adcs.word
#define ADCS_ANE0 _adcs.bit.ANE0
#define ADCS_ANE1 _adcs.bit.ANE1
#define ADCS_ANE2 _adcs.bit.ANE2
#define ADCS_ANS0 _adcs.bit.ANS0
#define ADCS_ANS1 _adcs.bit.ANS1
#define ADCS_ANS2 _adcs.bit.ANS2
#define ADCS_MD0 _adcs.bit.MD0
#define ADCS_MD1 _adcs.bit.MD1
#define ADCS_STRT _adcs.bit.STRT
#define ADCS_STS0 _adcs.bit.STS0
#define ADCS_STS1 _adcs.bit.STS1
#define ADCS_PAUS _adcs.bit.PAUS
#define ADCS_INTE _adcs.bit.INTE
#define ADCS_INT _adcs.bit.INT
#define ADCS_BUSY _adcs.bit.BUSY
#define ADCS_ANE _adcs.bitc.ANE
#define ADCS_ANS _adcs.bitc.ANS
#define ADCS_MD _adcs.bitc.MD
#define ADCS_STS _adcs.bitc.STS
__IO_EXTERN __io ADCS0STR _adcs0;  
#define ADCS0 _adcs0.byte
#define ADCS0_ANE0 _adcs0.bit.ANE0
#define ADCS0_ANE1 _adcs0.bit.ANE1
#define ADCS0_ANE2 _adcs0.bit.ANE2
#define ADCS0_ANS0 _adcs0.bit.ANS0
#define ADCS0_ANS1 _adcs0.bit.ANS1
#define ADCS0_ANS2 _adcs0.bit.ANS2
#define ADCS0_MD0 _adcs0.bit.MD0
#define ADCS0_MD1 _adcs0.bit.MD1
#define ADCS0_ANE _adcs0.bitc.ANE
#define ADCS0_ANS _adcs0.bitc.ANS
#define ADCS0_MD _adcs0.bitc.MD
__IO_EXTERN __io ADCS1STR _adcs1;  
#define ADCS1 _adcs1.byte
#define ADCS1_STRT _adcs1.bit.STRT
#define ADCS1_STS0 _adcs1.bit.STS0
#define ADCS1_STS1 _adcs1.bit.STS1
#define ADCS1_PAUS _adcs1.bit.PAUS
#define ADCS1_INTE _adcs1.bit.INTE
#define ADCS1_INT _adcs1.bit.INT
#define ADCS1_BUSY _adcs1.bit.BUSY
#define ADCS1_STS _adcs1.bitc.STS
__IO_EXTERN __io ADCRSTR _adcr;  
#define ADCR _adcr.word
#define ADCR_D0 _adcr.bit.D0
#define ADCR_D1 _adcr.bit.D1
#define ADCR_D2 _adcr.bit.D2
#define ADCR_D3 _adcr.bit.D3
#define ADCR_D4 _adcr.bit.D4
#define ADCR_D5 _adcr.bit.D5
#define ADCR_D6 _adcr.bit.D6
#define ADCR_D7 _adcr.bit.D7
#define ADCR_D8 _adcr.bit.D8
#define ADCR_D9 _adcr.bit.D9
#define ADCR_CT0 _adcr.bit.CT0
#define ADCR_CT1 _adcr.bit.CT1
#define ADCR_ST0 _adcr.bit.ST0
#define ADCR_ST1 _adcr.bit.ST1
#define ADCR_S10 _adcr.bit.S10
#define ADCR_CT _adcr.bitc.CT
#define ADCR_ST _adcr.bitc.ST
__IO_EXTERN __io ADCR0STR _adcr0;  
#define ADCR0 _adcr0.byte
#define ADCR0_D0 _adcr0.bit.D0
#define ADCR0_D1 _adcr0.bit.D1
#define ADCR0_D2 _adcr0.bit.D2
#define ADCR0_D3 _adcr0.bit.D3
#define ADCR0_D4 _adcr0.bit.D4
#define ADCR0_D5 _adcr0.bit.D5
#define ADCR0_D6 _adcr0.bit.D6
#define ADCR0_D7 _adcr0.bit.D7
__IO_EXTERN __io ADCR1STR _adcr1;  
#define ADCR1 _adcr1.byte
#define ADCR1_D8 _adcr1.bit.D8
#define ADCR1_D9 _adcr1.bit.D9
#define ADCR1_CT0 _adcr1.bit.CT0
#define ADCR1_CT1 _adcr1.bit.CT1
#define ADCR1_ST0 _adcr1.bit.ST0
#define ADCR1_ST1 _adcr1.bit.ST1
#define ADCR1_S10 _adcr1.bit.S10
#define ADCR1_CT _adcr1.bitc.CT
#define ADCR1_ST _adcr1.bitc.ST

#endif   /* __ADC_H  */
__IO_EXTERN __io IO_WORD _ppgc01;
#define PPGC01 _ppgc01    /*  PPG control */
__IO_EXTERN __io PPGC0STR _ppgc0;  
#define PPGC0 _ppgc0.byte
#define PPGC0_PUF0 _ppgc0.bit._PUF0
#define PPGC0_PIE0 _ppgc0.bit._PIE0
#define PPGC0_PE00 _ppgc0.bit._PE00
#define PPGC0_PEN0 _ppgc0.bit._PEN0
__IO_EXTERN __io PPGC1STR _ppgc1;  
#define PPGC1 _ppgc1.byte
#define PPGC1_MD0 _ppgc1.bit._MD0
#define PPGC1_MD1 _ppgc1.bit._MD1
#define PPGC1_PUF1 _ppgc1.bit._PUF1
#define PPGC1_PIE1 _ppgc1.bit._PIE1
#define PPGC1_PE10 _ppgc1.bit._PE10
#define PPGC1_PEN1 _ppgc1.bit._PEN1
#define PPGC1_MD _ppgc1.bitc._MD
__IO_EXTERN __io PPG01STR _ppg01;  
#define PPG01 _ppg01.byte
#define PPG01_PCM0 _ppg01.bit._PCM0
#define PPG01_PCM1 _ppg01.bit._PCM1
#define PPG01_PCM2 _ppg01.bit._PCM2
#define PPG01_PCS0 _ppg01.bit._PCS0
#define PPG01_PCS1 _ppg01.bit._PCS1
#define PPG01_PCS2 _ppg01.bit._PCS2
#define PPG01_PCM _ppg01.bitc._PCM
#define PPG01_PCS _ppg01.bitc._PCS
__IO_EXTERN __io IO_WORD _ppgc23;
#define PPGC23 _ppgc23   
__IO_EXTERN __io PPGC2STR _ppgc2;  
#define PPGC2 _ppgc2.byte
#define PPGC2_PUF2 _ppgc2.bit._PUF2
#define PPGC2_PIE2 _ppgc2.bit._PIE2
#define PPGC2_PE20 _ppgc2.bit._PE20
#define PPGC2_PEN2 _ppgc2.bit._PEN2
__IO_EXTERN __io PPGC3STR _ppgc3;  
#define PPGC3 _ppgc3.byte
#define PPGC3_MD0 _ppgc3.bit._MD0
#define PPGC3_MD1 _ppgc3.bit._MD1
#define PPGC3_PUF3 _ppgc3.bit._PUF3
#define PPGC3_PIE3 _ppgc3.bit._PIE3
#define PPGC3_PE30 _ppgc3.bit._PE30
#define PPGC3_PEN3 _ppgc3.bit._PEN3
#define PPGC3_MD _ppgc3.bitc._MD
__IO_EXTERN __io PPG23STR _ppg23;  
#define PPG23 _ppg23.byte
#define PPG23_PCM0 _ppg23.bit._PCM0
#define PPG23_PCM1 _ppg23.bit._PCM1
#define PPG23_PCM2 _ppg23.bit._PCM2
#define PPG23_PCS0 _ppg23.bit._PCS0
#define PPG23_PCS1 _ppg23.bit._PCS1
#define PPG23_PCS2 _ppg23.bit._PCS2
#define PPG23_PCM _ppg23.bitc._PCM
#define PPG23_PCS _ppg23.bitc._PCS
__IO_EXTERN __io IO_WORD _ppgc45;
#define PPGC45 _ppgc45   
__IO_EXTERN __io PPGC4STR _ppgc4;  
#define PPGC4 _ppgc4.byte
#define PPGC4_PUF4 _ppgc4.bit._PUF4
#define PPGC4_PIE4 _ppgc4.bit._PIE4
#define PPGC4_PE40 _ppgc4.bit._PE40
#define PPGC4_PEN4 _ppgc4.bit._PEN4
__IO_EXTERN __io PPGC5STR _ppgc5;  
#define PPGC5 _ppgc5.byte
#define PPGC5_MD0 _ppgc5.bit._MD0
#define PPGC5_MD1 _ppgc5.bit._MD1
#define PPGC5_PUF5 _ppgc5.bit._PUF5
#define PPGC5_PIE5 _ppgc5.bit._PIE5
#define PPGC5_PE50 _ppgc5.bit._PE50
#define PPGC5_PEN5 _ppgc5.bit._PEN5
#define PPGC5_MD _ppgc5.bitc._MD
__IO_EXTERN __io PPG45STR _ppg45;  
#define PPG45 _ppg45.byte
#define PPG45_PCM0 _ppg45.bit._PCM0
#define PPG45_PCM1 _ppg45.bit._PCM1
#define PPG45_PCM2 _ppg45.bit._PCM2
#define PPG45_PCS0 _ppg45.bit._PCS0
#define PPG45_PCS1 _ppg45.bit._PCS1
#define PPG45_PCS2 _ppg45.bit._PCS2
#define PPG45_PCM _ppg45.bitc._PCM
#define PPG45_PCS _ppg45.bitc._PCS
__IO_EXTERN __io IO_WORD _ppgc67;
#define PPGC67 _ppgc67   
__IO_EXTERN __io PPGC6STR _ppgc6;  
#define PPGC6 _ppgc6.byte
#define PPGC6_PUF6 _ppgc6.bit._PUF6
#define PPGC6_PIE6 _ppgc6.bit._PIE6
#define PPGC6_PE60 _ppgc6.bit._PE60
#define PPGC6_PEN6 _ppgc6.bit._PEN6
__IO_EXTERN __io PPGC7STR _ppgc7;  
#define PPGC7 _ppgc7.byte
#define PPGC7_MD0 _ppgc7.bit._MD0
#define PPGC7_MD1 _ppgc7.bit._MD1
#define PPGC7_PUF7 _ppgc7.bit._PUF7
#define PPGC7_PIE7 _ppgc7.bit._PIE7
#define PPGC7_PE70 _ppgc7.bit._PE70
#define PPGC7_PEN7 _ppgc7.bit._PEN7
#define PPGC7_MD _ppgc7.bitc._MD
__IO_EXTERN __io PPG67STR _ppg67;  
#define PPG67 _ppg67.byte
#define PPG67_PCM0 _ppg67.bit._PCM0
#define PPG67_PCM1 _ppg67.bit._PCM1
#define PPG67_PCM2 _ppg67.bit._PCM2
#define PPG67_PCS0 _ppg67.bit._PCS0
#define PPG67_PCS1 _ppg67.bit._PCS1
#define PPG67_PCS2 _ppg67.bit._PCS2
#define PPG67_PCM _ppg67.bitc._PCM
#define PPG67_PCS _ppg67.bitc._PCS
__IO_EXTERN __io ICS01STR _ics01;  
#define ICS01 _ics01.byte
#define ICS01_EG00 _ics01.bit._EG00
#define ICS01_EG01 _ics01.bit._EG01
#define ICS01_EG10 _ics01.bit._EG10
#define ICS01_EG11 _ics01.bit._EG11
#define ICS01_ICE0 _ics01.bit._ICE0
#define ICS01_ICE1 _ics01.bit._ICE1
#define ICS01_ICP0 _ics01.bit._ICP0
#define ICS01_ICP1 _ics01.bit._ICP1
#define ICS01_EG0 _ics01.bitc._EG0
#define ICS01_EG1 _ics01.bitc._EG1
__IO_EXTERN __io ICS23STR _ics23;  
#define ICS23 _ics23.byte
#define ICS23_EG20 _ics23.bit._EG20
#define ICS23_EG21 _ics23.bit._EG21
#define ICS23_EG30 _ics23.bit._EG30
#define ICS23_EG31 _ics23.bit._EG31
#define ICS23_ICE2 _ics23.bit._ICE2
#define ICS23_ICE3 _ics23.bit._ICE3
#define ICS23_ICP2 _ics23.bit._ICP2
#define ICS23_ICP3 _ics23.bit._ICP3
#define ICS23_EG2 _ics23.bitc._EG2
#define ICS23_EG3 _ics23.bitc._EG3
__IO_EXTERN __io ICS45STR _ics45;  
#define ICS45 _ics45.byte
#define ICS45_EG40 _ics45.bit._EG40
#define ICS45_EG41 _ics45.bit._EG41
#define ICS45_EG50 _ics45.bit._EG50
#define ICS45_EG51 _ics45.bit._EG51
#define ICS45_ICE4 _ics45.bit._ICE4
#define ICS45_ICE5 _ics45.bit._ICE5
#define ICS45_ICP4 _ics45.bit._ICP4
#define ICS45_ICP5 _ics45.bit._ICP5
#define ICS45_EG4 _ics45.bitc._EG4
#define ICS45_EG5 _ics45.bitc._EG5
__IO_EXTERN __io ICS67STR _ics67;  
#define ICS67 _ics67.byte
#define ICS67_EG60 _ics67.bit._EG60
#define ICS67_EG61 _ics67.bit._EG61
#define ICS67_EG70 _ics67.bit._EG70
#define ICS67_EG71 _ics67.bit._EG71
#define ICS67_ICE6 _ics67.bit._ICE6
#define ICS67_ICE7 _ics67.bit._ICE7
#define ICS67_ICP6 _ics67.bit._ICP6
#define ICS67_ICP7 _ics67.bit._ICP7
#define ICS67_EG6 _ics67.bitc._EG6
#define ICS67_EG7 _ics67.bitc._EG7
__IO_EXTERN __io TMCSR0STR _tmcsr0;  
#define TMCSR0 _tmcsr0.word
#define TMCSR0_TRG _tmcsr0.bit._TRG
#define TMCSR0_CNTE _tmcsr0.bit._CNTE
#define TMCSR0_UF _tmcsr0.bit._UF
#define TMCSR0_INTE _tmcsr0.bit._INTE
#define TMCSR0_RELD _tmcsr0.bit._RELD
#define TMCSR0_OUTL _tmcsr0.bit._OUTL
#define TMCSR0_OUTE _tmcsr0.bit._OUTE
#define TMCSR0_MOD0 _tmcsr0.bit._MOD0
#define TMCSR0_MOD1 _tmcsr0.bit._MOD1
#define TMCSR0_MOD2 _tmcsr0.bit._MOD2
#define TMCSR0_CSL0 _tmcsr0.bit._CSL0
#define TMCSR0_CSL1 _tmcsr0.bit._CSL1
#define TMCSR0_MOD _tmcsr0.bitc._MOD
#define TMCSR0_CSL _tmcsr0.bitc._CSL
__IO_EXTERN __io IO_WORD _tmr0;
#define TMR0 _tmr0   
__IO_EXTERN __io IO_WORD _tmrlr0;
#define TMRLR0 _tmrlr0   
__IO_EXTERN __io TMCSR1STR _tmcsr1;  
#define TMCSR1 _tmcsr1.word
#define TMCSR1_TRG _tmcsr1.bit._TRG
#define TMCSR1_CNTE _tmcsr1.bit._CNTE
#define TMCSR1_UF _tmcsr1.bit._UF
#define TMCSR1_INTE _tmcsr1.bit._INTE
#define TMCSR1_RELD _tmcsr1.bit._RELD
#define TMCSR1_OUTL _tmcsr1.bit._OUTL
#define TMCSR1_OUTE _tmcsr1.bit._OUTE
#define TMCSR1_MOD0 _tmcsr1.bit._MOD0
#define TMCSR1_MOD1 _tmcsr1.bit._MOD1
#define TMCSR1_MOD2 _tmcsr1.bit._MOD2
#define TMCSR1_CSL0 _tmcsr1.bit._CSL0
#define TMCSR1_CSL1 _tmcsr1.bit._CSL1
#define TMCSR1_MOD _tmcsr1.bitc._MOD
#define TMCSR1_CSL _tmcsr1.bitc._CSL
__IO_EXTERN __io IO_WORD _tmr1;
#define TMR1 _tmr1   
__IO_EXTERN __io IO_WORD _tmrlr1;
#define TMRLR1 _tmrlr1   
__IO_EXTERN __io OCS0STR _ocs0;   /*  Output compare */
#define OCS0 _ocs0.byte
#define OCS0_CST0 _ocs0.bit._CST0
#define OCS0_CST1 _ocs0.bit._CST1
#define OCS0_ICE0 _ocs0.bit._ICE0
#define OCS0_ICE1 _ocs0.bit._ICE1
#define OCS0_ICP0 _ocs0.bit._ICP0
#define OCS0_ICP1 _ocs0.bit._ICP1
#define OCS0_CST _ocs0.bitc._CST
#define OCS0_ICE _ocs0.bitc._ICE
#define OCS0_ICP _ocs0.bitc._ICP
__IO_EXTERN __io OCS1STR _ocs1;  
#define OCS1 _ocs1.byte
#define OCS1_OTD0 _ocs1.bit._OTD0
#define OCS1_OTD1 _ocs1.bit._OTD1
#define OCS1_OTE0 _ocs1.bit._OTE0
#define OCS1_OTE1 _ocs1.bit._OTE1
#define OCS1_CMOD _ocs1.bit._CMOD
#define OCS1_OTD _ocs1.bitc._OTD
#define OCS1_OTE _ocs1.bitc._OTE
__IO_EXTERN __io OCS2STR _ocs2;  
#define OCS2 _ocs2.byte
#define OCS2_CST0 _ocs2.bit._CST0
#define OCS2_CST1 _ocs2.bit._CST1
#define OCS2_ICE0 _ocs2.bit._ICE0
#define OCS2_ICE1 _ocs2.bit._ICE1
#define OCS2_ICP0 _ocs2.bit._ICP0
#define OCS2_ICP1 _ocs2.bit._ICP1
#define OCS2_CST _ocs2.bitc._CST
#define OCS2_ICE _ocs2.bitc._ICE
#define OCS2_ICP _ocs2.bitc._ICP
__IO_EXTERN __io OCS3STR _ocs3;  
#define OCS3 _ocs3.byte
#define OCS3_OTD0 _ocs3.bit._OTD0
#define OCS3_OTD1 _ocs3.bit._OTD1
#define OCS3_OTE0 _ocs3.bit._OTE0
#define OCS3_OTE1 _ocs3.bit._OTE1
#define OCS3_CMOD _ocs3.bit._CMOD
#define OCS3_OTD _ocs3.bitc._OTD
#define OCS3_OTE _ocs3.bitc._OTE
__IO_EXTERN __io IO_WORD _tcdt;
#define TCDT _tcdt    /* IO timer */
__IO_EXTERN __io TCCSSTR _tccs;  
#define TCCS _tccs.byte
#define TCCS_CLK0 _tccs.bit._CLK0
#define TCCS_CLK1 _tccs.bit._CLK1
#define TCCS_CLR _tccs.bit._CLR
#define TCCS_MODE _tccs.bit._MODE
#define TCCS_STOP _tccs.bit._STOP
#define TCCS_IVFE _tccs.bit._IVFE
#define TCCS_IVF _tccs.bit._IVF
#define TCCS_CLK _tccs.bitc._CLK
__IO_EXTERN __io ROMMSTR _romm;   /*  ROM Mirror */
#define ROMM _romm.byte
#define ROMM_MI _romm.bit._MI
__IO_EXTERN __io PACSRSTR _pacsr;   /*  ROM Correction */
#define PACSR _pacsr.byte
#define PACSR_AD0E _pacsr.bit._AD0E
#define PACSR_AD1E _pacsr.bit._AD1E
__IO_EXTERN __io DIRRSTR _dirr;  
#define DIRR _dirr.byte
#define DIRR_R0 _dirr.bit._R0
__IO_EXTERN __io LPMCRSTR _lpmcr;  
#define LPMCR _lpmcr.byte
#define LPMCR_SSR _lpmcr.bit._SSR
#define LPMCR_CG0 _lpmcr.bit._CG0
#define LPMCR_CG1 _lpmcr.bit._CG1
#define LPMCR_TMD _lpmcr.bit._TMD
#define LPMCR_RST _lpmcr.bit._RST
#define LPMCR_SPL _lpmcr.bit._SPL
#define LPMCR_SLP _lpmcr.bit._SLP
#define LPMCR_STP _lpmcr.bit._STP
#define LPMCR_CG _lpmcr.bitc._CG
__IO_EXTERN __io CKSCRSTR _ckscr;  
#define CKSCR _ckscr.byte
#define CKSCR_CS0 _ckscr.bit._CS0
#define CKSCR_CS1 _ckscr.bit._CS1
#define CKSCR_MCS _ckscr.bit._MCS
#define CKSCR_SCS _ckscr.bit._SCS
#define CKSCR_WS0 _ckscr.bit._WS0
#define CKSCR_WS1 _ckscr.bit._WS1
#define CKSCR_MCM _ckscr.bit._MCM
#define CKSCR_SCM _ckscr.bit._SCM
#define CKSCR_CS _ckscr.bitc._CS
#define CKSCR_WS _ckscr.bitc._WS
__IO_EXTERN __io IO_BYTE _arsr;
#define ARSR _arsr    /* External Bus I/F */
__IO_EXTERN __io IO_BYTE _hacr;
#define HACR _hacr   
__IO_EXTERN __io IO_BYTE _ecsr;
#define ECSR _ecsr   
__IO_EXTERN __io WDTCSTR _wdtc;  
#define WDTC _wdtc.byte
#define WDTC_WT0 _wdtc.bit._WT0
#define WDTC_WT1 _wdtc.bit._WT1
#define WDTC_WTE _wdtc.bit._WTE
#define WDTC_SRST _wdtc.bit._SRST
#define WDTC_ERST _wdtc.bit._ERST
#define WDTC_WRST _wdtc.bit._WRST
#define WDTC_STBR _wdtc.bit._STBR
#define WDTC_PONR _wdtc.bit._PONR
#define WDTC_WT _wdtc.bitc._WT
__IO_EXTERN __io TBTCSTR _tbtc;  
#define TBTC _tbtc.byte
#define TBTC_TBC0 _tbtc.bit._TBC0
#define TBTC_TBC1 _tbtc.bit._TBC1
#define TBTC_TBR _tbtc.bit._TBR
#define TBTC_TBOF _tbtc.bit._TBOF
#define TBTC_TBIE _tbtc.bit._TBIE
#define TBTC_TBC _tbtc.bitc._TBC
__IO_EXTERN __io WTCSTR _wtc;  
#define WTC _wtc.byte
#define WTC_WTC0 _wtc.bit._WTC0
#define WTC_WTC1 _wtc.bit._WTC1
#define WTC_WTC2 _wtc.bit._WTC2
#define WTC_WTR _wtc.bit._WTR
#define WTC_WTOF _wtc.bit._WTOF
#define WTC_WTIE _wtc.bit._WTIE
#define WTC_SCE _wtc.bit._SCE
#define WTC_WDCS _wtc.bit._WDCS
__IO_EXTERN __io FMCSSTR _fmcs;   /* Flash Control Register */
#define FMCS _fmcs.byte
#define FMCS_LPM0 _fmcs.bit._LPM0
#define FMCS_LPM1 _fmcs.bit._LPM1
#define FMCS_RDY _fmcs.bit._RDY
#define FMCS_WE _fmcs.bit._WE
#define FMCS_RDYINT _fmcs.bit._RDYINT
#define FMCS_INTE _fmcs.bit._INTE
/* include : icr.h */

#ifndef __ICR_H
#define __ICR_H

typedef union{  
    unsigned char    byte;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      const unsigned char ICS3     :1;
      const unsigned char ICS2     :1;
      const unsigned char ICS1     :1;
      const unsigned char ICS0     :1;
      const unsigned char ISE      :1;
      const unsigned char IL2      :1;
      const unsigned char IL1      :1;
      const unsigned char IL0      :1;
#else
      const unsigned char IL0      :1;
      const unsigned char IL1      :1;
      const unsigned char IL2      :1;
      const unsigned char ISE      :1;
      const unsigned char ICS0     :1;
      const unsigned char ICS1     :1;
      const unsigned char ICS2     :1;
      const unsigned char ICS3     :1;
#endif
    }bit;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      const unsigned char    :2;
      const unsigned char S1 :1;
      const unsigned char S0 :1;
#else
      const unsigned char    :4;
      const unsigned char S0 :1;
      const unsigned char S1 :1;
#endif
    }bitrd;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      const unsigned char ICS      :4;
      const unsigned char :1;
      const unsigned char IL       :3;
#else
      const unsigned char IL       :3;
      const unsigned char :1;
      const unsigned char ICS      :4;
#endif
    }bitc;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      const unsigned char    :2;
      const unsigned char S  :2;
#else
      const unsigned char    :4;
      const unsigned char S  :2;
#endif
    }bitcrd;
 }ICRSTR;

__IO_EXTERN __io ICRSTR _icr[16];

#define ICR(i)        _icr[i].byte
#define ICR_IL0(i)    _icr[i].bit.IL0
#define ICR_IL1(i)    _icr[i].bit.IL1
#define ICR_IL2(i)    _icr[i].bit.IL2
#define ICR_ISE(i)    _icr[i].bit.ISE
#define ICR_ICS0(i)   _icr[i].bit.ICS0
#define ICR_ICS1(i)   _icr[i].bit.ICS1
#define ICR_ICS2(i)   _icr[i].bit.ICS2
#define ICR_ICS3(i)   _icr[i].bit.ICS3
#define ICR_IL(i)     _icr[i].bitc.IL
#define ICR_ICS(i)    _icr[i].bitc.ICS
#define ICR_S0(i)     _icr[i].bitrd.S0
#define ICR_S1(i)     _icr[i].bitrd.S1
#define ICR_S(i)      _icr[i].bitcrd.S

#define ICR00       _icr[0].byte
#define ICR00_IL0   _icr[0].bit.IL0
#define ICR00_IL1   _icr[0].bit.IL1
#define ICR00_IL2   _icr[0].bit.IL2
#define ICR00_ISE   _icr[0].bit.ISE
#define ICR00_ICS0  _icr[0].bit.ICS0
#define ICR00_ICS1  _icr[0].bit.ICS1
#define ICR00_ICS2  _icr[0].bit.ICS2
#define ICR00_ICS3  _icr[0].bit.ICS3
#define ICR00_IL    _icr[0].bitc.IL
#define ICR00_ICS   _icr[0].bitc.ICS
#define ICR00_S0    _icr[0].bitrd.S0
#define ICR00_S1    _icr[0].bitrd.S1
#define ICR00_S     _icr[0].bitcrd.S

#define ICR01       _icr[1].byte
#define ICR01_IL0   _icr[1].bit.IL0
#define ICR01_IL1   _icr[1].bit.IL1
#define ICR01_IL2   _icr[1].bit.IL2
#define ICR01_ISE   _icr[1].bit.ISE
#define ICR01_ICS0  _icr[1].bit.ICS0
#define ICR01_ICS1  _icr[1].bit.ICS1
#define ICR01_ICS2  _icr[1].bit.ICS2
#define ICR01_ICS3  _icr[1].bit.ICS3
#define ICR01_IL    _icr[1].bitc.IL
#define ICR01_ICS   _icr[1].bitc.ICS
#define ICR01_S0    _icr[1].bitrd.S0
#define ICR01_S1    _icr[1].bitrd.S1
#define ICR01_S     _icr[1].bitcrd.S

#define ICR02       _icr[2].byte
#define ICR02_IL0   _icr[2].bit.IL0
#define ICR02_IL1   _icr[2].bit.IL1
#define ICR02_IL2   _icr[2].bit.IL2
#define ICR02_ISE   _icr[2].bit.ISE
#define ICR02_ICS0  _icr[2].bit.ICS0
#define ICR02_ICS1  _icr[2].bit.ICS1
#define ICR02_ICS2  _icr[2].bit.ICS2
#define ICR02_ICS3  _icr[2].bit.ICS3
#define ICR02_IL    _icr[2].bitc.IL
#define ICR02_ICS   _icr[2].bitc.ICS
#define ICR02_S0    _icr[2].bitrd.S0
#define ICR02_S1    _icr[2].bitrd.S1
#define ICR02_S     _icr[2].bitcrd.S

#define ICR03       _icr[3].byte
#define ICR03_IL0   _icr[3].bit.IL0
#define ICR03_IL1   _icr[3].bit.IL1
#define ICR03_IL2   _icr[3].bit.IL2
#define ICR03_ISE   _icr[3].bit.ISE
#define ICR03_ICS0  _icr[3].bit.ICS0
#define ICR03_ICS1  _icr[3].bit.ICS1
#define ICR03_ICS2  _icr[3].bit.ICS2
#define ICR03_ICS3  _icr[3].bit.ICS3
#define ICR03_IL    _icr[3].bitc.IL
#define ICR03_ICS   _icr[3].bitc.ICS
#define ICR03_S0    _icr[3].bitrd.S0
#define ICR03_S1    _icr[3].bitrd.S1
#define ICR03_S     _icr[3].bitcrd.S

#define ICR04       _icr[4].byte
#define ICR04_IL4   _icr[4].bit.IL0
#define ICR04_IL1   _icr[4].bit.IL1
#define ICR04_IL2   _icr[4].bit.IL2
#define ICR04_ISE   _icr[4].bit.ISE
#define ICR04_ICS4  _icr[4].bit.ICS0
#define ICR04_ICS1  _icr[4].bit.ICS1
#define ICR04_ICS2  _icr[4].bit.ICS2
#define ICR04_ICS3  _icr[4].bit.ICS3
#define ICR04_IL    _icr[4].bitc.IL
#define ICR04_ICS   _icr[4].bitc.ICS
#define ICR04_S4    _icr[4].bitrd.S0
#define ICR04_S1    _icr[4].bitrd.S1
#define ICR04_S     _icr[4].bitcrd.S

#define ICR05       _icr[5].byte
#define ICR05_IL0   _icr[5].bit.IL0
#define ICR05_IL1   _icr[5].bit.IL1
#define ICR05_IL2   _icr[5].bit.IL2
#define ICR05_ISE   _icr[5].bit.ISE
#define ICR05_ICS0  _icr[5].bit.ICS0
#define ICR05_ICS1  _icr[5].bit.ICS1
#define ICR05_ICS2  _icr[5].bit.ICS2
#define ICR05_ICS3  _icr[5].bit.ICS3
#define ICR05_IL    _icr[5].bitc.IL
#define ICR05_ICS   _icr[5].bitc.ICS
#define ICR05_S0    _icr[5].bitrd.S0
#define ICR05_S1    _icr[5].bitrd.S1
#define ICR05_S     _icr[5].bitcrd.S

#define ICR06       _icr[6].byte
#define ICR06_IL0   _icr[6].bit.IL0
#define ICR06_IL1   _icr[6].bit.IL1
#define ICR06_IL2   _icr[6].bit.IL2
#define ICR06_ISE   _icr[6].bit.ISE
#define ICR06_ICS0  _icr[6].bit.ICS0
#define ICR06_ICS1  _icr[6].bit.ICS1
#define ICR06_ICS2  _icr[6].bit.ICS2
#define ICR06_ICS3  _icr[6].bit.ICS3
#define ICR06_IL    _icr[6].bitc.IL
#define ICR06_ICS   _icr[6].bitc.ICS
#define ICR06_S0    _icr[6].bitrd.S0
#define ICR06_S1    _icr[6].bitrd.S1
#define ICR06_S     _icr[6].bitcrd.S

#define ICR07       _icr[7].byte
#define ICR07_IL0   _icr[7].bit.IL0
#define ICR07_IL1   _icr[7].bit.IL1
#define ICR07_IL2   _icr[7].bit.IL2
#define ICR07_ISE   _icr[7].bit.ISE
#define ICR07_ICS0  _icr[7].bit.ICS0
#define ICR07_ICS1  _icr[7].bit.ICS1
#define ICR07_ICS2  _icr[7].bit.ICS2
#define ICR07_ICS3  _icr[7].bit.ICS3
#define ICR07_IL    _icr[7].bitc.IL
#define ICR07_ICS   _icr[7].bitc.ICS
#define ICR07_S0    _icr[7].bitrd.S0
#define ICR07_S1    _icr[7].bitrd.S1
#define ICR07_S     _icr[7].bitcrd.S

#define ICR08       _icr[8].byte
#define ICR08_IL0   _icr[8].bit.IL0
#define ICR08_IL1   _icr[8].bit.IL1
#define ICR08_IL2   _icr[8].bit.IL2
#define ICR08_ISE   _icr[8].bit.ISE
#define ICR08_ICS0  _icr[8].bit.ICS0
#define ICR08_ICS1  _icr[8].bit.ICS1
#define ICR08_ICS2  _icr[8].bit.ICS2
#define ICR08_ICS3  _icr[8].bit.ICS3
#define ICR08_IL    _icr[8].bitc.IL
#define ICR08_ICS   _icr[8].bitc.ICS
#define ICR08_S0    _icr[8].bitrd.S0
#define ICR08_S1    _icr[8].bitrd.S1
#define ICR08_S     _icr[8].bitcrd.S

#define ICR09       _icr[9].byte
#define ICR09_IL0   _icr[9].bit.IL0
#define ICR09_IL1   _icr[9].bit.IL1
#define ICR09_IL2   _icr[9].bit.IL2
#define ICR09_ISE   _icr[9].bit.ISE
#define ICR09_ICS0  _icr[9].bit.ICS0
#define ICR09_ICS1  _icr[9].bit.ICS1
#define ICR09_ICS2  _icr[9].bit.ICS2
#define ICR09_ICS3  _icr[9].bit.ICS3
#define ICR09_IL    _icr[9].bitc.IL
#define ICR09_ICS   _icr[9].bitc.ICS
#define ICR09_S0    _icr[9].bitrd.S0
#define ICR09_S1    _icr[9].bitrd.S1
#define ICR09_S     _icr[9].bitcrd.S

#define ICR10       _icr[10].byte
#define ICR10_IL0   _icr[10].bit.IL0
#define ICR10_IL1   _icr[10].bit.IL1
#define ICR10_IL2   _icr[10].bit.IL2
#define ICR10_ISE   _icr[10].bit.ISE
#define ICR10_ICS0  _icr[10].bit.ICS0
#define ICR10_ICS1  _icr[10].bit.ICS1
#define ICR10_ICS2  _icr[10].bit.ICS2
#define ICR10_ICS3  _icr[10].bit.ICS3
#define ICR10_IL    _icr[10].bitc.IL
#define ICR10_ICS   _icr[10].bitc.ICS
#define ICR10_S0    _icr[10].bitrd.S0
#define ICR10_S1    _icr[10].bitrd.S1
#define ICR10_S     _icr[10].bitcrd.S

#define ICR11       _icr[11].byte
#define ICR11_IL0   _icr[11].bit.IL0
#define ICR11_IL1   _icr[11].bit.IL1
#define ICR11_IL2   _icr[11].bit.IL2
#define ICR11_ISE   _icr[11].bit.ISE
#define ICR11_ICS0  _icr[11].bit.ICS0
#define ICR11_ICS1  _icr[11].bit.ICS1
#define ICR11_ICS2  _icr[11].bit.ICS2
#define ICR11_ICS3  _icr[11].bit.ICS3
#define ICR11_IL    _icr[11].bitc.IL
#define ICR11_ICS   _icr[11].bitc.ICS
#define ICR11_S0    _icr[11].bitrd.S0
#define ICR11_S1    _icr[11].bitrd.S1
#define ICR11_S     _icr[11].bitcrd.S

#define ICR12       _icr[12].byte
#define ICR12_IL0   _icr[12].bit.IL0
#define ICR12_IL1   _icr[12].bit.IL1
#define ICR12_IL2   _icr[12].bit.IL2
#define ICR12_ISE   _icr[12].bit.ISE
#define ICR12_ICS0  _icr[12].bit.ICS0
#define ICR12_ICS1  _icr[12].bit.ICS1
#define ICR12_ICS2  _icr[12].bit.ICS2
#define ICR12_ICS3  _icr[12].bit.ICS3
#define ICR12_IL    _icr[12].bitc.IL
#define ICR12_ICS   _icr[12].bitc.ICS
#define ICR12_S0    _icr[12].bitrd.S0
#define ICR12_S1    _icr[12].bitrd.S1
#define ICR12_S     _icr[12].bitcrd.S

#define ICR13       _icr[13].byte
#define ICR13_IL0   _icr[13].bit.IL0
#define ICR13_IL1   _icr[13].bit.IL1
#define ICR13_IL2   _icr[13].bit.IL2
#define ICR13_ISE   _icr[13].bit.ISE
#define ICR13_ICS0  _icr[13].bit.ICS0
#define ICR13_ICS1  _icr[13].bit.ICS1
#define ICR13_ICS2  _icr[13].bit.ICS2
#define ICR13_ICS3  _icr[13].bit.ICS3
#define ICR13_IL    _icr[13].bitc.IL
#define ICR13_ICS   _icr[13].bitc.ICS
#define ICR13_S0    _icr[13].bitrd.S0
#define ICR13_S1    _icr[13].bitrd.S1
#define ICR13_S     _icr[13].bitcrd.S

#define ICR14       _icr[14].byte
#define ICR14_IL0   _icr[14].bit.IL0
#define ICR14_IL1   _icr[14].bit.IL1
#define ICR14_IL2   _icr[14].bit.IL2
#define ICR14_ISE   _icr[14].bit.ISE
#define ICR14_ICS0  _icr[14].bit.ICS0
#define ICR14_ICS1  _icr[14].bit.ICS1
#define ICR14_ICS2  _icr[14].bit.ICS2
#define ICR14_ICS3  _icr[14].bit.ICS3
#define ICR14_IL    _icr[14].bitc.IL
#define ICR14_ICS   _icr[14].bitc.ICS
#define ICR14_S0    _icr[14].bitrd.S0
#define ICR14_S1    _icr[14].bitrd.S1
#define ICR14_S     _icr[14].bitcrd.S

#define ICR15       _icr[15].byte
#define ICR15_IL0   _icr[15].bit.IL0
#define ICR15_IL1   _icr[15].bit.IL1
#define ICR15_IL2   _icr[15].bit.IL2
#define ICR15_ISE   _icr[15].bit.ISE
#define ICR15_ICS0  _icr[15].bit.ICS0
#define ICR15_ICS1  _icr[15].bit.ICS1
#define ICR15_ICS2  _icr[15].bit.ICS2
#define ICR15_ICS3  _icr[15].bit.ICS3
#define ICR15_IL    _icr[15].bitc.IL
#define ICR15_ICS   _icr[15].bitc.ICS
#define ICR15_S0    _icr[15].bitrd.S0
#define ICR15_S1    _icr[15].bitrd.S1
#define ICR15_S     _icr[15].bitcrd.S


#endif /*  __ICR_H */
__IO_EXTENDED IO_BYTE _padr0_l;
#define PADR0_L _padr0_l    /* ROM CORRECTION */
__IO_EXTENDED IO_BYTE _padr0_m;
#define PADR0_M _padr0_m   
__IO_EXTENDED IO_BYTE _padr0_h;
#define PADR0_H _padr0_h   
__IO_EXTENDED IO_BYTE _padr1_l;
#define PADR1_L _padr1_l   
__IO_EXTENDED IO_BYTE _padr1_m;
#define PADR1_M _padr1_m   
__IO_EXTENDED IO_BYTE _padr1_h;
#define PADR1_H _padr1_h   
__IO_EXTENDED IO_LWORD _prl01;
#define PRL01 _prl01    /*  PPG data */
__IO_EXTENDED IO_WORD _prl0;
#define PRL0 _prl0   
__IO_EXTENDED IO_BYTE _prll0;
#define PRLL0 _prll0   
__IO_EXTENDED IO_BYTE _prlh0;
#define PRLH0 _prlh0   
__IO_EXTENDED IO_WORD _prl1;
#define PRL1 _prl1   
__IO_EXTENDED IO_BYTE _prll1;
#define PRLL1 _prll1   
__IO_EXTENDED IO_BYTE _prlh1;
#define PRLH1 _prlh1   
__IO_EXTENDED IO_LWORD _prl23;
#define PRL23 _prl23   
__IO_EXTENDED IO_WORD _prl2;
#define PRL2 _prl2   
__IO_EXTENDED IO_BYTE _prll2;
#define PRLL2 _prll2   
__IO_EXTENDED IO_BYTE _prlh2;
#define PRLH2 _prlh2   
__IO_EXTENDED IO_WORD _prl3;
#define PRL3 _prl3   
__IO_EXTENDED IO_BYTE _prll3;
#define PRLL3 _prll3   
__IO_EXTENDED IO_BYTE _prlh3;
#define PRLH3 _prlh3   
__IO_EXTENDED IO_LWORD _prl45;
#define PRL45 _prl45   
__IO_EXTENDED IO_WORD _plr4;
#define PLR4 _plr4   
__IO_EXTENDED IO_BYTE _prll4;
#define PRLL4 _prll4   
__IO_EXTENDED IO_BYTE _prlh4;
#define PRLH4 _prlh4   
__IO_EXTENDED IO_WORD _prl5;
#define PRL5 _prl5   
__IO_EXTENDED IO_BYTE _prll5;
#define PRLL5 _prll5   
__IO_EXTENDED IO_BYTE _prlh5;
#define PRLH5 _prlh5   
__IO_EXTENDED IO_LWORD _prl67;
#define PRL67 _prl67   
__IO_EXTENDED IO_WORD _prl6;
#define PRL6 _prl6   
__IO_EXTENDED IO_BYTE _prll6;
#define PRLL6 _prll6   
__IO_EXTENDED IO_BYTE _prlh6;
#define PRLH6 _prlh6   
__IO_EXTENDED IO_WORD _prl7;
#define PRL7 _prl7   
__IO_EXTENDED IO_BYTE _prll7;
#define PRLL7 _prll7   
__IO_EXTENDED IO_BYTE _prlh7;
#define PRLH7 _prlh7   
__IO_EXTENDED IO_WORD _ipcp0;
#define IPCP0 _ipcp0   
__IO_EXTENDED IO_WORD _ipcp1;
#define IPCP1 _ipcp1   
__IO_EXTENDED IO_WORD _ipcp2;
#define IPCP2 _ipcp2   
__IO_EXTENDED IO_WORD _ipcp3;
#define IPCP3 _ipcp3   
__IO_EXTENDED IO_WORD _ipcp4;
#define IPCP4 _ipcp4   
__IO_EXTENDED IO_WORD _ipcp5;
#define IPCP5 _ipcp5   
__IO_EXTENDED IO_WORD _ipcp6;
#define IPCP6 _ipcp6   
__IO_EXTENDED IO_WORD _ipcp7;
#define IPCP7 _ipcp7   
__IO_EXTENDED IO_WORD _occp0;
#define OCCP0 _occp0   
__IO_EXTENDED IO_WORD _occp1;
#define OCCP1 _occp1   
__IO_EXTENDED IO_WORD _occp2;
#define OCCP2 _occp2   
__IO_EXTENDED IO_WORD _occp3;
#define OCCP3 _occp3   
/* include : CANSTR.H */

#ifndef __CANSTR
#define __CANSTR

typedef struct
{
  union{   
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD BVAL15 :1;
      IO_WORD BVAL14 :1;
      IO_WORD BVAL13 :1;
      IO_WORD BVAL12 :1;
      IO_WORD BVAL11 :1;
      IO_WORD BVAL10 :1;
      IO_WORD BVAL9 :1;
      IO_WORD BVAL8 :1;
      IO_WORD BVAL7 :1;
      IO_WORD BVAL6 :1;
      IO_WORD BVAL5 :1;
      IO_WORD BVAL4 :1;
      IO_WORD BVAL3 :1;
      IO_WORD BVAL2 :1;
      IO_WORD BVAL1 :1;
      IO_WORD BVAL0 :1;
#else
      IO_WORD BVAL0 :1;
      IO_WORD BVAL1 :1;
      IO_WORD BVAL2 :1;
      IO_WORD BVAL3 :1;
      IO_WORD BVAL4 :1;
      IO_WORD BVAL5 :1;
      IO_WORD BVAL6 :1;
      IO_WORD BVAL7 :1;
      IO_WORD BVAL8 :1;
      IO_WORD BVAL9 :1;
      IO_WORD BVAL10 :1;
      IO_WORD BVAL11 :1;
      IO_WORD BVAL12 :1;
      IO_WORD BVAL13 :1;
      IO_WORD BVAL14 :1;
      IO_WORD BVAL15 :1;
#endif
    } bit;
  } bvalr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD TREQ15 :1;
      IO_WORD TREQ14 :1;
      IO_WORD TREQ13 :1;
      IO_WORD TREQ12 :1;
      IO_WORD TREQ11 :1;
      IO_WORD TREQ10 :1;
      IO_WORD TREQ9 :1;
      IO_WORD TREQ8 :1;
      IO_WORD TREQ7 :1;
      IO_WORD TREQ6 :1;
      IO_WORD TREQ5 :1;
      IO_WORD TREQ4 :1;
      IO_WORD TREQ3 :1;
      IO_WORD TREQ2 :1;
      IO_WORD TREQ1 :1;
      IO_WORD TREQ0 :1;
#else
      IO_WORD TREQ0 :1;
      IO_WORD TREQ1 :1;
      IO_WORD TREQ2 :1;
      IO_WORD TREQ3 :1;
      IO_WORD TREQ4 :1;
      IO_WORD TREQ5 :1;
      IO_WORD TREQ6 :1;
      IO_WORD TREQ7 :1;
      IO_WORD TREQ8 :1;
      IO_WORD TREQ9 :1;
      IO_WORD TREQ10 :1;
      IO_WORD TREQ11 :1;
      IO_WORD TREQ12 :1;
      IO_WORD TREQ13 :1;
      IO_WORD TREQ14 :1;
      IO_WORD TREQ15 :1;
#endif
    } bit;
  } treqr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD TCAN15 :1;
      IO_WORD TCAN14 :1;
      IO_WORD TCAN13 :1;
      IO_WORD TCAN12 :1;
      IO_WORD TCAN11 :1;
      IO_WORD TCAN10 :1;
      IO_WORD TCAN9 :1;
      IO_WORD TCAN8 :1;
      IO_WORD TCAN7 :1;
      IO_WORD TCAN6 :1;
      IO_WORD TCAN5 :1;
      IO_WORD TCAN4 :1;
      IO_WORD TCAN3 :1;
      IO_WORD TCAN2 :1;
      IO_WORD TCAN1 :1;
      IO_WORD TCAN0 :1;
#else
      IO_WORD TCAN0 :1;
      IO_WORD TCAN1 :1;
      IO_WORD TCAN2 :1;
      IO_WORD TCAN3 :1;
      IO_WORD TCAN4 :1;
      IO_WORD TCAN5 :1;
      IO_WORD TCAN6 :1;
      IO_WORD TCAN7 :1;
      IO_WORD TCAN8 :1;
      IO_WORD TCAN9 :1;
      IO_WORD TCAN10 :1;
      IO_WORD TCAN11 :1;
      IO_WORD TCAN12 :1;
      IO_WORD TCAN13 :1;
      IO_WORD TCAN14 :1;
      IO_WORD TCAN15 :1;
#endif
    } bit;
  } tcanr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD TC15 :1;
      IO_WORD TC14 :1;
      IO_WORD TC13 :1;
      IO_WORD TC12 :1;
      IO_WORD TC11 :1;
      IO_WORD TC10 :1;
      IO_WORD TC9 :1;
      IO_WORD TC8 :1;
      IO_WORD TC7 :1;
      IO_WORD TC6 :1;
      IO_WORD TC5 :1;
      IO_WORD TC4 :1;
      IO_WORD TC3 :1;
      IO_WORD TC2 :1;
      IO_WORD TC1 :1;
      IO_WORD TC0 :1;
#else
      IO_WORD TC0 :1;
      IO_WORD TC1 :1;
      IO_WORD TC2 :1;
      IO_WORD TC3 :1;
      IO_WORD TC4 :1;
      IO_WORD TC5 :1;
      IO_WORD TC6 :1;
      IO_WORD TC7 :1;
      IO_WORD TC8 :1;
      IO_WORD TC9 :1;
      IO_WORD TC10 :1;
      IO_WORD TC11 :1;
      IO_WORD TC12 :1;
      IO_WORD TC13 :1;
      IO_WORD TC14 :1;
      IO_WORD TC15 :1;
#endif
    } bit;
 } tcr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD RC15 :1;
      IO_WORD RC14 :1;
      IO_WORD RC13 :1;
      IO_WORD RC12 :1;
      IO_WORD RC11 :1;
      IO_WORD RC10 :1;
      IO_WORD RC9 :1;
      IO_WORD RC8 :1;
      IO_WORD RC7 :1;
      IO_WORD RC6 :1;
      IO_WORD RC5 :1;
      IO_WORD RC4 :1;
      IO_WORD RC3 :1;
      IO_WORD RC2 :1;
      IO_WORD RC1 :1;
      IO_WORD RC0 :1;
#else
      IO_WORD RC0 :1;
      IO_WORD RC1 :1;
      IO_WORD RC2 :1;
      IO_WORD RC3 :1;
      IO_WORD RC4 :1;
      IO_WORD RC5 :1;
      IO_WORD RC6 :1;
      IO_WORD RC7 :1;
      IO_WORD RC8 :1;
      IO_WORD RC9 :1;
      IO_WORD RC10 :1;
      IO_WORD RC11 :1;
      IO_WORD RC12 :1;
      IO_WORD RC13 :1;
      IO_WORD RC14 :1;
      IO_WORD RC15 :1;
#endif
    } bit;
  } rcr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD RRTR15 :1;
      IO_WORD RRTR14 :1;
      IO_WORD RRTR13 :1;
      IO_WORD RRTR12 :1;
      IO_WORD RRTR11 :1;
      IO_WORD RRTR10 :1;
      IO_WORD RRTR9 :1;
      IO_WORD RRTR8 :1;
      IO_WORD RRTR7 :1;
      IO_WORD RRTR6 :1;
      IO_WORD RRTR5 :1;
      IO_WORD RRTR4 :1;
      IO_WORD RRTR3 :1;
      IO_WORD RRTR2 :1;
      IO_WORD RRTR1 :1;
      IO_WORD RRTR0 :1;
#else
      IO_WORD RRTR0 :1;
      IO_WORD RRTR1 :1;
      IO_WORD RRTR2 :1;
      IO_WORD RRTR3 :1;
      IO_WORD RRTR4 :1;
      IO_WORD RRTR5 :1;
      IO_WORD RRTR6 :1;
      IO_WORD RRTR7 :1;
      IO_WORD RRTR8 :1;
      IO_WORD RRTR9 :1;
      IO_WORD RRTR10 :1;
      IO_WORD RRTR11 :1;
      IO_WORD RRTR12 :1;
      IO_WORD RRTR13 :1;
      IO_WORD RRTR14 :1;
      IO_WORD RRTR15 :1;
#endif
    } bit;
  } rrtrr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD ROVR15 :1;
      IO_WORD ROVR14 :1;
      IO_WORD ROVR13 :1;
      IO_WORD ROVR12 :1;
      IO_WORD ROVR11 :1;
      IO_WORD ROVR10 :1;
      IO_WORD ROVR9 :1;
      IO_WORD ROVR8 :1;
      IO_WORD ROVR7 :1;
      IO_WORD ROVR6 :1;
      IO_WORD ROVR5 :1;
      IO_WORD ROVR4 :1;
      IO_WORD ROVR3 :1;
      IO_WORD ROVR2 :1;
      IO_WORD ROVR1 :1;
      IO_WORD ROVR0 :1;
#else
      IO_WORD ROVR0 :1;
      IO_WORD ROVR1 :1;
      IO_WORD ROVR2 :1;
      IO_WORD ROVR3 :1;
      IO_WORD ROVR4 :1;
      IO_WORD ROVR5 :1;
      IO_WORD ROVR6 :1;
      IO_WORD ROVR7 :1;
      IO_WORD ROVR8 :1;
      IO_WORD ROVR9 :1;
      IO_WORD ROVR10 :1;
      IO_WORD ROVR11 :1;
      IO_WORD ROVR12 :1;
      IO_WORD ROVR13 :1;
      IO_WORD ROVR14 :1;
      IO_WORD ROVR15 :1;
#endif
    } bit;
  } rovrr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD RIE15 :1;
      IO_WORD RIE14 :1;
      IO_WORD RIE13 :1;
      IO_WORD RIE12 :1;
      IO_WORD RIE11 :1;
      IO_WORD RIE10 :1;
      IO_WORD RIE9 :1;
      IO_WORD RIE8 :1;
      IO_WORD RIE7 :1;
      IO_WORD RIE6 :1;
      IO_WORD RIE5 :1;
      IO_WORD RIE4 :1;
      IO_WORD RIE3 :1;
      IO_WORD RIE2 :1;
      IO_WORD RIE1 :1;
      IO_WORD RIE0 :1;
#else
      IO_WORD RIE0 :1;
      IO_WORD RIE1 :1;
      IO_WORD RIE2 :1;
      IO_WORD RIE3 :1;
      IO_WORD RIE4 :1;
      IO_WORD RIE5 :1;
      IO_WORD RIE6 :1;
      IO_WORD RIE7 :1;
      IO_WORD RIE8 :1;
      IO_WORD RIE9 :1;
      IO_WORD RIE10 :1;
      IO_WORD RIE11 :1;
      IO_WORD RIE12 :1;
      IO_WORD RIE13 :1;
      IO_WORD RIE14 :1;
      IO_WORD RIE15 :1;
#endif
    } bit;
  } rier;
} CANLSTR;

typedef struct
{
  union{  
    IO_WORD word;
      struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD TS 	:1;
      IO_WORD RS 	:1;
      IO_WORD  	:1;
      IO_WORD  	:1;
      IO_WORD  	:1;
      IO_WORD NT 	:1;
      IO_WORD NS1 	:1;
      IO_WORD NS0 	:1;
      IO_WORD TOE 	:1;
      IO_WORD  	:1;
      IO_WORD      :1;
      IO_WORD      :1;
      IO_WORD      :1;
      IO_WORD NIE  :1;
      IO_WORD      :1;
      IO_WORD HALT :1;
#else
      IO_WORD HALT :1;
      IO_WORD      :1;
      IO_WORD NIE  :1;
      IO_WORD      :1;
      IO_WORD      :1;
      IO_WORD      :1;
      IO_WORD  	:1;
      IO_WORD TOE 	:1;
      IO_WORD NS0 	:1;
      IO_WORD NS1 	:1;
      IO_WORD NT 	:1;
      IO_WORD  	:1;
      IO_WORD  	:1;
      IO_WORD  	:1;
      IO_WORD RS 	:1;
      IO_WORD TS 	:1;
#endif
    }bit;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD 		:6;
      IO_WORD NS 	:2;
#else
      IO_WORD 		:8;
      IO_WORD NS 	:2;
#endif
    }bitc;
  }csr;
  union{  
    IO_WORD word;
    IO_WORD byte;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD NTE  :1;
      IO_WORD TCE  :1;
      IO_WORD RCE  :1;
      IO_WORD      :1;
      IO_WORD MBP3 :1;
      IO_WORD MBP2 :1;
      IO_WORD MBP1 :1;
      IO_WORD MBP0 :1;
#else
      IO_WORD MBP0 :1;
      IO_WORD MBP1 :1;
      IO_WORD MBP2 :1;
      IO_WORD MBP3 :1;
      IO_WORD      :1;
      IO_WORD RCE  :1;
      IO_WORD TCE  :1;
      IO_WORD NTE  :1;
#endif
    } bit;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD      :4;
      IO_WORD MBP  :4;
#else
      IO_WORD MBP  :4;
#endif
    } bitc;
  } leir;
  const union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD TEC7 :1;
      IO_WORD TEC6 :1;
      IO_WORD TEC5 :1;
      IO_WORD TEC4 :1;
      IO_WORD TEC3 :1;
      IO_WORD TEC2 :1;
      IO_WORD TEC1 :1;
      IO_WORD TEC0 :1;
      IO_WORD REC7 :1;
      IO_WORD REC6 :1;
      IO_WORD REC5 :1;
      IO_WORD REC4 :1;
      IO_WORD REC3 :1;
      IO_WORD REC2 :1;
      IO_WORD REC1 :1;
      IO_WORD REC0 :1;
#else
      IO_WORD REC0 :1;
      IO_WORD REC1 :1;
      IO_WORD REC2 :1;
      IO_WORD REC3 :1;
      IO_WORD REC4 :1;
      IO_WORD REC5 :1;
      IO_WORD REC6 :1;
      IO_WORD REC7 :1;
      IO_WORD TEC0 :1;
      IO_WORD TEC1 :1;
      IO_WORD TEC2 :1;
      IO_WORD TEC3 :1;
      IO_WORD TEC4 :1;
      IO_WORD TEC5 :1;
      IO_WORD TEC6 :1;
      IO_WORD TEC7 :1;
#endif
    }bit;
    struct{
      IO_BYTE REC;
      IO_BYTE TEC;
	    }bitc;
  }rtec;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD      :1;
      IO_WORD TS22 :1;
      IO_WORD TS21 :1;
      IO_WORD TS20 :1;
      IO_WORD TS13 :1;
      IO_WORD TS12 :1;
      IO_WORD TS11 :1;
      IO_WORD TS10 :1;
      IO_WORD RSJ1 :1;
      IO_WORD RSJ0 :1;
      IO_WORD PSC5 :1;
      IO_WORD PSC4 :1;
      IO_WORD PSC3 :1;
      IO_WORD PSC2 :1;
      IO_WORD PSC1 :1;
      IO_WORD PSC0 :1;
#else
      IO_WORD PSC0 :1;
      IO_WORD PSC1 :1;
      IO_WORD PSC2 :1;
      IO_WORD PSC3 :1;
      IO_WORD PSC4 :1;
      IO_WORD PSC5 :1;
      IO_WORD RSJ0 :1;
      IO_WORD RSJ1 :1;
      IO_WORD TS10 :1;
      IO_WORD TS11 :1;
      IO_WORD TS12 :1;
      IO_WORD TS13 :1;
      IO_WORD TS20 :1;
      IO_WORD TS21 :1;
      IO_WORD TS22 :1;
      IO_WORD      :1;
#endif
    } bit;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD     :1;
      IO_WORD TS2 :3;
      IO_WORD TS1 :4;
      IO_WORD RSJ :2;
      IO_WORD PSC :6;
#else
      IO_WORD PSC :6;
      IO_WORD RSJ :2;
      IO_WORD TS1 :4;
      IO_WORD TS2 :3;
#endif
    } bitc;
  } btr;
  union{  
    IO_WORD word;
      struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD IDE15 :1;
      IO_WORD IDE14 :1;
      IO_WORD IDE13 :1;
      IO_WORD IDE12 :1;
      IO_WORD IDE11 :1;
      IO_WORD IDE10 :1;
      IO_WORD IDE9 :1;
      IO_WORD IDE8 :1;
      IO_WORD IDE7 :1;
      IO_WORD IDE6 :1;
      IO_WORD IDE5 :1;
      IO_WORD IDE4 :1;
      IO_WORD IDE3 :1;
      IO_WORD IDE2 :1;
      IO_WORD IDE1 :1;
      IO_WORD IDE0 :1;
#else
      IO_WORD IDE0 :1;
      IO_WORD IDE1 :1;
      IO_WORD IDE2 :1;
      IO_WORD IDE3 :1;
      IO_WORD IDE4 :1;
      IO_WORD IDE5 :1;
      IO_WORD IDE6 :1;
      IO_WORD IDE7 :1;
      IO_WORD IDE8 :1;
      IO_WORD IDE9 :1;
      IO_WORD IDE10 :1;
      IO_WORD IDE11 :1;
      IO_WORD IDE12 :1;
      IO_WORD IDE13 :1;
      IO_WORD IDE14 :1;
      IO_WORD IDE15 :1;
#endif
    } bit;
  } ider;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD TRTR15 :1;
      IO_WORD TRTR14 :1;
      IO_WORD TRTR13 :1;
      IO_WORD TRTR12 :1;
      IO_WORD TRTR11 :1;
      IO_WORD TRTR10 :1;
      IO_WORD TRTR9 :1;
      IO_WORD TRTR8 :1;
      IO_WORD TRTR7 :1;
      IO_WORD TRTR6 :1;
      IO_WORD TRTR5 :1;
      IO_WORD TRTR4 :1;
      IO_WORD TRTR3 :1;
      IO_WORD TRTR2 :1;
      IO_WORD TRTR1 :1;
      IO_WORD TRTR0 :1;
#else
      IO_WORD TRTR0 :1;
      IO_WORD TRTR1 :1;
      IO_WORD TRTR2 :1;
      IO_WORD TRTR3 :1;
      IO_WORD TRTR4 :1;
      IO_WORD TRTR5 :1;
      IO_WORD TRTR6 :1;
      IO_WORD TRTR7 :1;
      IO_WORD TRTR8 :1;
      IO_WORD TRTR9 :1;
      IO_WORD TRTR10 :1;
      IO_WORD TRTR11 :1;
      IO_WORD TRTR12 :1;
      IO_WORD TRTR13 :1;
      IO_WORD TRTR14 :1;
      IO_WORD TRTR15 :1;
#endif
    } bit;
  } trtrr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD RFWT15 :1;
      IO_WORD RFWT14 :1;
      IO_WORD RFWT13 :1;
      IO_WORD RFWT12 :1;
      IO_WORD RFWT11 :1;
      IO_WORD RFWT10 :1;
      IO_WORD RFWT9 :1;
      IO_WORD RFWT8 :1;
      IO_WORD RFWT7 :1;
      IO_WORD RFWT6 :1;
      IO_WORD RFWT5 :1;
      IO_WORD RFWT4 :1;
      IO_WORD RFWT3 :1;
      IO_WORD RFWT2 :1;
      IO_WORD RFWT1 :1;
      IO_WORD RFWT0 :1;
#else
      IO_WORD RFWT0 :1;
      IO_WORD RFWT1 :1;
      IO_WORD RFWT2 :1;
      IO_WORD RFWT3 :1;
      IO_WORD RFWT4 :1;
      IO_WORD RFWT5 :1;
      IO_WORD RFWT6 :1;
      IO_WORD RFWT7 :1;
      IO_WORD RFWT8 :1;
      IO_WORD RFWT9 :1;
      IO_WORD RFWT10 :1;
      IO_WORD RFWT11 :1;
      IO_WORD RFWT12 :1;
      IO_WORD RFWT13 :1;
      IO_WORD RFWT14 :1;
      IO_WORD RFWT15 :1;
#endif
    } bit;
  } rfwtr;
  union{  
    IO_WORD word;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
    IO_WORD TIE15 :1;
    IO_WORD TIE14 :1;
    IO_WORD TIE13 :1;
    IO_WORD TIE12 :1;
    IO_WORD TIE11 :1;
    IO_WORD TIE10 :1;
    IO_WORD TIE9 :1;
    IO_WORD TIE8 :1;
    IO_WORD TIE7 :1;
    IO_WORD TIE6 :1;
    IO_WORD TIE5 :1;
    IO_WORD TIE4 :1;
    IO_WORD TIE3 :1;
    IO_WORD TIE2 :1;
    IO_WORD TIE1 :1;
    IO_WORD TIE0 :1;
#else
    IO_WORD TIE0 :1;
    IO_WORD TIE1 :1;
    IO_WORD TIE2 :1;
    IO_WORD TIE3 :1;
    IO_WORD TIE4 :1;
    IO_WORD TIE5 :1;
    IO_WORD TIE6 :1;
    IO_WORD TIE7 :1;
    IO_WORD TIE8 :1;
    IO_WORD TIE9 :1;
    IO_WORD TIE10 :1;
    IO_WORD TIE11 :1;
    IO_WORD TIE12 :1;
    IO_WORD TIE13 :1;
    IO_WORD TIE14 :1;
    IO_WORD TIE15 :1;
#endif
  } bit;
 } tier;
  union{
    unsigned long     dword;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD    AMS71:1;
      IO_WORD    AMS70:1;
      IO_WORD    AMS61:1;
      IO_WORD    AMS60:1;
      IO_WORD    AMS51:1;
      IO_WORD    AMS50:1;
      IO_WORD    AMS41:1;
      IO_WORD    AMS40:1;
      IO_WORD    AMS31:1;
      IO_WORD    AMS30:1;
      IO_WORD    AMS21:1;
      IO_WORD    AMS20:1;
      IO_WORD    AMS11:1;
      IO_WORD    AMS10:1;
      IO_WORD    AMS01:1;
      IO_WORD    AMS00:1;
#else
      IO_WORD    AMS00:1;
      IO_WORD    AMS01:1;
      IO_WORD    AMS10:1;
      IO_WORD    AMS11:1;
      IO_WORD    AMS20:1;
      IO_WORD    AMS21:1;
      IO_WORD    AMS30:1;
      IO_WORD    AMS31:1;
      IO_WORD    AMS40:1;
      IO_WORD    AMS41:1;
      IO_WORD    AMS50:1;
      IO_WORD    AMS51:1;
      IO_WORD    AMS60:1;
      IO_WORD    AMS61:1;
      IO_WORD    AMS70:1;
      IO_WORD    AMS71:1;
#endif
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD    AMS151:1;
      IO_WORD    AMS150:1;
      IO_WORD    AMS141:1;
      IO_WORD    AMS140:1;
      IO_WORD    AMS131:1;
      IO_WORD    AMS130:1;
      IO_WORD    AMS121:1;
      IO_WORD    AMS120:1;
      IO_WORD    AMS111:1;
      IO_WORD    AMS110:1;
      IO_WORD    AMS101:1;
      IO_WORD    AMS100:1;
      IO_WORD    AMS91:1;
      IO_WORD    AMS90:1;
      IO_WORD    AMS81:1;
      IO_WORD    AMS80:1;
#else
      IO_WORD    AMS80:1;
      IO_WORD    AMS81:1;
      IO_WORD    AMS90:1;
      IO_WORD    AMS91:1;
      IO_WORD    AMS100:1;
      IO_WORD    AMS101:1;
      IO_WORD    AMS110:1;
      IO_WORD    AMS111:1;
      IO_WORD    AMS120:1;
      IO_WORD    AMS121:1;
      IO_WORD    AMS130:1;
      IO_WORD    AMS131:1;
      IO_WORD    AMS140:1;
      IO_WORD    AMS141:1;
      IO_WORD    AMS150:1;
      IO_WORD    AMS151:1;
#endif
    }bit;
    struct{
#if defined(__BITFIELD_ORDER_MSB__)
      IO_WORD    AMS15:2;
      IO_WORD    AMS14:2;
      IO_WORD    AMS13:2;
      IO_WORD    AMS12:2;
      IO_WORD    AMS11:2;
      IO_WORD    AMS10:2;
      IO_WORD    AMS9:2;
      IO_WORD    AMS8:2;
      IO_WORD    AMS7:2;
      IO_WORD    AMS6:2;
      IO_WORD    AMS5:2;
      IO_WORD    AMS4:2;
      IO_WORD    AMS3:2;
      IO_WORD    AMS2:2;
      IO_WORD    AMS1:2;
      IO_WORD    AMS0:2;
#else
      IO_WORD    AMS0:2;
      IO_WORD    AMS1:2;
      IO_WORD    AMS2:2;
      IO_WORD    AMS3:2;
      IO_WORD    AMS4:2;
      IO_WORD    AMS5:2;
      IO_WORD    AMS6:2;
      IO_WORD    AMS7:2;
      IO_WORD    AMS8:2;
      IO_WORD    AMS9:2;
      IO_WORD    AMS10:2;
      IO_WORD    AMS11:2;
      IO_WORD    AMS12:2;
      IO_WORD    AMS13:2;
      IO_WORD    AMS14:2;
      IO_WORD    AMS15:2;
#endif
    } bitc;
  } amsr;
  union {
    unsigned long   dword;
    unsigned short  word;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        IO_WORD AM20 :1;
        IO_WORD AM19 :1;
        IO_WORD AM18 :1;
        IO_WORD AM17 :1;
        IO_WORD AM16 :1;
        IO_WORD AM15 :1;
        IO_WORD AM14 :1;
        IO_WORD AM13 :1;
        IO_WORD AM28 :1;
        IO_WORD AM27 :1;
        IO_WORD AM26 :1;
        IO_WORD AM25 :1;
        IO_WORD AM24 :1;
        IO_WORD AM23 :1;
        IO_WORD AM22 :1;
        IO_WORD AM21 :1;
#else
        IO_WORD AM21 :1;
        IO_WORD AM22 :1;
        IO_WORD AM23 :1;
        IO_WORD AM24 :1;
        IO_WORD AM25 :1;
        IO_WORD AM26 :1;
        IO_WORD AM27 :1;
        IO_WORD AM28 :1;
        IO_WORD AM13 :1;
        IO_WORD AM14 :1;
        IO_WORD AM15 :1;
        IO_WORD AM16 :1;
        IO_WORD AM17 :1;
        IO_WORD AM18 :1;
        IO_WORD AM19 :1;
        IO_WORD AM20 :1;
#endif

#if defined(__BITFIELD_ORDER_MSB__)
        IO_WORD AM4 :1;
        IO_WORD AM3 :1;
        IO_WORD AM2 :1;
        IO_WORD AM1 :1;
        IO_WORD AM0 :1;
        IO_WORD      :3;
        IO_WORD AM12 :1;
        IO_WORD AM11 :1;
        IO_WORD AM10 :1;
        IO_WORD AM9 :1;
        IO_WORD AM8 :1;
        IO_WORD AM7 :1;
        IO_WORD AM6 :1;
        IO_WORD AM5 :1;
#else
        IO_WORD AM5 :1;
        IO_WORD AM6 :1;
        IO_WORD AM7 :1;
        IO_WORD AM8 :1;
        IO_WORD AM9 :1;
        IO_WORD AM10 :1;
        IO_WORD AM11 :1;
        IO_WORD AM12 :1;
        IO_WORD      :3;
        IO_WORD AM0 :1;
        IO_WORD AM1 :1;
        IO_WORD AM2 :1;
        IO_WORD AM3 :1;
        IO_WORD AM4 :1;
#endif
    } bit_ext;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        IO_WORD AM2 :1;
        IO_WORD AM1 :1;
        IO_WORD AM0 :1;
        IO_WORD     :5;
        IO_WORD AM10 :1;
        IO_WORD AM9 :1;
        IO_WORD AM8 :1;
        IO_WORD AM7 :1;
        IO_WORD AM6 :1;
        IO_WORD AM5 :1;
        IO_WORD AM4 :1;
        IO_WORD AM3 :1;
#else
        IO_WORD AM3 :1;
        IO_WORD AM4 :1;
        IO_WORD AM5 :1;
        IO_WORD AM6 :1;
        IO_WORD AM7 :1;
        IO_WORD AM8 :1;
        IO_WORD AM9 :1;
        IO_WORD AM10 :1;
        IO_WORD     :5;
        IO_WORD AM0 :1;
        IO_WORD AM1 :1;
        IO_WORD AM2 :1;
#endif
    } bit_std;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        IO_WORD AM13_20    : 8;
        IO_WORD AM21_28    : 8;
        IO_WORD AM0_4      : 5;
        IO_WORD unused     : 3;            /* unused bits */
        IO_WORD AM5_12     : 8;
#else
        IO_WORD AM21_28    : 8;
        IO_WORD AM13_20    : 8;
        IO_WORD AM5_12     : 8;
        IO_WORD unused     : 3;            /* unused bits */
        IO_WORD AM0_4      : 5;
#endif
    } bitc_ext;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        IO_WORD AM0_2  : 3;
        IO_WORD unused : 5;                /* unused bits   */
        IO_WORD AM3_10 : 8;
#else
        IO_WORD AM3_10 : 8;
        IO_WORD unused : 5;                /* unused bits   */
        IO_WORD AM0_2  : 3;
#endif
        /*IO_WORD upper    :16;                /* unused bits */
    } bitc_std;
  } amr[2];
} CANHSTR;

typedef struct
{
    IO_WORD ram[16];
    union {
    unsigned long   dword;
    unsigned short  word;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        const IO_WORD ID20 :1;
        const IO_WORD ID19 :1;
        const IO_WORD ID18 :1;
        const IO_WORD ID17 :1;
        const IO_WORD ID16 :1;
        const IO_WORD ID15 :1;
        const IO_WORD ID14 :1;
        const IO_WORD ID13 :1;
        const IO_WORD ID28 :1;
        const IO_WORD ID27 :1;
        const IO_WORD ID26 :1;
        const IO_WORD ID25 :1;
        const IO_WORD ID24 :1;
        const IO_WORD ID23 :1;
        const IO_WORD ID22 :1;
        const IO_WORD ID21 :1;
#else
        const IO_WORD ID21 :1;
        const IO_WORD ID22 :1;
        const IO_WORD ID23 :1;
        const IO_WORD ID24 :1;
        const IO_WORD ID25 :1;
        const IO_WORD ID26 :1;
        const IO_WORD ID27 :1;
        const IO_WORD ID28 :1;
        const IO_WORD ID13 :1;
        const IO_WORD ID14 :1;
        const IO_WORD ID15 :1;
        const IO_WORD ID16 :1;
        const IO_WORD ID17 :1;
        const IO_WORD ID18 :1;
        const IO_WORD ID19 :1;
        const IO_WORD ID20 :1;
#endif

#if defined(__BITFIELD_ORDER_MSB__)
        const IO_WORD ID4 :1;
        const IO_WORD ID3 :1;
        const IO_WORD ID2 :1;
        const IO_WORD ID1 :1;
        const IO_WORD ID0 :1;
        const IO_WORD     :3;
        const IO_WORD ID12 :1;
        const IO_WORD ID11 :1;
        const IO_WORD ID10 :1;
        const IO_WORD ID9 :1;
        const IO_WORD ID8 :1;
        const IO_WORD ID7 :1;
        const IO_WORD ID6 :1;
        const IO_WORD ID5 :1;
#else
        const IO_WORD ID5 :1;
        const IO_WORD ID6 :1;
        const IO_WORD ID7 :1;
        const IO_WORD ID8 :1;
        const IO_WORD ID9 :1;
        const IO_WORD ID10 :1;
        const IO_WORD ID11 :1;
        const IO_WORD ID12 :1;
        const IO_WORD     :3;
        const IO_WORD ID0 :1;
        const IO_WORD ID1 :1;
        const IO_WORD ID2 :1;
        const IO_WORD ID3 :1;
        const IO_WORD ID4 :1;
#endif

    } bit_ext;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        const IO_WORD ID2 :1;
        const IO_WORD ID1 :1;
        const IO_WORD ID0 :1;
        const IO_WORD ID  :5;
        const IO_WORD ID10:1;
        const IO_WORD ID9 :1;
        const IO_WORD ID8 :1;
        const IO_WORD ID7 :1;
        const IO_WORD ID6 :1;
        const IO_WORD ID5 :1;
        const IO_WORD ID4 :1;
        const IO_WORD ID3 :1;
#else
        const IO_WORD ID3 :1;
        const IO_WORD ID4 :1;
        const IO_WORD ID5 :1;
        const IO_WORD ID6 :1;
        const IO_WORD ID7 :1;
        const IO_WORD ID8 :1;
        const IO_WORD ID9 :1;
        const IO_WORD ID10:1;
        const IO_WORD ID  :5;
        const IO_WORD ID0 :1;
        const IO_WORD ID1 :1;
        const IO_WORD ID2 :1;
#endif
    } bit_std;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        const IO_WORD ID13_20 : 8;
        const IO_WORD ID21_28 : 8;
        const IO_WORD ID0_4   : 5;
        const IO_WORD unused  : 3;         /* unused bits */
        const IO_WORD ID5_12  : 8;
#else
        const IO_WORD ID21_28 : 8;
        const IO_WORD ID13_20 : 8;
        const IO_WORD ID5_12  : 8;
        const IO_WORD unused  : 3;         /* unused bits */
        const IO_WORD ID0_4   : 5;
#endif
    } bitc_ext;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        const IO_WORD ID0_2   : 3;
        const IO_WORD unused  : 5;             /* unused bits   */
        const IO_WORD ID3_10  : 8;
#else
        const IO_WORD ID3_10  : 8;
        const IO_WORD unused  : 5;             /* unused bits   */
        const IO_WORD ID0_2   : 3;
#endif
    } bitc_std;
  } idr[16];
  union{
    IO_WORD         word;
    IO_BYTE         byte;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        IO_WORD     :4;
        IO_WORD     DLC3:1;
        IO_WORD     DLC2:1;
        IO_WORD     DLC1:1;
        IO_WORD     DLC0:1;
#else
        IO_WORD     DLC0:1;
        IO_WORD     DLC1:1;
        IO_WORD     DLC2:1;
        IO_WORD     DLC3:1;
#endif
    } bit;
    struct {
#if defined(__BITFIELD_ORDER_MSB__)
        IO_WORD     :4;
        IO_WORD     DLC:4;
#else
        IO_WORD     DLC:4;
#endif
    } bitc;
  } dlcr[16];
  union{
          unsigned long dwords [2];
          long          longs  [2];
          IO_WORD       words  [4];
          int           ints   [4];
          short         shorts [4];
    const IO_BYTE       bytes  [8]; /* because of word access*/
    const char          chars  [8]; /* because of word access*/
          float         floats [2];
          double        adouble;
  }dtr[16];
} CANMSTR;

#endif	/* CANSTR */
/* include : CANMAC01.H */

#ifndef __CANMAC
#define __CANMAC

__IO_EXTERN __io CANLSTR _canl0;

/* CAN0 macros */
#define BVALR0           _canl0.bvalr.word
#define BVALR0_BVAL0     _canl0.bvalr.bit.BVAL0
#define BVALR0_BVAL1     _canl0.bvalr.bit.BVAL1
#define BVALR0_BVAL2     _canl0.bvalr.bit.BVAL2
#define BVALR0_BVAL3     _canl0.bvalr.bit.BVAL3
#define BVALR0_BVAL4     _canl0.bvalr.bit.BVAL4
#define BVALR0_BVAL5     _canl0.bvalr.bit.BVAL5
#define BVALR0_BVAL6     _canl0.bvalr.bit.BVAL6
#define BVALR0_BVAL7     _canl0.bvalr.bit.BVAL7
#define BVALR0_BVAL8     _canl0.bvalr.bit.BVAL8
#define BVALR0_BVAL9     _canl0.bvalr.bit.BVAL9
#define BVALR0_BVAL10    _canl0.bvalr.bit.BVAL10
#define BVALR0_BVAL11    _canl0.bvalr.bit.BVAL11
#define BVALR0_BVAL12    _canl0.bvalr.bit.BVAL12
#define BVALR0_BVAL13    _canl0.bvalr.bit.BVAL13
#define BVALR0_BVAL14    _canl0.bvalr.bit.BVAL14
#define BVALR0_BVAL15    _canl0.bvalr.bit.BVAL15

#define TREQR0           _canl0.treqr.word
#define TREQR0_TREQ0     _canl0.treqr.bit.TREQ0
#define TREQR0_TREQ1     _canl0.treqr.bit.TREQ1
#define TREQR0_TREQ2     _canl0.treqr.bit.TREQ2
#define TREQR0_TREQ3     _canl0.treqr.bit.TREQ3
#define TREQR0_TREQ4     _canl0.treqr.bit.TREQ4
#define TREQR0_TREQ5     _canl0.treqr.bit.TREQ5
#define TREQR0_TREQ6     _canl0.treqr.bit.TREQ6
#define TREQR0_TREQ7     _canl0.treqr.bit.TREQ7
#define TREQR0_TREQ8     _canl0.treqr.bit.TREQ8
#define TREQR0_TREQ9     _canl0.treqr.bit.TREQ9
#define TREQR0_TREQ10    _canl0.treqr.bit.TREQ10
#define TREQR0_TREQ11    _canl0.treqr.bit.TREQ11
#define TREQR0_TREQ12    _canl0.treqr.bit.TREQ12
#define TREQR0_TREQ13    _canl0.treqr.bit.TREQ13
#define TREQR0_TREQ14    _canl0.treqr.bit.TREQ14
#define TREQR0_TREQ15    _canl0.treqr.bit.TREQ15
 
#define TCANR0           _canl0.tcanr.word
#define TCANR0_TCAN0     _canl0.tcanr.bit.TCAN0
#define TCANR0_TCAN1     _canl0.tcanr.bit.TCAN1
#define TCANR0_TCAN2     _canl0.tcanr.bit.TCAN2
#define TCANR0_TCAN3     _canl0.tcanr.bit.TCAN3
#define TCANR0_TCAN4     _canl0.tcanr.bit.TCAN4
#define TCANR0_TCAN5     _canl0.tcanr.bit.TCAN5
#define TCANR0_TCAN6     _canl0.tcanr.bit.TCAN6
#define TCANR0_TCAN7     _canl0.tcanr.bit.TCAN7
#define TCANR0_TCAN8     _canl0.tcanr.bit.TCAN8
#define TCANR0_TCAN9     _canl0.tcanr.bit.TCAN9
#define TCANR0_TCAN10    _canl0.tcanr.bit.TCAN10
#define TCANR0_TCAN11    _canl0.tcanr.bit.TCAN11
#define TCANR0_TCAN12    _canl0.tcanr.bit.TCAN12
#define TCANR0_TCAN13    _canl0.tcanr.bit.TCAN13
#define TCANR0_TCAN14    _canl0.tcanr.bit.TCAN14
#define TCANR0_TCAN15    _canl0.tcanr.bit.TCAN15
 
#define TCR0             _canl0.tcr.word
#define TCR0_TC0         _canl0.tcr.bit.TC0
#define TCR0_TC1         _canl0.tcr.bit.TC1
#define TCR0_TC2         _canl0.tcr.bit.TC2
#define TCR0_TC3         _canl0.tcr.bit.TC3
#define TCR0_TC4         _canl0.tcr.bit.TC4
#define TCR0_TC5         _canl0.tcr.bit.TC5
#define TCR0_TC6         _canl0.tcr.bit.TC6
#define TCR0_TC7         _canl0.tcr.bit.TC7
#define TCR0_TC8         _canl0.tcr.bit.TC8
#define TCR0_TC9         _canl0.tcr.bit.TC9
#define TCR0_TC10        _canl0.tcr.bit.TC10
#define TCR0_TC11        _canl0.tcr.bit.TC11
#define TCR0_TC12        _canl0.tcr.bit.TC12
#define TCR0_TC13        _canl0.tcr.bit.TC13
#define TCR0_TC14        _canl0.tcr.bit.TC14
#define TCR0_TC15        _canl0.tcr.bit.TC15
 
#define RCR0             _canl0.rcr.word
#define RCR0_RC0         _canl0.rcr.bit.RC0
#define RCR0_RC1         _canl0.rcr.bit.RC1
#define RCR0_RC2         _canl0.rcr.bit.RC2
#define RCR0_RC3         _canl0.rcr.bit.RC3
#define RCR0_RC4         _canl0.rcr.bit.RC4
#define RCR0_RC5         _canl0.rcr.bit.RC5
#define RCR0_RC6         _canl0.rcr.bit.RC6
#define RCR0_RC7         _canl0.rcr.bit.RC7
#define RCR0_RC8         _canl0.rcr.bit.RC8
#define RCR0_RC9         _canl0.rcr.bit.RC9
#define RCR0_RC10        _canl0.rcr.bit.RC10
#define RCR0_RC11        _canl0.rcr.bit.RC11
#define RCR0_RC12        _canl0.rcr.bit.RC12
#define RCR0_RC13        _canl0.rcr.bit.RC13
#define RCR0_RC14        _canl0.rcr.bit.RC14
#define RCR0_RC15        _canl0.rcr.bit.RC15
 
#define RRTRR0           _canl0.rrtrr.word
#define RRTRR0_RRTR0     _canl0.rrtrr.bit.RRTR0
#define RRTRR0_RRTR1     _canl0.rrtrr.bit.RRTR1
#define RRTRR0_RRTR2     _canl0.rrtrr.bit.RRTR2
#define RRTRR0_RRTR3     _canl0.rrtrr.bit.RRTR3
#define RRTRR0_RRTR4     _canl0.rrtrr.bit.RRTR4
#define RRTRR0_RRTR5     _canl0.rrtrr.bit.RRTR5
#define RRTRR0_RRTR6     _canl0.rrtrr.bit.RRTR6
#define RRTRR0_RRTR7     _canl0.rrtrr.bit.RRTR7
#define RRTRR0_RRTR8     _canl0.rrtrr.bit.RRTR8
#define RRTRR0_RRTR9     _canl0.rrtrr.bit.RRTR9
#define RRTRR0_RRTR10    _canl0.rrtrr.bit.RRTR10
#define RRTRR0_RRTR11    _canl0.rrtrr.bit.RRTR11
#define RRTRR0_RRTR12    _canl0.rrtrr.bit.RRTR12
#define RRTRR0_RRTR13    _canl0.rrtrr.bit.RRTR13
#define RRTRR0_RRTR14    _canl0.rrtrr.bit.RRTR14
#define RRTRR0_RRTR15    _canl0.rrtrr.bit.RRTR15
 
#define ROVRR0           _canl0.rovrr.word
#define ROVRR0_ROVR0     _canl0.rovrr.bit.ROVR0
#define ROVRR0_ROVR1     _canl0.rovrr.bit.ROVR1
#define ROVRR0_ROVR2     _canl0.rovrr.bit.ROVR2
#define ROVRR0_ROVR3     _canl0.rovrr.bit.ROVR3
#define ROVRR0_ROVR4     _canl0.rovrr.bit.ROVR4
#define ROVRR0_ROVR5     _canl0.rovrr.bit.ROVR5
#define ROVRR0_ROVR6     _canl0.rovrr.bit.ROVR6
#define ROVRR0_ROVR7     _canl0.rovrr.bit.ROVR7
#define ROVRR0_ROVR8     _canl0.rovrr.bit.ROVR8
#define ROVRR0_ROVR9     _canl0.rovrr.bit.ROVR9
#define ROVRR0_ROVR10    _canl0.rovrr.bit.ROVR10
#define ROVRR0_ROVR11    _canl0.rovrr.bit.ROVR11
#define ROVRR0_ROVR12    _canl0.rovrr.bit.ROVR12
#define ROVRR0_ROVR13    _canl0.rovrr.bit.ROVR13
#define ROVRR0_ROVR14    _canl0.rovrr.bit.ROVR14
#define ROVRR0_ROVR15    _canl0.rovrr.bit.ROVR15
 
#define RIER0            _canl0.rier.word
#define RIER0_RIE0       _canl0.rier.bit.RIE0
#define RIER0_RIE1       _canl0.rier.bit.RIE1
#define RIER0_RIE2       _canl0.rier.bit.RIE2
#define RIER0_RIE3       _canl0.rier.bit.RIE3
#define RIER0_RIE4       _canl0.rier.bit.RIE4
#define RIER0_RIE5       _canl0.rier.bit.RIE5
#define RIER0_RIE6       _canl0.rier.bit.RIE6
#define RIER0_RIE7       _canl0.rier.bit.RIE7
#define RIER0_RIE8       _canl0.rier.bit.RIE8
#define RIER0_RIE9       _canl0.rier.bit.RIE9
#define RIER0_RIE10      _canl0.rier.bit.RIE10
#define RIER0_RIE11      _canl0.rier.bit.RIE11
#define RIER0_RIE12      _canl0.rier.bit.RIE12
#define RIER0_RIE13      _canl0.rier.bit.RIE13
#define RIER0_RIE14      _canl0.rier.bit.RIE14
#define RIER0_RIE15      _canl0.rier.bit.RIE15
 
__IO_EXTENDED CANHSTR _canh0;
 
/* CAN0 macros */
#define CSR0             _canh0.csr.word
#define CSR0_HALT        _canh0.csr.bit.HALT
#define CSR0_NIE         _canh0.csr.bit.NIE
#define CSR0_TOE         _canh0.csr.bit.TOE
#define CSR0_NS0         _canh0.csr.bit.NS0
#define CSR0_NS1         _canh0.csr.bit.NS1
#define CSR0_NT          _canh0.csr.bit.NT
#define CSR0_RS          _canh0.csr.bit.RS
#define CSR0_TS          _canh0.csr.bit.TS
#define CSR0_NS          _canh0.csr.bitc.NS
 
#define LEIR0            _canh0.leir.byte
#define LEIR0_MBP0       _canh0.leir.bit.MBP0
#define LEIR0_MBP1       _canh0.leir.bit.MBP1
#define LEIR0_MBP2       _canh0.leir.bit.MBP2
#define LEIR0_MBP3       _canh0.leir.bit.MBP3
#define LEIR0_RCE        _canh0.leir.bit.RCE
#define LEIR0_TCE        _canh0.leir.bit.TCE
#define LEIR0_NTE        _canh0.leir.bit.NTE
#define LEIR0_MBP        _canh0.leir.bitc.MBP
 
#define RTEC0            _canh0.rtec.word
#define RTEC0_REC0       _canh0.rtec.bit.REC0
#define RTEC0_REC1       _canh0.rtec.bit.REC1
#define RTEC0_REC2       _canh0.rtec.bit.REC2
#define RTEC0_REC3       _canh0.rtec.bit.REC3
#define RTEC0_REC4       _canh0.rtec.bit.REC4
#define RTEC0_REC5       _canh0.rtec.bit.REC5
#define RTEC0_REC6       _canh0.rtec.bit.REC6
#define RTEC0_REC7       _canh0.rtec.bit.REC7
#define RTEC0_TEC0       _canh0.rtec.bit.TEC0
#define RTEC0_TEC1       _canh0.rtec.bit.TEC1
#define RTEC0_TEC2       _canh0.rtec.bit.TEC2
#define RTEC0_TEC3       _canh0.rtec.bit.TEC3
#define RTEC0_TEC4       _canh0.rtec.bit.TEC4
#define RTEC0_TEC5       _canh0.rtec.bit.TEC5
#define RTEC0_TEC6       _canh0.rtec.bit.TEC6
#define RTEC0_TEC7       _canh0.rtec.bit.TEC7
#define RTEC0_REC        _canh0.rtec.bitc.REC
#define RTEC0_TEC        _canh0.rtec.bitc.TEC
 
#define BTR0             _canh0.btr.word
#define BTR0_PSC0        _canh0.btr.bit.PSC0
#define BTR0_PSC1        _canh0.btr.bit.PSC1
#define BTR0_PSC2        _canh0.btr.bit.PSC2
#define BTR0_PSC3        _canh0.btr.bit.PSC3
#define BTR0_PSC4        _canh0.btr.bit.PSC4
#define BTR0_PSC5        _canh0.btr.bit.PSC5
#define BTR0_RSJ0        _canh0.btr.bit.RSJ0
#define BTR0_RSJ1        _canh0.btr.bit.RSJ1
#define BTR0_TS10        _canh0.btr.bit.TS10
#define BTR0_TS11        _canh0.btr.bit.TS11
#define BTR0_TS12        _canh0.btr.bit.TS12
#define BTR0_TS13        _canh0.btr.bit.TS13
#define BTR0_TS20        _canh0.btr.bit.TS20
#define BTR0_TS21        _canh0.btr.bit.TS21
#define BTR0_TS22        _canh0.btr.bit.TS22
#define BTR0_PSC         _canh0.btr.bitc.PSC
#define BTR0_RSJ         _canh0.btr.bitc.RSJ
#define BTR0_TS1         _canh0.btr.bitc.TS1
#define BTR0_TS2         _canh0.btr.bitc.TS2
 
#define IDER0            _canh0.ider.word
#define IDER0_IDE0       _canh0.ider.bit.IDE0
#define IDER0_IDE1       _canh0.ider.bit.IDE1
#define IDER0_IDE2       _canh0.ider.bit.IDE2
#define IDER0_IDE3       _canh0.ider.bit.IDE3
#define IDER0_IDE4       _canh0.ider.bit.IDE4
#define IDER0_IDE5       _canh0.ider.bit.IDE5
#define IDER0_IDE6       _canh0.ider.bit.IDE6
#define IDER0_IDE7       _canh0.ider.bit.IDE7
#define IDER0_IDE8       _canh0.ider.bit.IDE8
#define IDER0_IDE9       _canh0.ider.bit.IDE9
#define IDER0_IDE10      _canh0.ider.bit.IDE10
#define IDER0_IDE11      _canh0.ider.bit.IDE11
#define IDER0_IDE12      _canh0.ider.bit.IDE12
#define IDER0_IDE13      _canh0.ider.bit.IDE13
#define IDER0_IDE14      _canh0.ider.bit.IDE14
#define IDER0_IDE15      _canh0.ider.bit.IDE15
 
#define TRTRR0           _canh0.trtrr.word
#define TRTRR0_TRTR0     _canh0.trtrr.bit.TRTR0
#define TRTRR0_TRTR1     _canh0.trtrr.bit.TRTR1
#define TRTRR0_TRTR2     _canh0.trtrr.bit.TRTR2
#define TRTRR0_TRTR3     _canh0.trtrr.bit.TRTR3
#define TRTRR0_TRTR4     _canh0.trtrr.bit.TRTR4
#define TRTRR0_TRTR5     _canh0.trtrr.bit.TRTR5
#define TRTRR0_TRTR6     _canh0.trtrr.bit.TRTR6
#define TRTRR0_TRTR7     _canh0.trtrr.bit.TRTR7
#define TRTRR0_TRTR8     _canh0.trtrr.bit.TRTR8
#define TRTRR0_TRTR9     _canh0.trtrr.bit.TRTR9
#define TRTRR0_TRTR10    _canh0.trtrr.bit.TRTR10
#define TRTRR0_TRTR11    _canh0.trtrr.bit.TRTR11
#define TRTRR0_TRTR12    _canh0.trtrr.bit.TRTR12
#define TRTRR0_TRTR13    _canh0.trtrr.bit.TRTR13
#define TRTRR0_TRTR14    _canh0.trtrr.bit.TRTR14
#define TRTRR0_TRTR15    _canh0.trtrr.bit.TRTR15
 
#define RFWTR0           _canh0.rfwtr.word
#define RFWTR0_RFWT0     _canh0.rfwtr.bit.RFWT0
#define RFWTR0_RFWT1     _canh0.rfwtr.bit.RFWT1
#define RFWTR0_RFWT2     _canh0.rfwtr.bit.RFWT2
#define RFWTR0_RFWT3     _canh0.rfwtr.bit.RFWT3
#define RFWTR0_RFWT4     _canh0.rfwtr.bit.RFWT4
#define RFWTR0_RFWT5     _canh0.rfwtr.bit.RFWT5
#define RFWTR0_RFWT6     _canh0.rfwtr.bit.RFWT6
#define RFWTR0_RFWT7     _canh0.rfwtr.bit.RFWT7
#define RFWTR0_RFWT8     _canh0.rfwtr.bit.RFWT8
#define RFWTR0_RFWT9     _canh0.rfwtr.bit.RFWT9
#define RFWTR0_RFWT10    _canh0.rfwtr.bit.RFWT10
#define RFWTR0_RFWT11    _canh0.rfwtr.bit.RFWT11
#define RFWTR0_RFWT12    _canh0.rfwtr.bit.RFWT12
#define RFWTR0_RFWT13    _canh0.rfwtr.bit.RFWT13
#define RFWTR0_RFWT14    _canh0.rfwtr.bit.RFWT14
#define RFWTR0_RFWT15    _canh0.rfwtr.bit.RFWT15
 
#define TIER0            _canh0.tier.word
#define TIER0_TIE0       _canh0.tier.bit.TIE0
#define TIER0_TIE1       _canh0.tier.bit.TIE1
#define TIER0_TIE2       _canh0.tier.bit.TIE2
#define TIER0_TIE3       _canh0.tier.bit.TIE3
#define TIER0_TIE4       _canh0.tier.bit.TIE4
#define TIER0_TIE5       _canh0.tier.bit.TIE5
#define TIER0_TIE6       _canh0.tier.bit.TIE6
#define TIER0_TIE7       _canh0.tier.bit.TIE7
#define TIER0_TIE8       _canh0.tier.bit.TIE8
#define TIER0_TIE9       _canh0.tier.bit.TIE9
#define TIER0_TIE10      _canh0.tier.bit.TIE10
#define TIER0_TIE11      _canh0.tier.bit.TIE11
#define TIER0_TIE12      _canh0.tier.bit.TIE12
#define TIER0_TIE13      _canh0.tier.bit.TIE13
#define TIER0_TIE14      _canh0.tier.bit.TIE14
#define TIER0_TIE15      _canh0.tier.bit.TIE15
 
#define AMSR0            _canh0.amsr.dword
#define AMSR0_AMS0       _canh0.amsr.bitc.AMS0
#define AMSR0_AMS1       _canh0.amsr.bitc.AMS1
#define AMSR0_AMS2       _canh0.amsr.bitc.AMS2
#define AMSR0_AMS3       _canh0.amsr.bitc.AMS3
#define AMSR0_AMS4       _canh0.amsr.bitc.AMS4
#define AMSR0_AMS5       _canh0.amsr.bitc.AMS5
#define AMSR0_AMS6       _canh0.amsr.bitc.AMS6
#define AMSR0_AMS7       _canh0.amsr.bitc.AMS7
#define AMSR0_AMS8       _canh0.amsr.bitc.AMS8
#define AMSR0_AMS9       _canh0.amsr.bitc.AMS9
#define AMSR0_AMS10      _canh0.amsr.bitc.AMS10
#define AMSR0_AMS11      _canh0.amsr.bitc.AMS11
#define AMSR0_AMS12      _canh0.amsr.bitc.AMS12
#define AMSR0_AMS13      _canh0.amsr.bitc.AMS13
#define AMSR0_AMS14      _canh0.amsr.bitc.AMS14
#define AMSR0_AMS15      _canh0.amsr.bitc.AMS15
                    
#define AMR00            _canh0.amr[0].word  /* AMR0 for CAN0 (std ID bits) */
#define AMR10            _canh0.amr[1].word  /* AMR1 for CAN0 (std ID bits) */
#define AMRX00           _canh0.amr[0].dword /* AMR0 for CAN0 (ext ID bits) */
#define AMRX10           _canh0.amr[1].dword /* AMR1 for CAN0 (ext ID bits) */
 
__IO_EXTENDED CANMSTR _canm0;
 
/* CAN0 macros */
#define IDR0(buf)            (_canm0.idr[buf].word)
#define IDRX0(buf)           (_canm0.idr[buf].dword)
 
#define DLCR0(buf)           (_canm0.dlcr[buf].byte)
#define DLCR0_DLC0(buf)      (_canm0.dlcr[buf].bit.DLC0)
#define DLCR0_DLC1(buf)      (_canm0.dlcr[buf].bit.DLC1)
#define DLCR0_DLC2(buf)      (_canm0.dlcr[buf].bit.DLC2)
#define DLCR0_DLC3(buf)      (_canm0.dlcr[buf].bit.DLC3)
 
#define DTR0_BPTR(  buf)     (_canm0.dtr[buf].bytes )
#define DTR0_WPTR(  buf)     (_canm0.dtr[buf].words )
#define DTR0_DWPTR( buf)     (_canm0.dtr[buf].dwords)
#define DTR0_LWPTR( buf)     (_canm0.dtr[buf].dwords)
#define DTR0_CPTR(  buf)     (_canm0.dtr[buf].chars )
#define DTR0_IPTR(  buf)     (_canm0.dtr[buf].ints  )
#define DTR0_LPTR(  buf)     (_canm0.dtr[buf].longs )
 
#define DTR0_BYTE(  buf,i)   (_canm0.dtr[buf].bytes  [i])
#define DTR0_WORD(  buf,i)   (_canm0.dtr[buf].words  [i])
#define DTR0_DWORD( buf,i)   (_canm0.dtr[buf].dwords [i])
#define DTR0_CHAR(  buf,i)   (_canm0.dtr[buf].chars  [i])
#define DTR0_INT(   buf,i)   (_canm0.dtr[buf].ints   [i])
#define DTR0_SHORT( buf,i)   (_canm0.dtr[buf].shorts [i])
#define DTR0_LONGS( buf,i)   (_canm0.dtr[buf].longs  [i])
#define DTR0_FLOATS(buf,i)   (_canm0.dtr[buf].floats [i])
#define DTR0_DOUBLE(buf  )   (_canm0.dtr[buf].adouble   )
 

__IO_EXTERN __io CANLSTR _canl1;

/* CAN1 macros */
#define BVALR1           _canl1.bvalr.word
#define BVALR1_BVAL0     _canl1.bvalr.bit.BVAL0
#define BVALR1_BVAL1     _canl1.bvalr.bit.BVAL1
#define BVALR1_BVAL2     _canl1.bvalr.bit.BVAL2
#define BVALR1_BVAL3     _canl1.bvalr.bit.BVAL3
#define BVALR1_BVAL4     _canl1.bvalr.bit.BVAL4
#define BVALR1_BVAL5     _canl1.bvalr.bit.BVAL5
#define BVALR1_BVAL6     _canl1.bvalr.bit.BVAL6
#define BVALR1_BVAL7     _canl1.bvalr.bit.BVAL7
#define BVALR1_BVAL8     _canl1.bvalr.bit.BVAL8
#define BVALR1_BVAL9     _canl1.bvalr.bit.BVAL9
#define BVALR1_BVAL10    _canl1.bvalr.bit.BVAL10
#define BVALR1_BVAL11    _canl1.bvalr.bit.BVAL11
#define BVALR1_BVAL12    _canl1.bvalr.bit.BVAL12
#define BVALR1_BVAL13    _canl1.bvalr.bit.BVAL13
#define BVALR1_BVAL14    _canl1.bvalr.bit.BVAL14
#define BVALR1_BVAL15    _canl1.bvalr.bit.BVAL15

#define TREQR1           _canl1.treqr.word
#define TREQR1_TREQ0     _canl1.treqr.bit.TREQ0
#define TREQR1_TREQ1     _canl1.treqr.bit.TREQ1
#define TREQR1_TREQ2     _canl1.treqr.bit.TREQ2
#define TREQR1_TREQ3     _canl1.treqr.bit.TREQ3
#define TREQR1_TREQ4     _canl1.treqr.bit.TREQ4
#define TREQR1_TREQ5     _canl1.treqr.bit.TREQ5
#define TREQR1_TREQ6     _canl1.treqr.bit.TREQ6
#define TREQR1_TREQ7     _canl1.treqr.bit.TREQ7
#define TREQR1_TREQ8     _canl1.treqr.bit.TREQ8
#define TREQR1_TREQ9     _canl1.treqr.bit.TREQ9
#define TREQR1_TREQ10    _canl1.treqr.bit.TREQ10
#define TREQR1_TREQ11    _canl1.treqr.bit.TREQ11
#define TREQR1_TREQ12    _canl1.treqr.bit.TREQ12
#define TREQR1_TREQ13    _canl1.treqr.bit.TREQ13
#define TREQR1_TREQ14    _canl1.treqr.bit.TREQ14
#define TREQR1_TREQ15    _canl1.treqr.bit.TREQ15
 
#define TCANR1           _canl1.tcanr.word
#define TCANR1_TCAN0     _canl1.tcanr.bit.TCAN0
#define TCANR1_TCAN1     _canl1.tcanr.bit.TCAN1
#define TCANR1_TCAN2     _canl1.tcanr.bit.TCAN2
#define TCANR1_TCAN3     _canl1.tcanr.bit.TCAN3
#define TCANR1_TCAN4     _canl1.tcanr.bit.TCAN4
#define TCANR1_TCAN5     _canl1.tcanr.bit.TCAN5
#define TCANR1_TCAN6     _canl1.tcanr.bit.TCAN6
#define TCANR1_TCAN7     _canl1.tcanr.bit.TCAN7
#define TCANR1_TCAN8     _canl1.tcanr.bit.TCAN8
#define TCANR1_TCAN9     _canl1.tcanr.bit.TCAN9
#define TCANR1_TCAN10    _canl1.tcanr.bit.TCAN10
#define TCANR1_TCAN11    _canl1.tcanr.bit.TCAN11
#define TCANR1_TCAN12    _canl1.tcanr.bit.TCAN12
#define TCANR1_TCAN13    _canl1.tcanr.bit.TCAN13
#define TCANR1_TCAN14    _canl1.tcanr.bit.TCAN14
#define TCANR1_TCAN15    _canl1.tcanr.bit.TCAN15
 
#define TCR1             _canl1.tcr.word
#define TCR1_TC0         _canl1.tcr.bit.TC0
#define TCR1_TC1         _canl1.tcr.bit.TC1
#define TCR1_TC2         _canl1.tcr.bit.TC2
#define TCR1_TC3         _canl1.tcr.bit.TC3
#define TCR1_TC4         _canl1.tcr.bit.TC4
#define TCR1_TC5         _canl1.tcr.bit.TC5
#define TCR1_TC6         _canl1.tcr.bit.TC6
#define TCR1_TC7         _canl1.tcr.bit.TC7
#define TCR1_TC8         _canl1.tcr.bit.TC8
#define TCR1_TC9         _canl1.tcr.bit.TC9
#define TCR1_TC10        _canl1.tcr.bit.TC10
#define TCR1_TC11        _canl1.tcr.bit.TC11
#define TCR1_TC12        _canl1.tcr.bit.TC12
#define TCR1_TC13        _canl1.tcr.bit.TC13
#define TCR1_TC14        _canl1.tcr.bit.TC14
#define TCR1_TC15        _canl1.tcr.bit.TC15
 
#define RCR1             _canl1.rcr.word
#define RCR1_RC0         _canl1.rcr.bit.RC0
#define RCR1_RC1         _canl1.rcr.bit.RC1
#define RCR1_RC2         _canl1.rcr.bit.RC2
#define RCR1_RC3         _canl1.rcr.bit.RC3
#define RCR1_RC4         _canl1.rcr.bit.RC4
#define RCR1_RC5         _canl1.rcr.bit.RC5
#define RCR1_RC6         _canl1.rcr.bit.RC6
#define RCR1_RC7         _canl1.rcr.bit.RC7
#define RCR1_RC8         _canl1.rcr.bit.RC8
#define RCR1_RC9         _canl1.rcr.bit.RC9
#define RCR1_RC10        _canl1.rcr.bit.RC10
#define RCR1_RC11        _canl1.rcr.bit.RC11
#define RCR1_RC12        _canl1.rcr.bit.RC12
#define RCR1_RC13        _canl1.rcr.bit.RC13
#define RCR1_RC14        _canl1.rcr.bit.RC14
#define RCR1_RC15        _canl1.rcr.bit.RC15
 
#define RRTRR1           _canl1.rrtrr.word
#define RRTRR1_RRTR0     _canl1.rrtrr.bit.RRTR0
#define RRTRR1_RRTR1     _canl1.rrtrr.bit.RRTR1
#define RRTRR1_RRTR2     _canl1.rrtrr.bit.RRTR2
#define RRTRR1_RRTR3     _canl1.rrtrr.bit.RRTR3
#define RRTRR1_RRTR4     _canl1.rrtrr.bit.RRTR4
#define RRTRR1_RRTR5     _canl1.rrtrr.bit.RRTR5
#define RRTRR1_RRTR6     _canl1.rrtrr.bit.RRTR6
#define RRTRR1_RRTR7     _canl1.rrtrr.bit.RRTR7
#define RRTRR1_RRTR8     _canl1.rrtrr.bit.RRTR8
#define RRTRR1_RRTR9     _canl1.rrtrr.bit.RRTR9
#define RRTRR1_RRTR10    _canl1.rrtrr.bit.RRTR10
#define RRTRR1_RRTR11    _canl1.rrtrr.bit.RRTR11
#define RRTRR1_RRTR12    _canl1.rrtrr.bit.RRTR12
#define RRTRR1_RRTR13    _canl1.rrtrr.bit.RRTR13
#define RRTRR1_RRTR14    _canl1.rrtrr.bit.RRTR14
#define RRTRR1_RRTR15    _canl1.rrtrr.bit.RRTR15
 
#define ROVRR1           _canl1.rovrr.word
#define ROVRR1_ROVR0     _canl1.rovrr.bit.ROVR0
#define ROVRR1_ROVR1     _canl1.rovrr.bit.ROVR1
#define ROVRR1_ROVR2     _canl1.rovrr.bit.ROVR2
#define ROVRR1_ROVR3     _canl1.rovrr.bit.ROVR3
#define ROVRR1_ROVR4     _canl1.rovrr.bit.ROVR4
#define ROVRR1_ROVR5     _canl1.rovrr.bit.ROVR5
#define ROVRR1_ROVR6     _canl1.rovrr.bit.ROVR6
#define ROVRR1_ROVR7     _canl1.rovrr.bit.ROVR7
#define ROVRR1_ROVR8     _canl1.rovrr.bit.ROVR8
#define ROVRR1_ROVR9     _canl1.rovrr.bit.ROVR9
#define ROVRR1_ROVR10    _canl1.rovrr.bit.ROVR10
#define ROVRR1_ROVR11    _canl1.rovrr.bit.ROVR11
#define ROVRR1_ROVR12    _canl1.rovrr.bit.ROVR12
#define ROVRR1_ROVR13    _canl1.rovrr.bit.ROVR13
#define ROVRR1_ROVR14    _canl1.rovrr.bit.ROVR14
#define ROVRR1_ROVR15    _canl1.rovrr.bit.ROVR15
 
#define RIER1            _canl1.rier.word
#define RIER1_RIE0       _canl1.rier.bit.RIE0
#define RIER1_RIE1       _canl1.rier.bit.RIE1
#define RIER1_RIE2       _canl1.rier.bit.RIE2
#define RIER1_RIE3       _canl1.rier.bit.RIE3
#define RIER1_RIE4       _canl1.rier.bit.RIE4
#define RIER1_RIE5       _canl1.rier.bit.RIE5
#define RIER1_RIE6       _canl1.rier.bit.RIE6
#define RIER1_RIE7       _canl1.rier.bit.RIE7
#define RIER1_RIE8       _canl1.rier.bit.RIE8
#define RIER1_RIE9       _canl1.rier.bit.RIE9
#define RIER1_RIE10      _canl1.rier.bit.RIE10
#define RIER1_RIE11      _canl1.rier.bit.RIE11
#define RIER1_RIE12      _canl1.rier.bit.RIE12
#define RIER1_RIE13      _canl1.rier.bit.RIE13
#define RIER1_RIE14      _canl1.rier.bit.RIE14
#define RIER1_RIE15      _canl1.rier.bit.RIE15
 
__IO_EXTENDED CANHSTR _canh1;
 
/* CAN1 macros */
#define CSR1             _canh1.csr.word
#define CSR1_HALT        _canh1.csr.bit.HALT
#define CSR1_NIE         _canh1.csr.bit.NIE
#define CSR1_TOE         _canh1.csr.bit.TOE
#define CSR1_NS0         _canh1.csr.bit.NS0
#define CSR1_NS1         _canh1.csr.bit.NS1
#define CSR1_NT          _canh1.csr.bit.NT
#define CSR1_RS          _canh1.csr.bit.RS
#define CSR1_TS          _canh1.csr.bit.TS
#define CSR1_NS          _canh1.csr.bitc.NS
 
#define LEIR1            _canh1.leir.byte
#define LEIR1_MBP0       _canh1.leir.bit.MBP0
#define LEIR1_MBP1       _canh1.leir.bit.MBP1
#define LEIR1_MBP2       _canh1.leir.bit.MBP2
#define LEIR1_MBP3       _canh1.leir.bit.MBP3
#define LEIR1_RCE        _canh1.leir.bit.RCE
#define LEIR1_TCE        _canh1.leir.bit.TCE
#define LEIR1_NTE        _canh1.leir.bit.NTE
#define LEIR1_MBP        _canh1.leir.bitc.MBP
 
#define RTEC1            _canh1.rtec.word
#define RTEC1_REC0       _canh1.rtec.bit.REC0
#define RTEC1_REC1       _canh1.rtec.bit.REC1
#define RTEC1_REC2       _canh1.rtec.bit.REC2
#define RTEC1_REC3       _canh1.rtec.bit.REC3
#define RTEC1_REC4       _canh1.rtec.bit.REC4
#define RTEC1_REC5       _canh1.rtec.bit.REC5
#define RTEC1_REC6       _canh1.rtec.bit.REC6
#define RTEC1_REC7       _canh1.rtec.bit.REC7
#define RTEC1_TEC0       _canh1.rtec.bit.TEC0
#define RTEC1_TEC1       _canh1.rtec.bit.TEC1
#define RTEC1_TEC2       _canh1.rtec.bit.TEC2
#define RTEC1_TEC3       _canh1.rtec.bit.TEC3
#define RTEC1_TEC4       _canh1.rtec.bit.TEC4
#define RTEC1_TEC5       _canh1.rtec.bit.TEC5
#define RTEC1_TEC6       _canh1.rtec.bit.TEC6
#define RTEC1_TEC7       _canh1.rtec.bit.TEC7
#define RTEC1_REC        _canh1.rtec.bitc.REC
#define RTEC1_TEC        _canh1.rtec.bitc.TEC
 
#define BTR1             _canh1.btr.word
#define BTR1_PSC0        _canh1.btr.bit.PSC0
#define BTR1_PSC1        _canh1.btr.bit.PSC1
#define BTR1_PSC2        _canh1.btr.bit.PSC2
#define BTR1_PSC3        _canh1.btr.bit.PSC3
#define BTR1_PSC4        _canh1.btr.bit.PSC4
#define BTR1_PSC5        _canh1.btr.bit.PSC5
#define BTR1_RSJ0        _canh1.btr.bit.RSJ0
#define BTR1_RSJ1        _canh1.btr.bit.RSJ1
#define BTR1_TS10        _canh1.btr.bit.TS10
#define BTR1_TS11        _canh1.btr.bit.TS11
#define BTR1_TS12        _canh1.btr.bit.TS12
#define BTR1_TS13        _canh1.btr.bit.TS13
#define BTR1_TS20        _canh1.btr.bit.TS20
#define BTR1_TS21        _canh1.btr.bit.TS21
#define BTR1_TS22        _canh1.btr.bit.TS22
#define BTR1_PSC         _canh1.btr.bitc.PSC
#define BTR1_RSJ         _canh1.btr.bitc.RSJ
#define BTR1_TS1         _canh1.btr.bitc.TS1
#define BTR1_TS2         _canh1.btr.bitc.TS2
 
#define IDER1            _canh1.ider.word
#define IDER1_IDE0       _canh1.ider.bit.IDE0
#define IDER1_IDE1       _canh1.ider.bit.IDE1
#define IDER1_IDE2       _canh1.ider.bit.IDE2
#define IDER1_IDE3       _canh1.ider.bit.IDE3
#define IDER1_IDE4       _canh1.ider.bit.IDE4
#define IDER1_IDE5       _canh1.ider.bit.IDE5
#define IDER1_IDE6       _canh1.ider.bit.IDE6
#define IDER1_IDE7       _canh1.ider.bit.IDE7
#define IDER1_IDE8       _canh1.ider.bit.IDE8
#define IDER1_IDE9       _canh1.ider.bit.IDE9
#define IDER1_IDE10      _canh1.ider.bit.IDE10
#define IDER1_IDE11      _canh1.ider.bit.IDE11
#define IDER1_IDE12      _canh1.ider.bit.IDE12
#define IDER1_IDE13      _canh1.ider.bit.IDE13
#define IDER1_IDE14      _canh1.ider.bit.IDE14
#define IDER1_IDE15      _canh1.ider.bit.IDE15
 
#define TRTRR1           _canh1.trtrr.word
#define TRTRR1_TRTR0     _canh1.trtrr.bit.TRTR0
#define TRTRR1_TRTR1     _canh1.trtrr.bit.TRTR1
#define TRTRR1_TRTR2     _canh1.trtrr.bit.TRTR2
#define TRTRR1_TRTR3     _canh1.trtrr.bit.TRTR3
#define TRTRR1_TRTR4     _canh1.trtrr.bit.TRTR4
#define TRTRR1_TRTR5     _canh1.trtrr.bit.TRTR5
#define TRTRR1_TRTR6     _canh1.trtrr.bit.TRTR6
#define TRTRR1_TRTR7     _canh1.trtrr.bit.TRTR7
#define TRTRR1_TRTR8     _canh1.trtrr.bit.TRTR8
#define TRTRR1_TRTR9     _canh1.trtrr.bit.TRTR9
#define TRTRR1_TRTR10    _canh1.trtrr.bit.TRTR10
#define TRTRR1_TRTR11    _canh1.trtrr.bit.TRTR11
#define TRTRR1_TRTR12    _canh1.trtrr.bit.TRTR12
#define TRTRR1_TRTR13    _canh1.trtrr.bit.TRTR13
#define TRTRR1_TRTR14    _canh1.trtrr.bit.TRTR14
#define TRTRR1_TRTR15    _canh1.trtrr.bit.TRTR15
 
#define RFWTR1           _canh1.rfwtr.word
#define RFWTR1_RFWT0     _canh1.rfwtr.bit.RFWT0
#define RFWTR1_RFWT1     _canh1.rfwtr.bit.RFWT1
#define RFWTR1_RFWT2     _canh1.rfwtr.bit.RFWT2
#define RFWTR1_RFWT3     _canh1.rfwtr.bit.RFWT3
#define RFWTR1_RFWT4     _canh1.rfwtr.bit.RFWT4
#define RFWTR1_RFWT5     _canh1.rfwtr.bit.RFWT5
#define RFWTR1_RFWT6     _canh1.rfwtr.bit.RFWT6
#define RFWTR1_RFWT7     _canh1.rfwtr.bit.RFWT7
#define RFWTR1_RFWT8     _canh1.rfwtr.bit.RFWT8
#define RFWTR1_RFWT9     _canh1.rfwtr.bit.RFWT9
#define RFWTR1_RFWT10    _canh1.rfwtr.bit.RFWT10
#define RFWTR1_RFWT11    _canh1.rfwtr.bit.RFWT11
#define RFWTR1_RFWT12    _canh1.rfwtr.bit.RFWT12
#define RFWTR1_RFWT13    _canh1.rfwtr.bit.RFWT13
#define RFWTR1_RFWT14    _canh1.rfwtr.bit.RFWT14
#define RFWTR1_RFWT15    _canh1.rfwtr.bit.RFWT15
 
#define TIER1            _canh1.tier.word
#define TIER1_TIE0       _canh1.tier.bit.TIE0
#define TIER1_TIE1       _canh1.tier.bit.TIE1
#define TIER1_TIE2       _canh1.tier.bit.TIE2
#define TIER1_TIE3       _canh1.tier.bit.TIE3
#define TIER1_TIE4       _canh1.tier.bit.TIE4
#define TIER1_TIE5       _canh1.tier.bit.TIE5
#define TIER1_TIE6       _canh1.tier.bit.TIE6
#define TIER1_TIE7       _canh1.tier.bit.TIE7
#define TIER1_TIE8       _canh1.tier.bit.TIE8
#define TIER1_TIE9       _canh1.tier.bit.TIE9
#define TIER1_TIE10      _canh1.tier.bit.TIE10
#define TIER1_TIE11      _canh1.tier.bit.TIE11
#define TIER1_TIE12      _canh1.tier.bit.TIE12
#define TIER1_TIE13      _canh1.tier.bit.TIE13
#define TIER1_TIE14      _canh1.tier.bit.TIE14
#define TIER1_TIE15      _canh1.tier.bit.TIE15
 
#define AMSR1            _canh1.amsr.dword
#define AMSR1_AMS0       _canh1.amsr.bitc.AMS0
#define AMSR1_AMS1       _canh1.amsr.bitc.AMS1
#define AMSR1_AMS2       _canh1.amsr.bitc.AMS2
#define AMSR1_AMS3       _canh1.amsr.bitc.AMS3
#define AMSR1_AMS4       _canh1.amsr.bitc.AMS4
#define AMSR1_AMS5       _canh1.amsr.bitc.AMS5
#define AMSR1_AMS6       _canh1.amsr.bitc.AMS6
#define AMSR1_AMS7       _canh1.amsr.bitc.AMS7
#define AMSR1_AMS8       _canh1.amsr.bitc.AMS8
#define AMSR1_AMS9       _canh1.amsr.bitc.AMS9
#define AMSR1_AMS10      _canh1.amsr.bitc.AMS10
#define AMSR1_AMS11      _canh1.amsr.bitc.AMS11
#define AMSR1_AMS12      _canh1.amsr.bitc.AMS12
#define AMSR1_AMS13      _canh1.amsr.bitc.AMS13
#define AMSR1_AMS14      _canh1.amsr.bitc.AMS14
#define AMSR1_AMS15      _canh1.amsr.bitc.AMS15
                    
#define AMR01            _canh1.amr[0].word  /* AMR0 for CAN1 (std ID bits) */
#define AMR11            _canh1.amr[1].word  /* AMR1 for CAN1 (std ID bits) */
#define AMRX01           _canh1.amr[0].dword /* AMR0 for CAN1 (ext ID bits) */
#define AMRX11           _canh1.amr[1].dword /* AMR1 for CAN1 (ext ID bits) */
 
__IO_EXTENDED CANMSTR _canm1;
 
/* CAN1 macros */
#define IDR1(buf)            (_canm1.idr[buf].word)
#define IDRX1(buf)           (_canm1.idr[buf].dword)
 
#define DLCR1(buf)           (_canm1.dlcr[buf].byte)
#define DLCR1_DLC0(buf)      (_canm1.dlcr[buf].bit.DLC0)
#define DLCR1_DLC1(buf)      (_canm1.dlcr[buf].bit.DLC1)
#define DLCR1_DLC2(buf)      (_canm1.dlcr[buf].bit.DLC2)
#define DLCR1_DLC3(buf)      (_canm1.dlcr[buf].bit.DLC3)
 
#define DTR1_BPTR(  buf)     (_canm1.dtr[buf].bytes )
#define DTR1_WPTR(  buf)     (_canm1.dtr[buf].words )
#define DTR1_DWPTR( buf)     (_canm1.dtr[buf].dwords)
#define DTR1_LWPTR( buf)     (_canm1.dtr[buf].dwords)
#define DTR1_CPTR(  buf)     (_canm1.dtr[buf].chars )
#define DTR1_IPTR(  buf)     (_canm1.dtr[buf].ints  )
#define DTR1_LPTR(  buf)     (_canm1.dtr[buf].longs )
 
#define DTR1_BYTE(  buf,i)   (_canm1.dtr[buf].bytes  [i])
#define DTR1_WORD(  buf,i)   (_canm1.dtr[buf].words  [i])
#define DTR1_DWORD( buf,i)   (_canm1.dtr[buf].dwords [i])
#define DTR1_CHAR(  buf,i)   (_canm1.dtr[buf].chars  [i])
#define DTR1_INT(   buf,i)   (_canm1.dtr[buf].ints   [i])
#define DTR1_SHORT( buf,i)   (_canm1.dtr[buf].shorts [i])
#define DTR1_LONGS( buf,i)   (_canm1.dtr[buf].longs  [i])
#define DTR1_FLOATS(buf,i)   (_canm1.dtr[buf].floats [i])
#define DTR1_DOUBLE(buf  )   (_canm1.dtr[buf].adouble   )
 
 
#endif /* CANMAC */
#  undef ___IOWIDTH
#endif                   /* __MB90XXX_H */
