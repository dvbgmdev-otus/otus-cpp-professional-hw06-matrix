#ifndef N_MATRIX_STORAGE_TPP
#define N_MATRIX_STORAGE_TPP

#ifndef N_MATRIX_STORAGE_H
#include "n_matrix_storage.h"
#endif  // N_MATRIX_STORAGE_H

template <typename T, T DefaultValue, std::size_t Dimension>
T NMatrixStorage<T, DefaultValue, Dimension>::get(NMatrixPosition<Dimension>& position) const {
    const auto it = m_data.find(position);
    if (it == m_data.end()) {
        return DefaultValue;
    }

    return it->second;
}

template <typename T, T DefaultValue, std::size_t Dimension>
void NMatrixStorage<T, DefaultValue, Dimension>::set(NMatrixPosition<Dimension>& position, const T& value) {
    if (value == DefaultValue) {
        m_data.erase(position);
        return;
    }

    m_data[position] = value;
}

template <typename T, T DefaultValue, std::size_t Dimension>
std::size_t NMatrixStorage<T, DefaultValue, Dimension>::size() const {
    return m_data.size();
}

template <typename T, T DefaultValue, std::size_t Dimension>
auto NMatrixStorage<T, DefaultValue, Dimension>::begin() const -> Iterator {
    return Iterator(m_data.cbegin());
}

template <typename T, T DefaultValue, std::size_t Dimension>
auto NMatrixStorage<T, DefaultValue, Dimension>::end() const -> Iterator {
    return Iterator(m_data.cend());
}

#endif  // N_MATRIX_STORAGE_TPP
