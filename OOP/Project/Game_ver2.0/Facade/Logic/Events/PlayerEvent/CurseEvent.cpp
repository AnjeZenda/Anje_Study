#include "CurseEvent.h"
#include "../../Player/Player.h"
#include <random>
#include <iostream>

void CurseEvent::invoke() {
    if (!_isActive)
        return;
    _isActive = false;
    if (_observer)
        _observer->onCurseEventInvoked();
    PlayerRace newRace = static_cast<PlayerRace>(rand() % 4);
    PlayerClass newClass = static_cast<PlayerClass>(rand() % 5);
    player->setClass(newClass);
    player->setRace(newRace);
    player->setAttributes();
}

bool CurseEvent::isActive() {
    return _isActive;
}

IEvent *CurseEvent::clone() {
    auto event = new CurseEvent();
    event->_isActive = this->_isActive;
    event->setPlayer(player);
    return event;
}

void CurseEvent::setObserver(ICurseEventObserver *observer) {
    _observer = observer;
}
