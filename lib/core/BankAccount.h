#ifndef PROXYDEMO_BANKACCOUNT_H
#define PROXYDEMO_BANKACCOUNT_H

#include "IBankAccount.h"
#include "BankAccountType.h"

class BankAccount : public IBankAccount {
private:
    string _number;
    double _balance;
    BankAccountType _type;
    string _owner;

public:
    BankAccount(string owner, BankAccountType type, double balance = 0) : _balance(balance), _type(type),
                                                                             _owner(owner) {}

    void Deposit(double money) override {
        _balance += money;
    }

    bool Withdrawal(double money) override {
        if (money > _balance) return false;
        _balance -= money;
        return true;
    }

    double GetBalance() override {
        return _balance;
    }

    BankAccountType GetType() override {
        return _type;
    }

    string GetNumber() override {
        return _number;
    }

    string GetOwner() override {
        return _owner;
    }
};


#endif //PROXYDEMO_BANKACCOUNT_H
