#ifndef GAME_VER2_0_INPUTREADERFACTORY_H
#define GAME_VER2_0_INPUTREADERFACTORY_H
#include "IReaderFactory.h"
#include "SFMLHandler.h"

class InputReaderFactory : public IReaderFactory{
private:
    SFMLHandler *sfmlHandler;
public:
    InputReaderFactory(SFMLHandler *handler);
    Reader *create() override;
};


#endif //GAME_VER2_0_INPUTREADERFACTORY_H