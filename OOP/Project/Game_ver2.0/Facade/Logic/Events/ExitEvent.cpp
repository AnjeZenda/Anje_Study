#include "ExitEvent.h"


void ExitEvent::invoke() {
    if (_observer)
        _observer->onExitEventInvoked();
    if (_fieldChanger->getField().countFreeCells() > _fieldChanger->getField().getHeight() * _fieldChanger->getField().getWidth() / 3) {
        player->win();
    }
}

bool ExitEvent::isActive() {
    return true;
}

IEvent *ExitEvent::clone() {
    auto event = new ExitEvent();
    event->setPlayer(player);
    event->setField(_fieldChanger);
    return event;
}

void ExitEvent::setObserver(IExitEventObserver *observer) {
    _observer = observer;
}
