#include <climits>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

struct Square {
    int x, y;
    int size;
};

class Solution {
public:
    Solution(int length, int scale = 1) : length_side(length), scale(scale) {}
    void solve() {
        if (length_side % 2 == 0) {
            print_even_partition(length_side);
            return;
        }

        int divisor = find_minimal_divisor(length_side);
        if (divisor != 1) {
            Solution inner_solution{ divisor, length_side / divisor };
            inner_solution.solve();
            return;
        }
        
        scheme = new bool* [length_side];
        for (int i = 0; i < length_side; ++i) {
            scheme[i] = new bool[length_side] {};
        }
        current_answer = new Square[kMaxSize]{};
        answer = new Square[kMaxSize]{};
        int first_square_size = (length_side + 1) / 2;
        add_square(0, 0, first_square_size);
        add_square(0, first_square_size, first_square_size - 1);
        add_square(first_square_size, 0, first_square_size - 1);
        
        backtrack(first_square_size - 1);
        print_odd_partition();
        for (int i = 0; i < length_side; ++i) {
            delete[] scheme[i];
        }
        delete[] scheme;
        delete[] answer;
        delete[] current_answer;
    }

    void print_even_partition(int length) {
        printf("%d\n", 4);
        printf("%d %d %d\n", 1, 1, length / 2);
        printf("%d %d %d\n", 1, 1 + length / 2, length / 2);
        printf("%d %d %d\n", 1 + length / 2, 1, length / 2);
        printf("%d %d %d\n", 1 + length / 2, 1 + length / 2, length / 2);
    }

    void print_odd_partition() {
        printf("%d\n", answer_count);
        for (int i = 0; i < answer_count; ++i) {
            auto& s = answer[i];
            printf("%d %d %d\n", s.x * scale + 1, s.y * scale + 1, s.size * scale);
        }
    }

    int find_minimal_divisor(int divisible) {
        for (int i = 2; i <= int(std::sqrt(divisible)); ++i) {
            if (divisible % i == 0) {
                return i;
            }
        }
        return 1;
    }

    void add_square(int x_coordinate, int y_coordinate, int size) {
        for (int i = y_coordinate; i < y_coordinate + size; ++i) {
            for (int j = x_coordinate; j < x_coordinate + size; ++j) {
                scheme[i][j] = true;
            }
        }
        current_answer[current_answer_count++] = { x_coordinate, y_coordinate, size };
    }

    void backtrack(int height) {
        if (height >= length_side) {
            if (current_answer_count < answer_count) {
                answer_count = current_answer_count;
                std::memcpy(answer, current_answer, sizeof(Square) * answer_count);
            }
            return;
        }
        int free_x_coordinate = find_free_x(height);
        if (free_x_coordinate == -1) {
            backtrack(height + 1);
            return;
        }
        if (current_answer_count >= answer_count || current_answer_count >= kMaxSize) {
            return;
        }
        int size = std::min(length_side - free_x_coordinate, length_side - height);
        for (; size > 0; --size) {
            if (can_place(free_x_coordinate, height, size)) {
                add_square(free_x_coordinate, height, size);
                backtrack(height);
                clear_square(free_x_coordinate, height, size);
            }
        }
    }

    int find_free_x(int current_height) {
        for (int i = 0; i < length_side; i++) {
            if (scheme[current_height][i] == 0) {
                return i;
            }
        }
        return -1;
    }

    bool can_place(int x_coordinate, int y_coordinate, int size) {
        for (int i = y_coordinate; i < y_coordinate + size; ++i) {
            for (int j = x_coordinate; j < x_coordinate+ size; ++j) {
                if (scheme[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    void clear_square(int x_coordinate, int y_coordinate, int size) {
        for (int i = y_coordinate; i < y_coordinate + size; ++i) {
            for (int j = x_coordinate; j < x_coordinate + size; ++j) {
                scheme[i][j] = false;
            }
        }
        --current_answer_count;
    }
private:
    int answer_count = INT_MAX;
    int current_answer_count = 0;
    int length_side;
    static constexpr int kMaxSize = 15;
    Square* current_answer;
    Square* answer;
    bool** scheme;
    int scale;
};

int main() {
    int square_side;
    scanf("%d", &square_side);
    Solution solution{ square_side };
    solution.solve();
    return 0;
}