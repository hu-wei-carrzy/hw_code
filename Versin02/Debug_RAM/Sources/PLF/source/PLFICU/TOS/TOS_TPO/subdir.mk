################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/TOS/TOS_TPO/TOS_TPO.c \
../Sources/PLF/source/PLFICU/TOS/TOS_TPO/TOS_TPO2.c 

OBJS += \
./Sources/PLF/source/PLFICU/TOS/TOS_TPO/TOS_TPO.o \
./Sources/PLF/source/PLFICU/TOS/TOS_TPO/TOS_TPO2.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/TOS/TOS_TPO/TOS_TPO.d \
./Sources/PLF/source/PLFICU/TOS/TOS_TPO/TOS_TPO2.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/TOS/TOS_TPO/%.o: ../Sources/PLF/source/PLFICU/TOS/TOS_TPO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/TOS/TOS_TPO/TOS_TPO.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


