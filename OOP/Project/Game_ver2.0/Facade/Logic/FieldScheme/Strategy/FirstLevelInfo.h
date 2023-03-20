#ifndef GAME_VER2_0_FIRSTLEVELINFO_H
#define GAME_VER2_0_FIRSTLEVELINFO_H

#include "IStrategy.h"
#include "../LevelGenerator.h"

class FirstLevelInfo : public IStrategy {
private:
    FieldScheme scheme;
    LevelGenerator<
            RulePlayerPosition<2, 4>,
            RuleWalls<10>,
            RuleExit<4, 5>,
            RuleFieldChanger<7>,
            RuleUnexplored<13>,
            RuleEnemy<8>> generator;
public:
    FieldScheme generate() override;
};


#endif //GAME_VER2_0_FIRSTLEVELINFO_H