#include "PlayerEvent.h"

void PlayerEvent::setPlayer(Player *player) {
    this->player = player;
}

PlayerEvent::~PlayerEvent() {
    this->player = nullptr;
}
