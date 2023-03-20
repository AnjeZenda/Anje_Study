#ifndef GAME_VER2_0_SECONDLEVELINFO_H
#define GAME_VER2_0_SECONDLEVELINFO_H

#include "../LevelGenerator.h"
#include "IStrategy.h"

class SecondLevelInfo : public IStrategy {
private:
    FieldScheme scheme;
    LevelGenerator<
            RuleExit<7, 3>,
            RuleWalls<13>,
            RulePlayerPosition<2, 3>,
            RuleFieldChanger<7>,
            RuleUnexplored<-12>,
            RuleEnemy<8>> generator;
public:
    FieldScheme generate() override;
};


#endif //GAME_VER2_0_SECONDLEVELINFO_H