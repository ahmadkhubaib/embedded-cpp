/*
 * fpu.cpp
 *
 *  Created on: Aug 16, 2025
 *      Author: ahmad
 */

#include "fpu.hpp"

FPU_CP::enable() {
	SCB->CPACR |= (1 << 20);
	SCB->CPACR |= (1 << 21);
	SCB->CPACR |= (1 << 22);
	SCB->CPACR |= (1 << 23);
}

