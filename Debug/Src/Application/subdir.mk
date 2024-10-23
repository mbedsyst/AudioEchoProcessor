################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Application/DATA.c \
../Src/Application/main.c 

OBJS += \
./Src/Application/DATA.o \
./Src/Application/main.o 

C_DEPS += \
./Src/Application/DATA.d \
./Src/Application/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Application/%.o Src/Application/%.su Src/Application/%.cyclo: ../Src/Application/%.c Src/Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -DSTM32F401xE -D__FPU_PRESENT -DARM_MATH_CM4 -c -I../Inc -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Device/ST/STM32F4xx/Include" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Include" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/Lib/GCC" -I"C:/Users/zalma/OneDrive/Documents/F401_DSP/ZZ_Echo_Generator/Headers/DSP/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Application

clean-Src-2f-Application:
	-$(RM) ./Src/Application/DATA.cyclo ./Src/Application/DATA.d ./Src/Application/DATA.o ./Src/Application/DATA.su ./Src/Application/main.cyclo ./Src/Application/main.d ./Src/Application/main.o ./Src/Application/main.su

.PHONY: clean-Src-2f-Application

