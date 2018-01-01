################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
OBJCOPY_FLASH += \
dim.mhx \


# All Target
all: dim.abs secondary-outputs

# Tool invocations
dim.abs: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Link object files'
	flnk907s -cpu MB90543 -w 2 -Xset_rora -pl 60 -pw 132 -a -AL 2 -ro _INROM01=0x00fe0000/0x00ffffff -ra _INRAM01=0x00000100/0x000018ff -sc CONST/Const/WORD=0xFF4000 -rg 0 -Xm -NCI0302LIB -o "dim.abs" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

dim.mhx: dim.abs
	@echo 'Create Flash image (mhx format)'
	f2ms -S2 dim.abs -o dim.mhx -o "dim.mhx"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(OBJCOPY_FLASH) dim.abs
	-@echo ' '

secondary-outputs: $(OBJCOPY_FLASH)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
