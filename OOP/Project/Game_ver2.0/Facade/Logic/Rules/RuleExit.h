#ifndef GAME_VER2_0_RULEEXIT_H
#define GAME_VER2_0_RULEEXIT_H

#include <iostream>
#include "../FieldScheme/FieldScheme.h"

template<int X, int Y>
class RuleExit {
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
    void setExit(FieldScheme& fieldScheme, int x, int y) {
        fieldScheme.info[y][x] = EXIT;
        for (int i = (y - 1) % fieldScheme.info.size(), c = 0; c < 3; ++c, i = (i + 1) % fieldScheme.info.size()){
            for (int j = (x - 1) % fieldScheme.info.size(), k = 0; k < 3; ++k, j = (j + 1) % fieldScheme.info.size()) {
                if (i == y && j == x) {
                    continue;
                }
                fieldScheme.info[i][j] = FREE;
            }
        }
    }
    void setExit(FieldScheme& fieldScheme, int x, int y, std::pair<int, int> position) {
        for (int i = (y - 1) % fieldScheme.info.size(), c = 0; c < 3; ++c, i = (i + 1) % fieldScheme.info.size()){
            for (int j = (x - 1) % fieldScheme.info.size(), k = 0; k < 3; ++k, j = (j + 1) % fieldScheme.info.size()) {
                if (i == y && j == x || fieldScheme.info[i][j] == PLAYER) {
                    continue;
                }
                fieldScheme.info[i][j] = FREE;
            }
        }
        if (position.first == y && position.second == x) {
            auto xPos = x+1 % fieldScheme.info.size();
            auto yPos = y+1 % fieldScheme.info.size();
            fieldScheme.info[yPos][xPos] = EXIT;
            return;
        }
        fieldScheme.info[y][x] = EXIT;
        auto xPos = x % fieldScheme.info.size();
        while (xPos != position.second) {
            ++xPos %= fieldScheme.info.size();
            if (fieldScheme.info[y][xPos] == EXIT)
                break;
            fieldScheme.info[y][xPos] = FREE;
        }
        auto yPos = (y + 1) % fieldScheme.info.size();
        while (yPos != position.first) {
            fieldScheme.info[yPos][x] = FREE;
            ++yPos %= fieldScheme.info.size();
        }
    }
public:
    void update(FieldScheme& fieldScheme) {
        int positionX = X, positionY = Y;
        if (X >= fieldScheme.info.size() || Y >= fieldScheme.info.size() || X < 0 || Y < 0) {
            Logger::getInstance() << LogMessage{"Wrong position for exit. Set default", Logger::Error};
            positionX = fieldScheme.info.size() - 1;
            positionY = positionX;
        }
        std::pair<int, int> playerPosition{-1, -1};
        bool isBlockSet = false;
        for (auto row : fieldScheme.info) {
            isBlockSet = std::find(row.begin(), row.end(), BLOCKED) != row.end();
            if (isBlockSet)
                break;
        }
        for (int i = 0; i < fieldScheme.info.size(); ++i) {
            for (int j = 0; j < fieldScheme.info.size(); ++j) {
                if (fieldScheme.info[i][j] == PLAYER) {
                    playerPosition = std::make_pair(i, j);
                    break;
                }
            }
            if (playerPosition.first != -1) {
                break;
            }
        }
        if (playerPosition.first == -1 && isBlockSet) {
            setExit(fieldScheme, positionX, positionY);
        } else if (isBlockSet) {
            setExit(fieldScheme, positionX, positionY, playerPosition);
        } else {
            fieldScheme.info[positionY][positionX] = EXIT;
        }
    }
};


#endif //GAME_VER2_0_RULEEXIT_H