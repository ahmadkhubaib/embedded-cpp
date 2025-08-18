/*
 * spi.cpp
 *
 *  Created on: Aug 18, 2025
 *      Author: ahmad
 */

#include "spi.hpp"

#define SPI1EN      (1U << 12) // Enable clock for SPI1
#define GPIOAEN     (1U << 0)  // Enable clock for GPIOA
#define GPIOBEN     (1U << 1)  // Enable clock for GPIOB
#define GPIOCEN     (1U << 2)  // Enable clock for GPIOC
#define GPIODEN     (1U << 3)  // Enable clock for GPIOD
#define GPIOEEN     (1U << 4)  // Enable clock for GPIOE
#define SR_TXE      (1U << 1)  // Transmit buffer empty flag
#define SR_RXNE     (1U << 0)  // Receive buffer not empty flag
#define SR_BSY      (1U << 7)  // Busy flag

SPI::SPI(SPI_TypeDef *spiX, GPIO_TypeDef *gpioX, uint8_t cs_pin)
	: spiX(spiX), gpioX(gpioX), cs_pin(cs_pin) {

	// Enable the clock for the SPI peripheral
	if (gpioX == GPIOA) {
		RCC->AHB1ENR |= GPIOAEN;
	} else if (gpioX == GPIOB) {
		RCC->AHB1ENR |= GPIOBEN;
	} else if (gpioX == GPIOC) {
		RCC->AHB1ENR |= GPIOCEN;
	} else if (gpioX == GPIOD) {
		RCC->AHB1ENR |= GPIODEN;
	} else if (gpioX == GPIOE) {
		RCC->AHB1ENR |= GPIOEEN;
	}

	// Enable the clock for the SPI peripheral

}
