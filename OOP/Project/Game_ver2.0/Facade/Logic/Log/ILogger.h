#ifndef GAME_VER2_0_ILOGGER_H
#define GAME_VER2_0_ILOGGER_H


#include <string>

class ILogger {
public:
    virtual ILogger &operator<<(const std::string &message) = 0;
    virtual ~ILogger() = default;
};


#endif //GAME_VER2_0_ILOGGER_H