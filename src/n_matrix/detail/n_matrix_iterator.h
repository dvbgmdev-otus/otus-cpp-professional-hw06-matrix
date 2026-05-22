#ifndef N_MATRIX_ITERATOR_H
#define N_MATRIX_ITERATOR_H

#include <map>
#include <tuple>
#include <utility>

#include "n_matrix_types.h"

template <typename T, std::size_t Dimension>
class NMatrixIterator {
private:
    template <std::size_t>
    using CoordinateType = NMatrixIndex;

    template <typename Sequence>
    struct ValueTypeBuilder;

    template <std::size_t... Indexes>
    struct ValueTypeBuilder<std::index_sequence<Indexes...>> {
        using Type = std::tuple<CoordinateType<Indexes>..., T>;
    };

public:
    using StorageIterator = typename std::map<NMatrixPosition<Dimension>, T>::const_iterator;
    using ValueType = typename ValueTypeBuilder<std::make_index_sequence<Dimension>>::Type;

    explicit NMatrixIterator(StorageIterator iterator);

    NMatrixIterator& operator++();

    bool operator!=(const NMatrixIterator& other) const;

    ValueType operator*() const;

private:
    template <std::size_t... Indexes>
    ValueType makeValue(std::index_sequence<Indexes...>) const;

    StorageIterator m_iterator;
};

#include "n_matrix_iterator.tpp"

#endif  // N_MATRIX_ITERATOR_H
