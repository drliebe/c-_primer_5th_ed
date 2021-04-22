#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;

int main()
{
	vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
	list<int> ilist;

	copy(ivec.begin()+3, ivec.begin()+8, front_inserter(ilist));

	for (auto i: ilist)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
