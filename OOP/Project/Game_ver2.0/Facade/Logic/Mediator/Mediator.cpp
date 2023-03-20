#include <algorithm>
#include "Mediator.h"

void Mediator::process(Command command) {
    for (auto controller : controllers) {
        controller->process(command);
    }
}

void Mediator::addReader(Reader *reader) {
    this->readers.emplace_back(reader);
}

void Mediator::addController(IController *controller) {
    this->controllers.emplace_back(controller);
}

void Mediator::removeReader(Reader *reader) {
    this->readers.erase(std::remove(readers.begin(), readers.end(), reader), readers.end());
}

void Mediator::removeController(IController *controller) {
    this->controllers.erase(std::remove(controllers.begin(), controllers.end(), controller), controllers.end());
}

Mediator::~Mediator() {
    for (auto reader : readers) {
        reader = nullptr;
    }
}

