################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809\variant.c 

C_DEPS += \
.\core\variant\variant.c.d 

LINK_OBJ += \
.\core\variant\variant.c.o 


# Each subdirectory must supply rules for building sources it contributes
core\variant\variant.c.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809\variant.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


