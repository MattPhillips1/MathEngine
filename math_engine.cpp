#include "math_engine.h"
#include <iostream>

int main(){
	std::cout << "Hello World\n";
	mathengine::Vector<int> t{1, 2, 3};
	auto m = mathengine::Matrix<int, 4>(4);
	auto& r1 = m.row(0);
	r1[0] = 1;
	r1[1] = 1;
	auto c1 = m.col(0);

	std::cout << c1 << '\n';
	std::cout << r1 << '\n';
	c1 = r1;
	std::cout << c1 << '\n';
	std::cout << r1 << '\n';
	auto& r2 = m.row(0);
	std::cout << r1[0] << '\n';
	std::cout << c1[0] << '\n';
	std::cout << r2[0] << '\n';

	c1[0] += 1;
	std::cout << r1[0] << '\n';
	std::cout << c1[0] << '\n';
	std::cout << r2[0] << '\n';

	
	return 0;
}
