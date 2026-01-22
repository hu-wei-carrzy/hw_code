@echo off

::读取工具路径
set TOOLS_ROOT_PATH=%~dp0		
::读取文件带路径名
set APP_FILE=%1
::读取文件路径	
set APP_FILE_PATH=%~dp1
::读取文件名
set APP_FILE_NAME=%~n1
::读取扩展名
set APP_FILE_EXTEN=%~x1

set JLINK_TOOL_PATH=%2

set CUT_ADDR=0,0x1E00F

echo 准备生成裁剪后的目标文件，裁剪的地址范围：%CUT_ADDR%
%JLINK_TOOL_PATH% -open%APP_FILE% -delrange%CUT_ADDR% -saveas%APP_FILE_PATH%%APP_FILE_NAME%_CutForBoot%APP_FILE_EXTEN% -exit
