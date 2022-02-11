/*******************************************
 * @file lcd_spi_port.c
 * @author Sid Lau
 * @brief lcd spi port
 * @version 0.1
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 ******************************************/
#include <lcd_spi_port.h>

void LCD_WR_CMD(uint8_t cmd)
{
    LCD_DC(0);
    HAL_SPI_Transmit_DMA(&hspi1, &cmd, 1);
    // SPI1->DR = cmd;
    // while ((SPI1->SR & 1 << 1) == 0);
    LCD_DC(1);
}

void LCD_WR_DATA(uint8_t data)
{
    //HAL_SPI_Transmit_DMA(&hspi1, &data, 1);
    SPI1->DR = data;
    while ((SPI1->SR & 1 << 1) == 0);
}

void LCD_WR_DATA16(uint16_t data)
{
    uint8_t temp1 = data >> 8;
    uint8_t temp2 = data;
    //HAL_SPI_Transmit_DMA(&hspi1, &temp1, 1);
    //HAL_SPI_Transmit_DMA(&hspi1, &temp2, 1);
    SPI1->DR = temp1;
    while ((SPI1->SR & 1 << 1) == 0);
    SPI1->DR = temp2;
    while ((SPI1->SR & 1 << 1) == 0);
}

void LCD_Address_Set(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend)
{
#if (USE_HORIZONTAL == 0)
    LCD_WR_CMD(0x2A);
    LCD_WR_DATA16(xsta);
    LCD_WR_DATA16(xend);
    LCD_WR_CMD(0x2B);
    LCD_WR_DATA16(ysta);
    LCD_WR_DATA16(yend);
    LCD_WR_CMD(0x2C);
#elif (USE_HORIZONTAL == 1)
    LCD_WR_CMD(0x2A);
    LCD_WR_DATA16(xsta);
    LCD_WR_DATA16(xend);
    LCD_WR_CMD(0x2B);
    LCD_WR_DATA16(ysta + 80);
    LCD_WR_DATA16(yend + 80);
    LCD_WR_CMD(0x2C);
#elif (USE_HORIZONTAL == 2)
    LCD_WR_CMD(0x2A);
    LCD_WR_DATA16(xsta);
    LCD_WR_DATA16(xend);
    LCD_WR_CMD(0x2B);
    LCD_WR_DATA16(ysta);
    LCD_WR_DATA16(yend);
    LCD_WR_CMD(0x2C);
#elif (USE_HORIZONTAL == 3)
    LCD_WR_CMD(0x2A);
    LCD_WR_DATA16(xsta + 80);
    LCD_WR_DATA16(xend + 80);
    LCD_WR_CMD(0x2B);
    LCD_WR_DATA16(ysta);
    LCD_WR_DATA16(yend);
    LCD_WR_CMD(0x2C);
#endif
}

void LCD_Init(void)
{
    LCD_RES(0);
    wait_ms(100);
    LCD_RES(1);
    wait_ms(100);

    LCD_BLK(1);
    wait_ms(100);

    LCD_WR_CMD(0x11);
    wait_ms(120);
    LCD_WR_CMD(0x36);

#if (USE_HORIZONTAL == 0)
    LCD_WR_DATA(0x00);
#elif (USE_HORIZONTAL == 1)
    LCD_WR_DATA(0xC0);
#elif (USE_HORIZONTAL == 2)
    LCD_WR_DATA(0x70);
#elif (USE_HORIZONTAL == 3)
    LCD_WR_DATA(0xA0);
#endif

    LCD_WR_CMD(0x3A);
    LCD_WR_DATA(0x05);

    LCD_WR_CMD(0xB2);
    LCD_WR_DATA(0x0C);
    LCD_WR_DATA(0x0C);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x33);
    LCD_WR_DATA(0x33);

    LCD_WR_CMD(0xB7);
    LCD_WR_DATA(0x35);

    LCD_WR_CMD(0xBB);
    LCD_WR_DATA(0x37);

    LCD_WR_CMD(0xC0);
    LCD_WR_DATA(0x2C);

    LCD_WR_CMD(0xC2);
    LCD_WR_DATA(0x01);

    LCD_WR_CMD(0xC3);
    LCD_WR_DATA(0x12);

    LCD_WR_CMD(0xC4);
    LCD_WR_DATA(0x20);

    LCD_WR_CMD(0xC6);
    LCD_WR_DATA(0x0F);

    LCD_WR_CMD(0xD0);
    LCD_WR_DATA(0xA4);
    LCD_WR_DATA(0xA1);

    LCD_WR_CMD(0xE0);
    LCD_WR_DATA(0xD0);
    LCD_WR_DATA(0x04);
    LCD_WR_DATA(0x0D);
    LCD_WR_DATA(0x11);
    LCD_WR_DATA(0x13);
    LCD_WR_DATA(0x2B);
    LCD_WR_DATA(0x3F);
    LCD_WR_DATA(0x54);
    LCD_WR_DATA(0x4C);
    LCD_WR_DATA(0x18);
    LCD_WR_DATA(0x0D);
    LCD_WR_DATA(0x0B);
    LCD_WR_DATA(0x1F);
    LCD_WR_DATA(0x23);

    LCD_WR_CMD(0xE1);
    LCD_WR_DATA(0xD0);
    LCD_WR_DATA(0x04);
    LCD_WR_DATA(0x0C);
    LCD_WR_DATA(0x11);
    LCD_WR_DATA(0x13);
    LCD_WR_DATA(0x2C);
    LCD_WR_DATA(0x3F);
    LCD_WR_DATA(0x44);
    LCD_WR_DATA(0x51);
    LCD_WR_DATA(0x2F);
    LCD_WR_DATA(0x1F);
    LCD_WR_DATA(0x1F);
    LCD_WR_DATA(0x20);
    LCD_WR_DATA(0x23);
    LCD_WR_CMD(0x21);

    LCD_WR_CMD(0x29);
}
