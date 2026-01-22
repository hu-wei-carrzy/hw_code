################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LDB/LDB_DIN/LDB_DIN.c 

OBJS += \
./Sources/PLF/source/PLFICU/LDB/LDB_DIN/LDB_DIN.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LDB/LDB_DIN/LDB_DIN.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LDB/LDB_DIN/%.o: ../Sources/PLF/source/PLFICU/LDB/LDB_DIN/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LDB/LDB_DIN/LDB_DIN.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


