#pragma once
#include "../Mediator/IMediator.h"
#include "SFML/Graphics.hpp"
class Reader {
protected:
    IMediator *mediator;
public:
    explicit Reader(IMediator *mediator = nullptr);
    virtual void setMediator(IMediator *mediator) = 0;
};
