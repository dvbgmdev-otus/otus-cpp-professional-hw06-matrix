#ifndef N_MATRIX_CELL_TPP
#define N_MATRIX_CELL_TPP

#ifndef N_MATRIX_CELL_H
#include "n_matrix_cell.h"
#endif  // N_MATRIX_CELL_H

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixCell<T, DefaultValue, Dimension>::NMatrixCell(Storage& storage, NMatrixIndex row, NMatrixIndex column)
    : m_storage(storage), m_position{{row, column}} {}

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixCell<T, DefaultValue, Dimension>::NMatrixCell(Storage& storage, const Position& position)
    : m_storage(storage), m_position(position) {}

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixCell<T, DefaultValue, Dimension>& NMatrixCell<T, DefaultValue, Dimension>::operator=(const T& value) {
    m_storage.set(m_position, value);
    return *this;
}

template <typename T, T DefaultValue, std::size_t Dimension>
NMatrixCell<T, DefaultValue, Dimension>::operator T() const {
    return m_storage.get(m_position);
}

#endif  // N_MATRIX_CELL_TPP
