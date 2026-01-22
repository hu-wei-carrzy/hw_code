################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CTL/DAT_CTL.c 

OBJS += \
./Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CTL/DAT_CTL.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CTL/DAT_CTL.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CTL/%.o: ../Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CTL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CTL/DAT_CTL.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


