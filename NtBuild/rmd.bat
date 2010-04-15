@echo off

if not exist %1\. goto end

rmdir %1 /s /q

:end
