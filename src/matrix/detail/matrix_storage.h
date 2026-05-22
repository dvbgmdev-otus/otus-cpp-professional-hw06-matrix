#ifndef MATRIX_STORAGE_H
#define MATRIX_STORAGE_H

/**
 * @file matrix_storage.h
 * @brief Хранилище занятых ячеек двумерной разреженной матрицы.
 */

#include <map>

#include "matrix_iterator.h"
#include "matrix_types.h"

/**
 * @class MatrixStorage
 * @ingroup matrix_detail
 * @brief Контейнер занятых ячеек Matrix.
 *
 * MatrixStorage хранит только значения, отличные от DefaultValue. При записи
 * DefaultValue ячейка удаляется из хранилища.
 *
 * @tparam T Тип значения ячейки.
 * @tparam DefaultValue Значение свободной ячейки.
 */
template <typename T, T DefaultValue>
class MatrixStorage {
public:
    /** @brief Итератор по занятым ячейкам. */
    using Iterator = MatrixIterator<T>;

    /**
     * @brief Возвращает значение ячейки.
     * @param row Индекс строки.
     * @param column Индекс столбца.
     * @return Сохранённое значение или DefaultValue, если ячейка свободна.
     */
    T get(MatrixIndex row, MatrixIndex column) const;

    /**
     * @brief Записывает значение ячейки.
     * @param row Индекс строки.
     * @param column Индекс столбца.
     * @param value Новое значение ячейки.
     */
    void set(MatrixIndex row, MatrixIndex column, const T& value);

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
    /** @brief Ассоциативный контейнер занятых ячеек по координатам. */
    std::map<MatrixPosition, T> m_data;
};

#include "matrix_storage.tpp"

#endif  // MATRIX_STORAGE_H
