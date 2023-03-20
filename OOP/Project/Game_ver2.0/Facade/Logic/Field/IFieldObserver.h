#ifndef GAME_VER2_0_IFIELDOBSERVER_H
#define GAME_VER2_0_IFIELDOBSERVER_H


#include <string>

class IFieldObserver {
public:
    virtual void onCellPassabilityChanged(int x, int y, bool isPassable) = 0;
    virtual void onCellEventChanged(int x, int y, std::string eventName) = 0;
    virtual void onCellAttemptStep() = 0;
};


#endif //GAME_VER2_0_IFIELDOBSERVER_H