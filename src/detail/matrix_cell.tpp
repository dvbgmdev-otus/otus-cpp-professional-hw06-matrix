#ifndef MATRIX_CELL_TPP
#define MATRIX_CELL_TPP

#ifndef MATRIX_CELL_H
#include "matrix_cell.h"
#endif  // MATRIX_CELL_H

template <typename T, T DefaultValue>
MatrixCell<T, DefaultValue>::MatrixCell(storage_type& storage, MatrixIndex row, MatrixIndex column)
    : m_storage(storage), m_row(row), m_column(column) {}

template <typename T, T DefaultValue>
MatrixCell<T, DefaultValue>& MatrixCell<T, DefaultValue>::operator=(const T& value) {
    m_storage.set(m_row, m_column, value);
    return *this;
}

template <typename T, T DefaultValue>
MatrixCell<T, DefaultValue>::operator T() const {
    return m_storage.get(m_row, m_column);
}

#endif  // MATRIX_CELL_TPP
