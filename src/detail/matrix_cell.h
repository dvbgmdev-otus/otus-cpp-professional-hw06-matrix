#ifndef MATRIX_CELL_H
#define MATRIX_CELL_H

#include "matrix_storage.h"

template <typename T, T DefaultValue>
class MatrixCell {
public:
    using Storage = MatrixStorage<T, DefaultValue>;

    MatrixCell(Storage& storage, MatrixIndex row, MatrixIndex column);

    MatrixCell& operator=(const T& value);

    operator T() const;

private:
    Storage& m_storage;
    MatrixIndex m_row;
    MatrixIndex m_column;
};

#include "matrix_cell.tpp"

#endif  // MATRIX_CELL_H
