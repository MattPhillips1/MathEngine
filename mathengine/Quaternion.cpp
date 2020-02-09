#include "Quaternion.h"
#include <cmath>

namespace mathengine {
    template <typename T>
	bool Quaternion<T>::operator==(const Quaternion<T>& rhs) const noexcept {
	return s() == rhs.s() && v() == rhs.v();
	}

    template <typename T>
    bool Quaternion<T>::operator!=(const Quaternion& rhs) const noexcept {
		return !(*this == rhs);
	}

    template <typename T>
	Quaternion<T>& Quaternion<T>::operator+=(const Quaternion& rhs) noexcept {
		s(s() + rhs.s());
		v() += rhs.v();
		return (*this);
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::operator+(const Quaternion& rhs) const noexcept {
		auto temp = *this;
		temp += rhs;
		return temp;
	}

    template <typename T>
	Quaternion<T>& Quaternion<T>::operator-=(const Quaternion& rhs) noexcept {
		s(s() - rhs.s());
		v() -= rhs.v();
		return (*this);
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::operator-(const Quaternion& rhs) const noexcept {
		auto temp = *this;
		temp -= rhs;
		return temp;
	}

    template <typename T>
	Quaternion<T>& Quaternion<T>::operator*=(double rhs) noexcept {
		s(s() * rhs);
		v() *= rhs;
		return (*this);
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::operator*(double rhs) const noexcept {
		auto temp = *this;
		temp *= rhs;
		return temp;
	}

    template <typename T>
	Quaternion<T>& Quaternion<T>::operator/=(double rhs) {
		v() /= rhs;
		s(s()/rhs);
		return (*this);

	}

    template <typename T>
	Quaternion<T> Quaternion<T>::operator/(double rhs) const {
		auto temp = *this;
		temp /= rhs;
		return temp;
	}

    template <typename T>
	Quaternion<T>& Quaternion<T>::operator*=(const Quaternion& rhs) noexcept {
		auto new_s = s()*rhs.s() - v().dot(rhs.v());
		v() = s()*rhs.v() + rhs.s() * v() + v().cross(rhs.v());
		s(new_s);
		return (*this);
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& rhs) const noexcept {
		auto temp = *this;
		temp *= rhs;
		return temp;
	}

    template <typename T>
	double Quaternion<T>::magnitude() const noexcept {
		return std::sqrt(square_sum());
	}

    template <typename T>
	void Quaternion<T>::normalize() {
		*this /= magnitude();
	}

    template <typename T>
	void Quaternion<T>::make_rotation() {
		// Pre condition - Expects v to be unit
		// Pre condition - Expects s to be an angle in radians
		auto angle = s()/2;
		v() *= sin(angle);
		s(cos(angle));
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::unit() const {
		auto temp = *this;
		temp.normalize();
		return temp;
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::rotation_unit() const {
		auto temp = *this;
		temp.v().normalize();
		temp.make_rotation();
		return temp;
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::conjugate_of() const noexcept {
		auto temp = *this;
		temp.v() *= -1;
		return temp;
	}

    template <typename T>
	Quaternion<T> Quaternion<T>::inverse_of() const {
		auto temp = conjugate_of();
		temp /= square_sum();
		return temp;
	}

}
