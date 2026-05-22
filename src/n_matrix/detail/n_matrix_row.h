#ifndef N_MATRIX_ROW_H
#define N_MATRIX_ROW_H

#include "n_matrix_cell.h"
#include "n_matrix_storage.h"

template <typename T, T DefaultValue, std::size_t Dimension>
class NMatrixRow {
public:
    using Storage = NMatrixStorage<T, DefaultValue, Dimension>;
    using Cell = NMatrixCell<T, DefaultValue, Dimension>;

    NMatrixRow(Storage& storage, NMatrixIndex row);

    Cell operator[](NMatrixIndex column) &&;
    Cell operator[](NMatrixIndex column) & = delete;

private:
    Storage& m_storage;
    NMatrixIndex m_row;
};

#include "n_matrix_row.tpp"

#endif  // N_MATRIX_ROW_H
