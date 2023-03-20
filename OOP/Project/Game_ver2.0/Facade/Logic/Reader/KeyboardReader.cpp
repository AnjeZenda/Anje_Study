#include "KeyboardReader.h"
#include "../Controllers/IController.h"
#include "../ReaderFactory/KeyEventScheme.h"
KeyboardReader::KeyboardReader(IMediator *mediator) : Reader(mediator) {}

void KeyboardReader::setMediator(IMediator *mediator) {
    this->mediator = mediator;
}

void KeyboardReader::setCommands(KeyEventScheme *scheme) {
    this->scheme = scheme;
}

void KeyboardReader::update(sf::Event event) {
    if (event.type == sf::Event::KeyReleased) {
        auto code = event.key.code;
        if (scheme->getCommand(code) == "Left") {
            mediator->process(Command::MOVE_LEFT);
        } else if (scheme->getCommand(code) ==  "Right") {
            mediator->process(Command::MOVE_RIGHT);
        } else if (scheme->getCommand(code) == "Down") {
            mediator->process(Command::MOVE_DOWN);
        } else if (scheme->getCommand(code) == "Up") {
            mediator->process(Command::MOVE_UP);
        } else if (scheme->getCommand(code) == "Attack") {
            mediator-> process(Command::ATTACK);
        } else if (scheme->getCommand(code) == "Research") {
            mediator->process(Command::RESEARCH);
        } else if (scheme->getCommand(code) == "Save") {
            mediator->process(Command::SAVE);
        } else if (scheme->getCommand(code) == "Load") {
            mediator->process(Command::LOAD);
        }
    }
}

KeyboardReader::~KeyboardReader() {
    delete scheme;
}





