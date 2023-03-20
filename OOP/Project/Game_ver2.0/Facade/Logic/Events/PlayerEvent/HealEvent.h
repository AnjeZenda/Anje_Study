#pragma once

#include "PlayerEvent.h"

class IHealthEventObserver{
public:
    virtual void onHealthEventInvoked() = 0;
};

class HealEvent : public PlayerEvent {
private:
    bool _isActive = true;
    IHealthEventObserver *_observer = nullptr;
public:
    void invoke() override;
    bool isActive() override;
    IEvent *clone() override;
    void setObserver(IHealthEventObserver *observer);
};
