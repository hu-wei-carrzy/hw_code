################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN.c \
../Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PANP.c \
../Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN_PIN_CFG.c \
../Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN_PIN_CFG_GEN.c 

OBJS += \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN.o \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PANP.o \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN_PIN_CFG.o \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN_PIN_CFG_GEN.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN.d \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PANP.d \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN_PIN_CFG.d \
./Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN_PIN_CFG_GEN.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/%.o: ../Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/DAT/DAT_AD/DAT_PAN/DAT_PAN.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


