#include <cmath>
#include <stdexcept>

class PhysVector {
	public:
		PhysVector() noexcept : i(0), j(0), k(0){}
		PhysVector(float i, float j, float k) noexcept : i(i), j(j), k(k){}
		PhysVector(const PhysVector& o) noexcept : i(o.i), j(o.j), k(o.k){}
		PhysVector(PhysVector&& o) noexcept : i(o.i), j(o.j), k(o.k){}
		PhysVector& operator=(const PhysVector& o) noexcept {
			if (this == &o) return *this;
			i = o.i;
			j = o.j;
			k = o.k;
			return *this;
		}

		// Vector addition
		PhysVector& operator+=(const PhysVector& o) noexcept {
			i += o.i;
			j += o.j;
			k += o.k;
			return *this;
		}
		const PhysVector operator+(const PhysVector& o) const noexcept {
			return PhysVector(*this) += o;
		}
		// Vector subtraction
		PhysVector& operator-=(const PhysVector& o) noexcept {
			i -= o.i;
			j -= o.j;
			k -= o.k;
			return *this;
		}
		const PhysVector operator-(const PhysVector& o) const noexcept {
			return PhysVector(*this) -= o;
		}

		// Scalar Multiplication
		PhysVector& operator*=(const float s) noexcept {
			i *= s;
			j *= s;
			k *= s;
			return *this;
		}
		const PhysVector operator*(const float s) const noexcept {
			return PhysVector(*this) *= s;
		}
		// Scalar division
		PhysVector& operator/=(const float s) {
			if (s == 0) throw std::runtime_error("Math error: Division by 0");
			i /= s;
			j /= s;
			k /= s;
			return *this;
		}
		const PhysVector operator/(const float s) const {
			return PhysVector(*this) /= s;
		}

		float dot(const PhysVector& o) const noexcept {
			return i*o.i + j*o.j + k*o.k;
		}

		PhysVector cross(const PhysVector& o) const noexcept {
			return PhysVector(
					j*o.k - k*o.j,
					i*o.k - k*o.i,
					i*o.j - j*o.i);
		}

		float magnitude() const noexcept {
			return std::sqrt(i*i + j*j + k*k);
		}

		void normalize() {
			(*this) /= this->magnitude();
		}

		PhysVector norm() const {
			auto temp = PhysVector(*this);
			temp.normalize();
			return temp;
		}

	protected:
		float i;
		float j;
		float k;
};
