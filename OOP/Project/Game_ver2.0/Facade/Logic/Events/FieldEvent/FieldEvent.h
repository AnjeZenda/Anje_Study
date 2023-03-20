#pragma  once

#include "../IEvent.h"
#include "../../Field/FieldChanger.h"



class FieldEvent : public virtual IEvent {
protected:
    FieldChanger *_fieldChanger;
public:
    void invoke() override = 0;
    bool isActive() override = 0;
    IEvent * clone() override = 0;
    void setField(FieldChanger *field);
    ~FieldEvent() override;
};