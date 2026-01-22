################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939_INCLUDE/J1939_Routine.c 

OBJS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939_INCLUDE/J1939_Routine.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939_INCLUDE/J1939_Routine.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939_INCLUDE/%.o: ../Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939_INCLUDE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939_INCLUDE/J1939_Routine.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


