#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H

/**
 * @file matrix_row.h
 * @brief Proxy-объект строки двумерной разреженной матрицы.
 */

#include "matrix_cell.h"
#include "matrix_storage.h"

/**
 * @class MatrixRow
 * @ingroup matrix_detail
 * @brief Proxy-объект строки для второго шага индексирования Matrix.
 *
 * MatrixRow создаётся выражением matrix[row] и возвращает MatrixCell при
 * обращении к column через второй operator[].
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 */
template <typename T, T DefaultValue>
class MatrixRow {
public:
    /** @brief Тип хранилища занятых ячеек. */
    using Storage = MatrixStorage<T, DefaultValue>;
    /** @brief Тип proxy-объекта ячейки. */
    using Cell = MatrixCell<T, DefaultValue>;

    /**
     * @brief Создаёт proxy-объект строки.
     * @param storage Хранилище матрицы.
     * @param row Индекс строки.
     */
    MatrixRow(Storage& storage, MatrixIndex row);

    /**
     * @brief Возвращает proxy-объект ячейки в заданном столбце.
     * @param column Индекс столбца.
     * @return Proxy-объект ячейки.
     */
    Cell operator[](MatrixIndex column) &&;
    Cell operator[](MatrixIndex column) & = delete;

private:
    /** @brief Хранилище матрицы. */
    Storage& m_storage;
    /** @brief Индекс строки. */
    MatrixIndex m_row;
};

#include "matrix_row.tpp"

#endif  // MATRIX_ROW_H
