#ifndef GAME_VER2_0_PLAYEROBSERVER_H
#define GAME_VER2_0_PLAYEROBSERVER_H
#include "IPlayerObserver.h"
class IGame;

class Player;

class PlayerObserver : public IPlayerObserver{
private:
    IGame *game;
public:
    explicit PlayerObserver(IGame *game);
    void onWon() override;
    void onHealthChanged(int health) override;
    ~PlayerObserver() override = default;

    PlayerObserver& operator<<(const Player& player);
};


#endif //GAME_VER2_0_PLAYEROBSERVER_H