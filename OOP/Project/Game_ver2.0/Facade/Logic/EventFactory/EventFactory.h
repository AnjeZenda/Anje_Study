#pragma once

#include <type_traits>
#include "../Events/FieldEvent/FieldEvent.h"
#include "../Events/PlayerEvent/PlayerEvent.h"
#include "../Events/EventObserver.h"

class EventFactory {
private:
    Player *player;
    FieldChanger *field;
    EventObserver *eventObserver;
public:
    EventFactory();

    template<class T>
    T *create() {
        auto event = new T;
        if constexpr (std::is_base_of_v<PlayerEvent, T>)
            event->setPlayer(player);
        if constexpr (std::is_base_of_v<FieldEvent, T>)
            event->setField(field);
        event->setObserver(eventObserver);
        return event;
    }

    void setField(FieldChanger *field);
    void setPlayer(Player *player);
};
