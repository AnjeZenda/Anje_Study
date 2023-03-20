#ifndef GAME_VER2_0_CHANGEPASSABILITY_H
#define GAME_VER2_0_CHANGEPASSABILITY_H


#include "FieldEvent.h"

class IChangePassabilityEventObserver{
public:
    virtual void onChangePassabilityEventInvoked() = 0;
};

class ChangePassability : public FieldEvent {
private:
    bool _isActive = true;
    IChangePassabilityEventObserver *_observer;
public:
    void invoke() override;
    bool isActive() override;
    void setObserver(IChangePassabilityEventObserver *observer);
    IEvent *clone() override;

};


#endif //GAME_VER2_0_CHANGEPASSABILITY_H