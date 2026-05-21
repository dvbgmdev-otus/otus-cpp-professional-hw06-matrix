#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H

#include "matrix_cell.h"
#include "matrix_storage.h"

template <typename T, T DefaultValue>
class MatrixRow {
public:
    using Storage = MatrixStorage<T, DefaultValue>;

    MatrixRow(Storage& storage, MatrixIndex row);

    MatrixCell<T, DefaultValue> operator[](MatrixIndex column) &&;
    MatrixCell<T, DefaultValue> operator[](MatrixIndex column) & = delete;

private:
    Storage& m_storage;
    MatrixIndex m_row;
};

#include "matrix_row.tpp"

#endif  // MATRIX_ROW_H
