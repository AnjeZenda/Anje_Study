#include "LogInitializer.h"
#include "Logic/Log/Logger.h"
#include "Logic/Log/ConsoleLogger.h"
#include "Logic/Log/FileLogger.h"

#include <iostream>

void LogInitializer::execute() {
    std::cout << "Select levels of logging\nenter 1 to set or 0 to ignore\n";
    char c;
    int acts, info, error;
    std::cout << "Set Acts? ";
    std::cin >> acts;
    std::cout << "\nSet Info? ";
    std::cin >> info;
    std::cout << "\nSet Error? ";
    std::cin >> error;
    Logger::getInstance().setLevels(acts, info, error);

    std::cout << "\nSelect logging methods\n1 - Console\n2 - File\n3 - Console and file\n4 - None\n";
    std::cin >> c;
    if (c == '1') {
        auto consoleLogger = new ConsoleLogger();
        Logger::getInstance().addLogger(consoleLogger);
    } else if (c == '2') {
        auto fileLogger = new FileLogger();
        Logger::getInstance().addLogger(fileLogger);
    } else if (c == '3') {
        auto consoleLogger = new ConsoleLogger();
        auto fileLogger = new FileLogger();
        Logger::getInstance().addLogger(consoleLogger);
        Logger::getInstance().addLogger(fileLogger);
    }
}
