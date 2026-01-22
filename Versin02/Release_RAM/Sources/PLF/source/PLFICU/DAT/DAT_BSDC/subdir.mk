################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/DAT/DAT_BSDC/DAT_BSDC.c 

OBJS += \
./Sources/PLF/source/PLFICU/DAT/DAT_BSDC/DAT_BSDC.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/DAT/DAT_BSDC/DAT_BSDC.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/DAT/DAT_BSDC/%.o: ../Sources/PLF/source/PLFICU/DAT/DAT_BSDC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/DAT/DAT_BSDC/DAT_BSDC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


