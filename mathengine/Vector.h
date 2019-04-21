#include <vector>

class PhysVector {
	public:
		PhysVector() : i(0), j(0), k(0){}
		PhysVector(float i, float j, float k) : i(i), j(j), k(k){}
		PhysVector(const PhysVector& o) : i(o.i), j(o.j), k(o.k){}
		PhysVector& operator=(const PhysVector& o){
			if (this == &o) return *this;
			i = o.i;
			j = o.j;
			k = o.k;
			return *this;
		}

		// Vector addition
		PhysVector& operator+=(const PhysVector& o){
			i += o.i;
			j += o.j;
			k += o.k;
			return *this;
		}
		const PhysVector operator+(const PhysVector& o) const {
			return PhysVector(*this) += o;
		}
		// Vector subtraction
		PhysVector& operator-=(const PhysVector& o){
			i -= o.i;
			j -= o.j;
			k -= o.k;
			return *this;
		}
		const PhysVector operator-(const PhysVector& o) const {
			return PhysVector(*this) -= o;
		}

		// Scalar Multiplication
		PhysVector& operator*=(const float s){
			i *= s;
			j *= s;
			k *= s;
			return *this;
		}
		const PhysVector operator*(const float s) const {
			return PhysVector(*this) *= s;
		}
		// Scalar division
		PhysVector& operator/=(const float s){
			i /= s;
			j /= s;
			k /= s;
			return *this;
		}
		const PhysVector operator/(const float s) const {
			return PhysVector(*this) /= s;
		}

		float dot(const PhysVector& o) const {
			return i*o.i + j*o.j + k*o.k;
		}

		PhysVector cross(const PhysVector& o) const {
			return PhysVector(
					j*o.k - k*o.j,
					i*o.k - k*o.i,
					i*o.j - j*o.i);
		}

	protected:
		float i;
		float j;
		float k;
};
