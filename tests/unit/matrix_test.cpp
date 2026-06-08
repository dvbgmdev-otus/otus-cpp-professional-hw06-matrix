/**
 * @file matrix_test.cpp
 * @brief Unit-тесты поведения разреженной матрицы.
 */

#include "matrix.h"

#include <gtest/gtest.h>

class MatrixExampleTest : public ::testing::Test {
protected:
    Matrix<int, -1> m_matrix;
};

class MatrixSelfCheckTest : public ::testing::Test {
protected:
    Matrix<int> m_matrix;
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
    for (const auto& cell : m_matrix) {
        const auto& position = cell.first;
        const auto& cell_value = cell.second;

        EXPECT_EQ(position.first, 100);
        EXPECT_EQ(position.second, 100);
        EXPECT_EQ(cell_value, 314);
        ++count;
    }

    EXPECT_EQ(count, 1U);
}

#endif

#if (1)  // 2. Значение свободной ячейки

// 2.1 Матрица с явно заданным значением свободной ячейки должна возвращать его при чтении пустой ячейки.
TEST(MatrixDefaultValueTest, EmptyCell_WhenCustomDefaultValueIsSet_ThenReturnsCustomDefaultValue) {
    Matrix<int, -1> matrix;

    EXPECT_EQ(matrix[0][0], -1);
    EXPECT_EQ(matrix.size(), 0U);
}

#endif  // Значение свободной ячейки

#if (1)  // 3.Самоконтроль

// 3.1 Индексация оператором [] и количество занятых ячеек после заполнения диагоналей.
TEST_F(MatrixSelfCheckTest, Diagonals_WhenFilledByBracketIndexing_ThenOccupiedCellCountIs18) {
    for (MatrixIndex i = 0; i < 10; ++i) {
        m_matrix[i][i] = static_cast<int>(i);
        m_matrix[i][9 - i] = static_cast<int>(9 - i);
    }

    EXPECT_EQ(m_matrix.size(), 18U);
}

#endif  // Самоконтроль

#if (1)  // 4. Опциональные требования

// 4.1 Цепочка присваиваний в одну ячейку.
// 7. Опционально реализовать каноническую форму оператора =, допускающую выражения
// ((matrix[100][100] = 314) = 0) = 217
TEST_F(MatrixSelfCheckTest, CellAssignment_WhenChained_ThenLastValueIsStored) {
    ((m_matrix[100][100] = 314) = 0) = 217;

    EXPECT_EQ(m_matrix[100][100], 217);
    EXPECT_EQ(m_matrix.size(), 1U);
}

#endif  // Опциональные требования
