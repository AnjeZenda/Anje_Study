#include "FieldChanger.h"

#include <random>

#include "../EventFactory/EventFactory.h"

#include "../Events/PlayerEvent/DamageCurseEvent.h"
#include "../Events/PlayerEvent/CurseEvent.h"
#include "../Events/PlayerEvent/ManaEvent.h"
#include "../Events/PlayerEvent/HealEvent.h"
#include "../Events/FieldEvent/ChangePassability.h"
#include "../Events/FieldEvent/ReverseField.h"

void FieldChanger::reverseField() {
    if (_field == nullptr)
        return;
    auto& cells = _field->cells;
    int posY = 0;
    int posX = 0;
    auto obs = _field->observer;
    for (auto& row: cells) {
        posX = 0;
        for (auto& cell : row) {
            if (cell.isPlayerHere()) {
                continue;
            }
            if (cell.getType() == UNEXPLORED) {
                cell.setType(OCCUPIED);
                cell.setEvent(nullptr);
                auto event = _eventFactory->create<DamageCurseEvent>();
                cell.setEvent(event);
                obs->onCellEventChanged(posX, posY, "DamageCurseEvent");
            }
            else if (cell.getType() == OCCUPIED) {
                cell.setType(UNEXPLORED);
                cell.setEvent(nullptr);
                int num = rand() % 6;
                if (num == 0) {
                    auto event = _eventFactory->create<CurseEvent>();
                    cell.setEvent(event);
                    obs->onCellEventChanged(posX, posY, "CurseEvent");
                } else if (num == 1) {
                    auto event = _eventFactory->create<DamageCurseEvent>();
                    cell.setEvent(event);
                    obs->onCellEventChanged(posX, posY, "DamageCurseEvent");
                } else if (num == 2) {
                    auto event = _eventFactory->create<ManaEvent>();
                    cell.setEvent(event);
                    obs->onCellEventChanged(posX, posY, "ManaEvent");
                } else if (num == 3) {
                    auto event = _eventFactory->create<HealEvent>();
                    cell.setEvent(event);
                    obs->onCellEventChanged(posX, posY, "HealthEvent");
                } else if (num == 4) {
                    auto event = _eventFactory->create<ChangePassability>();
                    cell.setEvent(event);
                    obs->onCellEventChanged(posX, posY, "ChangePassability");
                } else if (num == 5) {
                    auto event = _eventFactory->create<ReverseField>();
                    cell.setEvent(event);
                    obs->onCellEventChanged(posX, posY, "ReverseField");
                }
            }
            ++posX;
        }
        ++posY;
    }
}

void FieldChanger::setField(Field *field) {
    FieldChanger::_field = field;
}

const Field &FieldChanger::getField() const {
    return *_field;
}

void FieldChanger::setEventFactory(EventFactory *eventFactory) {
    _eventFactory = eventFactory;
}

void FieldChanger::changePassability() {
    for (int i = _field->getPlayerPositionY() - 1; i <= _field->getPlayerPositionY() + 1; ++i) {
        for (int j = _field->getPlayerPositionX() - 1; j <= _field->getPlayerPositionX() + 1; ++j) {
            if (i == _field->getPlayerPositionY() && j == _field->getPlayerPositionX()) {
                continue;
            }
            int posY = i < 0 ? _field->getHeight() + i : (i >= _field->getHeight() ? i - _field->getHeight() : i);
            int posX = j < 0 ? _field->getWidth() + j : (j >= _field->getWidth() ? j - _field->getWidth() : j);
            if (_field->getCell(posX, posY).getType() == BLOCKED) {
                _field->cells[posY][posX].setType(FREE);
                _field->observer->onCellPassabilityChanged(posX, posY, true);
            }
        }
    }
}

FieldChanger::FieldChanger(EventFactory *eventFactory) : _eventFactory(eventFactory) {}
