#ifndef MATRIX_ITERATOR_TPP
#define MATRIX_ITERATOR_TPP

#ifndef MATRIX_ITERATOR_H
#include "matrix_iterator.h"
#endif  // MATRIX_ITERATOR_H

template <typename T>
MatrixIterator<T>::MatrixIterator(StorageIterator iterator)
    : m_iterator(iterator) {}

template <typename T>
MatrixIterator<T>& MatrixIterator<T>::operator++() {
    ++m_iterator;
    return *this;
}

template <typename T>
bool MatrixIterator<T>::operator!=(const MatrixIterator& other) const {
    return m_iterator != other.m_iterator;
}

template <typename T>
std::tuple<MatrixIndex, MatrixIndex, T> MatrixIterator<T>::operator*() const {
    return std::make_tuple(m_iterator->first.first, m_iterator->first.second, m_iterator->second);
}

#endif  // MATRIX_ITERATOR_TPP
