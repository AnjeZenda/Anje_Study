#pragma once
#include "SFML/Graphics.hpp"
#include "../Logic/Field/Field.h"

class PlayerView {
private:
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    sf::Image playerImage;
public:
    sf::Sprite drawPlayer(Field *field);
};
