#include <fstream>
#include <algorithm>
#include "Saver.h"



void Saver::save(const GameInfo &info) {
    std::ofstream file("save.txt");
    if (!file.is_open()) {
        throw SaverException("File is beaten");
    }
    file << std::string(info) << '\n';
    file << hash(info);
    file.close();
}

GameInfo Saver::load() {
    std::ifstream file("save.txt");
    if (!file.good()) {
        throw SaverException("File is beaten\n");
    }
    std::vector<std::string> fieldInfo;
    std::string playerInfo;
    std::string str;
    while (std::getline(file, str), str.find('*') == std::string::npos) {
        fieldInfo.emplace_back(str);
    }
    std::getline(file, playerInfo);
    std::getline(file, str);
    GameInfo info;
    info.scheme = decodeField(fieldInfo);
    info.player = decodePlayer(playerInfo);
    auto h = hash(info);
    int64_t h_read = strtoll(str.data(), nullptr, 10);
    if (h_read != h) {
        throw SaverException("File was changed!\n", info);
    }
    return info;
}

FieldScheme Saver::decodeField(std::vector<std::string> vec) {
    if (vec.empty()) {
        throw SaverException("Empty vector!\n");
    }
    FieldScheme scheme;
    int size = vec.size();
    int width = vec[0].size();
    if (size != width) {
        throw SaverException("Wrong size of width\n");
    }
    scheme.info.resize(size);
    for (int i = 0; i < size; ++i) {
        if (vec[i].size() != size) {
            throw SaverException("Wrong size of string\n");
        }
        scheme.info[i].resize(size);
        for (int j = 0; j < size; ++j) {
            scheme.info[i][j] = static_cast<CellType>((vec[i][j] - '0'));
        }
    }
    return scheme;
}

PlayerInfo Saver::decodePlayer(std::string str) {
    if (str.empty()) {
        throw SaverException("Player string is empty\n");
    }
    char *ptr;
    if (std::count(str.begin(), str.end(), ' ') != 6) {
        throw SaverException("Wrong player info in the file\n");
    }
    PlayerInfo player;
    player.health = std::strtol(str.data(), &ptr, 10);
    player.damage = std::strtol(ptr, &ptr, 10);
    player.mana = std::strtol(ptr, &ptr, 10);
    player.pRace = static_cast<PlayerRace>(std::strtol(ptr, &ptr, 10));
    player.pClass = static_cast<PlayerClass>(std::strtol(ptr, &ptr, 10));
    player.x = std::strtol(ptr, &ptr, 10);
    player.y = std::strtol(ptr, &ptr, 10);
    return player;
}

int64_t Saver::hash(const GameInfo& info) {
    int64_t h = 5381;
    std::string str = std::string(info);
    for (auto c : str) {
        h = (((h << 5) + h) + c) % INT64_MAX;
    }
    return h;
}

const char *SaverException::what() const noexcept {
    return str.data();
}


std::string SaverException::getMessage() {
    return str;
}


SaverException::SaverException(std::string str, std::optional<GameInfo> info) {
    this->str = str;
    this->info = info;
}

std::optional<GameInfo> &SaverException::getInfo() {
    return info;
}
