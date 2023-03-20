#ifndef GAME_VER2_0_FIELDCHANGER_H
#define GAME_VER2_0_FIELDCHANGER_H


#include "Field.h"

class EventFactory;

class FieldChanger {
private:
    Field *_field = nullptr;
    EventFactory *_eventFactory = nullptr;
public:
    explicit FieldChanger(EventFactory *eventFactory);
    void changePassability();
    void reverseField();

    [[nodiscard]] const Field &getField() const;
    void setField(Field *field);

    void setEventFactory(EventFactory *eventFactory);
};


#endif //GAME_VER2_0_FIELDCHANGER_H