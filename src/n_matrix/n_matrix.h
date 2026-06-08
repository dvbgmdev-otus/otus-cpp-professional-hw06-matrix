#ifndef N_MATRIX_H
#define N_MATRIX_H

/**
 * @file n_matrix.h
 * @brief Публичный интерфейс N-мерной разреженной матрицы.
 */

#include "n_matrix_slice.h"
#include "n_matrix_storage.h"

/**
 * @class NMatrix
 * @ingroup n_matrix
 * @brief Бесконечная N-мерная разреженная матрица.
 *
 * NMatrix хранит только занятые ячейки, то есть ячейки, которым присвоено
 * значение, отличное от значения по умолчанию. Чтение свободной ячейки
 * возвращает DefaultValue.
 *
 * Индексирование выполняется цепочкой operator[] длиной Dimension:
 *
 * @code{.cpp}
 * NMatrix<int, 0, 3> matrix;
 * matrix[1][2][3] = 42;
 * @endcode
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 * @tparam Dimension Количество измерений матрицы.
 */
template <typename T, T DefaultValue = T{}, std::size_t Dimension = 2>
class NMatrix {
public:
    /** @brief Итератор по занятым ячейкам матрицы. */
    using Iterator = typename NMatrixStorage<T, DefaultValue, Dimension>::Iterator;
    /** @brief Proxy-объект первого уровня индексирования. */
    using Slice = NMatrixSlice<T, DefaultValue, Dimension, 1>;

    /**
     * @brief Возвращает proxy-объект для продолжения N-мерного индексирования.
     * @param index Индекс первого измерения.
     * @return Proxy-объект следующего уровня индексирования.
     */
    Slice operator[](NMatrixIndex index) &;

    /**
     * @brief Возвращает количество занятых ячеек.
     * @return Количество ячеек, хранящихся в матрице.
     */
    std::size_t size() const;

    /**
     * @brief Возвращает итератор на первую занятую ячейку.
     * @return Итератор начала диапазона занятых ячеек.
     */
    Iterator begin() const;

    /**
     * @brief Возвращает итератор за последней занятой ячейкой.
     * @return Итератор конца диапазона занятых ячеек.
     */
    Iterator end() const;

private:
    /** @brief Хранилище занятых ячеек матрицы. */
    NMatrixStorage<T, DefaultValue, Dimension> m_storage;
};

#include "n_matrix.tpp"

#endif  // N_MATRIX_H
