#include <iostream>
#include "ConsoleLogger.h"

ILogger &ConsoleLogger::operator<<(const std::string &message) {
    std::cout << message << '\n';
    return *this;
}
