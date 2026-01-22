################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LAP/LAP_EEP/LAP_EEP.c \
../Sources/PLF/source/PLFICU/LAP/LAP_EEP/LAP_EEP_CFG.c 

OBJS += \
./Sources/PLF/source/PLFICU/LAP/LAP_EEP/LAP_EEP.o \
./Sources/PLF/source/PLFICU/LAP/LAP_EEP/LAP_EEP_CFG.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LAP/LAP_EEP/LAP_EEP.d \
./Sources/PLF/source/PLFICU/LAP/LAP_EEP/LAP_EEP_CFG.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LAP/LAP_EEP/%.o: ../Sources/PLF/source/PLFICU/LAP/LAP_EEP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LAP/LAP_EEP/LAP_EEP.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


