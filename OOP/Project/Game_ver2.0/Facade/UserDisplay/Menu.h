#pragma once

#include "../Logic/Player/Player.h"
#include "../Logic/FieldScheme/LevelGenerator.h"

class Menu {
private:
    Level level;
    bool isEnterLevel;
    bool isEnterCharacter;
    PlayerRace pRace;
    PlayerClass pClass;
public:
    Menu();
    PlayerClass getClass();
    PlayerRace getRace();
    bool executeField();
    bool executePlayer();
    Level getLevel();
};
