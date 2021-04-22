#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::accumulate;

int main()
{
	vector<int> vi{1,2,3,4,5,6,7,8,9,10};

	std::cout << accumulate(vi.begin(), vi.end(), 0) << std::endl;

	return 0;
}
