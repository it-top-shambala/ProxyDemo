cmake_minimum_required(VERSION 3.25)
project(ProxyDemo)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProxyDemo main.cpp lib/core/BankAccountType.h lib/core/IBankAccount.h lib/core/BankAccount.h lib/core/ProxyBankAccount.h lib/loggers/ILogger.h lib/loggers/LogToFile.h lib/loggers/LogToConsole.h)
