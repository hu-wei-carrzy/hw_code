################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/CanIf.c \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/CanIf_Lcfg.c 

OBJS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/CanIf.o \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/CanIf_Lcfg.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/CanIf.d \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/CanIf_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/%.o: ../Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/J1939ProtocolStack/CanIf/CanIf.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


