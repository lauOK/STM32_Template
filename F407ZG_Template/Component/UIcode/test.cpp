/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-11-17     Tibbers       the first version
 */
#include <stm32f4xx_hal.h>
#include <stdio.h>

bool test1(void)
{
    uint8_t a = 10;
    uint8_t b = 11;
    if (a < b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void task_app1(bool M)
{
    if(M)
    {
        printf("hello");
    }
    else {
        printf("nook");
    }
}
