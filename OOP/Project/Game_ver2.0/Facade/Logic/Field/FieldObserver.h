#ifndef GAME_VER2_0_FIELDOBSERVER_H
#define GAME_VER2_0_FIELDOBSERVER_H
#include "IFieldObserver.h"
class Field;

class FieldObserver : public IFieldObserver {
private:

public:
    void onCellPassabilityChanged(int x, int y, bool isPassable) override;
    void onCellEventChanged(int x, int y, std::string eventName) override;
    void onCellAttemptStep() override;
    FieldObserver& operator<<(const Field& field);
};


#endif //GAME_VER2_0_FIELDOBSERVER_H