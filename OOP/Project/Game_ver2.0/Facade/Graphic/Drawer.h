#pragma once
#include "SFML/Graphics.hpp"
#include "CellView.h"
#include "PlayerView.h"
#include "../Logic/Field/Field.h"

class Drawer {
private:
    Field *field;
    sf::RenderWindow *window;
    CellView cellView;
    PlayerView playerView;
public:
    Drawer(Field *, sf::RenderWindow *);
    void changeField(Field *field);
    void drawScene();
};
