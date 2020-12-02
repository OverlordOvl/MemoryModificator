//
// Created by Zver on 30.11.2020.
//

#include "logger.h"

logger::logger() {
    name = "Default";
    level = "INFO";
    filePath = "log\\" + name + ".log";
}

logger::logger(string name) {
    this->name = std::move(name);
    filePath = "log\\" + this->name + ".log";
}

logger::logger(string name, string level) {
    this->name = std::move(name);
    filePath = "log\\" + this->name + ".log";
    setLevel(level);
}

void logger::info(string str) {
    write(str, "INFO");
}

void logger::debug(string str) {
    write(str, "DEBUG");
}

void logger::critical(string str) {
    setColor(0, 4);
    write(str, "CRITICAL");
}


void logger::error(string str) {
    setColor(0, 4);
    write(str, "ERROR");
}

void logger::write(string str, string level) {
    string line = currentDateTime() + " " + name + " " + level + " " + str + "\n";
    cout << line;
    log.open( filePath, ios_base::app);
    if (log.is_open()) {
        log << line;
        log.close();
    } else {
        system("mkdir log");
        cout << "Warning! Not found path " + filePath << endl;
    }
    setColor(0, 7);
}

void logger::setLevel(string level) {
    if (op_in(level, levels))
    {
        this->level = level;
    } else {
        error("Not found level" + level);
        this->level = "INFO";
    }

}

void logger::setColor(int background, int text)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD) ((background << 4) | text));
}

