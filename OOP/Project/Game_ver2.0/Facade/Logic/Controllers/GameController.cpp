#include "GameController.h"
#include "../../Game.h"


void GameController::process(Command command) {
    switch(command) {
        case Command::SAVE:
            game->save();
            break;
        case Command::LOAD:
            game->load();
            break;
    }
}

GameController::GameController(Game *game) {
    this->game = game;
}

GameController::~GameController() {
    this->game = nullptr;
}
