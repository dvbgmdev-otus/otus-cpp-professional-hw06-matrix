#ifndef N_MATRIX_TPP
#define N_MATRIX_TPP

#ifndef N_MATRIX_H
#include "n_matrix.h"
#endif  // N_MATRIX_H

template <typename T, T DefaultValue>
NMatrixRow<T, DefaultValue> NMatrix<T, DefaultValue>::operator[](NMatrixIndex row) & {
    return NMatrixRow<T, DefaultValue>(m_storage, row);
}

template <typename T, T DefaultValue>
std::size_t NMatrix<T, DefaultValue>::size() const {
    return m_storage.size();
}

template <typename T, T DefaultValue>
auto NMatrix<T, DefaultValue>::begin() const -> Iterator {
    return m_storage.begin();
}

template <typename T, T DefaultValue>
auto NMatrix<T, DefaultValue>::end() const -> Iterator {
    return m_storage.end();
}

#endif  // N_MATRIX_TPP
