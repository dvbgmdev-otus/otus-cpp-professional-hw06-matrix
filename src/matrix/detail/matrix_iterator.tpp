#ifndef MATRIX_ITERATOR_TPP
#define MATRIX_ITERATOR_TPP

#ifndef MATRIX_ITERATOR_H
#include "matrix_iterator.h"
#endif  // MATRIX_ITERATOR_H

template <typename T>
MatrixIterator<T>::MatrixIterator(const StorageIterator& iterator)
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
auto MatrixIterator<T>::operator*() const -> Reference {
    return *m_iterator;
}

#endif  // MATRIX_ITERATOR_TPP
