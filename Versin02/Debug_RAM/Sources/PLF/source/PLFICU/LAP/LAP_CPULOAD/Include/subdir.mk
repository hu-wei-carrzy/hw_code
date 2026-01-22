################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Include/LIB_Mem_C.c 

OBJS += \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Include/LIB_Mem_C.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Include/LIB_Mem_C.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Include/%.o: ../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Include/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/Include/LIB_Mem_C.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


