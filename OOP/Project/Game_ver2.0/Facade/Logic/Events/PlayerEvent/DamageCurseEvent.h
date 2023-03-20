#pragma once

#include "PlayerEvent.h"

class IDamageCurseEventObserver {
public:
    virtual void onDamageCurseEventInvoked(int damage) = 0;
};

class DamageCurseEvent : public PlayerEvent {
private:
    bool _isActive = true;
    IDamageCurseEventObserver *_observer = nullptr;
public:
    void invoke() override;
    bool isActive() override;
    IEvent *clone() override;
    void setObserver(IDamageCurseEventObserver *observer);
};
