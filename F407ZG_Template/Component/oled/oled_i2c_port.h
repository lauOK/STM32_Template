/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-28     Tibbers       the first version
 */
#ifndef APPLICATIONS_BSP_I2C_H_
#define APPLICATIONS_BSP_I2C_H_

#include <stm32f4xx_hal.h>
#include <drv_i2c.h>

#define I2C0_PORT           GPIOE
#define I2C0_SCL_PIN        GPIO_PIN_14
#define I2C0_SDA_PIN        GPIO_PIN_12
#define I2C0_NAME           (char*)"i2c0"

void oled_i2c_init(void);

#endif /* APPLICATIONS_BSP_I2C_H_ */
