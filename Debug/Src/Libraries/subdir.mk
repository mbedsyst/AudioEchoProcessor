################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Libraries/ECHO.c \
../Src/Libraries/W25Qxx.c 

OBJS += \
./Src/Libraries/ECHO.o \
./Src/Libraries/W25Qxx.o 

C_DEPS += \
./Src/Libraries/ECHO.d \
./Src/Libraries/W25Qxx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Libraries/%.o Src/Libraries/%.su Src/Libraries/%.cyclo: ../Src/Libraries/%.c Src/Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -DSTM32F401xE -D__FPU_PRESENT -DARM_MATH_CM4 -c -I../Inc -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Device/ST/STM32F4xx/Include" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Include" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Lib/GCC" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Libraries

clean-Src-2f-Libraries:
	-$(RM) ./Src/Libraries/ECHO.cyclo ./Src/Libraries/ECHO.d ./Src/Libraries/ECHO.o ./Src/Libraries/ECHO.su ./Src/Libraries/W25Qxx.cyclo ./Src/Libraries/W25Qxx.d ./Src/Libraries/W25Qxx.o ./Src/Libraries/W25Qxx.su

.PHONY: clean-Src-2f-Libraries

