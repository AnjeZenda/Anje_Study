#include "SaverController.h"
#include "../Log/Logger.h"
#include "../Field/FieldGenerator.h"

void SaverController::save(const Field &field, const Player &player) {
    GameInfo info;
    int size = field.getHeight();
    auto& scheme = info.scheme.info;
    scheme.resize(size);
    for (int i = 0; i < size; ++i) {
        scheme[i].resize(size);
        for (int j = 0; j < size; ++j) {
            scheme[i][j] = field.getCell(j, i).getType();
        }
    }
    info.player.health = player.getHealth();
    info.player.mana = player.getMana();
    info.player.damage = player.getDamage();
    info.player.pClass = player.getPClass();
    info.player.pRace = player.getPRace();
    info.player.x = field.getPlayerPositionX();
    info.player.y = field.getPlayerPositionY();
    try {
        saver.save(info);
    } catch (SaverException& exception) {
        Logger::getInstance() << LogMessage {"Stinky code exception! " + exception.getMessage(), Logger::Error};
    }
}

Field *SaverController::load(Player &player, FieldGenerator& generator) {
    GameInfo info;
    try {
        info = saver.load();
    } catch (SaverException& exception) {
        Logger::getInstance() << LogMessage {"Unfortunately code exception! " + exception.getMessage(), Logger::Error};
        if (exception.getInfo().has_value()) {
            std::cout << "Would you like to load this save? If yes press 1 else press any key\n";
            int a;
            std::cin >> a;
            if (a != 1)
                return nullptr;
        }
        info = exception.getInfo().value();
    }
    auto& p = info.player;
    player.setHealth(p.health);
    player.setDamage(p.damage);
    player.setMana(p.mana);
    player.setRace(p.pRace);
    player.setClass(p.pClass);
    Field *field = generator.create(info.scheme);
    field->setPlayerPosition(p.x, p.y);
    return field;
}
