#ifndef P_VECTOR
#define P_VECTOR

#include <cmath>
#include <stdexcept>

namespace mathengine {
	class PhysVector {
		public:
			PhysVector() noexcept : _i(0), _j(0), _k(0){}
			PhysVector(double i, double j, double k) noexcept : _i(i), _j(j), _k(k){}
			PhysVector(const PhysVector& o) noexcept : _i(o.i()), _j(o.j()), _k(o.k()){}
			PhysVector(PhysVector&& o) noexcept : _i(o.i()), _j(o.j()), _k(o.k()){}
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

			inline double i() const noexcept { return _i; }
			inline double j() const noexcept { return _j; }
			inline double k() const noexcept { return _k; }

			inline void i(const double n) noexcept { _i = n; }
			inline void j(const double n) noexcept { _j = n; }
			inline void k(const double n) noexcept { _k = n; }


		private:
			double _i;
			double _j;
			double _k;
	};
	const PhysVector operator*(const double k, const PhysVector& v) noexcept;
};
#endif
