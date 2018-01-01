################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../serial/serial.c 

OBJS += \
./serial/serial.o 


# Each subdirectory must supply rules for building sources it contributes
serial/%.o: ../serial/%.c
	@echo 'Building file: $<'
	@echo 'Compiling C source files'
	fcc907s -cpu MB90543 -w 0 -INF srcin -T p,-B -I "C:\Users\phytech\Dropbox\eclipse\workspace\Fujitsu\dmx\scr" -O 0 -K NOUNROLL -K NOLIB -K NOEOPT -K NOADDSP -K NOALIAS -B -model MEDIUM -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


