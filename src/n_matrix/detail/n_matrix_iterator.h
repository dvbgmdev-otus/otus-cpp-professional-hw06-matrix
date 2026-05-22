#ifndef N_MATRIX_ITERATOR_H
#define N_MATRIX_ITERATOR_H

/**
 * @file n_matrix_iterator.h
 * @brief Итератор по занятым ячейкам N-мерной разреженной матрицы.
 */

#include <map>
#include <tuple>
#include <utility>

#include "n_matrix_types.h"

/**
 * @class NMatrixIterator
 * @ingroup n_matrix_detail
 * @brief Итератор, возвращающий координаты и значение занятой ячейки NMatrix.
 *
 * NMatrixIterator оборачивает const_iterator внутреннего std::map-хранилища и
 * при разыменовании возвращает tuple вида (index0, index1, ..., value).
 *
 * @tparam T Тип значения ячейки.
 * @tparam Dimension Количество измерений матрицы.
 */
template <typename T, std::size_t Dimension>
class NMatrixIterator {
private:
    /** @brief Тип одной координаты в результирующем кортеже. */
    template <std::size_t>
    using CoordinateType = NMatrixIndex;

    /** @brief Вспомогательный шаблон для построения типа значения итератора. */
    template <typename Sequence>
    struct ValueTypeBuilder;

    /** @brief Специализация построителя tuple по индексной последовательности. */
    template <std::size_t... Indexes>
    struct ValueTypeBuilder<std::index_sequence<Indexes...>> {
        /** @brief Тип tuple, содержащего все координаты и значение ячейки. */
        using Type = std::tuple<CoordinateType<Indexes>..., T>;
    };

public:
    /** @brief Тип итератора внутреннего контейнера хранения. */
    using StorageIterator = typename std::map<NMatrixPosition<Dimension>, T>::const_iterator;
    /** @brief Тип значения, возвращаемого при разыменовании итератора. */
    using ValueType = typename ValueTypeBuilder<std::make_index_sequence<Dimension>>::Type;

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
     * @brief Возвращает координаты и значение текущей занятой ячейки.
     * @return Кортеж (index0, index1, ..., value).
     */
    ValueType operator*() const;

private:
    /**
     * @brief Формирует значение итератора по индексной последовательности.
     * @return Кортеж координат и значения.
     */
    template <std::size_t... Indexes>
    ValueType makeValue(std::index_sequence<Indexes...>) const;

    /** @brief Итератор внутреннего контейнера хранения. */
    StorageIterator m_iterator;
};

#include "n_matrix_iterator.tpp"

#endif  // N_MATRIX_ITERATOR_H
