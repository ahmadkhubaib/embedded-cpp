#include <stdint.h>
#include <stdio.h>
#include <uart.hpp>
#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define LED_PIN_5	(1U<<5)

char key;

int main(void){

	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |=  (1U<<10);
	GPIOA->MODER &=~  (1U<<11);

	uart2_tx_rx_init();

	printf("Baudrate is 115200, USART module is working as rx tx enter 1 to turn on board led press other key to turn it off");

	 while(1){

		 key = uart2_read();
		 if(key == '1'){
			 GPIOA->ODR |= LED_PIN_5;
		 }else{
			 GPIOA->ODR &= ~LED_PIN_5;
		 }
	}
}


