/*
 * led.cpp
 *
 *  Created on: Aug 13, 2025
 *      Author: ahmad
 */
#include "led.hpp"

GPIO::GPIO(GPIO_TypeDef *port, uint8_t pin, bool isOutput) :
		port(port), pin(pin) {
	if (port == GPIOA) {
		RCC->AHB1ENR |= (1U << 0);
	} // Enable clock for GPIOA
	else if (port == GPIOB) {
		RCC->AHB1ENR |= (1U << 1);
	} // Enable clock for GPIOB
	else if (port == GPIOC) {
		RCC->AHB1ENR |= (1U << 2);
	} // Enable clock for GPIOC
	else if (port == GPIOD) {
		RCC->AHB1ENR |= (1U << 3);
	} // Enable clock for GPIOD
	else if (port == GPIOE) {
		RCC->AHB1ENR |= (1U << 4);
	} // Enable clock for GPIOE

	if (isOutput) {
		port->MODER |= (1U << (pin * 2)); // Set pin as output
		port->MODER &= ~(1U << (pin * 2 + 1));
	} else {
		port->MODER &= ~(3U << (pin * 2)); // Set pin as input
	}
}

void GPIO::toggle() {
	port->ODR ^= (1U << pin); // Toggle pin state
}
void GPIO::set() {
	port->ODR |= (1U << pin); // Set pin high
}
void GPIO::reset() {
	port->ODR &= ~(1U << pin); // Set pin low
}
bool GPIO::read() {
	return (port->IDR & (1U << pin)); // Read pin state
}

