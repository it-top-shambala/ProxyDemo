#include <iostream>

#include "lib/core/ProxyBankAccount.h"
#include "lib/core/BankAccount.h"

#include "./lib/loggers/LogToConsole.h"
#include "./lib/loggers/LogToFile.h"

using namespace std;

int main() {
    ILogger* logToConsole = new LogToConsole();
    ILogger* logToFile = new LogToFile("actions.log");

    IBankAccount* account = new ProxyBankAccount(new BankAccount("A", BankAccountType::Rub));
    dynamic_cast<ProxyBankAccount*>(account)->AddLogger("console", logToConsole);
    dynamic_cast<ProxyBankAccount*>(account)->AddLogger("file", logToFile);

    cout << account->GetBalance() << endl;
    account->Deposit(-8);
    cout << account->GetBalance() << endl;
    account->Deposit(8);
    cout << account->GetBalance() << endl;
    dynamic_cast<ProxyBankAccount*>(account)->DelLogger("console");
    account->Deposit(18);
    cout << account->GetBalance() << endl;

    return 0;
}
