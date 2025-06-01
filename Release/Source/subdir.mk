################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\Source\Calibration.cpp \
..\Source\ControlModule.cpp \
..\Source\ErrorHandler.cpp \
..\Source\InterBoardComm.cpp \
..\Source\IoModule.cpp \
..\Source\ObcDevSwitch.cpp \
..\Source\OperationModeDetection.cpp \
..\Source\ProtocolHandler.cpp \
..\Source\SerialCommunication.cpp \
..\Source\VersionInfo.cpp 

LINK_OBJ += \
.\Source\Calibration.cpp.o \
.\Source\ControlModule.cpp.o \
.\Source\ErrorHandler.cpp.o \
.\Source\InterBoardComm.cpp.o \
.\Source\IoModule.cpp.o \
.\Source\ObcDevSwitch.cpp.o \
.\Source\OperationModeDetection.cpp.o \
.\Source\ProtocolHandler.cpp.o \
.\Source\SerialCommunication.cpp.o \
.\Source\VersionInfo.cpp.o 

CPP_DEPS += \
.\Source\Calibration.cpp.d \
.\Source\ControlModule.cpp.d \
.\Source\ErrorHandler.cpp.d \
.\Source\InterBoardComm.cpp.d \
.\Source\IoModule.cpp.d \
.\Source\ObcDevSwitch.cpp.d \
.\Source\OperationModeDetection.cpp.d \
.\Source\ProtocolHandler.cpp.d \
.\Source\SerialCommunication.cpp.d \
.\Source\VersionInfo.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Source\Calibration.cpp.o: ..\Source\Calibration.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\ControlModule.cpp.o: ..\Source\ControlModule.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\ErrorHandler.cpp.o: ..\Source\ErrorHandler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\InterBoardComm.cpp.o: ..\Source\InterBoardComm.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\IoModule.cpp.o: ..\Source\IoModule.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\ObcDevSwitch.cpp.o: ..\Source\ObcDevSwitch.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\OperationModeDetection.cpp.o: ..\Source\OperationModeDetection.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\ProtocolHandler.cpp.o: ..\Source\ProtocolHandler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\SerialCommunication.cpp.o: ..\Source\SerialCommunication.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

Source\VersionInfo.cpp.o: ..\Source\VersionInfo.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO_EVERY -DARDUINO_ARCH_MEGAAVR  -DAVR_NANO_4809_328MODE -DMILLIS_USE_TIMERB3 -DNO_EXTERNAL_I2C_PULLUP "-IC:/Tools/Sloeber-V4.4.1/arduinoPlugin/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/api/deprecated"   -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\cores\arduino" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\variants\nona4809" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\Wire\src" -I"C:\Tools\Sloeber-V4.4.1\arduinoPlugin\packages\arduino\hardware\megaavr\1.8.8\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


