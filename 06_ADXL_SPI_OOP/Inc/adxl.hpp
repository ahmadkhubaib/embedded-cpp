/*
 * adxl.hpp
 *
 *  Created on: Aug 26, 2025
 *      Author: ahmad
 */

#ifndef ADXL_HPP_
#define ADXL_HPP_

#include "spi.hpp"
#include <cstdint>

class ADXL {
private:
	SPI &spi; // Pointer to the SPI object
	uint8_t device_addr;
	int16_t x, y, z; // Variables to store acceleration data

	void write_register(uint8_t reg, uint8_t value); // Write a value to a register
	void read_register(uint8_t reg, uint8_t *data, uint8_t size); // Read a value from a register

public:
	ADXL(SPI &spi, uint8_t device_addr = 0x53); // Constructor to initialize the ADXL object

	void init(); // Initialize the ADXL sensor
	void update_acceleration(); // Read acceleration data from the sensor
	int16_t getX(); // Get X-axis acceleration
	int16_t getY(); // Get Y-axis acceleration
	int16_t getZ(); // Get Z-axis acceleration
	int16_t getXG(); // Get X-axis acceleration in g
	int16_t getYG(); // Get Y-axis acceleration in g
	int16_t getZG(); // Get Z-axis acceleration in g
};
#endif /* ADXL_HPP_ */
