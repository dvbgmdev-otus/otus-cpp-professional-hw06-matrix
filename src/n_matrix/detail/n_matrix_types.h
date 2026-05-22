#ifndef N_MATRIX_TYPES_H
#define N_MATRIX_TYPES_H

#include <array>
#include <cstddef>

using NMatrixIndex = std::size_t;
template <std::size_t Dimension>
using NMatrixPosition = std::array<NMatrixIndex, Dimension>;

#endif  // N_MATRIX_TYPES_H
