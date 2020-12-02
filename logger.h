#ifndef ALBIONMASTER_LOGGER_H
#define ALBIONMASTER_LOGGER_H

#include <vector>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <cstdlib>
#include "prototype.h"


using namespace std;

class logger {

public:
    logger();
    logger(string name);
    logger(string name, string level);

    void info(string str);
    void debug(string str);
    void critical(string str);
    void error(string str);

private:
    ofstream log;
    string filePath;

    string name;

    string level;
    vector <string> levels = {"INFO", "DEBUG", "CRITICAL", "ERROR"};

    string mode;

    void write(string str, string level);
    void setLevel(string level);
    void setColor(int background, int text);
};

#endif //ALBIONMASTER_LOGGER_H
