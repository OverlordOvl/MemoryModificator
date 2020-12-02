#include "Include.h"

void WriteMemory(HANDLE _hProc, const DWORD *address, const DWORD &modification)
{
    WriteProcessMemory(_hProc, (LPVOID) *address, &modification, sizeof(modification), nullptr);
}
