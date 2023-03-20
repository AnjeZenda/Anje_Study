#include "PlayerController.h"

void PlayerController::process(Command command) {
    switch(command) {
        case Command::MOVE_DOWN:
            movePlayerDown();
            break;
        case Command::MOVE_UP:
            movePlayerUp();
            break;
        case Command::MOVE_LEFT:
            movePlayerLeft();
            break;
        case Command::MOVE_RIGHT:
            movePlayerRight();
            break;
        case Command::RESEARCH:
            doResearch();
            break;
        case Command::ATTACK:
            break;
    }
}

void PlayerController::movePlayerRight() {
    field->setPlayerPosition(field->getPlayerPositionX() + 1, field->getPlayerPositionY());
}

void PlayerController::movePlayerLeft() {
    field->setPlayerPosition(field->getPlayerPositionX() - 1, field->getPlayerPositionY());
}

void PlayerController::movePlayerDown() {
    field->setPlayerPosition(field->getPlayerPositionX(), field->getPlayerPositionY() + 1);
}

void PlayerController::movePlayerUp() {
    field->setPlayerPosition(field->getPlayerPositionX(), field->getPlayerPositionY() - 1);
}

void PlayerController::setField(Field *field) {
    this->field = field;
}

void PlayerController::doResearch() {
    field->research();
}

