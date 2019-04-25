#ifndef P_QUATERNION
#define P_QUATERNION

#include "Vector.h"

namespace mathengine {
	class PhysQuaternion {
		public:
			PhysQuaternion(const double s, const PhysVector& v) : _s{s}, _v{v} {}
			PhysQuaternion(const double s, const double i, const double j, const double k) : _s{s}, _v{i,j,k} {}
			PhysQuaternion(const PhysVector& v) : PhysQuaternion(0,v) {}
			PhysQuaternion(const double s, PhysVector&& v) : _s{s}, _v{std::move(v)} {}
			PhysQuaternion(PhysVector&& v) : PhysQuaternion(0, std::move(v)) {}
			PhysQuaternion(const PhysQuaternion& o) = default;
			PhysQuaternion(PhysQuaternion&& o) = default;
			PhysQuaternion& operator=(const PhysQuaternion& rhs) noexcept = default;

			bool operator==(const PhysQuaternion& rhs) const noexcept;
			bool operator!=(const PhysQuaternion& rhs) const noexcept;

			PhysQuaternion& operator+=(const PhysQuaternion& rhs) noexcept;
			const PhysQuaternion operator+(const PhysQuaternion& rhs) const noexcept;
			PhysQuaternion& operator-=(const PhysQuaternion& rhs) noexcept;
			const PhysQuaternion operator-(const PhysQuaternion& rhs) const noexcept;

			PhysQuaternion& operator*=(const double rhs) noexcept;
			const PhysQuaternion operator*(const double rhs) const noexcept;
			friend const PhysQuaternion operator*(const double lhs, const PhysQuaternion& rhs);
			PhysQuaternion& operator/=(const double rhs);
			const PhysQuaternion operator/(const double rhs) const;

			PhysQuaternion& operator*=(const PhysQuaternion& rhs) noexcept;
			const PhysQuaternion operator*(const PhysQuaternion& rhs) const noexcept;

			double magnitude() const noexcept;
			void normalize() noexcept;
			PhysQuaternion unit() const noexcept;
			PhysQuaternion conjugate_of() const noexcept;

			PhysVector& v() noexcept {return _v;};
			const PhysVector& v() const noexcept {return _v;};

			double s() const noexcept {return _s;}
			void s(const double n) noexcept { _s = n; }


		private:
			double _s;
			PhysVector _v;
	};
}
#endif
