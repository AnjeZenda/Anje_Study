#pragma once
#include "../Events/IEvent.h"

enum CellType {
    FREE, PLAYER, EXIT, OCCUPIED, BLOCKED, UNEXPLORED, FIELD_CHANGER
};

class Cell {
private:
    IEvent *event;
    bool playerPresence;
    CellType cellType;
public:
    Cell();
    ~Cell();
    Cell(const Cell &);
    Cell &operator=(const Cell&other);
    void setEvent(IEvent *event);
    [[nodiscard]] CellType getType() const;
    [[nodiscard]] bool isPlayerHere() const;
    void setType(CellType cellType);
    void react();
    void research();
    void runEvent();
    void setPlayerPresence(bool isHere);
};
