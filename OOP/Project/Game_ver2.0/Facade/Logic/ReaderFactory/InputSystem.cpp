#include "InputSystem.h"

InputSystem::InputSystem(IReaderFactory *factory) : _factory(factory){

}

void InputSystem::addReader() {
    for (auto mediator : mediators) {
        auto reader = _factory->create();
        reader->setMediator(mediator);
        mediator->addReader(reader);
    }
}

InputSystem::~InputSystem() {
    for (auto mediator : mediators) {
        delete mediator;
    }
    delete _factory;
}

void InputSystem::addMediators(IMediator *mediator) {
    mediators.emplace_back(mediator);
}
