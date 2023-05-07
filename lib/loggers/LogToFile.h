#ifndef PROXYDEMO_LOGTOFILE_H
#define PROXYDEMO_LOGTOFILE_H

#include <fstream>

#include "ILogger.h"

using namespace std;

class LogToFile : public ILogger {
private:
    string _path;

    void WriteToFile(string message) {
        ofstream file;
        file.open(_path, ios::app);
        file << message << endl;
        file.close();
    }

public:
    LogToFile(string path) {
        _path = path;
    }

    void LogInfo(string message) override {
        WriteToFile("[INFO] : " + message);
    }

    void LogError(string message) override {
        WriteToFile("[ERROR] : " + message);
    }

};


#endif //PROXYDEMO_LOGTOFILE_H
