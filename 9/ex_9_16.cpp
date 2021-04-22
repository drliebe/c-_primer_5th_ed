#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

int main()
{
	list<int> l1{1,2,3,4,5};
	vector<int> v2{1,2,3,6,5};

	bool equal = (l1 == v2);

	std::cout << equal << std::endl;

	return 0;
}
