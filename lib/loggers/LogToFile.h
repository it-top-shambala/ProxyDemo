#ifndef PROXYDEMO_LOGTOFILE_H
#define PROXYDEMO_LOGTOFILE_H

#include <fstream>

#include "ILogger.h"

using namespace std;

class LogToFile : public ILogger {
private:
    ofstream _file;

    void WriteToFile(string message) {
        _file << message << endl;
    }

public:
    LogToFile(string path) {
        _file.open(path, ios::app);
    }

    void LogInfo(string message) override {
        WriteToFile("[INFO] : " + message);
    }

    void LogError(string message) override {
        WriteToFile("[ERROR] : " + message);
    }

};


#endif //PROXYDEMO_LOGTOFILE_H
