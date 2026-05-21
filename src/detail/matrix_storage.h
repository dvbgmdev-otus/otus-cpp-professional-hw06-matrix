#ifndef MATRIX_STORAGE_H
#define MATRIX_STORAGE_H

#include <map>

#include "matrix_types.h"

template <typename T, T DefaultValue>
class MatrixStorage {
public:
    T get(MatrixIndex row, MatrixIndex column) const;

    void set(MatrixIndex row, MatrixIndex column, const T& value);

    std::size_t size() const;

private:
    std::map<MatrixPosition, T> m_data;
};

#include "matrix_storage.tpp"

#endif  // MATRIX_STORAGE_H
