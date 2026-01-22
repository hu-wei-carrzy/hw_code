@echo off

set HEX_TOOL_PATH=%1
set TOOLS_ROOT_PATH=%~dp0
set DEBUG_PATH=%TOOLS_ROOT_PATH%..\Debug_FLASH\

set NOW_TIME1=%date:~0,4%%date:~5,2%%date:~8,2%%time:~0,2%%time:~3,2%

set NOW_TIME=%NOW_TIME1: =0%

for %%i in (%DEBUG_PATH%*.elf) do (
set TARGET_NAME=%%~ni
)

%HEX_TOOL_PATH%\arm-none-eabi-objcopy -O ihex  %TOOLS_ROOT_PATH%..\Debug_FLASH\%TARGET_NAME%.elf   "%TARGET_NAME%%NOW_TIME%.hex"

call %TOOLS_ROOT_PATH%CutForBoot.bat %TOOLS_ROOT_PATH%..\Debug_FLASH\%TARGET_NAME%%NOW_TIME%.hex  %TOOLS_ROOT_PATH%TOOLS\JFlash.exe