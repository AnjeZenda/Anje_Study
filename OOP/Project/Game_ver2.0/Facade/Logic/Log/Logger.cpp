#include "Logger.h"
#include "ILogger.h"

Logger &Logger::getInstance() {
    static Logger instance;
    return instance;
}


Logger &Logger::operator<<(const LogMessage &message) {
    int level = message.level;
    if (levels[level] == 0)
        return *this;

    std::string str = levelToString(message.level) + ": " + message.message;
    for (auto logger : _loggers)
        *logger << str;
    return *this;
}

void Logger::addLogger(ILogger *logger) {
    _loggers.insert(logger);
}

void Logger::removeLogger(ILogger *logger) {
    _loggers.erase(logger);
}

Logger::~Logger() {
    for (auto logger : _loggers)
        delete logger;
}

std::string Logger::levelToString(Level level) {
    switch (level) {
        case Acts:
            return "[Acts]";
        case Info:
            return "[Info]";
        case Error:
            return "[Error]";
        default:
            return "[Unknown]";
    }
}

void Logger::setLevels(int acts, int info, int error) {
    levels[0] = acts;
    levels[1] = info;
    levels[2] = error;
}
