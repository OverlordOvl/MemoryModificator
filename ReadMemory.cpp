#include "Include.h"

DWORD ReadMemory(HANDLE _hProc, const DWORD *address)
{
    DWORD readValue = 0;
    ReadProcessMemory(_hProc, (LPVOID) * address, &readValue, sizeof(readValue), nullptr);
    return readValue;
}
