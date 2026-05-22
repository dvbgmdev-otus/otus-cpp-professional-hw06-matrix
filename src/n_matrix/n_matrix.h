#ifndef N_MATRIX_H
#define N_MATRIX_H

#include "n_matrix_row.h"
#include "n_matrix_storage.h"

template <typename T, T DefaultValue>
class NMatrix {
public:
    using Iterator = typename NMatrixStorage<T, DefaultValue>::Iterator;

    NMatrixRow<T, DefaultValue> operator[](NMatrixIndex row) &;

    std::size_t size() const;

    Iterator begin() const;

    Iterator end() const;

private:
    NMatrixStorage<T, DefaultValue> m_storage;
};

#include "n_matrix.tpp"

#endif  // N_MATRIX_H
