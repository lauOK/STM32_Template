################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../applications/sfud/src/sfud.c \
../applications/sfud/src/sfud_sfdp.c 

OBJS += \
./applications/sfud/src/sfud.o \
./applications/sfud/src/sfud_sfdp.o 

C_DEPS += \
./applications/sfud/src/sfud.d \
./applications/sfud/src/sfud_sfdp.d 


# Each subdirectory must supply rules for building sources it contributes
applications/sfud/src/%.o: ../applications/sfud/src/%.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F4 -DUSE_HAL_DRIVER -DSTM32F407xx -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\drivers" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\applications\sfud\inc" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\applications\sfud\port" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\applications\sfud\src" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\libraries\CMSIS\Include" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\libraries\CMSIS\RTOS\Template" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\libraries\STM32F4xx_HAL_Driver\Inc" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\libraries\STM32F4xx_HAL_Driver\Inc\Legacy" -I"Z:\Project\STM32_Project\F407ZG_SFUD_Test\applications" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
