#include <iostream>
#include <cmath>
#include <vector>
#include "Vector3.hpp"
#include "Matrix.hpp"

using Vector3i = Vector3<int>;

using namespace std;

int main() 
{

	unsigned w = 3;
	unsigned h = 3;

	Vector3i testVec(1, 2, 3);
	Matrix<double> test1(w, h);
	test1.fillFromExample();
	test1.print();
	std::cout << std::endl << std::endl;

	(test1 * test1.getRotatedmatrix()).print();
}

