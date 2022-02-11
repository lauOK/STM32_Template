################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
Z:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Src/main.c \
Z:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Src/stm32f4xx_hal_msp.c \
Z:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Src/stm32f4xx_it.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: Z:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Src/main.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DUSE_HAL_DRIVER -DSTM32F407xx -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Inc -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/STM32F4xx_HAL_Driver/Inc -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/CMSIS/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Application/User/stm32f4xx_hal_msp.o: Z:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Src/stm32f4xx_hal_msp.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DUSE_HAL_DRIVER -DSTM32F407xx -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Inc -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/STM32F4xx_HAL_Driver/Inc -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/CMSIS/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Application/User/stm32f4xx_it.o: Z:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Src/stm32f4xx_it.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DUSE_HAL_DRIVER -DSTM32F407xx -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Inc -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/STM32F4xx_HAL_Driver/Inc -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IZ:/Project/STM32_Project/F407ZG/F407ZG_Seria_Test/Drivers/CMSIS/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

