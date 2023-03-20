#ifndef GAME_VER2_0_LEVELGENERATOR_H
#define GAME_VER2_0_LEVELGENERATOR_H

#include "FieldScheme.h"

enum class Level {
    FIRST = 1, SECOND, THIRD
};

template<typename ... Rules>
class LevelGenerator {
private:
    template<typename Rule>
    void applyRule(FieldScheme& fieldScheme){
        Rule rule;
        rule.update(fieldScheme);
    }
public:
    void generate(FieldScheme& scheme) {
        (applyRule<Rules>(scheme), ...);
    }
};


#endif //GAME_VER2_0_LEVELGENERATOR_H