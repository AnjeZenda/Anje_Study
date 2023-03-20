#pragma once
#include "Logic/Player/Player.h"
#include "Logic/Field/Field.h"
#include "SFML/Graphics.hpp"
#include "Graphic/Drawer.h"
#include "Logic/EventFactory/EventFactory.h"
#include "UserDisplay/Menu.h"
#include "Logic/Reader/KeyboardReader.h"
#include "Logic/Controllers/PlayerController.h"
#include "Logic/Mediator/Mediator.h"
#include "Logic/Field/FieldGenerator.h"
#include "IGame.h"
#include "Logic/Player/PlayerObserver.h"
#include "Logic/Field/FieldObserver.h"
#include "Logic/ReaderFactory/SFMLHandler.h"
#include "Logic/ReaderFactory/InputSystem.h"
#include "Logic/Saver/SaverController.h"

enum class GameCondition {
    STOP, WORK
};

class Game : public IGame{
private:
    InputSystem *system;
    SFMLHandler *handler;
    sf::RenderWindow *window;
    Player *player;
    Field *field;
    Drawer *drawer;
    EventFactory *factory;
    KeyboardReader *reader;
    Mediator *mediator;
    PlayerController *playerController;
    FieldGenerator *fieldGenerator;
    FieldChanger *fieldChanger;
    GameCondition condition;
    PlayerObserver *playerObserver;
    FieldObserver *fieldObserver;
    SaverController saverController;
public:
    Game();
    ~Game();
    void start();
    void update();
    void stop() override;
    void load();
    void save();
};

