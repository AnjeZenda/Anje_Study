#include "DamageCurseEvent.h"
#include "../../Player/Player.h"
#include <random>

void DamageCurseEvent::invoke() {
    if (!_isActive)
        return;
    _isActive = false;
    int damage = (rand() % player->getHealth()) + 1;
    if (_observer)
        _observer->onDamageCurseEventInvoked(damage);
    player->setHealth(player->getHealth() - damage);
}

bool DamageCurseEvent::isActive() {
    return _isActive;
}

IEvent *DamageCurseEvent::clone() {
    auto event = new DamageCurseEvent();
    event->_isActive = this->_isActive;
    event->setPlayer(player);
    return event;
}

void DamageCurseEvent::setObserver(IDamageCurseEventObserver *observer) {
    _observer = observer;
}
