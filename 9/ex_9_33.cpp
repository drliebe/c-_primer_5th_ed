#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> v{0,1,2,3};

	auto begin = v.begin();

	while (begin != v.end())
	{
		++begin;
		v.insert(begin, 42);
		++begin;
	}

	for (auto i : v)
		std::cout << i << std::endl;

	return 0;
}
