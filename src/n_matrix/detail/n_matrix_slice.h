#ifndef N_MATRIX_SLICE_H
#define N_MATRIX_SLICE_H

/**
 * @file n_matrix_slice.h
 * @brief Proxy-объекты промежуточных уровней индексирования NMatrix.
 */

#include <cstddef>
#include <type_traits>

#include "n_matrix_cell.h"
#include "n_matrix_storage.h"
#include "n_matrix_types.h"

template <
    typename T,
    T DefaultValue,
    std::size_t Dimension,
    std::size_t Depth,
    bool IsLast = (Depth + 1 == Dimension)>
class NMatrixSlice;

/**
 * @class NMatrixSlice
 * @ingroup n_matrix_detail
 * @brief Proxy-объект промежуточного уровня индексирования NMatrix.
 *
 * На каждом шаге индексирования NMatrixSlice запоминает очередную координату
 * и возвращает proxy следующего уровня. На последнем уровне специализация
 * NMatrixSlice возвращает NMatrixCell.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 * @tparam Dimension Количество измерений матрицы.
 * @tparam Depth Текущая глубина индексирования.
 * @tparam IsLast Технический параметр для выбора специализации.
 */
template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth, bool IsLast>
class NMatrixSlice {
public:
    /** @brief Тип хранилища занятых ячеек. */
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    /** @brief Тип позиции ячейки. */
    using Position = NMatrixPosition<Dimension>;
    /** @brief Тип proxy-объекта следующего уровня индексирования. */
    using Slice = NMatrixSlice<T, DefaultValue, Dimension, Depth + 1>;

    /**
     * @brief Создаёт proxy-объект текущего уровня индексирования.
     * @param storage Хранилище матрицы.
     * @param position Частично заполненная позиция.
     */
    NMatrixSlice(Storage& storage, const Position& position);

    /**
     * @brief Запоминает индекс текущего измерения и возвращает следующий proxy.
     * @param index Индекс текущего измерения.
     * @return Proxy-объект следующего уровня индексирования.
     */
    Slice operator[](NMatrixIndex index) &&;
    Slice operator[](NMatrixIndex index) & = delete;

private:
    /** @brief Хранилище матрицы. */
    Storage& m_storage;
    /** @brief Частично заполненная позиция ячейки. */
    Position m_position;
};

/**
 * @ingroup n_matrix_detail
 * @brief Proxy-объект последнего уровня индексирования NMatrix.
 *
 * Специализация используется перед последним индексом. После получения
 * последней координаты она возвращает NMatrixCell с полной позицией ячейки.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 * @tparam Dimension Количество измерений матрицы.
 */
/** @cond */
template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth>
class NMatrixSlice<
    T,
    DefaultValue,
    Dimension,
    Depth,
    true> {
public:
    /** @brief Тип хранилища занятых ячеек. */
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    /** @brief Тип позиции ячейки. */
    using Position = NMatrixPosition<Dimension>;
    /** @brief Тип proxy-объекта ячейки. */
    using Cell = NMatrixCell<T, DefaultValue, Dimension>;

    /**
     * @brief Создаёт proxy-объект последнего уровня индексирования.
     * @param storage Хранилище матрицы.
     * @param position Частично заполненная позиция.
     */
    NMatrixSlice(Storage& storage, const Position& position);

    /**
     * @brief Запоминает последний индекс и возвращает proxy-объект ячейки.
     * @param index Индекс последнего измерения.
     * @return Proxy-объект ячейки.
     */
    Cell operator[](NMatrixIndex index) &&;
    Cell operator[](NMatrixIndex index) & = delete;

private:
    /** @brief Хранилище матрицы. */
    Storage& m_storage;
    /** @brief Частично заполненная позиция ячейки. */
    Position m_position;
};
/** @endcond */

#include "n_matrix_slice.tpp"

#endif  // N_MATRIX_SLICE_H
