#ifndef GAME_VER2_0_GAMECONTROLLER_H
#define GAME_VER2_0_GAMECONTROLLER_H


#include "IController.h"

class Game;

class GameController : public IController{
private:
    Game* game;
public:
    explicit GameController(Game *game);
    void process(Command command) override;
    ~GameController();
};


#endif //GAME_VER2_0_GAMECONTROLLER_H