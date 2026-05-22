#ifndef MATRIX_ITERATOR_H
#define MATRIX_ITERATOR_H

/**
 * @file matrix_iterator.h
 * @brief Итератор по занятым ячейкам двумерной разреженной матрицы.
 */

#include <map>
#include <tuple>

#include "matrix_types.h"

/**
 * @class MatrixIterator
 * @ingroup matrix_detail
 * @brief Итератор, возвращающий координаты и значение занятой ячейки Matrix.
 *
 * MatrixIterator оборачивает const_iterator внутреннего std::map-хранилища и
 * при разыменовании возвращает tuple вида (row, column, value).
 *
 * @tparam T Тип значения ячейки.
 */
template <typename T>
class MatrixIterator {
public:
    /** @brief Тип итератора внутреннего контейнера хранения. */
    using StorageIterator = typename std::map<MatrixPosition, T>::const_iterator;

    /**
     * @brief Создаёт итератор из итератора внутреннего контейнера.
     * @param iterator Итератор внутреннего контейнера.
     */
    explicit MatrixIterator(const StorageIterator& iterator);

    /**
     * @brief Переходит к следующей занятой ячейке.
     * @return Ссылка на текущий итератор.
     */
    MatrixIterator& operator++();

    /**
     * @brief Проверяет неравенство двух итераторов.
     * @param other Итератор для сравнения.
     * @return true, если итераторы указывают на разные позиции.
     */
    bool operator!=(const MatrixIterator& other) const;

    /**
     * @brief Возвращает координаты и значение текущей занятой ячейки.
     * @return Кортеж (row, column, value).
     */
    std::tuple<MatrixIndex, MatrixIndex, T> operator*() const;

private:
    /** @brief Итератор внутреннего контейнера хранения. */
    StorageIterator m_iterator;
};

#include "matrix_iterator.tpp"

#endif  // MATRIX_ITERATOR_H
