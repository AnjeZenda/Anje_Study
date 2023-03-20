#include "FirstLevelInfo.h"

FieldScheme FirstLevelInfo::generate() {
    scheme.info.resize(7);
    for (auto& row: scheme.info) {
        row.resize(7);
    }
    this->generator.generate(scheme);
    return scheme;
}
