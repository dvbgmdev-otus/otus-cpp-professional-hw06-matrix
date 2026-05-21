#ifndef MATRIX_STORAGE_TPP
#define MATRIX_STORAGE_TPP

#ifndef MATRIX_STORAGE_H
#include "matrix_storage.h"
#endif  // MATRIX_STORAGE_H

template <typename T, T DefaultValue>
T MatrixStorage<T, DefaultValue>::get(MatrixIndex row, MatrixIndex column) const {
    const auto it = m_data.find(MatrixPosition(row, column));
    if (it == m_data.end()) {
        return DefaultValue;
    }

    return it->second;
}

template <typename T, T DefaultValue>
void MatrixStorage<T, DefaultValue>::set(MatrixIndex row, MatrixIndex column, const T& value) {
    const MatrixPosition position(row, column);
    if (value == DefaultValue) {
        m_data.erase(position);
        return;
    }

    m_data[position] = value;
}

template <typename T, T DefaultValue>
std::size_t MatrixStorage<T, DefaultValue>::size() const {
    return m_data.size();
}

#endif  // MATRIX_STORAGE_TPP
