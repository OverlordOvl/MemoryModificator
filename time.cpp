#include "Include.h"


string currentDateTime() {
    time_t     now = time(nullptr);
    struct tm  tstruct{};
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
