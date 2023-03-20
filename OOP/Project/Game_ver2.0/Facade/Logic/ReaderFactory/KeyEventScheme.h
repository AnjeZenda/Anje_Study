#ifndef GAME_VER2_0_KEYEVENTSCHEME_H
#define GAME_VER2_0_KEYEVENTSCHEME_H
#include <map>
#include <SFML/Graphics.hpp>


class KeyEventScheme {
private:
    std::map<sf::Keyboard::Key, std::string> scheme;
public:
    void setCommand(sf::Keyboard::Key key, std::string name);
    bool isKeySet(sf::Keyboard::Key key);
    std::string getCommand(sf::Keyboard::Key key);
    void clearScheme();
};


#endif //GAME_VER2_0_KEYEVENTSCHEME_H