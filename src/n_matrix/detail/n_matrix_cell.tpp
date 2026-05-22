#ifndef N_MATRIX_CELL_TPP
#define N_MATRIX_CELL_TPP

#ifndef N_MATRIX_CELL_H
#include "n_matrix_cell.h"
#endif  // N_MATRIX_CELL_H

template <typename T, T DefaultValue>
NMatrixCell<T, DefaultValue>::NMatrixCell(Storage& storage, NMatrixIndex row, NMatrixIndex column)
    : m_storage(storage), m_row(row), m_column(column) {}

template <typename T, T DefaultValue>
NMatrixCell<T, DefaultValue>& NMatrixCell<T, DefaultValue>::operator=(const T& value) {
    m_storage.set(m_row, m_column, value);
    return *this;
}

template <typename T, T DefaultValue>
NMatrixCell<T, DefaultValue>::operator T() const {
    return m_storage.get(m_row, m_column);
}

#endif  // N_MATRIX_CELL_TPP
