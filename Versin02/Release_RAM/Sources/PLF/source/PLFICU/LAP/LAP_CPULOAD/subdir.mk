################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics.c \
../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics_Cfg.c \
../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics_RI.c 

OBJS += \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics.o \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics_Cfg.o \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics_RI.o 

C_DEPS += \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics.d \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics_Cfg.d \
./Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics_RI.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/%.o: ../Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/PLF/source/PLFICU/LAP/LAP_CPULOAD/SRV_CpuMetrics.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


