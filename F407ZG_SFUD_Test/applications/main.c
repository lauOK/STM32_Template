/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-26     RT-Thread    first version
 */

#include <stdio.h>
#include <board.h>
#include "sfud.h"
#include "drv_flash_spi.h"

void test()
{
    uint8_t data1[20] = {0};
    uint8_t data2[20] = {0};

    //uint8_t buf1[] = "hello worldÁùÒ»";
    //uint8_t buf2[] = "hascovision";

    const sfud_flash *flash = sfud_get_device_table();

    //sfud_chip_erase(flash); HAL_Delay(20*1000);

    //sfud_write(flash, 0x000000, sizeof(buf1), buf1);
    //sfud_write(flash, 0x100000, sizeof(buf2), buf2);

    //sfud_erase(flash, 0x000000, 20); //delay >= 5

    //HAL_Delay(5);

    sfud_read(flash, 0x000000, 20, data1);
    sfud_read(flash, 0x100000, 20, data2);

    printf("sfud read 0x000000 is : %s\n",data1);
    printf("sfud read 0x100000 is : %s\n",data2);
}

int main(void)
{
    MX_SPI1_Init();
    MX_GPIO_Init();

    sfud_init();
    test();

    while (1)
    {
        wait_ms(1000);
    }
    return 0;
}
