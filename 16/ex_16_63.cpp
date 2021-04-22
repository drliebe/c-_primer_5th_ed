#include <iostream>
#include <vector>
#include <string>

template <typename T>
size_t count_josh(std::vector<T> &vec, T val)
{
	size_t counter = 0;

	for (auto v: vec)
	{
		if (v == val)
			++counter;
	}
	return counter;
}


int main()
{
	std::vector<double> vd = {1.0, 2.0, 3.0, 1.0};
	std::vector<int> vi = {1, 2, 3, 1};
	std::vector<std::string> vs = {"one", "two", "three", "one"};

	std::cout << count_josh(vd, 1.0) << std::endl;
	std::cout << count_josh(vi, 1) << std::endl;
	std::cout << count_josh(vs, std::string("one")) << std::endl;

	return 0;
}
