################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CDL/DAT_CDL.c 

OBJS += \
./Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CDL/DAT_CDL.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CDL/DAT_CDL.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CDL/%.o: ../Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CDL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/DAT/DAT_CAN/DAT_CDL/DAT_CDL.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


