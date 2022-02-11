#ifndef _DRV_LCD_H
#define _DRV_LCD_H

#include <stm32f4xx_hal.h>
#include "lcd_spi_port.h"

#include "lvgl\lvgl.h"

void LCD_Fill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color);
void LCD_DrawPoint(uint16_t x, uint16_t y, uint16_t color);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawCircle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color);
#ifdef LCD_SHOW_CHINESE
void LCD_ShowChinese(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese12x12(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese16x16(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese24x24(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese32x32(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
#endif
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowString(uint16_t x, uint16_t y, const uint8_t *p, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowIntNum(uint16_t x, uint16_t y, uint16_t num, uint8_t len, uint16_t fc, uint16_t bc, uint8_t sizey);
void LCD_ShowFloatNum1(uint16_t x, uint16_t y, float num, uint8_t len, uint16_t fc, uint16_t bc, uint8_t sizey);
void LCD_ShowPicture(uint16_t x, uint16_t y, uint16_t length, uint16_t width, const uint8_t pic[]);


void Lv_DrawPoint(int16_t x, int16_t y, uint16_t color);
void LVGL_Fill(int16_t xsta, int16_t ysta, int16_t xend, int16_t yend, lv_color_t *color_p);

//画笔颜色
#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40      //棕色
#define BRRED 0XFC07      //棕红色
#define GRAY 0X8430       //灰色
#define DARKBLUE 0X01CF   //深蓝色
#define LIGHTBLUE 0X7D7C  //浅蓝色
#define GRAYBLUE 0X5458   //灰蓝色
#define LIGHTGREEN 0X841F //浅绿色
#define LGRAY 0XC618      //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE 0XA651  //浅灰蓝色(中间层颜色)
#define LBBLUE 0X2B12     //浅棕蓝色(选择条目的反色)

#endif