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
		double sum = s()*s();
		sum += v().i() * v().i();
		sum += v().j() * v().j();
		sum += v().k() * v().k();
		return std::sqrt(sum);
	}
	void PhysQuaternion::normalize() noexcept {
		*this /= magnitude();
	}
	PhysQuaternion PhysQuaternion::unit() const noexcept {
		auto temp = *this;
		temp.normalize();
		return temp;
	}
	PhysQuaternion PhysQuaternion::conjugate_of() const noexcept {
		auto temp = *this;
		temp.v() *= -1;
		return temp;
	}

}
