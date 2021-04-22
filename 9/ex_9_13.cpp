#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;


int main()
{
	list<int> l1{1,2,3,4,5};
	vector<int> v1{6,7,8,9,10};

	vector<double> vd1(l1.begin(), l1.end());

	for(auto d : vd1)
	{
		std::cout << d << std::endl;
	}

	vector<double> vd2(v1.begin(), v1.end());

	for(auto d : vd2)
	{
		std::cout << d << std::endl;
	}


	return 0;
}
