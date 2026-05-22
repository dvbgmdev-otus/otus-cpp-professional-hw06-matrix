#ifndef N_MATRIX_ROW_TPP
#define N_MATRIX_ROW_TPP

#ifndef N_MATRIX_ROW_H
#include "n_matrix_row.h"
#endif  // N_MATRIX_ROW_H

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixRow<T, DefaultValue, Dimension>::NMatrixRow(Storage& storage, NMatrixIndex row)
    : m_storage(storage), m_row(row) {}

template <typename T, T DefaultValue, std::size_t Dimension>
auto NMatrixRow<T, DefaultValue, Dimension>::operator[](NMatrixIndex column) && -> Cell {
    return Cell(m_storage, m_row, column);
}

#endif  // N_MATRIX_ROW_TPP
