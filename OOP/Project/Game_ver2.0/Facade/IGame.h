#ifndef GAME_VER2_0_IGAME_H
#define GAME_VER2_0_IGAME_H


class IGame {
public:
    virtual void stop() = 0;
    virtual ~IGame() = default;
};


#endif //GAME_VER2_0_IGAME_H