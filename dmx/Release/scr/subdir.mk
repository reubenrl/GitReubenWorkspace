################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_UPPER_SRCS += \
../scr/START.ASM 

ASM_SRCS += \
../scr/Mb90540.asm 

C_SRCS += \
../scr/ADC.c \
../scr/buffer.c \
../scr/cmnd_line.c \
../scr/debug_uart.c \
../scr/ext_adc.c \
../scr/file.c \
../scr/i2c_sw.c \
../scr/i2ceeprom.c \
../scr/leds.c \
../scr/one_wire.c \
../scr/parsing_cmd.c \
../scr/pwm.c \
../scr/rtc.c \
../scr/sbrk.c \
../scr/timer0.c \
../scr/timer1.c \
../scr/uart2_buffered.c \
../scr/vectors.c \
../scr/vt100.c 

OBJS += \
./scr/ADC.o \
./scr/Mb90540.o \
./scr/START.o \
./scr/buffer.o \
./scr/cmnd_line.o \
./scr/debug_uart.o \
./scr/ext_adc.o \
./scr/file.o \
./scr/i2c_sw.o \
./scr/i2ceeprom.o \
./scr/leds.o \
./scr/one_wire.o \
./scr/parsing_cmd.o \
./scr/pwm.o \
./scr/rtc.o \
./scr/sbrk.o \
./scr/timer0.o \
./scr/timer1.o \
./scr/uart2_buffered.o \
./scr/vectors.o \
./scr/vt100.o 


# Each subdirectory must supply rules for building sources it contributes
scr/%.o: ../scr/%.c
	@echo 'Building file: $<'
	@echo 'Compiling C source files'
	fcc907s -cpu MB90543 -w 0 -INF srcin -T p,-B -I "C:\Users\phytech\Dropbox\eclipse\workspace\Fujitsu\dmx\scr" -O 0 -K NOUNROLL -K NOLIB -K NOEOPT -K NOADDSP -K NOALIAS -B -model MEDIUM -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scr/%.o: ../scr/%.asm
	@echo 'Building file: $<'
	@echo 'Assembling source files'
	fasm907s -cpu MB90543 -w 0 -pl 60 -pw 132 -linf OFF -lsrc OFF -lsec OFF -lcros OFF -linc OFF -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scr/%.o: ../scr/%.ASM
	@echo 'Building file: $<'
	@echo 'Assembling source files'
	fasm907s -cpu MB90543 -w 0 -pl 60 -pw 132 -linf OFF -lsrc OFF -lsec OFF -lcros OFF -linc OFF -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


