#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H

#include "matrix_cell.h"
#include "matrix_storage.h"

template <typename T, T DefaultValue>
class MatrixRow {
public:
    using storage_type = MatrixStorage<T, DefaultValue>;
    using index_type = typename storage_type::index_type;

    MatrixRow(storage_type& storage, index_type row);

    MatrixCell<T, DefaultValue> operator[](index_type column) &&;
    MatrixCell<T, DefaultValue> operator[](index_type column) & = delete;

private:
    storage_type& m_storage;
    index_type m_row;
};

#include "matrix_row.tpp"

#endif  // MATRIX_ROW_H
