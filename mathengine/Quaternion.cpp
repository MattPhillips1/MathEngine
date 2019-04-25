#include "Quaternion.h"
#include <cmath>

namespace mathengine {
	bool PhysQuaternion::operator==(const PhysQuaternion& rhs) const noexcept {
	return s() == rhs.s() && v() == rhs.v();
	}
	bool PhysQuaternion::operator!=(const PhysQuaternion& rhs) const noexcept {
		return !(*this == rhs);
	}
	PhysQuaternion& PhysQuaternion::operator+=(const PhysQuaternion& rhs) noexcept {
		s(s() + rhs.s());
		v() += rhs.v();
		return (*this);
	}
	const PhysQuaternion PhysQuaternion::operator+(const PhysQuaternion& rhs) const noexcept {
		auto temp = *this;
		temp += rhs;
		return temp;
	}
	PhysQuaternion& PhysQuaternion::operator-=(const PhysQuaternion& rhs) noexcept {
		s(s() - rhs.s());
		v() -= rhs.v();
		return (*this);
	}
	const PhysQuaternion PhysQuaternion::operator-(const PhysQuaternion& rhs) const noexcept {
		auto temp = *this;
		temp -= rhs;
		return temp;
	}
	PhysQuaternion& PhysQuaternion::operator*=(const double rhs) noexcept {
		s(s() * rhs);
		v() *= rhs;
		return (*this);
	}
	const PhysQuaternion PhysQuaternion::operator*(const double rhs) const noexcept {
		auto temp = *this;
		temp *= rhs;
		return temp;
	}
	const PhysQuaternion operator*(const double lhs, const PhysQuaternion& rhs) {
		return rhs*lhs;
	}
	PhysQuaternion& PhysQuaternion::operator/=(const double rhs) {
		v() /= rhs;
		s(s()/rhs);
		return (*this);

	}
	const PhysQuaternion PhysQuaternion::operator/(const double rhs) const {
		auto temp = *this;
		temp /= rhs;
		return temp;
	}

	PhysQuaternion& PhysQuaternion::operator*=(const PhysQuaternion& rhs) noexcept {
		auto new_s = s()*rhs.s() - v().dot(rhs.v());
		v() = s()*rhs.v() + rhs.s() * v() + v().cross(rhs.v());
		s(new_s);
		return (*this);
	}
	const PhysQuaternion PhysQuaternion::operator*(const PhysQuaternion& rhs) const noexcept {
		auto temp = *this;
		temp *= rhs;
		return temp;
	}

	double PhysQuaternion::magnitude() const noexcept {
		return std::sqrt(square_sum());
	}
	void PhysQuaternion::normalize() {
		*this /= magnitude();
	}
	void PhysQuaternion::make_rotation() {
		// Pre condition - Expects v to be unit
		// Pre condition - Expects s to be an angle in radians
		auto angle = s()/2;
		v() *= sin(angle);
		s(cos(angle));
	}
	PhysQuaternion PhysQuaternion::unit() const {
		auto temp = *this;
		temp.normalize();
		return temp;
	}
	PhysQuaternion PhysQuaternion::rotation_unit() const {
		auto temp = *this;
		temp.v().normalize();
		temp.make_rotation();
		return temp;
	}
	PhysQuaternion PhysQuaternion::conjugate_of() const noexcept {
		auto temp = *this;
		temp.v() *= -1;
		return temp;
	}

	PhysQuaternion PhysQuaternion::inverse_of() const {
		auto temp = conjugate_of();
		temp /= square_sum();
		return temp;
	}

}
