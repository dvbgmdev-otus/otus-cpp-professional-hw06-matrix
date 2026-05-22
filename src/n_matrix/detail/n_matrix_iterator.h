#ifndef N_MATRIX_ITERATOR_H
#define N_MATRIX_ITERATOR_H

#include <map>
#include <tuple>

#include "n_matrix_types.h"

template <typename T>
class NMatrixIterator {
public:
    using StorageIterator = typename std::map<NMatrixPosition, T>::const_iterator;

    explicit NMatrixIterator(StorageIterator iterator);

    NMatrixIterator& operator++();

    bool operator!=(const NMatrixIterator& other) const;

    std::tuple<NMatrixIndex, NMatrixIndex, T> operator*() const;

private:
    StorageIterator m_iterator;
};

#include "n_matrix_iterator.tpp"

#endif  // N_MATRIX_ITERATOR_H
