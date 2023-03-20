#pragma once
#include "Reader.h"
#include "SFML/Graphics.hpp"
#include "../ReaderFactory/SFMLSubscriber.h"

class KeyEventScheme;


class KeyboardReader : public Reader, public SFMLSubscriber{
private:
    KeyEventScheme *scheme;
public:
    explicit KeyboardReader(IMediator *mediator = nullptr);
    void setMediator(IMediator *mediator) override;
    void setCommands(KeyEventScheme *scheme);
    void update(sf::Event event) override;
    ~KeyboardReader() override;
};
