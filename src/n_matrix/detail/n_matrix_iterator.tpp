#ifndef N_MATRIX_ITERATOR_TPP
#define N_MATRIX_ITERATOR_TPP

#ifndef N_MATRIX_ITERATOR_H
#include "n_matrix_iterator.h"
#endif  // N_MATRIX_ITERATOR_H

template <typename T>
NMatrixIterator<T>::NMatrixIterator(StorageIterator iterator)
    : m_iterator(iterator) {}

template <typename T>
NMatrixIterator<T>& NMatrixIterator<T>::operator++() {
    ++m_iterator;
    return *this;
}

template <typename T>
bool NMatrixIterator<T>::operator!=(const NMatrixIterator& other) const {
    return m_iterator != other.m_iterator;
}

template <typename T>
std::tuple<NMatrixIndex, NMatrixIndex, T> NMatrixIterator<T>::operator*() const {
    return std::make_tuple(m_iterator->first.first, m_iterator->first.second, m_iterator->second);
}

#endif  // N_MATRIX_ITERATOR_TPP
