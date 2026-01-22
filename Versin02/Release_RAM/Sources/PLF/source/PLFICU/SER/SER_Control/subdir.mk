################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/SER/SER_Control/SER_Control.c 

OBJS += \
./Sources/PLF/source/PLFICU/SER/SER_Control/SER_Control.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/SER/SER_Control/SER_Control.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/SER/SER_Control/%.o: ../Sources/PLF/source/PLFICU/SER/SER_Control/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/SER/SER_Control/SER_Control.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


