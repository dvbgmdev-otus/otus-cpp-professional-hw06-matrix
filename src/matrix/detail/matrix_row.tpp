#ifndef MATRIX_ROW_TPP
#define MATRIX_ROW_TPP

#ifndef MATRIX_ROW_H
#include "matrix_row.h"
#endif  // MATRIX_ROW_H

template <typename T, T DefaultValue>
MatrixRow<T, DefaultValue>::MatrixRow(Storage& storage, MatrixIndex row)
    : m_storage(storage), m_row(row) {}

template <typename T, T DefaultValue>
auto MatrixRow<T, DefaultValue>::operator[](MatrixIndex column) && -> Cell {
    return Cell(m_storage, m_row, column);
}

#endif  // MATRIX_ROW_TPP
