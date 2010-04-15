@rem redirect to a python .lpy script file
@echo off

for %%i in (oaTracer22.bat) do set rlocation=%%~$PATH:i
if not "%rlocation%" == "" goto foundme
for %%i in ("%0") do set rlocation=%%~dpioaTracer22.bat
if not exist "%rlocation%" (
  echo ** Can't find: oaTracer22.bat
  set rlocation=
  exit /B 1
)

:foundme
for %%i in ("%rlocation%") do set plocation=%%~dpipython.exe
if exist "%plocation%" goto ready
for %%i in (python.exe) do set plocation=%%~$PATH:i
if "%plocation%"=="" (
  echo ** Can't find: python
  set rlocation=
  set plocation=
  exit /B 1
)

:ready
for %%i in ("%rlocation%") do set slocation=%%~dpioaTracer22.lpy
if not exist "%slocation%" (
  echo %slocation%
  echo ** Can't find: oaTracer22.lpy
  set rlocation=
  set plocation=
  set slocation=
  exit /B 1
)

"%plocation%" "%slocation%" %*

