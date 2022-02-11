#ifndef _DELAY_H_
#define	_DELAY_H_

#include<stm32f4xx_hal.h>

#ifdef  __cplusplus
extern "C" {
#endif


void wait_ms(unsigned long ms_time);
void wait_us(unsigned long us_time);

#ifdef  __cplusplus
}
#endif

#endif

