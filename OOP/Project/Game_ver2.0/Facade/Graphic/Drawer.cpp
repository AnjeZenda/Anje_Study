#include "Drawer.h"

Drawer::Drawer(Field *field, sf::RenderWindow *window) {
    this->field = field;
    this->window = window;
}

void Drawer::drawScene() {
    window->clear();
    window->clear();
    for(int i = 0; i < field->getHeight(); ++i){
        for (int j = 0; j < field->getWidth(); ++j){
            window->draw(cellView.drawCell(field->getCell(j, i), j, i));
        }
    }
    window->draw(playerView.drawPlayer(field));
    window->display();
}

void Drawer::changeField(Field *field) {
    this->field = field;
}
