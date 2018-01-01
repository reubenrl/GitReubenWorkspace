/*
 * can.h
 *
 *  Created on: Jun 12, 2014
 *      Author: reuben
 */

#ifndef CAN_H_
#define CAN_H_

/*===== CAN ======= */

#define BTR_16M_20k8_24_66_2 0x7EDF /* BTR config 20.8 kBaud */
#define BTR_16M_33K0_22_68_3 0x6DD5 /* BTR config 33.0 kBaud */
#define BTR_16M_33K3_22_68_3 0x4DD5 /* BTR config 33.3 kBaud */
#define BTR_16M_83K3_24_66_2 0x7EC7 /* BTR config 83.3 kBaud */
#define BTR_16M_100k_20_70_3 0x5CC7 /* BTR config  100 kBaud */
#define BTR_16M_125k_16_68_2 0x4987 /* BTR config  125 kBaud */
#define BTR_16M_500k_16_68_2 0x4981 /* BTR config  500 kBaud */
#define BTR_16M_1M00_16_68_2 0x4980 /* BTR config  1.0 MBaud */

// The following macros convert from identifier value to the appropriate
// I/O register value and vise versa. These macros should be used for
// constant identifier values.
// The actual order of ID bits in the register can be found in the manual.
// ID (11bit-IDs uses Bit 28..18
//    (29bit-IDs uses Bit 28...0

#define MSG2STD(msg) ( (unsigned short )(msg) >>  3 & 0x000000FF  \
                     | (unsigned short )(msg) << 13 & 0x0000FF00  )

#define MSG2EXT(msg) ( (unsigned long  )(msg) >> 21 & 0x000000FF  \
                     | (unsigned long  )(msg) >>  5 & 0x0000FF00  \
                     | (unsigned long  )(msg) << 11 & 0x00FF0000  \
                     | (unsigned long  )(msg) << 27 & 0xFF000000  )

#define STD2MSG(reg) ( ((unsigned short)(reg) & 0x000000FF) <<  3  \
                     | ((unsigned short)(reg) & 0x0000FF00) >> 13  )

#define EXT2MSG(reg) ( ((unsigned long )(reg) & 0x000000FF) << 21  \
                     | ((unsigned long )(reg) & 0x0000FF00) <<  5  \
                     | ((unsigned long )(reg) & 0x00FF0000) >> 11  \
                     | ((unsigned long )(reg) & 0xFF000000) >> 27  )



void CAN0_init(void);
void CAN0_buffer1(void);
unsigned char GetCan0Data (char  x, unsigned char *BufPtr);
void SendCan0Data(unsigned char buffer, unsigned int str[]);
void canReadTask(void);
void canWriteTask(void);


#endif /* CAN_H_ */
