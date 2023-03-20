#ifndef GAME_VER2_0_RULEUNEXPLORED_H
#define GAME_VER2_0_RULEUNEXPLORED_H


#include <cstdlib>
#include "../FieldScheme/FieldScheme.h"

template<int... Args>
class RuleUnexplored {};

template<int Count>
class RuleUnexplored<Count> {
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
    void update(FieldScheme& fieldScheme) {
        int count;
        if (Count < 0) {
            Logger::getInstance() << LogMessage{
                    "Attempt to set an invalid number of cells. Set default",
                    Logger::Error};
            count = fieldScheme.info.size();
        } else
            count = Count % fieldScheme.info.size() + 1;
        int x = 0;
        for (int i = 0; i < count; i++) {
            while (x < fieldScheme.info.size()) {
                auto old = fieldScheme.info[i][x];
                fieldScheme.info[i][x] = old == FREE ? UNEXPLORED : old;
                if (old == fieldScheme.info[i][x]) {
                    ++x;
                }
                else {
                    x += 2;
                }
            }
            x = 0;
        }
        int y = 0;
        for (int i = 0; i < count; i++) {
            while (y < fieldScheme.info.size()) {
                auto old = fieldScheme.info[y][i];
                fieldScheme.info[y][i] = old == FREE ? UNEXPLORED : old;
                if (old == fieldScheme.info[y][i]) {
                    ++y;
                }
                else {
                    y += 2;
                }
            }
            y = 0;
        }
    }
};

template<int X, int Y>
class RuleUnexplored<X, Y> {
public:
    void update(FieldScheme& fieldScheme) {
        if (X < 0 || Y < 0 || X >= fieldScheme.info.size() || Y >= fieldScheme.info.size() ||
            fieldScheme.info[Y][X] != FREE) {
            Logger::getInstance() << LogMessage{
                    "Attempt to set the value beyond the boundaries of the field. Failed to set this value",
                    Logger::Error};
            return;
        }
        fieldScheme.info[Y][X] = UNEXPLORED;
    }
};


#endif //GAME_VER2_0_RULEUNEXPLORED_H