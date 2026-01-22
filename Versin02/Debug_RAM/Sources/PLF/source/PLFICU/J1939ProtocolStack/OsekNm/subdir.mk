################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm.c \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm_App.c \
../Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm_Cfg.c 

OBJS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm.o \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm_App.o \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm_Cfg.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm.d \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm_App.d \
./Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/%.o: ../Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/J1939ProtocolStack/OsekNm/OsekNm.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


