#include "EventObserver.h"
#include "../Log/Logger.h"

void EventObserver::onExitEventInvoked() {
    Logger::getInstance() << LogMessage{"Exit event invoked", Logger::Acts};
}

void EventObserver::onDamageCurseEventInvoked(int damage) {
    Logger::getInstance() << LogMessage{"Damage curse event invoked: " + std::to_string(damage), Logger::Acts};
}

void EventObserver::onCurseEventInvoked() {
    Logger::getInstance() << LogMessage{"You were cursed", Logger::Acts};
}

void EventObserver::onHealthEventInvoked() {
    Logger::getInstance() << LogMessage{"Bless healing!", Logger::Acts};
}

void EventObserver::onManaEventInvoked() {
    Logger::getInstance() << LogMessage{"Your mana was increased", Logger::Acts};
}

void EventObserver::onChangePassabilityEventInvoked() {
    Logger::getInstance() << LogMessage{"Broke blocked cells", Logger::Acts};
}

void EventObserver::onReverseFieldEventInvoked() {
    Logger::getInstance() << LogMessage{"Field was reversed", Logger::Acts};
}
