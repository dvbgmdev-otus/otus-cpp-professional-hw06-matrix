#ifndef N_MATRIX_CELL_H
#define N_MATRIX_CELL_H

/**
 * @file n_matrix_cell.h
 * @brief Proxy-объект ячейки N-мерной разреженной матрицы.
 */

#include "n_matrix_storage.h"

/**
 * @class NMatrixCell
 * @ingroup n_matrix_detail
 * @brief Proxy-объект для чтения и записи одной ячейки NMatrix.
 *
 * NMatrixCell хранит ссылку на хранилище и полную позицию ячейки. Операции
 * чтения и записи делегируются NMatrixStorage.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 * @tparam Dimension Количество измерений матрицы.
 */
template <typename T, T DefaultValue, std::size_t Dimension>
class NMatrixCell {
public:
    /** @brief Тип хранилища занятых ячеек. */
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    /** @brief Тип позиции ячейки. */
    using Position = NMatrixPosition<Dimension>;

    /**
     * @brief Создаёт proxy-объект двумерной ячейки.
     * @param storage Хранилище матрицы.
     * @param row Индекс строки.
     * @param column Индекс столбца.
     */
    NMatrixCell(Storage& storage, NMatrixIndex row, NMatrixIndex column);
    /**
     * @brief Создаёт proxy-объект ячейки с полной N-мерной позицией.
     * @param storage Хранилище матрицы.
     * @param position Позиция ячейки.
     */
    NMatrixCell(Storage& storage, const Position& position);

    /**
     * @brief Записывает значение в ячейку.
     * @param value Новое значение ячейки.
     * @return Ссылка на текущий proxy-объект для поддержки цепочки присваиваний.
     */
    NMatrixCell& operator=(const T& value);

    /**
     * @brief Читает значение ячейки.
     * @return Значение из хранилища или DefaultValue для свободной ячейки.
     */
    operator T() const;

private:
    /** @brief Хранилище матрицы. */
    Storage& m_storage;
    /** @brief Полная позиция ячейки. */
    Position m_position;
};

#include "n_matrix_cell.tpp"

#endif  // N_MATRIX_CELL_H
