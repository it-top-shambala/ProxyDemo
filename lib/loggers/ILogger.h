#ifndef PROXYDEMO_ILOGGER_H
#define PROXYDEMO_ILOGGER_H

#include <string>

using namespace std;

class ILogger {
public:
    virtual void LogInfo(string message) = 0;
    virtual void LogError(string message) = 0;
};


#endif //PROXYDEMO_ILOGGER_H
