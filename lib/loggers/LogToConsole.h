#ifndef PROXYDEMO_LOGTOCONSOLE_H
#define PROXYDEMO_LOGTOCONSOLE_H

#include <iostream>

#include "ILogger.h"

using namespace std;

class LogToConsole : public ILogger {
private:
    void WriteToConsole(string message) {
        cout << message << endl;
    }

public:
    void LogInfo(string message) override {
        WriteToConsole("[INFO] : " + message);
    }

    void LogError(string message) override {
        WriteToConsole("[ERROR] : " + message);
    }

};


#endif //PROXYDEMO_LOGTOCONSOLE_H
