#ifndef N_MATRIX_CELL_H
#define N_MATRIX_CELL_H

#include "n_matrix_storage.h"

template <typename T, T DefaultValue, std::size_t Dimension>
class NMatrixCell {
public:
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    using Position = NMatrixPosition<Dimension>;

    NMatrixCell(Storage& storage, NMatrixIndex row, NMatrixIndex column);
    NMatrixCell(Storage& storage, const Position& position);

    NMatrixCell& operator=(const T& value);

    operator T() const;

private:
    Storage& m_storage;
    Position m_position;
};

#include "n_matrix_cell.tpp"

#endif  // N_MATRIX_CELL_H
