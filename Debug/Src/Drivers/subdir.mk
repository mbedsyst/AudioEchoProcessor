################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Drivers/CLOCK.c \
../Src/Drivers/LED.c \
../Src/Drivers/SPI.c \
../Src/Drivers/UART.c 

OBJS += \
./Src/Drivers/CLOCK.o \
./Src/Drivers/LED.o \
./Src/Drivers/SPI.o \
./Src/Drivers/UART.o 

C_DEPS += \
./Src/Drivers/CLOCK.d \
./Src/Drivers/LED.d \
./Src/Drivers/SPI.d \
./Src/Drivers/UART.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Drivers/%.o Src/Drivers/%.su Src/Drivers/%.cyclo: ../Src/Drivers/%.c Src/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -DSTM32F401xE -D__FPU_PRESENT -DARM_MATH_CM4 -c -I../Inc -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Device/ST/STM32F4xx/Include" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Include" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Lib/GCC" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Drivers

clean-Src-2f-Drivers:
	-$(RM) ./Src/Drivers/CLOCK.cyclo ./Src/Drivers/CLOCK.d ./Src/Drivers/CLOCK.o ./Src/Drivers/CLOCK.su ./Src/Drivers/LED.cyclo ./Src/Drivers/LED.d ./Src/Drivers/LED.o ./Src/Drivers/LED.su ./Src/Drivers/SPI.cyclo ./Src/Drivers/SPI.d ./Src/Drivers/SPI.o ./Src/Drivers/SPI.su ./Src/Drivers/UART.cyclo ./Src/Drivers/UART.d ./Src/Drivers/UART.o ./Src/Drivers/UART.su

.PHONY: clean-Src-2f-Drivers

