#ifndef MATRIX_STORAGE_H
#define MATRIX_STORAGE_H

#include <cstddef>
#include <map>
#include <utility>

template <typename T, T DefaultValue>
class MatrixStorage {
public:
    using index_type = std::size_t;
    using value_type = T;
    using position_type = std::pair<index_type, index_type>;

    value_type get(index_type row, index_type column) const;

    void set(index_type row, index_type column, const value_type& value);

    std::size_t size() const;

private:
    std::map<position_type, value_type> m_data;
};

#include "matrix_storage.tpp"

#endif  // MATRIX_STORAGE_H
