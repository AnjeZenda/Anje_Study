#ifndef GAME_VER2_0_IPLAYEROBSERVER_H
#define GAME_VER2_0_IPLAYEROBSERVER_H


class IPlayerObserver {
public:
    virtual void onWon() = 0;
    virtual ~IPlayerObserver() = default;
    virtual void onHealthChanged(int health) = 0;
};


#endif //GAME_VER2_0_IPLAYEROBSERVER_H