################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/APPBT/App_Boot.c \
../Sources/PLF/source/APPBT/App_watchdog.c 

OBJS += \
./Sources/PLF/source/APPBT/App_Boot.o \
./Sources/PLF/source/APPBT/App_watchdog.o 

C_DEPS += \
./Sources/PLF/source/APPBT/App_Boot.d \
./Sources/PLF/source/APPBT/App_watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/APPBT/%.o: ../Sources/PLF/source/APPBT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/APPBT/App_Boot.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


