#ifndef GAME_VER2_0_FIELDSCHEME_H
#define GAME_VER2_0_FIELDSCHEME_H

#include <vector>
#include <string>
#include "../Field/Cell.h"

struct FieldScheme{
    std::vector<std::vector<CellType>> info;
    operator std::string() const {
        std::string str;
        str.reserve((info.size() + 1) * info.size());
        for (auto row : info) {
            for (auto elem : row) {
                int e = static_cast<int>(elem);
                str += std::to_string(e);
            }
            str += "\n";
        }
        return str;
    }
};


#endif //GAME_VER2_0_FIELDSCHEME_H