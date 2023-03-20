#include "Cell.h"

Cell::Cell() {
    this->cellType = FREE;
    this->event = nullptr;
    this->playerPresence = false;
}

Cell::~Cell() {
    delete this->event;
}

void Cell::setEvent(IEvent *event) {
    delete this->event;
    this->event = event;
}

Cell::Cell(const Cell &other) {
    this->cellType = other.cellType;
}

Cell &Cell::operator=(const Cell &other) {
    this->cellType = other.cellType;
    return *this;
}

CellType Cell::getType() const {
    return this->cellType;
}

bool Cell::isPlayerHere() const {
    return this->playerPresence;
}

void Cell::setType(CellType cellType) {
    this->cellType = cellType;
}

void Cell::react() {
    if (cellType == UNEXPLORED) {
        return;
    }
    if (cellType == OCCUPIED || cellType == FIELD_CHANGER)
        cellType = FREE;
    runEvent();
}

void Cell::runEvent() {
    if (this->event == nullptr)
        return;

    this->event->invoke();
    if (!event->isActive()) {
        delete this->event;
        this->event = nullptr;
    }
}

void Cell::setPlayerPresence(bool isHere) {
    this->playerPresence = isHere;
}

void Cell::research() {
    if (cellType != UNEXPLORED) {
        return;
    }
    runEvent();
    setType(FREE);
}
