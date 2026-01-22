################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Portable/SRV_CpuMetrics_TimerDriver.c 

OBJS += \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Portable/SRV_CpuMetrics_TimerDriver.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Portable/SRV_CpuMetrics_TimerDriver.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Portable/%.o: ../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Portable/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Portable/SRV_CpuMetrics_TimerDriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


