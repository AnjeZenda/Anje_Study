#include "FieldEvent.h"
#include "../../Field/Field.h"

void FieldEvent::setField(FieldChanger *field) {
    this->_fieldChanger = field;
}

FieldEvent::~FieldEvent() {
    this->_fieldChanger = nullptr;
}
