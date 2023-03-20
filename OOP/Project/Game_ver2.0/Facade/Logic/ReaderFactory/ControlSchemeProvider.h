#ifndef GAME_VER2_0_CONTROLSCHEMEPROVIDER_H
#define GAME_VER2_0_CONTROLSCHEMEPROVIDER_H
#include <fstream>
#include <string>
#include "KeyEventScheme.h"
class Converter;

class ControlSchemeProvider {
private:
    std::vector<std::string> values;
    std::ifstream _file;
    Converter *converter;
    KeyEventScheme *scheme;
public:
    ControlSchemeProvider(const std::string &filename);
    KeyEventScheme *setDefaultSettings();
    KeyEventScheme *setSettings();
    ~ControlSchemeProvider();
};


#endif //GAME_VER2_0_CONTROLSCHEMEPROVIDER_H