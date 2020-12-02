#include <Windows.h>
#include <TlHelp32.h>
#include <string>


DWORD FindProcessId(std::string processName)
{
    PROCESSENTRY32 peInfo;
    peInfo.dwSize = sizeof(peInfo);
    HANDLE _hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (_hSnap== INVALID_HANDLE_VALUE)
        return 0;
    Process32First(_hSnap, &peInfo);

    if (!processName.compare(peInfo.szExeFile))
    {
        CloseHandle(_hSnap);
        return peInfo.th32ProcessID;
    }

    while (Process32Next(_hSnap, &peInfo))
    {
        if (!processName.compare(peInfo.szExeFile))
        {
            CloseHandle(_hSnap);
            return peInfo.th32ProcessID;
        }
    }
    CloseHandle(_hSnap);
    return 0;
}
