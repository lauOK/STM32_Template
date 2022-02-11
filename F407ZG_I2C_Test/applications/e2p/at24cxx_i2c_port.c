/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-28     Tibbers       the first version
 */

#include <at24cxx_i2c_port.h>

__STATIC_INLINE void i2c1_sda_pin_out_low(void);
__STATIC_INLINE void i2c1_sda_pin_out_high(void);
__STATIC_INLINE void i2c1_scl_pin_out_low(void);
__STATIC_INLINE void i2c1_scl_pin_out_high(void);
__STATIC_INLINE uint8_t i2c1_sda_pin_read_level(void);
__STATIC_INLINE void i2c1_sda_pin_dir_input(void);
__STATIC_INLINE void i2c1_sda_pin_dir_output(void);

static i2c_dev i2c1_dev = {
    .name                    = I2C1_NAME,
    .speed                   = 20,
    .port.sda_pin_out_low    = i2c1_sda_pin_out_low,
    .port.sda_pin_out_high   = i2c1_sda_pin_out_high,
    .port.scl_pin_out_low    = i2c1_scl_pin_out_low,
    .port.scl_pin_out_high   = i2c1_scl_pin_out_high,
    .port.sda_pin_read_level = i2c1_sda_pin_read_level,
    .port.sda_pin_dir_input  = i2c1_sda_pin_dir_input,
    .port.sda_pin_dir_output = i2c1_sda_pin_dir_output,
};

__STATIC_INLINE void i2c1_sda_pin_out_low(void)
{
    HAL_GPIO_WritePin(I2C1_PORT, I2C1_SDA_PIN, RESET);
}
__STATIC_INLINE void i2c1_sda_pin_out_high(void)
{
    HAL_GPIO_WritePin(I2C1_PORT, I2C1_SDA_PIN, SET);
}
__STATIC_INLINE void i2c1_scl_pin_out_low(void)
{
    HAL_GPIO_WritePin(I2C1_PORT, I2C1_SCL_PIN, RESET);
}
__STATIC_INLINE void i2c1_scl_pin_out_high(void)
{
    HAL_GPIO_WritePin(I2C1_PORT, I2C1_SCL_PIN, SET);
}
__STATIC_INLINE uint8_t i2c1_sda_pin_read_level(void)
{
    return HAL_GPIO_ReadPin(I2C1_PORT, I2C1_SDA_PIN);
}
__STATIC_INLINE void i2c1_sda_pin_dir_input(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = I2C1_SDA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(I2C1_PORT, &GPIO_InitStruct);
}
__STATIC_INLINE void i2c1_sda_pin_dir_output(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = I2C1_SDA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(I2C1_PORT, &GPIO_InitStruct);
}
void at24cxx_i2c_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStruct.Pin = I2C1_SDA_PIN | I2C1_SCL_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(I2C1_PORT, &GPIO_InitStruct);

    i2c_init(&i2c1_dev);
}
