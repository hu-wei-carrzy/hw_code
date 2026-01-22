################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can.c \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can_Cbk.c \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can_PBcfg.c 

OBJS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can.o \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can_Cbk.o \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can_PBcfg.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can.d \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can_Cbk.d \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/%.o: ../Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/J1939ProtocolStack/CanDriver/Can.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


