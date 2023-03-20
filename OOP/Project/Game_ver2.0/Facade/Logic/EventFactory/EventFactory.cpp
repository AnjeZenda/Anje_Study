#include "EventFactory.h"

void EventFactory::setField(FieldChanger *field) {
    EventFactory::field = field;
}

void EventFactory::setPlayer(Player *player) {
    EventFactory::player = player;
}

EventFactory::EventFactory() : player(nullptr), field(nullptr) {
    eventObserver = new EventObserver();
}
