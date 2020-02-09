#include <algorithm>

namespace mathengine {


    template <typename T, typename Container, bool is_owning>
	template <typename NC, bool owning>
	bool Vector<T, Container, is_owning>::operator==(const Vector<T, NC, owning>& o) const noexcept {
		return std::equal(vec.begin(), vec.end(), o.vec.begin());
	}
	template <typename T, typename Container, bool is_owning>
	template <typename NC, bool owning>
	bool Vector<T, Container, is_owning>::operator!=(const Vector<T, NC, owning>& o) const noexcept {
		return !(*this == o);
	}

    template <typename T, typename Container, bool is_owning>
	template <typename NC, bool owning>
	Vector<T, Container, is_owning>& Vector<T, Container, is_owning>::operator=(const Vector<T, NC, owning>& o) noexcept {
		if constexpr (owning == is_owning && std::is_same<Container, NC>::value){
			if (this == &o) return *this;
		}
		std::copy(o.vec.cbegin(), o.vec.cend(), vec.begin()); 
		mag_valid = o.mag_valid;
		mag = o.mag;
		return *this;
	}
/*
	// Vector addition
    template <typename T, typename Container>
	Vector<T, Container>& Vector<T, Container>::operator+=(const Vector& o) noexcept {
	    if (o.size() != size()) throw std::runtime_error("Math Error: Cannot add two vectors of different size");
	    std::transform(o.cbegin(), o.cend(), begin(), end(), std::plus<T>());
		mag_valid = false;
		return *this;
	}

    template <typename T, typename Container>
	Vector<T, Container> Vector<T, Container>::operator+(const Vector<T, Container>& o) const noexcept {
		return Vector(*this) += o;
	}
	// Vector subtraction
	template <typename T, typename Container>
	Vector<T, Container>& Vector<T, Container>::operator-=(const Vector<T, Container>& o) noexcept {
        if (o.size() != size()) throw std::runtime_error("Math Error: Cannot subtract two vectors of different size");
		std::transform(o.cbegin(), o.cend(), begin(), end(), std::minus<T>());
		mag_valid = false;
		return *this;
	}
    template <typename T, typename Container>
	Vector<T, Container> Vector<T, Container>::operator-(const Vector<T, Container>& o) const noexcept {
		return Vector(*this) -= o;
	}

	// Scalar Multiplication
    template <typename T, typename Container>
	Vector<T, Container>& Vector<T, Container>::operator*=(const T s) noexcept {
		std::transform(begin(), end(), begin(), [&](const T& a){return a * s;});
		if(mag_valid) mag *= s;
		return *this;
	}
    template <typename T, typename Container>
	Vector<T, Container> Vector<T, Container>::operator*(const T s) const noexcept {
		return Vector(*this) *= s;
	}

	// Scalar division
    template <typename T, typename Container>
	Vector<T, Container>& Vector<T, Container>::operator/=(const T s) {
		if (s == 0) throw std::runtime_error("Math error: Division by 0");
		std::transform(begin(), end(), begin(), [&](const T& a){return a / s;});
        if(mag_valid) mag /= s;
        return *this;
	}
	template <typename T, typename Container>
	Vector<T, Container> Vector<T, Container>::operator/(const T s) const {
		return Vector(*this) /= s;
	}

    template <typename T, typename Container>
	T Vector<T, Container>::dot(const Vector<T, Container>& o) const noexcept {
		return std::inner_product(begin(), end(), o.begin(), 0);
	}



    template <typename T, typename Container>
    double Vector<T, Container>::magnitude() const noexcept {
		if (!mag_valid){
			mag = std::sqrt(square_sum());
			mag_valid = true;
		}
		return mag;
	}

    template <typename T, typename Container>
	void Vector<T, Container>::normalize() {
		(*this) /= magnitude();
		mag = 1;
		mag_valid = true;
	}

    template <typename T, typename Container>
	Vector<T, Container> Vector<T, Container>::unit() const {
		auto temp = Vector(*this);
		temp.normalize();
		return temp;
	}

    template <typename T, typename Container>
    template <typename OC>
    Vector<T> Vector<T, Container>::cross(const Vector<T, OC>& o) const noexcept {
        if (size() != 3 || o.size() != 3) raise std::runtime_error("Cross product is not defined on vectors with size != 3")
        return Vector<T>(
            (*this)[1]*(*this)[2] - (*this)[2]*(*this)[1],
            (*this)[2]*(*this)[0] - (*this)[0]*(*this)[2],
            (*this)[0]*(*this)[1] - (*this)[1]*(*this)[0]
        );
    }

    template <typename T, typename Container>
	Vector<T>& Vector<T>::rotate(double angle, const Vector<T>& axis){
		// Create it with the vector to avoid an extra copy
		auto q = Quaternion(angle, axis.unit());
		q.make_rotation();
		return rotate_unit(q);
	}

    template <typename T, typename Container>
	Vector3D<T>& Vector3D<T>::rotate(const Quaternion<T>& q){
		return rotate_unit(q.rotation_unit());
	}

    template <typename T, typename Container>
	Vector3D<T>& Vector3D<T>::rotate_unit(const Quaternion<T>& q){
		// Pre condition - Expects q to be ready for rotation
		// in form [sin(0.5x), cos(0.5x)v]
		auto p = Quaternion(*this);
		p = q*p*q.inverse_of();
		return p.v();
	}
*/
}
