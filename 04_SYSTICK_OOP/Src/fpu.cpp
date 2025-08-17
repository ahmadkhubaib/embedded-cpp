/*
 * fpu.cpp
 *
 *  Created on: Aug 16, 2025
 *      Author: ahmad
 */

#include "fpu.hpp"

void FPU_CP::enable(void) {
	SCB->CPACR |= (1 << 20);
	SCB->CPACR |= (1 << 21);
	SCB->CPACR |= (1 << 22);
	SCB->CPACR |= (1 << 23);
}

