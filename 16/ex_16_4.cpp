#include <iostream>
#include <vector>

template <typename T, typename V>
T find_josh(T beg, T end, V value)
{
	while(beg != end)
	{
		if (*beg == value)
			return beg;
		++beg;
	}
	return end;
}


int main()
{
	std::vector<int> ivec = {1,2,3,4,5};
	std::vector<int>::iterator it;

	it = find_josh(ivec.begin(), ivec.end(), 2);

	std::cout << *it << std::endl;


	return 0;
}
