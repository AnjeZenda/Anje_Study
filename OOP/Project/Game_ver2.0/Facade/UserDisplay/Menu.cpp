#include "Menu.h"
#include <iostream>
#include "../Logic/Log/Logger.h"

Menu::Menu() {
    this->isEnterLevel = false;
    this->isEnterCharacter = false;
    while (executeField()) {
        Logger::getInstance() << LogMessage{"Attempt to enter field's incorrect values\n", Logger::Error};
    }
    while (executePlayer()) {
        Logger::getInstance() << LogMessage{"Attempt to enter player's incorrect values\n", Logger::Error};
        std::cout << "You entered wrong character\nTry again\n";
    }
    if (!this->isEnterLevel) {
        this->level = Level::FIRST;
        Logger::getInstance() << LogMessage{"Default level FIRST has been set\n", Logger::Info};
    }
    if (!this->isEnterCharacter) {
        this->pClass = NO_CLASS;
        this->pRace = HUMAN;
        Logger::getInstance() << LogMessage{"Default character has been set: human with no class\n", Logger::Info};
    }

}


bool Menu::executeField() {
    char userAnswer;
    int level;
    std::cout << "Would you like to create _field with your size[y/Y/n/N]: ";
    std::cin >> userAnswer;

    if (userAnswer == 'y' || userAnswer == 'Y') {
        std::cout << "Enter the level of game from 1 to 3\n";
        std::cout << "level: ";
        std::cin >> level;

        if (level > 3 || level < 1) return true;

        this->level = static_cast<Level>(level);
        this->isEnterLevel = true;
    }
    return false;
}


bool Menu::executePlayer() {
    char userAnswer;
    int playerRace, playerClass;

    std::cout << "Would you like to create your character[y/Y/n/N]: ";
    std::cin >> userAnswer;

    if (userAnswer == 'y' || userAnswer == 'Y') {
        std::cout << "Enter the race\n";
        std::cout << "Choose the character's race:\n\t0 - human\n\t1 - elf\n\t2 - dwarf\n\t3 - orc\n";
        std::cout << "Race: ";
        std::cin >> playerRace;
        std::cout
                << "Choose the character's class:\n\t0 - no class\n\t1 - warrior\n\t2 - wizard\n\t3 - thief\n\t4 - cleric\n";
        std::cout << "Class: ";
        std::cin >> playerClass;

        if (playerClass < 0 || playerClass > 4 || playerRace < 0 || playerRace > 3) {
            return true;
        }

        this->pRace = static_cast<PlayerRace>(playerRace);
        this->pClass = static_cast<PlayerClass>(playerClass);
        this->isEnterCharacter = true;
    }
    return false;
}

PlayerClass Menu::getClass() {
    return this->pClass;
}

PlayerRace Menu::getRace() {
    return this->pRace;
}

Level Menu::getLevel() {
    return level;
}
