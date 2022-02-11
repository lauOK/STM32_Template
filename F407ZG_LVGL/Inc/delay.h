#ifndef _DELAY_H_
#define	_DELAY_H_

#include<stm32f4xx_hal.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define SYSCLK 168

void HAL_Delay_us(uint32_t nus);

#ifdef  __cplusplus
}
#endif

#endif

