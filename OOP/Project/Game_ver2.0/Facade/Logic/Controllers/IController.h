#pragma once

enum class Command{
    MOVE_UP, MOVE_DOWN, MOVE_RIGHT, MOVE_LEFT, ATTACK, RESEARCH, SAVE, LOAD
};

class IController {
public:
    virtual void process(Command) = 0;
};