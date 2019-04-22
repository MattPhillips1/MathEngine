#include "Vector.h"
namespace mathengine {
	bool PhysVector::operator==(const PhysVector& o) const noexcept {
		return i() == o.i() && j() == o.j() && k() == o.k();
	}
	bool PhysVector::operator!=(const PhysVector& o) const noexcept {
		return !(*this == o);
	}

	PhysVector& PhysVector::operator=(const PhysVector& o) noexcept {
		if (this == &o) return *this;
		i(o.i());
		j(o.j());
		k(o.k());
		return *this;
	}

	// Vector addition
	PhysVector& PhysVector::operator+=(const PhysVector& o) noexcept {
		i(i() + o.i());
		j(j() + o.j());
		k(k() + o.k());
		return *this;
	}
	const PhysVector PhysVector::operator+(const PhysVector& o) const noexcept {
		return PhysVector(*this) += o;
	}
	// Vector subtraction
	PhysVector& PhysVector::operator-=(const PhysVector& o) noexcept {
		i(i() - o.i());
		j(j() - o.j());
		k(k() - o.k());
		return *this;
	}
	const PhysVector PhysVector::operator-(const PhysVector& o) const noexcept {
		return PhysVector(*this) -= o;
	}

	// Scalar Multiplication
	PhysVector& PhysVector::operator*=(const double s) noexcept {
		i(i() * s);
		j(j() * s);
		k(k() * s);
		return *this;
	}
	const PhysVector PhysVector::operator*(const double s) const noexcept {
		return PhysVector(*this) *= s;
	}
	// Scalar division
	PhysVector& PhysVector::operator/=(const double s) {
		if (s == 0) throw std::runtime_error("Math error: Division by 0");
		auto div = 1.0/s;
		return (*this) *= div;
	}
	const PhysVector PhysVector::operator/(const double s) const {
		return PhysVector(*this) /= s;
	}

	double PhysVector::dot(const PhysVector& o) const noexcept {
		return i()*o.i() + j()*o.j() + k()*o.k();
	}

	PhysVector PhysVector::cross(const PhysVector& o) const noexcept {
		return PhysVector(
				j()*o.k() - k()*o.j(),
				i()*o.k() - k()*o.i(),
				i()*o.j() - j()*o.i());
	}

	double PhysVector::magnitude() const noexcept {
		return std::sqrt(i()*i() + j()*j() + k()*k());
	}

	void PhysVector::normalize() {
		(*this) /= this->magnitude();
	}

	PhysVector PhysVector::norm() const {
		auto temp = PhysVector(*this);
		temp.normalize();
		return temp;
	}

	const PhysVector operator*(const double k, const PhysVector& v) noexcept {
		return v*k;
	}
};
