#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::count;

int main()
{
	vector<int> vec{1,2,3,4,5,4,3,2,1,1,2,3};
	int value_sought = 5;

	std::cout << count(vec.begin(), vec.end(), value_sought) << std::endl;	


	return 0;
}
