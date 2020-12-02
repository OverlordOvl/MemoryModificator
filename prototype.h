//
// Created by Zver on 30.11.2020.
//
#include <Windows.h>
#include <iostream>
#include <string>
#include "logger.h"

#ifndef ALBIONMASTER_PROTOTYPE_H
#define ALBIONMASTER_PROTOTYPE_H

using namespace std;

DWORD FindProcessId(string processName);
string currentDateTime();
DWORD ReadMemory(HANDLE _hProc, const DWORD *address);
void WriteMemory(HANDLE _hProc, const DWORD *address, const DWORD &modification);
bool op_in(const string &verifiable, vector<string> &root);

#endif //ALBIONMASTER_PROTOTYPE_H
