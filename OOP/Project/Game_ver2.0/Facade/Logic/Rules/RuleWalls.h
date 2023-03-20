#ifndef GAME_VER2_0_RULEWALLS_H
#define GAME_VER2_0_RULEWALLS_H

#include <cstdlib>
#include "../FieldScheme/FieldScheme.h"

template<int ... Args>
class RuleWalls {};

template<int Count>
class RuleWalls<Count> {
private:
    void fieldInfo(FieldScheme& fieldScheme) {
        for (auto row : fieldScheme.info) {
            for (auto elem : row) {
                std::cout << elem << " ";
            }
            std::cout << '\n';
        }
        std::cout << "--------------------------------\n";
    }
    void createWall(FieldScheme& fieldScheme, int count) {
        for (int i = 0; i < count; ++i) {
            int x = rand() % fieldScheme.info.size();
            int y = rand() % fieldScheme.info.size();
            fieldScheme.info[y][x] = fieldScheme.info[y][x] != BLOCKED ? BLOCKED : FIELD_CHANGER;
        }
    }
    void createWall(FieldScheme& fieldScheme, int count, std::pair<int, int> position) {
        for (int i = 0; i < count; ++i) {
            int x = rand() % fieldScheme.info.size();
            int y = rand() % fieldScheme.info.size();
            fieldScheme.info[y][x] = fieldScheme.info[y][x] != BLOCKED && fieldScheme.info[y][x] != EXIT && fieldScheme.info[y][x] != PLAYER ? BLOCKED : FIELD_CHANGER;
        }
        for (int i = (position.first - 1) % fieldScheme.info.size(), c = 0; c < 3; ++c, i = (i + 1) % fieldScheme.info.size()){
            for (int j = (position.second - 1) % fieldScheme.info.size(), k = 0; k < 3; ++k, j = (j + 1) % fieldScheme.info.size()) {
                if (i == position.first && j == position.second) {
                    continue;
                }
                fieldScheme.info[i][j] = FREE;
            }
        }
    }
    void createWall(FieldScheme& fieldScheme, int count, std::pair<int, int> exitPosition, std::pair<int, int> playerPosition) {
        for (int i = 0; i < count; ++i) {
            int x = rand() % fieldScheme.info.size();
            int y = rand() % fieldScheme.info.size();
            fieldScheme.info[y][x] = fieldScheme.info[y][x] != BLOCKED && fieldScheme.info[y][x] != EXIT && fieldScheme.info[y][x] != PLAYER ? BLOCKED : FIELD_CHANGER;
        }
        auto x = playerPosition.second % fieldScheme.info.size();
        while (x != exitPosition.second) {
            ++x %= fieldScheme.info.size();
            fieldScheme.info[playerPosition.first][x] = FREE;
        }
        auto y = (playerPosition.first + 1) % fieldScheme.info.size();
        while (y != exitPosition.first) {
            fieldScheme.info[y][x] = FREE;
            ++y %= fieldScheme.info.size();
        }
    }

public:
    void update(FieldScheme& fieldScheme) {
        int count;
        if (Count < 0) {
            Logger::getInstance() << LogMessage{
                    "Attempt to set an invalid number of cells. Set default",
                    Logger::Error};
            count = fieldScheme.info.size() * fieldScheme.info.size() / 4;
        } else
            count = Count % (fieldScheme.info.size() * fieldScheme.info.size() / 4) + 1;
        std::pair<int, int> exitPosition{-1, -1}, playerPosition{-1, -1};
        for (int i = 0; i < fieldScheme.info.size(); ++i) {
            for (int j = 0; j < fieldScheme.info.size(); ++j) {
                if (fieldScheme.info[i][j] == EXIT) {
                    exitPosition = std::make_pair(i, j);
                }
                if (fieldScheme.info[i][j] == PLAYER) {
                    playerPosition = std::make_pair(i, j);
                }
            }
            if (exitPosition.first != -1 && playerPosition.first != -1) {
                break;
            }
        }
        if (exitPosition.first == -1 && playerPosition.first == -1) {
            createWall(fieldScheme, count);
        } else if (exitPosition.first == -1) {
            createWall(fieldScheme, count, playerPosition);
        } else if (playerPosition.first == -1) {
            createWall(fieldScheme, count, exitPosition);
        } else {
            createWall(fieldScheme, count, exitPosition, playerPosition);
        }
    }
};

template<int X, int Y>
class RuleWalls<X, Y> {
public:
    void update(FieldScheme& fieldScheme) {
        if (X < 0 || Y < 0 || X >= fieldScheme.info.size() || Y >= fieldScheme.info.size() || fieldScheme.info[Y][X] != FREE) {
            Logger::getInstance() << LogMessage{
                    "Attempt to set the value beyond the boundaries of the field. Failed to set this value",
                    Logger::Error};
            return;
        }
        fieldScheme.info[Y][X] = BLOCKED;
    }
};

#endif //GAME_VER2_0_RULEWALLS_H