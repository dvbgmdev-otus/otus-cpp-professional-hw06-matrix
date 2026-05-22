#ifndef N_MATRIX_ROW_TPP
#define N_MATRIX_ROW_TPP

#ifndef N_MATRIX_ROW_H
#include "n_matrix_row.h"
#endif  // N_MATRIX_ROW_H

template <typename T, T DefaultValue>
NMatrixRow<T, DefaultValue>::NMatrixRow(Storage& storage, NMatrixIndex row)
    : m_storage(storage), m_row(row) {}

template <typename T, T DefaultValue>
auto NMatrixRow<T, DefaultValue>::operator[](NMatrixIndex column) && -> Cell {
    return Cell(m_storage, m_row, column);
}

#endif  // N_MATRIX_ROW_TPP
