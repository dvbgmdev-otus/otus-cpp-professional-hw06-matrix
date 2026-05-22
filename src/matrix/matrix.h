#ifndef MATRIX_H
#define MATRIX_H

/**
 * @file matrix.h
 * @brief Публичный интерфейс двумерной разреженной матрицы.
 */

#include "matrix_row.h"
#include "matrix_storage.h"

/**
 * @class Matrix
 * @ingroup matrix
 * @brief Бесконечная двумерная разреженная матрица.
 *
 * Matrix хранит только занятые ячейки, то есть ячейки, которым присвоено
 * значение, отличное от значения по умолчанию. Чтение свободной ячейки
 * возвращает DefaultValue.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 */
template <typename T, T DefaultValue>
class Matrix {
public:
    /** @brief Итератор по занятым ячейкам матрицы. */
    using Iterator = typename MatrixStorage<T, DefaultValue>::Iterator;

    /**
     * @brief Возвращает proxy-объект строки для индексирования matrix[row][column].
     * @param row Индекс строки.
     * @return Proxy-объект строки.
     */
    MatrixRow<T, DefaultValue> operator[](MatrixIndex row) &;

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
    MatrixStorage<T, DefaultValue> m_storage;
};

#include "matrix.tpp"

#endif  // MATRIX_H
