################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/BSP/BSP_EEP/BSP_EEP.c 

OBJS += \
./Sources/PLF/source/BSP/BSP_EEP/BSP_EEP.o 

C_DEPS += \
./Sources/PLF/source/BSP/BSP_EEP/BSP_EEP.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/BSP/BSP_EEP/%.o: ../Sources/PLF/source/BSP/BSP_EEP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/BSP/BSP_EEP/BSP_EEP.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


