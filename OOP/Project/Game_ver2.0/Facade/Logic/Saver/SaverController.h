#ifndef GAME_VER2_0_SAVERCONTROLLER_H
#define GAME_VER2_0_SAVERCONTROLLER_H


#include "Saver.h"
#include "../Field/Field.h"
class FieldGenerator;

class SaverController {
private:
    Saver saver;
public:
    SaverController() = default;
    void save(const Field& field, const Player& player);
    Field* load(Player& player, FieldGenerator& generator);
};


#endif //GAME_VER2_0_SAVERCONTROLLER_H