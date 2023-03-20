#include "KeyEventScheme.h"

void KeyEventScheme::setCommand(sf::Keyboard::Key key, std::string name) {
    scheme.emplace(key, name);
}

bool KeyEventScheme::isKeySet(sf::Keyboard::Key key) {
    auto isSet = scheme.find(key);
    return isSet != scheme.end();
}



std::string KeyEventScheme::getCommand(sf::Keyboard::Key key) {
    return scheme[key];
}

void KeyEventScheme::clearScheme() {
    scheme.clear();
}

