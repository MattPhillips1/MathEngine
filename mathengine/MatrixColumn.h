//
// Created by matt on 7/1/20.
//

#ifndef MATHENGINE_MATRIXCOLUMN_H
#define MATHENGINE_MATRIXCOLUMN_H

#include "MatrixColumnIterator.h"

namespace mathengine {
    template<typename T, int num_cols>
    class Matrix;
    template<typename T, int num_cols>
    class MatrixColumn {
        public:
            using iterator = MatrixColumnIterator<T, num_cols, false>;
            using const_iterator = MatrixColumnIterator<T, num_cols, true>;

            // MatrixColumn(MatrixColumn&& o) = delete; // Cannot move a column of a matrix without moving the entire matrix
            MatrixColumn() = delete;
            // MatrixColumn(const MatrixColumn& o) = delete;
            MatrixColumn(Matrix<T, num_cols>& mat, int col) : m{mat}, col{col} {}

            T& operator[] (int i) {
                auto& r = m.row(i);
                return r[col];
            }
            const T& operator[] (int i) const { return m.row(i)[col]; }
            
            iterator begin() noexcept { return iterator(*this, 0); }
            iterator end() noexcept { return begin() + m.n_rows(); }

            const_iterator begin() const noexcept { return const_iterator(*this, 0); }
            const_iterator end() const noexcept { return begin() + m.n_rows(); }

            const_iterator cbegin() const noexcept { return begin(); }
            const_iterator cend() const noexcept { return end(); }
            


        private:
            Matrix<T, num_cols>& m;
            int col;
    };
}


#endif //MATHENGINE_MATRIXCOLUMN_H
