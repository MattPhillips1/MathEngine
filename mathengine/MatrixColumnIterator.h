//
// Created by matt on 6/1/20.
//

#ifndef MATHENGINE_MATRIXCOLUMNITERATOR_H
#define MATHENGINE_MATRIXCOLUMNITERATOR_H


namespace mathengine {
    template <typename T, int num_cols>
    class MatrixColumn;

    template<typename T, int num_cols, bool is_const>
    class MatrixColumnIterator {
        public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::conditional_t<is_const, const T, T>;
        using reference = std::conditional_t<is_const, const T &, T &>;
        using pointer = std::conditional_t<is_const, const T *, T *>;
        using difference_type = int;

        using column_type = std::conditional_t<is_const, const MatrixColumn<T, num_cols>&, MatrixColumn<T, num_cols>&>;

        MatrixColumnIterator() = delete;

        MatrixColumnIterator(column_type col, int curr_row) : column{col}, curr_row{curr_row} {}

        MatrixColumnIterator(const MatrixColumnIterator<T, num_cols, false> &it) : column{it.column}, curr_row{it.curr_row} {}

        reference operator*() const { return column[curr_row]; }

        MatrixColumnIterator &operator++() {
            ++curr_row;
            return *this;
        }

        MatrixColumnIterator operator++(int) {
            auto copy{*this};
            ++(*this);
            return copy;
        }

        pointer operator->() const { return &(operator*()); }

        friend bool operator==(const MatrixColumnIterator &lhs, const MatrixColumnIterator &rhs) {
            return &lhs.column == &rhs.column && lhs.curr_row == rhs.curr_row;
        }

        friend bool operator!=(const MatrixColumnIterator &lhs, const MatrixColumnIterator &rhs) {
            return !(lhs == rhs);
        }

        MatrixColumnIterator &operator+=(difference_type rhs) {
            curr_row += rhs;
            return *this;
        }

        MatrixColumnIterator &operator-=(difference_type rhs) { return *this += (-rhs); }


        friend MatrixColumnIterator operator+(const MatrixColumnIterator &lhs, difference_type rhs) {
            MatrixColumnIterator copy{lhs};
            copy += rhs;
            return copy;
        }

        friend MatrixColumnIterator operator+(difference_type lhs, const MatrixColumnIterator &rhs) {
            return rhs + lhs;
        }

        friend MatrixColumnIterator operator-(difference_type lhs, const MatrixColumnIterator &rhs) {
            return rhs + (-lhs);
        }

        friend difference_type operator-(const MatrixColumnIterator &lhs, const MatrixColumnIterator &rhs) {
            return lhs.curr_row - rhs.curr_row;
        }

        friend bool operator<(MatrixColumnIterator lhs, MatrixColumnIterator rhs) { return rhs - lhs > 0; }

        friend bool operator>(MatrixColumnIterator lhs, MatrixColumnIterator rhs) { return rhs - lhs < 0; }

        friend bool operator<=(MatrixColumnIterator lhs, MatrixColumnIterator rhs) { !(lhs > rhs); }

        friend bool operator>=(MatrixColumnIterator lhs, MatrixColumnIterator rhs) { !(lhs < rhs); }

        private:
            int curr_row;
            column_type column;
    };
}


#endif //MATHENGINE_MATRIXCOLUMNITERATOR_H
