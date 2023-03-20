#pragma once
#include <vector>
#include "IMediator.h"
#include "../Controllers/IController.h"
#include "../Reader/Reader.h"

class Mediator : public IMediator {
private:
    std::vector<IController *> controllers;
    std::vector<Reader *> readers;
public:
    void process(Command command) override;
    void addReader(Reader *) override;
    void addController(IController *) override;
    void removeReader(Reader *);
    void removeController(IController *);
    ~Mediator() override;
};