################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../applications/App/app_e2p.c 

OBJS += \
./applications/App/app_e2p.o 

C_DEPS += \
./applications/App/app_e2p.d 


# Each subdirectory must supply rules for building sources it contributes
applications/App/%.o: ../applications/App/%.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F4 -DUSE_HAL_DRIVER -DSTM32F407xx -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\applications\Bsp" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\applications\App" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\applications\Drive" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\drivers" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\libraries\CMSIS\Include" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\libraries\CMSIS\RTOS\Template" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\libraries\STM32F4xx_HAL_Driver\Inc" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\libraries\STM32F4xx_HAL_Driver\Inc\Legacy" -I"Z:\Project\STM32_Project\F407ZG_I2C_Test\applications" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
