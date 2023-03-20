#ifndef GAME_VER2_0_SAVER_H
#define GAME_VER2_0_SAVER_H

#include <optional>
#include "GameInfo.h"

class Saver {
private:
    static FieldScheme decodeField(std::vector<std::string> vec);
    static PlayerInfo decodePlayer(std::string str);
public:
    static void save(const GameInfo& info);
    static GameInfo load();
    static int64_t hash(const GameInfo &info);
};

class SaverException : public std::exception{
private:
    std::string str;
    std::optional<GameInfo> info;
public:
    explicit SaverException(std::string str, std::optional<GameInfo> info = std::nullopt);
    [[nodiscard]] const char * what() const noexcept override;
    std::string getMessage();
    [[nodiscard]] std::optional<GameInfo> &getInfo();
};

#endif //GAME_VER2_0_SAVER_H