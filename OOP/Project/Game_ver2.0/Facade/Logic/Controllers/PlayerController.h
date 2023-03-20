#pragma once

#include "IController.h"
#include "../Field/Field.h"

class PlayerController : public IController {
private:
    Field *field;
public:
    void process(Command) override;
    void movePlayerRight();
    void movePlayerLeft();
    void movePlayerDown();
    void movePlayerUp();
    void doResearch();
    void setField(Field *field);
};
