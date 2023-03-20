#pragma once

#include "PlayerEvent.h"

class ICurseEventObserver{
public:
    virtual void onCurseEventInvoked() = 0;
};

class CurseEvent : public PlayerEvent {
private:
    bool _isActive = true;
    ICurseEventObserver *_observer = nullptr;
public:
    void invoke() override;
    bool isActive() override;
    void setObserver(ICurseEventObserver *observer);
    IEvent *clone() override;
};
