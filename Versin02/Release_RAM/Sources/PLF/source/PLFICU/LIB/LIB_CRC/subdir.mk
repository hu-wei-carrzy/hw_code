################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LIB/LIB_CRC/Lib_Crc_16.c \
../Sources/PLF/source/PLFICU/LIB/LIB_CRC/Lib_Crc_32.c 

OBJS += \
./Sources/PLF/source/PLFICU/LIB/LIB_CRC/Lib_Crc_16.o \
./Sources/PLF/source/PLFICU/LIB/LIB_CRC/Lib_Crc_32.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LIB/LIB_CRC/Lib_Crc_16.d \
./Sources/PLF/source/PLFICU/LIB/LIB_CRC/Lib_Crc_32.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LIB/LIB_CRC/%.o: ../Sources/PLF/source/PLFICU/LIB/LIB_CRC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LIB/LIB_CRC/Lib_Crc_16.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


