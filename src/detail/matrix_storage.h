#ifndef MATRIX_STORAGE_H
#define MATRIX_STORAGE_H

#include <map>

#include "matrix_types.h"

template <typename T, T DefaultValue>
class MatrixStorage {
public:
    using value_type = T;

    value_type get(MatrixIndex row, MatrixIndex column) const;

    void set(MatrixIndex row, MatrixIndex column, const value_type& value);

    std::size_t size() const;

private:
    std::map<MatrixPosition, value_type> m_data;
};

#include "matrix_storage.tpp"

#endif  // MATRIX_STORAGE_H
