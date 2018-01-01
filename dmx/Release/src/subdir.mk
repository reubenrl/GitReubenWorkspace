################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_UPPER_SRCS += \
../src/START.ASM 

ASM_SRCS += \
../src/Mb90540.asm 

C_SRCS += \
../src/ADC.c \
../src/buffer.c \
../src/cmnd_line.c \
../src/debug_uart.c \
../src/ext_adc.c \
../src/file.c \
../src/i2c_sw.c \
../src/i2ceeprom.c \
../src/leds.c \
../src/one_wire.c \
../src/parsing_cmd.c \
../src/pwm.c \
../src/rtc.c \
../src/sbrk.c \
../src/serialTest.c \
../src/timer0.c \
../src/timer1.c \
../src/uart2.c \
../src/uart2_buffered.c \
../src/vectors.c \
../src/vt100.c 

OBJS += \
./src/ADC.o \
./src/Mb90540.o \
./src/START.o \
./src/buffer.o \
./src/cmnd_line.o \
./src/debug_uart.o \
./src/ext_adc.o \
./src/file.o \
./src/i2c_sw.o \
./src/i2ceeprom.o \
./src/leds.o \
./src/one_wire.o \
./src/parsing_cmd.o \
./src/pwm.o \
./src/rtc.o \
./src/sbrk.o \
./src/serialTest.o \
./src/timer0.o \
./src/timer1.o \
./src/uart2.o \
./src/uart2_buffered.o \
./src/vectors.o \
./src/vt100.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Compiling C source files'
	fcc907s -cpu MB90543 -w 0 -INF srcin -T p,-B -I "D:\GitReubenWorkspace\dmx\src\inc" -I "D:\GitReubenWorkspace\dmx\config" -O 0 -K NOUNROLL -K NOLIB -K NOEOPT -K NOADDSP -K NOALIAS -B -model MEDIUM -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.asm
	@echo 'Building file: $<'
	@echo 'Assembling source files'
	fasm907s -cpu MB90543 -w 0 -pl 60 -pw 132 -linf OFF -lsrc OFF -lsec OFF -lcros OFF -linc OFF -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.ASM
	@echo 'Building file: $<'
	@echo 'Assembling source files'
	fasm907s -cpu MB90543 -w 0 -pl 60 -pw 132 -linf OFF -lsrc OFF -lsec OFF -lcros OFF -linc OFF -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


