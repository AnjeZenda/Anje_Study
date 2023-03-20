#include "CellView.h"

sf::RectangleShape CellView::drawCell(const Cell &cell, int x, int y) {
    rectangle.setSize(sf::Vector2f(30, 30));
    rectangle.setPosition(sf::Vector2f(x * 40, y * 40));
    if(cell.isPlayerHere()) {
        rectangle.setFillColor(sf::Color::Yellow);
        return rectangle;
    }
    else {
        switch (cell.getType()) {
            case FREE:
                rectangle.setFillColor(sf::Color::Green);
                break;
            case UNEXPLORED:
                rectangle.setFillColor(sf::Color::Blue);
                break;
            case OCCUPIED:
                rectangle.setFillColor(sf::Color::Red);
                break;
            case PLAYER:
                rectangle.setFillColor(sf::Color::Yellow);
                break;
            case FIELD_CHANGER:
                rectangle.setFillColor(sf::Color(0, 200, 150));
                break;
            case BLOCKED:
                rectangle.setFillColor(sf::Color(137, 137,137));
                break;
            case EXIT:
                rectangle.setFillColor((sf::Color(180, 21, 220)));
                break;
        }
        return rectangle;
    }
}
