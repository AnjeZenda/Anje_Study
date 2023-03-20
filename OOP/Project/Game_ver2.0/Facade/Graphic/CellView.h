#pragma once
#include "SFML/Graphics.hpp"
#include "../Logic/Field/Cell.h"

class CellView {
private:
    sf::RectangleShape rectangle;
public:
    sf::RectangleShape drawCell(const Cell& cell, int x, int y);
};