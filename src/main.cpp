#include <iostream>

#include "matrix.h"

int main() {
    // 1. При запуске программы необходимо создать матрицу с пустым значением 0, заполнить главную
    // диагональ матрицы (от [0,0] до [9,9]) значениями от 0 до 9.
    Matrix<int> matrix;
    for (MatrixIndex i = 0; i < 10; ++i) {
        matrix[i][i] = static_cast<int>(i);
    }

    // 2. Заполнить второстепенную диагональ матрицы (от [0,9] до [9,0]) значениями от 9 до 0.
    for (MatrixIndex i = 0; i < 10; ++i) {
        matrix[i][9 - i] = static_cast<int>(9 - i);
    }

    // 3. Необходимо вывести фрагмент матрицы от [1,1] до [8,8]. Между столбцами пробел. Каждая строка матрицы на новой строке консоли.
    for (MatrixIndex row = 1; row <= 8; ++row) {
        for (MatrixIndex column = 1; column <= 8; ++column) {
            if (column > 1) {
                std::cout << ' ';
            }

            std::cout << matrix[row][column];
        }

        std::cout << '\n';
    }

    // 4. Вывести количество занятых ячеек.
    std::cout << matrix.size() << '\n';

    // 5. Вывести все занятые ячейки вместе со своими позициями.
    for (const auto& cell : matrix) {
        const auto& position = cell.first;
        const auto& cell_value = cell.second;

        std::cout << "Cell(" << position.first << "," << position.second << ") = " << cell_value << '\n';
    }

    return 0;
}
