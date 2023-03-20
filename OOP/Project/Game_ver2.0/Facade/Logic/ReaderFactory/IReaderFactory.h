#ifndef GAME_VER2_0_IREADERFACTORY_H
#define GAME_VER2_0_IREADERFACTORY_H
#include "../Reader/Reader.h"

class IReaderFactory {
public:
    virtual Reader* create() = 0;

};


#endif //GAME_VER2_0_IREADERFACTORY_H