#include "Field.h"
#include "../Log/Logger.h"

Field::Field(int height, int width) : _width(width), _height(height) {
    this->playerPositionX = 0, this->playerPositionY = 0;
    for (int i = 0; i < _height; ++i) {
        cells.emplace_back(std::vector<Cell>(width));
    }
}

int Field::getWidth() const {
    return _width;
}

int Field::getHeight() const {
    return _height;
}

int Field::getPlayerPositionX() const {
    return playerPositionX;
}

int Field::getPlayerPositionY() const {
    return playerPositionY;
}

void Field::setPlayerPosition(int x, int y) {
    int changePosX = x < 0 ? _width + x : (x == _width ? 0 : x);
    int changePosY = y < 0 ? _height + y : (y == _height ? 0 : y);
    if (cells[changePosY][changePosX].getType() != BLOCKED) {
        cells[getPlayerPositionY()][getPlayerPositionX()].setPlayerPresence(false);
        playerPositionX = changePosX;
        playerPositionY = changePosY;
        cells[playerPositionY][playerPositionX].setPlayerPresence(true);
        cells[playerPositionY][playerPositionX].react();
    } else {
        observer->onCellAttemptStep();
    }
}

const Cell &Field::getCell(int x, int y) const {
    return cells[y][x];
}

void Field::research() {
    cells[playerPositionY][playerPositionX].research();
}

int Field::countFreeCells() const {
    int count = 0;
    for (auto& row: cells) {
        for (auto& cell : row) {
            if (cell.getType() == FREE) {
                ++count;
            }
        }
    }
    return count;
}

void Field::setObserver(IFieldObserver *obs) {
    Logger::getInstance() << LogMessage{"Field set the observer", Logger::Info};
    observer = obs;
}


