#include "GameInfo.h"

GameInfo::operator std::string() const {
    return std::string(scheme) + "*\n" + std::string(player);
}
