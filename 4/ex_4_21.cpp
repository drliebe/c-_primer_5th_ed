#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> data = {1,2,4,5,6,7,8};

	for(auto &entry : data)
	{
		((entry%2) != 0 ) ? entry *= 2 : entry *= 1;
	}

	for(auto &entry : data)
	{
		std::cout << entry << std::endl;
	}

	return 0;
}
