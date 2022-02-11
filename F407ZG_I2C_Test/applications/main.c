/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-28     RT-Thread    first version
 */

#include <board.h>
#include <stm32f4xx_hal.h>
#include <stdio.h>

#include <drv_at24cxx.h>
#include <drv_oled.h>

void Task_E2P(void)
{
    uint8_t writebuf[] = "hascovision hascovision hascovision hascovision";
    uint8_t readbuf[256] = {0};

    at24_dev_t *dev = at24cxx_Init("i2c1");

    at24cxx_write(dev, 0, writebuf, sizeof(writebuf));
    at24cxx_read(dev, 0, readbuf, 256);

    printf("read is : %s\n", readbuf);
}

void Task_OLED(void)
{
    OLED_Init();
    OLED_ShowNum(0, 0, 12345678, 8, 8, 1);
    OLED_Refresh();
    wait_ms(2000);
    OLED_ScrollDisplay(3, 8, 1, 64);
}

int main(void)
{
    Task_E2P();
    Task_OLED();

    while (1)
    {
        printf("rtt\n");
        wait_ms(1000);
    }
    return 0;
}
