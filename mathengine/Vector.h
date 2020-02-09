#ifndef P_VECTOR
#define P_VECTOR

#include <cmath>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <numeric>

#define ENABLE_IF_OWNING bool owning_check = is_owning, typename = std::enable_if_t<owning_check>
#define ENABLE_IF_NOT_OWNING bool owning_check = is_owning, typename = std::enable_if_t<!owning_check>

namespace mathengine {
	
    /*template <typename T>
	class Quaternion;
*/
    template <typename T, typename Container = std::vector<T>, bool is_owning = true>
	class Vector {
		public:

			using container = typename std::conditional<is_owning, Container, Container&>::type;

			template <ENABLE_IF_OWNING>
			Vector() : vec{}, mag{0}, mag_valid{true}{}
			template <ENABLE_IF_OWNING>
			Vector(std::initializer_list<T> l) noexcept : vec{l}, mag{0}, mag_valid{false}{}
			template <typename NC, bool owning, ENABLE_IF_OWNING>
			explicit Vector(const Vector<T, NC, owning>& o) noexcept : vec{o.vec}, mag{o.mag}, mag_valid{o.mag_valid}{}
            template <typename NC, ENABLE_IF_OWNING>
			explicit Vector(Vector<T, NC, true>&& o) noexcept : vec{std::move(o.vec)}, mag{o.mag}, mag_valid{o.mag_valid}{}
			
			// template <ENABLE_IF_NOT_OWNING>
			explicit Vector(Container&& cont) : vec(std::move(cont)), mag{0}, mag_valid{false} {}
			
			template <ENABLE_IF_OWNING>
			constexpr explicit Vector(int size) : vec(container(size)), mag{0}, mag_valid{true} {}

			// template <ENABLE_IF_OWNING>
			// explicit Vector (Container&& o) : vec{std::move(o)}, mag{0}, mag_valid{false}{}
			
			template <typename NC, bool owning>
			Vector& operator=(const Vector<T, NC, owning>& o) noexcept;

			template <typename NC, bool owning>
			bool operator==(const Vector<T, NC, owning>& o) const noexcept;
			template <typename NC, bool owning>
			bool operator!=(const Vector<T, NC, owning>& o) const noexcept;

			friend std::ostream& operator<<(std::ostream& os, const Vector& rhs) noexcept {
			    os << "[ ";
			    auto it = rhs.begin();
			    for (; it != rhs.vec.end() - 1; ++it){
			        os << *it << ", ";
			    }
			    os << *it << " ]";
			    return os;
			}

			T& operator[](int i) noexcept { return vec[i]; }
			T operator[](int i) const noexcept { return vec[i]; }

/*
			// Vector addition
			Vector& operator+=(const Vector& o) noexcept;
			Vector operator+(const Vector& o) const noexcept;

			// Vector subtraction
			Vector& operator-=(const Vector& o) noexcept;
			Vector operator-(const Vector& o) const noexcept;

			// Scalar Multiplication
			Vector& operator*=(T s) noexcept;
			Vector operator*(T s) const noexcept;
			friend Vector operator*(T k, const Vector& v) noexcept {
			    return v*k;
			}

			

			// Scalar division
			Vector& operator/=(T s);
			Vector operator/(T s) const;

			T dot(const Vector& o) const noexcept;

			double magnitude() const noexcept;
			inline T square_sum() const noexcept {
			    return std::accumulate(vec.cbegin(), vec.cend(), 0, [](const T& a, const T& b) {
                    return a + b * b;
                });
			}

			inline int size() const noexcept { return vec.size(); }

			void normalize();

			Vector unit() const;

			auto begin() noexcept { return vec.begin(); }
			auto end() noexcept { return vec.end(); }

			auto cbegin() const noexcept { return vec.cbegin(); }
			auto cend() const noexcept { return vec.cend(); }

			Vector cross(const Vector& o) const noexcept;
			Vector& rotate(double angle, const Vector& axis);
            Vector& rotate(const Quaternion<T>& q);
            Vector& rotate_unit(const Quaternion<T>& q);
		*/

        private:
		template<typename U, typename NC, bool own>
		friend class Vector;
	        Container vec;
			mutable double mag;
			mutable bool mag_valid;

	};
}

#include "Vector.cpp"
#endif
