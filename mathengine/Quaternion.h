#ifndef P_QUATERNION
#define P_QUATERNION
/*
#include "Vector.h"

namespace mathengine {
    template <typename T>
	class Quaternion {
		public:
			Quaternion(const double s, const Vector3D<T>& v) : _s{s}, _v{v} {}
			Quaternion(const double s, const double i, const double j, const double k) : _s{s}, _v{i, j, k} {}
			Quaternion(const Vector3D<T>& v) : Quaternion(0, v) {}
			Quaternion(const double s, Vector3D<T>&& v) : _s{s}, _v{std::move(v)} {}
			Quaternion(Vector3D<T>&& v) : Quaternion(0, std::move(v)) {}

			bool operator==(const Quaternion& rhs) const noexcept;
			bool operator!=(const Quaternion& rhs) const noexcept;

			Quaternion& operator+=(const Quaternion& rhs) noexcept;
			Quaternion operator+(const Quaternion& rhs) const noexcept;
			Quaternion& operator-=(const Quaternion& rhs) noexcept;
			Quaternion operator-(const Quaternion& rhs) const noexcept;

			Quaternion& operator*=(double rhs) noexcept;
			Quaternion operator*(double rhs) const noexcept;

			friend Quaternion<T> operator*(double lhs, const Quaternion& rhs) { return rhs*lhs; }

			Quaternion& operator/=(double rhs);
			Quaternion operator/(double rhs) const;

			Quaternion& operator*=(const Quaternion& rhs) noexcept;
			Quaternion operator*(const Quaternion& rhs) const noexcept;

			double magnitude() const noexcept;
			inline double square_sum() const noexcept { return s()*s() + v().square_sum(); }

			void normalize();
			void make_rotation();
			Quaternion unit() const;
			Quaternion rotation_unit() const;
			Quaternion conjugate_of() const noexcept;

			Quaternion inverse_of() const;

			Vector3D<T>& v() noexcept {return _v;};
			const Vector3D<T>& v() const noexcept {return _v;};

			double s() const noexcept {return _s;}
			void s(const double n) noexcept { _s = n; }


		private:
			double _s;
			Vector3D<T> _v;

	};
}/*
#endif
