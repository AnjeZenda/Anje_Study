#ifndef GAME_VER2_0_LOGGER_H
#define GAME_VER2_0_LOGGER_H

#include <string>
#include <unordered_set>
#include <array>

class ILogger;
struct LogMessage;

class Logger {
public:
    enum Level {
        Acts = 0,
        Info,
        Error
    };

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance();
    void addLogger(ILogger *logger);
    void removeLogger(ILogger *logger);
    void setLevels(int acts, int info, int error);
    Logger &operator<<(const LogMessage &message);
    ~Logger();

    static std::string levelToString(Level level);

private:
    Logger() = default;
    std::unordered_set<ILogger*> _loggers;
    std::array<int, 3> levels{0, 0, 0};
};

struct LogMessage {
    std::string message;
    Logger::Level level;
};


#endif //GAME_VER2_0_LOGGER_H