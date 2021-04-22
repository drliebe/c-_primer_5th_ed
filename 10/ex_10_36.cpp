#include <iostream>
#include <list>
#include <algorithm>

using std::list;


int main()
{
	list<int> ilist{1,2,0,3,4,0,5,0,6,7,8};

	int val = 0;

	auto it = find(ilist.crbegin(), ilist.crend(), val);

	std::cout << "Last zero value: " << *it << " is preceeded by: " << *(++it) << std::endl;
	
	
	return 0;
}

