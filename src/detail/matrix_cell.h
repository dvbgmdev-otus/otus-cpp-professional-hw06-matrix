#ifndef MATRIX_CELL_H
#define MATRIX_CELL_H

#include "matrix_storage.h"

template <typename T, T DefaultValue>
class MatrixCell {
public:
    using storage_type = MatrixStorage<T, DefaultValue>;
    using index_type = typename storage_type::index_type;
    using value_type = typename storage_type::value_type;

    MatrixCell(storage_type& storage, index_type row, index_type column);

    MatrixCell& operator=(const value_type& value);

    operator value_type() const;

private:
    storage_type& m_storage;
    index_type m_row;
    index_type m_column;
};

#include "matrix_cell.tpp"

#endif  // MATRIX_CELL_H
