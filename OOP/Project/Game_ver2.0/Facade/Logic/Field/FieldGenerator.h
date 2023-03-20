#ifndef GAME_VER2_0_FIELDGENERATOR_H
#define GAME_VER2_0_FIELDGENERATOR_H

#include "../FieldScheme/LevelGenerator.h"
#include "Field.h"
#include "../FieldScheme/Strategy/IStrategy.h"

class EventFactory;

class FieldGenerator {
private:
    EventFactory* _eventFactory;
    Level level;
    IStrategy* strategy;
    FieldScheme fieldScheme;

public:
    explicit FieldGenerator(EventFactory *eventFactory);
    void execute(Field &field);
    void setStrategy(IStrategy *iStrategy);
    void setLevel(Level level);
    void setScheme();
    Field* create();
    Field* create(FieldScheme& scheme);
    ~FieldGenerator();
};


#endif //GAME_VER2_0_FIELDGENERATOR_H