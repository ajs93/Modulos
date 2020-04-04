################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Test_RingBuffer.axf

# Tool invocations
Test_RingBuffer.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/augusto/Desktop/InfoII/Libreria_modulos/Modulos/Modulos/Debug" -Xlinker -Map="Test_RingBuffer.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "Test_RingBuffer_Debug.ld" -o "Test_RingBuffer.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Test_RingBuffer.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Test_RingBuffer.axf"; # arm-none-eabi-objcopy -v -O binary "Test_RingBuffer.axf" "Test_RingBuffer.bin" ; # checksum -p LPC845 -d "Test_RingBuffer.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
