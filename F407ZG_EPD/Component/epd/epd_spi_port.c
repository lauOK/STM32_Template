/**
 * @file epd_spi_port.c
 * @author Sid Lau
 * @brief Spi driver for WaveShare E-Paper Dispaly
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 */

#include "epd_spi_port.h"

extern SPI_HandleTypeDef hspi1;
void EPD_SPI_WriteByte(uint8_t data)
{
    HAL_SPI_Transmit(&hspi1, &data, 1, 1000);
}

uint8_t EPD_Module_Init(void)
{
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    return 0;
}

void EPD_Module_Exit(void)
{
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 0);
}
