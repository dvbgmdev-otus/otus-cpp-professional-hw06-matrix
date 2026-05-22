/**
 * @file n_matrix_test.cpp
 * @brief Unit-тесты поведения N-мерной разреженной матрицы.
 */

#include "n_matrix.h"

#include <gtest/gtest.h>

#include <type_traits>
#include <tuple>
#include <utility>
#include <vector>

template <typename...>
struct Void {
    using Type = void;
};

template <typename... Args>
using VoidT = typename Void<Args...>::Type;

template <typename Matrix, typename = void>
struct HasThreeDimensionalIndexing : std::false_type {
};

template <typename Matrix>
struct HasThreeDimensionalIndexing<
    Matrix,
    VoidT<decltype(std::declval<Matrix&>()[0][0][0])>> : std::true_type {
};

class NMatrixApplicationScenarioTest : public ::testing::Test {
protected:
    NMatrix<int, 0> m_matrix;
};

#if (1)  // 1. Сценарий приложения

// 1.1 Заполнение диагоналей, проверка фрагмента, размера и занятых ячеек.
TEST_F(NMatrixApplicationScenarioTest, MainScenario_WhenDiagonalsFilled_ThenMatrixStateMatchesTask) {
    // 1 Заполнение главной диагонали значениями от 0 до 9.
    for (NMatrixIndex i = 0; i < 10; ++i) {
        m_matrix[i][i] = static_cast<int>(i);
    }

    // 2 Заполнение второстепенной диагонали значениями от 9 до 0.
    for (NMatrixIndex i = 0; i < 10; ++i) {
        m_matrix[i][9 - i] = static_cast<int>(9 - i);
    }

    // 3 Проверка фрагмента матрицы от [1,1] до [8,8].
    const std::vector<std::vector<int>> expected_fragment = {
        {1, 0, 0, 0, 0, 0, 0, 8},
        {0, 2, 0, 0, 0, 0, 7, 0},
        {0, 0, 3, 0, 0, 6, 0, 0},
        {0, 0, 0, 4, 5, 0, 0, 0},
        {0, 0, 0, 4, 5, 0, 0, 0},
        {0, 0, 3, 0, 0, 6, 0, 0},
        {0, 2, 0, 0, 0, 0, 7, 0},
        {1, 0, 0, 0, 0, 0, 0, 8},
    };

    for (NMatrixIndex row = 1; row <= 8; ++row) {
        for (NMatrixIndex column = 1; column <= 8; ++column) {
            EXPECT_EQ(m_matrix[row][column], expected_fragment[row - 1][column - 1]);
        }
    }

    // 4 Проверка количества занятых ячеек.
    EXPECT_EQ(m_matrix.size(), 18U);

    // 5 Сбор всех занятых ячеек вместе с позициями.
    std::vector<std::tuple<int, int, int>> occupied_cells;
    for (auto cell : m_matrix) {
        int row = 0;
        int column = 0;
        int cell_value = 0;
        std::tie(row, column, cell_value) = cell;

        occupied_cells.push_back(std::make_tuple(row, column, cell_value));
    }

    // 6 Проверка списка занятых ячеек.
    const std::vector<std::tuple<int, int, int>> expected_occupied_cells = {
        std::make_tuple(0, 9, 9),
        std::make_tuple(1, 1, 1),
        std::make_tuple(1, 8, 8),
        std::make_tuple(2, 2, 2),
        std::make_tuple(2, 7, 7),
        std::make_tuple(3, 3, 3),
        std::make_tuple(3, 6, 6),
        std::make_tuple(4, 4, 4),
        std::make_tuple(4, 5, 5),
        std::make_tuple(5, 4, 4),
        std::make_tuple(5, 5, 5),
        std::make_tuple(6, 3, 3),
        std::make_tuple(6, 6, 6),
        std::make_tuple(7, 2, 2),
        std::make_tuple(7, 7, 7),
        std::make_tuple(8, 1, 1),
        std::make_tuple(8, 8, 8),
        std::make_tuple(9, 9, 9),
    };

    EXPECT_EQ(occupied_cells, expected_occupied_cells);
}

#endif  // Сценарий приложения

#if (1)  // 2. Трехмерная индексация

// 2.1 Матрица размерности 3 должна поддерживать обращение matrix[x][y][z].
TEST(NMatrixThreeDimensionalTest, Indexing_WhenDimensionIs3_ThenThreeIndexesAreSupported) {
    EXPECT_TRUE((HasThreeDimensionalIndexing<NMatrix<int, 0, 3>>::value));
}

#endif  // Трехмерная индексация
