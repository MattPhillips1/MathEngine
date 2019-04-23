#include "Matrix.h"

namespace mathengine {

	bool PhysMatrix::operator==(const PhysMatrix& rhs) const noexcept {
		return rows == rhs.rows;
	}

	bool PhysMatrix::operator!=(const PhysMatrix& rhs) const noexcept {
		return !(*this == rhs);
	}
	// Matrix Addition
	PhysMatrix& PhysMatrix::operator+=(const PhysMatrix& rhs) noexcept {
		for (unsigned int i = 0; i < 3; ++i){
			rows[i] += rhs[i];
		}
		return (*this);
	}
	const PhysMatrix PhysMatrix::operator+(const PhysMatrix& rhs) noexcept {
		return PhysMatrix(*this) += rhs;
	}

	// Matrix Subtraction
	PhysMatrix& PhysMatrix::operator -= (const PhysMatrix& rhs) noexcept {
		for (unsigned int i = 0; i < 3; ++i){
			rows[i] -= rhs[i];
		}
		return (*this);
	}
	const PhysMatrix PhysMatrix::operator-(const PhysMatrix& rhs) noexcept {
		return PhysMatrix(*this) -= rhs;
	}

	// Scalar Multiplication
	PhysMatrix& PhysMatrix::operator*=(const double s) noexcept {
		for (auto& r : rows){
			r *= s;
		}
		return (*this);
	}
	const PhysMatrix PhysMatrix::operator*(const double s) const noexcept {
		return PhysMatrix(*this) *= s;
	}
	const PhysMatrix operator*(const double s, const PhysMatrix& v) noexcept {
		return v*s;
	}

	// Scalar Division
	PhysMatrix& PhysMatrix::operator/=(const double s) {
		for (auto& row : rows){
			row /= s;
		}
		return (*this);
	}
	const PhysMatrix PhysMatrix::operator/(const double s) const {
		return PhysMatrix(*this) /= s;
	}

	// Vector & Matrix Multiplication
	const PhysVector PhysMatrix::operator*(const PhysVector& rhs) const noexcept {
		auto i = (*this)[0].dot(rhs);
		auto j = (*this)[1].dot(rhs);
		auto k = (*this)[2].dot(rhs);
		return PhysVector(i,j,k);
	}
	PhysMatrix& PhysMatrix::operator*=(const PhysMatrix& rhs) noexcept {
		auto col1 = rhs.i();
		auto col2 = rhs.j();
		auto col3 = rhs.k();

		auto make_row = [&](const auto& row){
			return PhysVector(row.dot(col1), row.dot(col2), row.dot(col3));
		};
		rows[0] = make_row(rows[0]);
		rows[1] = make_row(rows[1]);
		rows[2] = make_row(rows[2]);
		return (*this);
	}
	const PhysMatrix PhysMatrix::operator*(const PhysMatrix& rhs) const noexcept {
		return PhysMatrix(*this) *= rhs;
	}

	// Matrix Operations
	void PhysMatrix::transpose() noexcept {
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
	PhysMatrix PhysMatrix::transpose_of() const noexcept {
		return PhysMatrix(i(), j(), k());
	}
	inline double cross_part(const double& k, const double& c1, const double& c2, const double& c3, const double& c4) noexcept {
		return k*(c1*c4 - c2*c3);
	}
	PhysMatrix PhysMatrix::inverse_of() const {
		auto make_vec = [&](const int start, const unsigned int r1, const unsigned int r2){
			double i = cross_part(start, rows[r1].j(), rows[r1].k(), rows[r2].j(), rows[r2].k());
			double j = cross_part(start*-1, rows[r1].i(), rows[r1].k(), rows[r2].i(), rows[r2].k());
			double k = cross_part(start, rows[r1].i(), rows[r1].j(), rows[r2].i(), rows[r2].j());
			return PhysVector(i,j,k);
		};
		auto r1 = make_vec(1,1,2);
		auto r2 = make_vec(-1,0,2);
		auto r3 = make_vec(1,0,1);

		double det = rows[0].i() * r1.i() + rows[0].j() * r1.j() + rows[0].k() * r1.k();
		auto m = PhysMatrix(r1, r2, r3);
		m.transpose();

		return m/det;
	}
	double PhysMatrix::det() const noexcept {
		double d = cross_part(rows[0].i(), rows[1].j(), rows[1].k(), rows[2].j(), rows[2].k());
		d -= cross_part(rows[0].j(), rows[1].i(), rows[1].k(), rows[2].i(), rows[2].k());
		d += cross_part(rows[0].k(), rows[1].i(), rows[1].j(), rows[2].i(), rows[2].j());
		return d;
	}
}
