#ifndef N_MATRIX_SLICE_TPP
#define N_MATRIX_SLICE_TPP

#ifndef N_MATRIX_SLICE_H
#include "n_matrix_slice.h"
#endif  // N_MATRIX_SLICE_H

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth, typename Enable>
inline NMatrixSlice<T, DefaultValue, Dimension, Depth, Enable>::NMatrixSlice(
    Storage& storage,
    const Position& position)
    : m_storage(storage), m_position(position) {}

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth, typename Enable>
auto NMatrixSlice<T, DefaultValue, Dimension, Depth, Enable>::operator[](NMatrixIndex index) && -> Slice {
    Position position = m_position;
    position[Depth] = index;
    return Slice(m_storage, position);
}

template <typename T, T DefaultValue, std::size_t Dimension>
inline NMatrixSlice<
    T,
    DefaultValue,
    Dimension,
    Dimension - 1,
    typename std::enable_if<(Dimension > 1)>::type>::NMatrixSlice(
    Storage& storage,
    const Position& position)
    : m_storage(storage), m_position(position) {}

template <typename T, T DefaultValue, std::size_t Dimension>
auto NMatrixSlice<
    T,
    DefaultValue,
    Dimension,
    Dimension - 1,
    typename std::enable_if<(Dimension > 1)>::type>::operator[](NMatrixIndex index) && -> Cell {
    Position position = m_position;
    position[Dimension - 1] = index;
    return Cell(m_storage, position);
}

#endif  // N_MATRIX_SLICE_TPP
