#pragma once

#include "IPlayerObserver.h"

enum PlayerClass {
    NO_CLASS, WARRIOR, WIZARD, THIEF, CLERIC
};

enum PlayerRace {
    HUMAN, ELF, DWARF, ORC
};

class Player {
private:
    int health, damage, mana;
    PlayerRace pRace;
    PlayerClass pClass;
    IPlayerObserver *observer;
public:
    Player(PlayerRace, PlayerClass);
    Player();
    void setHealth(int);
    void setMana(int);
    int getMana() const;
    int getHealth() const;
    int getDamage() const;
    PlayerRace getPRace() const;
    PlayerClass getPClass() const;
    void setRace(PlayerRace r);
    void setClass(PlayerClass c);
    void setAttributes();
    void setDamage(int damage);
    void setObserver(IPlayerObserver *observer);
    void win();
};
