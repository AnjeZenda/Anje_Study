#ifndef GAME_VER2_0_RULEENEMY_H
#define GAME_VER2_0_RULEENEMY_H

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "../FieldScheme/FieldScheme.h"
#include "../Log/Logger.h"

template<int ... Args>
class RuleEnemy {
};

template<int Count>
class RuleEnemy<Count> {
    void fieldInfo(FieldScheme& fieldScheme) {
        for (auto row : fieldScheme.info) {
            for (auto elem : row) {
                std::cout << elem << " ";
            }
            std::cout << '\n';
        }
        std::cout << "--------------------------------\n";
    }
public:
    void update(FieldScheme &fieldScheme) {
        int count;
        if (Count < 0) {
            Logger::getInstance() << LogMessage{
                    "Attempt to set an invalid number of cells. Set default",
                    Logger::Error};
            count = fieldScheme.info.size() * fieldScheme.info.size() / 5;
        } else
            count = Count % (fieldScheme.info.size() * fieldScheme.info.size() / 5) + 1;

        bool flag_player_presence = false, flag_exit_presence = false;
        for (auto row: fieldScheme.info) {
            flag_player_presence = std::find(row.begin(), row.end(), PLAYER) != row.end() || flag_player_presence;
            flag_exit_presence = std::find(row.begin(), row.end(), EXIT) != row.end() || flag_exit_presence;
            if (flag_exit_presence && flag_player_presence)
                break;
        }
        int x = 0, y = 0;
        for (int i = 0; i < count; ++i) {
            x %= fieldScheme.info.size();
            y %= fieldScheme.info.size();
            auto old = fieldScheme.info[y][x];
            if (flag_player_presence && flag_exit_presence) {
                fieldScheme.info[y][x] = old != PLAYER && old != EXIT &&
                                         old != BLOCKED ? OCCUPIED : old;
            } else if (flag_player_presence) {
                fieldScheme.info[y][x] = old != PLAYER &&
                                         old != BLOCKED ? OCCUPIED : old;
            } else if (flag_exit_presence) {
                fieldScheme.info[y][x] = old != EXIT &&
                                         old != BLOCKED ? OCCUPIED : old;
            } else {
                fieldScheme.info[y][x] = old != BLOCKED ? OCCUPIED : old;
            }
            if (fieldScheme.info[y][x] == old) {
                ++x;
            }
            else {
                ++y;
                x += 12;
            }
        }
    }
};

template<int X, int Y>
class RuleEnemy<X, Y> {
public:
    void update(FieldScheme &fieldScheme) {
        if (X < 0 || Y < 0 || X >= fieldScheme.info.size() || Y >= fieldScheme.info.size() || fieldScheme.info[Y][X] != FREE) {
            Logger::getInstance() << LogMessage{
                    "Attempt to set the value beyond the boundaries of the field. Failed to set this value",
                    Logger::Error};
            return;
        }
        fieldScheme.info[Y][X] = OCCUPIED;
    }
};

#endif //GAME_VER2_0_RULEENEMY_H