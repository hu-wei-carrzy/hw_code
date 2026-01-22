################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/DAT/DAT_BLDC/DAT_BLDC.c 

OBJS += \
./Sources/PLF/source/PLFICU/DAT/DAT_BLDC/DAT_BLDC.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/DAT/DAT_BLDC/DAT_BLDC.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/DAT/DAT_BLDC/%.o: ../Sources/PLF/source/PLFICU/DAT/DAT_BLDC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/DAT/DAT_BLDC/DAT_BLDC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


