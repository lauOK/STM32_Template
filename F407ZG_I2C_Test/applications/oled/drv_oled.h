/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-11-09     Tibbers       the first version
 */
#ifndef APPLICATIONS_BSP_BSP_OLED_H_
#define APPLICATIONS_BSP_BSP_OLED_H_

#include <stm32f4xx_hal.h>
#include <stdlib.h>
#include <drv_i2c.h>

typedef i2c_dev oled_dev_t;

oled_dev_t* oled_dev;

#define OLED_CMD  0
#define OLED_DATA 1

void OLED_ColorTurn(uint8_t i);
void OLED_DisplayTurn(uint8_t i);
void Send_Byte(uint8_t dat);
void OLED_WR_Byte(uint8_t dat,uint8_t mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t mode);
void OLED_DrawCircle(uint8_t x,uint8_t y,uint8_t r);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size1,uint8_t mode);
void OLED_ShowChar6x8(uint8_t x,uint8_t y,uint8_t chr,uint8_t mode);
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t size1,uint8_t mode);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size1,uint8_t mode);
void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t num,uint8_t size1,uint8_t mode);
void OLED_ScrollDisplay(uint8_t num,uint8_t space,uint8_t mode,uint8_t size);
void OLED_ShowPicture(uint8_t x,uint8_t y,uint8_t sizex,uint8_t sizey,uint8_t BMP[],uint8_t mode);
void OLED_Init(void);

#endif /* APPLICATIONS_BSP_BSP_OLED_H_ */
