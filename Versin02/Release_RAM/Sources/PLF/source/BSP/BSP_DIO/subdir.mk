################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/BSP/BSP_DIO/BSP_DIO.c \
../Sources/PLF/source/BSP/BSP_DIO/BSP_DIO_CFG_GEN.c 

OBJS += \
./Sources/PLF/source/BSP/BSP_DIO/BSP_DIO.o \
./Sources/PLF/source/BSP/BSP_DIO/BSP_DIO_CFG_GEN.o 

C_DEPS += \
./Sources/PLF/source/BSP/BSP_DIO/BSP_DIO.d \
./Sources/PLF/source/BSP/BSP_DIO/BSP_DIO_CFG_GEN.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/BSP/BSP_DIO/%.o: ../Sources/PLF/source/BSP/BSP_DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/BSP/BSP_DIO/BSP_DIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


