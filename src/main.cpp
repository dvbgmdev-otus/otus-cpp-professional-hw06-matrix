#include "matrix.h"

#include <iostream>
#include <tuple>

int main() {
    Matrix<int, 0> matrix;

    for (MatrixIndex i = 0; i < 10; ++i) {
        matrix[i][i] = static_cast<int>(i);
        matrix[i][9 - i] = static_cast<int>(9 - i);
    }

    for (MatrixIndex row = 1; row <= 8; ++row) {
        for (MatrixIndex column = 1; column <= 8; ++column) {
            if (column > 1) {
                std::cout << ' ';
            }

            std::cout << matrix[row][column];
        }

        std::cout << '\n';
    }

    std::cout << matrix.size() << '\n';

    for (const auto cell : matrix) {
        MatrixIndex row = 0;
        MatrixIndex column = 0;
        int value = 0;
        std::tie(row, column, value) = cell;

        std::cout << row << ' ' << column << ' ' << value << '\n';
    }

    return 0;
}
