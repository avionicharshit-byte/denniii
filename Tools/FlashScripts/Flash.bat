
@echo off

cls
echo *****************************************************************
echo * Sript does currently only support Arduino "NANO EVERY" boards *
echo *****************************************************************
echo.

set /P nr="Enter COM port no. (e.g. 3 for COM3): ":

set comPort=COM%nr%

:flash

c:\windows\system32\mode.com %comPort%: baud=1200 dtr=on
c:\windows\system32\mode.com %comPort%: dtr=off

@echo on

..\avrdude\avrdude.exe -C..\avrdude\avrdude.conf -patmega4809 -cjtag2updi -P%comPort% -b115200 -e -D -V -Uflash:w:..\..\Release\ObcDevSwitch.hex:i -Ufuse2:w:0x01:m -Ufuse5:w:0xC9:m -Ufuse8:w:0x00:m


if not errorlevel 0 goto error

#exit

:error
pause