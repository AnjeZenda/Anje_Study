#ifndef GAME_VER2_0_RULEPLAYERPOSITION_H
#define GAME_VER2_0_RULEPLAYERPOSITION_H

#include <algorithm>
#include "../FieldScheme/FieldScheme.h"


template<int X, int Y>
class RulePlayerPosition {
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
    void setPlayer(FieldScheme& fieldScheme, int x, int y) {
        fieldScheme.info[y][x] = PLAYER;
        for (int i = (y - 1) % fieldScheme.info.size(), c = 0; c < 3; ++c, i = (i + 1) % fieldScheme.info.size()){
            for (int j = (x - 1) % fieldScheme.info.size(), k = 0; k < 3; ++k, j = (j + 1) % fieldScheme.info.size()) {
                if (i == y && j == x) {
                    continue;
                }
                fieldScheme.info[i][j] = FREE;
            }
        }
    }
    void setPlayer(FieldScheme& fieldScheme, int x, int y, std::pair<int, int> exitPosition) {
        for (int i = (y - 1) % fieldScheme.info.size(), c = 0; c < 3; ++c, i = (i + 1) % fieldScheme.info.size()){
            for (int j = (x - 1) % fieldScheme.info.size(), k = 0; k < 3; ++k, j = (j + 1) % fieldScheme.info.size()) {
                if (i == y && j == x || fieldScheme.info[i][j] == EXIT) {
                    continue;
                }
                fieldScheme.info[i][j] = FREE;
            }
        }
        if (exitPosition.first == y && exitPosition.second == x) {
            auto xPos = x+1 % fieldScheme.info.size();
            auto yPos = y+1 % fieldScheme.info.size();
            fieldScheme.info[yPos][xPos] = PLAYER;
            return;
        }
        fieldScheme.info[y][x] = PLAYER;
        auto xPos = x % fieldScheme.info.size();
        while (xPos != exitPosition.second) {
            ++xPos %= fieldScheme.info.size();
            if (fieldScheme.info[y][xPos] == EXIT)
                break;
            fieldScheme.info[y][xPos] = FREE;
        }
        auto yPos = (y + 1) % fieldScheme.info.size();
        while (yPos != exitPosition.first) {
            fieldScheme.info[yPos][xPos] = FREE;
            ++yPos %= fieldScheme.info.size();
        }
    }
public:
    void update(FieldScheme &fieldScheme) {
        int positionX = X, positionY = Y;
        if (X >= fieldScheme.info.size() || Y >= fieldScheme.info.size() || X < 0 || Y < 0) {
            Logger::getInstance() << LogMessage{"Wrong position for player. Set default", Logger::Error};
            positionX = 0;
            positionY = 0;
        }
        std::pair<int, int> exitPosition{-1, -1};
        bool isBlockSet = false;
        for (auto row : fieldScheme.info) {
            isBlockSet = std::find(row.begin(), row.end(), BLOCKED) != row.end();
            if (isBlockSet)
                break;
        }
        for (int i = 0; i < fieldScheme.info.size(); ++i) {
            for (int j = 0; j < fieldScheme.info.size(); ++j) {
                if (fieldScheme.info[i][j] == EXIT) {
                    exitPosition = std::make_pair(i, j);
                    break;
                }
            }
            if (exitPosition.first != -1) {
                break;
            }
        }
        if (exitPosition.first == -1 && isBlockSet) {
            setPlayer(fieldScheme, positionX, positionY);
        } else if (isBlockSet) {
            setPlayer(fieldScheme, positionX, positionY, exitPosition);
        } else {
            fieldScheme.info[positionY][positionX] = PLAYER;
        }
    }
};

#endif //GAME_VER2_0_RULEPLAYERPOSITION_H