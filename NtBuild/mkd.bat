@echo off
rem RCS: @(#) $Id: mkd.bat,v 1.1 2007/02/21 16:26:35 amson Exp $

if exist %1\. goto end

if "%OS%" == "Windows_NT" goto winnt

md %1
if errorlevel 1 goto end

goto success

:winnt
md %1
if errorlevel 1 goto end

:success
echo created directory %1

:end
