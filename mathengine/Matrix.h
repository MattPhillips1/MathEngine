#ifndef P_MATRIX
#define P_MATRIX

#include <array>
#include "Vector.h"
namespace mathengine {
	class PhysMatrix {
		/*
		* Aligned in the following way (better cache performance)
		* i       j       k
		* 1       0       0
		* 0       1       0
		* 0       0       1
		*
		* ie top row is one vector with i,j,k components
		*/
		public:
			// Default, Copy, Move constructors generated
			PhysMatrix() = default;
			PhysMatrix(PhysVector&& a, PhysVector&& b, PhysVector&& c) : rows{a,b,c} {}
			PhysMatrix(
					const double i1, const double j1, const double k1,
					const double i2, const double j2, const double k2,
					const double i3, const double j3, const double k3
					) : PhysMatrix(PhysVector{i1,j1,k1}, PhysVector{i2,j2,k2}, PhysVector{i3,j3,k3}) {}
			PhysMatrix(const PhysVector& a, const PhysVector& b, const PhysVector& c) : rows{a,b,c} {}

			bool operator==(const PhysMatrix& rhs) const noexcept;
			bool operator!=(const PhysMatrix& rhs) const noexcept;

			// Matrix Addition
			PhysMatrix& operator += (const PhysMatrix& rhs) noexcept;
			const PhysMatrix operator+(const PhysMatrix& rhs) noexcept;

			// Matrix Subtraction
			PhysMatrix& operator -= (const PhysMatrix& rhs) noexcept;
			const PhysMatrix operator-(const PhysMatrix& rhs) noexcept;

			// Scalar Multiplication
			PhysMatrix& operator*=(const double s) noexcept;
			const PhysMatrix operator*(const double s) const noexcept;
			friend const PhysMatrix operator*(const double s, const PhysMatrix& v) noexcept;

			// Scalar Division
			PhysMatrix& operator/=(const double s);
			const PhysMatrix operator/(const double s) const;

			// Vector & Matrix Multiplication
			const PhysVector operator*(const PhysVector& rhs) const noexcept;
			PhysMatrix& operator*=(const PhysMatrix& rhs) noexcept;
			const PhysMatrix operator*(const PhysMatrix& rhs) const noexcept;

			PhysVector& operator[](const unsigned int i) { return rows[i]; }
			PhysVector operator[](const unsigned int i) const { return rows[i]; }
			PhysVector col(const unsigned int i) const;
			PhysVector i() const { return PhysVector(rows[0].i(), rows[1].i(), rows[2].i()); }
			PhysVector j() const { return PhysVector(rows[0].j(), rows[1].j(), rows[2].j()); }
			PhysVector k() const { return PhysVector(rows[0].k(), rows[1].k(), rows[2].k()); }

			// Matrix Operations
			void transpose() noexcept;
			PhysMatrix transpose_of() const noexcept;
			PhysMatrix inverse_of() const;
			double det() const noexcept;


		private:
			std::array<PhysVector, 3> rows;

	};
}
#endif
