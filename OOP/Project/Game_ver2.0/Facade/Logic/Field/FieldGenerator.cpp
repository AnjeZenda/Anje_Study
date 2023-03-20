#include "FieldGenerator.h"

#include <random>
#include <iostream>

#include "../EventFactory/EventFactory.h"

#include "../Events/FieldEvent/ChangePassability.h"
#include "../Events/FieldEvent/ReverseField.h"
#include "../Events/PlayerEvent/DamageCurseEvent.h"
#include "../Events/PlayerEvent/CurseEvent.h"
#include "../Events/PlayerEvent/ManaEvent.h"
#include "../Events/PlayerEvent/HealEvent.h"
#include "../Events/ExitEvent.h"
#include "../FieldScheme/Strategy/FirstLevelInfo.h"
#include "../FieldScheme/Strategy/SecondLevelInfo.h"
#include "../FieldScheme/Strategy/ThirdLevelInfo.h"

FieldGenerator::FieldGenerator(EventFactory *_eventFactory) : _eventFactory(_eventFactory) {}

void FieldGenerator::execute(Field &field) {
    auto& cells = field.cells;
    auto width = field.getWidth();
    auto height = field.getHeight();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (cells[i][j].getType() == PLAYER) {
                cells[i][j].setPlayerPresence(true);
            } else if (cells[i][j].getType() == FIELD_CHANGER) {
                int r = rand() % 2;
                if (r == 1) {
                    auto event = _eventFactory->create<ChangePassability>();
                    cells[i][j].setEvent(event);
                    continue;
                }
                auto event = _eventFactory->create<ReverseField>();
                cells[i][j].setEvent(event);
            } else if (cells[i][j].getType() == EXIT) {
                auto event = _eventFactory->create<ExitEvent>();
                cells[i][j].setEvent(event);
            } else if (cells[i][j].getType() == OCCUPIED) {
                auto event = _eventFactory->create<DamageCurseEvent>();
                cells[i][j].setEvent(event);
            } else if (cells[i][j].getType() == UNEXPLORED) {
                int num = rand() % 4;
                if (num == 0) {
                    auto event = _eventFactory->create<CurseEvent>();
                    cells[i][j].setEvent(event);
                } else if (num == 1) {
                    auto event = _eventFactory->create<DamageCurseEvent>();
                    cells[i][j].setEvent(event);
                } else if (num == 2) {
                    auto event = _eventFactory->create<ManaEvent>();
                    cells[i][j].setEvent(event);
                } else if (num == 3) {
                    auto event = _eventFactory->create<HealEvent>();
                    cells[i][j].setEvent(event);
                }
            }
        }
    }
}

void FieldGenerator::setStrategy(IStrategy *iStrategy) {
    this->strategy = iStrategy;
}

void FieldGenerator::setLevel(Level level) {
    this->level = level;
    switch(level) {
        case Level::FIRST:
            setStrategy(new FirstLevelInfo());
            break;
        case Level::SECOND:
            setStrategy(new SecondLevelInfo());
            break;
        case Level::THIRD:
            setStrategy(new ThirdLevelInfo());
            break;
    }
}

void FieldGenerator::setScheme() {
    this->fieldScheme = strategy->generate();
}

Field *FieldGenerator::create() {
    this->setScheme();
    return create(fieldScheme);
}

FieldGenerator::~FieldGenerator() {
    this->_eventFactory = nullptr;
    delete this->strategy;
}

Field *FieldGenerator::create(FieldScheme &scheme) {
    int size = scheme.info.size();
    auto field = new Field(size, size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            switch (scheme.info[i][j]) {
                case PLAYER:
                    field->setPlayerPosition(j, i);
                    break;
                case BLOCKED:
                    field->cells[i][j].setType(BLOCKED);
                    break;
                case UNEXPLORED:
                    field->cells[i][j].setType(UNEXPLORED);
                    break;
                case OCCUPIED:
                    field->cells[i][j].setType(OCCUPIED);
                    break;
                case FIELD_CHANGER:
                    field->cells[i][j].setType(FIELD_CHANGER);
                    break;
                case EXIT:
                    field->cells[i][j].setType(EXIT);
                    break;
                default:
                    break;
            }
        }
    }
    this->execute(*field);
    return field;
}
