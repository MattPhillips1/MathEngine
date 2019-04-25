#ifndef P_VECTOR
#define P_VECTOR

#include <cmath>
#include <stdexcept>
#include <iostream>

namespace mathengine {
	class PhysVector {
		public:
			PhysVector() noexcept : _i{0}, _j{0}, _k{0}, mag{0}, mag_valid{true}{}
			PhysVector(double i, double j, double k) noexcept : _i{i}, _j{j}, _k{k}, mag{0}, mag_valid{false}{}
			PhysVector(const PhysVector& o) noexcept : _i{o.i()}, _j{o.j()}, _k{o.k()}, mag{o.mag}, mag_valid{o.mag_valid}{}
			PhysVector(PhysVector&& o) noexcept : _i{o.i()}, _j{o.j()}, _k{o.k()}, mag{o.mag}, mag_valid{o.mag_valid} {}
			PhysVector& operator=(const PhysVector& o) noexcept;
			bool operator==(const PhysVector& o) const noexcept;
			bool operator!=(const PhysVector& o) const noexcept;

			friend std::ostream& operator<<(std::ostream& os, const PhysVector& rhs) noexcept { return os << "[ " << rhs.i() << ", " << rhs.j() << ", " << rhs.k() <<" ]";}

			// Vector addition
			PhysVector& operator+=(const PhysVector& o) noexcept;
			const PhysVector operator+(const PhysVector& o) const noexcept;

			// Vector subtraction
			PhysVector& operator-=(const PhysVector& o) noexcept;
			const PhysVector operator-(const PhysVector& o) const noexcept;

			// Scalar Multiplication
			PhysVector& operator*=(const double s) noexcept;
			const PhysVector operator*(const double s) const noexcept;
			friend const PhysVector operator*(const double k, const PhysVector& v) noexcept;

			// Scalar division
			PhysVector& operator/=(const double s);
			const PhysVector operator/(const double s) const;

			double dot(const PhysVector& o) const noexcept;

			PhysVector cross(const PhysVector& o) const noexcept;

			double magnitude() const noexcept;
			inline double square_sum() const noexcept { return i()*i() + j()*j() + k()*k(); }

			void normalize();

			PhysVector unit() const;

			inline double i() const noexcept { return _i; }
			inline double j() const noexcept { return _j; }
			inline double k() const noexcept { return _k; }

			inline void i(const double n) noexcept { mag_valid = false; _i = n; }
			inline void j(const double n) noexcept { mag_valid = false; _j = n; }
			inline void k(const double n) noexcept { mag_valid = false; _k = n; }

		private:
			double _i;
			double _j;
			double _k;
			mutable double mag;
			mutable bool mag_valid;

	};
}
#endif
