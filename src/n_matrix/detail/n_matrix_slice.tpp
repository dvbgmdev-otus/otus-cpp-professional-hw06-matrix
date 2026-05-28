#ifndef N_MATRIX_SLICE_TPP
#define N_MATRIX_SLICE_TPP

#ifndef N_MATRIX_SLICE_H
#include "n_matrix_slice.h"
#endif  // N_MATRIX_SLICE_H

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth, bool IsLast>
// cppcheck-suppress uninitMemberVar
inline NMatrixSlice<T, DefaultValue, Dimension, Depth, IsLast>::NMatrixSlice(
    Storage& storage,
    const Position& position)
    : m_storage(storage), m_position(position) {}

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth, bool IsLast>
auto NMatrixSlice<T, DefaultValue, Dimension, Depth, IsLast>::operator[](NMatrixIndex index) && -> Slice {
    Position position = m_position;
    position[Depth] = index;
    return Slice(m_storage, position);
}

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth>
inline NMatrixSlice<
    T,
    DefaultValue,
    Dimension,
    Depth,
    true>::NMatrixSlice(
    Storage& storage,
    const Position& position)
    : m_storage(storage), m_position(position) {}

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth>
auto NMatrixSlice<
    T,
    DefaultValue,
    Dimension,
    Depth,
    true>::operator[](NMatrixIndex index) && -> Cell {
    Position position = m_position;
    position[Depth] = index;
    return Cell(m_storage, position);
}

#endif  // N_MATRIX_SLICE_TPP
