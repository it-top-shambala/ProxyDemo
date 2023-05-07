#ifndef PROXYDEMO_PROXYBANKACCOUNT_H
#define PROXYDEMO_PROXYBANKACCOUNT_H

#include <map>

#include "IBankAccount.h"
#include "BankAccountType.h"

#include "../loggers/ILogger.h"

using namespace std;

class ProxyBankAccount : public IBankAccount {
private:
    IBankAccount* _account;
    map<string, ILogger*> _loggers;

    void LogInfo(string message) {
        if (_loggers.empty()) return;

        for (auto logger : _loggers) {
            logger.second->LogInfo(message);
        }
    }

    void LogError(string message) {
        if (_loggers.empty()) return;

        for (auto logger : _loggers) {
            logger.second->LogError(message);
        }
    }

public:
    ProxyBankAccount(IBankAccount *account) : _account(account) {}

    ProxyBankAccount(IBankAccount *account, const map<string, ILogger *> &loggers) : _account(account),
                                                                                     _loggers(loggers) {}

    void Deposit(double money) override {
        if (money < 0) {
            LogError("Bad money = " + to_string(money));
            money = 0;
        }
        _account->Deposit(money);
        LogInfo("Deposit money = " + to_string(money));
    }

    bool Withdrawal(double money) override {
        if (money < 0) {
            LogError("Bad money = " + to_string(money));
            money = 0;
        }
        LogInfo("Withdrawal money = " + to_string(money));
        return _account->Withdrawal(money);
    }

    double GetBalance() override {
        LogInfo("GetBalance()");
        return _account->GetBalance();
    }

    BankAccountType GetType() override {
        LogInfo("GetType()");
        return _account->GetType();
    }

    string GetNumber() override {
        LogInfo("GetNumber()");
        return _account->GetNumber();
    }

    string GetOwner() override {
        LogInfo("GetOwner()");
        return _account->GetOwner();
    }

    void AddLogger(string name, ILogger* logger) {
        _loggers.insert(pair<string, ILogger*>(name, logger));
    }
    void DelLogger(string name) {
        _loggers.erase(name);
    }
};


#endif //PROXYDEMO_PROXYBANKACCOUNT_H
