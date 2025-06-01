################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\CDC.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\NANO_compat.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\Tone.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART0.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART1.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART2.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART3.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UNO_compat.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\USBCore.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\WInterrupts.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\WMath.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\abi.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\main.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\new.cpp 

S_UPPER_SRCS += \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_pulse.S 

C_SRCS += \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\hooks.c \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring.c \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_analog.c \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_digital.c \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_pulse.c \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_shift.c 

C_DEPS += \
.\core\core\hooks.c.d \
.\core\core\wiring.c.d \
.\core\core\wiring_analog.c.d \
.\core\core\wiring_digital.c.d \
.\core\core\wiring_pulse.c.d \
.\core\core\wiring_shift.c.d 

AR_OBJ += \
.\core\core\CDC.cpp.o \
.\core\core\NANO_compat.cpp.o \
.\core\core\Tone.cpp.o \
.\core\core\UART.cpp.o \
.\core\core\UART0.cpp.o \
.\core\core\UART1.cpp.o \
.\core\core\UART2.cpp.o \
.\core\core\UART3.cpp.o \
.\core\core\UNO_compat.cpp.o \
.\core\core\USBCore.cpp.o \
.\core\core\WInterrupts.cpp.o \
.\core\core\WMath.cpp.o \
.\core\core\abi.cpp.o \
.\core\core\hooks.c.o \
.\core\core\main.cpp.o \
.\core\core\new.cpp.o \
.\core\core\wiring.c.o \
.\core\core\wiring_analog.c.o \
.\core\core\wiring_digital.c.o \
.\core\core\wiring_pulse.S.o \
.\core\core\wiring_pulse.c.o \
.\core\core\wiring_shift.c.o 

S_UPPER_DEPS += \
.\core\core\wiring_pulse.S.d 

CPP_DEPS += \
.\core\core\CDC.cpp.d \
.\core\core\NANO_compat.cpp.d \
.\core\core\Tone.cpp.d \
.\core\core\UART.cpp.d \
.\core\core\UART0.cpp.d \
.\core\core\UART1.cpp.d \
.\core\core\UART2.cpp.d \
.\core\core\UART3.cpp.d \
.\core\core\UNO_compat.cpp.d \
.\core\core\USBCore.cpp.d \
.\core\core\WInterrupts.cpp.d \
.\core\core\WMath.cpp.d \
.\core\core\abi.cpp.d \
.\core\core\main.cpp.d \
.\core\core\new.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
core\core\CDC.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\CDC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\NANO_compat.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\NANO_compat.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\Tone.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\Tone.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\UART.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\UART0.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART0.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\UART1.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART1.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\UART2.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART2.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\UART3.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UART3.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\UNO_compat.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\UNO_compat.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\USBCore.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\WInterrupts.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\WInterrupts.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\WMath.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\WMath.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\abi.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\abi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\hooks.c.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\hooks.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\main.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\main.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\new.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\new.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\wiring.c.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\wiring_analog.c.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\wiring_digital.c.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\wiring_pulse.S.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_pulse.S
	@echo 'Building file: $<'
	@echo 'Starting S compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\wiring_pulse.c.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\wiring_shift.c.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


