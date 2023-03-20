#ifndef GAME_VER2_0_FILELOGGER_H
#define GAME_VER2_0_FILELOGGER_H


#include "ILogger.h"
#include <fstream>

class FileLogger : public ILogger {
private:
    std::ofstream _file;
public:
    FileLogger();
    explicit FileLogger(const std::string &filename);
    ~FileLogger() override;
    ILogger &operator<<(const std::string &message) override;
};


#endif //GAME_VER2_0_FILELOGGER_H