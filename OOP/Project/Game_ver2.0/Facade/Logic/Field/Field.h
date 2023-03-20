#pragma once

#include <vector>
#include "IFieldObserver.h"
#include "Cell.h"

class Field {
private:
    friend class FieldGenerator;
    friend class FieldChanger;
    std::vector<std::vector<Cell>> cells;
    int playerPositionX, playerPositionY;
    const int _width, _height;
    IFieldObserver *observer;
public:
    explicit Field(int height = 5, int width = 5);
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getPlayerPositionX() const;
    [[nodiscard]] int getPlayerPositionY() const;
    void setPlayerPosition(int x, int y);
    [[nodiscard]] const Cell &getCell(int x, int y) const;
    void research();
    [[nodiscard]] int countFreeCells() const;
    void setObserver(IFieldObserver *obs);
};