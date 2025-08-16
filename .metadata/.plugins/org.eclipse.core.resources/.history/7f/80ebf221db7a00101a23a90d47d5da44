#include "led.hpp"

int main() {
	GPIO led(GPIOA, 5, true); // Create an instance of GPIO for pin PA5 as output
	GPIO button(GPIOC, 13, false); // Create an instance of GPIO for pin PC13 as input

	while (1) {
		if (!button.read()) {
			led.toggle(); // Toggle the LED state

		}
	}
}
