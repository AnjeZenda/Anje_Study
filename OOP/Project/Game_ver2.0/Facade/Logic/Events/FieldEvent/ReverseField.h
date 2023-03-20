#pragma once

#include "FieldEvent.h"

class IReverseFieldEventObserver{
public:
    virtual void onReverseFieldEventInvoked() = 0;
};

class ReverseField : public FieldEvent {
private:
    bool _isActive = true;
    IReverseFieldEventObserver *_observer;
public:
    void invoke() override;
    bool isActive() override;
    IEvent * clone() override;
    void setObserver(IReverseFieldEventObserver *observer);
};
