/*
 * adxl.cpp
 *
 *  Created on: Aug 26, 2025
 *      Author: ahmad
 */

#include "adxl.hpp"

#define ADXL_DEVID_REG       0x00
#define ADXL_DEV_ADDR        0x53
#define ADXL_REG_DATA_FORMAT 0x31
#define ADXL_REG_POWER_CTL   0x2D
#define ADXL_REG_DATA_START  0x32
#define ADXL_RANGE_4G     	 0x01
#define ADXL_MEASURE         0x08
#define ADXL_READ_MASK       0x80
#define ADXL_MULTI_BYTE_MASK 0x40
#define ADXL_RESET           0x00
#define ADXL_SCALE_FACTOR    0.0078f // Scale factor for 4g range


ADXL::ADXL(SPI &spi, uint8_t device_addr) :
		spi(spi), device_addr(device_addr), x(0), y(0), z(0) {
	// Constructor to initialize the ADXL object
}

void ADXL::write_register(uint8_t reg, uint8_t value) {
	uint8_t data[2] = {(uint8_t)(reg | ADXL_MULTI_BYTE_MASK), value};
	spi.setCSLow();
	spi.sendData(data, 2);
	spi.setCSHigh();
}

void ADXL::read_register(uint8_t reg, uint8_t *data, uint8_t size) {
	reg |= ADXL_READ_MASK | ADXL_MULTI_BYTE_MASK;
	spi.setCSLow();
	spi.sendData(&reg, 1);
	spi.receiveData(data, size);
	spi.setCSHigh();
}

void ADXL::init() {
	write_register(ADXL_REG_DATA_FORMAT, ADXL_RANGE_4G);
	write_register(ADXL_REG_POWER_CTL, ADXL_RESET);
	write_register(ADXL_REG_POWER_CTL, ADXL_MEASURE);
}


void ADXL::update_acceleration() {
	uint8_t buffer[6];
	read_register(ADXL_REG_DATA_START, buffer, 6);
	x = (int16_t)((buffer[1] << 8) | buffer[0]);
	y = (int16_t)((buffer[3] << 8) | buffer[2]);
	z = (int16_t)((buffer[5] << 8) | buffer[4]);
}

int16_t ADXL::getX() {
	return x;
}
int16_t ADXL::getY() {
	return y;
}
int16_t ADXL::getZ() {
	return z;
}

int16_t ADXL::getXG() {
	return x * ADXL_SCALE_FACTOR;
}

int16_t ADXL::getYG() {
	return y * ADXL_SCALE_FACTOR;
}

int16_t ADXL::getZG() {
	return z * ADXL_SCALE_FACTOR;
}





