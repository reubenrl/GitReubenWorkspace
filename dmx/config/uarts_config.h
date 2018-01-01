/*
 * uarts_config.h
 *
 *  Created on: Jun 4, 2014
 *      Author: reuben
 */

#ifndef UARTS_CONFIG_H_
#define UARTS_CONFIG_H_


#define UART_0		0
#define UART_1		1

// buffer memory allocation defines
// buffer sizes
#ifndef UART0_TX_BUFFER_SIZE
#define UART0_TX_BUFFER_SIZE		0x0040	///< number of bytes for uart0 transmit buffer
#endif
#ifndef UART0_RX_BUFFER_SIZE
#define UART0_RX_BUFFER_SIZE		0x0064	///< number of bytes for uart0 receive buffer
#endif
#ifndef UART1_TX_BUFFER_SIZE
#define UART1_TX_BUFFER_SIZE		0x0040	///< number of bytes for uart1 transmit buffer
#endif
#ifndef UART1_RX_BUFFER_SIZE
#define UART1_RX_BUFFER_SIZE		0x0064	///< number of bytes for uart1 receive buffer
#endif


#endif /* UARTS_CONFIG_H_ */
