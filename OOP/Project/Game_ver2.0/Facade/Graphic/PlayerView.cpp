#include "PlayerView.h"

sf::Sprite PlayerView::drawPlayer(Field *field) {
    playerImage.loadFromFile("E:/Game_ver2.0/Resources/creature-sheet.png");
    playerTexture.loadFromImage(playerImage);
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(1, 5, 21, 19));
    playerSprite.setPosition(field->getPlayerPositionX() * 40 + 5, field->getPlayerPositionY() * 40 + 5);
    return playerSprite;
}


