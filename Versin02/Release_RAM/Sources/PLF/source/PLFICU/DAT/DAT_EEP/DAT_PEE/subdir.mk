################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/DAT/DAT_EEP/DAT_PEE/DAT_PEE.c 

OBJS += \
./Sources/PLF/source/PLFICU/DAT/DAT_EEP/DAT_PEE/DAT_PEE.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/DAT/DAT_EEP/DAT_PEE/DAT_PEE.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/DAT/DAT_EEP/DAT_PEE/%.o: ../Sources/PLF/source/PLFICU/DAT/DAT_EEP/DAT_PEE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/DAT/DAT_EEP/DAT_PEE/DAT_PEE.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


