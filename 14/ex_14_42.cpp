#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std::placeholders;

int main()
{
	std::vector<int> ivec = {1, 1000, 2000, 4000, 3};
	std::greater<int> gr;
	
	auto greater_than_1024 = count_if(ivec.begin(), ivec.end(), std::bind(gr, _1, 1024));	
	std::cout << greater_than_1024 << std::endl;
	
	std::vector<std::string> svec = {"pooh", "pooh", "not pooh", "pooh"};
	std::not_equal_to<std::string> ne;

	auto p = find_if(svec.begin(), svec.end(), std::bind(ne, _1, "pooh"));
	std::cout << *p << std::endl;

	std::vector<double> dvec = {1.0, 2.0, 3.0, 4.0, 5.0};
	std::multiplies<double> mlt;
	transform(dvec.begin(), dvec.end(), dvec.begin(), std::bind(mlt, _1, 2.0));
	for (auto d : dvec)
		std::cout << d << " ";
	std::cout << std::endl;

	return 0;
}
