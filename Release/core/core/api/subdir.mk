################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\Common.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\IPAddress.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\PluggableUSB.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\Print.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\Stream.cpp \
C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\String.cpp 

AR_OBJ += \
.\core\core\api\Common.cpp.o \
.\core\core\api\IPAddress.cpp.o \
.\core\core\api\PluggableUSB.cpp.o \
.\core\core\api\Print.cpp.o \
.\core\core\api\Stream.cpp.o \
.\core\core\api\String.cpp.o 

CPP_DEPS += \
.\core\core\api\Common.cpp.d \
.\core\core\api\IPAddress.cpp.d \
.\core\core\api\PluggableUSB.cpp.d \
.\core\core\api\Print.cpp.d \
.\core\core\api\Stream.cpp.d \
.\core\core\api\String.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
core\core\api\Common.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\Common.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\api\IPAddress.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\api\PluggableUSB.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\PluggableUSB.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\api\Print.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\Print.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\api\Stream.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\Stream.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\api\String.cpp.o: C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino\api\String.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


