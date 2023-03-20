#ifndef GAME_VER2_0_SFMLSUBSCRIBER_H
#define GAME_VER2_0_SFMLSUBSCRIBER_H
#include "SFML/Graphics.hpp"

class SFMLSubscriber {
public:
    virtual void update(sf::Event event) = 0;
    virtual ~SFMLSubscriber() = default;
};


#endif //GAME_VER2_0_SFMLSUBSCRIBER_H