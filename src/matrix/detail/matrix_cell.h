#ifndef MATRIX_CELL_H
#define MATRIX_CELL_H

/**
 * @file matrix_cell.h
 * @brief Proxy-объект ячейки двумерной разреженной матрицы.
 */

#include "matrix_storage.h"

/**
 * @class MatrixCell
 * @ingroup matrix_detail
 * @brief Proxy-объект для чтения и записи одной ячейки Matrix.
 *
 * MatrixCell не хранит значение самостоятельно. Он содержит ссылку на
 * хранилище и координаты ячейки, а операции чтения и записи делегирует
 * MatrixStorage.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 */
template <typename T, T DefaultValue>
class MatrixCell {
public:
    /** @brief Тип хранилища занятых ячеек. */
    using Storage = MatrixStorage<T, DefaultValue>;

    /**
     * @brief Создаёт proxy-объект для ячейки с заданными координатами.
     * @param storage Хранилище матрицы.
     * @param row Индекс строки.
     * @param column Индекс столбца.
     */
    MatrixCell(Storage& storage, MatrixIndex row, MatrixIndex column);

    /**
     * @brief Записывает значение в ячейку.
     * @param value Новое значение ячейки.
     * @return Ссылка на текущий proxy-объект для поддержки цепочки присваиваний.
     */
    MatrixCell& operator=(const T& value);

    /**
     * @brief Читает значение ячейки.
     * @return Значение из хранилища или DefaultValue для свободной ячейки.
     */
    operator T() const;

private:
    /** @brief Хранилище матрицы. */
    Storage& m_storage;
    /** @brief Индекс строки. */
    MatrixIndex m_row;
    /** @brief Индекс столбца. */
    MatrixIndex m_column;
};

#include "matrix_cell.tpp"

#endif  // MATRIX_CELL_H
