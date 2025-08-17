/*
 * usart.hpp
 *
 *  Created on: Aug 15, 2025
 *      Author: ahmad
 */

#ifndef USART_HPP_
#define USART_HPP_

#include "stm32f4xx.h"
#include <stdint.h>

class USART {
	private:
        USART_TypeDef *usart;
        uint32_t baudRate;
	public:
        USART(USART_TypeDef *usart, uint32_t baudrate);
        void setBaudRate(uint32_t periph_clock);
        void sendChar(char c);
        void sendString(const char *str);
};



#endif /* USART_HPP_ */