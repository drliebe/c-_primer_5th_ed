#include <iostream>
#include <vector>

using std::vector;


int main()
{
	vector<int> ivec{1,2,3,4,5,6,7,8,9};

	auto rev_it = ivec.crbegin();

	while (rev_it != ivec.crend())
	{
		std::cout << *rev_it << std::endl;
		++rev_it;
	}

	return 0;
}
