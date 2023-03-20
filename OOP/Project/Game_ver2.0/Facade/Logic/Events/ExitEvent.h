#ifndef GAME_VER2_0_EXITEVENT_H
#define GAME_VER2_0_EXITEVENT_H


#include "PlayerEvent/PlayerEvent.h"
#include "FieldEvent/FieldEvent.h"

class IExitEventObserver {
public:
    virtual void onExitEventInvoked() = 0;
};

class ExitEvent : public PlayerEvent, public FieldEvent {
private:
    IExitEventObserver *_observer = nullptr;
public:
    void invoke() override;
    bool isActive() override;
    IEvent *clone() override;
    void setObserver(IExitEventObserver *observer);
};


#endif //GAME_VER2_0_EXITEVENT_H