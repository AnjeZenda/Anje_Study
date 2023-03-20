#include "FieldObserver.h"
#include "../Log/Logger.h"
#include <string>
#include "Field.h"

void FieldObserver::onCellPassabilityChanged(int x, int y, bool isPassable) {
    Logger::getInstance() << LogMessage{
            "Cell(" + std::to_string(x) + ";" + std::to_string(y) + ") change passability to " +
            std::to_string(isPassable), Logger::Info};
}

void FieldObserver::onCellEventChanged(int x, int y, std::string eventName) {
    Logger::getInstance()
            << LogMessage{
                    "Cell(" + std::to_string(x) + ";" + std::to_string(y) + ") change event to " + eventName,
                    Logger::Info};
}

void FieldObserver::onCellAttemptStep() {
    Logger::getInstance() << LogMessage{"Attempt to step on a blocked cell", Logger::Error};
}

FieldObserver &FieldObserver::operator<<(const Field &field) {
    Logger::getInstance() << LogMessage{
            "Field info:\nsize: " + std::to_string(field.getHeight()) + "x" + std::to_string(field.getWidth()),
            Logger::Info};
    return *this;
}
