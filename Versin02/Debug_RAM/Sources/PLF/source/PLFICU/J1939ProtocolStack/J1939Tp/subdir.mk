################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/J1939Tp.c \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/J1939Tp_LCfg.c 

OBJS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/J1939Tp.o \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/J1939Tp_LCfg.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/J1939Tp.d \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/J1939Tp_LCfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/%.o: ../Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/J1939ProtocolStack/J1939Tp/J1939Tp.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


