#ifndef GAME_VER2_0_SFMLHANDLER_H
#define GAME_VER2_0_SFMLHANDLER_H
#include "SFMLSubscriber.h"

class SFMLHandler {
private:
    std::vector <SFMLSubscriber *> subscribers;
public:
    SFMLHandler() = default;
    void addSubscriber(SFMLSubscriber *sub);
    void update(sf::Event event);
    ~SFMLHandler();
};


#endif //GAME_VER2_0_SFMLHANDLER_H