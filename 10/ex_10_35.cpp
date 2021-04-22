#include <iostream>
#include <vector>

using std::vector;


int main()
{
	vector<int> ivec{1,2,3,4,5,6,7,8,9};

	auto end_it = ivec.end();
	--end_it;

	while (end_it != ivec.begin())
	{
		std::cout << *end_it << std::endl;
		--end_it;
	}
	std::cout << *end_it << std::endl;

	return 0;
}
