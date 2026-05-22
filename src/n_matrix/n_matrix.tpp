#ifndef N_MATRIX_TPP
#define N_MATRIX_TPP

#ifndef N_MATRIX_H
#include "n_matrix.h"
#endif  // N_MATRIX_H

template <typename T, T DefaultValue, std::size_t Dimension>
auto NMatrix<T, DefaultValue, Dimension>::operator[](NMatrixIndex index) & -> Slice {
    NMatrixPosition<Dimension> position = {};
    position[0] = index;
    return Slice(m_storage, position);
}

template <typename T, T DefaultValue, std::size_t Dimension>
std::size_t NMatrix<T, DefaultValue, Dimension>::size() const {
    return m_storage.size();
}

template <typename T, T DefaultValue, std::size_t Dimension>
auto NMatrix<T, DefaultValue, Dimension>::begin() const -> Iterator {
    return m_storage.begin();
}

template <typename T, T DefaultValue, std::size_t Dimension>
auto NMatrix<T, DefaultValue, Dimension>::end() const -> Iterator {
    return m_storage.end();
}

#endif  // N_MATRIX_TPP
