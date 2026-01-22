################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LIB/LIB_VER/LIB_VER.c 

OBJS += \
./Sources/PLF/source/PLFICU/LIB/LIB_VER/LIB_VER.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LIB/LIB_VER/LIB_VER.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LIB/LIB_VER/%.o: ../Sources/PLF/source/PLFICU/LIB/LIB_VER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LIB/LIB_VER/LIB_VER.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


