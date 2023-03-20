#ifndef GAME_VER2_0_THIRDLEVELINFO_H
#define GAME_VER2_0_THIRDLEVELINFO_H

#include "IStrategy.h"
#include "../LevelGenerator.h"

class ThirdLevelInfo : public IStrategy {
private:
    FieldScheme scheme;
    LevelGenerator<
            RuleFieldChanger<7>,
            RuleUnexplored<70>,
            RuleEnemy<11>,
            RuleWalls<17>,
            RuleExit<11, 7>,
            RulePlayerPosition<7, 1>
            > generator;
public:
    FieldScheme generate() override;
};


#endif //GAME_VER2_0_THIRDLEVELINFO_H