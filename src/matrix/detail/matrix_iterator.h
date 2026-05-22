#ifndef MATRIX_ITERATOR_H
#define MATRIX_ITERATOR_H

#include <map>
#include <tuple>

#include "matrix_types.h"

template <typename T>
class MatrixIterator {
public:
    using StorageIterator = typename std::map<MatrixPosition, T>::const_iterator;

    explicit MatrixIterator(StorageIterator iterator);

    MatrixIterator& operator++();

    bool operator!=(const MatrixIterator& other) const;

    std::tuple<MatrixIndex, MatrixIndex, T> operator*() const;

private:
    StorageIterator m_iterator;
};

#include "matrix_iterator.tpp"

#endif  // MATRIX_ITERATOR_H
