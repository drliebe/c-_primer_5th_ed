#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> v1{1,2,3,4,5};
	vector<int> v2{1,2,3,6,5};

	bool equal = (v1 == v2);

	std::cout << equal << std::endl;

	return 0;
}
