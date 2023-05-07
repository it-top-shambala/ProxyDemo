#ifndef PROXYDEMO_IBANKACCOUNT_H
#define PROXYDEMO_IBANKACCOUNT_H

#include <string>

#include "BankAccountType.h"

using namespace std;

class IBankAccount {
public:
    virtual void Deposit(double money) = 0;
    virtual bool Withdrawal(double money) = 0;
    virtual double GetBalance() = 0;
    virtual BankAccountType GetType() = 0;
    virtual string GetNumber() = 0;
    virtual string GetOwner() = 0;
};


#endif //PROXYDEMO_IBANKACCOUNT_H
