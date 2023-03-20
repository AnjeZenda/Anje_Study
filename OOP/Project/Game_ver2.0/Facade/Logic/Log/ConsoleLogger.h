#ifndef GAME_VER2_0_CONSOLELOGGER_H
#define GAME_VER2_0_CONSOLELOGGER_H


#include "ILogger.h"

class ConsoleLogger : public ILogger {
public:
    ILogger &operator<<(const std::string &message) override;
};


#endif //GAME_VER2_0_CONSOLELOGGER_H