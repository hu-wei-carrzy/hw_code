################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_RWI/LAP_RWI.c 

OBJS += \
./Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_RWI/LAP_RWI.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_RWI/LAP_RWI.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_RWI/%.o: ../Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_RWI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_RWI/LAP_RWI.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


