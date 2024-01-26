################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Toggling_LED.lss \

FLASH_IMAGE += \
Toggling_LED.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Toggling_LED.elf secondary-outputs

# Tool invocations
Toggling_LED.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Toggling_LED.map -mmcu=atmega32 -o "Toggling_LED.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Toggling_LED.lss: Toggling_LED.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Toggling_LED.elf  >"Toggling_LED.lss"
	@echo 'Finished building: $@'
	@echo ' '

Toggling_LED.hex: Toggling_LED.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Toggling_LED.elf  "Toggling_LED.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Toggling_LED.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Toggling_LED.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Toggling_LED.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
