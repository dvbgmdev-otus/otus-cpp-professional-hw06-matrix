#ifndef N_MATRIX_ITERATOR_TPP
#define N_MATRIX_ITERATOR_TPP

#ifndef N_MATRIX_ITERATOR_H
#include "n_matrix_iterator.h"
#endif  // N_MATRIX_ITERATOR_H

template <typename T, std::size_t Dimension>
NMatrixIterator<T, Dimension>::NMatrixIterator(StorageIterator iterator)
    : m_iterator(iterator) {}

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
std::tuple<NMatrixIndex, NMatrixIndex, T> NMatrixIterator<T, Dimension>::operator*() const {
    return std::make_tuple(m_iterator->first[0], m_iterator->first[1], m_iterator->second);
}

#endif  // N_MATRIX_ITERATOR_TPP
