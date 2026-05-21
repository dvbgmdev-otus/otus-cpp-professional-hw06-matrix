#ifndef MATRIX_H
#define MATRIX_H

#include "matrix_row.h"
#include "matrix_storage.h"

template <typename T, T DefaultValue>
class Matrix {
public:
    MatrixRow<T, DefaultValue> operator[](MatrixIndex row) &;

    std::size_t size() const;

private:
    MatrixStorage<T, DefaultValue> m_storage;
};

#include "matrix.tpp"

#endif  // MATRIX_H
