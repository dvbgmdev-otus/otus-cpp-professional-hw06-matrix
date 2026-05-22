#ifndef N_MATRIX_CELL_TPP
#define N_MATRIX_CELL_TPP

#ifndef N_MATRIX_CELL_H
#include "n_matrix_cell.h"
#endif  // N_MATRIX_CELL_H

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixCell<T, DefaultValue, Dimension>::NMatrixCell(Storage& storage, NMatrixIndex row, NMatrixIndex column)
    : m_storage(storage), m_row(row), m_column(column) {}

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixCell<T, DefaultValue, Dimension>& NMatrixCell<T, DefaultValue, Dimension>::operator=(const T& value) {
    NMatrixPosition<Dimension> position = {m_row, m_column};
    m_storage.set(position, value);
    return *this;
}

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixCell<T, DefaultValue, Dimension>::operator T() const {
    NMatrixPosition<Dimension> position = {m_row, m_column};
    return m_storage.get(position);
}

#endif  // N_MATRIX_CELL_TPP
