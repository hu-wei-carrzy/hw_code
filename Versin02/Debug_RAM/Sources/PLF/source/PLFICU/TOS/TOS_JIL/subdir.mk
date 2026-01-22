################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/TOS/TOS_JIL/TOS_JIL.c 

OBJS += \
./Sources/PLF/source/PLFICU/TOS/TOS_JIL/TOS_JIL.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/TOS/TOS_JIL/TOS_JIL.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/TOS/TOS_JIL/%.o: ../Sources/PLF/source/PLFICU/TOS/TOS_JIL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/TOS/TOS_JIL/TOS_JIL.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


