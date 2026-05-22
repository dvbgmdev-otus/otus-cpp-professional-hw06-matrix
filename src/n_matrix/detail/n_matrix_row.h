#ifndef N_MATRIX_ROW_H
#define N_MATRIX_ROW_H

/**
 * @file n_matrix_row.h
 * @brief Proxy-объект строки двумерного сценария N-мерной матрицы.
 */

#include "n_matrix_cell.h"
#include "n_matrix_storage.h"

/**
 * @class NMatrixRow
 * @ingroup n_matrix_detail
 * @brief Proxy-объект строки для двумерного индексирования NMatrix.
 *
 * Класс используется для совместимости с двумерной формой индексирования и
 * возвращает NMatrixCell при обращении ко второму индексу.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 * @tparam Dimension Количество измерений матрицы.
 */
template <typename T, T DefaultValue, std::size_t Dimension>
class NMatrixRow {
public:
    /** @brief Тип хранилища занятых ячеек. */
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    /** @brief Тип proxy-объекта ячейки. */
    using Cell = NMatrixCell<T, DefaultValue, Dimension>;

    /**
     * @brief Создаёт proxy-объект строки.
     * @param storage Хранилище матрицы.
     * @param row Индекс строки.
     */
    NMatrixRow(Storage& storage, NMatrixIndex row);

    /**
     * @brief Возвращает proxy-объект ячейки в заданном столбце.
     * @param column Индекс столбца.
     * @return Proxy-объект ячейки.
     */
    Cell operator[](NMatrixIndex column) &&;
    Cell operator[](NMatrixIndex column) & = delete;

private:
    /** @brief Хранилище матрицы. */
    Storage& m_storage;
    /** @brief Индекс строки. */
    NMatrixIndex m_row;
};

#include "n_matrix_row.tpp"

#endif  // N_MATRIX_ROW_H
