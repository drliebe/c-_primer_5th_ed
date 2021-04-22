#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> v1;
	//vector<int> v1{1,2,3,4,5};

	std::cout << v1.at(0) << std::endl;
	std::cout << v1.front() << std::endl;
	std::cout << *(v1.begin()) << std::endl;

	return 0;
}
