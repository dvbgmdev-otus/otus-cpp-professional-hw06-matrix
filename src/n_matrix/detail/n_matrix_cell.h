#ifndef N_MATRIX_CELL_H
#define N_MATRIX_CELL_H

#include "n_matrix_storage.h"

template <typename T, T DefaultValue>
class NMatrixCell {
public:
    using Storage = NMatrixStorage<T, DefaultValue>;

    NMatrixCell(Storage& storage, NMatrixIndex row, NMatrixIndex column);

    NMatrixCell& operator=(const T& value);

    operator T() const;

private:
    Storage& m_storage;
    NMatrixIndex m_row;
    NMatrixIndex m_column;
};

#include "n_matrix_cell.tpp"

#endif  // N_MATRIX_CELL_H
