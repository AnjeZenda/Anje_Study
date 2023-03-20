#pragma once
#include "../IEvent.h"
#include "../../Player/Player.h"


class PlayerEvent : public virtual IEvent {
protected:
    Player *player;
public:
    void invoke() override = 0;
    bool isActive() override = 0;
    IEvent * clone() override = 0;
    void setPlayer(Player *player);
    ~PlayerEvent() override;
};