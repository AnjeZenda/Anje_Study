#ifndef GAME_VER2_0_GAMEINFO_H
#define GAME_VER2_0_GAMEINFO_H


#include <string>
#include "../FieldScheme/FieldScheme.h"
#include "../Player/Player.h"

struct PlayerInfo {
    int health, damage, mana;
    PlayerRace pRace;
    PlayerClass pClass;
    int x, y;
    operator std::string() const {
        std::string str;
        str.reserve(21);
        str += std::to_string(health) + " " + std::to_string(damage) + " " + std::to_string(mana);
        int e = static_cast<int>(pRace);
        str += " " + std::to_string(e);
        e = static_cast<int>(pClass);
        str += " " + std::to_string(e);
        str += " " + std::to_string(x) + " " + std::to_string(y);
        return str;
    }
};

struct GameInfo {
    FieldScheme scheme;
    PlayerInfo player;
    explicit operator std::string() const;
};


#endif //GAME_VER2_0_GAMEINFO_H