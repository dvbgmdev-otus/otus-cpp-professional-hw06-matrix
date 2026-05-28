/**
 * @file matrix_test.cpp
 * @brief Unit-тесты поведения разреженной матрицы.
 */

#include "matrix.h"

#include <gtest/gtest.h>

#include <tuple>

class MatrixExampleTest : public ::testing::Test {
protected:
    Matrix<int, -1> m_matrix;
};

class MatrixSelfCheckTest : public ::testing::Test {
protected:
    Matrix<int, 0> m_matrix;
};

#if (1)  // 1. Пример из задания

// 1.1 Чтение значения по умолчанию, запись ячейки и обход занятых ячеек.
TEST_F(MatrixExampleTest, TaskExample_WhenCellAssigned_ThenOnlyAssignedCellIsOccupied) {
    ASSERT_EQ(m_matrix.size(), 0U);

    auto value = m_matrix[0][0];
    EXPECT_EQ(value, -1);
    EXPECT_EQ(m_matrix.size(), 0U);

    m_matrix[100][100] = 314;
    EXPECT_EQ(m_matrix[100][100], 314);
    EXPECT_EQ(m_matrix.size(), 1U);

    std::size_t count = 0;
    for (auto cell : m_matrix) {
        MatrixIndex row = 0;
        MatrixIndex column = 0;
        int cell_value = 0;
        std::tie(row, column, cell_value) = cell;

        EXPECT_EQ(row, 100);
        EXPECT_EQ(column, 100);
        EXPECT_EQ(cell_value, 314);
        ++count;
    }

    EXPECT_EQ(count, 1U);
}

#endif

#if (1)  // 2.Самоконтроль

// 2.1 Индексация оператором [] и количество занятых ячеек после заполнения диагоналей.
TEST_F(MatrixSelfCheckTest, Diagonals_WhenFilledByBracketIndexing_ThenOccupiedCellCountIs18) {
    for (MatrixIndex i = 0; i < 10; ++i) {
        m_matrix[i][i] = static_cast<int>(i);
        m_matrix[i][9 - i] = static_cast<int>(9 - i);
    }

    EXPECT_EQ(m_matrix.size(), 18U);
}

#endif  // Самоконтроль

#if (1)  // 3. Опциональные требования

// 3.1 Цепочка присваиваний в одну ячейку.
// 7. Опционально реализовать каноническую форму оператора =, допускающую выражения
// ((matrix[100][100] = 314) = 0) = 217
TEST_F(MatrixSelfCheckTest, CellAssignment_WhenChained_ThenLastValueIsStored) {
    ((m_matrix[100][100] = 314) = 0) = 217;

    EXPECT_EQ(m_matrix[100][100], 217);
    EXPECT_EQ(m_matrix.size(), 1U);
}

#endif  // Опциональные требования
