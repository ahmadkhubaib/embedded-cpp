#include "led.hpp"
#include "usart.hpp"

int main() {
	GPIO led(GPIOA, 5, true); // Create an instance of GPIO for pin PA5 as output
	GPIO button(GPIOC, 13, false); // Create an instance of GPIO for pin PC13 as input

	USART usart(USART2, 115200); // Create an instance of USART for USART2 with baud rate 115200

	while (1) {
		if (!button.read()) {
			led.toggle(); // Toggle the LED state
			usart.sendString("Hello, USART...LED TOGGLE!\n"); // Send a string over USART

		}
	}
}
