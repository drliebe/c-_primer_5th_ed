#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> vec1 = {1,2,3,4,5};

	int array1[5];

	for(int i=0; i<5; ++i)
	{
		array1[i] = vec1[i];
	}


	for(auto i : array1)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
