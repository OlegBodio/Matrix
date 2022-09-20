#include <iostream>
#include <cmath>
#include <vector>
#include "Vector3.hpp"
#include "Matrix.hpp"

using Vector3i = Vector3<int>;

int main() 
{
	unsigned w = 3;
	unsigned h = 3;

	Vector3i testVec(1, 2, 3);
	Matrix<int> test(w, h);
	test.fillRandom();
	test.print();
	auto col = test.getLine(0);
	auto line = test.getColumn(0);

	(test * test).print();
	
}