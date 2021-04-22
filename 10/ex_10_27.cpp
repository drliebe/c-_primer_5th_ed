#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;
using std::unique_copy;
using std::back_inserter;

int main()
{
	vector<int> ivec{1,1,2,3,4,5,5,7,8,8,5,3};
	list<int> ilist;

	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.begin(), ivec.end(), back_inserter(ilist));

	for(auto i: ilist)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
