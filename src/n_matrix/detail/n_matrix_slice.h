#ifndef N_MATRIX_SLICE_H
#define N_MATRIX_SLICE_H

#include <cstddef>

#include "n_matrix_storage.h"
#include "n_matrix_types.h"

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth>
class NMatrixSlice {
public:
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    using Position = NMatrixPosition<Dimension>;

    NMatrixSlice(Storage& storage, const Position& position);

private:
    Storage& m_storage;
    Position m_position;
};

#include "n_matrix_slice.tpp"

#endif  // N_MATRIX_SLICE_H
