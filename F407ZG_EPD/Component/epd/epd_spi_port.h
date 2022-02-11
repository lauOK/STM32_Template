/**
 * @file epd_spi_port.h
 * @author Sid Lau
 * @brief Spi driver for WaveShare E-Paper Display
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _EPD_SPI_PORT_H_
#define _EPD_SPI_PORT_H_

#include "main.h"
#include "stm32f4xx_hal.h"
#include "delay.h"
#include <stdint.h>
#include <stdio.h>

/**
 * e-Paper GPIO
**/
#define EPD_RST_PIN     RST_GPIO_Port, RST_Pin
#define EPD_DC_PIN      DC_GPIO_Port, DC_Pin
#define EPD_CS_PIN      CS_GPIO_Port, CS_Pin
#define EPD_BUSY_PIN    BUSY_GPIO_Port, BUSY_Pin

/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value) 	HAL_GPIO_WritePin(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) 				HAL_GPIO_ReadPin(_pin)


void EPD_SPI_WriteByte(uint8_t data);
uint8_t  EPD_Module_Init(void);
void EPD_Module_Exit(void);
#endif
