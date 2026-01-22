################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_SRI/LAP_SRI.c 

OBJS += \
./Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_SRI/LAP_SRI.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_SRI/LAP_SRI.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_SRI/%.o: ../Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_SRI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LAP/LAP_DIAG/LAP_SRI/LAP_SRI.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


