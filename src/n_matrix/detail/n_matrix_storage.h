#ifndef N_MATRIX_STORAGE_H
#define N_MATRIX_STORAGE_H

#include <map>

#include "n_matrix_iterator.h"
#include "n_matrix_types.h"

template <typename T, T DefaultValue, std::size_t Dimension>
class NMatrixStorage {
public:
    using Iterator = NMatrixIterator<T, Dimension>;

    T get(const NMatrixPosition<Dimension>& position) const;

    void set(const NMatrixPosition<Dimension>& position, const T& value);

    std::size_t size() const;

    Iterator begin() const;

    Iterator end() const;

private:
    std::map<NMatrixPosition<Dimension>, T> m_data;
};

#include "n_matrix_storage.tpp"

#endif  // N_MATRIX_STORAGE_H
