#ifndef GAME_VER2_0_CONVERTER_H
#define GAME_VER2_0_CONVERTER_H
#include <map>
#include "SFML/Window/Keyboard.hpp"

class Converter {
private:
    std::map<std::string, sf::Keyboard::Key> commands;

public:
    Converter();
    sf::Keyboard::Key convert(std::string string);
};


#endif //GAME_VER2_0_CONVERTER_H