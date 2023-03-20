#include "ReverseField.h"

void ReverseField::invoke() {
    if (!_isActive)
        return;
    _isActive = false;
    if (_observer)
        _observer->onReverseFieldEventInvoked();
    _fieldChanger->reverseField();
}

bool ReverseField::isActive() {
    return _isActive;
}

IEvent *ReverseField::clone() {
    auto event = new ReverseField();
    event->_isActive = this->_isActive;
    event->setField(_fieldChanger);
    return event;
}

void ReverseField::setObserver(IReverseFieldEventObserver *observer) {
    _observer = observer;
}
