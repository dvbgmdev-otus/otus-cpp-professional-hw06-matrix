#ifndef N_MATRIX_STORAGE_H
#define N_MATRIX_STORAGE_H

#include <map>

#include "n_matrix_iterator.h"
#include "n_matrix_types.h"

template <typename T, T DefaultValue>
class NMatrixStorage {
public:
    using Iterator = NMatrixIterator<T>;

    T get(NMatrixIndex row, NMatrixIndex column) const;

    void set(NMatrixIndex row, NMatrixIndex column, const T& value);

    std::size_t size() const;

    Iterator begin() const;

    Iterator end() const;

private:
    std::map<NMatrixPosition, T> m_data;
};

#include "n_matrix_storage.tpp"

#endif  // N_MATRIX_STORAGE_H
