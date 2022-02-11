#ifndef __AT24CXX_H__
#define __AT24CXX_H__

#include <stm32f4xx_hal.h>
#include <sf_i2c/drv_i2c.h>

#define AT24C01     0
#define AT24C02     1
#define AT24C04     2
#define AT24C08     3
#define AT24C16     4
#define AT24C32     5
#define AT24C64     6
#define AT24C128    7
#define AT24C256    8
#define AT24C512    9
#define AT24CTYPE   10

#ifndef E2P_TYPE
#define E2P_TYPE     AT24C02
#endif

typedef i2c_dev at24_dev_t;

at24_dev_t* at24cxx_Init(const char* AT24CXX_I2C_BUS);
uint8_t at24cxx_read(at24_dev_t *dev, uint32_t ReadAddr, uint8_t *pBuffer, uint16_t NumToRead);
uint8_t at24cxx_write(at24_dev_t *dev, uint32_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite);

#endif
