#include "ChangePassability.h"


void ChangePassability::invoke() {
    if (!_isActive)
        return;
    _isActive = false;
    if(_observer)
        _observer->onChangePassabilityEventInvoked();
    _fieldChanger->changePassability();
}

bool ChangePassability::isActive() {
    return _isActive;
}

IEvent *ChangePassability::clone() {
    auto event = new ChangePassability();
    event->_isActive = this->_isActive;
    event->setField(_fieldChanger);
    return event;
}

void ChangePassability::setObserver(IChangePassabilityEventObserver *observer) {
    _observer = observer;
}
