#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std::placeholders;

int main()
{
	std::vector<int> ivec = {3,4,5,6,7};
	std::modulus<int> md;

	int iquery = 12;

	auto it = find_if_not(ivec.begin(), ivec.end(), std::bind(md, iquery, _1));
	if (it != ivec.end())
		std::cout << *it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	return 0;
}
