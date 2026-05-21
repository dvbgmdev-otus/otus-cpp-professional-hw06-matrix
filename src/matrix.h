#ifndef MATRIX_H
#define MATRIX_H

#include "matrix_row.h"
#include "matrix_storage.h"

template <typename T, T DefaultValue>
class Matrix {
public:
    using index_type = typename MatrixStorage<T, DefaultValue>::index_type;
    using value_type = typename MatrixStorage<T, DefaultValue>::value_type;

    MatrixRow<T, DefaultValue> operator[](index_type row) &;

    std::size_t size() const;

private:
    MatrixStorage<T, DefaultValue> m_storage;
};

#include "matrix.tpp"

#endif  // MATRIX_H
