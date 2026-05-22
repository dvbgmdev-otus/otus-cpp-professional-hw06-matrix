#ifndef N_MATRIX_SLICE_H
#define N_MATRIX_SLICE_H

#include <cstddef>
#include <type_traits>

#include "n_matrix_cell.h"
#include "n_matrix_storage.h"
#include "n_matrix_types.h"

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth, typename Enable = void>
class NMatrixSlice;

template <typename T, T DefaultValue, std::size_t Dimension, std::size_t Depth, typename Enable>
class NMatrixSlice {
public:
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    using Position = NMatrixPosition<Dimension>;
    using Slice = NMatrixSlice<T, DefaultValue, Dimension, Depth + 1>;

    NMatrixSlice(Storage& storage, const Position& position);

    Slice operator[](NMatrixIndex index) &&;
    Slice operator[](NMatrixIndex index) & = delete;

private:
    Storage& m_storage;
    Position m_position;
};

template <typename T, T DefaultValue, std::size_t Dimension>
class NMatrixSlice<
    T,
    DefaultValue,
    Dimension,
    Dimension - 1,
    typename std::enable_if<(Dimension > 1)>::type> {
public:
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    using Position = NMatrixPosition<Dimension>;
    using Cell = NMatrixCell<T, DefaultValue, Dimension>;

    NMatrixSlice(Storage& storage, const Position& position);

    Cell operator[](NMatrixIndex index) &&;
    Cell operator[](NMatrixIndex index) & = delete;

private:
    Storage& m_storage;
    Position m_position;
};

#include "n_matrix_slice.tpp"

#endif  // N_MATRIX_SLICE_H
