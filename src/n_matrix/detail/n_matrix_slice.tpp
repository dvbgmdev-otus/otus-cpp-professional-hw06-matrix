#ifndef N_MATRIX_SLICE_TPP
#define N_MATRIX_SLICE_TPP

#ifndef N_MATRIX_SLICE_H
#include "n_matrix_slice.h"
#endif  // N_MATRIX_SLICE_H

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth>
inline NMatrixSlice<T, DefaultValue, Dimension, Depth>::NMatrixSlice(
    Storage& storage,
    const Position& position)
    : m_storage(storage), m_position(position) {}

#endif  // N_MATRIX_SLICE_TPP
