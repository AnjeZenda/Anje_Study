#pragma once

#include "PlayerEvent.h"

class IManaEventObserver{
public:
    virtual void onManaEventInvoked() = 0;
};

class ManaEvent : public PlayerEvent {
private:
    bool _isActive = true;
    IManaEventObserver *_observer = nullptr;
public:
    void invoke() override;
    bool isActive() override;
    IEvent *clone() override;
    void setObserver(IManaEventObserver *observer);
};
