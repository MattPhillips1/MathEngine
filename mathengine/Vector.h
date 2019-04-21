#ifndef P_VECTOR
#define P_VECTOR

#include <cmath>
#include <stdexcept>

namespace mathengine {
	class PhysVector {
		public:
			PhysVector() noexcept : i(0), j(0), k(0){}
			PhysVector(double i, double j, double k) noexcept : i(i), j(j), k(k){}
			PhysVector(const PhysVector& o) noexcept : i(o.i), j(o.j), k(o.k){}
			PhysVector(PhysVector&& o) noexcept : i(o.i), j(o.j), k(o.k){}
			PhysVector& operator=(const PhysVector& o) noexcept;
			bool operator==(const PhysVector& o) const noexcept;
			bool operator!=(const PhysVector& o) const noexcept;

			// Vector addition
			PhysVector& operator+=(const PhysVector& o) noexcept;
			const PhysVector operator+(const PhysVector& o) const noexcept;

			// Vector subtraction
			PhysVector& operator-=(const PhysVector& o) noexcept;
			const PhysVector operator-(const PhysVector& o) const noexcept;

			// Scalar Multiplication
			PhysVector& operator*=(const double s) noexcept;
			const PhysVector operator*(const double s) const noexcept;

			// Scalar division
			PhysVector& operator/=(const double s);
			const PhysVector operator/(const double s) const;

			double dot(const PhysVector& o) const noexcept;

			PhysVector cross(const PhysVector& o) const noexcept;

			double magnitude() const noexcept;

			void normalize();

			PhysVector norm() const;


			double i;
			double j;
			double k;
	};
	const PhysVector operator*(const double k, const PhysVector& v) noexcept;
};
#endif
