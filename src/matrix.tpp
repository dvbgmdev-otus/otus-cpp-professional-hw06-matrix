#ifndef MATRIX_TPP
#define MATRIX_TPP

#ifndef MATRIX_H
#include "matrix.h"
#endif  // MATRIX_H

template <typename T, T DefaultValue>
MatrixRow<T, DefaultValue> Matrix<T, DefaultValue>::operator[](index_type row) & {
    return MatrixRow<T, DefaultValue>(m_storage, row);
}

template <typename T, T DefaultValue>
std::size_t Matrix<T, DefaultValue>::size() const {
    return m_storage.size();
}

#endif  // MATRIX_TPP
