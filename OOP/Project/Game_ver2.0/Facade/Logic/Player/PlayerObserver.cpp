#include "PlayerObserver.h"

#include <iostream>
#include "Player.h"
#include "../../IGame.h"
#include "../Log/Logger.h"

void PlayerObserver::onWon() {
    Logger::getInstance() << LogMessage{"Win!", Logger::Info};
    std::cout << "You won!\n";
    game->stop();
}

PlayerObserver::PlayerObserver(IGame *game) : game(game) {}

void PlayerObserver::onHealthChanged(int health) {
    Logger::getInstance() << LogMessage{("Player health changed to " + std::to_string(health)), Logger::Acts};
    if (health < 1) {
        std::cout << "You are defeated!\n";
        Logger::getInstance() << LogMessage{"You are defeated!", Logger::Info};
        game->stop();
    }

}

PlayerObserver &PlayerObserver::operator<<(const Player &player) {
    Logger::getInstance() << LogMessage{"Player info | health: " + std::to_string(player.getHealth()) + ", mana: " +
                                        std::to_string(player.getMana()), Logger::Info};
    return *this;
}
