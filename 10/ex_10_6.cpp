#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::fill_n;

int main()
{
	vector<int> ivec{1,2,3,4,5,6,7,8,9,10};

	fill_n(ivec.begin(), ivec.size(), 0);

	for(auto i: ivec)
		std::cout << i << std::endl;

	return 0;
}
