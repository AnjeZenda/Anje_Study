#pragma once
class IController;
class Reader;
enum class Command;

class IMediator {
public:
    virtual void process(Command command) = 0;
    virtual void addReader(Reader *) = 0;
    virtual void addController(IController *) = 0;
    virtual ~IMediator()= default;
};