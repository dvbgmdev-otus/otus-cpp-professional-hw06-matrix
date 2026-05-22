#ifndef N_MATRIX_STORAGE_TPP
#define N_MATRIX_STORAGE_TPP

#ifndef N_MATRIX_STORAGE_H
#include "n_matrix_storage.h"
#endif  // N_MATRIX_STORAGE_H

template <typename T, T DefaultValue>
T NMatrixStorage<T, DefaultValue>::get(NMatrixIndex row, NMatrixIndex column) const {
    const auto it = m_data.find(NMatrixPosition(row, column));
    if (it == m_data.end()) {
        return DefaultValue;
    }

    return it->second;
}

template <typename T, T DefaultValue>
void NMatrixStorage<T, DefaultValue>::set(NMatrixIndex row, NMatrixIndex column, const T& value) {
    const NMatrixPosition position(row, column);
    if (value == DefaultValue) {
        m_data.erase(position);
        return;
    }

    m_data[position] = value;
}

template <typename T, T DefaultValue>
std::size_t NMatrixStorage<T, DefaultValue>::size() const {
    return m_data.size();
}

template <typename T, T DefaultValue>
auto NMatrixStorage<T, DefaultValue>::begin() const -> Iterator {
    return Iterator(m_data.cbegin());
}

template <typename T, T DefaultValue>
auto NMatrixStorage<T, DefaultValue>::end() const -> Iterator {
    return Iterator(m_data.cend());
}

#endif  // N_MATRIX_STORAGE_TPP
