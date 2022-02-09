cmdow @ /HID
@ECHO OFF
cls
SET i=%APPDATA%
cd %~dp0%
SET APPDATA=%CD%
cls
launcher.jar
cls
SET APPDATA=%i%