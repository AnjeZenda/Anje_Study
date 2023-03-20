#include "Player.h"
#include "../Log/Logger.h"

Player::Player(PlayerRace playerRace, PlayerClass playerClass) {
    pRace = playerRace;
    pClass = playerClass;
}

Player::Player() : Player(HUMAN, NO_CLASS) {

}

void Player::setHealth(int health) {
    if (health >= 200) {
        this->health = 200;
        return;
    }
    this->health = health;
    observer->onHealthChanged(this->health);
}

void Player::setMana(int mana) {
    if (mana >= 100) {
        this->mana = 100;
        return;
    } else if (mana <= 0) {
        this->mana = 0;
        return;
    }
    this->mana = mana;
    Logger::getInstance() << LogMessage{"Player's mana: " + std::to_string(this->mana)};
}

int Player::getMana() const {
    return mana;
}

int Player::getHealth() const {
    return health;
}

void Player::setAttributes() {//TODO unordered_map in GAME_ver3.0 PlayerGenerator
    switch (pRace) {
        case HUMAN:
            damage = 20;
            mana = 20;
            health = 50;
            break;
        case ELF:
            damage = 15;
            mana = 40;
            health = 40;
            break;
        case DWARF:
            damage = 30;
            mana = 0;
            health = 40;
            break;
        case ORC:
            damage = 25;
            mana = 10;
            health = 50;
            break;
    }
    switch (pClass) {
        case CLERIC:
            mana += 10;
            damage += 5;
            break;
        case WIZARD:
            mana += 20;
            health += 5;
            break;
        case WARRIOR:
            health += 20;
            damage += 10;
            break;
        case THIEF:
            damage += 10;
            mana += 5;
            break;
        case NO_CLASS:
            break;
    }
}

void Player::setRace(PlayerRace r) {
    this->pRace = r;
}

void Player::setClass(PlayerClass c) {
    this->pClass = c;
}

void Player::win() {
    observer->onWon();
}

void Player::setObserver(IPlayerObserver *observer) {
    Logger::getInstance() << LogMessage{"Player set the observer", Logger::Info};
    Player::observer = observer;
}

int Player::getDamage() const {
    return damage;
}

PlayerRace Player::getPRace() const {
    return pRace;
}

PlayerClass Player::getPClass() const {
    return pClass;
}

void Player::setDamage(int damage) {
    this->damage = damage;
}
