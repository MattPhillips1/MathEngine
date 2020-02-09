#ifndef P_MATRIX
#define P_MATRIX

#include <array>
#include "Vector.h"
// #include "MatrixColumnIterator.h"
#include "MatrixColumn.h"

namespace mathengine {
    // template <typename T, int num_cols>
    // class MatrixColumn;

    template <typename T, int num_cols>
	class Matrix {
		/*
		* Aligned in the following way (better cache performance)
		* i       j       k
		* 1       0       0
		* 0       1       0
		* 0       0       1
		*
		* ie top row is one vector with i,j,k components
		*/
		public:

			using MatrixRow = Vector<T, std::array<T, num_cols>, true>;
			using MatrixCol = Vector<T, MatrixColumn<T, num_cols>, false>;
			// Default, Copy, Move constructors generated
			constexpr explicit Matrix(int num_rows) : rows(num_rows) {}
			/*
			bool operator==(const Matrix& rhs) const noexcept;
			bool operator!=(const Matrix& rhs) const noexcept;

			// Matrix Addition
			Matrix& operator += (const Matrix& rhs) noexcept;
			Matrix operator+(const Matrix& rhs) noexcept;

			// Matrix Subtraction
			Matrix& operator -= (const Matrix& rhs) noexcept;
			const Matrix operator-(const Matrix& rhs) noexcept;

			// Scalar Multiplication
			Matrix& operator*=(T s) noexcept;
			Matrix operator*(T s) const noexcept;
			friend Matrix operator*(T s, const Matrix& v) noexcept {
			    return v*s;
			}

			// Scalar Division
			Matrix& operator/=(T s);
			Matrix operator/(T s) const;

			// Vector & Matrix Multiplication
            template<typename U, typename Container>
			Vector<U, Container> operator*(const Vector<U, Container>& rhs) const noexcept;
			template<typename U, bool is_const>
			Vector<U> operator*(const MatrixColumn<U, num_cols, is_const>& rhs) const noexcept;
			Matrix& operator*=(const Matrix& rhs) noexcept;
			Matrix operator*(const Matrix& rhs) const noexcept;

			// Matrix Operations
			void transpose() noexcept;
			Matrix transpose_of() const noexcept;
			Matrix inverse_of() const;
			T det() const noexcept;
			*/
			MatrixRow& row(int i) noexcept { return rows[i]; }
			const MatrixRow& row(int i) const noexcept { return rows[i]; }
			MatrixCol col(int i) noexcept { return MatrixCol(MatrixColumn<T, num_cols>(*this, i)); }
			const MatrixCol col(int i) const noexcept { return MatrixCol(MatrixColumn<T, num_cols>(*this, i)); }

			void add_row(void) { rows.emplace_back(num_cols); }
			int n_rows(void) const noexcept { return rows.size(); }

			constexpr int n_cols(void) const noexcept { return num_cols; }



		private:
			std::vector<MatrixRow> rows;
			friend class MatrixColumn<T, num_cols>;
	};
}
#endif
