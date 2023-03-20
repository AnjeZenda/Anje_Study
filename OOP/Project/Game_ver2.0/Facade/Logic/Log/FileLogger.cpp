#include "FileLogger.h"

FileLogger::FileLogger() : FileLogger("data.log") {}

FileLogger::FileLogger(const std::string& filename) : _file(filename) {}

FileLogger::~FileLogger() {
    _file.close();
}

ILogger &FileLogger::operator<<(const std::string &message) {
    _file << message << '\n';
    return *this;
}
