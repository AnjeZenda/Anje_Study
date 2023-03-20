#pragma once

class IEvent {
public:
    virtual void invoke() = 0;
    virtual bool isActive() = 0;
    virtual IEvent *clone() = 0;
    virtual ~IEvent() = default;
};