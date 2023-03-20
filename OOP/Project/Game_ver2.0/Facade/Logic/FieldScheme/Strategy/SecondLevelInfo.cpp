#include "SecondLevelInfo.h"

FieldScheme SecondLevelInfo::generate() {
    scheme.info.resize(10);
    for (auto& row: scheme.info) {
        row.resize(10);
    }
    this->generator.generate(scheme);
    return scheme;
}
