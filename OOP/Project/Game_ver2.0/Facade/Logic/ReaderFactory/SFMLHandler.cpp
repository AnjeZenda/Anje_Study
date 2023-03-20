#include "SFMLHandler.h"


void SFMLHandler::addSubscriber(SFMLSubscriber *sub) {
    subscribers.emplace_back(sub);
}

void SFMLHandler::update(sf::Event event) {
    for (auto sub: subscribers) {
        sub->update(event);
    }
}

SFMLHandler::~SFMLHandler() {
    for (auto sub : subscribers) {
        delete sub;
    }
}




