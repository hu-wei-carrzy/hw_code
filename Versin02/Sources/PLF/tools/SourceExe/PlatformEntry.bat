echo off
echo off
echo off
rem *******************************************************************************
echo *******************************************
echo begin CollectJIL file

if exist .\CollectJIL\CollectJIL.exe   ( 
 cd .\CollectJIL\
 .\CollectJIL.exe  
 rem delay 1s
 ping -n 1 127.0.0.1>nul
 ) else (
 goto ErrLostCollectJIL
 )
 
cd ..
echo collectJIL file over and OK
echo *******************************************
echo. 
echo.

rem *******************************************************************************
echo *******************************************
echo Collect JIL file over, begin SCC2 Analysis...

rem if exist SCC2Gen rd /s /q SCC2Gen
rem .\..\..\source\PLFICU\LAP\LAP_SUP\LAP_SUP.JIL
rem  here should clear all file in SCC2Gen folder
echo now first delete all files in SCC2Gen 
rd /s/q .\..\..\source\PLFICU\SCC2Gen\

echo after delete files, now begin SCC2 Analysis......

.\SCC2\SCC2.EXE  .\CollectJIL\LAP_SUP.jil -OUT:.\..\..\source\PLFICU\SCC2Gen\GEN -G:.\SCC2\ -Int -DUMP:.\..\..\..\source\PLFICU\SCC2Gen\DB.JIL
.\SCC2\SCC2.EXE  .\CollectJIL\LAP_SUP.jil -OUT:.\..\..\source\PLFICU\SCC2Gen\GENSIMU -G:.\SCC2\ -Simu
del .\CollectJIL\*.jil
del .\CollectJIL\*.h
del .\..\..\source\PLFICU\SCC2Gen\GENSIMU\*.cpp

echo current path：%cd%
echo SCC2 Analysis Over and OK
echo *******************************************
echo. 
echo.

rem *******************************************************************************
echo *******************************************
echo begin process the generated heder files

if exist .\ProcessGenHeader\ProcessGenHeader.exe 	(
  cd .\ProcessGenHeader\
  ProcessGenHeader.exe 
 ) else (
 goto ErrLostProcessGenHeader
 )

cd ..
echo Process generated file over and OK.
echo *******************************************
echo.
echo.

rem *******************************************************************************
echo *******************************************
echo begin generate the LDB channels

if exist .\AutoGenHALChannels\AutoGenHALChannels.exe   ( 
  cd .\AutoGenHALChannels\
  AutoGenHALChannels.exe
  ) else (
  goto ErrLostAutoGenHALChannels
  )
 
cd ..
echo end generate the LDB channels
echo *******************************************
echo.
echo.


rem *******************************************************************************
echo *******************************************
echo begin AutoGenSERChannels file

if exist .\AutoGenSERChannels\AutoGenSERChannels.exe   ( 
 cd .\AutoGenSERChannels\
 .\AutoGenSERChannels.exe  
 rem delay 1s
 ping -n 1 127.0.0.1>nul
 ) else (
 goto ErrLostAutoGenSERChannels
 )
 
cd ..
echo AutoGenSERChannels file over and OK
echo *******************************************
echo. 
echo.



rem *******************************************************************************
echo *******************************************
echo begin ProcessCAN

if exist .\ProcessCAN\ProcessCAN.exe   ( 
 cd .\ProcessCAN\
 .\ProcessCAN.exe  
 rem delay 1s
 ping -n 1 127.0.0.1>nul
 ) else (
 goto ErrLostProcessCAN
 )
 
cd ..
echo ProcessCAN over and OK
echo *******************************************
echo. 
echo.


rem *******************************************************************************
echo *******************************************
echo begin CanEmission

if exist .\CanEmission\CanEmission.exe   ( 
 cd .\CanEmission\
 .\CanEmission.exe  
 rem delay 1s
 ping -n 1 127.0.0.1>nul
 ) else (
 goto ErrLostCanEmission
 )
 
cd ..
echo CanEmission over and OK
echo *******************************************
echo. 
echo.



rem *******************************************************************************
echo *******************************************
echo begin CanTimeout

if exist .\CanTimeout\CanTimeout.exe   ( 
 cd .\CanTimeout\
 .\CanTimeout.exe  
 rem delay 1s
 ping -n 1 127.0.0.1>nul
 ) else (
 goto ErrLostCanTimeout
 )
 
cd ..
echo CanTimeout over and OK
echo *******************************************
echo. 
echo.



rem *******************************************************************************
echo *******************************************
echo begin Gen EEP init code 


if exist .\AutoGenEEPInit\AutoGenEEPInit.exe   ( 
 cd .\AutoGenEEPInit\
 .\AutoGenEEPInit.exe  
 rem delay 1s
 ping -n 1 127.0.0.1>nul
 ) else (
 goto ErrLostAutoGenEEPInit
 )
 
cd ..
echo AutoGen EEP Init code over and OK
echo *******************************************
echo. 
echo.


rem *******************************************************************************
echo *******************************************
echo begin Simplify CAN message 


if exist .\SimplifyCANMsg\SimplifyCANMsg.exe   ( 
 cd .\SimplifyCANMsg\
  .\SimplifyCANMsg.exe  
 rem delay 1s
 ping -n 1 127.0.0.1>nul
 ) else (
 goto ErrLostSimplifyCANMsg
 )
 
cd ..
echo Simplify CAN message over and OK
echo *******************************************
echo. 
echo.
echo.


rem *******************************************************************************
echo *******************************************
echo Platform analyse over and OK, byebye!
echo *******************************************
pause 
exit

rem ******************************************************************************
:ErrLostAutoGenSERChannels
echo *******************************************
echo !!!!!Error occur, Lost AutoGenSERChannels.exe file, please check .\..\AutoGenSERChannels\AutoGenSERChannels.exe file existing status
echo *******************************************
pause
exit

rem ********************************************************************************
:ErrLostCollectJIL
echo *******************************************
echo !!!!!Error occur, Lost CollectJIL.exe file, please check .\..\CollectJIL\CollectJIL.exe file existing status
echo *******************************************
pause
exit

rem ********************************************************************************
:ErrProcessGenHeader
echo *******************************************
echo !!!!!Error occur, Lost ProcessGenHeader.exe file, please check .\Tools\SourceExe\ProcessGenHeader\ProcessGenHeader.exe file existing status
echo *******************************************
pause
exit

rem ********************************************************************************
:ErrLostAutoGenHALChannels
echo *******************************************
echo !!!!!Error occur, Lost AutoGenHALChannels.exe file, please check .\Tools\SourceExe\AutoGenHALChannels\AutoGenHALChannels.exe file existing status
echo *******************************************
pause
exit


rem ********************************************************************************
:ErrLostProcessCAN
echo *******************************************
echo !!!!!Error occur, Lost ProcessCAN.exe file, please check .\Tools\SourceExe\ProcessCAN\ProcessCAN.exe file existing status
echo *******************************************
pause
exit


rem ********************************************************************************
:ErrLostCanEmission
echo *******************************************
echo !!!!!Error occur, Lost CanEmission.exe file, please check .\Tools\SourceExe\CanEmission\CanEmission.exe file existing status
echo *******************************************
pause
exit


rem ********************************************************************************
:ErrLostCanEmission
echo *******************************************
echo !!!!!Error occur, Lost CanTimeout.exe file, please check .\Tools\SourceExe\CanTimeout\CanTimeout.exe file existing status
echo *******************************************
pause
exit


ErrLostAutoGenEEPInit
rem ********************************************************************************
:ErrLostAutoGenEEPInit
echo *******************************************
echo !!!!!Error occur, Lost  AutoGenEEPInit.exe file, please check .\Tools\SourceExe\AutoGenEEPInit\AutoGenEEPInit.exe file existing status
echo *******************************************
pause
exit



ErrLostSimplifyCANMsg
rem ********************************************************************************
:ErrLostSimplifyCANMsg
echo *******************************************
echo !!!!!Error occur, Lost  SimplifyCANMsg.exe file, please check .\Tools\SourceExe\SimplifyCANMsg\SimplifyCANMsg.exe file existing status
echo *******************************************
pause
exit


