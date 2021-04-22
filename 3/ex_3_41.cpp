#include <iostream>
#include <string>
#include <vector>


using std::vector;

int main()
{
	int array1[] = {1,2,3,4,5};

	vector<int> vec1(std::begin(array1), std::end(array1));

	for(auto i : vec1)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
