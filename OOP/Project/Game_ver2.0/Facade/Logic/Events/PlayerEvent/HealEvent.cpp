#include "HealEvent.h"
#include "../../Player/Player.h"


void HealEvent::invoke() {
    if (!_isActive)
        return;
    _isActive = false;
    if (_observer)
        _observer->onHealthEventInvoked();
    player->setHealth(player->getHealth() + 10);
}

bool HealEvent::isActive() {
    return _isActive;
}

IEvent *HealEvent::clone() {
    auto event = new HealEvent();
    event->_isActive = this->_isActive;
    event->setPlayer(player);
    return event;
}

void HealEvent::setObserver(IHealthEventObserver *observer) {
    _observer = observer;
}
