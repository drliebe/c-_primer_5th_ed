#include <iostream>
#include <vector>

using std::vector;

int func1(int i, int j);


int main()
{

	vector<int (*)(int, int)> vec_of_func1;

	std::cout << "works..." << std::endl;

	return 0;
}
