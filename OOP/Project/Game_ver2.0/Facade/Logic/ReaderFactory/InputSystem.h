#ifndef GAME_VER2_0_INPUTSYSTEM_H
#define GAME_VER2_0_INPUTSYSTEM_H
#include "IReaderFactory.h"
class IMediator;

class InputSystem {
private:
    IReaderFactory *_factory;
    std::vector<IMediator *> mediators;
public:
    InputSystem(IReaderFactory *factory);
    void addMediators(IMediator *mediator);
    void addReader();
    ~InputSystem();
};


#endif //GAME_VER2_0_INPUTSYSTEM_H