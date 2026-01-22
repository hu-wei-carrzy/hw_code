################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/BSP/BSP_TIM/BSP_TIM.c 

OBJS += \
./Sources/PLF/source/BSP/BSP_TIM/BSP_TIM.o 

C_DEPS += \
./Sources/PLF/source/BSP/BSP_TIM/BSP_TIM.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/BSP/BSP_TIM/%.o: ../Sources/PLF/source/BSP/BSP_TIM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/BSP/BSP_TIM/BSP_TIM.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


