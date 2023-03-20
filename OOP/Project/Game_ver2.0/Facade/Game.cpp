#include <iostream>
#include "Game.h"
#include "Logic/Controllers/PlayerController.h"
#include "Logic/Reader/KeyboardReader.h"
#include "Logic/Mediator/Mediator.h"
#include "LogInitializer.h"
#include "Logic/ReaderFactory/InputReaderFactory.h"
#include "Logic/Controllers/GameController.h"

Game::Game() { //TODO initializer list
    condition = GameCondition::WORK;
    window = nullptr;
    field = nullptr;
    player = nullptr;
    factory = nullptr;
    drawer = nullptr;
    playerController = nullptr;
    reader = nullptr;
    mediator = nullptr;
    playerObserver = nullptr;
    fieldObserver = nullptr;
    system = nullptr;
    handler = nullptr;
}

Game::~Game() {
    delete fieldObserver;
    delete system;
    delete handler;
    delete playerController;
    delete factory;
    delete drawer;
    delete player;
    delete field;
    delete window;
}

void Game::start() {
    LogInitializer::execute();
    Menu menu{};

    factory = new EventFactory();
    player = new Player(menu.getRace(), menu.getClass());
    playerObserver = new PlayerObserver(this);
    fieldObserver = new FieldObserver();
    player->setObserver(playerObserver);
    player->setAttributes();
    factory->setPlayer(player);

    fieldChanger = new FieldChanger(factory);
    factory->setField(fieldChanger);

    fieldGenerator = new FieldGenerator(factory);
    fieldGenerator->setLevel(menu.getLevel());
    field = fieldGenerator->create();
    field->setObserver(fieldObserver);
    fieldChanger->setField(field);
    factory->setField(fieldChanger);


    mediator = new Mediator();

    handler = new SFMLHandler();

    system = new InputSystem(new InputReaderFactory(handler));
    system->addMediators(mediator);
    system->addReader();


    playerController = new PlayerController();
    playerController->setField(field);


    mediator->addController(playerController);

    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game");
    drawer = new Drawer(field, window);
    this->update();
}

void Game::update() {
    GameController *ctrl = new GameController(this);
    mediator->addController(ctrl);
    while (window->isOpen() && condition == GameCondition::WORK) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            handler->update(event);
        }
        drawer->drawScene();
    }
    delete ctrl;
}

void Game::stop() {
    condition = GameCondition::STOP;
}

void Game::load() {
    auto *field_new = saverController.load(*player, *fieldGenerator);
    if (field_new == nullptr) {
        Logger::getInstance() << LogMessage{"Faild to load saving", Logger::Error};
        return;
    }
    delete field;
    field = field_new;
    field->setObserver(fieldObserver);
    fieldChanger->setField(field);
    factory->setField(fieldChanger);
    playerController->setField(field);
    drawer->changeField(field);
}

void Game::save() {
    saverController.save(*field, *player);
}