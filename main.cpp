#include "main.h"


#define PROC_NAME "experimental.exe"


DWORD HandlePID() {
    return FindProcessId(PROC_NAME);
};



HANDLE HandleAlbion(DWORD _pID) {
    return OpenProcess(PROCESS_ALL_ACCESS, 0, _pID);
}


logger log("Main");


int getCommand() {
    int command;
    cout << "Список комманд" << endl;
    cout << "1. Установить значение" << endl;
    cout << "2. Выйти" << endl;
    cout << "Команда: ";
    cin >> command;
    return command;
}


void MemoryModification(HANDLE _hProc, DWORD &address, DWORD &modification) {
    DWORD value = ReadMemory(_hProc, &address);
    log.debug("\nValue success handled. Address " + to_string(address) + " = " + to_string(value) + "\n" );
    WriteMemory(_hProc, &address, modification);
    value = ReadMemory(_hProc, &address);
    log.debug("New value for address " + to_string(address) + " = " + to_string(value) + "\n");
}

bool checkPID(const DWORD *_pID) {
    if (_pID != nullptr)
        return true;
    else
        return false;
}


bool checkHProc(HANDLE *_hProc) {
    if (_hProc != nullptr)
        return true;
    else
        return false;
}

bool switchCommands(HANDLE _hProc, DWORD &address)
{
    int command = getCommand();
    DWORD modification;
    switch (command) {
        case 1: {
            cout << "Новое значение: ";
            cin >> modification;
            cout << endl;
            MemoryModification(_hProc, address, modification);
            break;
        }
        case 2: {
            cout << "Выход." << endl;
            return false;
        }

        default: {
            cout << "Команда не найдена." << endl;
            switchCommands(_hProc, address);
            break;
        }
    }
    return true;
}


void start() {

    log.info("Program start");
    DWORD modification;
    DWORD address = 0xffffcbd4;


    log.info("Handle pID");
    DWORD _pID = HandlePID();
    if (checkPID(&_pID)) {
        log.info("pID handled: " + to_string(_pID));

        log.info("Handle Process");
        HANDLE _hProc = HandleAlbion(_pID);

        if (!checkHProc(&_hProc)) {
            log.error("Game not launched.");
            return;
        }

        log.info("Success Process handle");
        if (!switchCommands(_hProc, address))
            return;

        CloseHandle(_hProc);

    } else {
        log.critical("Window not found.");
    }


    start();

}


int main() {
    start();
    log.info("Program stop");
    cin.get();
    return 0;
}


