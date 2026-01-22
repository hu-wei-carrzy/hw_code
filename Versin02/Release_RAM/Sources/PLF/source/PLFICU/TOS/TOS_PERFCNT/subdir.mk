################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/TOS/TOS_PERFCNT/TOS_PERFCNT.c 

OBJS += \
./Sources/PLF/source/PLFICU/TOS/TOS_PERFCNT/TOS_PERFCNT.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/TOS/TOS_PERFCNT/TOS_PERFCNT.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/TOS/TOS_PERFCNT/%.o: ../Sources/PLF/source/PLFICU/TOS/TOS_PERFCNT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/TOS/TOS_PERFCNT/TOS_PERFCNT.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


