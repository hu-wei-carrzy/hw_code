################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/BSP/BSP_I2C/BSP_I2C.c \
../Sources/PLF/source/BSP/BSP_I2C/I2C_REAL.c \
../Sources/PLF/source/BSP/BSP_I2C/I2C_SIM.c 

OBJS += \
./Sources/PLF/source/BSP/BSP_I2C/BSP_I2C.o \
./Sources/PLF/source/BSP/BSP_I2C/I2C_REAL.o \
./Sources/PLF/source/BSP/BSP_I2C/I2C_SIM.o 

C_DEPS += \
./Sources/PLF/source/BSP/BSP_I2C/BSP_I2C.d \
./Sources/PLF/source/BSP/BSP_I2C/I2C_REAL.d \
./Sources/PLF/source/BSP/BSP_I2C/I2C_SIM.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/BSP/BSP_I2C/%.o: ../Sources/PLF/source/BSP/BSP_I2C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/BSP/BSP_I2C/BSP_I2C.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


