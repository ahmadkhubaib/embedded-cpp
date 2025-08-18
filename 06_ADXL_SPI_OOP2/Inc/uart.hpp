/*
 * uart.hpp
 *
 *  Created on: Aug 13, 2025
 *      Author: ahmad
 */

#ifndef UART_HPP_
#define UART_HPP_


#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>

void uart2_tx_rx_init(void);
char uart2_read(void);


#endif /* UART_HPP_ */
