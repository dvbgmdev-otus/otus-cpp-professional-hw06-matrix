#ifndef MATRIX_ROW_TPP
#define MATRIX_ROW_TPP

#ifndef MATRIX_ROW_H
#include "matrix_row.h"
#endif  // MATRIX_ROW_H

template <typename T, T DefaultValue>
MatrixRow<T, DefaultValue>::MatrixRow(storage_type& storage, MatrixIndex row)
    : m_storage(storage), m_row(row) {}

template <typename T, T DefaultValue>
MatrixCell<T, DefaultValue> MatrixRow<T, DefaultValue>::operator[](MatrixIndex column) && {
    return MatrixCell<T, DefaultValue>(m_storage, m_row, column);
}

#endif  // MATRIX_ROW_TPP
