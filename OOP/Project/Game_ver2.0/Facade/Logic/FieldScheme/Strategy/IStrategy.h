#ifndef GAME_VER2_0_ISTRATEGY_H
#define GAME_VER2_0_ISTRATEGY_H


#include "../FieldScheme.h"
#include "../../Rules/RuleEnemy.h"
#include "../../Rules/RuleFieldChanger.h"
#include "../../Rules/RuleExit.h"
#include "../../Rules/RuleUnexplored.h"
#include "../../Rules/RuleWalls.h"
#include "../../Rules/RulePlayerPosition.h"

class IStrategy {
public:
    virtual FieldScheme generate() = 0;
};


#endif //GAME_VER2_0_ISTRATEGY_H