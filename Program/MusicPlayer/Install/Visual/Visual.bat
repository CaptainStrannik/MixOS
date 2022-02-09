@echo off
CD /d %~dp0

echo.
echo Now we will install or reinstall your visual C++ Redistributable packages.
set /p answer=Do you want to continue? (Y or N):
if %answer%==Y goto INSTALL
if %answer%==N exit


:INSTALL
echo Installing runtime packages...

set IS_X64=0 && if "%PROCESSOR_ARCHITECTURE%"=="AMD64" (set IS_X64=1) else (if "%PROCESSOR_ARCHITEW6432%"=="AMD64" (set IS_X64=1))

if "%IS_X64%" == "1" goto X64

echo 2005...
start /wait Visual C++ 2005 x86.exe /q

echo 2008...
start /wait Visual C++ 2008 x86.exe /qb

echo 2010...
start /wait Visual C++ 2010 x86.exe /passive /norestart

echo 2012...
start /wait Visual C++ 2012 x86.exe /passive /norestart

echo 2013...
start /wait Visual C++ 2013 x86.exe /passive /norestart

echo 2015-2022...
start /wait Visual C++ 2022 x86.exe /passive /norestart

goto END

:X64


echo Your Processor is 64 bit. Well =)
echo 2005...
start /wait Visual C++ 2005 x86.exe /q
start /wait Visual C++ 2005 x64.exe /q

echo 2008...
start /wait Visual C++ 2008 x86.exe /qb
start /wait Visual C++ 2008 x64.exe /qb

echo 2010...
start /wait Visual C++ 2010 x86.exe /passive /norestart
start /wait Visual C++ 2010 x64.exe /passive /norestart

echo 2012...
start /wait Visual C++ 2012 x86.exe /passive /norestart
start /wait Visual C++ 2012 x64.exe /passive /norestart

echo 2013...
start /wait Visual C++ 2013 x86.exe /passive /norestart
start /wait Visual C++ 2013 x64.exe /passive /norestart

echo 2015-2022...
start /wait Visual C++ 2022 x86.exe /passive /norestart
start /wait Visual C++ 2022 x64.exe /passive /norestart

goto END

:END

echo.
echo Installation completed successfully. You should to restart your pc now.

exit