#include "Matrix.h"

#include <algorithm>

namespace mathengine {
/*
    template<typename T, int N, int M>
	bool Matrix<T, N, M>::operator==(const Matrix& rhs) const noexcept {
		return rows == rhs.rows;
	}

    template<typename T, int N, int M>
	bool Matrix<T, N, M>::operator!=(const Matrix& rhs) const noexcept {
		return !(*this == rhs);
	}
	// Matrix Addition
    template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator+=(const Matrix& rhs) noexcept {
		std::transform(begin(), end(), rhs.cbegin(), std::plus<Vector<T, N>>());
		return (*this);
	}
    template<typename T, int N, int M>
	Matrix<T, N, M> Matrix<T, N, M>::operator+(const Matrix& rhs) noexcept {
		return Matrix(*this) += rhs;
	}

	// Matrix Subtraction
    template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator-=(const Matrix& rhs) noexcept {
		for (unsigned int i = 0; i < 3; ++i){
			rows[i] -= rhs[i];
		}
		return (*this);
	}
    template<typename T, int N, int M>
	Matrix<T, N, M> Matrix<T, N, M>::operator-(const Matrix& rhs) noexcept {
		return Matrix(*this) -= rhs;
	}

	// Scalar Multiplication
    template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator*=(T s) noexcept {
		for (auto& r : rows){
			r *= s;
		}
		return (*this);
	}
    template<typename T, int N, int M>
	Matrix<T, N, M> Matrix<T, N, M>::operator*(T s) const noexcept {
        return Matrix(*this) *= s;
    }

	// Scalar Division
    template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator/=(T s) {
		for (auto& row : rows){
			row /= s;
		}
		return (*this);
	}
    template<typename T, int N, int M>
	Matrix<T, N, M> Matrix<T, N, M>::operator/(T s) const {
		return Matrix(*this) /= s;
	}

	// Vector & Matrix Multiplication
    template<typename T, int N, int M>
    template<typename U>
	Vector<U, N> Matrix<T, N, M>::operator*(const Vector<U, N>& rhs) const noexcept {
	    Vector<U, N> v;
	    int i = 0;
	    for (const auto& r : rows) {
            v[i++] = r.dot(rhs);
	    }
		return v;
	}

    template<typename T, int N, int M>
    Vector<T, M> Matrix<T, N, M>::col(int idx){
        Vector<T, M> c;
        int j = 0;
        for (int i = 0; i < M; ++i){
            c[j++] = rows[idx][i];
        }
        return c;
    }

    template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator*=(const Matrix& rhs) noexcept {
	    std::transform(begin(), end(), begin(), rhs.begin(), [](const auto& a, const auto& b){ return a.dot(b); });
		auto col1 = rhs.i();
		auto col2 = rhs.j();
		auto col3 = rhs.k();

		auto make_row = [&](const auto& row){
			return Vector(row.dot(col1), row.dot(col2), row.dot(col3));
		};
		rows[0] = make_row(rows[0]);
		rows[1] = make_row(rows[1]);
		rows[2] = make_row(rows[2]);
		return (*this);
	}
    template<typename T>
	Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const noexcept {
		return Matrix(*this) *= rhs;
	}

	// Matrix Operations
    template<typename T>
	void Matrix<T>::transpose() noexcept {
		double tmp = rows[0].j();
		rows[0].j(rows[1].i());
		rows[1].i(tmp);

		tmp = rows[0].k();
		rows[0].k(rows[2].i());
		rows[2].i(tmp);

		tmp = rows[1].k();
		rows[1].k(rows[2].j());
		rows[2].j(tmp);
	}
    template<typename T>
	Matrix<T> Matrix<T>::transpose_of() const noexcept {
		return Matrix(i(), j(), k());
	}
    template<typename T>
	inline T cross_part(const T& k, const T& c1, const T& c2, const T& c3, const T& c4) noexcept {
		return k*(c1*c4 - c2*c3);
	}
    template<typename T>
	Matrix<T> Matrix<T>::inverse_of() const {
		auto make_vec = [&](const int start, const unsigned int r1, const unsigned int r2){
			double i = cross_part(start, rows[r1].j(), rows[r1].k(), rows[r2].j(), rows[r2].k());
			double j = cross_part(start*-1, rows[r1].i(), rows[r1].k(), rows[r2].i(), rows[r2].k());
			double k = cross_part(start, rows[r1].i(), rows[r1].j(), rows[r2].i(), rows[r2].j());
			return Vector(i, j, k);
		};
		auto r1 = make_vec(1,1,2);
		auto r2 = make_vec(-1,0,2);
		auto r3 = make_vec(1,0,1);

		double det = rows[0].i() * r1.i() + rows[0].j() * r1.j() + rows[0].k() * r1.k();
		auto m = Matrix(r1, r2, r3);
		m.transpose();

		return m/det;
	}
    template<typename T>
	T Matrix<T>::det() const noexcept {
		T d = cross_part(rows[0].i(), rows[1].j(), rows[1].k(), rows[2].j(), rows[2].k());
		d -= cross_part(rows[0].j(), rows[1].i(), rows[1].k(), rows[2].i(), rows[2].k());
		d += cross_part(rows[0].k(), rows[1].i(), rows[1].j(), rows[2].i(), rows[2].j());
		return d;
	}
	*/
}
