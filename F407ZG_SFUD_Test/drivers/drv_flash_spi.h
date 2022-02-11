/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-09-14     Tibbers       the first version
 */
#ifndef APPLICATIONS_DRV_FLASH_H_
#define APPLICATIONS_DRV_FLASH_H_

#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

#define FLASH_CS_Pin    GPIO_PIN_14
#define FLASH_CS_Port   GPIOB

void MX_SPI1_Init(void);
void MX_GPIO_Init(void);

//uint8_t User_SPI_Trans_Rec(uint8_t Txdata);

#endif
