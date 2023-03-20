#include "ThirdLevelInfo.h"

FieldScheme ThirdLevelInfo::generate() {
    scheme.info.resize(15);
    for (auto& row: scheme.info) {
        row.resize(15);
    }
    this->generator.generate(scheme);
    return scheme;
}
