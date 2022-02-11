#include <drv_at24cxx.h>
#include <string.h>
#include <stdlib.h>
#include <at24cxx_i2c_port.h>

/****A0 A1 A2 connect GND********/
#define AT24Cxx_WRITE_ADDR 0xA0
#define AT24Cxx_READ_ADDR  0xA1

#if (E2P_TYPE == AT24C01)
    #define AT24CXX_PAGE_BYTE               8
    #define AT24CXX_MAX_MEM_ADDRESS         128
#elif (E2P_TYPE == AT24C02)
    #define AT24CXX_PAGE_BYTE               8
    #define AT24CXX_MAX_MEM_ADDRESS         256
#elif (E2P_TYPE == AT24C04)
    #define AT24CXX_PAGE_BYTE               16
    #define AT24CXX_MAX_MEM_ADDRESS         512
#elif (E2P_TYPE == AT24C08)
    #define AT24CXX_PAGE_BYTE               16
    #define AT24CXX_MAX_MEM_ADDRESS         1024
#elif (E2P_TYPE == AT24C16)
    #define AT24CXX_PAGE_BYTE               16
    #define AT24CXX_MAX_MEM_ADDRESS         2048
#elif (E2P_TYPE == AT24C32)
    #define AT24CXX_PAGE_BYTE               32
    #define AT24CXX_MAX_MEM_ADDRESS         4096
#elif (E2P_TYPE == AT24C64)
    #define AT24CXX_PAGE_BYTE               32
    #define AT24CXX_MAX_MEM_ADDRESS         8192
#elif (E2P_TYPE == AT24C128)
    #define AT24CXX_PAGE_BYTE               64
    #define AT24CXX_MAX_MEM_ADDRESS         16384
#elif (E2P_TYPE == AT24C256)
    #define AT24CXX_PAGE_BYTE               64
    #define AT24CXX_MAX_MEM_ADDRESS         32768
#elif (E2P_TYPE == AT24C512)
    #define AT24CXX_PAGE_BYTE               128
    #define AT24CXX_MAX_MEM_ADDRESS         65536
#endif

uint8_t at24cxx_check(at24_dev_t *dev)
{
    uint8_t temp;
    uint8_t checkbuff = 0x55;

    i2c_read_data(dev, AT24Cxx_READ_ADDR, AT24CXX_MAX_MEM_ADDRESS - 1, &temp, 1);
    if (temp == 0x55) return 0;
    else
    {
        i2c_write_data(dev, AT24Cxx_WRITE_ADDR, AT24CXX_MAX_MEM_ADDRESS - 1, &checkbuff, 1);
        wait_ms(5);
        i2c_read_data(dev, AT24Cxx_READ_ADDR, AT24CXX_MAX_MEM_ADDRESS - 1, &temp, 1);
        if (temp == 0x55) return 0;
    }
    return 1;
}

uint8_t at24cxx_read(at24_dev_t *dev, uint32_t ReadAddr, uint8_t *pBuffer, uint16_t NumToRead)
{
    if(ReadAddr + NumToRead > AT24CXX_MAX_MEM_ADDRESS)
    {
        return 0;
    }
    while (NumToRead--)
    {
        i2c_start(dev);
        i2c_write_byte(dev, I2C_WRITE(AT24Cxx_WRITE_ADDR));
        i2c_write_byte(dev, ReadAddr++);
        i2c_start(dev);
        i2c_write_byte(dev, I2C_READ(AT24Cxx_READ_ADDR));

        *pBuffer++ = i2c_read_byte(dev, 1);
    }
    i2c_stop(dev);
    return 1;
}

uint8_t at24cxx_write(at24_dev_t *dev, uint32_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite)
{
    if(WriteAddr + NumToWrite > AT24CXX_MAX_MEM_ADDRESS)
    {
        return 0;
    }
    while (NumToWrite--)
    {
        i2c_start(dev);
        i2c_write_byte(dev, I2C_WRITE(AT24Cxx_WRITE_ADDR));
        i2c_write_byte(dev, WriteAddr++);
        i2c_write_byte(dev, *pBuffer++);
        i2c_stop(dev);
        wait_ms(5);
    }
    return 1;
}

at24_dev_t* at24cxx_Init(const char* AT24CXX_I2C_BUS)
{
    at24cxx_i2c_init();
    at24_dev_t *dev = i2c_obj_find(AT24CXX_I2C_BUS);
    if (at24cxx_check(dev))
    {
        return NULL;
    }
    return dev;
}
