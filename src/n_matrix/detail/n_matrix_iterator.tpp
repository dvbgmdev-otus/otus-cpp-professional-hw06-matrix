#ifndef N_MATRIX_ITERATOR_TPP
#define N_MATRIX_ITERATOR_TPP

#ifndef N_MATRIX_ITERATOR_H
#include "n_matrix_iterator.h"
#endif  // N_MATRIX_ITERATOR_H

template <typename T, std::size_t Dimension>
NMatrixIterator<T, Dimension>::NMatrixIterator(StorageIterator iterator) : m_iterator(iterator) {}

template <typename T, std::size_t Dimension>
NMatrixIterator<T, Dimension>& NMatrixIterator<T, Dimension>::operator++() {
    ++m_iterator;
    return *this;
}

template <typename T, std::size_t Dimension>
bool NMatrixIterator<T, Dimension>::operator!=(const NMatrixIterator& other) const {
    return m_iterator != other.m_iterator;
}

template <typename T, std::size_t Dimension>
auto NMatrixIterator<T, Dimension>::operator*() const -> ValueType {
    return makeValue(std::make_index_sequence<Dimension>());
}

template <typename T, std::size_t Dimension>
template <std::size_t... Indexes>
auto NMatrixIterator<T, Dimension>::makeValue(std::index_sequence<Indexes...>) const -> ValueType {
    return std::make_tuple(m_iterator->first[Indexes]..., m_iterator->second);
}

#endif  // N_MATRIX_ITERATOR_TPP
