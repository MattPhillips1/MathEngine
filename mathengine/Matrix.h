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

		private:
			std::array<PhysVector, 3> rows;

	};
}
#endif
