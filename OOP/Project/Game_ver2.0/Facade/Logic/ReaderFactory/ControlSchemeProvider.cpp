#include "ControlSchemeProvider.h"
#include "../Reader/Converter.h"
#include "../Log/Logger.h"

ControlSchemeProvider::ControlSchemeProvider(const std::string &filename) {
    this->scheme = new KeyEventScheme;
    _file.open(filename, std::ios_base::in);
    converter = new Converter;
}

KeyEventScheme *ControlSchemeProvider::setDefaultSettings() {
    scheme->clearScheme();
    scheme->setCommand(sf::Keyboard::Right, "Right");
    scheme->setCommand(sf::Keyboard::Left, "Left");
    scheme->setCommand(sf::Keyboard::Up, "Up");
    scheme->setCommand(sf::Keyboard::Down, "Down");
    scheme->setCommand(sf::Keyboard::R, "Research");
    scheme->setCommand(sf::Keyboard::X, "Attack");
    scheme->setCommand(sf::Keyboard::F5, "Save");
    scheme->setCommand(sf::Keyboard::F9, "Load");
    Logger::getInstance() << LogMessage{"Default settings have been set", Logger::Info};
    return scheme;
}

KeyEventScheme *ControlSchemeProvider::setSettings() {
    if (_file.is_open()) {
        std::string line;
        std::string command;
        std::string button;
        while (!_file.eof()) {
            getline(_file, line);
            size_t separator = line.find('=');
            if (separator != std::string::npos) {
                command = line.substr(0, separator);
                button = line.substr(separator + 1);
                auto converted_value = converter->convert(button);
                auto isValueExist = find(values.begin(), values.end(), command);
                if (!scheme->isKeySet(converted_value) && converted_value != sf::Keyboard::Unknown &&
                    isValueExist == values.end()) {
                    scheme->setCommand(converted_value, command);
                    values.emplace_back(command);
                    Logger::getInstance()
                            << LogMessage{"Key " + button + " set for the command " + command, Logger::Info};
                } else {
                    Logger::getInstance()
                            << LogMessage{"Impossible to set the same key to different commands", Logger::Error};
                    return setDefaultSettings();
                }
            } else {
                Logger::getInstance()
                        << LogMessage{"There is no any assignment to this command or this key", Logger::Error};
                return setDefaultSettings();
            }
        }
        return scheme;
    } else {
        Logger::getInstance()
                << LogMessage{"Something wrong with file opening", Logger::Error};
        return setDefaultSettings();
    }
}

ControlSchemeProvider::~ControlSchemeProvider() {
    this->scheme = nullptr;
    _file.close();
    delete converter;
}
