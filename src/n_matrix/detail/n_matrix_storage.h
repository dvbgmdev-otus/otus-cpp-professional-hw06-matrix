#ifndef N_MATRIX_STORAGE_H
#define N_MATRIX_STORAGE_H

/**
 * @file n_matrix_storage.h
 * @brief Хранилище занятых ячеек N-мерной разреженной матрицы.
 */

#include <map>

#include "n_matrix_iterator.h"
#include "n_matrix_types.h"

/**
 * @class NMatrixStorage
 * @ingroup n_matrix_detail
 * @brief Контейнер занятых ячеек NMatrix.
 *
 * NMatrixStorage хранит только значения, отличные от DefaultValue. При записи
 * DefaultValue позиция удаляется из хранилища.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 * @tparam Dimension Количество измерений матрицы.
 */
template <typename T, T DefaultValue, std::size_t Dimension>
class NMatrixStorage {
public:
    /** @brief Итератор по занятым ячейкам. */
    using Iterator = NMatrixIterator<T, Dimension>;

    /**
     * @brief Возвращает значение ячейки.
     * @param position Позиция ячейки.
     * @return Сохранённое значение или DefaultValue, если ячейка свободна.
     */
    T get(const NMatrixPosition<Dimension>& position) const;

    /**
     * @brief Записывает значение ячейки.
     * @param position Позиция ячейки.
     * @param value Новое значение ячейки.
     */
    void set(const NMatrixPosition<Dimension>& position, const T& value);

    /**
     * @brief Возвращает количество занятых ячеек.
     * @return Размер внутреннего хранилища.
     */
    std::size_t size() const;

    /**
     * @brief Возвращает итератор на первую занятую ячейку.
     * @return Итератор начала диапазона.
     */
    Iterator begin() const;

    /**
     * @brief Возвращает итератор за последней занятой ячейкой.
     * @return Итератор конца диапазона.
     */
    Iterator end() const;

private:
    /** @brief Ассоциативный контейнер занятых ячеек по N-мерным позициям. */
    std::map<NMatrixPosition<Dimension>, T> m_data;
};

#include "n_matrix_storage.tpp"

#endif  // N_MATRIX_STORAGE_H
