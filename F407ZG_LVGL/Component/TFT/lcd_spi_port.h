#ifndef _LCD_SPI_PORT_H
#define _LCD_SPI_PORT_H

#include <stm32f4xx_hal.h>
#include <main.h>
#include <spi.h>
#include <delay.h>

extern SPI_HandleTypeDef hspi1;

#define USE_HORIZONTAL 0

#define LCD_W 240
#define LCD_H 240

#define LCD_RES(n) (n ? HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_RESET))
#define LCD_DC(n) (n ? HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_RESET))
#define LCD_BLK(n) (n ? HAL_GPIO_WritePin(BLK_GPIO_Port, BLK_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(BLK_GPIO_Port, BLK_Pin, GPIO_PIN_RESET))


void LVGL_Address_Set(int16_t xsta, int16_t ysta, int16_t xend, int16_t yend);
void LCD_Address_Set(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend);
void LCD_WR_DATA(uint8_t data);
void LCD_WR_CMD(uint8_t cmd);
void LCD_Init(void);
void LCD_WR_DATA16(uint16_t data);

#endif
