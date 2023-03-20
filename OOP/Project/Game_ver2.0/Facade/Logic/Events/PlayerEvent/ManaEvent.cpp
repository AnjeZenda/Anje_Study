#include "ManaEvent.h"


void ManaEvent::invoke() {
    if (!_isActive)
        return;
    _isActive = false;
    if (_observer)
        _observer->onManaEventInvoked();
    player->setMana(player->getMana() + 10);
}

bool ManaEvent::isActive() {
    return _isActive;
}

IEvent *ManaEvent::clone() {
    auto event = new ManaEvent();
    event->_isActive = this->_isActive;
    event->setPlayer(player);
    return event;
}

void ManaEvent::setObserver(IManaEventObserver *observer) {
    _observer = observer;
}
