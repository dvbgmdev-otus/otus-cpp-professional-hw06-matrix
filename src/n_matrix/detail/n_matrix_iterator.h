#ifndef N_MATRIX_ITERATOR_H
#define N_MATRIX_ITERATOR_H

/**
 * @file n_matrix_iterator.h
 * @brief Итератор по занятым ячейкам N-мерной разреженной матрицы.
 */

#include <map>

#include "n_matrix_types.h"

/**
 * @class NMatrixIterator
 * @ingroup n_matrix_detail
 * @brief Итератор по занятым ячейкам NMatrix.
 *
 * NMatrixIterator оборачивает const_iterator внутреннего std::map-хранилища и
 * при разыменовании возвращает ссылку на пару (position, value).
 *
 * @tparam T Тип значения ячейки.
 * @tparam Dimension Количество измерений матрицы.
 */
template <typename T, std::size_t Dimension>
class NMatrixIterator {
public:
    /** @brief Тип итератора внутреннего контейнера хранения. */
    using StorageIterator = typename std::map<NMatrixPosition<Dimension>, T>::const_iterator;
    /** @brief Тип ссылки на занятую ячейку внутреннего контейнера. */
    using Reference = typename StorageIterator::reference;

    /**
     * @brief Создаёт итератор из итератора внутреннего контейнера.
     * @param iterator Итератор внутреннего контейнера.
     */
    explicit NMatrixIterator(const StorageIterator& iterator);

    /**
     * @brief Переходит к следующей занятой ячейке.
     * @return Ссылка на текущий итератор.
     */
    NMatrixIterator& operator++();

    /**
     * @brief Проверяет неравенство двух итераторов.
     * @param other Итератор для сравнения.
     * @return true, если итераторы указывают на разные позиции.
     */
    bool operator!=(const NMatrixIterator& other) const;

    /**
     * @brief Возвращает позицию и значение текущей занятой ячейки.
     * @return Ссылка на пару (position, value).
     */
    Reference operator*() const;

private:
    /** @brief Итератор внутреннего контейнера хранения. */
    StorageIterator m_iterator;
};

#include "n_matrix_iterator.tpp"

#endif  // N_MATRIX_ITERATOR_H
